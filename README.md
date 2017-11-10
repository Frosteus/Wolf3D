# Libft
Library which I made as part of a learning process in UNIT Factory.
This library includes custom realization of standart functions. Also it includes other useful functions and algorithms for projects. 
Use "make" command to compile library. Makefile contains make, clean, fclean commands.
libft.h includes all necessary structures and all function prototypes.

Standart C library functions:
abs() and fabs()
atoi()
isalnum()
isalpha()
isdigit()
isprint()
isspace()
memchr()
memcmp()
memcpy()
memmove()
memset()
putchar()
strcat()
strchr()
strcmp()
strcpy()
strlen()
strncat()
strncmp()
strncpy()
strrchr()
strstr()
tolower()
toupper()

Additional ~nix and other functions (due to project subject):
bzero()
isascii()
itoa()
itoa_base ()
lstadd() - linked list - add node function.
lstdel() - linked list - delete list function.
lstdelone() - linked list - delete node function.
lstiter() - linked list - use function on list link (It's need rework).
lstmap() - linked list - use function on list link and create new list  (It's need rework).
memalloc()
memccpy()
memdel()
putchar_fd()
putendl()
putendl_fd()
putnbr()
putnbr_fd()
putstr()
putstr_fd()
strclr()
strdel()
strdup()
strequ()
striter()
striteri()
strjoin()
strlcat()
strmap()
strmapi()
strnequ()
strnew()
strnstr()
strrev()
strsplit()
strsub()
strtrim()

Custom functions and algorithms:
ft_binary_search() - realization of binary search algorithm.
ft_quicksort() - realization of quick sort algorithm.
ft_sqrt() - custom realization of sqrt function.
ft_str_word_ctr() - this function counts "words" in str pointer delimited with specified character.
ft_swap() - function to swap two values by pointers using memcpy.
