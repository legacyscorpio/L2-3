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
		chASCII;
	char ch;
	char decision;
	char repeat = 'y';

	cout << "Enter a Y/y to convert a telephone number from letters to digits." << endl
		<< "Enter any other letter to terminate the program. " << endl;
	cin >> decision;

	if (decision == 'y' || decision == 'Y')
	{
		while (repeat == 'y' || repeat == 'Y')
		{
			cout << endl
				 << "Enter a telephone number using 7 or more letters" << endl
				 << "for Prefix and number, only the first 7 letters are used" << endl
				 << "and dashes '-' are ZEROES. underscores '_' are ONES" << endl
				 << "ALL OTHER SYMBOLS ARE ignored." << endl
				 << "-->:";

			cin.ignore(100, '\n');															//Clearing the buffer from trying to break the program.
			cin.get(ch);

			cout << endl;
			cout << "The corresponding telephone number is : ";


			for (int i = 0; i <= 6; i++)
			{

				chASCII = static_cast<int>(ch);
				if (i == 3)
				{
					cout << "-";
				}

				if (chASCII >= '0' && chASCII <= '9')
				{
					cout << endl << "Number Input Found. Terminating Program." << endl;
					ExitMessage();
				}

				switch (ch)																   //To capture empty or not enough numbers. 
				{
				case ' ':
				case '\n':
				case '\t':
					cout << endl << "Error, not enough numbers. Terminating Program.";
					ExitMessage();
					break;
				}
				if (ch == '-') 
				{
					digit = 0;
					cout << digit;
					cin.get(ch);
					continue;
				}																            //Converting '-' to 0 and underscore '1'
				if (ch == '_') 
				{
					digit = 1;
					cout << digit;
					cin.get(ch);
					continue;
				}
					

				if (chASCII >= static_cast<int>('A') && chASCII <= static_cast<int>('Z'))
				{
					alphabetLetter = chASCII - static_cast<int>('A');
					letterToDigitConverter(alphabetLetter);									// See function for details 
				}

				if (chASCII >= static_cast<int>('a') && chASCII <= static_cast<int>('z'))
				{
					alphabetLetter = chASCII - static_cast<int>('a');
					letterToDigitConverter(alphabetLetter);									// See function for details 
				}
				else
				{
					cout << endl << "Invalid Entry found. Terminating Program.";
					ExitMessage();
				}



				cin.get(ch);
			}

			
			cout << endl << endl
				<< "To process another phone number, enter Y/y" << endl
				<< "Enter any other letter to terminate the program." << endl;

			cin.ignore(100, '\n');															//Clearing the buffer.
			cin >> repeat;
		}
	}

	else
	{
		cout << "Exiting Program.";
		ExitMessage();																	  //see function for details.
		return 0;
	}

	cout << "Exiting Program.";
	ExitMessage();
	return 0;

}


void letterToDigitConverter(int alphabetL)												//Conversion from Letters to Digits corresponding to telephone number pads. 
{
	if (0 <= alphabetL && alphabetL < 26)
	{
		int digit;
		digit = (alphabetL / 3) + 2;

		if (((alphabetL / 3 == 6) || (alphabetL / 3 == 7)) && (alphabetL % 3 == 0))
			digit = digit - 1;
		if (digit > 9)
			digit = 9;

		cout << digit;
	}
}

void ExitMessage()																		// Exit message and exits the program.
{
	char q;
	cout << "\nPress any key to Exit.";
	cin.clear();																		// Clears the cin failure state to make sure exit pauses properly.
	cin.ignore(100, '\n');
	cin.get(q);

	exit(EXIT_FAILURE);
}

