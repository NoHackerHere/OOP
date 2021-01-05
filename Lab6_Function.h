#ifndef GRIDSEARCH_H
#define GRIDSEARCH_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int SIZE = 16; // Constant value that determines size of array

int row, col;

// Function Prototypes for populating and printing grid //
bool gridFill (char (&charArray)[SIZE][SIZE], int, string); // Imports grid from file and populates array
void gridPrint (char (&charArray)[SIZE][SIZE], int); // Prints the grid after population, columns then rows

// Modifying List //
//void addToList (string, int, int, bool); // Adds word to list and assigns whether found or not found tag
//void exportList (); // Saves list of searched words to a .txt file
//void printList (); // Prints all elements of list

// Searching Functions //
bool searchValid (char (&charArray)[SIZE][SIZE], string, int);
bool searchUp (char (&charArray)[SIZE][SIZE], int, int, string, int);
bool searchDown (char (&charArray)[SIZE][SIZE], int, int, string, int);
bool searchLeft (char (&charArray)[SIZE][SIZE], int, int, string, int);
bool searchRight (char (&charArray)[SIZE][SIZE], int, int, string, int);
bool searchList (string);

// Function Definitions //
bool gridFill (char (&charArray)[SIZE][SIZE], int size, string filename) {
        // Import Search Grid and Insert as elements in character Array //
	bool greatSuccess = 0;
        ifstream gridSearch_1 (filename.c_str()); // Does not like filename as variable instead of direct string name
        int colelementInsert; // Placeholder to move within array column-wise
        int rowelementInsert; // Placeholder to move within array row-wise
        for (rowelementInsert = 0; rowelementInsert < size; rowelementInsert++) {
                for (colelementInsert = 0; colelementInsert < size; colelementInsert++) {
                        gridSearch_1 >> charArray[rowelementInsert][colelementInsert];
                }
        }
        gridSearch_1.close();
        if (!gridSearch_1.is_open()) {greatSuccess = 1;}

	return greatSuccess;
}

void gridPrint (char (&charArray)[SIZE][SIZE], int size) {
        int colelementPrint;
        int rowelementPrint;
        for (rowelementPrint = 0; rowelementPrint < size; rowelementPrint++) {
                for (colelementPrint = 0; colelementPrint < size; colelementPrint++) {
                        cout << charArray[rowelementPrint][colelementPrint] << " ";
                }
                cout << endl; // Jumps to next row to begin next print line
        }
}

bool searchValid (char (&charArray)[SIZE][SIZE], string searchWord, int size) {
        bool found = false;
        int searchRow;
        int searchCol;
	int wordLen = searchWord.length();
        for (searchRow = 0; searchRow < size; searchRow++) {
                for (searchCol = 0; searchCol < size; searchCol++) {
                        if (searchWord[0] == charArray[searchRow][searchCol]) {
                                bool rightFound = searchRight (charArray, searchRow, searchCol, searchWord, wordLen);
				bool leftFound = searchLeft (charArray, searchRow, searchCol, searchWord, wordLen);
				bool upFound = searchUp (charArray, searchRow, searchCol, searchWord, wordLen);
				bool downFound = searchDown (charArray, searchRow, searchCol, searchWord, wordLen);
				if (rightFound) { // Prints the word, row, col, and adds to list
					cout << "Slide to the right. " << endl;
        		                cout << searchWord << " | Row " << searchRow << ", " << "Column " << searchCol << endl;
					//wordList_c::addToList(searchWord, searchRow, searchCol, 1); // Adds word to the list
					row = searchRow;
					col = searchCol;
					found = true;
					continue;
				}
				if (leftFound) { // Prints the word, row, col, and adds to list
					cout << "Slide to the left. " << endl;
					cout << searchWord << " | Row " << searchRow << ", " << "Column " << searchCol << endl;
					//wordList_caddToList(searchWord, searchRow, searchCol, 1); // Adds word to the list
					row = searchRow;
					col = searchCol;
					found = true;
					continue;
				}
				if (upFound) { // Prints the word, row, col, and adds to list
					cout << "What's Up? " << searchWord << " is!" << endl;
					cout << searchWord << " | Row " << searchRow << ", " << "Column " << searchCol << endl;
					//wordList_c::addToList(searchWord, searchRow, searchCol, 1); // Adds word to the list
					row = searchRow;
					col = searchCol;
					found = true;
					continue;
                                }
				if (downFound) { // Prints the word, row, col, and adds to list
					cout << "Yell timber because it's going down. " << endl;
					cout << searchWord << " | Row " << searchRow << ", " << "Column " << searchCol << endl;
					//wordList_c::addToList(searchWord, searchRow, searchCol, 1); // Adds word to the list
					row = searchRow;
					col = searchCol;
					found = true;
					continue;
                                }
                        }
			if (found == true) {
				break;
			}
                }
		if (found == true) {
			break;
		}
        }
	return found;
}

