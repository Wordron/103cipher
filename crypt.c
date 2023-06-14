/*
** EPITECH PROJECT, 2022
** crypt.c
** File description:
** crypt
*/
#include "103cipher.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int **mat_key(int nb, char *key)
{
    int **matrice = malloc(sizeof(int *) * nb);
    int index = 0;

    for (int j = 0; j < nb; j++)
        matrice[j] = malloc(sizeof(int) * nb);
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

int **get_square_mat_key(char *key)
{
    int nb = my_strlen(key);
    int i = 0;
    int **matrice;

    while(nb > i * i)
        i++;
    matrice = mat_key(i, key);
    return (matrice);
}

int get_nb_cols(char *key)
{
    int cols = 0;
    int nb = my_strlen(key);

    while(nb > cols * cols)
        cols++;
    return (cols);
}

int **get_mat_mess(char *message, int cols)
{
    int nb_rows = my_strlen(message) / cols + 1;
    int **mat_message = malloc(sizeof(int *) * nb_rows);
    int index = 0;

    for (int j = 0; j != nb_rows; j++)
        mat_message[j] = malloc(sizeof(int) * cols);
    for (int k = 0; k < nb_rows; k++) {
        for (int l = 0; l < cols; l++) {
            mat_message[k][l] = message[index];
            index++;
        }
    }
    return(mat_message);
}

int crypt(char *message, char *key)
{
    int **mat_key = get_square_mat_key(key);
    int cols = get_nb_cols(key);
    int nb_rows = my_strlen(message) / cols + 1;
    int **mat_message = get_mat_mess(message, cols);
    int **mat_result;

    mat_result = matrixe_product_int(mat_message, mat_key, cols, nb_rows, cols);
    print_crypted(mat_key, cols, mat_result, nb_rows);
}
