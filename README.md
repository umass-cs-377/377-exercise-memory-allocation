# COMPSCI 377 LAB: Memory Allocation

## Purpose

This lab is designed to cover various forms of memory in C++, through the malloc function, pointers, and how to manipulate existing memory. Please make sure that all of your answers to questions in these labs come from work done on the Edlab environment – otherwise, they may be inconsistent results and will not receive points.

Please submit your answers to this lab on Gradescope. All answers are due by the time specified on Gradescope. The TA present in your lab will do a brief explanation of the various parts of this lab, but you are expected to answer all questions by yourself. Please raise your hand if you have any questions during the lab section – TAs will be notified you are asking a question. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade. Labs are weighted equally, regardless of their total points.

## Part 1: Malloc (10 Points)

Whenever we code programs, we need to ensure that the program has enough memory to support the data structures used in its runtime. Often this is achieved through the ‘new’ keyword, in code such as ‘int[] something = new int[10]’, which automatically assigns the memory required for a specific structure upon initialization. If we do not have the proper memory allocated, then our code will inevitably run into a Segmentation Fault if we try to access the data outside of what we have put aside. However, using C++ we can more finely allocate memory for our program via the ‘malloc’ method. The method takes a single parameter, which is the size of the assigned memory in terms of bytes. This means that for a data structure that would take 8 bytes, the command malloc(8) would assign enough memory to provide enough space for that structure. Additionally, the method returns the pointer to the first byte of the allocated block of memory, so that it can be referenced later. Especially useful for this reference is the free() method, which allows us to de-allocated memory from our code that is not being used. In programs with a limited memory space, this can be vital to ensure that there is not too much space being utilized. Please look at the following code, and then answer the subsequent questions about malloc:

```
#include <iostream> //Required for cout
#include <stdlib.h> //Required for malloc, free

using namespace std;

int main() {
	int* memory; //Declares a new pointer
	memory = (int*)malloc(5 * sizeof(int)); //assigns the pointer to allocated memory for 5 int objects

	cout << "Memory Allocated At: " << memory << "\n";
	
	if (memory == NULL){
		return 1; //Only occurs if memory allocation fails and malloc() returns NULL
	}

	for (int i = 0; i < 5; i++){
		memory[i] = i; //Sets the values in the allocated array
	}

	for (int i = 0; i < 5; i++){
		cout << memory[i] << " "; //Prints out the allocated array
	}
	cout << "\n";

	free(memory); //Frees the allocated memory

	cout << "Memory Has Been Freed.\n";

	return 0;
}
```

## Part 2: Pointers (10 Points)
In previous labs, we have discussed utilizing pointers with simple data types like integer and strings. However, we can also use pointers for more complex data structures, and manipulate them using references to pointers. Additionally, we can use arithmetic with pointers to get values located at locations relative to existing pointers. Using this math, we can also manipulate existing pointers, such as incrementing one to iterate through an array. Take the example code below using pointers with arrays, modified from the previous part’s code:

```
#include <iostream> //Required for cout
#include <stdlib.h> //Required for malloc, free

using namespace std;

int getIndex(int* array, int pos){
	return *(array + pos); //Prints out the data located at the memory address (array + pos)
}

int main() {
	int* memory; //Declares a new pointer
	memory = (int*)malloc(5 * sizeof(int)); //assigns the pointer to allocated memory for 5 int objects

	cout << "Memory Allocated At: " << memory << "\n";
	
	if (memory == NULL){
		return 1; //Only occurs if memory allocation fails and malloc() returns NULL
	}

	for (int i = 0; i < 5; i++){
		memory[i] = i; //Sets the values in the allocated array
	}

	cout << "Printing once... ";
	for (int i = 0; i < 5; i++){
		cout << getIndex(memory, i) << " "; //Prints out the allocated array using a modified pointer via getIndex()
	}
	cout << "\n";

	cout << "Printing twice... ";
	int* incremented = memory; //Sets a new pointer at the same address of memory
	for (int i = 0; i < 5; i++){
		cout << *incremented << " "; //Prints out the data stored at the location of the pointer
		incremented++; //Increments the new pointer
	}
	cout << "\n";

	free(memory); //Frees the allocated memory

	cout << "Memory Has Been Freed.\n";

	return 0;
}
```
