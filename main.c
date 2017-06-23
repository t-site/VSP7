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

#include<gd.h>
gdImagePtr juggyplow( gdImagePtr );
int main(int argc,char **argv)
{
	gdImagePtr input_image,output_image,juggyplow_image;
	int multiply_factor;
	if(argc != 4)
	{
		printf("%s as image resampler improved Russell Kirsch's\n",argv[0]);
		puts("Variable Shape Pixels idea.");
		printf("%s <scale_factor> <input_image_file> <output_image_file>\n",argv[0]);
		puts("Valid scale_factor are 1 to 7.");
		puts(" 1 for denoise JPEG image.");
		puts(" 2,3,4 are recommended.");
		puts("7 for output raw variable shaped pixel data.");
		return 1;
	}
	multiply_factor = atoi(argv[1]);
	if(multiply_factor < 1 || multiply_factor > 7)
	{
		puts("Error: invalid multiply factor. valid for 1 to 7.");
		return 4;
	}
	if( GD_FALSE == gdSupportsFileType(argv[3],1 ) )
	{
		puts("Error: Output file Format not Surppotted\n");
		return 3;
	}
	input_image=gdImageCreateFromFile(argv[2]);
	if( input_image == NULL )
	{
		puts("Error: Can not open the input file\n");
		return 2;
	}
	
	juggyplow_image = juggyplow(input_image);	
	
	if(multiply_factor == 7)
	{
		output_image = juggyplow_image;
	}
	else 
	{
		unsigned int sx,sy;
		sx = (unsigned int)(gdImageSX(input_image) * multiply_factor);
		sy = (unsigned int)(gdImageSY(input_image) * multiply_factor);
		gdImageSetInterpolationMethod(juggyplow_image,GD_HERMITE);
		output_image = gdImageScale(juggyplow_image,sx,sy);
		gdImageDestroy(juggyplow_image);
	}

	if( GD_FALSE == gdImageFile(output_image,argv[3]))
	{
		puts("Error: Can not save Output image file\n");

		gdImageDestroy(input_image);
		gdImageDestroy(output_image);
		return 5;
	}
	gdImageDestroy(input_image);
	gdImageDestroy(output_image);
	return 0;
}
