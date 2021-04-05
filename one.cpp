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