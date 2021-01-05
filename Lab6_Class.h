#ifndef CLASSLIST_H
#define CLASSLIST_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream wordExport("List_of_Words.txt");

// List //
struct wordList_s {
        string word;
        int wordRow;
        int wordCol;
        bool found;

        wordList_s *next;
        wordList_s *prev;

};

// Class //
class wordList_c {

	private:
		wordList_s *HEAD;
		wordList_s *TAIL;
		char charArray[SIZE][SIZE]; // Grid moved from main() into Class
		string fileName;

	public:
		// constructor to set grid, filename, and size
		wordList_c(char charArray[SIZE][SIZE], int size, string fileName) {
			HEAD = NULL;
		}
		~wordList_c() { // The destructor to delete and exit program
			exportList(); // Exports the list of words searched for by the user, will overwrite filename
			deleteList(); // Function to delete objects and lists
			cout << "Deallocated Memory" << endl;
		}

		// If the word was previously searched for, print the results of that search, and return a 1 so the main doesn't re-search the grid
		bool searchList (string wordFound) { // Searches list to find whether or not word has been searched
			wordList_s *searchTemp; // Searches list from HEAD to TAIL
			wordList_s *searchTempRev; // Searches list from TAIL to HEAD
		        bool found = false;
			// Checks if word is within list
        		for (searchTemp = HEAD; searchTemp != NULL; searchTemp = searchTemp->next) {
				if (searchTemp->word == wordFound) {
        	                	cout << wordFound << " already found at " << searchTemp->wordRow << "," << searchTemp->wordCol << endl;
        	                	found = true;
        	                	break;
        	        	}
		        }
		        return found;
		}


		// Print all words that have been searched for in the grid
		void printList () { // Prints all elements of list
		        wordList_s *temp = new wordList_s;
		        if (!HEAD) {
	        	        cout << "List is empty. Please search for words." << endl;
	                	return;
	        	}
	        	cout << "Word | Row | Column | Found" << endl;
	        	for (temp = HEAD; temp != NULL; temp = temp->next) {
	        	        cout << temp->word << " " << temp->wordRow << " " << temp->wordCol << " " << temp->found << endl;
	        	}
	        	return;
		}

		// Delete all entries to ensure no orphans or memory leaks upon program exit
		void deleteList () {
			wordList_s *del;
			wordList_s *delTemp;
			del = HEAD;
			while (del != NULL) {
				delTemp = del->next;
				delete del;
				del = delTemp;
			}
			return;
		}

                // Before quitting the program, save all entry information to a file for further analysis (and submission as proof)
		void exportList () {
		        wordList_s *exportTemp;
        		wordExport << "Word | Row | Column | Found" << endl;
		        for (exportTemp = HEAD; exportTemp != NULL; exportTemp = exportTemp->next) {
		                wordExport << exportTemp->word << " " << exportTemp->wordRow << " , " << exportTemp->wordCol << " " << exportTemp->found << endl;
		        }
		        //return;
		}

		// A new word was searched for in the grid and was found or not
		// Now add that word to the list
		// Remember it is a doubly linked list
		void addToList (string addWord, int addRow, int addCol, bool ifound) {
        		if (!HEAD) { // Populate the list if it is empty
                		wordList_s *addTemp = new wordList_s; // Create a node and store the corresponding elements into it.
                		addTemp->word = addWord;
                		addTemp->wordRow = addRow;
                		addTemp->wordCol = addCol;
                		addTemp->found = ifound;
                		addTemp->next = NULL; // Set next pointer to GND
                		addTemp->prev = NULL; // Set previous pointer to GND for first node of list
        		}
        		wordList_s *addTemp = new wordList_s;
        		addTemp->word = addWord;
        		addTemp->wordRow = addRow;
        		addTemp->wordCol = addCol;
        		addTemp->found = ifound;
        		addTemp->next = HEAD;
        		addTemp->prev = NULL;
        		TAIL = addTemp->prev;
        		HEAD = addTemp;
			return;
		}

};
#endif
