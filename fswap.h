//--------------------------------------------------------------------------------------
//
//    Fast swap for C
//    inspire: https://ru.stackoverflow.com/questions/836089/%d0%9e%d0%b1%d0%bc%d0%b5%d0%bd-%d1%87%d0%b5%d1%80%d0%b5%d0%b7-%d1%83%d0%ba%d0%b0%d0%b7%d0%b0%d1%82%d0%b5%d0%bb%d0%b8/836167#836167
//    online example: http://coliru.stacked-crooked.com/a/be12a57be0162860
//    require: GCC
//    build example: gcc --std=gnu99 -O2 -Wall -pedantic -funit-at-a-time swap-test.c ; ./a.out
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
/**
 * @file ./fswap.h
 * @mainpage Fast swap for C, any types to any types
 * @brief Fast swap public library header
 *
 * - Reference @ref: fswap.h
 * - Main macro ::__swap_fast(A,B)
 *
 * A functional combine producing swap objects of any types.
 *
 *  - Automatic calculation of the size of the item to be exchanged (swapped).
 *  - Check the dimension of both elements.
 *  - Checking the identity of both elements.
 *  - High speed of data processing.
 *  - Support C99 and above.
 *
 * Basic example for usage: @ref swap-example
 *
 * Testing automatic swapped types, run:
 * @code{.sh}
 *    make; ./swap-test
 * @endcode
 *
 * Show support types, run:
 * @code{.sh}
 *    make types
 * @endcode
 *
 * @see https://peterssharp.github.io/Fast-Swap-for-C/ [Web Home]
 * @see https://github.com/PetersSharp/Fast-Swap-for-C [Git Home]
 * @see https://github.com/PetersSharp/Fast-Swap-for-C/blob/master/swap-test.c [Test source example]
 * @see http://coliru.stacked-crooked.com/a/be12a57be0162860 [OnLine test example]
 *
 * @copyright  2018 (c) PS
 */

/**
 * @brief Main swap routine macro, not use other functions directly.
 *        In the macro, the type of object and its size are determined.
 *        Depending on this, the function and the swap (copy) mode are selected.
 * @param A: any C types, equals B.
 * @param B: any C types, equals A.
 *
 * Example:
 *
 */
/**
 * \htmlonly
 * Variable A, B - any C types pointer.
 * \endhtmlonly
 * @snippet ./swap-test.c Swap int declare
 * @snippet ./swap-test.c Swap int example
 *
 * @snippet ./swap-test.c Swap int array declare
 * @snippet ./swap-test.c Swap int array example
 *
 */
/**
 * \manonly
 * Variable obj1, obj2 - any C types pointer, 
 * __swap_fast(obj1, obj2);
 * \endmanonly
 */
/**
 * @note
 *     1. To connect to your project, you need to declare a one header file fswap.h
 *     2. If you use own structures in an array format, you will need to add their description to fswap.h
 *     3. All functions that are automatically selected by ::__swap_fast(A,B), do not use them directly.
 */
#define __swap_fast(A,B) __extension__ \
    (__builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), int[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const int[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned int[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned int[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), short[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const short[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned short[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned short[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), long long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const long long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned long long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned const long long[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), char*), __swap_pp((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const char*), __swap_pp((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), char[]), __swap_p(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const char[]), __swap_p(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned char*), __swap_pp((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned char*), __swap_pp((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), unsigned char[]), __swap_p(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const unsigned char[]), __swap_p(A, B, (sizeof(A) - 1), (sizeof(B) - 1)), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), void*), __swap_pp((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const void*), __swap_pp((void**)&A, (void**)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), void*[]), __swap_ppp((void***)&A, (void***)&B), \
            __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(A), const void*[]), __swap_ppp((void***)&A, (void***)&B), \
    __swap_p(A, B, sizeof(*A), sizeof(*B)))))))))))))))))))))))))))))))

/**
 * @brief Swap triple pointers types.
 * @param a: any C types triple pointer, equals type b.
 * @param b: any C types triple pointer, equals type a.
 * @see __swap_fast
 * @attention
 *     1. variable 'a' and 'b' must not be equal.
 *     2. do not use this function directly.
 */
__attribute__((always_inline)) inline void __swap_ppp(void ***a, void ***b)
{
    void **c = *a;
    *a = *b; *b = c;
}

/**
 * @brief Swap double pointers types.
 * @param a: any C types double pointer, equals type b.
 * @param b: any C types double pointer, equals type a.
 * @see __swap_fast
 * @attention
 *     1. variable 'a' and 'b' must not be equal.
 *     2. do not use this function directly.
 */
__attribute__((always_inline)) inline void __swap_pp(void **a, void **b)
{
    void *c = *a;
    *a = *b; *b = c;
}

/**
 * @brief Swap all sized types.
 * @param a: any C types pointer, equals type b.
 * @param b: any C types pointer, equals type a.
 * @param na: swap size to a type.
 * @param nb: swap size to b type.
 * @see __swap_fast
 * @attention
 *     1. variable 'a' and 'b' must not be equal.
 *     2. variable 'na' and 'nb' must be equal.
 *     3. do not use this function directly.
 */
__attribute__((always_inline)) inline void __swap_p(void *a, void *b, size_t na, size_t nb)
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
