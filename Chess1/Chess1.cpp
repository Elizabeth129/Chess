#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>

using namespace std;

class Moves
{
public:
	Moves();
	~Moves();
	bool Rook(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y);
	bool Bishop(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y);
	bool Knight(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y);
	bool Queen(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y);
	bool Pawn(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y);
	void ChangePawn(int(&figure)[8][8], int pos_end_x, int pos_end_y);
	bool CheckWhite(int(&figure)[8][8], int pos_end_x, int pos_end_y);
	bool CheckBlack(int(&figure)[8][8], int pos_end_x, int pos_end_y);
	bool King(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y);
	bool CheckWhite1(int(&figure)[8][8]);
	bool CheckBlack1(int(&figure)[8][8]);
	bool CheckmateWhite(int(&figure)[8][8]);
	bool CheckmateBlack(int(&figure)[8][8]);
	bool CastlingWhiteLong(int(&figure)[8][8]);
	bool CastlingWhiteShort(int(&figure)[8][8]);
	bool CastlingBlackLong(int(&figure)[8][8]);
	bool CastlingBlackShort(int(&figure)[8][8]);
	void Restart();
	static int GetMove() { return Move; };
	static int GetEnPassant() { return EnPassant; };
	static int GetCheckWhite() { return CheckWhite_; };
	static int GetCheckBlack() { return CheckBlack_; };
	static bool GetCanCastlingWhiteLong() { return CanCastlingWhiteLong; }
	static bool GetCanCastlingWhiteShort() { return CanCastlingWhiteShort; }
	static bool GetCanCastlingBlackLong() { return CanCastlingBlackLong; }
	static bool GetCanCastlingBlackShort() { return CanCastlingBlackShort; }
	static void SetMove(int move) { Move = move; };
	static void SetEnPassent(int enPassant) { EnPassant = enPassant; };
	static void SetCheckWhite(int check) { CheckWhite_ = check; };
	static void SetCheckBlack(int check) { CheckBlack_ = check; };
	static void SetCanCastlingWhiteLong(int canCastling) { CanCastlingWhiteLong = canCastling; }
	static void SetCanCastlingWhiteShort(int canCastling) { CanCastlingWhiteShort = canCastling; }
	static void SetCanCastlingBlackLong(int canCastling) { CanCastlingBlackLong = canCastling; }
	static void SetCanCastlingBlackShort(int canCastling) { CanCastlingBlackShort = canCastling; }
private:
	static int EnPassant;
	static int Move;
	static int CheckWhite_;
	static int CheckBlack_;
	static bool CanCastlingWhiteLong;
	static bool CanCastlingWhiteShort;
	static bool CanCastlingBlackLong;
	static bool CanCastlingBlackShort;
};

Moves::Moves()
{
}

Moves::~Moves()
{
}

bool Moves::Rook(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y)
{
	if (pos_start_x == pos_end_x || pos_start_y == pos_end_y)
	{
		if (pos_end_x == pos_start_x)
			for (int i = min(pos_end_y, pos_start_y) + 1; i < max(pos_end_y, pos_start_y); i++)
			{
				if (figure[i][pos_start_x] != 0) return false;
			}
		if (pos_end_y == pos_start_y)
			for (int i = min(pos_end_x, pos_start_x) + 1; i < max(pos_end_x, pos_start_x); i++)
			{
				if (figure[pos_start_y][i] != 0) return false;
			}
		if (figure[pos_end_y][pos_end_x] == 0)
		{
			if (figure[pos_start_y][pos_start_x] < 7)
			{
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckWhite1(figure))
				{
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else {
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					CheckWhite_ = -1;
					return true;
				}
			}
			if (figure[pos_start_y][pos_start_x] > 6)
			{
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckBlack1(figure))
				{
					
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else {
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					CheckBlack_ = -1;
					return true;
				}
			}
		}
		else
			if (figure[pos_start_y][pos_start_x] < 7)
			{
				if (figure[pos_end_y][pos_end_x] > 6)
				{
						int n = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
						figure[pos_start_y][pos_start_x] = 0;
						if (CheckWhite1(figure))
						{
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							return false;
						}
						else {
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							CheckWhite_ = -1;
							return true;
						}
				}
				else return false;
			}
			else
				if (figure[pos_start_y][pos_start_x] > 6)
				{
					if (figure[pos_end_y][pos_end_x] < 7)
					{
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckBlack1(figure))
							{
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								CheckBlack_ = -1;
								return true;
							}
					}
					else
						return false;
				}
	}
	return false;
}

