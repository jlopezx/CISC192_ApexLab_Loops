/* File: apex_code.cpp
 * Project: Apex Lab 4 - Loops
 * Class: CISC 192 - C++
 * Professor: Alex Chow
 * Written by: Joshua Lopez
 * Description: This code defines 4 functions:
 *
 * void email_concat(stringstream& cin, stringstream& cout):
 * -Takes a string of email addresses and an END statement and replaces the spaces with a colon (:).
 *
 * void donation_total(stringstream &cin, stringstream &cout)
 * -Prompts the user for any amount of donations, adds them up and returns the total. If if reaches more
 *  than $100, it will send them two t-shirts.
 *
 * void average_books_checked_out(std::stringstream &cin, std::stringstream &cout)
 * -Adds the total amount of books checked out monthly, displays the average and lets the user know
 *  if hours needed to be extended.
 *
 * void rectangles(std::stringstream &cin, std::stringstream &cout)
 * -Prompts the user for a character, and the grid size (column x rows). Then it prints the grid with the
 *  character they chose.
 *
 * */
#include <iostream>
#include <string>
#include <iomanip>
#include "apex_code.h"

using namespace std;

const int STARTING_VALUE = 0; // Using this const to avoid using magic numbers. 0 is where my for-loop
								  // variables are going to start.

void email_concat(stringstream& cin, stringstream& cout)
{
	string userInput;			// Used to hold our user's input
	string finalOutput = "";	// Used to hold our final message. Initalized to ensure it's an empty string
	int isEnd;					// Holds our index for when END is found.

	// Takes the user input and stores it to userInput.
	getline(cin, userInput);

	// This if statement is more because there is a potential for an infinite loop if "END" isn't
	// added to the string input. I know for this lab it doesn't matter, but I want to practice following
	// good practice.
	if (userInput.find("END") == std::string::npos) {
		cout << "Need to provide END in your input" << endl;

	} else {
		// In in this branch, we have an "END" in our string. Here we will find the END's index and store it
		// to isEnd which whill hold our index to knwo if we reached the end.
		isEnd = userInput.find("END");
		// Easily could of been a different loop, but since we know how many times we need to loop a FOR
		// loop is the most appropriate.
		for (int i = STARTING_VALUE; i < isEnd; ++i) {
			// If looks for spaces to replace them with colons. We use the replace function to replace the
			// space. This function is given to us by the developers of C++ under the <string> file.
			if (userInput[i] == ' ') {
				// .replace() method takes in the index of where to start replacement, the number of
				// characters to replace, and the string to replace it with.
				userInput.replace(i, 1, ":");
			}
			// Inside the foor loop, we append each character to the finalOutput string to build our final
			// output.
			finalOutput += userInput[i];
		}
		// Simply prints out our appended string with the new colons (:).
		cout << finalOutput;
	}
}

void donation_total(stringstream &cin, stringstream &cout) {
	const int T_SHIRT_PROMO = 100; // THe amount needed to send a t-shirt to the donators.
	const int MININUM_VALUE = 0;   // Used to hold the minimum value before we go into negative numbers
								   // which in this case is 0.

	double donated = 0;			   // Holds the current donated amount. Initialized to ensure it's 0.
	double totalDonated = 0;	   // Adds the total donated amount. Initialized to ensure its truly 0.

	// We do not know how many donations are made so we use a do-while loop and check if the donated amount
	// is not negative. This loop ensures we at least run the loop code one time.
	do {
		// Adding donated to totalDonated. It's before the cin because we do not want to add the negative
		// input.
		totalDonated += donated;
		cin >> donated;

	} while (donated >= MININUM_VALUE);

	// If donations are more than $100, we send a t-shirt, twice.
	if (totalDonated > T_SHIRT_PROMO) {
		cout << "Send a t-shirt" << endl << "Send a t-shirt" << endl;
	}
	// Print total donations with fixed to neverr display scientific notation, and precision of 2 for x.xx
	// format.
	cout << "Total donations made $" << fixed << setprecision(2) << totalDonated;
}

void average_books_checked_out(std::stringstream &cin, std::stringstream &cout)
{
	const int monthsInYear = 12;
	const int monthlyThreshold = 1268;
	const int averageMonthlyLimit = 2500;

	int booksChecked; 			// Hold the number of books checked out by each user.
	int totalBooksChecked = 0; 	// Holds the total number of books checked out.
	int monthlyBooksAverage;	// This isn't needed but provided better code readability. Used to hold
								// average of books checked out monthly.
	int count = 0;				// Count variable to know how many times we've iterated.
	bool overThreshold = true;	// This checks if every month had more than 1268. Initialized to true, but
								// Will be set to false if any input is NOT over 1268.

	// A for loop would have been more appropriate, but I decided to use a while to keep in the spirit
	// of using different loop structures. This loop will take 12 inputs from the user and add them
	// together.
	while(count < monthsInYear) {
		// Puts the monthly checked out books into booksChecks. It will read these month-by-month for the
		// entire year.
		cin >> booksChecked;

		// Adds all the books checked out to totalBooksChecked.
		totalBooksChecked += booksChecked;

		// Checks if inputs are over 1268, if any are over 1268, then overThreshold will be false regardless
		// if the rest of the inputs are over 1268.
		overThreshold = overThreshold && (booksChecked > monthlyThreshold);

		// Pre-increments count. Used over post-increment as its more efficient. (Avoids using the temporary
		// copy).
		++count;
	}

	// Caculates average of books checked out each month and stores the result to booksAverage.
	monthlyBooksAverage = totalBooksChecked / monthsInYear;

	cout << "Average monthly circulation: " << monthlyBooksAverage << " books" << endl;
	if (overThreshold && monthlyBooksAverage > averageMonthlyLimit) {
		cout << "Extend hours!!";
	}


}

void rectangles(std::stringstream &cin, std::stringstream &cout)
{
	// Variables for user inputs.
    char charInput;
    int userColumns;
    int userRows;

    // Prompts the user for speciifc inputs
    cin >> userColumns;		// Gets the columns input for the grid.
    cin >> userRows;		// Gets the rows input for the grid.
    cin >> charInput;		// Gets the character the user wants printed to form the grid.

    // Nested for loops. Using typical i j variables for the loop bodies. Outer loops is rows and inner
    // loop is columns because of the direction things are printed. Columns are printed first, then
    // we move to the next row with an endl.
    for (int i = STARTING_VALUE; i < userRows; ++i) {
    	for (int j = STARTING_VALUE; j < userColumns; ++j) {
    		cout << charInput << " ";
    	}
    	// This endl moves to the next row.
    	cout << endl;
    }
}
