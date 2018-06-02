Fast swap for C (gcc required), use only the header file [_fswap.h_](https://github.com/PetersSharp/Fast-Swap-for-C/blob/master/fswap.h).

A functional combine producing swap objects of any types.
- Automatic calculation of the size of the element to be swapped.
- Check the dimension of both elements.
- Checking the identity of both elements.
- High speed of data processing.
- Support C99 and above.

To connect to your project, you need to declare a one header file:

```C
#include "fswap.h"
```

Call swap method:
```C
/* obj1, obj2 - any C types. */
__swap_fast(obj1, obj2);
```

If you use own structures in an array format, you will need to add their description to [_fswap.h_](
https://github.com/PetersSharp/Fast-Swap-for-C/blob/master/fswap.h), example:
```C
 __builtin_choose_expr( \
   __builtin_types_compatible_p(__typeof__(A), struct my_struct[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
```
