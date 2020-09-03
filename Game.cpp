#include<windows.h>
#include<stdio.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship()
{
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("        ");
}

int main()
{
	char ch = ' ';
	int x = 10, y = 5;
	gotoxy(x, y);
	draw_ship();
	do {
			ch = _getch();
			if (ch == 'a' && x > 0) 
			{ 
				erase_ship(x, y);
				gotoxy(--x, y);
				draw_ship();

			}
			if (ch == 'd' && x < 80) 
			{ 
				erase_ship(x, y);
				gotoxy(++x, y);
				draw_ship();
			}
			if (ch == 'w' && y > 0)
			{
				erase_ship(x, y);
				gotoxy(x, --y);
				draw_ship();
			}
			if (ch == 's' && y < 20)
			{
				erase_ship(x, y);
				gotoxy(x, ++y);
				draw_ship();
			}

			fflush(stdin);
		Sleep(100);
	} while (ch != 'x');

	return 0;
}