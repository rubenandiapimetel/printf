# printf
Recrea la funcion printf de la stdio.h de C  (ft_printf)


Para usar hacer make

se genera una libreria estatica llamada libftprintf.a

en vez de usar:

printf(cmd1, cmd2,...) 

usar:

ft_printf(cmd1, cmd 2, cmd 3, ...)

hay archivo main.c de prueba.

EJ:


make

gcc main.c libftprintf.a -o testout

./testout
