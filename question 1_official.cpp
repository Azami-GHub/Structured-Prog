#include <iostream>
using namespace std;


// to check whether all seats are occupied or not
int allOccupied(char seats[7][5])
{ 
	int count=0;
	for(int row=0; row<7; row++)
	{
		for(int col=1; col<5; col++)
		if(seats[row][col]=='X')
			count++;
	}

	if(count==28)
	{
		return 1;
	}
	return 0;
}


// function to display seats
void disp_seats(char seats[7][5])
{ 
	for(int row=0; row<7; row++)
	{
		for(int col=0; col<5; col++)
		{
			cout<<seats[row][col]<<" ";
		}
		cout<<endl;
	}

	return;
}

// function to get desired seats by customer
string getData()
{ 
	string p;
	cout<<"Enter valid seat no to check(like 1B) or N to end: ";
	cin>>p;
	return p;
}



//update seats status
void update(char seats[7][5],int i,int j){ 
	cout<<"Your desired seat is valid. Reserved for you\n";
	cout<<"Thank you for choosing Discord Cinema!"<<endl;
	cout<<endl;
	cout<<"Discord Cinema Seat status updated\n"<<endl;
	cout<<endl;
	seats[i][j]='X';
}




// to check desired seats by customer is succesfully process or not
int check(char seats[7][5],string s){ 
//if user input is not in the range 1A to 7D
	if(s[0]>'7' || s[0]<'1' || s[1]>'D' || s[1]<'A')
	{ 
		cout<<"Invalid seat no entered\n"; //invalid sit no
		return 0;
	}



	int i=-1, j=-1;
//find the row no of the customer's seats
	for(int row=0; row<7; row++)
	{	
		if(seats[row][0]==s[0])
		{
			i=row;
		}
	}
 //find the column no of the customer's seats
		for(int col=0; col<5; col++)
		{
			if(seats[i][col]==s[1])
			{
				j=col;
			}
		}

	//check whether seat is already occupied or not.
	if(j==-1)
	{
		cout<<"The chosen seat is already occupied ie. marked with 'X'\n";
		cout<<"Please choose another seat ^-^ "<<endl;
		//return 0;
	}
	else
	{
	//if it's a valid seats & not occupied, 
	//process the requested & update the sit as occupied 
	update(seats,i,j);   	
	}
//return 1;
} 



// to process and check customer input
void process(char seats[7][5])
{
	// user can stop process by input 'N'
	cout<<"Enter N if you are done!\n"; 
	string s;
	// continue if not interrepted by user unless 
	//there is valid seat in unoccupied state
	while(true)
	{ 
		s=getData(); //get user input
		// if user doesn't want to continue
		if(s[0]=='N')  // determine the user input
		{  
			break; // break
		}

		//process the request & check according to desired seats entered
		else if(check(seats,s))
		{ 
			disp_seats(seats);
		}

		else if(allOccupied(seats))
		{ //if all seats are occupied
			cout<<"We are so sorry, no more seats left!1..."<<endl;
			cout<<endl;
			break; //break
		}
	}
	cout<<"Thank You for choosing Discord Cinema, Have a nice day!"<<endl; //end of program
}






int main()
{
	char seats[7][5];
	for(int row=0; row<7; row++){
		//to display row number of seats exp 1A,2B,3A etc
		seats[row][0]= row+1 + '0';
		for(int col=1; col<5; col++)
		{
			//using ASCII value to display A,B,C,D respectively
			seats[row][col]='A'+ col-1; // to determine which alphabet to be stored in respective column and respective alphabet index
		}
	}
	
	cout<<"===============WELCOME TO DISCORD CINEMA==============="<<endl;
	cout<<endl;
	cout<<"Initial seat arrangements......\n";
	disp_seats(seats);
	
	process(seats);
	
}