bool Moves::Bishop(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y)
{
	if (abs(pos_start_x - pos_end_x) == abs(pos_start_y - pos_end_y))
	{
		if (pos_start_x > pos_end_x)
		{
			if (pos_start_y > pos_end_y)
			{
				for (int i = 1; i < abs(pos_start_x - pos_end_x); i++)
				{
					if (figure[pos_start_y - i][pos_start_x - i] != 0) return false;
				}
			}
			if (pos_start_y < pos_end_y)
			{
				for (int i = 1; i < abs(pos_start_x - pos_end_x); i++)
				{
					if (figure[pos_start_y + i][pos_start_x - i] != 0) return false;
				}
			}
		}
		else
		{
			if (pos_start_y > pos_end_y)
			{
				for (int i = 1; i < abs(pos_start_x - pos_end_x); i++)
				{
					if (figure[pos_start_y - i][pos_start_x + i] != 0) return false;
				}
			}
			if (pos_start_y < pos_end_y)
			{
				for (int i = 1; i < abs(pos_start_x - pos_end_x); i++)
				{
					if (figure[pos_start_y + i][pos_start_x + i] != 0) return false;
				}
			}
		}

		if (figure[pos_end_y][pos_end_x] == 0)
		{
			if (figure[pos_start_y][pos_start_x] < 7)
			{
				
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckWhite1(figure))
				{
					
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else {
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					//EnPassant = -1;
					
					CheckWhite_ = -1;
					return true;
				}
			}
			if (figure[pos_start_y][pos_start_x] > 6)
			{
				
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckBlack1(figure))
				{
					
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else {
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					//EnPassant = -1;
					
					CheckBlack_ = -1;
					return true;
				}
			}
		}
		else
			if (figure[pos_start_y][pos_start_x] < 7)
			{
				if (figure[pos_end_y][pos_end_x] > 6)
				{
					
						
						int n = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
						figure[pos_start_y][pos_start_x] = 0;
						if (CheckWhite1(figure))
						{
							
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							return false;
						}
						else {
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							//EnPassant = -1;
						
							CheckWhite_ = -1;
							return true;
						}
					
				}
				else return false;
			}
			else
				if (figure[pos_start_y][pos_start_x] > 6)
				{
					if (figure[pos_end_y][pos_end_x] < 7)
					{
						
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckBlack1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								//EnPassant = -1;
								
								CheckBlack_ = -1;
								return true;
							}
						
					}
					else
						return false;
				}
	}
	return false;
}

bool Moves::Knight(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y)
{
	if ((abs(pos_start_x - pos_end_x) == 2 && abs(pos_start_y - pos_end_y) == 1) ||
		(abs(pos_start_x - pos_end_x) == 1 && abs(pos_start_y - pos_end_y) == 2))
	{
		if (figure[pos_end_y][pos_end_x] == 0)
		{
			if (figure[pos_start_y][pos_start_x] < 7)
			{
				
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckWhite1(figure))
				{
					
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else {
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					//EnPassant = -1;
					
					CheckWhite_ = -1;
					return true;
				}
			}
			if (figure[pos_start_y][pos_start_x] > 6)
			{
				
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckBlack1(figure))
				{
					
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else {
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					//EnPassant = -1;
					
					CheckBlack_ = -1;
					return true;
				}
			}
		}
		else
			if (figure[pos_start_y][pos_start_x] == 2)
			{
				if (figure[pos_end_y][pos_end_x] > 6)
				{
					
						
						int n = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
						figure[pos_start_y][pos_start_x] = 0;
						if (CheckWhite1(figure))
						{
							
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							return false;
						}
						else {
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							//EnPassant = -1;
							
							CheckWhite_ = -1;
							return true;
						}
					
				}
				else return false;
			}
			else
				if (figure[pos_start_y][pos_start_x] == 8)
				{
					if (figure[pos_end_y][pos_end_x] < 7)
					{
						
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckBlack1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								//EnPassant = -1;
								
								CheckBlack_ = -1;
								return true;
							}
						
					}
					else
						return false;
				}
	}
	return false;
}

bool Moves::Queen(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y)
{
	if (Rook(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y) ||
		Bishop(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y))
	{

		
		return true;
	}
	return false;
}

