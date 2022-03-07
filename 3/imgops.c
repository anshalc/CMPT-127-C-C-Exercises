/*
 * imgops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 


/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/


/* TASK 1 - Easy functions to get started */

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  memset(array, 0, rows*cols*sizeof(uint8_t));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  uint8_t* nw_array = malloc(rows*cols*sizeof(uint8_t));
  if((sizeof(nw_array)/sizeof(nw_array[0])) == rows*cols*sizeof(uint8_t))
  {
  	memcpy(&nw_array, &array, rows*cols*sizeof(uint8_t));
  }
  nw_array = NULL;
  return nw_array;
}

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  float min = 256;
  for(int i=0;i<rows*cols;i++)
  {
  	if(array[i]<min)
  		min=array[i];
  }
  return fmin(256, min);
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  float max = 0;
  for(int i=0;i<rows*cols;i++)
  {
  	if(array[i]>max)
  		max=array[i];
  }
  return fmax(0, max);
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for(int i=0;i<cols*rows;i++)
  	if(array[i] == pre_color)
  		array[i] = post_color;
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  	for(int i=0;i<rows;i++)
  	{
  		for(int j=0;j<cols/2;j++)
  		{
  			int temp = array[i*cols+j];
  			array[i*cols+j] = array[i*cols+ cols -j-1];
  			array[i*cols + cols-j-1] = temp;
  		}
  	}

}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
    for(int i=0;i<rows/2;i++)
    {
      int k = rows-1-i;
      for(int j=0;j<cols;j++)
      {
        int temp = array[i*cols+j];
        array[i*cols+j] = array[k*cols+j];
        array[k*cols+j] = temp;

      }
    }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
	int count = 0;
    for(int i = 0; i < rows*cols; i++)
    {
    	if(array[i] == color)
    	{
    		*x = i%cols;
    		*y = i/cols;
    		return 1;
    	}

    }
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    for(int i=0;i<rows*cols;i++)
    {
    	array[i] = 255 - array[i];
    }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Resulting values are rounded to the nearest
// integer (0.5 rounded up) and any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  for(int i=0;i<rows*cols;i++)
  {
  	int k;
  	k = round(scale_factor * array[i]);
  	{
  		if(k>=255)
  		{
  			array[i] = 255;
  		}
  		else
  			array[i] = k;
  	}
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    // your code here
  int i;
  unsigned int cc=cols;
  unsigned int rr=rows;
  
  uint8_t arr[rr*cc];
  for (i=0;i<rr*cc;i++)
  {
    arr[i]=array[i];
  }    
  int x=max(arr,cc,rr);
  int n=min(arr,cc,rr);
  for (i=0;i<rows*cols;i++)
  {
    array[i]=array[i]-n;
    
  }  
  
  for (i=0;i<rows*cols;i++)
  {
    array[i]=round(array[i]*255.0/(x-n));    
  }  

}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  uint8_t *ret = malloc((rows/2)*(cols/2)*sizeof(uint8_t));
  if(ret != NULL)
  {
  	for(int y = 0;y<rows/2;y++)
  		for(int x =0;x<cols/2;x++)
  		{
  			unsigned int total = 0;

  		for(int i = 2*y;i<2*y+2;i++)
  			for(int j = 2*x;j<2*x+2;j++)
  				total+= array[i*cols + j];

  		ret[y*(cols/2) + x] = round(total/4.0);

  	}
  }
  return ret;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The rectangle edges of a rectangular region are aligned with the x,y axes. 
  
  The region includes all the columns from [left, right-1] inclusive,
  and all the rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, you can use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must remained unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  int i,j;
  for (i=0;i<rows;i++)
  {
    if (left==right || top==bottom)
    {
      break;
    }
    for (j=0;j<cols;j++)
    {
      if (i>=top && i<=bottom-1)
      {
        if (j>=left && j<=right-1)
        {
          array[i*cols+j]=color;
        }
      }
    }
  }
  
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
	int sum = 0;
    for(int i=0;i<rows*cols;i++)
    {
    	int x = left * cols + top;
    	int y = right * cols + bottom;
    	if(i>=x && i<=y)
    	{
    		sum = sum+array[i];
    		return sum;
    	}
    }
    return 0;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
    // your code here
  int i,j,k=0;
  uint8_t* regcopy=malloc( sizeof(uint8_t)*(right-left)*(bottom-top));
  if (left==right || top==bottom)
  {
    return NULL;
  }
  
  else 
  {
    for (i=0;i<rows;i++)
    {
      for (j=0;j<cols;j++)
      {
        if (i>=top && i<=bottom-1 )
        {
          if (j>=left && j<=right-1 )
          {
            regcopy[k]=array[i*cols+j];
            k++;
          }
        }
      }
    }   
    return regcopy;
  }
}
