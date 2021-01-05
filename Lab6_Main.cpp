#include <iostream>
#include <fstream>
#include <string>
#include "Lab6_Function.h" // #Includes all functions for searching grid and list
#include "Lab6_Class.h" // #Includes the class that stores the functions and attributes

using namespace std;

int main() {
	int exitStat = 0;
	int notAgain = 0; // DO NOT TINKER
	wordList_c *listArray[4]; // Creates an array to store each of the grids as objects

	for(int i = 0; i < 4; i++) { // Traverse each of the lists
		char charArray2[SIZE][SIZE];  // max size, but may not be full for each grid
		string fileName;
		int size;

		cout << "Enter a file name (or Exit to exit) (Please don't type it incorrectly): ";
		cin >> fileName;
		// If the user types Exit rather than a filename, quit everything but save list
                if(fileName == "Exit") {exitStat = 1; break;}
		cout << "and the size: ";
		cin >> size;

		wordList_c *ptr = new wordList_c(charArray2, size, fileName);
		listArray[i] = ptr;
		gridFill(charArray2, size, fileName);
		gridPrint(charArray2, size); // Prints the first grid

		// Saves list(s) and clears memory
		if (exitStat) {ptr->exportList(); ptr->deleteList(); break;}
		notAgain++; // SERIOUSLY DO NOT TINKER

		string searchWord; // Index string and search for corresponding characters
		do {
			cout << "What word (type * to start a new list)? ";
			cin >> searchWord;

			// if done with that grid (the * input), print the entries for that list
                        if (searchWord == "*") {
                                cout << "The list looks like this so far: " << endl;
                                ptr->printList();
				break;
			}

			// search for words in the list; if found, don't need to search again
                        bool inList = ptr->searchList (searchWord);
                        if (inList == false) {
                             	cout << searchWord << " is not in the list but I've added it." << endl;
			}
			else {
				continue;
			}

			// search for words in the grid and add them to the list
			bool validSearch = searchValid (charArray2, searchWord, size);
                        if (validSearch == false) {
                        	cout << "Sorry bud, " << searchWord << " isn't in the grid." << endl;
                        	ptr->addToList(searchWord, -1, -1, 0); // List of words that are not found
                        }
			else {
				ptr->addToList(searchWord, row, col, 1);
			}

		} while(searchWord != "*");
	} // For loop close

	for (int i = 0; i < notAgain; i++) {delete listArray[i];} // The biggest enemy

	wordExport.close();

	return 0;
}
