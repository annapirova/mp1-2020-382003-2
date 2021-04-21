#include <locale>
#include <iostream>
#include <random>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class LAB
{
	int **A;
	int N, M;
	int *px;
	int *py;      // координаты €чеек, вход€щих  путь
	int len;                       // длина пути

public:
	const int WALL = -1;
	const int SPACE = -2;
	LAB();
	LAB(int n = 1, int m = 1);
	void print();
	void print2();
	int randNum(int min, int max)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(min, max);
		return dist(mt);
	}	
	void gran();
	void DIVISION(int x, int y, int width, int height, int Mwidth, int Mheight);
	bool ALGORITHM(int ax, int ay, int bx, int by);
	~LAB();
};

int main() 
{
	srand(time(NULL));
	int a = 12;
	int b = 17;
	cout << "Put your brain border" << endl;
	cin >> a;
	cin >> b;
	LAB labirint(a+2, b+2);
	labirint.gran();
	//labirint.print();
	labirint.DIVISION(1, 1, a, b, a, b);
	cout << endl;
	//labirint.print();
	labirint.ALGORITHM(1, 1, a, b);
	cout << endl;
	labirint.print2();
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	system("pause");
	return 0;
}

LAB::LAB()
{
	N = 5;
	M = 5;
	len = 0;
	int R = M *N;
	px = new int[R];
	py = new int[R];
	for (int i = 0; i < R; i++)
	{
		px[i] = 0;
		py[i] = 0;
	}
	A = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}
}

LAB::LAB(int n, int m)
{
	N = n;
	M = m;
	len = 0;
	int R = (N) * (M);
	px = new int[R];
	py = new int[R];

	A = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}
	for (int i = 0; i < R; i++)
	{
		px[i]=0;
		py[i] = 0;
	}
}

void LAB::print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 0));
			if (A[i][j] == WALL) cout << "#"<<" ";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 0));
			if (A[i][j] == SPACE) cout<< "  ";
		}
		cout << endl;
	}
}

void LAB::print2()
{
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	for (int j = 0; j < ((N-2)*(M-2)); j++) if ((px[j] > 0) && (py[j] > 0)) cout << py[j] << "," << px[j] << endl;
	//if((px[j] > 0) && (py[j] > 0))
}

void LAB::gran()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = WALL;
		}
	}

	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < M-1; j++)
		{
		 // if ((i % 2 != 0)&&(j % 2 !=0)) A[i][j] = 0; //создаЄт поле из клеток
			A[i][j] = SPACE; //оставл€ет пустое поле a*b 
		}
	}
}

