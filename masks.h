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

#ifndef MASKS_H
#define MASKS_H

#include<math.h>
#include<limits.h>

#define M INT_MAX

#define MASK_SIZE 7

int masks [][MASK_SIZE][MASK_SIZE] = {
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0}
	},
	{
		
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M}
	},
	{
		{0,0,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,M,M,M}
	},
	{
		{0,0,0,0,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,M,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,M},
		{0,0,0,0,0,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}

	},
	{
		{M,M,M,M,M,M,M},
		{0,M,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,0,M,M},
		{0,0,0,0,0,0,M}
	},
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,0,0},
		{M,M,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{M,M,0,0,0,0,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{0,M,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,0,M,M}
	},
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,0},
		{M,M,M,M,0,0,0},
		{M,M,M,0,0,0,0},
		{M,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,M,M,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,0,0},
		{M,0,0,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,M,M,0},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,M},
		{0,0,0,0,0,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,M},
		{0,0,0,0,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M}
	},
	{
		{0,0,0,0,0,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M}
	},
	{
		{M,M,M,M,M,M,M},
		{0,M,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{0,M,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{0,M,M,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,0,0,0,0,0},
		{M,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,0,0,0,0},
		{M,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,M,M,0},
		{M,M,M,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,M,M,0},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,M,M,0}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,M,M,M,M},
		{0,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,0,M,M,M,M,M},
		{0,M,M,M,M,M,M}
	},
	{
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,0,M,M},
		{0,0,0,0,0,0,M}
	},
	{
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,0,0,M},
		{0,0,0,0,0,0,0}
	},
	{
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,0,M,M}
	},
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,M,M,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,M,0,0},
		{M,M,M,M,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,0},
		{M,M,M,M,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{M,0,0,0,0,0,0},
		{M,M,0,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0}
	},
	{
		{0,0,0,0,0,0,0},
		{M,0,0,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0}
	},
	{
		{M,M,0,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,M,0,0,0}
	},
	{
		{M,M,0,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,M,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,M,0,0,0,0},
		{M,M,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,M,0,0,0},
		{0,M,M,M,M,M,0},
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M}
	},
	{
		{M,M,M,M,M,M,M},
		{M,M,M,M,M,M,M},
		{0,M,M,M,M,M,0},
		{0,0,0,M,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	},
	{
		{0,0,0,0,0,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,M,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,M,M,M},
		{0,0,0,0,0,M,M}
	}
};

#undef M

#define HALF_MASK 3

#define MASK_COUNT (sizeof(masks)/sizeof(masks[0]))

double pixel_weight [MASK_SIZE][MASK_SIZE];

void pixel_weight_matrix_calc(void)
{
	int x,y;
	for ( y = 0 ; y <= HALF_MASK ; y++)
	{
		for ( x = 0 ; x <= HALF_MASK ; x++)
		{
			double weight,fx,fy;
            fx = ( 1.0 + (double)x );
            fy = ( 1.0 + (double)y );
			weight = 1.0 / ( pow(fx,fx) + pow(fy,fy) );
			pixel_weight[HALF_MASK + y][HALF_MASK + x]=weight;
			pixel_weight[HALF_MASK + y][HALF_MASK - x]=weight;
			pixel_weight[HALF_MASK - y][HALF_MASK + x]=weight;
			pixel_weight[HALF_MASK - y][HALF_MASK - x]=weight;
		}
	}
	pixel_weight[HALF_MASK][HALF_MASK]=0.0;
}

struct masks_weight {
	int A;
	int B;
	double A_weight;
	double B_weight;
};

struct masks_weight masks_weight_list[MASK_COUNT];

void pixel_weight_all_calc(void)
{
	int i,j,k;
	for ( i=0; i < MASK_COUNT ; i++)
	{
		
		masks_weight_list[i].A=0;
		masks_weight_list[i].B=0;
		masks_weight_list[i].A_weight=0.0;
		masks_weight_list[i].B_weight=0.0;
		
		for ( j=0; j < MASK_SIZE ; j++)
		{
			for (k=0; k < MASK_SIZE ; k++)
			{
				if( masks[i][j][k] )
				{
					masks_weight_list[i].A++;
					masks_weight_list[i].A_weight+=pixel_weight[j][k];
				}else {
					masks_weight_list[i].B++;
					masks_weight_list[i].B_weight+=pixel_weight[j][k];					
				}
			}
		}
	}
}
#else
#endif
