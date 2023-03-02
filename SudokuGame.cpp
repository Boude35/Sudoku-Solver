/*
*Author: Pablo Boudet
*Date: 09/22/2020
*Purpose Solve The Sudoku puzzle
*
*/

#include <iostream>
#include <fstream>

using namespace std;

//create the matrix that will held the values of the sudoku
int theBoard[9][9];

//Initialize the board of the sudoku
void initBoard()
{
	for(int row=0;row<9; row++)
	{
		for(int col=0;col<9;col++)
		{	
			theBoard[row][col]= ' ';	
		}
	}	
		
}

//print a row border
void printRowBorder()
{
	for(int col=0;col<3;col++)
		cout<<"+---";
	cout<<"+"<<endl;
}

//pints the whole board
void printBoard()
{
	
	for(int row=0;row<9; row++)
	{
		if(row%3==0) //create the border each three rows
		{
			printRowBorder(); //cal the function to print row borders
		}
		for(int col=0;col<9;col++)
		{	
			if(col%3==0) //create the border each three rows
				cout <<"|"; 
			//substitude with a * when the value of the matrix is zero
			//and with the vaule of th matrix whe it is different to zero
			if (theBoard[row][col]== 0)
			{
				cout << '*';
			}
			else
			{
				cout << theBoard[row][col];
			}
			
		}
		cout <<"|"<< endl; //last column border
		
	}
	printRowBorder();// last row border
}

//Check if the number can be placed 
bool canPlace(int atRow, int atCol, int n)
{
	//if the number is different to zero, cant be placed
	if(theBoard[atRow][atCol]!=0)
		return false;
	
	//check if the same number is in the column
	for(int c=0; c<9; c++)
	{
		if(theBoard[atRow][c] == n)
			return false;
	}
	
	//check if the same number is in the row
	for(int c=0; c<9; c++)
	{
		if(theBoard[c][atCol] == n)
			return false;
	}
	
	//check if there is any same value in the 3x3 quadrant
	int filacua = (atRow/3)*3;
	int colucua = (atCol/3)*3;
	for(int i= filacua; i<filacua+3;i++)
	{
		for (int j = colucua; j<colucua+3;j++)
		{
			if (theBoard[i][j]==n)
			return false;
		}
	}
	
	return true; //return true if all the conditions before are false and the number cn be placed
	
}

//Find the next empty value
bool findPlace(int *row, int *col)
{
	for(*row=0; *row<9; (*row)++)
	{
		for(*col=0; *col<9; (*col)++)
		{	
			if (theBoard[*row][*col]==0)//if the matrix equals zero(next empty value) returns true
				return true;	
		}	
	}
	return false;
}

//solve the sudoku
bool solveBoard(int board[9][9])
{
	int row=0; //initialize row
	int col=0; //initialize colum
	
		if (!findPlace(&row,&col))//check if the sudoku is already solve
			return true;
			
		for (int n=1; n<=9 ; n++)//values that can be placed
		{
			if(canPlace(row, col,n))//check if the conditions are satisfied
			{
				theBoard[row][col] = n;//place the number	
				
				//try to solve the rest of te puzzle
				if(solveBoard(theBoard))
			 		return true;
			 		
			 	//Recursive call failed could not be solve with the number placed
			 	//remove the number placed
				theBoard[row][col]= 0;
			 }
		}	
	
	return false;
}

void solveBoard()
{
	solveBoard(theBoard);
}


int main(int argc, char *argv[])
{
	cout << " Please Insert the file with the sudoku : ";

	initBoard();
	string myFile;
	cin >> myFile;
	
	//create a ready to let the user imput a file with the values of the sudoku
	ifstream TheReader(myFile.c_str());
	
	int imputFromFile;//store the file values
	
	
	
	if (TheReader)
	{
		TheReader>>imputFromFile; //store the first value of the file
		while (TheReader)//while it has values
		{
			for(int row=0;row<9; row++)
			{	
				for(int col=0;col<9;col++)
				{	
					theBoard[row][col] = imputFromFile ; //store the file values in the matrix
				
					TheReader >> imputFromFile;//next value
				}
		
			}
		}
	}
	
	else // if the file could not be find or does not exist
	{
		cout << "file could not be find "
			<<endl;
			
			return 0;
	}

	
	
	printBoard();
	
	
	cout<< "The solved sudoku is:" <<endl;
	solveBoard();
	printBoard();
	return 0;
}




