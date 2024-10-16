// Copyright Dascalu Stefan-Nicolae 321CA 2023 - 2024
#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#define MODULO 10007

/**
 * Allocates a matrix with the given number of rows and columns.
 * @param rows Number of rows in the matrix.
 * @param columns Number of columns in the matrix.
 * @return A matrix structure with allocated memory for the given dimensions.
 */
matrix alloc_matrix(int rows, int columns)
{
	matrix mat;
	mat.rows = rows;
	mat.columns = columns;

	mat.matrix = (int **)malloc(rows * sizeof(int *));
	if (!mat.matrix) {
		printf("Failed to allocate");
		free(mat.matrix);
		exit(-1);
	}

	for (int i = 0; i < rows; i++) {
		mat.matrix[i] = (int *)malloc(columns * sizeof(int));
		if (!mat.matrix[i]) {
			printf("Failed to allocate");
			for (int j = 0; j <= i; j++)
				free(mat.matrix[j]);
			free(mat.matrix);
			exit(-1);
		}
	}

	mat.sum = 0;
	return mat;
}

/**
 * Allocates or reallocates an array of matrices.
 * @param array Pointer to an array of matrices.
 * @param size_number Pointer to the size of the allocated array.
 * @param number Pointer to the current number of matrices in the array.
 */
void alloc_array(matrix **array, int *size_number, int *number)
{
	*number = *number + 1;

	if (!(*array)) {
		*array = (matrix *)malloc(*number * sizeof(matrix));
		if (!array) {
		    printf("Failed to allocate");
		    free(array);
		    exit(-1);
		}
		*size_number = 1;
	} else if (*size_number < *number) {
		*size_number = *size_number * 2;
		*array = (matrix *)realloc(*array, *size_number * sizeof(matrix));

		if (!array) {
			printf("Failed to alocate");
			free(array);
			exit(-1);
	}
	}
}

/**
 * Reads and fills a matrix with values from standard input.
 * @param array Array of matrices.
 * @param number Index of the matrix in the array to be filled.
 */
void read_matrix(matrix *array, int number)
{
	int cs; // for coding style
	for (int i = 0; i < array[number].rows; ++i) {
		for (int j = 0; j < array[number].columns; ++j) {
			scanf("%d", &array[number].matrix[i][j]);
			cs = (array[number].sum + array[number].matrix[i][j]) % MODULO;
			array[number].sum = (cs + MODULO) % MODULO;
		}
	}
}

/**
 * Frees the memory allocated for an array of matrices.
 * @param array Array of matrices to be freed.
 * @param number Number of matrices in the array.
 */
void free_matrix(matrix *array, int number)
{
	for (int i = 0; i < number; i++)
		for (int j = 0; j < array[i].rows; j++)
			free(array[i].matrix[j]);

	for (int i = 0; i < number; i++)
		free(array[i].matrix);
}

/**
 * Frees the memory allocated for a single matrix.
 * @param array The matrix to be freed.
 */
void free_mat(matrix array)
{
	for (int i = 0; i < array.rows; ++i)
		free(array.matrix[i]);
	free(array.matrix);
}

/**
 * Prints the dimensions of a specified matrix from an array.
 * @param array Array of matrices.
 * @param number Index of the matrix whose dimensions are to be printed.
 */
