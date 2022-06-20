# COMPSCI 377 Exercise: Memory Allocation

## Purpose

This exercise is designed to cover various aspects of memory in C/C++: the `malloc` and `free` functions, pointers, and how to manipulate memory. Please make sure that all of your answers to questions in these exercises come from work done on the Edlab environment – otherwise, they may be inconsistent results and will not receive points. Please read through this document and follow the instructions. After you do that, visit Gradescope and complete the questions associated with this exercise by the assigned due date.

## Setup

Once you have logged in to Edlab, you can clone this repo using

```bash
git clone https://github.com/umass-cs-377/377-exercise-memory-allocation.git
```

Then you can use `cd` to open the directory you just cloned:

```bash
cd 377-memory-allocation
```

This repository includes a `Makefile` that allows you to locally compile and run all the sample code listed in this tutorial. You can compile them by running `make`. Feel free to modify the source files yourself, after making changes you can run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something went wrong during the compilation so that you can start fresh.

## Part 1: Malloc

Whenever we code programs, we need to ensure that the program has enough memory to support the data structures used in its runtime. In C++, we can use the ‘new’ keyword. For example, `int[] something = new int[10];` which allocates a 10 integer array on the heap. There is, however, another method for allocating memory in C and C++ programs by using the ‘malloc()’ function. There are other related functions, such as `calloc` and `realloc`, that allocate memory. If you are interested in learning more about those functions use man: `man 3 malloc`. The `malloc` function takes a single parameter, the size of the memory we want to allocate, in terms of bytes. For example, if we would like to allocate 8 bytes, we can call the command `malloc(8);`. The function returns the pointer to the first byte of the allocated block of memory to be referenced later in our code. For example, we can use the pointer to perform pointer arithmetic to access any element within (or outside of ☠️) the allocated memory region. When we are done using that memory, we need to pass the reference to `free()` to manually de-allocate memory in use by our program that is no longer needed. If we do not do this our program will leak memory, that is, it will continue to be allocated, but our program no longer uses it and may not even have a reference to it. Please look at the following code, and then answer the related questions in the exercise about `malloc`:

```cpp
#include <stdlib.h>  //Required for malloc, free

#include <iostream>  //Required for cout

using namespace std;

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

  for (int i = 0; i < 5; i++) {
    cout << memory[i] << " ";  // Prints out the allocated array
  }
  cout << "\n";

  free(memory);  // Frees the allocated memory

  cout << "Memory Has Been Freed.\n";

  return 0;
}
```

## Part 2: Pointers

In prior assignments, we have discussed utilizing pointers with simple data types like integer and strings. However, we can also use pointers for more complex data structures and use pointers to manipulate them in various ways. Additionally, we can use arithmetic with pointers to get values located at memory locations relative to existing pointers. For example, we can use pointer arithmetic for incrementing a pointer through an array rather than use array indexing. Take the example code below using pointers with arrays, modified from the previous part’s code:

```cpp
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
```
