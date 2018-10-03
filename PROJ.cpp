#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node
{
    int x,y;
    node *next;
    node *down;
};
node *start = NULL, *end;
node *gstart, *rstart, *bstart, *ystart;        //colour pin starts
node *gend, *rend, *bend, *yend;                //colour pin enters special
node *gend2, *rend2, *bend2, *yend2;            //colour pin reaches END

node *gstack, *rstack, *bstack, *ystack;
node *gstackend, *rstackend, *bstackend, *ystackend;

node *red[4], *green[4], *blue[4], *yellow[4];
int g=0,r=0,b=0,yel=0;
int gg=0,rr=0,bb=0,yy=0;
//--------------------------------------------------------------- STACKS
void makegstack()
{
    ifstream fi;
    int x,y;
    fi.open("gstack.txt");
    node *temp;
    while(!fi.eof())
    {
        g++;
        temp = new node;
        fi>>x>>y;
        temp->next = NULL;
        temp->down = NULL;
        temp->x = x;
        temp->y = y;
        setlinestyle(SOLID_LINE,1,3);
        setcolor(GREEN);
        if(gstack)
        {
            gstackend->next = temp;
            gstackend = temp;
        }
        else
        {
            gstack = temp;
            gstackend = temp;
        }
    }
}
void makerstack()
{
    ifstream fi;
    int x,y;
    fi.open("rstack.txt");
    node *temp;
    while(!fi.eof())
    {
        r++;
        temp = new node;
        fi>>x>>y;
        temp->next = NULL;
        temp->down = NULL;
        temp->x = x;
        temp->y = y;
        setlinestyle(SOLID_LINE,1,3);
        setcolor(LIGHTRED);
        if(rstack)
        {
            rstackend->next = temp;
            rstackend = temp;
        }
        else
        {
            rstack = temp;
            rstackend = temp;
        }
    }
}
void makebstack()
{
    ifstream fi;
    int x,y;
    fi.open("bstack.txt");
    node *temp;
    while(!fi.eof())
    {
        b++;
        temp = new node;
        fi>>x>>y;
        temp->next = NULL;
        temp->down = NULL;
        temp->x = x;
        temp->y = y;
        setlinestyle(SOLID_LINE,1,3);
        setcolor(LIGHTCYAN);
        if(bstack)
        {
            bstackend->next = temp;
            bstackend = temp;
        }
        else
        {
            bstack = temp;
            bstackend = temp;
        }
    }
}
void makeystack()
{
    ifstream fi;
    int x,y;
    fi.open("ystack.txt");
    node *temp;
    while(!fi.eof())
    {
        yel++;
        temp = new node;
        fi>>x>>y;
        temp->next = NULL;
        temp->down = NULL;
        temp->x = x;
        temp->y = y;
        setlinestyle(SOLID_LINE,1,3);
        setcolor(BROWN);
        if(ystack)
        {
            ystackend->next = temp;
            ystackend = temp;
        }
        else
        {
            ystack = temp;
            ystackend = temp;
        }
    }
}
//--------------------------------------------------------------- MAIN LIST
void newmainnode(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    temp->down = NULL;
    if(start)
    {
        end->next = temp;
        end = temp;
    }
    else
    {
        start = temp;
        end = temp;
    }
}

void newnodeg(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    temp->down = NULL;
    if(gend->down)
    {
        gend2->next = temp;
        gend2 = temp;
    }
    else
    {
        gend->down = temp;
        gend2 = temp;
    }
}

void newnoder(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    temp->down = NULL;
    if(rend->down)
    {
        rend2->next = temp;
        rend2 = temp;
    }
    else
    {
        rend->down = temp;
        rend2 = temp;
    }
}
void newnodeb(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    temp->down = NULL;
    if(bend->down)
    {
        bend2->next = temp;
        bend2 = temp;
    }
    else
    {
        bend->down = temp;
        bend2 = temp;
    }
}
void newnodey(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    temp->down = NULL;
    if(yend->down)
    {
        yend2->next = temp;
        yend2 = temp;
    }
    else
    {
        yend->down = temp;
        yend2 = temp;
    }
}

