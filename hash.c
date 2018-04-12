#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define len 10

int hashTable[len];

int hash(int num) {
	return num % 10;
}

void initializeHashTable() {
	for (int i = 0; i < len; i++) {
		hashTable[i] = INT_MIN;
	}
}

void insertIntoHashTable(int num) {
	int pos = hash(num);
	// Check for collission
	while (hashTable[pos] != INT_MIN) {
		if(pos == len - 1) {
			pos = 0;
		} else {		
			pos++;
		}
	}
	hashTable[pos] = num;
}

int foundInTable(int num) {
	// found at position
	if (hashTable[hash(num)] == num) {
		return 1;
	} else {
		for(int pos = 0; pos < len; pos++) {
			if (hashTable[pos] == num) return 1;
		}
		return 0;
	}
}

void search(int num) {
	if( foundInTable(num) ) {
		printf("\nFound\n");
	} else {
		printf("\nNot Found\n");
	}
}

int main(void) {
	int num;
	initializeHashTable();
	printf("Enter 10 numbers\n");
	for(int i = 0; i < 10; i++) {
		scanf("%d", &num);
		insertIntoHashTable(num);
	}
	printf("\nEnter number you want to search for\n");
	scanf("%d", &num);
	search(num);
	return 0;
}

