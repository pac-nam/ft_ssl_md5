# Libft

The libft project takes up the concept of the D06 of the swimming pool, to make you write a library of useful functions that you can then use in the vast majority of your C projects this year and save you a lot of time.

This project ask you to write a lot of code that you have already done during the pool, which makes it a great time to take stock of your progress.

## Function

### Char function

| name | man |
| ---- | ---- |
| [ft_isalnum](srcs/char/ft_isalnum.c) | Check for any character for which ft_isalpha or ft_isdigit is true. |
| [ft_isalpha](srcs/char/ft_isalpha.c) | Check for any character for which ft_isupper or ft_islower is true. |
| [ft_isascii](srcs/char/ft_isascii.c) | Check for an ASCII character. |
| [ft_iscntrl](srcs/char/ft_iscntrl.c) | Check for any control character. |
| [ft_isdigit](srcs/char/ft_isdigit.c) | Check for a decimal digit character. |
| [ft_isprint](srcs/char/ft_isprint.c) | Check for any printing character, including space. |
| [ft_ispunct](srcs/char/ft_ispunct.c) | Check for a punctuation character. |
| [ft_isspace](srcs/char/ft_isspace.c) | Check for the white-space characters. |
| [ft_isxdigit](srcs/char/ft_isxdigit.c) | Check tests for any hexadecimal-digit character. |
| [ft_tolower](srcs/char/ft_tolower.c) | Converts an upper-case letter to the corresponding lowercase letter. |
| [ft_toupper](srcs/char/ft_toupper.c) | Converts a lower-case letter to the corresponding uppercase letter. |

### Conversion functions

| nom | man |
| ---- | ---- |
| [ft_atoi](srcs/conversion/ft_atoi.c) | Function converts the initial portion of the string pointed to by str to an int representation. |
| [ft_atoll](srcs/conversion/ft_atoll.c) | Function converts the initial portion of the string pointed to by str to a long long representation. |
| [ft_conv_utf8](srcs/conversion/ft_conv_utf8.c) | Function converts the wildchar string pointed to by str into allocated string. |
| [ft_dtoa](srcs/conversion/ft_dtoa.c) | Function converts a double into a allocate string. |
| [ft_intlen_base](srcs/conversion/ft_intlen_base.c) | Return the len of the int with a given base. |
| [ft_intlen](srcs/conversion/ft_intlen.c) | Return the len of an int. |
| [ft_itoa_base](srcs/conversion/ft_itoa_base.c) | Function converts an int with a base into a allocate string.. |
| [ft_itoa_no_malloc](srcs/conversion/int/ft_itoa_no_malloc.c) | Function converts an int into bufferized string. |
| [ft_itoa](srcs/conversion/ft_itoa.c) | Function converts a int into allocate string. |
| [ft_lllen](srcs/conversion/ft_lllen.c) | Return the len of a long long. |
| [ft_lltoa](srcs/conversion/ft_lltoa.c) | Function converts a long long into a allocate string. |
| [ft_ulltoa_base](srcs/conversion/ft_ulltoa_base.c) | Function converts an unsigned long long with a base into allocate string. |
| [ft_wc_convert](srcs/conversion/ft_wc_convert.c) | Function convert a wildchar to string. |
| [ft_wcs_convert](srcs/conversion/ft_wcs_convert.c) | Function convert wildchar string to string. |

### List functions

| name | man |
| ---- | ---- |
| [ft_lstadd](srcs/list/ft_lstadd.c) | Add an element to the begin of the list. |
| [ft_lstdel](srcs/list/ft_lstdel.c) | Delete the list. |
| [ft_lstdelone](srcs/list/ft_lstdelone.c) | Delete the first element of the list. |
| [ft_lstiter](srcs/list/ft_lstiter.c) | Use the given function on each element of the list. |
| [ft_lstmap](srcs/list/ft_lstmap.c) | Use the given function on each element of the list, return a new allocated list. |
| [ft_lstnew](srcs/list/ft_lstnew.c) | Create a new list. |
| [ft_lstpushback](srcs/list/ft_lstpushback.c) | Add an element to the end of the list. |
| [ft_lstrev](srcs/list/ft_lstrev.c) | Reverse the list order. |
| [ft_lstsize](srcs/list/ft_lstsize.c) | Return the list size. |

### Fonctions de math

