#include<iostream>
using namespace std;

#define  max 100 

bool IsVerticalWin(char B[max][max], int dim, int WC, char s)
{
	int count = 0;
	for (int ri = 0; ri < dim - WC + 1; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			for (int i = 0; i < WC; i++)
			{
				if (B[ri + i][ci] == s)
				{
					count++;
				}
				else
					break;
			}
			if (count == WC)
				return true;
			else
				count = 0;
		}
	}
	return false;
}
bool IsHorizontalWin(char B[max][max], int dim, int WC, char s)
{
	int count = 0;
	for (int ri = 0; ri < dim - WC + 1; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			for (int i = 0; i < WC; i++)
			{
				if (B[ri][ci + i] == s)
				{
					count++;
				}
				else
					break;
			}
			if (count == WC)
				return true;
			else
				count = 0;
		}
	}
	return false;
}
bool IsDiagonalTL2BR(char B[max][max], int dim, int WC, char s)
{
	int count = 0;
	for (int ri = 0; ri < dim - WC + 1; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			for (int i = 0; i < WC; i++)
			{
				if (B[ri + i][ci + i] == s)
				{
					count++;
				}
				else
					break;
			}
			if (count == WC)
				return true;
			else
				count = 0;
		}
	}
	return false;
}
bool IsDiagonalTR2BL(char B[max][max], int dim, int WC, char s)
{
	int count = 0;
	for (int ri = 0; ri < dim - WC + 1; ri++)
	{
		for (int ci = WC - 1; ci < dim; ci++)
		{
			for (int i = 0; i < WC; i++)
			{
				if (B[ri + i][ci - i] == s)
				{
					count++;
				}
				else
					break;
			}
			if (count == WC)
				return true;
			else
				count = 0;
		}
	}
	return false;
}
bool IsWin(char B[max][max], int dim, int WC, char s)
{
	return(IsHorizontalWin(B, dim, WC, s) || IsVerticalWin(B, dim, WC, s) ||
		IsDiagonalTL2BR(B, dim, WC, s) || IsDiagonalTR2BL(B, dim, WC, s));
}
bool IsDraw(char B[][max], int dim)
{
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if (B[ri][ci] == '-')
				return false;
		}
	}
	return true;
}
void startScreen(char s)
{
	cout << " \n\n\n\n\n\n\nGOMOKU : THE GAME OF LEGEND ";
	cout << "\n\nPress ENTER to start";
	
}
void ALL_INPUTS(char B[][max], int& NoOfPlayers, int& WIN_COUNT, char ps[], int& turn, int& Dimension)
{
	cout << "\n\nEnter dimension of the grid: ";
	cin >> Dimension;
	for (int ri = 0; ri < Dimension; ri++)
	{
		for (int ci = 0; ci < Dimension; ci++)
		{
			B[ri][ci] = '-';
		}
	}
	cout << "\n\nEnter how many players want to play:  ";
	cin >> NoOfPlayers;
	cout << "\n\nEnter " << NoOfPlayers << " symbols for each player : ";
	for (int i = 0; i < NoOfPlayers; i++)
	{
		cin >> ps[i];
	}
	cout << "\n\nEnter No of Win count : ";
	cin >> WIN_COUNT;
	//turn = rand() % NoOfPlayers;
}
void DISPLAY_BOARD(char b[][max], int dim)
{
	//system("clear");
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			cout << b[ri][ci];
		}
		cout << endl;
	}
}
void DISPLAY_PLAYER_MSG(char s)
{
	cout << "Player " << s << "'s Turn";
}
void PLAYERS_TURN(int& Ri, int& Ci)
{
	cout << "\nEnter the row: ";
	cin >> Ri;
	cout << "\nEnter the column: ";
	cin >> Ci;
}
bool IsValid(char B[][max], int dim, int Ri, int Ci)
{
	if ((Ri < 0 || Ri >= dim || Ci < 0 || Ci >= dim) || B[Ri][Ci] != '-')
	{
		return false;
	}
	return true;
}
void UPDATE_BOARD(char B[][max], int Ri, int Ci, char s)
{
	B[Ri][Ci] = s;
}
void TURN_CHANGE(int& turn, int nop)
{
	turn = (turn + 1) % nop;
}
int main()
{
	char B[max][max], PSs[100];
	int NoOfPlayers, dim, score[100] = { 0 }, WinCount;
	int turn, ri, ci;
	bool won;
	
	startScreen('.');
	//system("clear");
	ALL_INPUTS(B, NoOfPlayers, WinCount, PSs, turn, dim);
	do
	{
		DISPLAY_BOARD(B, dim);
		DISPLAY_PLAYER_MSG(PSs[turn]);
		do
		{
			PLAYERS_TURN(ri, ci);
			if (IsValid(B, dim, ri, ci) == false)
			{
				cout << "Invalid input !! Enter again: ";
				DISPLAY_PLAYER_MSG(PSs[turn]);
			}
		} while (IsValid(B, dim, ri, ci) == false);
		UPDATE_BOARD(B, ri, ci, PSs[turn]);
		won = IsWin(B, dim, WinCount, PSs[turn]);
		if ((won != true) || (IsDraw(B, dim) != true))
			TURN_CHANGE(turn, NoOfPlayers);
	} while ((won != true) && (IsDraw(B, dim) != true));
	//system("clear");
	if (won == true)
	{
	
		TURN_CHANGE(turn, NoOfPlayers);
		cout << "\n\n\nPlayer " << PSs[turn] << " Wins!!!!!";
	}
	else
		cout << "\n\n\nGAME DRAW !!!!";
	return 0;
}
