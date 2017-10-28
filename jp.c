/*

Copyright (c) 2017 "tropposite" as on https://github.com/t-site

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include"masks.h"
#include<gd.h>

		
static	int red_pick[MASK_SIZE][MASK_SIZE];
static	int green_pick[MASK_SIZE][MASK_SIZE];
static	int blue_pick[MASK_SIZE][MASK_SIZE];

static int juggyplow_correct_mask ( const int matrix[][MASK_SIZE] )
{
	int i,j,k;
	double diff_max = 0;
	int correct_mask = 0;
	for ( i = 0 ; i < MASK_COUNT ; i++ )
	{
		double diff;
		double A_count=0,B_count=0;
		for ( j = 0; j < MASK_SIZE ; j++ )
		{
			for ( k = 0; k < MASK_SIZE ; k++ )
			{
				double pixel;
				pixel = (double)matrix[j][k];

				if (masks[i][j][k])
					A_count += ( pixel * pixel_weight[j][k] ) ;
				else
					B_count += ( pixel * pixel_weight[j][k] ) ;
			}
		}
		diff = fabs(( A_count / masks_weight_list[i].A_weight ) - ( B_count / masks_weight_list[i].B_weight )) ;
		if( diff_max < diff )
		{
			diff_max = diff;
			correct_mask = i ;
		}
	}
	return correct_mask;
}
static void juggyplow_blight_apply( const int correct_mask , const int matrix[][MASK_SIZE] , int *a_b )
{
	int i,j;
	int pixel;
	double A_all_f,B_all_f;
	A_all_f = matrix[HALF_MASK][HALF_MASK];
	B_all_f = matrix[HALF_MASK][HALF_MASK];
	
	
	for ( i = 0 ; i < MASK_SIZE ; i++ )
	{
		for ( j = 0 ; j < MASK_SIZE ; j++ )
		{
				pixel = matrix[i][j];
				if(masks[correct_mask][i][j] )
				{
					A_all_f += ( (double)pixel * pixel_weight[i][j]) ;
				}else
				{
					B_all_f += ( (double)pixel * pixel_weight[i][j]) ;					
				}
		}
	}
	
	a_b[0] = (int)(A_all_f / (1.0+masks_weight_list[correct_mask].A_weight)) ;
	a_b[1] = (int)(B_all_f / (1.0+masks_weight_list[correct_mask].B_weight)) ;
}

gdImagePtr juggyplow( gdImagePtr input_image )
{
	gdImagePtr output_image;
	int OutputImageSX;
	int OutputImageSY;
	int InputImageSX;
	int InputImageSY;
	int input_x;
	int input_y;
	
	InputImageSX = gdImageSX(input_image) ;
	InputImageSY = gdImageSY(input_image) ;
	OutputImageSX = MASK_SIZE * gdImageSX(input_image) ;
	OutputImageSY = MASK_SIZE * gdImageSY(input_image) ;
	pixel_weight_matrix_calc();
	pixel_weight_all_calc();
	output_image = gdImageCreateTrueColor(OutputImageSX,OutputImageSY);
	for ( input_y = 0 ; input_y < InputImageSY ; input_y++ )
	{
		for ( input_x = 0 ; input_x < InputImageSX ; input_x++ )
		{
			int i,j,k,l;
			int red_correct_mask ;
			int green_correct_mask;
			int blue_correct_mask;
			int reds[2];
			int greens[2];
			int blues[2];
			int x,y;

			for( i = 0; i < MASK_SIZE ; i++)
			{
				y = input_y - HALF_MASK + i ;
				for( j=0 ; j < MASK_SIZE ; j++)
				{
					int pixel;
					x = input_x - HALF_MASK + j ;

					pixel=gdImageGetTrueColorPixel( input_image , x , y);
					red_pick[i][j]=gdTrueColorGetRed( pixel );
					green_pick[i][j]=gdTrueColorGetGreen( pixel );
					blue_pick[i][j]=gdTrueColorGetBlue( pixel );
				}
			}

			red_correct_mask = juggyplow_correct_mask(red_pick);
			green_correct_mask = juggyplow_correct_mask(green_pick);
			blue_correct_mask = juggyplow_correct_mask(blue_pick);
           

			juggyplow_blight_apply( red_correct_mask , red_pick , reds );

			juggyplow_blight_apply( green_correct_mask , green_pick , greens );

			juggyplow_blight_apply( blue_correct_mask , blue_pick , blues );
			
			for( k = 0 ; k < MASK_SIZE ; k++ )
			{
				for( l = 0 ; l < MASK_SIZE ; l++)
				{
						int mask_x;
						int mask_y;
						int red,green,blue;
						mask_x = input_x * MASK_SIZE + l;
						mask_y = input_y * MASK_SIZE + k;
						if( masks[red_correct_mask][k][l] )
							red = reds[0];
						else
							red = reds[1];

						if( masks[green_correct_mask][k][l] )
							green = greens[0];
						else
							green = greens[1];
						
						if( masks[blue_correct_mask][k][l] )
							blue = blues[0];
						else
							blue = blues[1];

						gdImageSetPixel(output_image,mask_x,mask_y,gdImageColorClosest(output_image,red,green,blue));
					
				}
			}
		}
	}
	return output_image;
}
