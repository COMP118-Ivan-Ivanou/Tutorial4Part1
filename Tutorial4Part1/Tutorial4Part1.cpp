/** \file		Lab_4
*   \brief		Program which creates a menu where user can select which function to call
*   \details		Program which creates a menu via do while loop
*				where user can select which function to call.
*				Also there is a functions like shapeLen & shape...
*				which we cannot call from the menu.
*				After 4th lecture there was an update: added cassert library
*				and assert(); method to make pre and post check of in/output.
*				Also added function calAreaOfCircle(); to check/use assert(); function
*				and <cassert> library
*   \author		Ivan Ivanou
*   \version		0.2
*   \date		02.16.2022(mm.dd.yyyy)
*   \copyright	GNU Public License
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Shapes.h"

using namespace std;

const int MAX_ARRAY = 10;
const int PI = 3.14;

void drawAhorizontalLine(const int numb, const char ch);
void drawAverticalLine(const int numb1, const char ch);
void drawAsquare(const int numb2);
void draw_rectangle(const int numb3, const int numb4);
void shapeLen(int randArray[MAX_ARRAY]);
void shapeTy(int randArray1[MAX_ARRAY]);
void shapeCh(char randArray2[MAX_ARRAY]);

int main() {

	srand(time(NULL));

	int randArray[MAX_ARRAY], num1 = 0, num2, num3, num4, num5, num6;

	cout << "Welcome there!" << endl;
	//creating do while loop to do the project till user enters 5
	do {
		cout << "\nSelect the input" << endl;
		cout << "1. Draw a horizontal line:" << endl;
		cout << "2. Draw a vertical line:" << endl;
		cout << "3. Draw a square:" << endl;
		cout << "4. Draw a rectangle:" << endl;
		cout << "5. Quit" << endl;

		cin >> num1;
		//switching the input
		switch (num1) {
		case 1:
			cout << "Enter the number of stars:";
			cin >> num2;
			drawAhorizontalLine(num2, '*');
			break;

		case 2:
			cout << "Enter the number of stars:";
			cin >> num3;
			drawAverticalLine(num3, '@');
			break;

		case 3:
			cout << "Enter parameter:";
			cin >> num4;
			drawAsquare(num4);
			break;

		case 4:
			cout << "Enter first parameter:" << endl;
			cin >> num5;
			cout << "Enter second parameter" << endl;
			cin >> num6;
			draw_rectangle(num5, num6);
			break;

		case 5:
			exit(1);
			break;
		}
	} while (num1 != 5);
}

/*
* Function draws a horizontal line
* @param numb to set a maximum value for the for loop
* @return a horizontal line
* returning in case that the number is > 0
*/
void drawAhorizontalLine(const int numb, const char ch) {
	//check if the number acceptable
	if (numb > 0) {
		//creating a loop which take numb1 as a parameter of amount of *
		for (int i = 0; i < numb; i++) {
			cout << ch;
		}
	}
}

/*
* Function draws a vertical line
* @param numb1 to set a maximum value for the for loop
* @return a vertical line
* returning in case that the number is > 0
*/
void drawAverticalLine(const int numb1, const char ch) {
	if (numb1 > 0) {
		//creating a loop which take numb1 as a parameter of amount of *
		for (int i = 0; i < numb1; i++) {
			cout << ch + "\n";
		}
	}
}

/*
* Function draws a square
* @param numb2 to set a maximum value for the for loops to draw
* a top wall of square
* @return a square
* returning in case that the number is > 0
*/
void drawAsquare(const int numb2) {
	if (numb2 > 0) {
		//draw the top wall
		for (int column = 0; column < numb2; ++column)
		{
			cout << "$";
		}

		cout << "\n";
		//draw the sides.
		for (int row = 0; row < numb2; ++row)
		{
			cout << "$";
			//second wall
			for (int column = 0; column < numb2 - 2; ++column)
			{
				cout << " ";
			}
			cout << "$\n";
		}

		//draw bottom wall 
		for (int column = 0; column < numb2; ++column)
		{
			cout << "$";
		}
		//stop printing
		cout << "\n";
	}
}

/*
* Function draws a rectangle
* @param numb3 to set a maximum value for the for loops to
* set a height of rectangle
* @param numb4 to set a maximum value for the for loops to
* set a weight of rectangle
* @return a rectangle
* returning in case that the numbers is > 0
*/
void draw_rectangle(const int numb3, const int numb4) {
	if (numb3 > 0 && numb4 > 0) {
		//using for loop for the height
		for (int i = 0; i < numb3; i++) {

			//using for loop for the weight
			for (int y = 0; y < numb4; y++) {
				cout << "^ ";
			}

			cout << endl;
		}
	}
}

/*
* Function generates a random int array with numbers between 1 and 4
* @param randArray to store randomly generated numbers
* @return a array with random numbers
*/
void shapeTy(int randArray[MAX_ARRAY]) {
	//putting random numbers
	for (int i = 0; i < MAX_ARRAY; i++) {
		randArray[i] = rand() % 4 + 1;
	}
	//showing all the numbers
	for (int i = 0;i < MAX_ARRAY;i++) {
		cout << "Elements no " << i + 1 << ":" << randArray[i] << endl;
	}
}

/*
* Function generates a random int array with numbers between 1 and 20
* @param randArray1 to store randomly generated numbers
* @return a array with random numbers
*/
void shapeLen(int randArray1[MAX_ARRAY]) {
	//putting random numbers
	for (int i = 0; i < MAX_ARRAY; i++) {
		randArray1[i] = rand() % 20 + 1;
	}
	//showing all the numbers
	for (int i = 0;i < MAX_ARRAY;i++) {
		cout << "Elements no " << i + 1 << ":" << randArray1[i] << endl;
	}
	//showing the size of array
	cout << sizeof(randArray1);
}

/*
* Function generates a random char array with random chars from alphabers[] array
* @param randArray2 to store randomly generated chars
* @return a array with random chars
*/
void shapeCh(char randArray2[MAX_ARRAY]) {
	//creating array with letters
	char alphabets[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	//initializing the integer
	int i = 0;

	//setting the while loop
	while (i < MAX_ARRAY) {
		//generating letters between 0 and 25
		int temp = rand() % 26;

		//push result to array
		randArray2[i] = alphabets[temp];

		//continuing while loop
		i++;
	}

	//for loop to output the array
	for (i = 0; i < MAX_ARRAY; i++) {
		cout << randArray2[i];
	}
}

/*
* Function calculates the area of the circle
* @param const double parameter radius
* @return a result in a double format
* return if all assert(); functions are passed
*/
double calAreaOfCircle(const double radius) {
	//initializing new variable
	double res;

	//pre-condition test
	assert(radius > 0);

	//calsulating the result
	res = PI * pow(radius, 2.0);

	//post-condition test
	assert(res > 0);

	//returning the result
	return res;
}