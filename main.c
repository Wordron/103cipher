/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include "103cipher.h"

int main(int ac, char **av)
{/*
    double **matrix = malloc(sizeof(double *) * 4);
    double **test;
    double **comatrix;
    double det;

    for (int u = 0; u < 3; u++)
        matrix[u] = malloc(sizeof(double) * 3);
    matrix[0][0] = 6;
    matrix[0][1] = 9;
    matrix[0][2] = 5;

    matrix[1][0] = 9;
    matrix[1][1] = 3;
    matrix[1][2] = 2;

    matrix[2][0] = 8;
    matrix[2][1] = 5;
    matrix[2][2] = 1;
    matrix[3] = NULL;

    test = get_transpo(get_comatrix(matrix, "test"), 3);

    det = get_det(matrix, 3);

    printf("det = %f\ntest =\n", det);
    for (int u = 0; u < 3; u++) {
        for (int i = 0; i < 3; i++)
            printf("%f\t", test[u][i]);
        printf("\n");
    }

    comatrix = get_matrix_reverse(test, det, "test");
    printf("reversed matrix =\n");
    for (int u = 0; u < 3; u++) {
        for (int i = 0; i < 3; i++)
            printf("%f\t", comatrix[u][i]);
        printf("\n");
    }
    printf("multiplication :%f\n", -7 * 0.007937);

    for (int u = 0; u < 3; u++)
        free(matrix[u]);
    free(matrix);
*/
    int error = 0;
 
    if (ac != 4)
        return (84);
    if (atoi(av[3]) != 0 && atoi(av[3]) != 1)
        return (84);
    if (my_str_isalpha(av[3]) == 1)
        return (84);
    if (atoi(av[3]) == 0)
        crypt(av[1], av[2]);
    if (atoi(av[3]) == 1) {
       error = decrypt(av[1], av[2]);
        if (error == 84)
            return (84);
    }
}
