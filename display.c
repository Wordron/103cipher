/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/
#include <stdio.h>

void print_crypted(int **mat_key, int cols, int **mat_result, int nb_rows)
{
    int i = 0;
    int j = 0;
    int l = 0;
    int k = 0;

    printf("Key matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < cols - 1; j++)
            printf("%i ", mat_key[i][j]);
        printf("%i", mat_key[i][j]);
        printf("\n");
    }
    printf("\nEncrypted message:\n");
    for (k = 0; k < nb_rows - 1; k++) {
        for (l = 0; l < cols; l++)
            printf("%i ", mat_result[k][l]);
    }
    for (l = 0; l < cols - 1; l++)
        printf("%i ", mat_result[k][l]);
    printf("%i", mat_result[k][l]);
    printf("\n");
}

void print_decrypted(double **mat_key, int cols, char *result_mess)
{
    int j = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (j = 0; j < cols; j++)
            printf("%f\t", mat_key[i][j]);
        printf("%f", mat_key[i][j]);
        printf("\n");
    }
    printf("\nDecrypted message:\n");
    printf("%s\n", result_mess);
}
