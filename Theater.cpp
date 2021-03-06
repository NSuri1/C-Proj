#include <iostream>
#include <iomanip>
using namespace std;


//Variables by Nalin Suri
const int rows= 15;
const int cols= 30;
double seatPrices[rows];
bool availableSeats[rows][cols];


//Function Prototypes/Organizational Logic by Nick Perez

void enterSeatPrices();
//first function to be called, asks users for price of each row (using loop)
//Created by Nalin Suri

void menu();
//menu caller function to display menu and selection
//Created by Juan Herrera

void displaySeats(bool);
//display Seats will display the seats the user has purchased or not passed a multi dimensional array
//where true means the seat is sold and false means the seat is available
//	for(int count=0;count<rows; count++)
//	{
//		for(int count1=0; count1<cols; count1++)
//		{
//			if(availableSeats is false)
//				cout<<"#"; (Hashtag for seats available)
//			else
//				cout<<"*"; (Star for seats bought)
//		}}
//Created by Nalin Suri

void displaySeatPrices(double []);
//Displays prices by row
//Created by Juan Herrera

void confirm(bool);
//calls menu again if user presses enter after couting Press the Enter key to continue;
//Created by Nick Perez

void viewTicketSales(double prices[],bool seats[][cols]);


/*
goes through seats array and if it is true add its price by its row to an accumulator
example pseudocode:
for(){
	for(){
		if(seats[row][col]){
		total+=prices[row]
		}
	}
}
after call the main function immediately
Created by Nick Perez
*/

void purchaseTicket(bool (&seats)[rows][cols]);
/*asks user whether to view available seats or not 
if(y){displaySeats();confirm();} 
do{
flag=false;
	asks user for row to purchase
	asks user for seat num to purchase
	set that seat to be purchased
	ask user if they'd like to purchase another seat
	if(y){flag=true;} 
}while(flag);
//use a do loop with a nested while
//within nested loop you'll need another decision to check to see of seat is available
//cout << "\nPlease enter desired row number (1-" << ROWS << "): ";
//cout << "Row must be between 1 and " << ROWS << ". Please re-enter: ";
//cout << "\nPlease enter desired seat number (1-" << COLS << "): ";
//cout << "Seat must be between 1 and " << COLS << ". Please re-enter: ";
// if the seat is available
// mark the seat is taken
// add to patron's ticket total
// add to patron's $ total
 //cout << "\nPurchase confirmed\n";
 // otherwise seat has been sold
//cout << "\nSorry. That seat has been sold.\n";
//cout << "\nWould you like to purchase another seat (y/n)? ";
// Display a purchase summary for the patron
//cout << "\n\nYou have purchased a total of " << numTickets << " tickets " << "for a total price of $" << totPrice;
 // Add patron's purchases to theater total puchases
 
Function by Nalin Suri, psuedocode by Nick Perez
*/

int main(){

	//Functions Implemented by Nalin Suri
	enterSeatPrices();
	menu();
	

	system("PAUSE");
	return 0;
}



void menu() //Juan Herrera
{
int choice;
cout << "\n\n\n\t\tC++ Theatre" << endl << endl;
cout << "\n\t1. View Available Seats";
cout << "\n\t2. View Seating Prices";
cout << "\n\t3. View Ticket Sales";
cout << "\n\t4. Purchase a Ticket";
cout << "\n\t5. Exit the Program\n\n";
cout << "\n\tEnter your choice(1-5):  ";
cin>>choice;
bool booll;

do{
	booll=false;
switch(choice){
	case 1:
	displaySeats(true);
	break;
	case 2:
	displaySeatPrices(seatPrices);
	break;
	case 3:
	viewTicketSales(seatPrices, availableSeats);
	break;
	case 4:
	purchaseTicket(availableSeats);
	break;
	case 5:
	return;
	break;
	default:
	cout<<"Choice must be between 1 and 5. Please re-enter: ";
	cin>>choice;
	booll=true;
	break;
			}
} while(booll);}

