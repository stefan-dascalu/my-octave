// Copyright Dascalu Stefan-Nicolae 321CA 2023 - 2024
#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main(void)
{
	matrix *array = NULL; // Pointer to the array of matrices
	int number = 0;       // Number of matrices currently in the array
	int size_number = 0;  // Size of the allocated memory for the array
	char command;         // Command input by the user

	do {
		scanf(" %c", &command);
		switch (command) {
		case 'L':
			alloc_array(&array, &size_number, &number);
			int n, m;
			scanf("%d %d", &n, &m);
			array[number - 1] = alloc_matrix(n, m); // Allocate and store matrix
			read_matrix(array, number - 1); // Fill the matrix with data
			break;
		case 'D':
			show_dimensions_matrix(array, number);
			break;
		case 'P':
			print_matrix(array, number);
			break;
		case 'C':
			cut_matrix(array, number);
			break;
		case 'M':
			alloc_array(&array, &size_number, &number);
			array[number - 1] = multiply_matrix(array, &number);
			break;
		case 'T':
			transpose_matrix(array, number);
			break;
		case 'O':
			sort_matrix(array, 0, number - 1);
			break;
		case 'F':
			delete_matrix(array, &number);
			break;
		case 'R':
			raise_matrix(array, number);
			break;
		case 'Q':
			free_matrix(array, number); // Free the array of matrices
			free(array); // Free the pointer to the array
			break;
		default:
			printf("Unrecognized command\n");
		break;
		}
	} while (command != 'Q');

	return 0;
}
