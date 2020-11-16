# Libft

Le projet libft reprend le concept du D06 de la piscine, à savoir vous faire écrire une bibliothèque de fonctions utiles que vous pourrez ensuite utiliser dans la vaste majorité de vos projets de C cette année et ainsi vous faire gagner beaucoup de temps.

Ce projet vous demande d’écrire beaucoup de code que vous avez déja réalisé pendant la piscine, ce qui en fait un excellent moment pour faire le point sur votre avancement.

## Fonctions

### Fonction de caratère

| nom | man |
| ---- | ---- |
| [ft_isalnum](srcs/char/ft_isalnum.c) | Vérifie si le caractère est alphanumérique. |
| [ft_isalpha](srcs/char/ft_isalpha.c) | Vérifie si le caractère est alphabétique. |
| [ft_isascii](srcs/char/ft_isascii.c) | Vérifie si le caractère est dans la table ascii. |
| [ft_iscntrl](srcs/char/ft_iscntrl.c) | Vérifie si le caractère est non imprimable. |
| [ft_isdigit](srcs/char/ft_isdigit.c) | Vérifie si le caractère est numérique. |
| [ft_isprint](srcs/char/ft_isprint.c) | Vérifie si le caractère est imprimable (espace inclu). |
| [ft_ispunct](srcs/char/ft_ispunct.c) | Vérifie si le caractère est un caractère de ponctuation. |
| [ft_isspace](srcs/char/ft_isspace.c) | Vérifie si le caractère est un caractère d'espacement. |
| [ft_isxdigit](srcs/char/ft_isxdigit.c) | Vérifie si le caractère fait partie d'une base héxadécimale. |
| [ft_tolower](srcs/char/ft_tolower.c) | Converti le caractère en minuscule s'il est en majuscule. |
| [ft_toupper](srcs/char/ft_toupper.c) | Converti le caractère en majuscule s'il est en minuscule. |

### Fonction de couleur

| nom | man |
| ---- | ---- |
| [ft_blue](srcs/color/ft_blue.c) | Écrit en bleu. |
| [ft_cyan](srcs/color/ft_cyan.c) | Écrit en cyan. |
| [ft_green](srcs/color/ft_green.c) | Écrit en vert. |
| [ft_magenta](srcs/color/ft_magenta.c) | Écrit en magenta. |
| [ft_red](srcs/color/ft_red.c) | Écrit en rouge. |
| [ft_yellow](srcs/color/ft_yellow.c) | Écrit en jaune. |

### Fonction de conversion

| nom | man |
| ---- | ---- |
| [ft_atoi](srcs/conversion/ft_atoi.c) | Converti une chaîne de caractères en int. |
| [ft_atoll](srcs/conversion/ft_atoll.c) | Converti une chaîne de caractères en long long. |
| [ft_conv_utf8](srcs/conversion/ft_conv_utf8.c) | Converti un wildchar en chaîne de caractères. |
| [ft_dtoa](srcs/conversion/ft_dtoa.c) | Converti un double en chaîne de caractères. |
| [ft_intlen_base](srcs/conversion/ft_intlen_base.c) | Renvoie la longeur de l'entier dans une base donnée en paramètre. |
| [ft_intlen](srcs/conversion/ft_intlen.c) | Renvoie la longeur de l'entier en base 10. |
| [ft_itoa_base](srcs/conversion/ft_itoa_base.c) | Converti un int en une chaîne de caractères allouée avec une base mise en paramètre. |
| [ft_itoa_no_malloc](srcs/conversion/int/ft_itoa_no_malloc.c) | Converti un int en une chaîne de caractères non allouée. |
| [ft_itoa](srcs/conversion/ft_itoa.c) | Converti un int en une chaîne de caractères allouée. |
| [ft_lllen](srcs/conversion/ft_lllen.c) | Renvoie la longeur du long long passé en paramètre en base 10. |
| [ft_lltoa](srcs/conversion/ft_lltoa.c) | Converti un long long en une chaîne de caractères allouée. |
| [ft_ulltoa_base](srcs/conversion/ft_ulltoa_base.c) | Converti un unsigned long long en une chaîne de caractères allouée avec une base mise en paramètre. |
| [ft_wc_convert](srcs/conversion/ft_wc_convert.c) | Converti un wildchar en chaîne de caractères. |
| [ft_wcs_convert](srcs/conversion/ft_wcs_convert.c) | Converti une chaine de caractères contenant des wildchar en chaîne de caractères. |