bool Moves::Pawn(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y)
{
	if (pos_start_x == pos_end_x)
	{
		if (figure[pos_start_y][pos_start_x] == 6)
		{
			if (pos_end_y - pos_start_y == 1)
			{
				if (figure[pos_end_y][pos_end_x] == 0)
				{
					if (figure[pos_start_y][pos_start_x] < 7)
					{
						int n = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
						figure[pos_start_y][pos_start_x] = 0;
						
						if (CheckWhite1(figure))
						{
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							
							return false;
						}
						else {
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							//EnPassant = -1;
							
							CheckWhite_ = -1;
							return true;
						}
					}
					if (figure[pos_start_y][pos_start_x] > 6)
					{
						int n = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
						figure[pos_start_y][pos_start_x] = 0;
						
						if (CheckBlack1(figure))
						{
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							
							return false;
						}
						else {
							figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = n;
							//EnPassant = -1;
							
							CheckBlack_ = -1;
							return true;
						}
					}
				}
			}
			else
				if (pos_end_y - pos_start_y == 2)
				{
					if (figure[pos_end_y][pos_end_x] == 0 && figure[pos_end_y - 1][pos_end_x] == 0 &&
						pos_start_y == 1)
					{
						if (figure[pos_start_y][pos_start_x] < 7)
						{
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							
							if (CheckWhite1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								EnPassant = pos_start_x;
								
								CheckWhite_ = -1;
								return true;
							}
						}
						if (figure[pos_start_y][pos_start_x] > 6)
						{
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckBlack1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								EnPassant = pos_start_x;
								
								CheckBlack_ = -1;
								return true;
							}
						}

					}
				}

		}
		else
			if (figure[pos_start_y][pos_start_x] == 12)
			{
				if (pos_start_y - pos_end_y == 1)
				{
					if (figure[pos_end_y][pos_end_x] == 0)
					{
						if (figure[pos_start_y][pos_start_x] < 7)
						{
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckWhite1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								//EnPassant = -1;
								
								CheckWhite_ = -1;
								return true;
							}
						}
						if (figure[pos_start_y][pos_start_x] > 6)
						{
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckBlack1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								//EnPassant = -1;
								
								CheckBlack_ = -1;
								return true;
							}
						}
					}
				}
				else
					if (pos_start_y - pos_end_y == 2)
					{
						if (figure[pos_end_y][pos_end_x] == 0 && figure[pos_end_y + 1][pos_end_x] == 0
							&& pos_start_y == 6)
						{
							if (figure[pos_start_y][pos_start_x] < 7)
							{
								
								int n = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
								figure[pos_start_y][pos_start_x] = 0;
								if (CheckWhite1(figure))
								{
									
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									return false;
								}
								else {
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									EnPassant = pos_start_x + 8;
									
									CheckWhite_ = -1;
									return true;
								}
							}
							if (figure[pos_start_y][pos_start_x] > 6)
							{
								
								int n = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
								figure[pos_start_y][pos_start_x] = 0;
								if (CheckBlack1(figure))
								{
									
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									return false;
								}
								else {
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									EnPassant = pos_start_x + 8;
									
									CheckBlack_ = -1;
									return true;
								}
							}
						}
					}
			}
	}
	else
		if (abs(pos_end_x - pos_start_x) == 1)
		{
			if (figure[pos_start_y][pos_start_x] == 6)
			{
				if (pos_end_y - pos_start_y == 1)
				{
					if (figure[pos_end_y][pos_end_x] > 6)
					{
						if (figure[pos_start_y][pos_start_x] < 7)
						{
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckWhite1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								//EnPassant = -1;
								
								CheckWhite_ = -1;
								return true;
							}
						}
						if (figure[pos_start_y][pos_start_x] > 6 && Move == 1)
						{
							
							int n = figure[pos_end_y][pos_end_x];
							figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
							figure[pos_start_y][pos_start_x] = 0;
							if (CheckBlack1(figure))
							{
								
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								return false;
							}
							else {
								figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = n;
								//EnPassant = -1;
								
								CheckBlack_ = -1;
								return true;
							}
						}
					}
					else
						if (EnPassant == 8 + pos_end_x)
						{
							figure[pos_end_y][pos_end_x] = figure[pos_end_y - 1][pos_end_x];
							figure[pos_end_y - 1][pos_end_x] = 0;
							if (figure[pos_start_y][pos_start_x] < 7 )
							{
								
								int n = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
								figure[pos_start_y][pos_start_x] = 0;
								if (CheckWhite1(figure))
								{
									
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									return false;
								}
								else {
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									//EnPassant = -1;
									
									CheckWhite_ = -1;
									return true;
								}
							}
							if (figure[pos_start_y][pos_start_x] > 6)
							{
								
								int n = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
								figure[pos_start_y][pos_start_x] = 0;
								if (CheckBlack1(figure))
								{
									
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									return false;
								}
								else {
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									//EnPassant = -1;
									
									CheckBlack_ = -1;
									return true;
								}
							}
						}
				}
			}
			else
				if (figure[pos_start_y][pos_start_x] == 12)
				{

					if (pos_start_y - pos_end_y == 1)
					{

						if (figure[pos_end_y][pos_end_x] < 7 && figure[pos_end_y][pos_end_x] != 0)
						{

							if (figure[pos_start_y][pos_start_x] < 7)
							{
								
								int n = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
								figure[pos_start_y][pos_start_x] = 0;
								if (CheckWhite1(figure))
								{
									
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									return false;
								}
								else {
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									//EnPassant = -1;
									
									CheckWhite_ = -1;
									return true;
								}
							}
							if (figure[pos_start_y][pos_start_x] > 6)
							{
								
								int n = figure[pos_end_y][pos_end_x];
								figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
								figure[pos_start_y][pos_start_x] = 0;
								if (CheckBlack1(figure))
								{
									
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									return false;
								}
								else {
									figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = n;
									//EnPassant = -1;
								
									CheckBlack_ = -1;
									return true;
								}
							}
						}
						else
							if (EnPassant == pos_end_x)
							{
								figure[pos_end_y][pos_end_x] = figure[pos_end_y + 1][pos_end_x];
								figure[pos_end_y + 1][pos_end_x] = 0;
								if (figure[pos_start_y][pos_start_x] < 7 )
								{
									
									int n = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
									figure[pos_start_y][pos_start_x] = 0;
									if (CheckWhite1(figure))
									{
										
										figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
										figure[pos_end_y][pos_end_x] = n;
										return false;
									}
									else {
										figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
										figure[pos_end_y][pos_end_x] = n;
										//EnPassant = -1;
										
										CheckWhite_ = -1;
										return true;
									}
								}
								if (figure[pos_start_y][pos_start_x] > 6 )
								{
									
									int n = figure[pos_end_y][pos_end_x];
									figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
									figure[pos_start_y][pos_start_x] = 0;
									if (CheckBlack1(figure))
									{
										
										figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
										figure[pos_end_y][pos_end_x] = n;
										return false;
									}
									else {
										figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
										figure[pos_end_y][pos_end_x] = n;
										//EnPassant = -1;
										
										CheckBlack_ = -1;
										return true;
									}
								}
							}
					}
				}
		}
	return false;
}

