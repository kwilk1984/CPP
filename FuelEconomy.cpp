/*==============================================================
Program:  Fuel Economy
Version:  0.2.1
Version Date:  02/13/2021
Author:  Kevin Wilkins
Date:  07/10/2012
Contributor(s):  
Parameters:
A program that computes fuel economy and outputs results in both miles per 
gallon and kilometers per liter.  The program also grabs user data regarding
the year, make, and model of their vehicle and stores it as a string
variable.

The program itself uses 3 functions called from the main() function:
	1) TitleSeq: displays the title of the program
	2) QuitProgram: Allows the user to exit the program

In the switch the program will call 2 functions relating to the choice of:
	1) SI units
	2) Imperial units

These units are displayed on the menu as International and American units.

The program runs as a console application.
==============================================================*/

/*==============================================================
Preprocessor Directives
==============================================================*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

/*==============================================================
Function Prototypes
==============================================================*/
void TitleSeq();
void QuitProgram();
void menu();
void unitsSI();
void ImperialUnits();

/*==============================================================
Main function
==============================================================*/

int main()
{
    /* Clear the terminal prior to main title sequence */
	system("clear");
	
	/* Set decimal precision to 3
	Doing this results in 3 decimal points and adds more
	accuracy */
    cout << fixed << setprecision(3);
	
	/*Call the title sequence function which will run the main
	title of the program */
	TitleSeq();
	
	/* After calling the main title the menu is then called up
	so the end user can make their selection of measurement */
    menu();
		    
    /* End the program */
	cout << "Closing application . . ." << endl;
	cin.get();
    return 0;
}

/*==============================================================
Program Title Sequence
==============================================================*/
void TitleSeq()
{
    //Program Title    
    cout << "*********************************\n" 
    	 << "*********************************\n"
    	 << "*********************************\n"
    	 << "**** Fuel Economy Calculator ****\n" 
    	 << "*********************************\n"
		 << "*********************************\n" 
    	 << "*********************************\n"
         << endl << endl;
	
	cout << "Press 'ENTER' to begin\n";
	cin.get();
 	system("clear");
}

/*==============================================================
Program Quit
==============================================================*/
void QuitProgram()
{
    //Variable declaration
    char answer;
    
    //Asks user if they would like to quit the program
    cout << "Please enter y (yes) or n (no)\n"
         << "Would you like to quit?  ";
    cin >> answer;
    
    /* If the user confirms that they are ready to exit then
	the program will proceed to closing by returning to main()
	and terminating */
    if(answer == 'y') return;

	/* If user chooses they do not want to exit then they will
	be sent back to the main menu */
    else if(answer == 'n')
    {
        system("clear");
		menu();
    }
}

/*==============================================================
Menu
==============================================================*/
void menu()
{
	/* We need the option variable to receive input from the user
	with what measurements they want to use */
    int option = 0;
	
	//Loop
	do
	{
		//Menu Options
		cout << "******************\n" 
		     << "   Main Menu\n" 
			 << "******************" 
			 << endl << endl;
		cout << "1.  Use International Units\n" 
			 << "2.  Use American Units\n" 
			 << "3.  Exit\n\n" 
			 << "Enter your selection:  ";
		cin >> option;
	
		//Switch
		switch(option)
		{
		    // When the user chooses to use SI units
			case 1: system("clear");
				unitsSI();
				break;
            
   		     // When the user chooses to use Imperial units
			case 2: system("clear");
				ImperialUnits();
				break;
	
			// When the user wants to quit the program
	 	   case 3: QuitProgram();
	  		  	break;
            
       		 // Error message
     	   default: system("clear");
				cout << "Invalid choice.  Please try again . . ." 
					 << endl << endl;
				break;
		}
	}while(option != abs(3));
}

/*==============================================================
SI Units
==============================================================*/
void unitsSI()
{
	/* International System units */
	double liters = 0;
	double kilometers = 0;
	string year, make, model;
	
	// Get vehicle information, trip distance, and fuel used
	cout << endl << endl;
	cout << "- You are using International Units -\n\n";
	cout << "What is your vehicle Year/Make/Model?\n";
	cout << ">>  Year:  ";
	cin >> year;
	cout << ">>  Make:  ";
	cin >> make;
	cout << ">> Model:  ";
	cin >> model;
	cout << endl << endl;
	
	cout << ">> Trip:  ";
	cin >> kilometers;
	cout << ">> Fuel:  ";
	cin >> liters;
	cout << endl << endl;
	
	// Output report to console
	cout << "              :: Fuel Economy Report :: \n"
		 << "        Vehicle:  " << year << " " << make << " " << model << endl;
    cout << "Fuel Efficiency:  " << kilometers / liters 
    	 << " km/L\n\n" << endl;
	
 	/* Wait for input from the user and then clear the console and
	 return to the main menu */
	cin.ignore();
	cout << "Press 'ENTER' to continue\n";
	cin.get();
 	system("clear");
 	menu();
}

/*==============================================================
Imperial Units
==============================================================*/
void ImperialUnits()
{
	/* Imperial - or American - units */
	double miles = 0;
	double gallons = 0;
	string year, make, model;
	
	// Get vehicle information, trip distance, and fuel used
	cout << endl << endl;
	cout << "- You are using American Units -\n\n";
	cout << "What is your vehicle Year/Make/Model?\n";
	cout << ">>  Year:  ";
	cin >> year;
	cout << ">>  Make:  ";
	cin >> make;
	cout << ">> Model:  ";
	cin >> model;
	cout << endl << endl;
	
	cout << ">> Trip:  ";
	cin >> miles;
	cout << ">> Fuel:  ";
	cin >> gallons;
	cout << endl << endl;
	
	// Output report to console
	cout << "              :: Fuel Economy Report :: \n"
		 << "        Vehicle:  " << year << " " << make << " " << model << endl;
    cout << "Fuel Efficiency:  " << miles / gallons 
    	 << " MPG\n\n" << endl;
 	
 	/* Wait for input from the user and then clear the console and
	 return to the main menu */
	cin.ignore();
	cout << "Press 'ENTER' to continue\n";
	cin.get();
 	system("clear");
 	menu();
}
