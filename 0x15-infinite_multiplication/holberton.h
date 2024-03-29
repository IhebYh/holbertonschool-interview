#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0
#define user_input_error 98

#define char_to_digit(x) (x - '0')
#define mul_chars(a, b) (char_to_digit(a) * char_to_digit(b))
#define add_chars(a, b) (char_to_digit(a) + char_to_digit(b))
#define isdigit(x) ((x) >= '0' && (x) <= '9')


typedef unsigned long int size_t;

int _putchar(char c);
char *infinite_multiply(char *n1, char *n2);
void rev_string(char *str);
void add_digit(char *buf, int digit);
void *_calloc(size_t nmemb, size_t size);
size_t _strlen(char *str);
int valid_inputs(char *n1, char *n2);
char *skip_leading_zeroes(char *str);
int _puts(char *str);

#endif /* HOLBERTON_H */
