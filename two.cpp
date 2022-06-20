#include <stdlib.h>  //Required for malloc, free

#include <iostream>  //Required for cout

using namespace std;

int getIndex(int* array, int pos) {
  // Assigns the pointer to allocated memory for 5 int objects
  return *(array + pos);
}

int main() {
  int* memory;  // Declares a new pointer

  // Assigns the pointer to allocated memory for 5 int objects
  memory = (int*)malloc(5 * sizeof(int));

  // If we get a null pointer, we ran out of memory
  if (memory == NULL) {
    return 1;
  }

  cout << "Memory Allocated At: " << memory << "\n";

  for (int i = 0; i < 5; i++) {
    memory[i] = i;  // Sets the values in the allocated array
  }

  cout << "Printing once... ";
  for (int i = 0; i < 5; i++) {
    // Prints out the allocated array using a modified pointer via getIndex()
    cout << getIndex(memory, i) << " ";
  }
  cout << "\n";

  cout << "Printing twice... ";
  int* incremented = memory;  // Sets a new pointer at the same address of
                              // memory
  for (int i = 0; i < 5; i++) {
    cout << *incremented
         << " ";    // Prints out the data stored at the location of the pointer
    incremented++;  // Increments the new pointer
  }
  cout << "\n";

  free(memory);  // Frees the allocated memory

  cout << "Memory Has Been Freed.\n";

  return 0;
}