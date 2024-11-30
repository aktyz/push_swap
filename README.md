# General idea

I want to implement the stacs as lists of integers.
Right now I think I will need:
- structure for stack as a list
- functions to sort the stack
- functions to modify the order of items on the list
- function to iterate throught a list

DONE => best is to really crete the functions for Libft BONUS and then re-use them here with the stack or/and stack item structure.

DONE => Enrich Libft with gnl and printf to handle the reading and output of your push_swap program

DONE => Copy Libft into this project and construct Makefile that will pick it up

> From subject PDF:
> - *Your project’s Makefile must compile the library by using its Makefile, then compile the project.*
> - *your Makefile must not relink*

DONE => Learn operations on **ptr...  -.-

DONE => TDD: write tests for parse_arg() function

DONE => Complete parse_arg() function as per subject requirements, reading from terminal argument missing

> PICK-UP: the solution is too long for 100 and 500 numbers :(

TODO =><br>
- [x] Valgrind runs x2<br>
- [x] the solution is too long for 100 and 500 numbers :(<br>
- [x] norminette!!!!<br>


- [x] REMOVE wildcards from Makefiles<br>
- [x] run Valgrind check
- [x] refactor heap utils - creation of the list uses heapadd() - to remove last leak
> - [x] errors check: some arguments are bigger than an integer<br>
> - [x] errors check: some arguments are not numbers<br>
- [x] remove the last leak<br>
- [x] resolve segmentation fault - most probably in the last developed funcitons (not tested)
- [x] ft_get_lowest_cost_node(*a, *b); // returning a pointer to the node with the lowest operation cost<br>
- [x] ft_push_b_correct_place(**a, **b); // returning void;<br>
- [x] ft_push_a_correct_place(**a, **b); // returning void;<br>
- [x] add unit tests to the cost calculation functions to make sure we get a sorted array in the end<br><br>
- [x] check how arguments should be passed to your main: string or many argv<br>
- [x] split heap_utils.c into separate files depending on function<br>
- [x] correct ft_nb_at_head() to account for the direction of the rotation<br>
- [x] correct return from ft_node_cost_calculation - depeinding on the combination of positive negative a & b rotations<br>
- [x] remove unusued "initial index of the node"<br>
- [x] revrite ft_heap_new(**heap) & ft_heap_add(**heap)<br><br>

OUTOFSCOPE for Eval:
- [x] move check on ints from parse_args and parse_string_arg to a separate funciton<br>

# Difficult norm remaining
## SRC
```
./src/push_swap_utils.c: Error!
Error: TOO_MANY_LINES       (line:  68, col:   1):	Function has more than 25 lines
Error: TOO_MANY_LINES       (line: 106, col:   1):	Function has more than 25 lines
Error: TOO_MANY_LINES       (line: 196, col:   1):	Function has more than 25 lines

./src/push_swap.c: Error!
Error: TOO_MANY_LINES       (line:  73, col:   1):	Function has more than 25 lines

./src/heap_check.c: Error!
Error: TOO_MANY_LINES       (line:  74, col:   1):	Function has more than 25 lines
```

### LIBFT (?)

#### Leaks correction in ft_split

==34246== HEAP SUMMARY:
==34246==     in use at exit: 40 bytes in 4 blocks
==34246==   total heap usage: 9 allocs, 5 frees, 136 bytes allocated
==34246== 
==34246== 8 bytes in 3 blocks are still reachable in loss record 1 of 2
==34246==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==34246==    by 0x4052A2: ft_allocate_word (ft_split.c:42)
==34246==    by 0x4051A0: ft_allocate_words (ft_split.c:65)
==34246==    by 0x40503D: ft_split (ft_split.c:30)
==34246==    by 0x402FED: parse_string_arg (push_swap_utils.c:34)
==34246==    by 0x403928: main (push_swap.c:26)
==34246== 
==34246== 32 bytes in 1 blocks are still reachable in loss record 2 of 2
==34246==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==34246==    by 0x40500E: ft_split (ft_split.c:27)
==34246==    by 0x402FED: parse_string_arg (push_swap_utils.c:34)
==34246==    by 0x403928: main (push_swap.c:26)


## TEST
```
./test/heap_swap_test.c: Error!
Error: TOO_MANY_LINES       (line:  45, col:   1):	Function has more than 25 lines

./test/heap_reverse_rotate_test.c: Error!
Error: TOO_MANY_LINES       (line:  45, col:   1):	Function has more than 25 lines

./test/heap_utils_test.c: Error!
Error: TOO_MANY_LINES       (line:  48, col:   1):	Function has more than 25 lines

./test/heap_cost_calculation_test.c: Error!
Error: TOO_MANY_LINES       (line:  70, col:   1):	Function has more than 25 lines
Error: TOO_MANY_LINES       (line: 115, col:   1):	Function has more than 25 lines
Error: TOO_MANY_LINES       (line: 163, col:   1):	Function has more than 25 lines

./test/push_swap_utils_test.c: Error!
Error: TOO_MANY_LINES       (line:  45, col:   1):	Function has more than 25 lines

./test/heap_check_test.c: Error!
Error: TOO_MANY_LINES       (line:  56, col:   1):	Function has more than 25 lines
```

# Short notes on Makefiles

Knowledge used in Makefile:
For examples have a look at the actual [Makefile](Makefile) in this project.
- [The patsubst Function](https://ocw.mit.edu/courses/1-124j-foundations-of-software-engineering-fall-2000/pages/lecture-notes/gnu_makefile_documentation/#TOC77)
```
$(patsubst pattern,replacement,text)
```
Finds whitespace-separated words in text that match pattern and replaces them with replacement. Here pattern may contain a % which acts as a wildcard, matching any number of any characters within a word. If replacement also contains a %, the % is replaced by the text that matched the % in pattern. % characters in patsubst function invocations can be quoted with preceding backslashes (\&grave;). Backslashes that would otherwise quote %characters can be quoted with more backslashes. Backslashes that quote%characters or other backslashes are removed from the pattern before it is compared file names or has a stem substituted into it. Backslashes that are not in danger of quoting%characters go unmolested. For example, the patternthe\%weird\%pattern\&grave; has the%weird\&grave; preceding the operative %character, andpattern\&grave; following it. The final two backslashes are left alone because they cannot affect any % character. Whitespace between words is folded into single space characters; leading and trailing whitespace is discarded. For example,
```
$(patsubst %.c,%.o,x.c.c bar.c)
```
produces the value x.c.o bar.o.