void LAB::DIVISION(int x, int y, int width, int height, int Mwidth, int Mheight)
	{
		bool ORIENTATION = true;
		int random1 = randNum(1, 2);
			int random2 = randNum(1, 2);
	//if (width>33) random1= randNum(1, 2);
	//if (height>33) random2 = randNum(1, 2);

		if ((width <= random1) || (height <= random2)) 
		{
			return;
		}
		if (width > height)
		{
			ORIENTATION = false;
		}
		if (ORIENTATION) 
		{
			int Startx = x;
			int Starty = y + height / 2; 

			for (int i = 0; i < width; i++) 
			{
				A[Startx + i][Starty] = WALL;
			}
			
			int HoleCount = 0;
			if (Startx - 1 > 0 && A[Startx - 1][Starty] == SPACE)
			{
				HoleCount++;
				A[Startx][Starty] = SPACE;
			}

			if (Startx - 1 > 0 && A[Startx + 1][Starty] == SPACE)
			{
				HoleCount++;
				A[Startx][Starty] = SPACE;
			}

			if (Startx - 1 > 0 && A[Startx][Starty-1] == SPACE)
			{
				HoleCount++;
				A[Startx][Starty] = SPACE;
			}
			if (Startx - 1 > 0 && A[Startx][Starty + 1] == SPACE)
			{
				HoleCount++;
				A[Startx][Starty] = SPACE;
			}
	//print();

			if (Startx + width < Mwidth && A[Startx + width][Starty] == SPACE)
			{
				HoleCount++;
				A[Startx + (width - 1)][Starty] = SPACE;
			}

			/*if (Startx + width < Mwidth && A[Startx + width][Starty+1] == SPACE)
			{
				HoleCount++;
				A[Startx + (width - 1)][Starty] = SPACE;
			}*/ //Ћишн€€ догадка

			/*if (Startx + width < Mwidth && A[Startx + width][Starty - 1] == SPACE)
			{
				HoleCount++;
				A[Startx + (width - 1)][Starty] = SPACE;
			}*/ //Ћишн€€ догадка

			if (HoleCount == 0)
			{
				int Holex = Startx + randNum(0, width-1); //rand() % width;
				int Holey = Starty;

				A[Holex][Holey] = SPACE; 
			}

			DIVISION(x, y, width, height / 2, Mwidth, Mheight); 

			if (height % 2 == 0)
			{
				DIVISION(x, Starty + 1, width, (height / 2) - 1, Mwidth, Mheight);
			}
			else
			{
				DIVISION(x, Starty + 1, width, (height / 2), Mwidth, Mheight);
			}
		}
		else 	 
		{
			int Startx = x + width / 2;
			int Starty = y;

			for (int i = 0; i < height; i++)
			{
				A[Startx][Starty + i] = WALL;
			}

			int VHoleCount = 0;
		if (Starty - 1 > 0 && A[Startx][Starty - 1] == SPACE)
			{
				VHoleCount++;
				A[Startx][Starty] = SPACE;
			}

		if (Starty - 1 > 0 && A[Startx][Starty + 1] == SPACE)
		{
			VHoleCount++;
			A[Startx][Starty] = SPACE;
		}
		if (Starty - 1 > 0 && A[Startx-1][Starty] == SPACE)
		{
			VHoleCount++;
			A[Startx][Starty] = SPACE;
		}
		if (Starty - 1 > 0 && A[Startx+1][Starty] == SPACE)
		{
			VHoleCount++;
			A[Startx][Starty] = SPACE;
		}
	//	print();
	

		if (Starty + height < Mheight && A[Startx][Starty + height] == SPACE)
			{
				VHoleCount++;
				A[Startx][Starty + (height - 1)] = SPACE;
			}
		/*if (Starty + height < Mheight && A[Startx-1][Starty + height] == SPACE)
		{
			VHoleCount++;
			A[Startx][Starty + (height - 1)] = SPACE;
		}*/ //“≈—“

		/*if (Starty + height < Mheight && A[Startx+1][Starty + height] == SPACE)
		{
			VHoleCount++;
			A[Startx][Starty + (height - 1)] = SPACE;
		}*/ //“≈—“

		if (VHoleCount == 0)
			{
				int Holex = Startx;
				int Holey = Starty + randNum(0, height-1); //rand() % height;
				A[Holex][Holey] = SPACE;
			}

			DIVISION(x, y, width / 2, height, Mwidth, Mheight); 
			if (width % 2 == 0)
			{
				DIVISION(Startx + 1, y, (width / 2) - 1, height, Mwidth, Mheight);
			}	
			else
			{
				DIVISION(Startx + 1, y, (width / 2), height, Mwidth, Mheight);
			}

		}
		A[Mwidth][Mheight] = -2;
	}

bool LAB:: ALGORITHM(int ax, int ay, int bx, int by)   // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
	{
		int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
		int dy[4] = { 0, 1, 0, -1 };   // справа, снизу, слева и сверху
		int d, x, y, k;
		bool stop;

		if (A[ay][ax] == WALL || A[by][bx] == WALL) return false;  // €чейка (ax, ay) или (bx, by) - стена

		// распространение волны
		d = 0;
		A[ay][ax] = 0;            // стартова€ €чейка помечена 0
		do {
			stop = true;               // предполагаем, что все свободные клетки уже помечены
			for (y = 0; y < N; ++y)
				for (x = 0; x < M; ++x)
					if (A[y][x] == d)                         // €чейка (x, y) помечена числом d
					{
						for (k = 0; k < 4; ++k)                    // проходим по всем непомеченным сосед€м
						{
							int iy = y + dy[k], ix = x + dx[k];
							if ((iy >= 0) && (iy <N) && (ix >= 0) && (ix < M) && (A[iy][ix] == SPACE))
							{
								stop = false;              // найдены непомеченные клетки
								A[iy][ix] = d + 1;      // распростран€ем волну
							}
						}
					}
			d++;
		} while (!stop && A[by][bx] == SPACE);

		if (A[by][bx] == SPACE) return false;  // путь не найден

		// восстановление пути
		len = A[by][bx];            // длина кратчайшего пути из (ax, ay) в (bx, by)
		x = bx;
		y = by;
		d = len;
		while (d > 0)
		{
			px[d] = x;
			py[d] = y;                   // записываем €чейку (x, y) в путь
			d--;
			for (k = 0; k < 4; ++k)
			{
				int iy = y + dy[k], ix = x + dx[k];
				if ((iy >= 0 )&& (iy <N )&& (ix >= 0 )&& (ix < M )&& (A[iy][ix] == d))
				{
					x = x + dx[k];
					y = y + dy[k];           // переходим в €чейку, котора€ на 1 ближе к старту
					break;
				}
			}
		}
		px[0] = ax;
		py[0] = ay;                    
		return true;
	}

LAB::~LAB()
{
	for (int i = 0; i < N; i++) {
		delete[] A[i];
	}
	delete[] A;
}