### Fonctions de liste

| nom | man |
| ---- | ---- |
| [ft_lstadd](srcs/list/ft_lstadd.c) | Ajoute un élément en début de liste. |
| [ft_lstdel](srcs/list/ft_lstdel.c) | Supprime la liste. |
| [ft_lstdelone](srcs/list/ft_lstdelone.c) | Supprime le premier élément de la liste. |
| [ft_lstiter](srcs/list/ft_lstiter.c) | Applique la fonction passée en paramètre à tous les éléments de la liste. |
| [ft_lstmap](srcs/list/ft_lstmap.c) | Applique la fonction passée en paramètre à tous les éléments de la liste, renvoie une nouvelle liste allouée. |
| [ft_lstnew](srcs/list/ft_lstnew.c) | Créé une nouvelle liste. |
| [ft_lstpushback](srcs/list/ft_lstpushback.c) | Ajoute un élément en fin de liste. |
| [ft_lstrev](srcs/list/ft_lstrev.c) | Inverse l'ordre de la liste. |
| [ft_lstsize](srcs/list/ft_lstsize.c) | Renvoie la taille de la liste. |

### Fonctions de math

| nom | man |
| ---- | ---- |
| [ft_abs](srcs/math/ft_abs.c) | Renvoie la valeur absolue de l'entier passé en paramètre. |
| [ft_biggest](srcs/math/ft_biggest.c) | Renvoie l'entier le plus grand parmis les 2 passés en paramètre. |
| [ft_bracket](srcs/math/ft_bracket.c) | Vérifie la cohérence des parenthèses d'une expression mathématique. |
| [ft_power](srcs/math/ft_power.c) | Renvoie un entier à la puissance demandée. |
| [ft_random](srcs/math/ft_random.c) | Renvoie un entier aléatoire. |
| [ft_smallest](srcs/math/ft_smallest.c) | Renvoie l'entier le plus petit parmis les 2 passés en paramètre. |
| [ft_sort_int_tab](srcs/math/ft_sort_int_tab.c) | Trie le tableau d'entiers passé en paramètres. |
| [ft_sqrt](srcs/math/ft_sqrt.c) | Renvoie la racine carrée de l'entier passé en paramètre (arrondi au supérieur). |

### Fonction de mémoire

| nom | man |
| ---- | ---- |
| [ft_addncharbefore](srcs/memory/ft_addncharbefore.c) | Ajoute un nombre de caractères donné au debut de la chaîne de caractères. |
| [ft_bzero](srcs/memory/ft_bzero.c) | Remplit de `\0` une zone mémoire d'une taille donnée. |
| [ft_flags](srcs/memory/ft_flags.c) | Remplit un unsigned int avec les flags passés en paramètres à argv. |
| [ft_gnl](srcs/memory/ft_gnl.c) | Renvoie une ligne d'un file descriptor donné à chaque appel. |
| [ft_memalloc](srcs/memory/ft_memalloc.c) | Alloue une nouvelle zone mémoire, réalise un ft_bzero dessus et retourne l'adresse de cette zone. |
| [ft_memccpy](srcs/memory/ft_memccpy.c) | Copie une zone mémoire vers une destination. Jusqu'à ce que n octets soient copies ou que la valeur passée en paramètre soit trouvée.|
| [ft_memchr](srcs/memory/ft_memchr.c) | Cherche une valeur dans une zone mémoire en commencant du début. |
| [ft_memcmp](srcs/memory/ft_memcmp.c) | Compare deux zones mémoire. |
| [ft_memcpy](srcs/memory/ft_memcpy.c) | Copie une zone mémoire dans une autre. |
| [ft_memdel](srcs/memory/ft_memdel.c) | Libère une zone mémoire et la met à NULL. |
| [ft_memmove](srcs/memory/ft_memmove.c) | Déplace une zone mémoire dans une autre. |
| [ft_memrev](srcs/memory/ft_memrev.c) | Inverse la zone mémoire octet par octet. |
| [ft_memset](srcs/memory/ft_memset.c) | Initialise une zone mémoire de taille donnée à la valeure mise en paramètre. |
| [ft_swap](srcs/memory/ft_swap.c) | Intervertit 2 pointeurs. |

### Fonction d'affichage

