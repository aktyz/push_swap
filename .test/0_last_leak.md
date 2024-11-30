# valgrind --leak-check=full ./push_swap $ARG
```
==52050== Memcheck, a memory error detector
==52050== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==52050== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==52050== Command: ./push_swap 67\ 4\ 9\ 68\ -10
==52050== 
Error
==52050== 
==52050== HEAP SUMMARY:
==52050==     in use at exit: 0 bytes in 0 blocks
==52050==   total heap usage: 15 allocs, 15 frees, 238 bytes allocated
==52050== 
==52050== All heap blocks were freed -- no leaks are possible
==52050== 
==52050== For lists of detected and suppressed errors, rerun with: -s
==52050== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
# valgrind --leak-check=full ./push_swap 4 76 8
```
==52200== Memcheck, a memory error detector
==52200== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==52200== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==52200== Command: ./push_swap 67 4 9 68 -10
==52200== 
Error
==52200== 
==52200== HEAP SUMMARY:
==52200==     in use at exit: 0 bytes in 0 blocks
==52200==   total heap usage: 9 allocs, 9 frees, 176 bytes allocated
==52200== 
==52200== All heap blocks were freed -- no leaks are possible
==52200== 
==52200== For lists of detected and suppressed errors, rerun with: -s
==52200== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