bool searchUp (char (&charArray)[SIZE][SIZE], int row, int col, string searchWord, int size) {
        bool found = false;
        int i = row;
        int strIndex = 1; // For going to next element of string array
        i--; // Indexes to one row above the current letter
       	while (searchWord[strIndex] == charArray[i][col]) {
       	        i--;
       	        strIndex++;
       	        if (strIndex == size) {
       	                found = true;
               	        break;
		}
	}
        return found;
}

bool searchDown (char (&charArray)[SIZE][SIZE], int row, int col, string searchWord, int size) {
        bool found = false;
        int i = row; // Stays on the same column as first letter
        int strIndex = 1; // For going to next element of string array
        i++;
       	while (searchWord[strIndex] == charArray[i][col]) {
		i++;
               	strIndex++;
               	if (strIndex == size) {
			found = true;
                        break;
                }
        }
        return found;
}

bool searchLeft (char (&charArray)[SIZE][SIZE], int row, int col, string searchWord, int size) {
        bool found = false;
        int strIndex = 1; // For going to next element of string array
        int j = col; // Fixes row, but traverses column to left
        j--;
      	while (searchWord[strIndex] == charArray[row][j]) {
      	        j--;
       	        strIndex++;
       	        if (strIndex == size) {
       	                found = true;
       	                break;
       	        }
       	}
        return found;
}

bool searchRight (char (&charArray)[SIZE][SIZE], int row, int col, string searchWord, int size) {
        bool ifound = false;
        int j = col; // Picks up where previous letter left off, initalised as first letter
        int strIndex = 1; // For going to next element of string array, must initialise to 0 to begin from first letter
        j++;
       	while (searchWord[strIndex] == charArray[row][j]) {
		j++;
		strIndex++;
		if (strIndex == size) {
			ifound = true;
			break;
		}
	}
        return ifound;
}
/*
bool searchList (string wordFound) { // Searches list to find whether or not word has been searched
	wordList_s *searchTemp; // Searches list from HEAD to TAIL
	wordList_s *searchTempRev; // Searches list from TAIL to HEAD
	bool found = false;
	for (searchTemp = HEAD, searchTempRev = TAIL; searchTemp != NULL, searchTempRev != NULL; searchTemp = searchTemp->next, searchTempRev = searchTempRev->prev) {
		if (wordFound == searchTemp->word) { // Checks if word is within list
			cout << wordFound << " found at " << searchTemp->wordRow << " , " << searchTemp->wordCol << endl;
			found = true;
			break;
		}
		if (wordFound == searchTempRev->word) {
			cout << wordFound << " fount at " << searchTempRev->wordRow << " , " << searchTempRev->wordCol << endl;
			found = true;
			break;
		}
	}
	return found;
}*/
/*
void addToList (string addWord, int addRow, int addCol, bool ifound) {
	if (!HEAD) { // Populate the list if it is empty
		wordList *addTemp = new wordList; // Create a node and store the corresponding elements into it.
		addTemp->word = addWord;
		addTemp->wordRow = addRow;
		addTemp->wordCol = addCol;
		addTemp->found = ifound;
		addTemp->next = NULL; // Set next pointer to GND
		addTemp->prev = NULL; // Set previous pointer to GND for first node of list
	}
	wordList *addTemp = new wordList;
	addTemp->word = addWord;
	addTemp->wordRow = addRow;
	addTemp->wordCol = addCol;
	addTemp->found = ifound;
	addTemp->next = HEAD;
	addTemp->prev = NULL;
	TAIL = addTemp->prev;
	HEAD = addTemp;
	return;
}*/
/*
void exportList () {
	ofstream wordExport;
	wordExport.open ("List_of_Words.txt");
	wordList *exportTemp = new wordList;
	wordExport << "Word | Row | Column | Found" << endl;
	for (exportTemp = HEAD; exportTemp != NULL; exportTemp = exportTemp->next) {
		wordExport << exportTemp->word << " " << exportTemp->wordRow << " , " << exportTemp->wordCol << exportTemp->found << endl;
	}
	wordExport.close ();
	return;
}*/
/*
void printList () { // Prints all elements of list
        wordList *temp = new wordList;
	if (!HEAD) {
		cout << "List is empty. Please search for words." << endl;
		return;
	}
	cout << "Word | Row | Column | Found" << endl;
        for (temp = HEAD; temp != NULL; temp = temp->next) {
                cout << temp->word << " " << temp->wordRow << " " << temp->wordCol << " " << temp->found << endl;
        }
	return;
}*/

#endif //GRIDSEARCH_H
