/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "cchen120+zli80",                  /* Team name */

    "Zonglin Li",                      /* First member full name */
    "zli80@ur.rochester.edu",          /* First member email address */

    "Chi Chun Chen",                   /* Second member full name (leave blank if none) */
    "cchen120@ur.rochester.edu"        /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
#define BSIZE 16
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    //My version
    int i, j, ii, jj;
    for(ii = 0; ii < dim; ii += BSIZE){
        for(jj = 0; jj < dim; jj +=BSIZE){
            for(i = ii; i < ii + BSIZE; i += 4){
                for(j = jj; j < jj + BSIZE; j += 4){
                    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
                    dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
                    dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
                    dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
                    dst[RIDX(dim-1-j-1, i, dim)] = src[RIDX(i, j+1, dim)];
                    dst[RIDX(dim-1-j-1, i+1, dim)] = src[RIDX(i+1, j+1, dim)];
                    dst[RIDX(dim-1-j-1, i+2, dim)] = src[RIDX(i+2, j+1, dim)];
                    dst[RIDX(dim-1-j-1, i+3, dim)] = src[RIDX(i+3, j+1, dim)];
                    dst[RIDX(dim-1-j-2, i, dim)] = src[RIDX(i, j+2, dim)];
                    dst[RIDX(dim-1-j-2, i+1, dim)] = src[RIDX(i+1, j+2, dim)];
                    dst[RIDX(dim-1-j-2, i+2, dim)] = src[RIDX(i+2, j+2, dim)];
                    dst[RIDX(dim-1-j-2, i+3, dim)] = src[RIDX(i+3, j+2, dim)];
                    dst[RIDX(dim-1-j-3, i, dim)] = src[RIDX(i, j+3, dim)];
                    dst[RIDX(dim-1-j-3, i+1, dim)] = src[RIDX(i+1, j+3, dim)];
                    dst[RIDX(dim-1-j-3, i+2, dim)] = src[RIDX(i+2, j+3, dim)];
                    dst[RIDX(dim-1-j-3, i+3, dim)] = src[RIDX(i+3, j+3, dim)];
                }
            }
        }
    }

    // int i, j;
    // int jj, kk;

    // if (dim == 64) {
    //     for (i = 0; i < dim; i++)
    //         for (j = 0; j < dim; j++)
    //             dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
    // } else {
    //     int bsize = 16;

    //     if (dim == 1024)
    //         bsize = 4;

    //     for (jj = 0; jj < dim; jj += bsize) {
    //         for (kk = 0; kk < dim; kk += bsize) {
    //             for (i = jj; i < jj + bsize; i++) {
    //                 int j_m = kk + bsize;
    //                 for (j = kk; j < j_m; j+=4) {
    //                     pixel *dptr = dst + RIDX(dim-1-j, i, dim);
    //                     pixel *sptr = src + RIDX(i, j, dim);
    //                     *dptr = *sptr; sptr++; dptr-=dim;
    //                     *dptr = *sptr; sptr++; dptr-=dim;
    //                     *dptr = *sptr; sptr++; dptr-=dim;
    //                     *dptr = *sptr;
    //                 }
    //             }
    //         }
    //     }
    // }


}

