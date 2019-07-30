#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include "Header.h"
using namespace std;


//--- Display ARRAY ---
// Display the array to the screen
void displayArray(vector<string> vec,int size) {

	for (int i = 0; i < size; i++) {
		cout << i << ": [" << vec[i] << "], \n";
	};

};//END DISPLAYARRAY


//--- READ ARRAY ---
vector<string> readArray() {

	vector<string> namesVector;

	string namesArr[100] = {};

	string name;

	ifstream inputFile;
	inputFile.open("names.txt");

	if (inputFile) {

		for (int i = 0; i < MAXNAMES; i++) {

			// Get string from line
			getline(inputFile, name);

			cout << name << endl;

			// Store the variable in Vector
			namesVector.push_back(name);

			// Store the variable to a cell in the array
			namesArr[i] = name;
		};

	}
	else {
		cout << "ERROR - CANT READ FILE" << endl;
	};


	inputFile.close();

	/* cout << "\n2) --- Display Vector --- " << endl;

	for (int i = 0; i < MAXNAMES; i++) {
		cout << namesVector[i];
	}; */

	return namesVector;
};//END READARRAY


//---  SELECTION SORT ---
//Sort a string array in ascending order
vector<string> selectionSort(vector<string> &v) {
	
	int minIndex;
	string minValue;

	for (int start = 0; start < (v.size() - 1); start ++) {

		minIndex = start;
		minValue = v[start];

		for (int index = start + 1; index < v.size(); index++) {

			if (v[index] < minValue) {

				minValue = v[index];
				minIndex = index;

			}; // end if

		}; // end for 2
		swap(v[minIndex],v[start]);
	}; // end for

	displayArray(v, v.size());

	return v;

};//END SELECTION SORT

//---  SEQUENTIAL / LINEAR SORT ---
// Performs a linear search on an array
int sequentialSearch(const vector<string> &v, string str) {

	int index = 0;
	int position = -1;
	bool found = false;

	while (index < v.size() && !found) {
	
		if (v[index] == str) {
		
			found = true;
			position = index;

		}; // end if
		index++;
	}; // END WHILE
	return position; 

};//END SEQUENTIAL / Linear Seach

//---  BUBBLE SORT ---
// Sort a string array in acending order
vector<string> bubbleSort(vector<string> v) {
	
	int maxElement, index;

	for (maxElement = v.size() - 1; maxElement > 0; maxElement--) {
		for (index = 0; index < maxElement; index++) {
			if (v[index] > v[index + 1]) {
				swap(v[index],v[index + 1]);
			};
		}; // END FOR2
	}; // END FOR

	displayArray(v, v.size() );

	return v;

};//END BUBBLE SORT

//---  BINARY SEARCH ---
// Perform a binary search on an array
int binarySearch(vector<string> v, string str) {

	int first = 0,
		last = v.size() - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last) {
		
		middle = (first + last) / 2; // Calculate mid point
		if (v[middle] == str) {
			found = true;
			position = middle;
		}
		else if (v[middle] > str) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}; // end if, else if, else

	}; // end while

	return position;

};//END BINARY SEARCH


// MAIN FUNCTION
int main() {

	vector<string> mainVector;
	string searchValue, newName;
	int position;

	cout << "1) --- Read Names from File --- " << endl;

	mainVector = readArray();

	cout << "\n\n2) --- Display Vector\n\n";

	displayArray(mainVector, MAXNAMES); 

	cout << "\n\n3) --- Selection Sort\n\n";

	// Selection Sort

	mainVector = selectionSort(mainVector);

	// Sequential Search
	cout << "\n\n4) --- Sequential Search\n\n";
	do {
		cout << "\nEnter your name to search (lastname, firstname):";
		getline(cin, searchValue);

		position = sequentialSearch(mainVector, searchValue);

		if (position != -1)
			cout << "\nYour name is found at position: " << position << endl;
		else {
			cout << "\nYour name is not found\n";

			cout << "\nEnter Your Name to Add to Array Like: Lastname, Firstname" << endl;
			getline(cin, newName);
			mainVector[0]= newName;

			cout << "\nUpdated Vector with your name: " << endl;
			displayArray(mainVector, mainVector.size());
		};

		
	} while (position == -1);

	// Bubble Sort
	cout << "\n\n5) --- Bubble Sort\n\n";

	mainVector = bubbleSort(mainVector);

	// Binary Search 
	cout << "\n\n6) --- Binary Search\n\n";
	do {
		cout << "\nEnter name to search:";
		getline(cin, searchValue);

		position = binarySearch(mainVector, searchValue);

		if (position != -1)
			cout << "\nThat name is found at position: " << position << endl;
		else
			cout << "\nThat name is not found\n";
	} while (position == -1);

	cout << "\n\nCongrats, we are done assignment 4!!!";
	cout << "\nPress Any Key to Exit";

	_getch();


} // END FUNCTION MAIN


