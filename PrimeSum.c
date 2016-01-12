/*
Name: Tyler Gauntlett
NID: ty340586
Course: COP 3502 Fall 2015
Date 9/4/2015
*/

#include <stdio.h>
#include <stdlib.h>

// Assigns assignment specified t and n values.
#define NATURALNUMBERS 20000
#define PRIMENUMBERS 10000

// Initializing function.
int* getArray(int input);

int main(){
	
	// Initializing user defined variables.
	int input, numOfCases;

	// User enters the number of times they wish to run the program.
	scanf("%i", &numOfCases);

	// Loop that runs the program a user entered number of times.
	while (numOfCases > 0){

		// User input that decieds the size of the memory in the
		// returning fuction.
		scanf("%i", &input);

		// Array containing the sums of the prime numbers.
		// The function is the P(n) function specified in the
		// assignment instructions.
		int* primeNumbers = getArray(input);

		// Prints the value located in the array of added sums. -1 is used
		// to pick the second to last index (memory overflow without it).
		printf("%i\n", primeNumbers[input-1]);


		// Frees the memory back to the computer before recycling the function.
		free(primeNumbers);

		// Decrements the original number of cases specified by the user.
		numOfCases--;
	}

	return 0;
}



int* getArray(int input){
	// Initializing static variables.
	int i, j, tempStore = 0;

	// Initializing static arrays.
	int primeNumbers[PRIMENUMBERS], naturalNumbers[NATURALNUMBERS];


	// Dynamically allocated an array that will ultimately store
	// the added sums of prime numbers.
	int* storeNumbers = malloc(sizeof(int)*input);


	// Fills in an array with all possible prime number options
	// (0 and 1 are not included).
	for (i = 0; i< NATURALNUMBERS; i++){
		naturalNumbers[i] = i + 2;
	}


	// Looks at each index in natural numbers,
	// then compares it to the value -1. If the value is prime,
	// it takes all future multiples of the prime number and makes them -1.
	// After marking that prime number, it moves forward and continues marking
	// muliples of prime numbers until all values are either -1 or prime numbers.
	for (i = 0; i < NATURALNUMBERS; i++){
		if (naturalNumbers[i] != -1){
			for (j = 2 * naturalNumbers[i] - 2; j < NATURALNUMBERS; j = j + naturalNumbers[i]){
				naturalNumbers[j] = -1;
			}
		}
	}


	// If the value is not marked -1 from the preivous sieve, it is then
	// stored into another array that only holds prime numbers.
	// Both indexs are incrimented until all numbers have been added
	// to the new array.
	j = 0;
	for (i = 0; i < NATURALNUMBERS && j < PRIMENUMBERS; i++){
		if (naturalNumbers[i] != -1){
			primeNumbers[j] = naturalNumbers[i];
			j++;
			
		}
	}


	// Funciton that takes the prime numbers array and adds
	// them together and inputs them into an array that stores
	// specifically what index each sum exists.
	for (i = 0; i < input; i++){

		// Adds the number currently residing in
		// the index with the number residing in
		// the next index.
		tempStore = tempStore + primeNumbers[i];

		// Stores the added number into storeNumber index.
		if (storeNumbers[i] < input){
			storeNumbers[i] = tempStore;
		}

	}


	// Returns a pointer to the array holding the added sum values.
	return storeNumbers;

}