/**
 * @file swap-example
 * @brief Fast swap - basic example for usage.
 * \include ./swap-test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fswap.h"

#define __NELE(A)      (sizeof(A) / sizeof(A[0]))

int main(void)
{
    int i;
//! [Swap int declare]

    int ia = 10, ib = 20, *pia = &ia, *pib = &ib;

//! [Swap int declare]
//! [Swap int array declare]

    int iaa[] = { 1, 2, 3, 4, 5 }, iba[] = { 6, 7, 8, 9, 0 };

//! [Swap int array declare]
    char sa[] = "qwerty", sb[] = "ytrewq", *psa = sa, *psb = sb;
    float fa = 0.456, fb = 0.789, *pfa = &fa, *pfb = &fb;
    double da = 0.123, db = 0.456, *pda = &da, *pdb = &db;

//! [Swap int example]

    printf("%d)\tInt*      pia = %d, pib = %d\n", __LINE__, *pia, *pib);

    __swap_fast(pia, pib);

    printf("%d)\tInt*      pia = %d, pib = %d\n", __LINE__, *pia, *pib);

//! [Swap int example]

    printf("%d)\tInt Array iaa = {", __LINE__);
    for (i = 0; i < __NELE(iaa); i++)
    {
        printf(" %d,", iaa[i]);
    }
    printf(" }\n");

//! [Swap int array example]

    __swap_fast(iaa, iba);

    printf("%d)\tInt Array iaa = {", __LINE__);
    for (i = 0; i < __NELE(iaa); i++)
    {
        printf(" %d,", iaa[i]);
    }
    printf(" }\n");

//! [Swap int array example]

    printf("%d)\tChar*     psa = %s, psb = %s\n", __LINE__, psa, psb);
    __swap_fast(psa, psb);
    printf("%d)\tChar*     psa = %s, psb = %s\n", __LINE__, psa, psb);

    printf("%d)\tChar[]    sa  = %s, sb = %s\n",  __LINE__, sa, sb);
    __swap_fast(sa, sb);
    printf("%d)\tChar[]    sa  = %s, sb = %s\n",  __LINE__, sa, sb);

    printf("%d)\tDouble*   pda = %f, pdb = %f\n", __LINE__, *pda, *pdb);
    __swap_fast(pda, pdb);
    printf("%d)\tDouble*   pda = %f, pdb = %f\n", __LINE__, *pda, *pdb);

    printf("%d)\tFloat*    pfa  = %f, pfb = %f\n", __LINE__, *pfa, *pfb);
    __swap_fast(pfa, pfb);
    printf("%d)\tFloat*    pfa  = %f, pfb = %f\n", __LINE__, *pfa, *pfb);

    return 0;
}
