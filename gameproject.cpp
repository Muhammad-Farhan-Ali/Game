#include<iostream>
#include<windows.h>

using namespace std;

void gotoxy(int x,int y);
char getCharAtxy(short int x,short int y);

void printmaze();
void printplayerright();
void printplayerleft();
void eraseplayer();

void moveplayerright();
void moveplayerleft();

void moveplayerdown();
void moveplayerup();

void player();

void print_enemy1();
void erase_enemy1();
void e1state();
void move_enemy1();

void print_enemy2();
void erase_enemy2();
void e2state();
void move_enemy2();

void print_enemy3();
void shoot_enemy3();

void gamestate(int state);
void checkstate();
void checkscore();

int px=7,py=3;                          //for player movement 
int e1x=63,e1y=9;                       //for enemy 1 movement 
int e2x=63,e2y=13;                      //for enemy 2 movement 

int e3x=28,e3y=28;

int position=0;
int e1position=0;
int e2position=0;

int score=0;

int main()
{

    printmaze();
    printplayerright();
    print_enemy1();
    print_enemy2();
    print_enemy3();

    while(true)
    {
        player();
        move_enemy1();
        move_enemy2();
        shoot_enemy3();
        checkscore();
    }

        
    return 0;
}

void gotoxy(int x,int y)
{
    COORD coordinates;
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
char getCharAtxy(short int x,short int y)
{
    CHAR_INFO ci;
    COORD xy = {0,0};
    SMALL_RECT rect = {x,y,x,y};
    COORD coordBufSize;
    coordBufSize.X=1;
    coordBufSize.Y=1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),&ci,coordBufSize,xy,&rect)?ci.Char.AsciiChar : ' ';
}

void gamestate(int state)           //for removing % barriers 
{
    if(state==1)                    //removes first % barrier
    {
    gotoxy(53,7);
    cout<<" ";
    gotoxy(53,8);
    cout<<" ";
    gotoxy(53,9);
    cout<<" ";
    gotoxy(53,10);
    cout<<" ";
    gotoxy(53,11);
    cout<<" ";
    score+=500;
    }
    
    if(state==2)                     //removes second % barrier
    {
    gotoxy(106,19);
    cout<<" ";
    gotoxy(106,20);                
    cout<<" ";
    gotoxy(106,21);
    cout<<" ";
    gotoxy(106,22);
    cout<<" ";
    gotoxy(106,23);
    cout<<" ";
    score+=500;
    }

    if(state==3)                     //removes third % barrier
    {
    gotoxy(47,30);
    cout<<"             ";
    score+=1000;
    }

    if(state==4)                     //removes fourth % barrier
    {
    gotoxy(78,31);
    cout<<" ";
    gotoxy(78,32);                
    cout<<" ";
    gotoxy(78,33);
    cout<<" ";
    gotoxy(78,34);
    cout<<" ";
    gotoxy(78,35);
    cout<<" ";
    score+=2000;
    }

}
void checkstate()                   // for checking state of game i.e gamestate
{
    if(((getCharAtxy(px+7,py) == '@') || (getCharAtxy(px+7,py+1) == '@') || (getCharAtxy(px+7,py+2) == '@')) 
    || ((getCharAtxy(px-1,py) == '@') || (getCharAtxy(px-1,py+1) == '@') || (getCharAtxy(px-1,py+2) == '@')))
        {
            if(py<6)                     //for first @ in maze
            {
            gamestate(1);
            }
            else if(py>6 && py<21)       //for second @ in maze
            {
            gamestate(2);
            } 
            else if(py>21 && py<30)       //for third @ in maze
            {
            gamestate(3);
            } 
            else if(py>30 && py<37)       //for forth @ in maze
            {
            gamestate(4);
            } 

        }
}
void checkscore()
{
    gotoxy(0,37);
    cout<<"Score:"<<score;
}


