/*
 * =====================================================================================
 *
 *       Filename:  msort.c
 *
 *    Description:  Implementation of the merge sort algorithm
 *
 *        Version:  1.0
 *        Created:  16.08.2015 13:38:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "msort.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int32_t i;
	int32_t src[5] = {5,545,4,78,-4};
	msort(src,0,4);
	for (i = 0; i < 5; i++)
		printf(" %d",src[i]);
	printf("\n");
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  msort
 *  Description:  recursive merge sort with a nlog(n) run time
 * =====================================================================================
 */
	void
msort (int32_t *src, uint32_t start,uint32_t finish)
{
	uint32_t q;
	if (start < finish)
	{
		q = (uint32_t) (start + finish)/2 ;
		msort(src,start,q);
		msort(src,q + 1,finish);
		merge(src,start,q,finish);
	}
}		/* -----  end of function msort  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  merge
 *  Description:  src[p..q] and src[q + 1..r] are sorted instances from src
 * =====================================================================================
 */
	void
merge (int32_t *src, uint32_t p, uint32_t q, uint32_t r)
{
	uint32_t n1;
	uint32_t n2;
	uint32_t i;
	uint32_t j;
	uint32_t k;
	int32_t *L;
	int32_t *R;
	n1 = q - p + 1;
	n2 = r - q;
	L = (int32_t*) malloc(n1*sizeof(int32_t));
	R = (int32_t*) malloc(n2*sizeof(int32_t));
	
	/*TODO: change for memcpy  */
	for ( i = 0; i < n1; i += 1 ) 
	{
		L[i] = src[p + i];
	}	
	
	for ( j = 0; j < n2; j += 1 ) 
	{
		R[j] = src[q + j + 1];
	}
	
	L[n1] = INT32_MAX;
	R[n2] = INT32_MAX;
	i = 0;
	j = 0;
	
	for ( k = p; k <= r; k += 1 ) {
		if (L[i] <= R[j])
		{
			src[k] = L[i];
			i = i + 1;
		}
		else
		{
			src[k] = R[j];
			j = j + 1;
		}
	}
	free(L);
	free(R);

}		/* -----  end of function merge  ----- */