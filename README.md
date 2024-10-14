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

> PICK-UP: start working on cost-calculation function

IN_PROGRESS => implement Turk algorithm<br>
- [ ] ft_cost_calculation(*a, *b); // returning a pointer to the new head with the cheapest<br>
- [ ] ft_push_b_correct_place(**a, **b); // returning void;<br>
- [ ] ft_push_a_correct_place(**a, **b); // returning void;<br>

TODO =><br>
- [ ] errors check: some arguments aren’t integers<br>
- [ ] errors check: some arguments are bigger than an integer<br>
- [x] remove unusued "initial index of the node"<br>
- [x] revrite ft_heap_new(**heap) & ft_heap_add(**heap)<br>
- [ ] check how arguments should be passed to your main: string or many argv<br>
- [ ] REMOVE wildcards from Makefiles<br>
- [ ] split heap_utils.c into separate files depending on function<br>
- [ ] norminette!!!!<br><br>

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





