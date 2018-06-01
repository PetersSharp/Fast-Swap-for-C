#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fswap.h"

#define __NELE(A)      (sizeof(A) / sizeof(A[0]))

int main(void)
{
    int i;
    int ia = 10, ib = 20, *pia = &ia, *pib = &ib;
    int iaa[] = { 1, 2, 3, 4, 5}, iba[] = { 6, 7, 8, 9, 0 };
    char sa[] = "qwerty", sb[] = "ytrewq", *psa = sa, *psb = sb;
    float fa = 0.456, fb = 0.789, *pfa = &fa, *pfb = &fb;
    double da = 0.123, db = 0.456, *pda = &da, *pdb = &db;

    printf("%d)\tInt*      pia = %d, pib = %d\n", __LINE__, *pia, *pib);
    __swap_wrapper(pia, pib);
    printf("%d)\tInt*      pia = %d, pib = %d\n", __LINE__, *pia, *pib);

    printf("%d)\tInt Array iaa = {", __LINE__);
    for (i = 0; i < __NELE(iaa); i++)
    {
        printf(" %d,", iaa[i]);
    }
    printf(" }\n");

    __swap_wrapper(iaa, iba);

    printf("%d)\tInt Array iaa = {", __LINE__);
    for (i = 0; i < __NELE(iaa); i++)
    {
        printf(" %d,", iaa[i]);
    }
    printf(" }\n");

    printf("%d)\tChar*     psa = %s, psb = %s\n", __LINE__, psa, psb);
    __swap_wrapper(psa, psb);
    printf("%d)\tChar*     psa = %s, psb = %s\n", __LINE__, psa, psb);

    printf("%d)\tChar[]    sa  = %s, sb = %s\n",  __LINE__, sa, sb);
    __swap_wrapper(sa, sb);
    printf("%d)\tChar[]    sa  = %s, sb = %s\n",  __LINE__, sa, sb);

    printf("%d)\tDouble*   pda = %f, pdb = %f\n", __LINE__, *pda, *pdb);
    __swap_wrapper(pda, pdb);
    printf("%d)\tDouble*   pda = %f, pdb = %f\n", __LINE__, *pda, *pdb);

    printf("%d)\tFloat*    pfa  = %f, pfb = %f\n", __LINE__, *pfa, *pfb);
    __swap_wrapper(pfa, pfb);
    printf("%d)\tFloat*    pfa  = %f, pfb = %f\n", __LINE__, *pfa, *pfb);

    return 0;
}
