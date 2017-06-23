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
static	int red_matrix[MASK_SIZE][MASK_SIZE];
static	int green_matrix[MASK_SIZE][MASK_SIZE];
static	int blue_matrix[MASK_SIZE][MASK_SIZE];

		
static	int red_by3[MASK_SIZE][MASK_SIZE];
static	int green_by3[MASK_SIZE][MASK_SIZE];
static	int blue_by3[MASK_SIZE][MASK_SIZE];

static int juggyplow_correct_mask ( const int matrix[][MASK_SIZE] )
{
	int i,j,k;
	double diff_max = 0;
	int correct_mask = 0;
	for ( i = 0 ; i < MASK_COUNT ; i++ )
	{
		double diff;
		int A_count=0,B_count=0;
		for ( j = 0; j < MASK_SIZE ; j++ )
		{
			for ( k = 0; k < MASK_SIZE ; k++ )
			{
				int pixel;
				pixel = matrix[j][k];

				if(masks[i][j][k])
				{
					A_count += (masks[i][j][k]) & pixel ;
				}else
				{
					B_count += (~ masks[i][j][k]) & pixel ;
				}
			}
		}
		diff = fabs(( (double)A_count / (double)pixel_weight_list[i].A ) - ( (double)B_count / (double)pixel_weight_list[i].B )) ;
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
	
	a_b[0] = (int)(A_all_f / (1.0+pixel_weight_list[correct_mask].A_weight)) ;
	a_b[1] = (int)(B_all_f / (1.0+pixel_weight_list[correct_mask].B_weight)) ;
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
	gdImagePtr matrix_from3;
	
	InputImageSX = gdImageSX(input_image) ;
	InputImageSY = gdImageSY(input_image) ;
	OutputImageSX = MASK_SIZE * gdImageSX(input_image) ;
	OutputImageSY = MASK_SIZE * gdImageSY(input_image) ;
	pixel_weight_matrix_calc();
	pixel_weight_all_calc();
	output_image = gdImageCreateTrueColor(OutputImageSX,OutputImageSY);
	matrix_from3 = gdImageCreateTrueColor(3,3);
	gdImageSetInterpolationMethod(matrix_from3,GD_LINEAR);
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
			gdImagePtr matrix37;
			for ( y = 0, i = input_y - HALF_MASK ;  y < MASK_SIZE ; i ++ ,y++ )
			{
				for ( x = 0, j = input_x - HALF_MASK ; x < MASK_SIZE ; j++ ,x++ )
				{
					int pixel;

					pixel=gdImageGetTrueColorPixel(input_image,j,i);
					red_matrix[y][x]=gdImageRed(output_image,pixel);
					green_matrix[y][x]=gdImageGreen(output_image,pixel);
					blue_matrix[y][x]=gdImageBlue(output_image,pixel);

				}
			}

			red_correct_mask = juggyplow_correct_mask(red_matrix);
			green_correct_mask = juggyplow_correct_mask(green_matrix);
			blue_correct_mask = juggyplow_correct_mask(blue_matrix);
            

			gdImageCopy(matrix_from3,input_image,0,0,(input_x-1) , (input_y -1),3,3);

            matrix37 = gdImageScale(matrix_from3,MASK_SIZE,MASK_SIZE);
			for( i = 0; i < MASK_SIZE ; i++)
			{
				for( j=0 ; j < MASK_SIZE ; j++)
				{
					int pixel;

					pixel=gdImageGetTrueColorPixel(matrix37,j,i);
					red_by3[i][j]=gdImageRed(matrix37,pixel);
					green_by3[i][j]=gdImageGreen(matrix37,pixel);
					blue_by3[i][j]=gdImageBlue(matrix37,pixel);
				}
			}
			gdImageDestroy(matrix37);

			juggyplow_blight_apply( red_correct_mask , red_by3 , reds );

			juggyplow_blight_apply( green_correct_mask , green_by3 , greens );

			juggyplow_blight_apply( blue_correct_mask , blue_by3 , blues );
			
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
    gdImageDestroy(matrix_from3);
	return output_image;
}
