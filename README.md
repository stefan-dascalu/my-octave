// Copyright Dascalu Stefan-Nicolae 321CA 2023 - 2024

		Task 'L' - Load Matrix
	The 'L' task involves dynamically allocating a new matrix. 
	The program maintains an array of matrix structures, each representing an individual matrix. 
	Upon receiving the 'L' command followed by dimensions (rows and columns), the program resizes the matrix array using alloc_array,
then allocates a new matrix with the specified dimensions using alloc_matrix. 
	The newly created matrix is then filled with data using read_matrix. In case of allocation failure,
an error message is displayed, and the program exits.

		Task 'D' - Display Dimensions
	On receiving the 'D' command and an index, this task displays the dimensions of the matrix 
at the specified index in the array. 
	The dimensions are accessed directly from the matrix structure, which stores the number of rows and columns.

		Task 'P' - Print Matrix
	Similar to 'D', the 'P' task prints the entire matrix at the given index. 
	It checks for a valid index and uses a loop to display each element of the matrix,
utilizing the dimensions stored within the matrix structure.

		Task 'T' - Transpose Matrix
	The 'T' task transposes a matrix at a given index. 
	After validating the index, it uses transpose_matrix to swap the rows and columns of the matrix, 
reallocating the matrix as needed and updating its dimensions.

		Task 'M' - Multiply Matrices
	This task multiplies two matrices, identified by their indices, ensuring their dimensions are compatible for multiplication. 
It uses multiply_matrix, which handles the multiplication process and updates the resulting matrix in the array.

		Task 'C' - Cut Matrix
	The 'C' task reduces the size of a matrix based on specified rows and columns. 
	After validating the index, it reads the dimensions for the cut and uses cut_matrix to create a 
new matrix of the required size, copying the relevant elements from the original matrix.

		Task 'F' - Delete Matrix
	Upon receiving the 'F' command followed by the index of the matrix to be deleted, the function delete_matrix is called. 
	This function takes care of deallocating the memory used by the specified matrix and ensures 
the continuity of the matrix array by rearranging the remaining matrices. After the deletion, 
it updates the total count of matrices in the array, maintaining an accurate record of 
the matrices currently managed by the program.

		Task 'O' - Sort Matrices
	On receiving the 'O' command, the suite sorts the entire array of matrices based on a specific property
(like the sum of elements) using the sort_matrix function.
	It implements a merge sort algorithm for this purpose.

		Task 'Q' - Quit
	The 'Q' command exits the program, ensuring all allocated memory for the matrix array is properly freed using free_matrix.

		Default Case
	Handles unrecognized commands by displaying an appropriate error message.

