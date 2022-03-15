// L2-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

//Function Prototype
void letterToDigitConverter(int alphabetL);
void ExitMessage();

int main()
{
	int digit,
		alphabetLetter,
		chASCIInum;
	char ch;
	char decision;
	char repeat = 'y';

	cout << "Enter a Y/y to convert a telephone number" 
		 << "from letters to digits." 
		 << endl
		 << "Enter any other letter to terminate the program. " 
		 << endl;

	cin.get(decision);									//User Decides if they want to start the program.

	if (decision == 'y' || decision == 'Y')											
	{
		while (repeat == 'y' || repeat == 'Y')						//While repeat is set to y, it will continue to run.
		{
			cout << endl
				<< "Enter a telephone number using 7 or more letters" 
				<< endl
				<< "for Prefix and number, only the first 7 letters are used" 
				<< endl
				<< "and dashes '-' are ZEROES. underscores '_' are ONES"
				<< endl
				<< "ALL OTHER SYMBOLS ARE ignored." 
				<< endl
				<< "-->:";

			cin.ignore(100, '\n');							//Clearing the buffer in case of extra characters.
			cin.get(ch);								//Get letters from user. 

			cout << endl;
			cout << "The corresponding telephone number is : ";


			for (int i = 0; i <= 6; i++)						//Run loop that will run for the first 7 letters
			{

				chASCIInum = static_cast<int>(ch);				//Get the ASCII index number of ch. 
				if (i == 3)							//If i == 3 then add a '-'
				{
					cout << "-";
				}

				if (chASCIInum >= '0' && chASCIInum <= '9')			//if chASCII number ends up being between the ASCII range of numbers,
				{								//then report error and exit. 
					cout << endl 
						 << "Number Input Found." 
						 << "Terminating Program." 
						 << endl;
					ExitMessage();
				}

				switch (ch)							//To capture empty or not enough numbers. 
				{
				case ' ':
				case '\n':
				case '\t':
					cout << endl 
						 << "Error, not enough numbers." 
						 << "Terminating Program.";
					ExitMessage();
					break;
				}
				if (ch == '-')							//Converting '-' to 0 and underscore '1'
				{
					digit = 0;
					cout << digit;
					cin.get(ch);
					continue;
				}																            
				if (ch == '_')
				{
					digit = 1;
					cout << digit;
					cin.get(ch);
					continue;
				}


				if (chASCIInum >= static_cast<int>('A')				//if chASCII numbers are within range then,
					&& chASCIInum <= static_cast<int>('Z'))			
				{
					alphabetLetter = chASCIInum - static_cast<int>('A');	//then subtract chASCII num from 'A' to get alphabet letter position.
					letterToDigitConverter(alphabetLetter);			//See function for details 
				}

				else if (chASCIInum >= static_cast<int>('a')			//if chASCII numbers are within range then,
					&& chASCIInum <= static_cast<int>('z'))   
				{
					alphabetLetter = chASCIInum - static_cast<int>('a');	//then subtract chASCII num from 'A' to get alphabet letter position.
					letterToDigitConverter(alphabetLetter);			//See function for details 
				}
				else
				{
					cout << endl << "Invalid Entry found." 
						 << "Terminating Program.";			//Capture any conditions that don't apply.
					ExitMessage();
				}



				cin.get(ch);							//Get next letter. 
			}


			cout << endl 
				 << endl
				 << "To process another phone number, enter Y/y" << endl
				 << "Enter any other letter to terminate the program." 
				 << endl;

			cin.ignore(100, '\n');							//Clearing the buffer to avoid extra characters in the buffer.
			cin.get(repeat);							//Get decision to repeat.
		}
	}

	else
	{
		cout << "Exiting Program.";
		ExitMessage();									//see function for details.
		return 0;
	}

	cout << "Exiting Program.";
	ExitMessage();
	return 0;

}


void letterToDigitConverter(int alphabetL)							//Conversion from Letters to Digits corresponding to telephone number pads, 
{												//by using the alphabet letter position and then calculating it into 
	if (0 <= alphabetL && alphabetL < 26)							//phone digits to represent numbers on phone keypad. 
	{
		int digit;
		digit = (alphabetL / 3) + 2;

		if (((alphabetL / 3 == 6) || (alphabetL / 3 == 7)) 
			&& (alphabetL % 3 == 0))
			digit = digit - 1;
		if (digit > 9)
			digit = 9;

		cout << digit;
	}
}

void ExitMessage()										//Exit message and exits the program.
{
	char q;
	cout << "\nPress any key to Exit.";
	cin.clear();										//Clears the cin failure state to make sure exit pauses properly.
	cin.ignore(100, '\n');															
	cin.get(q);

	exit(EXIT_FAILURE);
}
