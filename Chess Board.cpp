#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>

/*int setpiece(int x1, int y1, int x2, int y2){
    readimagefile("b_king.gif",x1+20,y1+20,x2-20,y2-20);
    readimagefile("b_queen.gif",x1+10,y1+10,x2-30,y2-30);
    readimagefile("b_pawn.gif",x1+10,y1+10,x2-30,y2-30);
    readimagefile("w_king.gif",x1+10,y1+10,x2-30,y2-30);
}*/

// Driver Code
int main()
{

    char board[6][5] = {
                        {'K', ' ', ' ',' ',' '},
                        {' ', ' ', ' ',' ','P'},
                        {' ', ' ', ' ',' ',' '},
                        {' ', ' ', ' ','R',' '},
                        {' ', ' ', ' ',' ',' '},
                        {' ', 'q', ' ',' ',' '}
                    };

	// Auto detection
	int gr = DETECT, gm;
	int r, c, x = 100, y = 100, black = 0;
	int size = 100;
    initwindow(800,800,"MENU",0,0,false,true);
	// Initialize graphics mode by passing
	// three arguments to initgraph function

	// &gdriver is the address of gdriver
	// variable, &gmode is the address of
	// gmode and "C:\\Turboc3\\BGI" is the
	// directory path where BGI files are stored
//	initgraph(&gr, &gm, "");

//    setpiece(x,y,x+size,y+size);
//    scanf("%d");

	// Iterate over 6rows
	for (r = 0; r < 6; r++) {

		// iterate over 5cols
		for (c = 0; c < 5; c++) {

			// If current block is to
			// color as black
			if (black == 0) {

				// set next color as white
				setcolor(WHITE);

				// sets the current fill
				// pattern and fill color
				// for black boxes
				setfillstyle(SOLID_FILL, DARKGRAY);

				// creating rectangle
				// with length and breadth
				// with size 30
				rectangle(x, y, x + size, y + size);

				// Fill an enclosed area
				floodfill(x + 1, y + 1, WHITE);

				// Set black to true
				black = 1;
			}

			// If current block is to
			// color as white
			else {
				setcolor(WHITE);

				// sets the current fill
				// pattern and fill color
				// for whitw boxes
				setfillstyle(SOLID_FILL, WHITE);

				// creating rectangle
				// with length and breadth
				// with size 30
				rectangle(x, y, x + size, y + size);

				// Fill an enclosed area
				floodfill(x + 1, y + 1, WHITE);

				// Set black to false
				black = 0;
			}
         /*   if(board[r][c]=='K')
                setpiece(x,y,x+size,y+size);

            if(board[r][c]=='Q')
                setpiece(x,y,x+size,y+size);

                 if(board[r][c]=='P')
                setpiece(x,y,x+size,y+size);

                  if(board[r][c]=='R')
                setpiece(x,y,x+size,y+size);*/

			// Increment for next row
			x = x + size;

			// delay function under library
			// "dos.h" for holding the
			// function for some time
			delay(30);
		}
//		if (black == 0)
//			black = 1;
//		else
//			black = 0;

		delay(30);
		x = size;
		y = size + y;
	}

	// getch is used to hold the output screen
	// and wait until user gives any type of
	// input in turbo c
	getch();

	// close graph function is used to exit
	// from the graphics screen
	closegraph();
	return 0;
}