void printmaze()
{
system("cls");
cout<<"|#########################################################################################################################|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                               @       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#######################################             #####################################################################|"<<endl;
cout<<"|#                                                   %                                                                   #|"<<endl;
cout<<"|#                                                   %                                                                   #|"<<endl;
cout<<"|#                                                   %                                                                   #|"<<endl;
cout<<"|#                                                   %                                                                   #|"<<endl;
cout<<"|#                                                   %                                                                   #|"<<endl;
cout<<"|###########################################################################################################             #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                @                                                                                                      #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#             ############################################             ##################################################|"<<endl;
cout<<"|#                                                                                                        %              #|"<<endl;
cout<<"|#                                                                                                        %              #|"<<endl;
cout<<"|#                                                                                                        %              #|"<<endl;
cout<<"|#                                                                                                        %              #|"<<endl;
cout<<"|#                                                                                                        %              #|"<<endl;
cout<<"|##########################################################################################################              #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#   @                                                                                                                   #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|#                                                                                                                       #|"<<endl;
cout<<"|##############################################%%%%%%%%%%%%%##############################################################|"<<endl;
cout<<"|#                                                                            %                                          #|"<<endl;
cout<<"|#                                                                            %                               ____       #|"<<endl;
cout<<"|#   @                                                                        %                              |    |      #|"<<endl;
cout<<"|#                                                                            %                              |.   |      #|"<<endl;
cout<<"|#                                                                            %                              |    |      #|"<<endl;
cout<<"|#########################################################################################################################|"<<endl;
}
void printplayerright()
{
    gotoxy(px,py);
    cout<<" ('') /"<<endl;
    gotoxy(px,py+1);
    cout<<" /__\\/"<<endl;
    gotoxy(px,py+2);
    cout<<" \\/\\/"<<endl;
}
void printplayerleft()
{
    gotoxy(px,py);
    cout<<"\\ ('') "<<endl;
    gotoxy(px,py+1);
    cout<<" \\/__\\"<<endl;
    gotoxy(px,py+2);
    cout<<"  \\/\\/"<<endl;
}
void eraseplayer()
{
    gotoxy(px,py);
    cout<<"       "<<endl;
    gotoxy(px,py+1);
    cout<<"       "<<endl;
    gotoxy(px,py+2);
    cout<<"       "<<endl;
}

void moveplayerright()
{
    if(((getCharAtxy(px+7,py) == ' ') && (getCharAtxy(px+7,py+1) == ' ') && (getCharAtxy(px+7,py+2) == ' '))
    || (getCharAtxy(px+7,py) == '@') || (getCharAtxy(px+7,py+1) == '@') || (getCharAtxy(px+7,py+2) == '@'))
    {
        checkstate();
        eraseplayer();
        px=px+1;
        printplayerright();
        Sleep(1);
        position=0;
    }
}
void moveplayerleft()
{
    if(((getCharAtxy(px-1,py) == ' ') && (getCharAtxy(px-1,py+1) == ' ') && (getCharAtxy(px-1,py+2) == ' '))
    || ((getCharAtxy(px-1,py) == '@') || (getCharAtxy(px-1,py+1) == '@') || (getCharAtxy(px-1,py+2) == '@')))
    {
        checkstate();
        eraseplayer();
        px=px-1;
        printplayerleft();
        Sleep(1);
        position++;
    }
}