void create()
{
    int i;
    ifstream fi;
    fi.open("abc.txt");
    int x,y;
    while(!fi.eof())
    {
        fi>>x>>y;
        newmainnode(x,y);
    }
    fi.close();
    end->next = start;
    gstart = start;
    rstart = gstart;
    for(i=0;i<13;i++)
    {
        rstart = rstart->next;
    }
    bstart = rstart;
    for(i=0;i<13;i++)
    {
        bstart = bstart->next;
    }
    ystart = bstart;
    for(i=0;i<13;i++)
    {
        ystart = ystart->next;
    }

    rend = gstart;
    for(i=0;i<11;i++)
    {
        rend = rend->next;
    }
    bend = rend;
    for(i=0;i<13;i++)
    {
        bend = bend->next;
    }
    yend = bend;
    for(i=0;i<13;i++)
    {
        yend = yend->next;
    }
    gend = yend;
    for(i=0;i<13;i++)
    {
        gend = gend->next;
    }

    fi.open("bbc.txt");
    for(i=0;i<5;i++)
    {
        fi>>x>>y;
        newnodeg(x,y);
    }for(i=0;i<5;i++)
    {
        fi>>x>>y;
        newnoder(x,y);
    }for(i=0;i<5;i++)
    {
        fi>>x>>y;
        newnodeb(x,y);
    }for(i=0;i<5;i++)
    {
        fi>>x>>y;
        newnodey(x,y);
    }
    fi.close();

}



//------------------------------------------------------------------printing board

void printboard()
{
	int i;

	setcolor(LIGHTGREEN);
	setfillstyle(1,WHITE);

	int blow = 20, bhigh = 450;
	rectangle(blow,blow,bhigh,bhigh); //main board
	floodfill(blow+1,blow+1,LIGHTGREEN);

	setcolor(BLACK);

	int clow = ((bhigh+blow)/2)-40, chigh = ((bhigh+blow)/2)+40;
	rectangle(clow,clow,chigh,chigh); //center box
	setfillstyle(1,MAGENTA);
	floodfill(clow+1,clow+1,BLACK);

	// ---- side waale boxes

	//left
	setfillstyle(1,LIGHTGREEN);
	rectangle(blow+(clow-blow)/6,clow+(chigh-clow)/3,clow,chigh-(chigh-clow)/3);
	floodfill(blow+(clow-blow)/6+1,clow+(chigh-clow)/3+1,BLACK);
	//right
	setfillstyle(1,BLUE);
	rectangle(chigh,clow+(chigh-clow)/3,bhigh-(bhigh-chigh)/6,chigh-(chigh-clow)/3);
	floodfill(chigh+1,clow+(chigh-clow)/3+1,BLACK);
	//up
	setfillstyle(1,RED);
	rectangle(clow+(chigh-clow)/3,blow+(clow-blow)/6,chigh-(chigh-clow)/3,clow);
	floodfill(clow+(chigh-clow)/3+1,blow+(clow-blow)/6+1,BLACK);
	//down
	setfillstyle(1,YELLOW);
	rectangle(clow+(chigh-clow)/3,chigh,chigh-(chigh-clow)/3,bhigh-(bhigh-chigh)/6);
	floodfill(clow+(chigh-clow)/3 +1,chigh +1,BLACK);

	//------------------TRACK

	for(i=0;i<4;i++)
	{        //left
	line(blow,clow+i*(chigh-clow)/3,clow,clow+i*(chigh-clow)/3);
	}

	for(i=0;i<4;i++)
	{        //right
	line(chigh,clow+i*(chigh-clow)/3,bhigh,clow+i*(chigh-clow)/3);
	}


	for(i=0;i<4;i++)
	{        //up
	line(clow+i*(chigh-clow)/3,blow,clow+i*(chigh-clow)/3,clow);
	}

	for(i=0;i<4;i++)
	{        //down
	line(clow+i*(chigh-clow)/3,chigh,clow+i*(chigh-clow)/3,bhigh);
	}

	//--- choti lines

	for(i=0;i<=6;i++)
	{                //left side
	line(blow+i*(clow-blow)/6,clow,blow+i*(clow-blow)/6,chigh);
	}
	setfillstyle(1,LIGHTGREEN);
	floodfill(blow+(clow-blow)/6+1,clow+1,BLACK);

	for(i=0;i<=6;i++)
	{                //right side
	line(chigh+i*(bhigh-chigh)/6,clow,chigh+i*(bhigh-chigh)/6,chigh);
	}
	setfillstyle(1,BLUE);
	floodfill(chigh+4*(bhigh-chigh)/6+1,chigh-1,BLACK);

	for(i=0;i<=6;i++)
	{                //upper side
	line(clow,blow+i*(clow-blow)/6,chigh,blow+i*(clow-blow)/6);
	}
	setfillstyle(1,RED);
	floodfill(chigh-1,blow+(clow-blow)/6+1,BLACK);

	for(i=0;i<=6;i++)
	{                //lower side
	line(clow,chigh+i*(bhigh-chigh)/6,chigh,chigh+i*(bhigh-chigh)/6);
	}
	setfillstyle(1,YELLOW);
	floodfill(clow+1,chigh+4*(bhigh-chigh)/6+1,BLACK);

	//--------------TRACK ENDS

	//---------- BIG COLOUR BOXES

	// green box
	setfillstyle(1,LIGHTGREEN);
	floodfill(blow+1,blow+1,BLACK);

	// red box
	setfillstyle(1,RED);
	floodfill(bhigh-1,blow+1,BLACK);


	// blue box
	setfillstyle(1,BLUE);
	floodfill(bhigh-1,bhigh-1,BLACK);

	// yellow box
	setfillstyle(1,YELLOW);
	floodfill(blow+1,bhigh-1,BLACK);

    setcolor(WHITE);
    setbkcolor(MAGENTA);
    settextstyle(0,HORIZ_DIR,3);
	outtextxy(200,225,"END");
    setbkcolor(BLACK);
}