char unroll_rotate_descr[] = "rotate: Currentworking version";  
void rotate_unroll(int dim, pixel *src, pixel*dst)  
{  
    int i, j;
    for(i = 0; i < dim; i += 32)
    {
        for(j = dim - 1; j >= 0; j -= 1)
        {       
            pixel *dptr = dst + RIDX(dim-1-j, i, dim);
            pixel *sptr = src + RIDX(i, j, dim);
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr; sptr += dim; dptr++;
            *dptr = *sptr;
        }
    }
}    

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    add_rotate_function(&rotate_unroll, unroll_rotate_descr);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    // Four corners
    // top left corner
    dst[0].red = (src[0].red + src[1].red + src[dim].red + src[dim+1].red) >> 2;
    dst[0].blue = (src[0].blue + src[1].blue + src[dim].blue + src[dim+1].blue) >> 2;
    dst[0].green = (src[0].green + src[1].green + src[dim].green + src[dim+1].green) >> 2;
    // top right corner
    dst[dim-1].red = (src[dim-2].red + src[dim-1].red + src[2*dim-2].red + src[2*dim-1].red) >> 2;
    dst[dim-1].blue = (src[dim-2].blue + src[dim-1].blue + src[2*dim-2].blue + src[2*dim-1].blue) >> 2;
    dst[dim-1].green = (src[dim-2].green + src[dim-1].green + src[2*dim-2].green + src[2*dim-1].green) >> 2;
    // bottom lfet corner
    dst[(dim-1)*dim].red = (src[(dim-2)*dim].red + src[(dim-2)*dim+1].red + src[(dim-1)*dim].red + src[(dim-1)*dim+1].red) >> 2;
    dst[(dim-1)*dim].blue = (src[(dim-2)*dim].blue + src[(dim-2)*dim+1].blue + src[(dim-1)*dim].blue + src[(dim-1)*dim+1].blue) >> 2;
    dst[(dim-1)*dim].green = (src[(dim-2)*dim].green + src[(dim-2)*dim+1].green + src[(dim-1)*dim].green + src[(dim-1)*dim+1].green) >> 2;
    // bottom right corner
    dst[dim*dim-1].red = (src[(dim-1)*dim-2].red + src[(dim-1)*dim-1].red + src[dim*dim-2].red + src[dim*dim-1].red) >> 2;
    dst[dim*dim-1].blue = (src[(dim-1)*dim-2].blue + src[(dim-1)*dim-1].blue + src[dim*dim-2].blue + src[dim*dim-1].blue) >> 2;
    dst[dim*dim-1].green = (src[(dim-1)*dim-2].green + src[(dim-1)*dim-1].green + src[dim*dim-2].green + src[dim*dim-1].green) >> 2;

    int i, j;
    // Four edges
    // top edge
    for(j = 1; j < dim-1; j++){
        dst[j].red = (src[j-1].red + src[j].red + src[j+1].red + src[j+dim-1].red + src[j+dim].red + src[j+dim+1].red) / 6;
        dst[j].blue = (src[j-1].blue + src[j].blue + src[j+1].blue + src[j+dim-1].blue + src[j+dim].blue + src[j+dim+1].blue) / 6;
        dst[j].green = (src[j-1].green + src[j].green + src[j+1].green + src[j+dim-1].green + src[j+dim].green + src[j+dim+1].green) / 6;
    }
    // left edge
    for(i = dim; i < (dim-1)*dim; i += dim){
        dst[i].red = (src[i-dim].red + src[i-dim+1].red + src[i].red + src[i+1].red + src[i+dim].red + src[i+dim+1].red) / 6;
        dst[i].blue = (src[i-dim].blue + src[i-dim+1].blue + src[i].blue + src[i+1].blue + src[i+dim].blue + src[i+dim+1].blue) / 6;
        dst[i].green = (src[i-dim].green + src[i-dim+1].green + src[i].green + src[i+1].green + src[i+dim].green + src[i+dim+1].green) / 6;
    }
    // right edge
    for(i = 2*dim-1; i < dim*dim-1; i += dim){
        dst[i].red = (src[i-dim-1].red + src[i-dim].red + src[i-1].red + src[i].red + src[i+dim-1].red + src[i+dim].red) / 6;
        dst[i].blue = (src[i-dim-1].blue + src[i-dim].blue + src[i-1].blue + src[i].blue + src[i+dim-1].blue + src[i+dim].blue) / 6;
        dst[i].green = (src[i-dim-1].green + src[i-dim].green + src[i-1].green + src[i].green + src[i+dim-1].green + src[i+dim].green) / 6;
    }
    // bottom edge
    for(j = (dim-1)*dim+1; j < dim*dim-1; j++){
        dst[j].red = (src[j-dim-1].red + src[j-dim].red + src[j-dim+1].red + src[j-1].red + src[j].red + src[j+1].red) / 6;
        dst[j].blue = (src[j-dim-1].blue + src[j-dim].blue + src[j-dim+1].blue + src[j-1].blue + src[j].blue + src[j+1].blue) / 6;
        dst[j].green = (src[j-dim-1].green + src[j-dim].green + src[j-dim+1].green + src[j-1].green + src[j].green + src[j+1].green) / 6;
    }

    // Inside
    int index, row, lastr, lastg, lastb;
    for(i = 1; i < dim-1; i++){
        row = i * dim;
        lastr = src[row-dim].red + src[row-dim+1].red + src[row-dim+2].red + 
                src[row].red + src[row+1].red + src[row+2].red + 
                src[row+dim].red + src[row+dim+1].red + src[row+dim+2].red;
        lastb = src[row-dim].blue + src[row-dim+1].blue + src[row-dim+2].blue + 
                src[row].blue + src[row+1].blue + src[row+2].blue + 
                src[row+dim].blue + src[row+dim+1].blue + src[row+dim+2].blue;
        lastg = src[row-dim].green + src[row-dim+1].green + src[row-dim+2].green + 
                src[row].green + src[row+1].green + src[row+2].green + 
                src[row+dim].green + src[row+dim+1].green + src[row+dim+2].green;
        dst[row+1].red = lastr / 9;
        dst[row+1].blue = lastb / 9;
        dst[row+1].green = lastg / 9;
        for(j = 2; j < dim-2; j += 2){
            index = row + j;
            lastr = lastr - src[index-dim-2].red - src[index-2].red - src[index+dim-2].red + 
                            src[index-dim+1].red + src[index+1].red + src[index+dim+1].red;
            lastb = lastb - src[index-dim-2].blue - src[index-2].blue - src[index+dim-2].blue + 
                            src[index-dim+1].blue + src[index+1].blue + src[index+dim+1].blue;
            lastg = lastg - src[index-dim-2].green - src[index-2].green - src[index+dim-2].green + 
                            src[index-dim+1].green + src[index+1].green + src[index+dim+1].green;
            dst[index].red = lastr / 9;
            dst[index].blue = lastb / 9;
            dst[index].green = lastg / 9;
            index = row + j + 1;
            lastr = lastr - src[index-dim-2].red - src[index-2].red - src[index+dim-2].red + 
                            src[index-dim+1].red + src[index+1].red + src[index+dim+1].red;
            lastb = lastb - src[index-dim-2].blue - src[index-2].blue - src[index+dim-2].blue + 
                            src[index-dim+1].blue + src[index+1].blue + src[index+dim+1].blue;
            lastg = lastg - src[index-dim-2].green - src[index-2].green - src[index+dim-2].green + 
                            src[index-dim+1].green + src[index+1].green + src[index+dim+1].green;
            dst[index].red = lastr / 9;
            dst[index].blue = lastb / 9;
            dst[index].green = lastg / 9;
        }
        index = row + dim - 2;
        lastr = lastr - src[index-dim-2].red - src[index-2].red - src[index+dim-2].red + 
                            src[index-dim+1].red + src[index+1].red + src[index+dim+1].red;
        lastb = lastb - src[index-dim-2].blue - src[index-2].blue - src[index+dim-2].blue + 
                            src[index-dim+1].blue + src[index+1].blue + src[index+dim+1].blue;
        lastg = lastg - src[index-dim-2].green - src[index-2].green - src[index+dim-2].green + 
                            src[index-dim+1].green + src[index+1].green + src[index+dim+1].green;
        dst[index].red = lastr / 9;
        dst[index].blue = lastb / 9;
        dst[index].green = lastg / 9;
    }
}