| nom | man |
| ---- | ---- |
| [ft_abs](srcs/math/ft_abs.c) | Return the absolute value of the integer. |
| [ft_biggest](srcs/math/ft_biggest.c) | Return the biggest int between the 2 given. |
| [ft_bracket](srcs/math/ft_bracket.c) | Check the brackets of a mathematic expression. |
| [ft_power](srcs/math/ft_power.c) | Return the integer at the power given. |
| [ft_random](srcs/math/ft_random.c) | Return a random int. |
| [ft_smallest](srcs/math/ft_smallest.c) | Return the smallest int between the 2 given. |
| [ft_sort_int_tab](srcs/math/ft_sort_int_tab.c) | Sort the given integer array. |
| [ft_sqrt](srcs/math/ft_sqrt.c) | Return the square root of the given integer (rounded up). |

### Memory function

| name | man |
| ---- | ---- |
| [ft_addncharbefore](srcs/memory/ft_addncharbefore.c) | Add a given number of char before the string. |
| [ft_bzero](srcs/memory/ft_bzero.c) | Writes n zeroed bytes to the string s.  If n is zero, ft_bzero does nothing. |
| [ft_flags](srcs/memory/ft_flags.c) | Fulfil an unsigned int by flags given to argv. |
| [ft_gnl](srcs/memory/ft_gnl.c) | Return one line from the given file descriptor on each call. |
| [ft_memalloc](srcs/memory/ft_memalloc.c) | Allocated memory and filled with bytes of value zero. |
| [ft_memccpy](srcs/memory/ft_memccpy.c) | Copies bytes from string src to string dst. |
| [ft_memchr](srcs/memory/ft_memchr.c) | Locates the first occurrence of c (converted to an unsigned char) in string s. |
| [ft_memcmp](srcs/memory/ft_memcmp.c) | Compares byte string s1 against byte string s2.  Both strings are assumed to be n bytes long. |
| [ft_memcpy](srcs/memory/ft_memcpy.c) | Copies n bytes from memory area src to memory area dst.  If dst and src overlap, behavior is undefined. |
| [ft_memdel](srcs/memory/ft_memdel.c) | Free a memory zone. |
| [ft_memmove](srcs/memory/ft_memmove.c) | Copies len bytes from string src to string dst.  The two strings may overlap; the copy is always done in a non-destructive manner. |
| [ft_memrev](srcs/memory/ft_memrev.c) | Reverse a memory zone byte by byte. |
| [ft_memset](srcs/memory/ft_memset.c) | Writes len bytes of value c (converted to an unsigned char) to the string b. |
| [ft_swap](srcs/memory/ft_swap.c) | swap 2 pointers. |

### Print Function

| name | man |
| ---- | ---- |
| [ft_buffer](srcs/print/ft_buffer.c) | Bufferized printing function to avoid multiple syscall. |
| [ft_printf](srcs/print/ft_printf.c) | Function write output to stdout. |
| [ft_putchar](srcs/print/ft_putchar.c) | Write a char. |
| [ft_printmemory](srcs/print/ft_printmemory.c) | Write a memory zone in hexadecimal. |
| [ft_printnchar](srcs/print/ft_printnchar.c) | Write a given number of character. |
| [ft_putaddr](srcs/print/ft_putaddr.c) | Write an address in hexadecimal. |
| [ft_putchar_fd](srcs/print/ft_putchar_fd.c) | Write a char to a file descriptor. |
| [ft_putdbl](srcs/print/ft_putdbl.c) | Write a double. |
| [ft_putendl_fd](srcs/print/ft_putendl_fd.c) | Write a string with a newline to a file descriptor. |
| [ft_putendl](srcs/print/ft_putendl.c) | Write a string with a newline. |
| [ft_putnbr_fd](srcs/print/ft_putnbr_fd.c) | Write a int to a file descriptor. |
| [ft_putnbr](srcs/print/ft_putnbr.c) | Write a int. |
| [ft_putstr_fd](srcs/print/ft_putstr_fd.c) | Write a string to a file descriptor. |
| [ft_putstr](srcs/print/ft_putstr.c) | Write a string. |

### String function

