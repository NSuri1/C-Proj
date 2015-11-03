#include <iostream>
#include <iomanip>
using namespace std;

const int rows= 15;
const int cols= 30;

//Function Prototypes done by Nick Perez and Nalin Suri
void enterSeatPrices(double (&array)[rows]);
//first function to be called, asks users for price of each row
void menu();
//menu caller
void displaySeats(int [][cols]);
//display Seats
void displaySeatPrices(double []);
//displays prices by row 
void confirm();
//calls menu again if user presses enter after couting Press the Enter key to continue;
void juan();
void nick();
void nalin();

int main(){
	//menu();
	juan();
	nalin();
	nick();
	
	system("PAUSE");
	return 0;
}


//Menu done by Juan Herrera
void menu(){
int choice;
cout << "\n\n\n\t\tC++ Theatre" << endl << endl;
cout << "\n\t1. View Available Seats";
cout << "\n\t2. View Seating Prices";
cout << "\n\t3. View Ticket Sales";
cout << "\n\t4. Purchase a Ticket";
cout << "\n\t5. Exit the Program\n\n";
cout << "\n\tEnter your choice(1-5): ";
cin>>choice;
bool booll;

do{
	booll=false;
switch(choice){
	case 1:
	cout<< "Case 1 \n";
	break;
	case 2:
	cout<<"Case 2 \n";
	break;
	case 3:
	cout<< "Case 3 \n";
	break;
	case 4:
	cout<< "Case 4 \n";
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
void confirm(){
	string nothing;
	cout<<"Please enter to continue";
	cin>>nothing;
	menu();
}

//Function done by Nalin Suri
void enterSeatPrices(double (&array)[rows]) 
{
	for (int count=0;count<rows; count++)
	{
		cout<< "Please enter ticket price for Row"<< setw(2) << rows+1;
		cin>> array[rows];
	}
	
}

void displaySeatPrices(double price[]){
	cout>>"Ticket Prices by Row \n";
	for(int i=0;i<16;i++){
		cout<<"\tRow\t"<<"Price \n";
		cout<<"\t---\t"<<"---- \n";
		cout<<"\t"<<i+1<<"\t"<<price[i]<<endl;
	}
	
	
}
void nick(){

}
void nalin(){
	
}
void juan(){
	
}
