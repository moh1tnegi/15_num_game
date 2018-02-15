#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

#define swap(x, y) x+=y;y=x-y;x-=y

int getkey() {
	int ch;
	ch = getch();
	if(ch == 0) {
		ch = getch();
		return ch;
	}
	return ch;
}

int check(int *a) {
    int i, j;
    for(i=1; i<15; i++) {
        if(*(a+i*sizeof(int)) < *(a+i*sizeof(int))) return 0;
    }
    return 1;
}
int main() {
	int i, j, totalMoves=0, x=3, y=3;
	int puzzle[4][4] = {
						1,  4, 15,  7,
						8, 10,  2, 11,
					   14,  3,  6, 13,
					   12,  9,  5,  0};
	while(1) {
        	system("cls");
        	for(i=0; i<4; i++) {
        		for(j=0; j<4; j++) {
        	        if(!puzzle[i][j]) {
                    	printf("   ");
                    	continue;
                	}
	        		printf("%2d ", puzzle[i][j]);
        		}
        		printf("\n");
        	}
	        if(puzzle[3][0]==13&&puzzle[3][1]==14&&puzzle[3][2]==15)
        	if(check(&puzzle[0][0])) {
	            printf("\nCongratulations... Puzzle Completed!!!\n");
        	    printf("Total Moves: %d\n", totalMoves);
	            printf("Press any key...");getch();break;
	        }
        	printf("\nTotal Moves: %d", totalMoves);
        	i--;
		j--;
        	int tmp=getkey();//up 72 dw 80 lt 75 rt 77
	        if(tmp==72) {
        		if(y==3) continue;
        		swap(puzzle[y][x], puzzle[y+1][x]);
	        	y++;
        	}
	        else if(tmp==80) {
        		if(y==0) continue;
        		swap(puzzle[y][x], puzzle[y-1][x]);
	        	y--;
        	}
        	else if(tmp==75) {
        		if(x==3) continue;
	        	swap(puzzle[y][x], puzzle[y][x+1]);
        		x++;
	        }
        	else if(tmp==77) {
        		if(x==0) continue;
	        	swap(puzzle[y][x], puzzle[y][x-1]);
        		x--;
        	}
        	totalMoves++;
	}
    return 0;
}