void Moves::ChangePawn(int(&figure)[8][8], int pos_end_x, int pos_end_y)
{
	cout << "For what figure you want to change pawn?\n";
	cout << "Rook, Bishop, Knight, Queen?";
	string s;
	cin >> s;
	if (s == "Rook")
	{
		if (figure[pos_end_y][pos_end_x] == 6)
		{
			figure[pos_end_y][pos_end_x] = 1;
		}
		if (figure[pos_end_y][pos_end_x] == 12)
		{
			figure[pos_end_y][pos_end_x] = 7;
		}
	}
	if (s == "Bishop")
	{
		if (figure[pos_end_y][pos_end_x] == 6)
		{
			figure[pos_end_y][pos_end_x] = 3;
		}
		if (figure[pos_end_y][pos_end_x] == 12)
		{
			figure[pos_end_y][pos_end_x] = 9;
		}
	}
	if (s == "Knight")
	{
		if (figure[pos_end_y][pos_end_x] == 6)
		{
			figure[pos_end_y][pos_end_x] = 2;
		}
		if (figure[pos_end_y][pos_end_x] == 12)
		{
			figure[pos_end_y][pos_end_x] = 8;
		}
	}
	if (s == "Queen")
	{
		if (figure[pos_end_y][pos_end_x] == 6)
		{
			figure[pos_end_y][pos_end_x] = 4;
		}
		if (figure[pos_end_y][pos_end_x] == 12)
		{
			figure[pos_end_y][pos_end_x] = 10;
		}
	}
}

