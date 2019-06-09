#ifndef _ENEMY_H_
# define _ENEMY_H_

class Enemy{
    public:
        Enemy(WINDOW * win,int y, int x, char c);

        void mvleft();
        void mvright();
        int getmv();
        void display();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW * curwin;
};  

Enemy::Enemy(WINDOW * win, int y, int x, char c)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void Enemy::mvleft()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
}

void Enemy::mvright()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax - 2)
        xLoc = xMax-2;
}

int Enemy::getmv(){
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Enemy::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
}

#endif