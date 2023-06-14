/*
** EPITECH PROJECT, 2022
** matrixes_product.c
** File description:
** product of two matrixes
*/
#include <stdlib.h>
#include <stdio.h>

int **matrixe_product_int(int **matrix_1, int **matrix_2, int size, int nb_line_matrix_1, int nb_col_matrix_2)
{
    int **matrix_result = malloc(sizeof(int *) * nb_line_matrix_1);

    for (int i = 0; i < nb_line_matrix_1; i++)
        matrix_result[i] = malloc(sizeof(int) * nb_col_matrix_2);
    for (int i = 0; i < nb_line_matrix_1; i++) {
        for (int j = 0; j < nb_col_matrix_2; j++) {
            matrix_result[i][j] = 0;
            for (int k = 0; k < size; k++)
                matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
    }
    return (matrix_result);
}

double **matrixe_product_double(double **matrix_1, double **matrix_2, int size, int nb_line_matrix_1, int nb_col_matrix_2)
{
    double **matrix_result = malloc(sizeof(double *) * nb_line_matrix_1);

    for (int i = 0; i < nb_line_matrix_1; i++)
        matrix_result[i] = malloc(sizeof(double) * nb_col_matrix_2);
    for (int i = 0; i < nb_line_matrix_1; i++) {
        for (int j = 0; j < nb_col_matrix_2; j++) {
            matrix_result[i][j] = 0;
            for (int k = 0; k < size; k++)
                matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
    }
    return (matrix_result);
}