| nom | man |
| ---- | ---- |
| [ft_buffer](srcs/print/ft_buffer.c) | Fonctions d'affichage bufferisées pour limiter les appels systèmes. |
| [ft_printf](srcs/print/ft_printf.c) | Écrit la chaîne formatée sur la sortie standard. |
| [ft_putchar](srcs/print/ft_putchar.c) | Affiche un caractère sur la sortie standard. |
| [ft_printmemory](srcs/print/ft_printmemory.c) | Affiche une zone mémoire sous forme hexadécimale. |
| [ft_printnchar](srcs/print/ft_printnchar.c) | Affiche un nombre définit de caractères passés en paramètre. |
| [ft_putaddr](srcs/print/ft_putaddr.c) | Affiche une adresse sur la sortie standard. |
| [ft_putchar_fd](srcs/print/ft_putchar_fd.c) | Affiche un caractère sur le file descriptor mit en paramètre. |
| [ft_putchar](srcs/print/ft_putchar.c) | Affiche un caractère sur la sortie standard. |
| [ft_putdbl](srcs/print/ft_putdbl.c) | Affiche un double sur la sortie standard. |
| [ft_putendl_fd](srcs/print/ft_putendl_fd.c) | Affiche une chaîne de caractères sur le file descriptor mit en paramètre suivit d'un retour à la ligne. |
| [ft_putendl](srcs/print/ft_putendl.c) | Affiche une chaîne de caractères sur la sortie standard suivit d'un retour à la ligne. |
| [ft_putnbr_fd](srcs/print/ft_putnbr_fd.c) | Affiche un nombre sur le file descriptor mit en paramètre. |
| [ft_putnbr](srcs/print/ft_putnbr.c) | Affiche un nombre sur l'entrée standard. |
| [ft_putstr_fd](srcs/print/ft_putstr_fd.c) | Affiche une chaîne de caractères sur le file descriptor mit en paramètre. |
| [ft_putstr](srcs/print/ft_putstr.c) | Affiche une chaîne de caractères sur la sortie standard. |

### Fonction de string

