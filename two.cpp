#include <iostream> //Required for cout
#include <stdlib.h> //Required for malloc, free

using namespace std;

int getIndex(int* array, int pos){
	return *(array + pos); //Assigns the pointer to allocated memory for 5 int objects
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