void confirm(bool menuOrNah){
	cout<<"Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	if(menuOrNah){
		menu();
	}
}


void enterSeatPrices() //Nalin Suri
{
	for (int count=0;count<rows; count++)
	{
		cout<< "Please enter ticket price for Row "<< setw(2) << count+1<< ": ";
		cin>> seatPrices[count];
	}
	
}

void displaySeats(bool flag) //Nalin Suri
{
	cout << "\n\t\tSeats";
	cout << "\n\t123456789012345678901234567890" << endl;

	for(int r=0;r<rows; r++)
	{
		cout<< "\nRow "<<setw(2) << r+1<<"\t";
		
		for(int c=0; c<cols; c++)
		{
			if(availableSeats[r][c]==false)
			{
				cout<<"#";
			}
			else
			{
				cout<<"*";
			}
		}
	}
	cout << "\n\n\n\tLegend:\t* = Sold";
	cout << "\n\t\t# = Available\n\n\n";
	confirm(flag);
	
	
	
}

void displaySeatPrices(double price[]) //Juan Herrera
{
	cout<<"\nTicket Prices by Row \n\n";
	cout<<setw(8)<<"Row"<<setw(10)<<"Price\n";
	cout<<setw(8)<<"---"<<setw(10)<<"-----\n";
	for(int i=0;i<15;i++){
		 cout<<fixed<<setw(7)<<right<<i+1<<fixed<<setw(10)<<setprecision(2)<<price[i]<<endl;
	}
	cout<< endl<<endl<<endl;
confirm(true);
}

void viewTicketSales(double prices[],bool seats[][cols]){
	int r;
	double total=0.0;
	
	
	for(r=0;r<rows;r++){
		for(int c=0;c<cols;c++){
		if(seats[r][c]){
		total+=prices[r];
		}
	}
 }
 cout<<"\n\nTotal Sales to Date:  $"<<fixed<< setprecision(2)<<total<<endl;
 
 menu();
}

void purchaseTicket(bool (&seats)[rows][cols]) //Created by Nalin Suri
{
	char choice=' ';
	char again=' ';
	int rowChoice=0;
	int colChoice=0;
	double totPrice=0;
	int numTickets=0;
	
	
	cout << "\n\t\t C++ Theatre" << endl;
	cout << "\t\tTicket Purchase Opportunity" << endl << endl;
	cout << "Do you wish to view the chart of available seats \n"<< "before making your selections (y/n)? ";
	cin>> choice;
	
	if(choice=='Y'||choice=='y')
	{
		
		displaySeats(false);
		
	}
	
	do{
		
		cout << "\nPlease enter desired row number (1-" << rows << "): ";
		cin>>rowChoice;
		while(rowChoice<1||rowChoice>rows){
			cout << "Row must be between 1 and " << rows << ". Please re-enter: ";
			cin>>rowChoice;
		}
		cout << "\nPlease enter desired seat number (1-" << cols << "): ";
		cin>>colChoice;
		while(colChoice<1||colChoice>cols){
			cout << "Row must be between 1 and " << cols << ". Please re-enter: ";
			cin>>colChoice;
		}
		if (availableSeats[rowChoice-1][colChoice-1]==false)
		{
			availableSeats[rowChoice-1][colChoice-1]=true;
			totPrice+=seatPrices[rowChoice-1];
			cout << "\nPurchase confirmed\n";
			
			numTickets++;
		}
		else
		{
			cout << "\nSorry. That seat has been sold.\n";	
		}
		cout << "\nWould you like to purchase another seat (y/n)? ";
		cin>> again;
		
	}
	while (again=='Y'||again=='y');
	
	cout << "\n\nYou have purchased a total of " << numTickets << " tickets for a total price of $" << fixed<<setprecision(2)<<totPrice<<endl;
	
	menu();
}
