/*
** EPITECH PROJECT, 2022
** 103cipher.h
** File description:
** prototype the functions needed by 103cipher
*/

#ifndef CIPHER_H_
    #define CIPHER_H_

    int crypt(char *message, char *key);
    int decrypt(char *message, char *key);
    int my_strlen(char const *str);
    int **matrixe_product_int(int **matrix_1, int **matrix_2, int size, int nb_line_matrix_1, int nb_col_matrix_2);
    double **matrixe_product_double(double **matrix_1, double **matrix_2, int size, int nb_line_matrix_1, int nb_col_matrix_2);
    int **mat_key(int nb, char *key);
    void print_crypted(int **mat_key, int cols, int **mat_result, int nb_rows);
    void print_decrypted(double **mat_key, int cols, char *result_mess);
    int **get_mat_mess(char *message, int cols);
    int get_nb_cols(char *key);
    int get_rows_mess(char *message);
    int *get_mess_matrice(char *message);
    double **get_matrice_message(int *array, int cols, int nb_numbers);
    int my_str_isalpha(char const *str);

    double **get_comatrix(double **matrix, char *key, int nb_cols_key);
    double **get_transpo(double **matrice, int cols);
    double **get_matrix_reverse(double **matrix, double det, char *key);
    double get_det(double **matrix_key, int nb_cols_key);

#endif /* !CIPHER_H_ */
