# VSP7a an improvement of Russell Kirsh's Variable Shape Pixels idea

vsp7a as an image enlarger.

## improvement feature

1. 7x7 kernel,bold center pixel
1. inverse square law of lay implement fully
1. new trapezoid masks added
1. 7x raw variable shape pixel output and shrink to 2,3,4x for smooth viewing
1. not so slow throughput

## Variable Shape Pixels likes no other

Variable shape pixels invented by Russell Kirsch,father of digital image.
Its more smooth view than square pixels.
But I didn't found any implements.
I implement it with more improvement.
and I say Variable Shape Pixels likes no other.

I tuned VSP7 for Oiran image. recommend for nature and traditional design,Photograph contents. not for anime.

Variable Shape Pixels maybe eliminate noise in lossy image formats.
lossless image formats recommended for output.

vsp7a 2-4x output can used by cascade for more enlarge.
no 'blobs' and square block noise found like GIMP's lanzcos3.
but so slow.

```bash:cascade.sh

vsp7a 3 input.jpg 3x.gd
vsp7a 3 3x.gd 9x.gd
vsp7a 3 9x.gd 27x.png
```

NOTICE: current VSP7, jpeg noise eliminate function is lost.
git-55170a8 for use this function. but slow.
```bash:jpeg-clean.sh
vsp7a 1 input.jpg output.png
```


## Requirements

1. Processor impliments Double precision floating point number
1. C compiler
1. Standard C Library
1. C math Library
1. [libgd](https://libgd.github.io) Graphic library

## TODO

1. Ultrafast mask algolithm using CPU caches ( 49x faster )
1. Gaussian blur for 7x output
1. multi thread