void show_dimensions_matrix(matrix *array, int number)
{
	int index;
	scanf("%d", &index);

	if (index > number - 1 || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	printf("%d %d\n", array[index].rows, array[index].columns);
}

/**
 * Prints the contents of a specified matrix from an array.
 * @param array Array of matrices.
 * @param number Index of the matrix to be printed.
 */
void print_matrix(matrix *array, int number)
{
	int index;
	scanf("%d", &index);

	if (index > number - 1 || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	for (int i = 0; i < array[index].rows; i++) {
		for (int j = 0; j < array[index].columns; j++)
			printf("%d ", array[index].matrix[i][j]);
		printf("\n");
	}
}

/**
 * Cuts a matrix to a smaller size based on specified rows and columns.
 * @param array Array of matrices.
 * @param number Index of the matrix in the array to be cut.
 */
void cut_matrix(matrix *array, int number)
{
	int index, n, m, cs;
	scanf("%d", &index);

	scanf("%d", &n);
	int *rows;

	rows = (int *)malloc(n * sizeof(int));
	if (!rows) {
		printf("Failed to alocate");
		free(rows);
		exit(-1);
	}

	for (int i = 0; i < n; ++i)
		scanf("%d", &rows[i]);

	scanf("%d", &m);
	int *columns;

	columns = (int *)malloc(m * sizeof(int));
	if (!columns) {
		printf("Failed to alocate");
		free(array);
		exit(-1);
	}

	for (int j = 0; j < m; ++j)
		scanf("%d", &columns[j]);

	if (index > number - 1 || index < 0) {
		printf("No matrix with the given index\n");
		free(rows);
		free(columns);
		return;
	}

	matrix new_matrix = alloc_matrix(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			new_matrix.matrix[i][j] = array[index].matrix[rows[i]][columns[j]];
			cs = ((new_matrix.sum + new_matrix.matrix[i][j]) % MODULO);
			new_matrix.sum = (cs + MODULO) % MODULO;
		}
	}

	free_mat(array[index]);
	free(rows);
	free(columns);

	array[index] = new_matrix;
}

/**
 * Multiplies two matrices from an array and returns the result.
 * @param array Array of matrices.
 * @param number Pointer to the total number of matrices in the array.
 * @return The resulting matrix after multiplication.
 */
matrix multiply_matrix(matrix *array, int *number)
{
	int index1, index2, cs; // for coding style
	scanf("%d %d", &index1, &index2);

	if (index1 > *number - 1 || index2 > *number - 1) {
		printf("No matrix with the given index\n");
		exit(0);
	}

	if (index1 < 0 || index2 < 0) {
		printf("No matrix with the given index\n");
		exit(0);
	}

	if (array[index1].columns != array[index2].rows) {
		printf("Cannot perform matrix multiplication\n");
		exit(0);
	}

	matrix aux;
	aux = alloc_matrix(array[index1].rows, array[index2].columns);

	for (int i = 0; i < array[index1].rows; i++)
		for (int j = 0; j < array[index2].columns; j++) {
			int sum = 0;
			for (int k = 0; k < array[index1].columns; k++) {
				cs = array[index1].matrix[i][k] * array[index2].matrix[k][j];
				cs = sum + cs % MODULO;
				sum = ((cs % MODULO) + MODULO) % MODULO;
			}
			aux.matrix[i][j] = sum;
			aux.sum = (((aux.sum + sum) % MODULO) + MODULO) % MODULO;
		}

	return aux;
}

/**
 * Sorts an array of matrices based on their sum property.
 * Using merge sort algorithm.
 * @param array Array of matrices to be sorted.
 * @param left Starting index for sorting.
 * @param right Ending index for sorting.
 */
void sort_matrix(matrix *array, int left, int right)
{
	if (left >= right)
		return;

	int middle = (left + right) / 2;
	sort_matrix(array, left, middle);
	sort_matrix(array, middle + 1, right);

	int left_size = middle - left + 1;
	int right_size = right - middle;

	matrix *left_array = (matrix *)malloc(left_size * sizeof(matrix));
	if (!left_array) {
		printf("Failed to allocate");
		free(left_array);
		exit(-1);
	}

	matrix *right_array = (matrix *)malloc(right_size * sizeof(matrix));
	if (!right_array) {
		printf("Failed to allocate");
		free(right_array);
		exit(-1);
	}

	for (int i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for (int j = 0; j < right_size; j++)
		right_array[j] = array[middle + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < left_size && j < right_size) {
		if (left_array[i].sum <= right_array[j].sum) {
			array[k] = left_array[i];
			i++;
		} else {
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < left_size) {
		array[k] = left_array[i];
		i++;
		k++;
	}

	while (j < right_size) {
		array[k] = right_array[j];
		j++;
		k++;
	}

	free(left_array);
	free(right_array);
}

/**
 * Transposes a specified matrix from an array.
 * @param array Array of matrices.
 * @param number Index of the matrix to be transposed.
 */
void transpose_matrix(matrix *array, int number)
{
	int index;
	scanf("%d", &index);

	if (index > number - 1 || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	matrix aux = alloc_matrix(array[index].columns, array[index].rows);
	aux.sum = array[index].sum;

	for (int i = 0; i < array[index].rows; i++)
		for (int j = 0; j < array[index].columns; j++)
			aux.matrix[j][i] = array[index].matrix[i][j];

	free_mat(array[index]);
	array[index] = aux;
}

/**
 * Raises a specified matrix from an array to a given power.
 * @param array Array of matrices.
 * @param number Index of the matrix to be raised to a power.
 */
void raise_matrix(matrix *array, int number)
{
	int index, power;
	scanf("%d %d", &index, &power);
	if (index > number - 1 || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	if (power < 0) {
		printf("Power should be positive\n");
		return;
	}

	if (array[index].rows != array[index].columns) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	if (power == 0) {
		for (int i = 0; i < array[index].rows; i++) {
			for (int j = 0; j < array[index].columns; j++) {
				if (i == j)
					array[index].matrix[i][j] = 1;
				else
					array[index].matrix[i][j] = 0;
			}
		}
	}

	//..
}

/**
 * Deletes a specified matrix from the array based on a given index and
 * rearranges the array.
 * The function ensures that the array of matrices
 * remains properly ordered after the deletion of any matrix.

 * @param array The array of matrices from which a specific
	matrix is to be deleted.
 * @param number Pointer to the total number of matrices in the array,
	which will be updated after the deletion.
 */
void delete_matrix(matrix *array, int *number)
{
	int index;
	scanf("%d", &index);

	if (index > *number - 1 || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	free_mat(array[index]);
	for (int i = index; i < *number - 1; i++)
		array[i] = array[i + 1];

	*number = *number - 1;
}

