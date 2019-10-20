/// 
/// File: triangle.c 
/// 
/// A program to print out multiple "pyramid" triangles of the form:
/// <pre>
///   *
///  ***
/// *****
/// </pre>
/// 
/// @author TODO_AUTHOR_ID_ : TODO_AUTHOR_FULL_NAME_ Sarah Strickman sxs4599
/// 
// // // // // // // // // // // // // // // // // // // // // // // // 

// TODO_ADD_#INCLUDES_ HERE
#include <stdlib.h>
#include <stdio.h>

/**
 *  Function: drawTriangle
 *
 *  Description: Draw a 'pyramid' triangle whose base width is 'size'.
 *  Note: If size is even, the function makes a 'size + 1' pyramid triangle. 
 * 
 *  @param size  the width of the base of the triangle to draw
 */
// TODO_WRITE_DRAWTRIANGLE_FUNCTION HERE
int drawTriangle(int size) {
	// if the size is < 0, return an error code
	// otherwise, do the triangle thing
	if(size < 0) {
		return 1;
	}
	if(size % 2 == 0) {
		// if the size number is even
		// add 1 to it
		size = size + 1;
	}
	printf("\n");

	int numSpaces = size / 2; // number of spaces to print in each line
		//will be the floor of the function!

	int numChars = 1; // number of characters to print out in each line

	int counter = 0; // counter that will keep track of what to print

	while(numChars <= size) {
		// while the max number of characters haven't been printed in 1 line,
		// print the number of spaces that are in 1 line.
		// Then print the number of characters in the line. 
		// Then print a newline character and set the stage for the next line
		counter = 0;

		while(counter < numSpaces) {
			printf(" ");
			counter++;
		}

		counter = 0;

		while(counter < numChars) {
			printf("*");
			counter++;
		}
		printf("\n");
		numSpaces -= 1;
		numChars += 2;
	}
	return EXIT_SUCCESS;
}


/**
 *  Function: main 
 *
 *  Description: draws pyramid triangles of size 1, 5, and '6'.
 *
 *  @returns errorCode  error Code; EXIT_SUCCESS if no error
 */
// TODO_WRITE_MAIN_FUNCTION HERE
int main() {
	int a = drawTriangle(1);
	int b = drawTriangle(5);
	int c = drawTriangle(6);
	printf("\n");
	if (a + b + c == 0) {
		return EXIT_SUCCESS;
	}
	else {
		return 1;
	}
}