| nom | man |
| ---- | ---- |
| [ft_char_index](srcs/str/ft_char_index.c) | Cherche un caractère dans une chaîne de caractère et retourne l'index de sa première occurence. |
| [ft_strcapitalize](srcs/str/ft_strcapitalize.c) | Passe la chaîne de caractère en majuscule. |
| [ft_strcat](srcs/str/ft_strcat.c) | Concatène deux chaînes de caractère. |
| [ft_strchr](srcs/str/ft_strchr.c) | Cherche un caractère dans une chaîne de caractère. |
| [ft_strclr](srcs/str/ft_strclr.c) | Assigne la valeur '`\0` à tous les caractères de la chaîne passée en paramètre. |
| [ft_strcmp](srcs/str/ft_strcmp.c) | Compare lexicographiquement s1 et s2. Si les deux chaînes sont égales, la fonction retourne 0, ou -1 si s1 est inférieur à s2 sinon 1. |
| [ft_strcpy](srcs/str/ft_strcpy.c) | Copie la chaîne de caractère src dans dst. |
| [ft_strdel](srcs/str/ft_strdel.c) | Prend en paramètre l’adresse d’une chaîne de caractères qui doit être libérée avec free(3) et son pointeur mis à NULL. |
| [ft_strdup](srcs/str/ft_strdup.c) | Alloue une place suffisante pour copier la chaîne de caractère s1. Si l'allocation échoue la fonction revoie NULL. |
| [ft_strequ](srcs/str/ft_strequ.c) | Compare lexicographiquement s1 et s2. Si les deux chaînes sont égales, la fonction retourne 1, sinon 0. |
| [ft_striter](srcs/str/ft_striter.c) | Applique la fonction f à chaque caractère de la chaîne de caractères passée en paramètre. Chaque caractère est passé par adresse à la fonction f afin de pouvoir être modifié si nécessaire. |
| [ft_striteri](srcs/str/ft_striteri.c) | Applique la fonction f à chaque caractère de la chaîne de caractères passée en paramètre en précisant son index en premier argument. Chaque caractère est passé par adresse à la fonction f afin de pouvoir être modifié si nécessaire. |
| [ft_strjoin](srcs/str/ft_strjoin.c) | Alloue et retourne une chaîne de caractères “fraiche” terminée par un `\0` résultant de la concaténation de s1 et s2. Si l’allocation échoue, la fonction renvoie NULL. |
| [ft_strlcat](srcs/str/ft_strlcat.c) | Concatène des chaînes avec les mêmes paramètres d'entrée et résultats de sortie que ft_snprintf. |
| [ft_strlen](srcs/str/ft_strlen.c) | Retourne la longeur de la chaîne de caractère passée en paramètre. |
| [ft_strlenwcs](srcs/str/ft_strlenwcs.c) | Retourne la longeur de la chaîne de wildchar passée en paramètre. |
| [ft_strlowerize](srcs/str/ft_strlowerize.c) | Passe la chaîne de caractère en minuscule. |
| [ft_strmap](srcs/str/ft_strmap.c) | Applique la fonction f à chaque caractère de la chaîne de caractères passée en paramètre pour créer une nouvelle chaîne “fraiche” résultant des applications successives de f. |
| [ft_strmapi](srcs/str/ft_strmapi.c) | Applique la fonction f à chaque caractère de la chaîne de caractères passée en paramètre en précisant son index pour créer une nouvelle chaîne “fraiche” résultant des applications successives de f. |
| [ft_strncat](srcs/str/ft_strncat.c) | Concatène deux chaînes de caractère d'une taille passée en paramètre. |
| [ft_strncmp](srcs/str/ft_strncmp.c) | Compare lexicographiquement s1 et s2 d'une taille donnée en paramètre. Si les deux chaînes sont égales, la fonction retourne 0, ou -1 si s1 est inférieur à s2 sinon 1. |
| [ft_strncpy](srcs/str/ft_strncpy.c) | Copie n caractères de src dans dst. |
| [ft_strnequ](srcs/str/ft_strnequ.c) | Compare lexicographiquement s1 et s2 jusqu’à n caractères maximum ou bien qu’un `\0` ait été rencontré. Si les deux chaînes sont égales, la fonction retourne 1, sinon 0. |
| [ft_strnew](srcs/str/ft_strnew.c) | Alloue et retourne une chaîne de caractères initialisée à `\0`. Si l’allocation échoue, la fonction renvoie NULL. |
| [ft_strnstr](srcs/str/ft_strnstr.c) | Recherche une chaîne de caractères d'une taille donnée en paramètre dans une autre et retourne son adresse. |
| [ft_strpbrk](srcs/str/ft_strpbrk.c) | Cherche un caractère d'un charset dans une chaîne de caractères et retourne son adresse, et NULL si aucune occurence n'est trouvée. |
| [ft_strrchr](srcs/str/ft_strrchr.c) | Recherche un caractère en commançant par la fin dans une chaîne et retourne son adresse. |
| [ft_strrev](srcs/str/ft_strrev.c) | Inverse une chaîne de caractères. |
| [ft_strrstr](srcs/str/ft_strrstr.c) | Recherche une chaîne de caractères dans une autre et retourne l'adresse de sa dernière occurence. |
| [ft_strsplit](srcs/str/ft_split.c) | Alloue et retourne un tableau de chaînes de caractères “fraiches” (toutes terminées par un `\0`) résultant de la découpe de s selon le caractère c. Si l’allocation échoue, la fonction retourne NULL. |
| [ft_strstr](srcs/str/ft_strstr.c) | Recherche une chaîne de caractères dans une autre et retourne l'adresse de sa première occurence. |
| [ft_strsub](srcs/str/ft_strsub.c) | Alloue et retourne la copie “fraiche” d’un tronçon de la chaîne de caractères passée en paramètre. Le tronçon commence à l’index start et à pour longueur len. Si start et len ne désignent pas un tronçon de chaîne valide, le comportement est indéterminé. Si l’allocation échoue, la fonction renvoie NULL. |
| [ft_strtrim](srcs/str/ft_strtrim.c) | Alloue et retourne une copie de la chaîne passée en paramètre sans les espaces blancs au debut et à la fin de cette chaîne. On considère comme espaces blancs les caractères ` `, `\n` et `\t`. Si s ne contient pas d’espaces blancs au début ou à la fin, la fonction renvoie une copie de s. Si l’allocation échoue, la fonction renvoie NULL. |
| [ft_strupperize](srcs/str/ft_strupperize.c) | Passe la chaîne de caractère en majuscule. |
| [ft_wcslen](srcs/str/ft_wcslen.c) | Renvoie la longueur d'un wildchar. |
