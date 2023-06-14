/*
** EPITECH PROJECT, 2022
** get_matrix_message.c
** File description:
** get_matrix message
*/
#include <stdio.h>
#include <stdlib.h>
#include "103cipher.h"

int get_rows_mess(char *message)
{
    int count = 0;
    int length = my_strlen(message);

    for (int i = 0; i != length; i++) {
        if (message[i] == ' ')
            count++;
    }
    count++;
    return (count);
}

int *get_mess_matrice(char *message)
{
    int nb_numbers = get_rows_mess(message);
    int *array = malloc(sizeof(int) * nb_numbers);
    int number = 0;
    int index = 0;

    for (int z = 0; z != nb_numbers; z++)
        array[z] = 0;
    for (int i = 0; i != my_strlen(message); i++){
        if (message[i] == ' ') {
            index++;
        } else
            array[index] = array[index] * 10 + (message[i] - 48);
    }
    return (array);
}

double **get_matrice_message(int *array, int cols, int nb_numbers)
{
    int rows = nb_numbers / cols;
    double **matrice = malloc(sizeof(double *) * rows);
    int index = 0;

    for (int i = 0; i != rows; i++)
        matrice[i] = malloc(sizeof(double) * cols);
    for (int j = 0; j != rows; j++) {
        for (int k = 0; k != cols; k++) {
            matrice[j][k] = array[index];
            index++;
        }
    }
    return (matrice);
}