char smooth_unroll_descr[] = "smooth: Storing reused results";
void smooth_unroll(int dim, pixel *src, pixel *dst) 
{
    // Four corners
    // top left corner
    dst[0].red = (src[0].red + src[1].red + src[dim].red + src[dim+1].red) >> 2;
    dst[0].blue = (src[0].blue + src[1].blue + src[dim].blue + src[dim+1].blue) >> 2;
    dst[0].green = (src[0].green + src[1].green + src[dim].green + src[dim+1].green) >> 2;
    // top right corner
    dst[dim-1].red = (src[dim-2].red + src[dim-1].red + src[2*dim-2].red + src[2*dim-1].red) >> 2;
    dst[dim-1].blue = (src[dim-2].blue + src[dim-1].blue + src[2*dim-2].blue + src[2*dim-1].blue) >> 2;
    dst[dim-1].green = (src[dim-2].green + src[dim-1].green + src[2*dim-2].green + src[2*dim-1].green) >> 2;
    // bottom lfet corner
    dst[(dim-1)*dim].red = (src[(dim-2)*dim].red + src[(dim-2)*dim+1].red + src[(dim-1)*dim].red + src[(dim-1)*dim+1].red) >> 2;
    dst[(dim-1)*dim].blue = (src[(dim-2)*dim].blue + src[(dim-2)*dim+1].blue + src[(dim-1)*dim].blue + src[(dim-1)*dim+1].blue) >> 2;
    dst[(dim-1)*dim].green = (src[(dim-2)*dim].green + src[(dim-2)*dim+1].green + src[(dim-1)*dim].green + src[(dim-1)*dim+1].green) >> 2;
    // bottom right corner
    dst[dim*dim-1].red = (src[(dim-1)*dim-2].red + src[(dim-1)*dim-1].red + src[dim*dim-2].red + src[dim*dim-1].red) >> 2;
    dst[dim*dim-1].blue = (src[(dim-1)*dim-2].blue + src[(dim-1)*dim-1].blue + src[dim*dim-2].blue + src[dim*dim-1].blue) >> 2;
    dst[dim*dim-1].green = (src[(dim-1)*dim-2].green + src[(dim-1)*dim-1].green + src[dim*dim-2].green + src[dim*dim-1].green) >> 2;

    int i, j;
    // Four edges
    // top edge
    for(j = 1; j < dim-1; j++){
        dst[j].red = (src[j-1].red + src[j].red + src[j+1].red + src[j+dim-1].red + src[j+dim].red + src[j+dim+1].red) / 6;
        dst[j].blue = (src[j-1].blue + src[j].blue + src[j+1].blue + src[j+dim-1].blue + src[j+dim].blue + src[j+dim+1].blue) / 6;
        dst[j].green = (src[j-1].green + src[j].green + src[j+1].green + src[j+dim-1].green + src[j+dim].green + src[j+dim+1].green) / 6;
    }
    // left edge
    for(i = dim; i < (dim-1)*dim; i += dim){
        dst[i].red = (src[i-dim].red + src[i-dim+1].red + src[i].red + src[i+1].red + src[i+dim].red + src[i+dim+1].red) / 6;
        dst[i].blue = (src[i-dim].blue + src[i-dim+1].blue + src[i].blue + src[i+1].blue + src[i+dim].blue + src[i+dim+1].blue) / 6;
        dst[i].green = (src[i-dim].green + src[i-dim+1].green + src[i].green + src[i+1].green + src[i+dim].green + src[i+dim+1].green) / 6;
    }
    // right edge
    for(i = 2*dim-1; i < dim*dim-1; i += dim){
        dst[i].red = (src[i-dim-1].red + src[i-dim].red + src[i-1].red + src[i].red + src[i+dim-1].red + src[i+dim].red) / 6;
        dst[i].blue = (src[i-dim-1].blue + src[i-dim].blue + src[i-1].blue + src[i].blue + src[i+dim-1].blue + src[i+dim].blue) / 6;
        dst[i].green = (src[i-dim-1].green + src[i-dim].green + src[i-1].green + src[i].green + src[i+dim-1].green + src[i+dim].green) / 6;
    }
    // bottom edge
    for(j = (dim-1)*dim+1; j < dim*dim-1; j++){
        dst[j].red = (src[j-dim-1].red + src[j-dim].red + src[j-dim+1].red + src[j-1].red + src[j].red + src[j+1].red) / 6;
        dst[j].blue = (src[j-dim-1].blue + src[j-dim].blue + src[j-dim+1].blue + src[j-1].blue + src[j].blue + src[j+1].blue) / 6;
        dst[j].green = (src[j-dim-1].green + src[j-dim].green + src[j-dim+1].green + src[j-1].green + src[j].green + src[j+1].green) / 6;
    }

    // Inside
    int index, row;
    for(i = 1; i < dim-1; i++){
        row = i * dim;
        for(j = 1; j < dim-1; j += 2){
            index = row + j;
            dst[index].red = (src[index-dim-1].red + src[index-dim].red + src[index-dim+1].red + 
                                src[index-1].red + src[index].red + src[index+1].red + 
                                src[index+dim-1].red + src[index+dim].red + src[index+dim+1].red) / 9;
            dst[index].blue = (src[index-dim-1].blue + src[index-dim].blue + src[index-dim+1].blue + 
                                src[index-1].blue + src[index].blue + src[index+1].blue + 
                                src[index+dim-1].blue + src[index+dim].blue + src[index+dim+1].blue) / 9;
            dst[index].green = (src[index-dim-1].green + src[index-dim].green + src[index-dim+1].green + 
                                src[index-1].green + src[index].green + src[index+1].green + 
                                src[index+dim-1].green + src[index+dim].green + src[index+dim+1].green) / 9;
            index = row + j + 1;
            dst[index].red = (src[index-dim-1].red + src[index-dim].red + src[index-dim+1].red + 
                                src[index-1].red + src[index].red + src[index+1].red + 
                                src[index+dim-1].red + src[index+dim].red + src[index+dim+1].red) / 9;
            dst[index].blue = (src[index-dim-1].blue + src[index-dim].blue + src[index-dim+1].blue + 
                                src[index-1].blue + src[index].blue + src[index+1].blue + 
                                src[index+dim-1].blue + src[index+dim].blue + src[index+dim+1].blue) / 9;
            dst[index].green = (src[index-dim-1].green + src[index-dim].green + src[index-dim+1].green + 
                                src[index-1].green + src[index].green + src[index+1].green + 
                                src[index+dim-1].green + src[index+dim].green + src[index+dim+1].green) / 9;
        }
    }
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&smooth_unroll, smooth_unroll_descr);
    /* ... Register additional test functions here */
}