void moveplayerdown()
{
    if(position==0)
    {
        if((getCharAtxy(px,py+3)==' ') && (getCharAtxy(px+6,py+3)==' '))
        {
            eraseplayer();
            py=py+1;
            printplayerright();
            Sleep(50);
        }
    }
    else if(position!=0)
    {
        if((getCharAtxy(px,py+3)==' ') && (getCharAtxy(px+6,py+3)==' '))
        {
            eraseplayer();
            py=py+1;
            Sleep(50);
            printplayerleft();
        }
    }
}
void moveplayerup()
{
    if(position==0)
    {
        if((getCharAtxy(px,py-1)==' ') && (getCharAtxy(px+6,py-1)==' '))
        {
            eraseplayer();
            py=py-1;
            printplayerright();
            Sleep(50);
        }
    }
    else if(position!=0)
    {
        if((getCharAtxy(px,py-1)==' ') && (getCharAtxy(px+6,py-1)==' '))
        {
            eraseplayer();
            py=py-1;
            Sleep(50);
            printplayerleft();
        }
    }
}
void player()
{    
    if(GetAsyncKeyState(VK_RIGHT))
    {
        moveplayerright();
    }
    else if(GetAsyncKeyState(VK_LEFT))
    {
        moveplayerleft();
    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        moveplayerdown();
    }
    else if(GetAsyncKeyState(VK_UP))
    {
        moveplayerup();
    }
}


void print_enemy1()
{
    gotoxy(e1x,e1y);
    cout<<"(00) "<<endl;
    gotoxy(e1x,e1y+1);
    cout<<"/__\\"<<endl;
    gotoxy(e1x,e1y+2);
    cout<<"|  | "<<endl;
}
void erase_enemy1()
{
    gotoxy(e1x,e1y);
    cout<<"     "<<endl;
    gotoxy(e1x,e1y+1);
    cout<<"     "<<endl;
    gotoxy(e1x,e1y+2);
    cout<<"     "<<endl;
}
void e1state()
{
    if(getCharAtxy(e1x+5,e1y)=='#')
    {
        e1position++;
    }
    else if((getCharAtxy(e1x-1,e1y)=='#')||(getCharAtxy(e1x-1,e1y)=='%'))
    {
        e1position=0;
    }
}
void move_enemy1()
{
    e1state();
    if((getCharAtxy(e1x+5,e1y)==' ') && e1position==0)
    {
        erase_enemy1();
        e1x=e1x+1;
        print_enemy1();
        Sleep(1);
    }
    else if(getCharAtxy(e1x-1,e1y)==' ' && e1position!=0)
    {
        erase_enemy1();
        e1x=e1x-1;
        print_enemy1();
        Sleep(1);
    }
}


void print_enemy2()
{
    gotoxy(e2x,e2y);
    cout<<"(00) "<<endl;
    gotoxy(e2x,e2y+1);
    cout<<"/__\\ "<<endl;
    gotoxy(e2x,e2y+2);
    cout<<"|  | "<<endl;
}
void erase_enemy2()
{
    gotoxy(e2x,e2y);
    cout<<"     "<<endl;
    gotoxy(e2x,e2y+1);
    cout<<"     "<<endl;
    gotoxy(e2x,e2y+2);
    cout<<"     "<<endl;
}
void e2state()
{
    if(getCharAtxy(e2x,e2y-1)=='#')
    {
        e2position=0;
    }
    else if(getCharAtxy(e2x,e2y+4)=='#')
    {
        e2position++;
    }
}
void move_enemy2()
{
    e2state();
    if(((getCharAtxy(e2x,e2y+4)==' ') && (getCharAtxy(e2x+5,e2y+4)==' ')) && e2position==0)
    {
        erase_enemy2();
        e2y=e2y+1;
        print_enemy2();
        Sleep(20);
    }
    else if(((getCharAtxy(e2x,e2y-1)==' ') && (getCharAtxy(e2x+5,e2y-1)==' ')) && e2position!=0)
    {
        erase_enemy2();
        e2y=e2y-1;
        print_enemy2();
        Sleep(20);
    }
}

void print_enemy3()
{
    gotoxy(20,28);
    cout<<"/  \\--"<<endl;
    gotoxy(20,29);
    cout<<"|___|  "<<endl;
}
void shoot_enemy3()
{
    gotoxy(e3x,e3y);
    cout<<"  ";
    e3x=e3x+1;
    if(e3x==119)
    {
        e3x=28;
    }
    gotoxy(e3x,e3y);
    cout<<"=-";
    Sleep(1);
    
}



