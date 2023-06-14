/*
** EPITECH PROJECT, 2022
** decrypt.c
** File description:
** decrypte an encoded message
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "103cipher.h"

double **mat_key_double(int nb, char *key)
{
    double **matrice = malloc(sizeof(double *) * nb);
    int index = 0;

    for (int j = 0; j < nb; j++)
        matrice[j] = malloc(sizeof(double) * nb);
    for (int k = 0; k < nb; k++) {
        for (int l = 0; l < nb; l++) {
            if (index > my_strlen(key))
                matrice[k][l] = 0;
            else {
                matrice[k][l] = key[index];
                index++;
            }
        }
    }
    return (matrice);
}

double **get_square_mat_key_double(char *key)
{
    int nb = my_strlen(key);
    int i = 0;
    double **matrice;

    while(nb > i * i)
        i++;
    matrice = mat_key_double(i, key);
    return (matrice);
}

int get_nb_line(double **matrice)
{
    int i = 0;

    while (matrice[i] != NULL)
        i++;
    return (i);
}

double **get_matrix_reverse_two_by_two(double **matrix, double det, char *key)
{
    double temp = 1 / (float) det;
    double **matrix_reverse = malloc(sizeof(double *) * 3);
    double **temp_matrix = malloc(sizeof(double *) * 2);

    for (int u = 0; u < 2; u++)
        matrix_reverse[u] = malloc(sizeof(double) * 2);
    matrix_reverse[2] = NULL;
    for (int u = 0; u < 2; u++)
        temp_matrix[u] = malloc(sizeof(double) * 2);
    temp_matrix[0][0] = matrix[1][1];
    temp_matrix[0][1] = -matrix[0][1];
    temp_matrix[1][0] = matrix[1][0];
    temp_matrix[1][1] = -matrix[0][0];
    for (int i = 0; i < get_nb_cols(key); i++) {
        for (int j = 0; j <  get_nb_cols(key); j++)
            matrix_reverse[i][j] = temp * ((double) temp_matrix[i][j]);
    }
    return (matrix_reverse);
}

double **get_matrix_reverse(double **matrix, double det, char *key)
{
    double temp = 1 / (float) det;
    double **matrix_reverse = malloc(sizeof(double *) * 4);

    for (int u = 0; u < 3; u++)
        matrix_reverse[u] = malloc(sizeof(double) * 3);
    matrix_reverse[3] = NULL;
    for (int i = 0; i < get_nb_cols(key); i++) {
        for (int j = 0; j < get_nb_cols(key); j++) {
            matrix_reverse[i][j] = temp * ((double) matrix[i][j]);
        }
    }
    return (matrix_reverse);
}

double get_det_two_by_two(double **matrix)
{
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

double get_det(double **matrix_key, int nb_cols_key)
{
    double det = 0;
    double **matrix_intermediate_det = malloc(sizeof(double *) * 2);
    int col_intermediate = 0;
    int line_intermediate = 0;

    for (int i = 0; i < 2; i++)
        matrix_intermediate_det[i] = malloc(sizeof(double) * 2);
    for (int k = 0; k < nb_cols_key; k++) {
        line_intermediate = 0;
        col_intermediate = 0;
        for (int i = 0; i < nb_cols_key; i++) {
            for (int j = 1; j < nb_cols_key; j++) {
                if (i != k) {
                    if (line_intermediate == 2) {
                        line_intermediate = 0;
                        col_intermediate++;
                    }
                    matrix_intermediate_det[line_intermediate][col_intermediate] = matrix_key[j][i]; //return 0 each time, why ?
                    line_intermediate++;
                }
            }
        }
        det += (matrix_key[0][k] * pow(-1, k)) * get_det_two_by_two(matrix_intermediate_det);
    }
    for (int i = 0; i < 2; i++)
        free(matrix_intermediate_det[i]);
    free(matrix_intermediate_det);
    return (det);
}

double **get_comatrix(double **matrix, char *key, int nb_cols_key)
{
    double **matrix_intermediate_det = malloc(sizeof(double *) * 2);
    double **comatrix = malloc(sizeof(double *) * 3);
    double det = 0;
    int col_intermediate = 0;
    int line_intermediate = 0;

    for (int u = 0; u < 2; u++)
        matrix_intermediate_det[u] = malloc(sizeof(double) * 2);
    for (int u = 0; u < 3; u++)
        comatrix[u] = malloc(sizeof(double) * 3);

    for (int k = 0; k < nb_cols_key; k++) {
        for (int l = 0; l < 3; l++) {
            line_intermediate = 0;
            col_intermediate = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < nb_cols_key; j++) {
                    if (i != l && j != k) {
                        if (line_intermediate == 2) {
                            line_intermediate = 0;
                            col_intermediate++;
                        }
                        matrix_intermediate_det[line_intermediate][col_intermediate] = matrix[j][i];
                        line_intermediate++;
                    }
                }
            }
            det = get_det_two_by_two(matrix_intermediate_det) * pow(-1, k + l);
            comatrix[k][l] = det;
        }
    }
    return (comatrix);
}

double **get_transpo(double **matrice, int cols)
{
    double **matrice_result = malloc(sizeof(double *) * cols);

    for (int k = 0; k != cols; k++)
        matrice_result[k] = malloc(sizeof(double) * cols);
    for (int i = 0; i != cols; i++) {
        for (int j = 0; j != cols; j++)
            matrice_result[i][j] = matrice[j][i];
    }
    for (int k = 0; k != cols; k++)
        free(matrice[k]);
    free(matrice);
    return (matrice_result);
}

int decrypt(char *message, char *key)
{
    double **matrix_key = get_square_mat_key_double(key);
    double **matrix_key_reverse;
    double **comatrix_transposed;
    int nb_cols_key = get_nb_cols(key);
    double **matrix_message = get_matrice_message(get_mess_matrice(message), nb_cols_key, get_rows_mess(message));
    double **matrix_result;
    char *final_message = malloc(sizeof(char) * my_strlen(message));
    double det = 0;
    int z = 0;

    if (my_strlen(key) >= 16)
        return (84);
    //For a single character
    if (my_strlen(key) == 1) {
        matrix_result = malloc(sizeof(double *) * get_rows_mess(message));
        for (int i = 0; i < get_rows_mess(message); i++)
            matrix_result[i] = malloc(sizeof(double));
        matrix_key_reverse = malloc(sizeof(double *));
        matrix_key_reverse[0] = malloc(sizeof(double));
        matrix_key_reverse[0][0] = (double) key[0];

        for (int i = 0; i != get_rows_mess(message); i++)
            matrix_result[i][0] = (matrix_message[i][0] / key[0]);
    }

    //For a 2 * 2 matrix
    if (nb_cols_key == 2) {
        if (get_det_two_by_two(matrix_key) == 0)
            return (84);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                matrix_key[i][j] = matrix_key[i][j] * pow(-1, i + j);
        }
        matrix_key_reverse = get_matrix_reverse_two_by_two(matrix_key, get_det_two_by_two(matrix_key), key);
        matrix_result = matrixe_product_double(matrix_message, matrix_key_reverse, get_nb_cols(key), get_rows_mess(message) / 2, get_nb_cols(key));
    }

    //For a 3 * 3 matrix or higher ?
    if (nb_cols_key >= 3) {
        det = get_det(matrix_key, nb_cols_key);
        if (det == 0)
            return (84);
        comatrix_transposed = get_transpo(get_comatrix(matrix_key, key, nb_cols_key), nb_cols_key);
        matrix_key_reverse = get_matrix_reverse(comatrix_transposed, det, key);
        matrix_result = matrixe_product_double(matrix_message, matrix_key_reverse, get_nb_cols(key), get_nb_line(matrix_message), get_nb_cols(key));
        for (int i = 0; i < nb_cols_key; i++)
            free(comatrix_transposed[i]);
        free(comatrix_transposed);
    }

    for (int i = 0; i != (get_rows_mess(message) / get_nb_cols(key)); i++) {
        for (int j = 0; j < nb_cols_key; j++) {
            matrix_result[i][j] = round(matrix_result[i][j]);
            matrix_result[i][j] = abs(matrix_result[i][j]);
            final_message[z] = ((char) matrix_result[i][j]);
            z++;
        }
    }
    print_decrypted(matrix_key_reverse, nb_cols_key, final_message);

    for (int i = 0; i < nb_cols_key; i++)
        free(matrix_result[i]);
    free(matrix_result);
    for (int i = 0; i < nb_cols_key; i++)
        free(matrix_message[i]);
    free(matrix_message);
    for (int i = 0; i < nb_cols_key; i++)
        free(matrix_key_reverse[i]);
    free(matrix_key_reverse);
    for (int i = 0; i < nb_cols_key; i++)
        free(matrix_key[i]);
    free(matrix_key);
    free(final_message);
}
