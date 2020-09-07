//==============================================================
//Fuel Economy Program
//Kevin Wilkins
//July 10, 2012
//==============================================================

/*
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
*/

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
void unitsSI();
void ImperialUnits();

/*==============================================================
Main function
==============================================================*/

int main()
{
    //Variable declaration--------------------------------------
    double miles, kilometers;
    double gallons, liters;
    string vehicle, year, make, model;
	int option = 0;
	
    //Set decimal precision-------------------------------------
    cout << fixed << setprecision(3);
	
	//Program title function call-------------------------------
	TitleSeq();
	
	//Loop------------------------------------------------------
    do
    {
		//Menu--------------------------------------------------
		cout << "******************\n" 
		     << "   Main Menu\n" 
			 << "******************" 
			 << endl << endl;
		cout << "1.  Use International Units\n" 
			 << "2.  Use American Units\n" 
			 << "3.  Exit\n\n" 
			 << "Enter your selection:  ";
		cin >> option;
		
		//Switch------------------------------------------------
	    switch(option)
	    {
		    // When the user chooses to use SI units
			case 1: void unitsSI()
    	         break;
  	         
            // When the user chooses to use Imperial units
			case 2: void ImperialUnits()
			 	 break;
			
			// When the user wants to quit the program
	 	    case 3: QuitProgram();
                 break;
            
            // Error message
            default: cout << "Invalid choice.  Please try again . . ." 
						  << endl << endl;
      		     break;
		}
    }while(option != abs(3));
	    
    //Program termination
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
         << "A program by Kevin Wilkins" << endl << endl;
	
	cout << "Press 'ENTER' to continue\n";
	cin.get();
	cout << endl;
}

/*==============================================================
Program Quit
==============================================================*/
void QuitProgram()
{
    //Variable declaration
    char answer;
    
    //Asks user if they would like to quit the program
    cout << "Please enter Y (yes) or N (no)\n"
         << "Would you like to quit? ";
    cin >> answer;
    
    //If statements take user input and then output accordingly
    if(answer == 'Y' || answer == 'y')
    {
        cout << "Closing application . . ." << endl;
		cout << "Press 'ENTER' to close." << endl;
		cin.get();		
    }
    else if(answer == 'N' || answer == 'n')
    {
        main();
    }
}

/*==============================================================
SI Units
==============================================================*/
void unitsSI()
{
	// Get vehicle information, trip distance, and fuel used
	cout << endl << endl;
	cout << "- You are using International Units -\n\n";
	cout << "What is your vehicle Year/Make/Model?\n";
	cout << "Year:  ";
	cin >> year;
	cout << "Make:  ";
	cin >> make;
	cout << "Model:  ";
	cin >> model;
	cout << endl << endl;
	
	cout << "Enter your trip distance:  ";
	cin >> kilometers;
	cout << "Enter your fuel amount:  ";
	cin >> liters;
	cout << endl << endl;
	
	// Output report to console
	cout << "Fuel Economy Report for: " 
		 << year 
		 << " " 
		 << make 
		 << " " 
		 << model << endl;
    cout << "Your fuel economy is:  " << kilometers / liters 
    	 << " km/L\n\n" << endl;
 	
 	cout << "Press 'ENTER' to continue\n";
	cin.get();
 	cout << endl << endl;
}

/*==============================================================
Imperial Units
==============================================================*/
void ImperialUnits()
{
	// Get vehicle information, trip distance, and fuel used
	cout << endl << endl;
	cout << "- You are using American Units -\n\n";
	cout << "What is your vehicle Year/Make/Model?\n";
	cout << "Year:  ";
	cin >> year;
	cout << "Make:  ";
	cin >> make;
	cout << "Model:  ";
	cin >> model;
	cout << endl << endl;
	
	cout << "Enter your trip distance:  ";
	cin >> miles;
	cout << "Enter your fuel amount:  ";
	cin >> gallons;
	cout << endl << endl;
	
	// Output report to console
	cout << "Fuel Economy Report for: " 
		 << year 
		 << " " 
		 << make 
		 << " " 
		 << model << endl;
    cout << "Your fuel economy is:  " 
		 << miles / gallons 
    	 << " miles/gallon\n\n" << endl;
 	
 	cout << "Press 'ENTER' to continue\n";
	cin.get();
 	cout << endl << endl;
}