bool Moves::CheckWhite(int(&figure)[8][8], int pos_end_x, int pos_end_y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] == 12)
			{
				if (Pawn(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 7)
			{
				if (Rook(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 9)
			{
				if (Bishop(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 8)
			{
				if (Knight(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 10)
			{
				if (Queen(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 11)
			{
				if (abs(pos_end_x - j) < 2 && abs(pos_end_y - i) < 2)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Moves::CheckBlack(int(&figure)[8][8], int pos_end_x, int pos_end_y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] == 6)
			{
				if (Pawn(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 1)
			{
				if (Rook(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 3)
			{
				if (Bishop(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 2)
			{
				if (Knight(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 4)
			{
				if (Queen(figure, j, i, pos_end_x, pos_end_y))
				{
					return true;
				}
			}
			if (figure[i][j] == 5)
			{
				if (abs(pos_end_x - j) < 2 && abs(pos_end_y - i) < 2)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Moves::King(int(&figure)[8][8], int pos_start_x, int pos_start_y, int pos_end_x, int pos_end_y)
{
	if (abs(pos_end_x - pos_start_x) < 2 && abs(pos_end_y - pos_start_y) < 2)
	{
		if (figure[pos_start_y][pos_start_x] == 5)
		{
			if (figure[pos_end_y][pos_end_x] > 6 || figure[pos_end_y][pos_end_x] == 0)
			{
				int n = figure[pos_end_y][pos_end_x];
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (CheckWhite(figure, pos_end_x, pos_end_y))
				{
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					return false;
				}
				else
				{
					figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = n;
					if (figure[pos_start_y][pos_start_x] < 7 )
					{
						//EnPassant = -1;
						
						return true;
					}
					if (figure[pos_start_y][pos_start_x] > 6 )
					{
						//EnPassant = -1;
						
						return true;
					}
				}
			}
		}
		else
			if (figure[pos_start_y][pos_start_x] == 11)
			{
				if (figure[pos_end_y][pos_end_x] < 7 || figure[pos_end_y][pos_end_x] == 0)
				{
					int n = figure[pos_end_y][pos_end_x];
					figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
					figure[pos_start_y][pos_start_x] = 0;
					if (CheckBlack(figure, pos_end_x, pos_end_y))
					{
						figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = n;
						return false;
					}
					else
					{
						figure[pos_start_y][pos_start_x] = figure[pos_end_y][pos_end_x];
						figure[pos_end_y][pos_end_x] = n;
						if (figure[pos_start_y][pos_start_x] < 7 )
						{
							//EnPassant = -1;
							
							return true;
						}
						if (figure[pos_start_y][pos_start_x] > 6 )
						{
							//EnPassant = -1;
							
							return true;
						}
					}
				}
			}
	}
	return false;
}

bool Moves::CheckWhite1(int(&figure)[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] == 5)
			{
				return CheckWhite(figure, j, i);
			}
		}
	}
}

bool Moves::CheckBlack1(int(&figure)[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] == 11)
			{
				return CheckBlack(figure, j, i);
			}
		}
	}
}

bool Moves::CheckmateWhite(int(&figure)[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] < 7)
			{
				for (int k = 0; k < 8; k++)
				{
					for (int l = 0; l < 8; l++)
					{
						if (figure[i][j] == 1 && Rook(figure, j, i, l, k))
						{
							return false;
						}
						
						if (figure[i][j] == 3 && Bishop(figure, j, i, l, k))
						{
							return false;
						}
						
						if (figure[i][j] == 4 && Queen(figure, j, i, l, k))
						{					
							return false;
						}
						
						if (figure[i][j] == 2 && Knight(figure, j, i, l, k))
						{
							return false;
						}
						
						if (figure[i][j] == 6 && Pawn(figure, j, i, l, k))
						{
							return false;
						}
						
						if (figure[i][j] == 5 && King(figure, j, i, l, k))
						{
							return false;
						}
					}
				}
			}
		}
	}
	
	return true;
}

bool Moves::CheckmateBlack(int(&figure)[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] > 6)
			{
				for (int k = 0; k < 8; k++)
				{
					for (int l = 0; l < 8; l++)
					{
						if (figure[i][j] == 7 && Rook(figure, j, i, l, k))
						{
							return false;
						}

						if (figure[i][j] == 9 && Bishop(figure, j, i, l, k))
						{
							return false;
						}

						if (figure[i][j] == 10 && Queen(figure, j, i, l, k))
						{
							return false;
						}

						if (figure[i][j] == 8 && Knight(figure, j, i, l, k))
						{
							return false;
						}

						if (figure[i][j] == 12 && Pawn(figure, j, i, l, k))
						{
							return false;
						}

						if (figure[i][j] == 11 && King(figure, j, i, l, k))
						{
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}

bool Moves::CastlingWhiteLong(int(&figure)[8][8])
{
	if (CanCastlingWhiteLong)
	{
		if (figure[0][1] == 0 && figure[0][2] == 0 && figure[0][3] == 0)
		{
			if (!CheckWhite(figure, 4, 0)) {
				figure[0][3] = figure[0][4];
				if (!CheckWhite(figure, 3, 0))
				{
					figure[0][2] = figure[0][3];
					figure[0][3] = figure[0][0];
					if (!CheckWhite(figure, 2, 0))
					{
						figure[0][4] = figure[0][2];
						figure[0][0] = figure[0][3];
						CanCastlingWhiteLong = false;
						CanCastlingWhiteShort = false;
						return true;
					}
				}
				else
				{
					figure[0][4] = figure[0][3];
				}
			}
		}
	}
	return false;
}

bool Moves::CastlingWhiteShort(int(&figure)[8][8])
{
	if (CanCastlingWhiteShort)
	{
		if (figure[0][5] == 0 && figure[0][6] == 0)
		{
			if (!CheckWhite(figure, 4, 0)) {
				figure[0][5] = figure[0][4];
				if (!CheckWhite(figure, 5, 0))
				{
					figure[0][6] = figure[0][5];
					figure[0][5] = figure[0][7];
					if (!CheckWhite(figure, 6, 0))
					{
						figure[0][4] = figure[0][6];
						figure[0][7] = figure[0][5];
						CanCastlingWhiteShort = false;
						CanCastlingWhiteLong = false;
						return true;
					}
				}
				else
				{
					figure[0][4] = figure[0][5];
				}
			}
		}
	}
	return false;
}

bool Moves::CastlingBlackLong(int(&figure)[8][8])
{
	if (CanCastlingBlackLong)
	{
		if (figure[7][1] == 0 && figure[7][2] == 0 && figure[7][3] == 0)
		{
			if (!CheckWhite(figure, 4, 7)) {
				figure[7][3] = figure[7][4];
				if (!CheckWhite(figure, 3, 7))
				{
					figure[7][2] = figure[7][3];
					figure[7][3] = figure[7][0];
					if (!CheckWhite(figure, 2, 7))
					{
						figure[7][4] = figure[7][2];
						figure[7][0] = figure[7][3];
						CanCastlingBlackLong = false;
						CanCastlingBlackShort = false;
						return true;
					}
				}
				else
				{
					figure[7][4] = figure[7][3];
				}
			}
		}
	}
	return false;
}

bool Moves::CastlingBlackShort(int(&figure)[8][8])
{
	if (CanCastlingBlackShort)
	{
		if (figure[7][5] == 0 && figure[7][6] == 0)
		{
			if (!CheckWhite(figure, 4, 7)) {
				figure[7][5] = figure[7][4];
				if (!CheckWhite(figure, 5, 7))
				{
					figure[7][6] = figure[7][5];
					figure[7][5] = figure[7][7];
					if (!CheckWhite(figure, 6, 7))
					{
						figure[7][4] = figure[7][6];
						figure[7][7] = figure[7][5];
						CanCastlingBlackShort = false;
						CanCastlingBlackLong = false;
						return true;
					}
				}
				else
				{
					figure[0][4] = figure[0][5];
				}
			}
		}
	}
	return false;
}

void Moves::Restart()
{
	EnPassant = -1;
	Move = 0;
	CheckBlack_ = -1;
	CheckWhite_ = -1;
	CanCastlingBlackLong = true;
	CanCastlingBlackShort = true;
	CanCastlingWhiteLong = true;
	CanCastlingWhiteShort = true;
}



bool gameOver = false;
const int n = 8;
const int colFigure = 13;
int figure[n][n] = {
	{1,2,3,4,5,3,2,1},
	{6,6,6,6,6,6,6,6},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{12,12,12,12,12,12,12,12},
	{7,8,9,10,11,9,8,7}
};
int figure_start[n][n] = {
	{1,2,3,4,5,3,2,1},
	{6,6,6,6,6,6,6,6},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{12,12,12,12,12,12,12,12},
	{7,8,9,10,11,9,8,7}
};
string nameOfFigure[colFigure] = { "","WR","WN","WB","WQ","WK","WP","BR","BN","BB","BQ","BK","BP" };
int colMoves, colCastlesWhite, colCastlesBlack, scoreWhite, scoreBlack;
int pos_start_x;
int pos_end_x;
int pos_start_y;
int pos_end_y;
int Moves::EnPassant = -1;
int Moves::Move = 0;
int Moves::CheckWhite_ = -1;
int Moves::CheckBlack_ = -1;
bool Moves::CanCastlingBlackLong = true;
bool Moves::CanCastlingBlackShort = true;
bool Moves::CanCastlingWhiteLong = true;
bool Moves::CanCastlingWhiteShort = true;
bool start = false;
void Logic(bool f);

void Setup()
{
	gameOver = false;
	colMoves = 0;
	colCastlesBlack = 0;
	colCastlesWhite = 0;
	scoreWhite = 0;
	scoreBlack = 0;
}

void Draw()
{
	system("cls");
	HANDLE hCon;
	COORD cPos;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	//output figure
	cPos.X = 6;
	cPos.Y = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			SetConsoleCursorPosition(hCon, cPos);
			cout << nameOfFigure[figure[i][j]];
			cPos.X += 3;
		}
		cPos.X = 6;
		cPos.Y++;
	}

	cPos.X = 15;
	cPos.Y = 0;
	SetConsoleCursorPosition(hCon, cPos);
	cout << "White";
	cPos.Y = 11;
	SetConsoleCursorPosition(hCon, cPos);
	cout << "Black";
	int codChar = 97;
	cPos.Y = 1;
	cPos.X = 7;
	for (int i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(hCon, cPos);
		cout << (char)(codChar + i);
		cPos.X += 3;
	}
	cPos.Y = 10;
	cPos.X = 7;
	for (int i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(hCon, cPos);
		cout << (char)(codChar + i);
		cPos.X += 3;
	}
	cPos.Y = 2;
	cPos.X = 4;
	for (int i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(hCon, cPos);
		cout << i + 1;
		cPos.Y++;
	}
	cPos.Y = 2;
	cPos.X = 30;
	for (int i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(hCon, cPos);
		cout << i + 1;
		cPos.Y++;
	}
	cPos.X = 40;
	cPos.Y = 2;
	SetConsoleCursorPosition(hCon, cPos);
	cout << "Score White: " << scoreWhite << "\n";
	cPos.X = 40;
	cPos.Y = 3;
	SetConsoleCursorPosition(hCon, cPos);
	cout << "Score Black: " << scoreBlack << "\n";
	Sleep(1000);
	//output lines
	POINT op;
	HWND hWnd = GetConsoleWindow(); //Получаем дескриптор окна консоли
	HDC hDC = GetDC(hWnd); //Получаем контекст устройства по полученному дескриптору
	SelectObject(hDC, GetStockObject(WHITE_PEN)); //Выбираем перо WHITE_PEN в контекст

	int x1 = 50;
	int y1 = 40;
	int y2 = 200;
	for (int i = 0; i < n + 1; i++)
	{
		MoveToEx(hDC, x1, y1, &op);
		LineTo(hDC, x1, y2);
		x1 += 27;
	}

	x1 = 50;
	int x2 = 266;
	y1 = 40;
	for (int i = 0; i < n + 1; i++)
	{
		MoveToEx(hDC, x1, y1, &op);
		LineTo(hDC, x2, y1);
		y1 += 20;
	}

	MoveToEx(hDC, 45, 35, &op);
	LineTo(hDC, 45, 205);
	MoveToEx(hDC, 45, 35, &op);
	LineTo(hDC, 271, 35);
	MoveToEx(hDC, 271, 35, &op);
	LineTo(hDC, 271, 205);
	MoveToEx(hDC, 45, 205, &op);
	LineTo(hDC, 271, 205);

	cPos.X = 10;
	cPos.Y = 13;
	SetConsoleCursorPosition(hCon, cPos);
	if (Moves::GetMove() == 0) cout << "White\n"; else cout << "Black\n";

	cPos.X = 0;
	cPos.Y = 15;
	SetConsoleCursorPosition(hCon, cPos);
	if (gameOver)
	{
		cout << "Game over!\n";
	}
}

void LogicRook()
{
	//cout << pos_end_x << " " << pos_end_y;
	Moves m;
	bool f = m.Rook(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y);
	Logic(f);
}

void LogicBishop()
{
	Moves m;
	bool f = m.Bishop(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y);
	Logic(f);
}

void LogicKnight()
{
	Moves m;
	bool f = m.Knight(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y);
	Logic(f);
}

void LogicQueen()
{
	Moves m;
	bool f = m.Queen(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y);
	Logic(f);
}

void LogicPawn()
{
	Moves m;
	bool f = m.Pawn(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y);
	Logic(f);
}

void LogicKing()
{
	Moves m;
	bool f = m.King(figure, pos_start_x, pos_start_y, pos_end_x, pos_end_y);
	Logic(f);
}

void Logic(bool f)
{
	if (f)
	{
		if ((figure[pos_start_y][pos_start_x] < 7 && Moves::GetMove() == 0)
			|| (figure[pos_start_y][pos_start_x] > 6 && Moves::GetMove() == 1)) {
			if (figure[pos_start_y][pos_start_x] == 5)
			{
				Moves::SetCanCastlingWhiteLong(false);
				Moves::SetCanCastlingWhiteShort(false);
			}
			if (figure[pos_start_y][pos_start_x] == 11)
			{
				Moves::SetCanCastlingBlackLong(false);
				Moves::SetCanCastlingBlackShort(false);
			}
			if (figure[pos_start_y][pos_start_x] == 1 && pos_start_x == 0)
			{
				Moves::SetCanCastlingWhiteLong(false);
			}
			if (figure[pos_start_y][pos_start_x] == 1 && pos_start_x == 7)
			{
				Moves::SetCanCastlingWhiteShort(false);
			}
			if (figure[pos_start_y][pos_start_x] == 7 && pos_start_x == 0)
			{
				Moves::SetCanCastlingBlackLong(false);
			}
			if (figure[pos_start_y][pos_start_x] == 7 && pos_start_x == 7)
			{
				Moves::SetCanCastlingBlackShort(false);
			}
			if (figure[pos_start_y][pos_start_x] < 7)
			{
				if (Moves::GetEnPassant() != pos_start_x || figure[pos_start_y][pos_start_x] < 6)
				{
					Moves::SetEnPassent(-1);
				}
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (figure[i][j] == 11)
						{
							Moves m;
							if (m.CheckBlack(figure, j, i))
							{
								Moves::SetCheckBlack(1);
							}
						}
					}
				}
			}
			else
				if (figure[pos_start_y][pos_start_x] > 6)
				{
					if (Moves::GetEnPassant() != pos_start_x+8 || figure[pos_start_y][pos_start_x] < 12)
					{
						Moves::SetEnPassent(-1);
					}
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (figure[i][j] == 5)
							{
								Moves m;
								if (m.CheckWhite(figure, j, i))
								{
									Moves::SetCheckWhite(1);
								}
							}
						}
					}
				}
			if (figure[pos_end_y][pos_end_x] == 0)
			{
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
			}
			else
			{
				figure[pos_end_y][pos_end_x] = figure[pos_start_y][pos_start_x];
				figure[pos_start_y][pos_start_x] = 0;
				if (figure[pos_end_y][pos_end_x] < 7) scoreWhite++;
				if (figure[pos_end_y][pos_end_x] > 6) scoreBlack++;
			}
			if (figure[pos_end_y][pos_end_x] == 6)
			{
				if (pos_end_y == 7)
				{
					Moves m;
					m.ChangePawn(figure, pos_end_x, pos_end_y);
				}
			}
			if (figure[pos_end_y][pos_end_x] == 12)
			{
				if (pos_end_y == 0)
				{
					Moves m;
					m.ChangePawn(figure, pos_end_x, pos_end_y);
				}
			}
			if (figure[pos_end_y][pos_end_x] > 6)
			{
				Moves m;
				if (m.CheckWhite1(figure))
				{
					if (m.CheckmateWhite(figure))
					{
						gameOver = true;
					}
				}
			}
			if (figure[pos_end_y][pos_end_x] < 7)
			{
				Moves m;
				if (m.CheckBlack1(figure))
				{
					if (m.CheckmateBlack(figure))
					{
						gameOver = true;
					}
				}
			}
			Moves::SetMove((Moves::GetMove() + 1) % 2);
		}
		else cout << "Can't move!";
	}
	else
	{
		cout << "Can't move!";
	}
}

void RestartGame()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			figure[i][j] = figure_start[i][j];
		}
	}
	colCastlesBlack = 0;
	colCastlesWhite = 0;
	Setup();
	Moves m;
	m.Restart();

}

void Save()
{
	string nameOfFile;
	cout << "Input name of file:\n";
	cin >> nameOfFile;
	try
	{
		ofstream fileSave;
		fileSave.open(nameOfFile);
		if (fileSave.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					fileSave << figure[i][j] << " ";
				}
			}
			fileSave << Moves::GetMove() << " ";
			fileSave << Moves::GetEnPassant() << " ";
			fileSave << scoreWhite << " " << scoreBlack << " ";
			fileSave << Moves::GetCanCastlingWhiteLong() << " ";
			fileSave << Moves::GetCanCastlingWhiteShort() << " ";
			fileSave << Moves::GetCanCastlingBlackLong() << " ";
			fileSave << Moves::GetCanCastlingBlackShort() << " ";
			fileSave << gameOver;

		}
	}
	catch (exception err)
	{
		cout << err.what() << "\n";
	}
}

void Load()
{
	string nameOfFile;
	cout << "Input name of file:\n";
	cin >> nameOfFile;
	try
	{
		ifstream fileLoad;
		fileLoad.open(nameOfFile);
		if (fileLoad.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					fileLoad >> figure[i][j];
				}
			}
			int m;
			fileLoad >> m;
			Moves::SetMove(m);
			fileLoad >> m;
			Moves::SetEnPassent(m);
			fileLoad >> scoreWhite;
			fileLoad >> scoreBlack;
			fileLoad >> m;
			Moves::SetCanCastlingWhiteLong(m);
			fileLoad >> m;
			Moves::SetCanCastlingWhiteShort(m);
			fileLoad >> m;
			Moves::SetCanCastlingBlackLong(m);
			fileLoad >> m;
			Moves::SetCanCastlingBlackShort(m);
			fileLoad >> gameOver;
		}
	}
	catch (exception err)
	{
		cout << err.what() << "\n";
	}
}