void printmarkers()
{
    int i;
    for(i=0;i<4;i++)
    {
        setcolor(GREEN);
        circle(green[i]->x,green[i]->y,10);
        setcolor(LIGHTRED);
        circle(red[i]->x,red[i]->y,10);
        setcolor(LIGHTBLUE);
        circle(blue[i]->x,blue[i]->y,10);
        setcolor(BROWN);
        circle(yellow[i]->x,yellow[i]->y,10);
    }
    setbkcolor(BLACK);
}

//-------------------------------------------------------Token Menus!!


void case1(char colour)
{
    if(colour == 'g')
    {
        green[g-1] = gstart;
        g--;
        gg++;
    }
    if(colour == 'r')
    {
        red[r-1] = rstart;
        r--;
        rr++;
    }
    if(colour == 'y')
    {
        yellow[yel-1] = ystart;
        yel--;
        yy++;
    }
    if(colour == 'b')
    {
        blue[b-1] = bstart;
        b--;
        bb++;
    }

}

void case2(char colour,int dice)
{
    int j;
    if(colour == 'g')
    {
        for(j=0;j<dice;j++)
        {
            if(green[3] == gend)
            {
                green[3] = green[3]->down;
            }
            else
                green[3] = green[3]->next;
        }
        for(j=0;j<4;j++)
        {
            if(green[3] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(green[3] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(green[3] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }

        }
    }
    else if(colour == 'r')
    {
        for(j=0;j<dice;j++)
        {
            if(red[3] == rend)
            {
                red[3] = red[3]->down;
            }
            else
                red[3] = red[3]->next;
        }
        for(j=0;j<4;j++)
        {
            if(red[3] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(red[3] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(red[3] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else if(colour == 'b')
    {
        for(j=0;j<dice;j++)
        {
            if(blue[3] == bend)
            {
                blue[3] = blue[3]->down;
            }
            else
                blue[3] = blue[3]->next;
        }
        for(j=0;j<4;j++)
        {
            if(blue[3] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(blue[3] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(blue[3] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else
    {
        for(j=0;j<dice;j++)
        {
            if(yellow[3] == yend)
            {
                yellow[3] = yellow[3]->down;
            }
            else
                yellow[3] = yellow[3]->next;
        }
        for(j=0;j<4;j++)
        {
            if(yellow[3] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(yellow[3] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(yellow[3] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
        }
    }
}

void case3(char colour,int dice)
{
    int j;
    if(colour == 'g')
    {
        for(j=0;j<dice;j++)
        {
            if(green[2] == gend)
            {
                green[2] = green[2]->down;
            }
            else
                green[2] = green[2]->next;
        }
        for(j=0;j<4;j++)
        {
            if(green[2] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(green[2] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(green[2] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }

        }
    }
    else if(colour == 'r')
    {
        for(j=0;j<dice;j++)
        {
            if(red[2] == rend)
            {
                red[2] = red[2]->down;
            }
            else
                red[2] = red[2]->next;
        }
        for(j=0;j<4;j++)
        {
            if(red[2] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(red[2] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(red[2] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else if(colour == 'b')
    {
        for(j=0;j<dice;j++)
        {
            if(blue[2] == bend)
            {
                blue[2] = blue[2]->down;
            }
            else
                blue[2] = blue[2]->next;
        }
        for(j=0;j<4;j++)
        {
            if(blue[2] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(blue[2] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(blue[2] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else
    {
        for(j=0;j<dice;j++)
        {
            if(yellow[2] == yend)
            {
                yellow[2] = yellow[2]->down;
            }
            else
                yellow[2] = yellow[2]->next;
        }
        for(j=0;j<4;j++)
        {
            if(yellow[2] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(yellow[2] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(yellow[2] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
        }
    }
}

void case4(char colour,int dice)
{
    int j;
    if(colour == 'g')
    {
        for(j=0;j<dice;j++)
        {
            if(green[1] == gend)
            {
                green[1] = green[1]->down;
            }
            else
                green[1] = green[1]->next;
        }
        for(j=0;j<4;j++)
        {
            if(green[1] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(green[1] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(green[1] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }

        }
    }
    else if(colour == 'r')
    {
        for(j=0;j<dice;j++)
        {
            if(red[1] == rend)
            {
                red[1] = red[1]->down;
            }
            else
                red[1] = red[1]->next;
        }
        for(j=0;j<4;j++)
        {
            if(red[1] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(red[1] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(red[1] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else if(colour == 'b')
    {
        for(j=0;j<dice;j++)
        {
            if(blue[1] == bend)
            {
                blue[1] = blue[1]->down;
            }
            else
                blue[1] = blue[1]->next;
        }
        for(j=0;j<4;j++)
        {
            if(blue[1] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(blue[1] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(blue[1] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else
    {
        for(j=0;j<dice;j++)
        {
            if(yellow[1] == yend)
            {
                yellow[1] = yellow[1]->down;
            }
            else
                yellow[1] = yellow[1]->next;
        }
        for(j=0;j<4;j++)
        {
            if(yellow[1] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(yellow[1] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(yellow[1] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
        }
    }
}

void case5(char colour,int dice)
{
    int j;
    if(colour == 'g')
    {
        for(j=0;j<dice;j++)
        {
            if(green[0] == gend)
            {
                green[0] = green[0]->down;
            }
            else
                green[0] = green[0]->next;
        }
        for(j=0;j<4;j++)
        {
            if(green[0] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(green[0] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(green[0] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }

        }
    }
    else if(colour == 'r')
    {
        for(j=0;j<dice;j++)
        {
            if(red[0] == rend)
            {
                red[0] = red[0]->down;
            }
            else
                red[0] = red[0]->next;
        }
        for(j=0;j<4;j++)
        {
            if(red[0] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(red[0] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(red[0] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else if(colour == 'b')
    {
        for(j=0;j<dice;j++)
        {
            if(blue[0] == bend)
            {
                blue[0] = blue[0]->down;
            }
            else
                blue[0] = blue[0]->next;
        }
        for(j=0;j<4;j++)
        {
            if(blue[0] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(blue[0] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
            else if(blue[0] == yellow[j])
            {
                yellow[j] = yellow[yel-1]->next;
                break;
            }
        }
    }
    else
    {
        for(j=0;j<dice;j++)
        {
            if(yellow[0] == yend)
            {
                yellow[0] = yellow[0]->down;
            }
            else
                yellow[0] = yellow[0]->next;
        }
        for(j=0;j<4;j++)
        {
            if(yellow[0] == red[j])
            {
                red[j] = red[r-1]->next;
                break;
            }
            else if(yellow[0] == blue[j])
            {
                blue[j] = blue[b-1]->next;
                break;
            }
            else if(yellow[0] == green[j])
            {
                green[j] = green[g-1]->next;
                break;
            }
        }
    }
}


void tokenmenu0(char colour,int dice)
{
    char a;
    int flag = 0;
    settextstyle(3,HORIZ_DIR,1);
    if(dice == 6)
    {
        outtextxy(470,200,"1. POP A TOKEN?");
    }

    else
    {
        outtextxy(470,200,"1. CONTINUE?");
        flag = 1;
    }

    outtextxy(470,300,"Enter your choice");
    a = getch();
    if(flag == 1)
    {
        a = 0;
    }
    switch(a)
    {
        case '0':{break;}
        case '1':{
                case1(colour);
                break;
                }
    }
}

void tokenmenu1(char colour,int dice)
{
    char a;
    int j;
    settextstyle(3,HORIZ_DIR,1);


    outtextxy(470,200,"1. MOVE 1?");
    if(colour == 'g')
    {
        if(g!=0 && dice==6)
            outtextxy(470,220,"2. POP A TOKEN?");
    }
    else if(colour == 'r')
    {
        if(r!=0 && dice==6)
            outtextxy(470,220,"2. POP A TOKEN?");
    }
    else if(colour == 'b')
    {
        if(b!=0 && dice==6)
            outtextxy(470,220,"2. POP A TOKEN?");
    }
    else
    {
        if(yel!=0 && dice==6)
            outtextxy(470,220,"2. POP A TOKEN?");
    }
    outtextxy(470,300,"Enter your choice");
    a = getch();

    switch(a)
    {

        case '1':{
                case2(colour,dice);

                break;}
        case '2':{
                case1(colour);
                break;}
    }
}

void tokenmenu2(char colour,int dice)
{
    char a;
    int j;
    settextstyle(3,HORIZ_DIR,1);


    outtextxy(470,200,"1. MOVE 1?");
    outtextxy(470,220,"2. MOVE 2?");
    if(colour == 'g')
    {
        if(g!=0 && dice==6)
            outtextxy(470,240,"3. POP A TOKEN?");
    }
    else if(colour == 'r')
    {
        if(r!=0 && dice==6)
            outtextxy(470,240,"3. POP A TOKEN?");
    }
    else if(colour == 'b')
    {
        if(b!=0 && dice==6)
            outtextxy(470,240,"3. POP A TOKEN?");
    }
    else
    {
        if(yel!=0 && dice==6)
            outtextxy(470,240,"3. POP A TOKEN?");
    }
    outtextxy(470,300,"Enter your choice");
    a = getch();

    switch(a)
    {

        case '1':{
                case2(colour,dice);
                break;}
        case '2':{
                case3(colour,dice);
                break;}
        case '3':{
                case1(colour);

                break;}
    }
}

void tokenmenu3(char colour,int dice)
{
    char a;
    int j;
    settextstyle(3,HORIZ_DIR,1);


    outtextxy(470,200,"1. MOVE 1?");
    outtextxy(470,220,"2. MOVE 2?");
    outtextxy(470,240,"3. MOVE 3?");
    if(colour == 'g')
    {
        if(g!=0 && dice==6)
            outtextxy(470,260,"4. POP A TOKEN?");
    }
    else if(colour == 'r')
    {
        if(r!=0 && dice==6)
            outtextxy(470,260,"4. POP A TOKEN?");
    }
    else if(colour == 'b')
    {
        if(b!=0 && dice==6)
            outtextxy(470,260,"4. POP A TOKEN?");
    }
    else
    {
        if(yel!=0 && dice==6)
            outtextxy(470,260,"4. POP A TOKEN?");
    }
    outtextxy(470,300,"Enter your choice");
    a = getch();

    switch(a)
    {

        case '1':{
                case2(colour,dice);
                break;}
       case '2':{
                case3(colour,dice);
                break;}
        case '3':{
                case4(colour,dice);
                break;}
        case '4':{
                case1(colour);
                break;}
    }
}


void tokenmenu4(char colour,int dice)
{
    char a;
    int j;
    settextstyle(3,HORIZ_DIR,1);


    outtextxy(470,200,"1. MOVE 1?");
    outtextxy(470,220,"2. MOVE 2?");
    outtextxy(470,240,"3. MOVE 3?");
    outtextxy(470,260,"4. MOVE 4?");
    if(colour == 'g')
    {
        if(g!=0 && dice==6)
            outtextxy(470,280,"5. POP A TOKEN?");
    }
    else if(colour == 'r')
    {
        if(r!=0 && dice==6)
            outtextxy(470,280,"5. POP A TOKEN?");
    }
    else if(colour == 'b')
    {
        if(b!=0 && dice==6)
            outtextxy(470,280,"5. POP A TOKEN?");
    }
    else
    {
        if(yel!=0 && dice==6)
            outtextxy(470,280,"5. POP A TOKEN?");
    }
    outtextxy(470,300,"Enter your choice");
    a = getch();

    switch(a)
    {

        case '1':{
                case2(colour,dice);
                break;}
       case '2':{
                case3(colour,dice);
                break;}
        case '3':{
                case4(colour,dice);
                break;}
        case '4':{
                case5(colour,dice);
                break;}
        case '5':{
                case1(colour);
                break;}
    }
}
//---------------------------------------------------------------------------------MAIN
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	printboard();

	setcolor(LIGHTGREEN);
    setlinestyle(0,1,1);
    rectangle(450,20,630,450);

	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,2);
	outtextxy(465,40,"GAME STARTED");
	settextstyle(3,HORIZ_DIR,6);
	outtextxy(465,150,"LUDO");
	settextstyle(3,HORIZ_DIR,2);
	outtextxy(500,300,"MADE BY");
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(500,350,"ABHISHEK");
	outtextxy(485,380,"SHREY BATRA");
	outtextxy(473,410,"YASH VARSHNEY");

	for(int aaaa=0;aaaa<4;aaaa++)
    {
        setcolor(WHITE);
        settextstyle(3,HORIZ_DIR,2);
        outtextxy(500,210,"Loading.");
        delay(200);
        outtextxy(500,210,"Loading..");
        delay(200);
        outtextxy(500,210,"Loading...");
        delay(200);
        setcolor(BLACK);
        outtextxy(500,210,"Loading...");
    }

    setcolor(WHITE);

	create();

	makegstack();
	makerstack();
	makebstack();
	makeystack();

	red[0] = rstack;
	red[1] = red[0]->next;
	red[2] = red[1]->next;
	red[3] = red[2]->next;
	green[0] = gstack;
	green[1] = green[0]->next;
	green[2] = green[1]->next;
	green[3] = green[2]->next;
	blue[0] = bstack;
	blue[1] = blue[0]->next;
	blue[2] = blue[1]->next;
	blue[3] = blue[2]->next;
	yellow[0] = ystack;
	yellow[1] = yellow[0]->next;
	yellow[2] = yellow[1]->next;
	yellow[3] = yellow[2]->next;

    printmarkers();

	setcolor(LIGHTGREEN);
    setlinestyle(0,1,1);
    rectangle(450,20,630,450);
    setfillstyle(SOLID_FILL,BLACK);
    int z = 0;
    int win = 0;
    char x;
    int dice;
    char colour;

    while(!win)
    {
        cleardevice();
        printboard();
        setlinestyle(0,1,3);
        printmarkers();
        setcolor(LIGHTGREEN);
        setlinestyle(0,1,1);
        rectangle(450,20,630,450);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(455,25,LIGHTGREEN);

        switch(z)
        {
            case 0:{
                    R0:
                    setcolor(WHITE);
                    settextstyle(3,HORIZ_DIR,2);
                    outtextxy(470,30,"GREEN'S TURN");

                    settextstyle(3,HORIZ_DIR,1);
                    outtextxy(470,60,"1. Roll Dice?");
                    outtextxy(470,80,"2. Exit?");
                    outtextxy(470,100,"Enter your option");

                    colour = 'g';

                    x = getch();
                    switch(x)
                    {
                        case '1':{
                                srand(time(NULL));
                                dice = (rand() % 6) + 1;
                                settextstyle(8,HORIZ_DIR,7);
                                switch(dice)
                                {
                                    case 1:{
                                            outtextxy(480,140,"\"1\"");
                                            delay(500);
                                            break;}
                                    case 2:{
                                            outtextxy(480,140,"\"2\"");
                                            delay(500);
                                            break;}
                                    case 3:{
                                            outtextxy(480,140,"\"3\"");
                                            delay(500);
                                            break;}
                                    case 4:{
                                            outtextxy(480,140,"\"4\"");
                                            delay(500);
                                            break;}
                                    case 5:{
                                            outtextxy(480,140,"\"5\"");
                                            delay(500);
                                            break;}
                                    case 6:{
                                            outtextxy(480,140,"\"6\"");
                                            delay(500);
                                            break;}
                                }
                                switch(gg)
                                {
                                    case 0:{
                                            tokenmenu0(colour,dice);
                                            break;}
                                    case 1:{
                                            tokenmenu1(colour,dice);
                                            break;}
                                    case 2:{
                                            tokenmenu2(colour,dice);
                                            break;}
                                    case 3:{
                                            tokenmenu3(colour,dice);
                                            break;}
                                    case 4:{
                                            tokenmenu4(colour,dice);
                                            break;}
                                }


                                break;
                                }
                        case '2':{
                                goto END;
                                break;
                                }
                        default:{
                                outtextxy(470,130,"INVALID OPTION!");
                                outtextxy(480,150,"ENTER AGAIN!");
                                delay(1000);
                                goto R0;
                                break;
                                }
                    }

                    if(!green[0] || !green[1] || !green[2] || !green[3])
                    {
                        win = 1;
                        setcolor(BLACK);
                        setbkcolor(WHITE);
                        settextstyle(1,HORIZ_DIR,10);
                        outtextxy(100,100,"WIN");
                        return 0;
                    }

                    break;
                    }

            case 1:{
                    R1:
                    setcolor(WHITE);
                    settextstyle(3,HORIZ_DIR,2);
                    outtextxy(470,30,"RED'S TURN");

                    settextstyle(3,HORIZ_DIR,1);
                    outtextxy(470,60,"1. Roll Dice?");
                    outtextxy(470,80,"2. Exit?");
                    outtextxy(470,100,"Enter your option");

                    colour = 'r';

                    x = getch();
                    switch(x)
                    {
                        case '1':{
                                dice = (rand() % 6) + 1;
                                settextstyle(8,HORIZ_DIR,7);
                                switch(dice)
                                {
                                    case 1:{
                                            outtextxy(480,140,"\"1\"");
                                            delay(500);
                                            break;}
                                    case 2:{
                                            outtextxy(480,140,"\"2\"");
                                            delay(500);
                                            break;}
                                    case 3:{
                                            outtextxy(480,140,"\"3\"");
                                            delay(500);
                                            break;}
                                    case 4:{
                                            outtextxy(480,140,"\"4\"");
                                            delay(500);
                                            break;}
                                    case 5:{
                                            outtextxy(480,140,"\"5\"");
                                            delay(500);
                                            break;}
                                    case 6:{
                                            outtextxy(480,140,"\"6\"");
                                            delay(500);
                                            break;}
                                }
                                switch(rr)
                                {
                                    case 0:{
                                            tokenmenu0(colour,dice);
                                            break;}
                                    case 1:{
                                            tokenmenu1(colour,dice);
                                            break;}
                                    case 2:{
                                            tokenmenu2(colour,dice);
                                            break;}
                                    case 3:{
                                            tokenmenu3(colour,dice);
                                            break;}
                                    case 4:{
                                            tokenmenu4(colour,dice);
                                            break;}
                                }


                                break;
                                }
                        case '2':{
                                goto END;
                                break;
                                }
                        default:{
                                outtextxy(470,130,"INVALID OPTION!");
                                outtextxy(480,150,"ENTER AGAIN!");
                                delay(1000);
                                goto R1;
                                break;
                                }
                    }

                    if(!red[0] || !red[1] || !red[2] || !red[3])
                    {
                        win = 1;
                        setcolor(BLACK);
                        setbkcolor(WHITE);
                        settextstyle(1,HORIZ_DIR,10);
                        outtextxy(100,100,"WIN");
                        return 0;
                    }


                    break;
                    }


            case 2:{
                    R2:
                    setcolor(WHITE);
                    settextstyle(3,HORIZ_DIR,2);
                    outtextxy(470,30,"BLUE'S TURN");

                    settextstyle(3,HORIZ_DIR,1);
                    outtextxy(470,60,"1. Roll Dice?");
                    outtextxy(470,80,"2. Exit?");
                    outtextxy(470,100,"Enter your option");

                    colour = 'b';

                    x = getch();
                    switch(x)
                    {
                        case '1':{
                                dice = (rand() % 6) + 1;
                                settextstyle(8,HORIZ_DIR,7);
                                switch(dice)
                                {
                                    case 1:{
                                            outtextxy(480,140,"\"1\"");
                                            delay(500);
                                            break;}
                                    case 2:{
                                            outtextxy(480,140,"\"2\"");
                                            delay(500);
                                            break;}
                                    case 3:{
                                            outtextxy(480,140,"\"3\"");
                                            delay(500);
                                            break;}
                                    case 4:{
                                            outtextxy(480,140,"\"4\"");
                                            delay(500);
                                            break;}
                                    case 5:{
                                            outtextxy(480,140,"\"5\"");
                                            delay(500);
                                            break;}
                                    case 6:{
                                            outtextxy(480,140,"\"6\"");
                                            delay(500);
                                            break;}
                                }
                                switch(bb)
                                {
                                    case 0:{
                                            tokenmenu0(colour,dice);
                                            break;}
                                    case 1:{
                                            tokenmenu1(colour,dice);
                                            break;}
                                    case 2:{
                                            tokenmenu2(colour,dice);
                                            break;}
                                    case 3:{
                                            tokenmenu3(colour,dice);
                                            break;}
                                    case 4:{
                                            tokenmenu4(colour,dice);
                                            break;}
                                }


                                break;
                                }
                        case '2':{
                                goto END;
                                break;
                                }
                        default:{
                                outtextxy(470,130,"INVALID OPTION!");
                                outtextxy(480,150,"ENTER AGAIN!");
                                delay(1000);
                                goto R2;
                                break;
                                }
                    }

                    if(!blue[0] || !blue[1] || !blue[2] || !blue[3])
                    {
                        win = 1;
                        setcolor(BLACK);
                        setbkcolor(WHITE);
                        settextstyle(1,HORIZ_DIR,10);
                        outtextxy(100,100,"WIN");
                        return 0;
                    }



                    break;
                    }

            case 3:{
                    R3:
                    setcolor(WHITE);
                    settextstyle(3,HORIZ_DIR,2);
                    outtextxy(470,30,"YELLOW'S TURN");

                    settextstyle(3,HORIZ_DIR,1);
                    outtextxy(470,60,"1. Roll Dice?");
                    outtextxy(470,80,"2. Exit?");
                    outtextxy(470,100,"Enter your option");

                    colour = 'y';

                    x = getch();
                    switch(x)
                    {
                        case '1':{
                                dice = (rand() % 6) + 1;
                                settextstyle(8,HORIZ_DIR,7);
                                switch(dice)
                                {
                                    case 1:{
                                            outtextxy(480,140,"\"1\"");
                                            delay(500);
                                            break;}
                                    case 2:{
                                            outtextxy(480,140,"\"2\"");
                                            delay(500);
                                            break;}
                                    case 3:{
                                            outtextxy(480,140,"\"3\"");
                                            delay(500);
                                            break;}
                                    case 4:{
                                            outtextxy(480,140,"\"4\"");
                                            delay(500);
                                            break;}
                                    case 5:{
                                            outtextxy(480,140,"\"5\"");
                                            delay(500);
                                            break;}
                                    case 6:{
                                            outtextxy(480,140,"\"6\"");
                                            delay(500);
                                            break;}
                                }
                                switch(yy)
                                {
                                    case 0:{
                                            tokenmenu0(colour,dice);
                                            break;}
                                    case 1:{
                                            tokenmenu1(colour,dice);
                                            break;}
                                    case 2:{
                                            tokenmenu2(colour,dice);
                                            break;}
                                    case 3:{
                                            tokenmenu3(colour,dice);
                                            break;}
                                    case 4:{
                                            tokenmenu4(colour,dice);
                                            break;}
                                }


                                break;
                                }
                        case '2':{
                                goto END;
                                break;
                                }
                        default:{
                                outtextxy(470,130,"INVALID OPTION!");
                                outtextxy(480,150,"ENTER AGAIN!");
                                delay(1000);
                                goto R3;
                                break;
                                }
                    }

                    if(!yellow[0] || !yellow[1] || !yellow[2] || !yellow[3])
                    {
                        win = 1;
                        setcolor(BLACK);
                        setbkcolor(WHITE);
                        settextstyle(1,HORIZ_DIR,10);
                        outtextxy(100,100,"WIN");
                        return 0;
                    }



                    break;
                    }
        }

        z = (z+1)%4;
        win = 0;
    }
    END:
	closegraph();
	return 0;
}
