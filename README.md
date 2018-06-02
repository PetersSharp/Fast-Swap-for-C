# Fast Swap for C

[![Build Status](https://travis-ci.org/PetersSharp/Fast-Swap-for-C.svg)](https://travis-ci.org/PetersSharp/Fast-Swap-for-C)
[![codecov.io](https://codecov.io/github/PetersSharp/Fast-Swap-for-C/coverage.svg?branch=master)](https://codecov.io/github/PetersSharp/Fast-Swap-for-C?branch=master)
[![Coverage Status](https://codeclimate.com/github/PetersSharp/Fast-Swap-for-C/badges/coverage.svg)](https://codeclimate.com/github/PetersSharp/Fast-Swap-for-C/coverage)
[![Code Climate](https://codeclimate.com/github/PetersSharp/Fast-Swap-for-C/badges/gpa.svg)](https://codeclimate.com/github/PetersSharp/Fast-Swap-for-C)

Fast swap for C (gcc required), included 

A functional combine producing swap objects of any types.
- Automatic calculation of the size of the element to be swapped.
- Check the dimension of both elements.
- Checking the identity of both elements.
- High speed of data processing.
- Support C99 and above.

To connect to your project, you need to declare a one header file:

````
#include "fswap.h"
````

Call swap method:
````
/* obj1, obj2 - any C types. */
__swap_fast(obj1, obj2);
````

If you use own structures in an array format, you will need to add their description to _fswap.x_, example:
````
 __builtin_choose_expr( \
   __builtin_types_compatible_p(__typeof__(A), struct my_struct[]), __swap_p(A, B, sizeof(A), sizeof(B)), \
````



Inspire:        [ru.stackoverflow.com](https://ru.stackoverflow.com/questions/836089/%d0%9e%d0%b1%d0%bc%d0%b5%d0%bd-%d1%87%d0%b5%d1%80%d0%b5%d0%b7-%d1%83%d0%ba%d0%b0%d0%b7%d0%b0%d1%82%d0%b5%d0%bb%d0%b8/836167#836167)  
OnLine example: [coliru.stacked-crooked.com](http://coliru.stacked-crooked.com/a/be12a57be0162860)  
Git repository: [github](https://github.com/PetersSharp/Fast-Swap-for-C)  
Web:            [home](https://peterssharp.github.io/Fast-Swap-for-C/)   

