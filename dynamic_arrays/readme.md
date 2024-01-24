# Dynamic Array

### Overview

Here is an impementation of a dynamic array created to behave like std::vector. This program keeps track of the balance and transaction made on a debit card. The debit card object contains a list of transactions. this list of transactions is the dynamic array. You will see the dynamic array in the DynamicArray class. 

### Why a Dynamic Array?
In C/C++, arrays are declared like this:
```c++
int myNums[10];
```
The compiler needs to know the value of 'size' at compile time in order reserve enough memory for the array. Because of this, 'size' must be a known constant and cannot be determined at runtime. We could get around this by allocating memory to the heap like this:
```c++
int* myNums = new int[size_determined_at_runtime]
```
However, this can become tiresome since the programmer will have to deallocate and reallocate when they want to expand or grow the array. 

A dynamic array is desiged to automate the memory allocation process.

A dynamic array will detect when the array has ran out of space and allocate a larger amount of memory and deallocate the smaller array that is no longer needed. on the heap to be used. A well designed dynamic array will handle proper memory management giving more power to the programmer with this simple data structure!

### Run This Program
This program has been compiled on a linux os for x86 architecture. The executable is located in this directory as dynarray.exe you can run it with the following command:
```sh
./dynamic_arrays/dynarray.exe 
```
