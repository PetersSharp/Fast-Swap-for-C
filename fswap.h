//--------------------------------------------------------------------------------------
//
//    Fast swap for C
//    inspire: https://ru.stackoverflow.com/questions/836089/%d0%9e%d0%b1%d0%bc%d0%b5%d0%bd-%d1%87%d0%b5%d1%80%d0%b5%d0%b7-%d1%83%d0%ba%d0%b0%d0%b7%d0%b0%d1%82%d0%b5%d0%bb%d0%b8/836167#836167
//    online example: http://coliru.stacked-crooked.com/a/be12a57be0162860
//    require: GCC
//    build example: gcc --std=c99 -O2 -Wall -pedantic -funit-at-a-time swap-test.c ; ./a.out
//    Copyright (C) 2018, @PS
//
//     - https://github.com/PetersSharp/Fast-Swap-for-C
//
//    * $Id$
//    * commit date: $Format:%cd by %aN$
//
//--------------------------------------------------------------------------------------

#ifndef FAST_SWAP_H
#define FAST_SWAP_H

#define __swap_wrapper(A,B) __extension__ \
    (__builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), int[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const int[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned int[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned int[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), short[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const short[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned short[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned short[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), long long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const long long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned long long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned const long long[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), char*), __swap_p((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const char*), __swap_p((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), char[]), __swap(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const char[]), __swap(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned char*), __swap_p((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned char*), __swap_p((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned char[]), __swap(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned char[]), __swap(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), void*), __swap_p((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const void*), __swap_p((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), void[]), __swap(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const void[]), __swap(A, B, sizeof(A), sizeof(B)), \
    __swap(A, B, sizeof(*A), sizeof(*B)))))))))))))))))))))))))))))))


__attribute__((always_inline)) void __swap_p(void **a, void **b) {
    void *c = *a;
    *a = *b; *b = c;
}

__attribute__((always_inline)) void __swap(void *a, void *b, size_t na, size_t nb)
{
    if ((!na) || (na != nb)) { return; }

    char *va = (char*)a,
         *vb = (char*)b;

    if (va == vb) { return; }

    __builtin_prefetch(va + na, 1, 1);
    __builtin_prefetch(vb + nb, 1, 1);

    while (na--)
    {
        va[na] ^= vb[na];
        vb[na] ^= va[na];
        va[na] ^= vb[na];
    }
}

#endif
