/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** task12
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] <= 'z' && str[i] >= 'a') ||
            (str[i] <= 'Z' && str[i] >= 'A'))
            i++;
        else
            return (0);
    }
    return (1);
}
