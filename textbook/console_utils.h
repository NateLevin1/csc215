#include <termios.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

void gotoxy(int x, int y) {
  printf("%c[%d;%df",0x1B, y, x);
}

void clrscr(void) {
  fprintf(stdout, "\033[2J\033[0;0f");
  fflush(stdout);
}

void textcolor(int attr, int fg, int bg) {   
  printf("%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
}

// Taken from https://github.com/zoelabbb/conio.h
int setEchoMode(bool enable) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    if (enable)
        newt.c_lflag |= ECHO;
    else
        newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

// Taken from https://github.com/zoelabbb/conio.h
int getch() {
    return setEchoMode(false);
}

// Taken from https://github.com/zoelabbb/conio.h
int getche() {
    return setEchoMode(true);
}