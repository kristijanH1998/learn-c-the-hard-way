#ifndef __cases_h__
#define __cases_h__

#define cases(n) {  case n-1:\
                    *to++ = *from++;\
                    case n-2:\
                    *to++ = *from++;\
                    case n-3:\
                    *to++ = *from++;\
                    case n-4:\
                    *to++ = *from++;\
                    case n-5:\
                    *to++ = *from++;\
                    case n-6:\
                    *to++ = *from++;\
                    case n-7:\
                    *to++ = *from++;\
                }

// #define duffs_device_len_n(cond, n, decr) while(cond) {*to++ = *from++; cases(n); n = n - decr;}

#endif