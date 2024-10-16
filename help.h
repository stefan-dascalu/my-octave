// Copyright Dascalu Stefan-Nicolae 321CA 2023 - 2024
#ifndef HELP_H
#define HELP_H

typedef struct {
	int **matrix;
	int rows, columns, sum;
} matrix;

matrix alloc_matrix(int rows, int columns);
void alloc_array(matrix **array, int *size_number, int *number);
void read_matrix(matrix *array, int number);
void free_matrix(matrix *array, int number);
void free_mat(matrix array);
void show_dimensions_matrix(matrix *array, int number);
void print_matrix(matrix *array, int number);
void cut_matrix(matrix *array, int number);
matrix multiply_matrix(matrix *array, int *number);
void sort_matrix(matrix *array, int left, int right);
void transpose_matrix(matrix *array, int number);
void delete_matrix(matrix *array, int *number);
void raise_matrix(matrix *array, int number);

#endif
