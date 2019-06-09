#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "enemy.h"
using namespace std;

void Bord(int y)
{
    WINDOW * playwin = newwin(20, 50, (y/2)-10, 10);
    box(playwin,0, 0);
    refresh();
    wrefresh(playwin);

     keypad(playwin, true);
     return ;
}

int main()
{   
    //NCURSES START
    initscr();
    noecho();
    cbreak();

    //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create window for our input
    WINDOW *playwin = newwin(20, 50, (yMax/2)-10, 10);
    box(playwin,0, 0);
    refresh();
    wrefresh(playwin);

    keypad(playwin, true);

    string choices[3] = {"Start Game", "Help", "Exit"};
    int choice;
    int highlight = 0;

    while(1){
        for(int i = 0; i < 3; i++)
        {
            if (i == highlight)
            wattron(playwin, A_REVERSE);
            mvwprintw(playwin, i+1, 1, choices[i].c_str());
            wattroff(playwin, A_REVERSE);
        }
        choice = wgetch(playwin);
        
        switch(choice)
        {
            case KEY_UP:
            highlight--;
            if(highlight == -1){
                highlight = 0;
            }
                break;
            case KEY_DOWN:
            highlight++;
            if(highlight == 3){
                highlight = 2;
            }
                break;
            default:
                ;
        }
        if(choice == 10)
        {
            break;
        }
    }

    wrefresh(playwin);

    Player * p = new Player(playwin, 1 , 1 , 'p');
    while(p->getmv()!='x')
    {
        p->display();
        wrefresh(playwin);
    }

    // makes it so that we can use arrow keys
    keypad(playwin, true);

    
    //make sure program waits before exiting
    getch();
    refresh(); 
    endwin();

    return 0;
}