void Castling()
{
	string s;
	cout << "White or Black?\n";
	cin >> s;
	if (s == "White")
	{
		cout << "Long or Short?\n";
		cin >> s;
		if (s == "Long")
		{
			Moves m;
			bool f = m.CastlingWhiteLong(figure);
			if (f && Moves::GetMove() == 0)
			{
				figure[0][2] = figure[0][4];
				figure[0][3] = figure[0][0];
				figure[0][4] = 0;
				figure[0][0] = 0;
				Moves::SetMove((Moves::GetMove() + 1) % 2);
			}
			else
			{
				cout << "Can't castling!";
			}
		}
		if (s == "Short")
		{
			Moves m;
			bool f = m.CastlingWhiteShort(figure);
			if (f && Moves::GetMove() == 0)
			{
				figure[0][6] = figure[0][4];
				figure[0][5] = figure[0][7];
				figure[0][4] = 0;
				figure[0][7] = 0;
				Moves::SetMove((Moves::GetMove() + 1) % 2);
			}
			else
			{
				cout << "Can't castling!";
			}
		}
	}
	if (s == "Black")
	{
		cout << "Long or Short?\n";
		cin >> s;
		if (s == "Long" && Moves::GetMove() == 1)
		{
			Moves m;
			bool f = m.CastlingBlackLong(figure);
			if (f)
			{
				figure[7][2] = figure[7][4];
				figure[7][3] = figure[7][0];
				figure[7][4] = 0;
				figure[7][0] = 0;
				Moves::SetMove((Moves::GetMove() + 1) % 2);
			}
			else
			{
				cout << "Can't castling!";
			}
		}
		if (s == "Short" && Moves::GetMove() == 1)
		{
			Moves m;
			bool f = m.CastlingBlackShort(figure);
			if (f)
			{
				figure[7][6] = figure[7][4];
				figure[7][5] = figure[7][7];
				figure[7][4] = 0;
				figure[7][7] = 0;
				Moves::SetMove((Moves::GetMove() + 1) % 2);
			}
			else
			{
				cout << "Can't castling!";
			}
		}
	}
}

