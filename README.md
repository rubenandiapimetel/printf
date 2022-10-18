# printf
Recrea la funcion printf de C (stdio.h)


Para usar hacer 

&>$make

se genera una libreria estatica llamada libftprintf.a

en el archivo main.c vez de usar:

printf(cmd1, cmd2,...) 

usar:

&>$ft_printf(cmd1, cmd 2, cmd 3, ...)

Dentro hay un archivo main.c de prueba.
(Puedes crear tu propio archivo main.c para probarlo).

EJ:


&>$make

&>$gcc main.c libftprintf.a -o textosalida

&>$./textosalida