| name | man |
| ---- | ---- |
| [ft_char_index](srcs/str/ft_char_index.c) | Return the index of the first occurence of a char in a string. |
| [ft_strcapitalize](srcs/str/ft_strcapitalize.c) | Function converts a lower-case letter to the corresponding upper-case letter. |
| [ft_strcat](srcs/str/ft_strcat.c) | Function append a copy. of the null-terminated string s2 to the end of the null-terminated string s1, then add a terminating `\0`. |
| [ft_strchr](srcs/str/ft_strchr.c) | Function locates the first occurrence of c in string s. |
| [ft_strclr](srcs/str/ft_strclr.c) | Cleans by putting `\0`. |
| [ft_strcmp](srcs/str/ft_strcmp.c) | Function lexicographically compare the null-terminated strings s1 and s2. |
| [ft_strcpy](srcs/str/ft_strcpy.c) | Function copy the string src to dst. |
| [ft_strdel](srcs/str/ft_strdel.c) | Take a ptr in param to free and put NULL. |
| [ft_strdup](srcs/str/ft_strdup.c) | Function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it. |
| [ft_strequ](srcs/str/ft_strequ.c) | Function lexicographically compare the null-terminated strings s1 and s2. |
| [ft_striter](srcs/str/ft_striter.c) | Applies the function f to each character of the character string passed in parameter. |
| [ft_striteri](srcs/str/ft_striteri.c) | Applies the function f to each character in the character string passed as a parameter, specifying its index as the first argument.  |
| [ft_strjoin](srcs/str/ft_strjoin.c) | Allocate a new string of size s1 + s2 After that s1 was copy to the new allocate, and s2 was concatenate. |
| [ft_strlcat](srcs/str/ft_strlcat.c) | Concatenate strings with the same input parameters and output result as ft_snprintf. |
| [ft_strlen](srcs/str/ft_strlen.c) | Function computes the length of the string s. |
| [ft_strlenwcs](srcs/str/ft_strlenwcs.c) | Function computes the length of the wildchar string s. |
| [ft_strlowerize](srcs/str/ft_strlowerize.c) | Put uppercase to lowercase on place. |
| [ft_strmap](srcs/str/ft_strmap.c) | Apply the function f to each character in the character string passed as a parameter to create a new “fresh” string resulting from the successive applications of f. |
| [ft_strmapi](srcs/str/ft_strmapi.c) | Apply the function f to each character of the character string passed in parameter by specifying its index to create a new “fresh” string resulting from the successive applications of f. |
| [ft_strncat](srcs/str/ft_strncat.c) | Function append a copy of the null-terminated string s2 to the end of the null-terminated str s1, then add a terminating `\0`. |
| [ft_strncmp](srcs/str/ft_strncmp.c) | Function compares not more than n characters. |
| [ft_strncpy](srcs/str/ft_strncpy.c) | Function copy at most len characters from src into dst. |
| [ft_strnequ](srcs/str/ft_strnequ.c) | Function lexicographically compare the null-terminated strings s1 and s2 of size n. |
| [ft_strnew](srcs/str/ft_strnew.c) | Allocate a new string of size `size`. |
| [ft_strnstr](srcs/str/ft_strnstr.c) | Function locates the first occurrence of the null-terminated string needle in the null-terminated string haystack with length len. |
| [ft_strpbrk](srcs/str/ft_strpbrk.c) | Function locates in the null-terminated string s the first occurrence of any character in the string charset and returns a pointer to this character.  If no characters from charset occur anywhere in s ft_strpbrk returns NULL.|
| [ft_strrchr](srcs/str/ft_strrchr.c) | Function locates the first occurrence of c (converted to an unsigned char) in string s. |
| [ft_strrev](srcs/str/ft_strrev.c) | Reverse a string char by char. |
| [ft_strrstr](srcs/str/ft_strrstr.c) | Function locates the last occurrence of the null-terminated string needle in the null-terminated string haystack. |
| [ft_strsplit](srcs/str/ft_strsplit.c) | Split a strings with the char c delimiter to a tab was allocate. |
| [ft_strstr](srcs/str/ft_strstr.c) | Function locates the first occurrence of the null-terminated string needle in the null-terminated string haystack. |
| [ft_strsub](srcs/str/ft_strsub.c) | Allocate a new string of size n. After that s1 was copy to the new allocate at start 'start', and copy n char. |
| [ft_strtrim](srcs/str/ft_strtrim.c) | Remove whitespaces (`\n`, `\t`, ` `) at start and and end of string s1. |
| [ft_strupperize](srcs/str/ft_strupperize.c) | Function converts a lower-case letter to the corresponding upper-case letter. |
| [ft_wcslen](srcs/str/ft_wcslen.c) | Return the length of a wildchar. |