void Input()
{
	string input;
	cin >> input;
	if (input == "Start")
	{
		start = true;
	}
	if (input == "Restart")
	{
		RestartGame();
		start = false;
	}
	if (input == "Save")
	{
		Save();
	}
	if (input == "Load")
	{
		Load();
		start = false;
	}
	if (input == "Castling")
	{
		Castling();
	}
	if (input == "Move")
	{

		string move;
		cin >> move;
		pos_start_x = (int)move[0] - 97;
		pos_end_x = (int)move[2] - 97;
		pos_start_y = (int)move[1] - 49;
		pos_end_y = (int)move[3] - 49;

		if (figure[pos_start_y][pos_start_x] == 1 || figure[pos_start_y][pos_start_x] == 7)
		{
			//cout << pos_end_x << " " << pos_end_y;
			LogicRook();
		}
		if (figure[pos_start_y][pos_start_x] == 3 || figure[pos_start_y][pos_start_x] == 9)
		{
			//cout << pos_end_x << " " << pos_end_y;
			LogicBishop();
		}
		if (figure[pos_start_y][pos_start_x] == 2 || figure[pos_start_y][pos_start_x] == 8)
		{
			//cout << pos_end_x << " " << pos_end_y;
			LogicKnight();
		}
		if (figure[pos_start_y][pos_start_x] == 4 || figure[pos_start_y][pos_start_x] == 10)
		{
			//cout << pos_end_x << " " << pos_end_y;
			LogicQueen();
		}
		if (figure[pos_start_y][pos_start_x] == 6 || figure[pos_start_y][pos_start_x] == 12)
		{
			//cout << pos_end_x << " " << pos_end_y;
			LogicPawn();
		}
		if (figure[pos_start_y][pos_start_x] == 5 || figure[pos_start_y][pos_start_x] == 11)
		{
			//cout << pos_end_x << " " << pos_end_y;
			LogicKing();
		}
	}
}


int main()
{
	Setup();
	while (true)
	{
		Draw();
		if (!start)
		{
			cout << "Input Start please!\n";
			Input();
			continue;
		}
		Input();
		Sleep(1000);
	}
}
