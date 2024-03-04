#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <thread>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

void meniu1();
void meniu2();
void meniu3();
void meniu4();
void meniu_salvari();
void salvare();
void citire();
void info();
void desenaresegment(int c);
void desenareTabla(int n);
void desenareTabla_sv();
void dimensiuni_tabla(int &a,int &b,int &c,int &d);
void play3();
void play2();
void play1();
void mesaj_final();
void desenaresegmentAUTO();
void desenare_strategica();
void countdown();
bool intrebare();

int nrseg=0,sco1,sco2,n,cn,copie_cn,z1,z2,z3,z4,utilizate,libere,blocate,mod_joc,tura=0; //tura = 0-jucator1/ 1-jucator2; mod_joc = 1-joc normal / 2-joc antrenament / 3 joc strategic
char puncte[10],nume1[20],nume2[20],ceas[10],copie_ceas[10];
int limba; // 1- engleza, 0- romana
int timp; // 0- fara timp , 1- cu timp
int men,cmen; // 0 - meniu continuare, 1 - meniu salvare
int sv1,sv2,sv3; // 0- nu contine salvare, 1- contine salvare
int sunet; // 0 - mute, 1 - unmute


struct segmente
{
    struct
    {
        int x,y;
    } p1,p2;
} seg[101],mutare;

struct pct
{
    int x,y;
    unsigned check,tip_pct=0; /* 1 = punct utilizat, 2 = punct liber, 3 = punct blocat */
} a[151][101];


//OCTAVIANA
void eroare_trasare(char text[50])
{
    settextstyle(10,HORIZ_DIR,5);
    int maxx=getmaxx();
    int maxy=getmaxy();
    int tx=textwidth(text);
    int ty=textheight(text);
    for(int i=1; i<=3; i++)
    {
        setcolor(15);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
        delay(300);
        setcolor(0);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
        delay(300);
        setcolor(15);
    }
}

//RARES
void eroare_puncte()
{
    setbkcolor(0);
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,5);
    int maxx=getmaxx();
    int maxy=getmaxy();
    if(n==0)
    {
        if(limba==0)
        {
            int tx=textwidth("NU ATI INTRODUS NUMARUL DE PUNCTE");
            int ty=textheight("NU ATI INTRODUS NUMARUL DE PUNCTE");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"NU ATI INTRODUS NUMARUL DE PUNCTE");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"NU ATI INTRODUS NUMARUL DE PUNCTE");
        }
        else
        {
            int tx=textwidth("YOU HAVE NOT ENTERED THE NUMBER OF POINTS");
            int ty=textheight("YOU HAVE NOT ENTERED THE NUMBER OF POINTS");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"YOU HAVE NOT ENTERED THE NUMBER OF POINTS");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"YOU HAVE NOT ENTERED THE NUMBER OF POINTS");
        }
    }
    else if(n<5)
    {
        if(limba==0)
        {
            int tx=textwidth("PREA PUTINE PUNCTE");
            int ty=textheight("PREA PUTINE PUNCTE");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA PUTINE PUNCTE");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA PUTINE PUNCTE");
        }
        else
        {
            int tx=textwidth("TOO FEW POINTS");
            int ty=textheight("TOO FEW POINTS");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO FEW POINTS");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO FEW POINTS");
        }
    }
    else if(n>200)
    {
        if(limba==0)
        {
            int tx=textwidth("PREA MULTE PUNCTE");
            int ty=textheight("PREA MULTE PUNCTE");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA MULTE PUNCTE");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA MULTE PUNCTE");
        }
        else
        {
            int tx=textwidth("TOO MANY POINTS");
            int ty=textheight("TOO MANY POINTS");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO MANY POINTS");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO MANY POINTS");
        }
    }
    else if(cn<5 && timp==1)
    {
        if(limba==0)
        {
            int tx=textwidth("PREA PUTIN TIMP");
            int ty=textheight("PREA PUTIN TIMP");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA PUTIN TIMP");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA PUTIN TIMP");
        }
        else
        {
            int tx=textwidth("TOO LITTLE TIME");
            int ty=textheight("TOO LITTLE TIME");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO LITTLE TIME");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO LITTLE TIME");
        }
    }
    else if(cn>60 && timp==1)
    {
        if(limba==0)
        {
            int tx=textwidth("PREA MULT TIMP");
            int ty=textheight("PREA MULT TIMP");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA MULT TIMP");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"PREA MULT TIMP");
        }
        else
        {
            int tx=textwidth("TOO MUCH TIME");
            int ty=textheight("TOO MUCH TIME");
            setcolor(15);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO MUCH TIME");
            setcolor(0);
            delay(2000);
            outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,"TOO MUCH TIME");
        }
    }
    setcolor(15);
    setbkcolor(0);
    settextstyle(8,HORIZ_DIR,5);
}



//RARES
void meniu_prim()
{
    int t=0;
    clearviewport();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);

    n=0;
    strcpy(nume1,"");
    z1=0;
    strcpy(nume2,"");
    z2=0;
    strcpy(puncte,"");
    z3=0;
    int width,height;
    int x,y;
    bool ok=0;

    setbkcolor(0);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");

    settextstyle(10,HORIZ_DIR,7);
    width=textwidth("INFO");
    height=textheight("INFO");
    outtextxy(getmaxx()/2-width/2,getmaxy()/2+200,"INFO");

    if(limba==0)
    {
        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        width=textwidth("SEGMENTE");
        height=textheight("SEGMENTE");
        outtextxy(getmaxx()/2-width/2,20,"SEGMENTE");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"LIMBA");

        settextstyle(10,HORIZ_DIR,7);
        width=textwidth("JOC NOU");
        height=textheight("JOC NOU");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2-200,"JOC NOU");

        width=textwidth("CONTINUA JOCUL");
        height=textheight("CONTINUA JOCUL");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2,"CONTINUA JOCUL");
    }
    else
    {
        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        width=textwidth("SEGMENTS");
        height=textheight("SEGMENTS");
        outtextxy(getmaxx()/2-width/2,20,"SEGMENTS");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"LANGUAGE");

        settextstyle(10,HORIZ_DIR,7);
        width=textwidth("NEW GAME");
        height=textheight("NEW GAME");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2-200,"NEW GAME");

        width=textwidth("CONTINUE THE GAME");
        height=textheight("CONTINUE THE GAME");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2,"CONTINUE THE GAME");
    }
    while(1)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(limba==0)
            {
                width=textwidth("JOC NOU");
                height=textheight("JOC NOU");
            }
            else
            {
                width=textwidth("NEW GAME");
                height=textheight("NEW GAME");
            }
                if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2-200 && y<=getmaxy()/2-200+height)
            {

                meniu1();

            }

            if(limba==0)
            {
                width=textwidth("CONTINUA JOCUL");
                height=textheight("CONTINUA JOCUL");
            }
            else
            {
                width=textwidth("CONTINUE THE GAME");
                height=textheight("CONTINUE THE GAME");
            }
            if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2 && y<=getmaxy()/2+height)
            {
                men=0;
                meniu_salvari();
            }

            width=textwidth("INFO");
            height=textheight("INFO");
            if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2+200 && y<=getmaxy()/2+200+height)
            {
                info();
            }

            else if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if(t==0 && ((limba==0 && x<=textwidth("LIMBA")+40 && x>=40 && y>=40 && y<=textheight("LIMBA")+40) || (limba==1 && x<=textwidth("LANGUAGE")+40 && x>=40 && y>=40 && y<=textheight("LANGUAGE")+40)))
            {
                t=1;
                settextstyle(10,HORIZ_DIR,5);
                setbkcolor(0);
                if(limba==0)
                {
                    outtextxy(40,40+textheight("LIMBA"),"ROMANA");
                    outtextxy(40,40+textheight("LIMBA")+textheight("ROMANA"),"ENGLEZA");
                }
                else
                {
                    outtextxy(40,40+textheight("LANGUAGE"),"ROMANIAN");
                    outtextxy(40,40+textheight("LANGUAGE")+textheight("ROMANIAN"),"ENGLISH");
                }
            }
            else if((t==1 && limba==0 && x<=textwidth("ROMANA")+40 && x>=40 && y>=40+textheight("LIMBA") && y<=textheight("ROMANA")+textheight("LIMBA")+40) || (t==1 && limba==1 && x<=textwidth("ROMANIAN")+40 && x>=40 && y>=40+textheight("LANGUAGE") && y<=textheight("ROMANIAN")+textheight("LANGUAGE")+40))
            {
                limba=0;
                meniu_prim();
            }
            else if((t==1 && limba==0 && x<=textwidth("ENGLEZA")+40 && x>=40 && y>=textheight("ROMANA")+textheight("LIMBA")+40 && y<=textheight("ENGLEZA")+textheight("ROMANA")+textheight("LIMBA")+40) || (t==1 && limba==1 && x<=textwidth("ENGLISH")+40 && x>=40 && y>=textheight("ROMANIAN")+textheight("LANGUAGE")+40 && y<=textheight("ENGLISH")+textheight("ROMANIAN")+textheight("LANGUAGE")+40))
            {
                limba=1;
                meniu_prim();
            }
            else if(t==1 && ((limba==0 && x<=textwidth("LIMBA")+40 && x>=40 && y>=40 && y<=textheight("LIMBA")+40) || (limba==1 && x<=textwidth("LANGUAGE")+40 && x>=40 && y>=40 && y<=textheight("LANGUAGE")+40)))
                meniu_prim();
            else if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}

//RARES
void meniu1()
{
    int cx,cy;
    clearviewport();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    n=0;
    cn=0;
    timp=0;
    strcpy(nume1,"");
    z1=0;
    strcpy(nume2,"");
    z2=0;
    strcpy(puncte,"");
    z3=0;
    strcpy(ceas,"");
    z4=0;

    int width,height;
    int x,y;
    bool ok=0;

    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,5);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);

    if(limba==0)
    {
        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        width=textwidth("SEGMENTE");
        height=textheight("SEGMENTE");
        outtextxy(getmaxx()/2-width/2,20,"SEGMENTE");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");

        settextstyle(10,HORIZ_DIR,7);
        width=textwidth("DOI JUCATORI");
        height=textheight("DOI JUCATORI");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2+100,"DOI JUCATORI");

        width=textwidth("UN JUCATOR");
        height=textheight("UN JUCATOR");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2-100,"UN JUCATOR");
    }
    else
    {
        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        width=textwidth("SEGMENTS");
        height=textheight("SEGMENTS");
        outtextxy(getmaxx()/2-width/2,20,"SEGMENTS");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");

        settextstyle(10,HORIZ_DIR,7);
        width=textwidth("MULTIPLAYER");
        height=textheight("MULTIPLAYER");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2+100,"MULTIPLAYER");

        width=textwidth("SINGLEPLAYER");
        height=textheight("SINGLEPLAYER");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2-100,"SINGLEPLAYER");
    }
    while(ok==0)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(limba==0)
            {
                width=textwidth("UN JUCATOR");
                height=textheight("UN JUCATOR");
            }
            else
            {
                width=textwidth("SINGLEPLAYER");
                height=textheight("SINGLEPLAYER");
            }
            if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2-100 && y<=getmaxy()/2-100+height)
            {
                meniu3();
                ok=1;
            }

            if(limba==0)
            {
                width=textwidth("DOI JUCATORI");
                height=textheight("DOI JUCATORI");
            }
            else
            {
                width=textwidth("MULTIPLAYER");
                height=textheight("MULTIPLAYER");
            }
            if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2+100 && y<=getmaxy()/2+100+height)
            {
                meniu2();
                ok=1;
            }
            else if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if((limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40) || (limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40)) meniu_prim();
            else if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}

//RARES
void citire1()
{
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,5);
    n=0;
    char c;
    int width,height;
    int pct_buton1[10]= {getmaxx()/3+10,getmaxy()/6+20,getmaxx()/3+10,2*getmaxy()/6-10,2*(getmaxx()/3)-10,2*getmaxy()/6-10,2*(getmaxx()/3)-10,getmaxy()/6+20,getmaxx()/3+10,getmaxy()/6+20};
    int pct_buton2[10]= {getmaxx()/3,getmaxy()/6+10,getmaxx()/3,2*getmaxy()/6,2*(getmaxx()/3),2*getmaxy()/6,2*(getmaxx()/3),getmaxy()/6+10,getmaxx()/3,getmaxy()/6+10};


    width=textwidth(puncte);
    height=textheight(puncte);
    fillpoly(5,pct_buton1);
    outtextxy(getmaxx()/2-width/2,(2*getmaxy()/6-getmaxy()/6-10)/2+getmaxy()/6+10-height/2,puncte);
    if(limba==0) outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMAR PUNCTE:");
    else outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMBER OF POINTS:");

    while (ismouseclick(WM_LBUTTONDOWN)==NULL)
    {
        if(kbhit())
        {
            c=getch();
            if(c!=8 && z1<=6 && c<=57 && c>=48)
            {
                puncte[z1]=c;
                puncte[z1+1]=NULL;
                z1++;
            }
            else if(c==8 && z1>0)
            {
                z1--;
                puncte[z1]=NULL;
            }
            width=textwidth(puncte);
            height=textheight(puncte);
            fillpoly(5,pct_buton1);
            outtextxy(getmaxx()/2-width/2,(2*getmaxy()/6-getmaxy()/6-10)/2+getmaxy()/6+10-height/2,puncte);
            if(limba==0) outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMAR PUNCTE:");
            else outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMBER OF POINTS:");
        }
    }
    fillpoly(5,pct_buton2);
    width=textwidth(puncte);
    height=textheight(puncte);
    outtextxy(getmaxx()/2-width/2,(2*getmaxy()/6-getmaxy()/6-10)/2+getmaxy()/6+10-height/2,puncte);
    if(limba==0) outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMAR PUNCTE:");
    else outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMBER OF POINTS:");

    for(int i=0; i<z1; i++) n=10*n+(puncte[i]-'0');
}

//RARES
void citire2()
{
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,5);
    char c;
    int width,height;
    int pct_buton1[10]= {getmaxx()/3+10,2*getmaxy()/6+20,getmaxx()/3+10,3*getmaxy()/6-10,2*(getmaxx()/3)-10,3*getmaxy()/6-10,2*(getmaxx()/3)-10,2*getmaxy()/6+20,getmaxx()/3+10,2*getmaxy()/6+20};
    int pct_buton2[10]= {getmaxx()/3,2*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6,2*(getmaxx()/3),2*getmaxy()/6+10,getmaxx()/3,2*getmaxy()/6+10};

    width=textwidth(nume1);
    height=textheight(nume1);
    fillpoly(5,pct_buton1);
    outtextxy(getmaxx()/2-width/2,(3*getmaxy()/6-2*getmaxy()/6-10)/2+2*getmaxy()/6+10-height/2,nume1);
    if(limba==0) outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"JUCATOR 1:");
    else outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"PLAYER 1:");

    while (ismouseclick(WM_LBUTTONDOWN)==NULL)
    {
        if(kbhit())
        {
            c=getch();
            if(c!=8 && z2<=15 && ((c<=90 && c>=65)||(c<=122 && c>=97)||c==32||(c<=57 && c>=48)))
            {
                nume1[z2]=c;
                nume1[z2+1]=NULL;
                z2++;
            }
            else if(c==8 && z2>0)
            {
                z2--;
                nume1[z2]=NULL;
            }
            width=textwidth(nume1);
            height=textheight(nume1);
            fillpoly(5,pct_buton1);
            outtextxy(getmaxx()/2-width/2,(3*getmaxy()/6-2*getmaxy()/6-10)/2+2*getmaxy()/6+10-height/2,nume1);
            if(limba==0) outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"JUCATOR 1:");
            else outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"PLAYER 1:");
        }
    }
    width=textwidth(nume1);
    height=textheight(nume1);
    fillpoly(5,pct_buton2);
    outtextxy(getmaxx()/2-width/2,(3*getmaxy()/6-2*getmaxy()/6-10)/2+2*getmaxy()/6+10-height/2,nume1);
    if(limba==0) outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"JUCATOR 1:");
    else outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"PLAYER 1:");
}

//RARES
void citire3()
{
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,5);
    char c;
    int width,height;
    int pct_buton1[10]= {getmaxx()/3+10,3*getmaxy()/6+20,getmaxx()/3+10,4*getmaxy()/6-10,2*(getmaxx()/3)-10,4*getmaxy()/6-10,2*(getmaxx()/3)-10,3*getmaxy()/6+20,getmaxx()/3+10,3*getmaxy()/6+20};
    int pct_buton2[10]= {getmaxx()/3,3*getmaxy()/6+10,getmaxx()/3,4*getmaxy()/6,2*(getmaxx()/3),4*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6+10};

    width=textwidth(nume2);
    height=textheight(nume2);
    fillpoly(5,pct_buton1);
    outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,nume2);
    if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"JUCATOR 2:");
    else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"PLAYER 2:");

    while (ismouseclick(WM_LBUTTONDOWN)==NULL)
    {
        if(kbhit())
        {
            c=getch();
            if(c!=8 && z3<=15 && ((c<=90 && c>=65)||(c<=122 && c>=97)||c==32||(c<=57 && c>=48)))
            {
                nume2[z3]=c;
                nume2[z3+1]=NULL;
                z3++;
            }
            else if(c==8 && z3>0)
            {
                z3--;
                nume2[z3]=NULL;
            }
            width=textwidth(nume2);
            height=textheight(nume2);
            fillpoly(5,pct_buton1);
            outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,nume2);
            if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"JUCATOR 2:");
            else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"PLAYER 2:");
        }
    }
    width=textwidth(nume2);
    height=textheight(nume2);
    fillpoly(5,pct_buton2);
    outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,nume2);
    if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"JUCATOR 2:");
    else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"PLAYER 2:");
}

void citire4()
{
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,5);
    cn=0;
    char c;
    int width,height;
    int pct_buton_timp_selectat[10]= {getmaxx()/3+10,4*getmaxy()/6+20,getmaxx()/3+10,5*getmaxy()/6-10,2*(getmaxx()/3)-10,5*getmaxy()/6-10,2*(getmaxx()/3)-10,4*getmaxy()/6+20,getmaxx()/3+10,4*getmaxy()/6+20};
    int pct_buton5[10]= {getmaxx()/3,4*getmaxy()/6+10,getmaxx()/3,5*getmaxy()/6,2*(getmaxx()/3),5*getmaxy()/6,2*(getmaxx()/3),4*getmaxy()/6+10,getmaxx()/3,4*getmaxy()/6+10};
    int pct_buton_timp[10]= {2*(getmaxx()/3)-80,4*getmaxy()/6+10,2*(getmaxx()/3)-80,4*getmaxy()/6+50,2*(getmaxx()/3),4*getmaxy()/6+50,2*(getmaxx()/3),4*getmaxy()/6+10,2*(getmaxx()/3)-80,4*getmaxy()/6+10};
    int pct_puton_timp_off[10]= {2*(getmaxx()/3)-79,4*getmaxy()/6+11,2*(getmaxx()/3)-79,4*getmaxy()/6+49,2*(getmaxx()/3)-41,4*getmaxy()/6+49,2*(getmaxx()/3)-41,4*getmaxy()/6+11,2*(getmaxx()/3)-79,4*getmaxy()/6+11};
    int pct_puton_timp_on[10]= {2*(getmaxx()/3)-39,4*getmaxy()/6+11,2*(getmaxx()/3)-39,4*getmaxy()/6+49,2*(getmaxx()/3),4*getmaxy()/6+49,2*(getmaxx()/3),4*getmaxy()/6+11,2*(getmaxx()/3)-39,4*getmaxy()/6+11};

    width=textwidth(ceas);
    height=textheight(ceas);
    fillpoly(5,pct_buton_timp_selectat);
    fillpoly(5,pct_buton_timp);

    setfillstyle(SOLID_FILL,2);
    fillpoly(5,pct_puton_timp_on);
    setfillstyle(SOLID_FILL,0);

    outtextxy(getmaxx()/2-width/2,(5*getmaxy()/6-4*getmaxy()/6-10)/2+4*getmaxy()/6+10-height/2,ceas);
    if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
    else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");

    while (ismouseclick(WM_LBUTTONDOWN)==NULL)
    {
        if(kbhit())
        {
            c=getch();
            if(c!=8 && z4<=6 && c<=57 && c>=48)
            {
                ceas[z4]=c;
                ceas[z4+1]=NULL;
                z4++;
            }
            else if(c==8 && z4>0)
            {
                z4--;
                ceas[z4]=NULL;
            }
            width=textwidth(ceas);
            height=textheight(ceas);
            fillpoly(5,pct_buton_timp_selectat);
            fillpoly(5,pct_buton_timp);

            setfillstyle(SOLID_FILL,2);
            fillpoly(5,pct_puton_timp_on);
            setfillstyle(SOLID_FILL,0);

            outtextxy(getmaxx()/2-width/2,(5*getmaxy()/6-4*getmaxy()/6-10)/2+4*getmaxy()/6+10-height/2,ceas);
            if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
            else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");
        }
    }
    fillpoly(5,pct_buton5);
    fillpoly(5,pct_buton_timp);

    setfillstyle(SOLID_FILL,2);
    fillpoly(5,pct_puton_timp_on);
    setfillstyle(SOLID_FILL,0);

    width=textwidth(ceas);
    height=textheight(ceas);
    outtextxy(getmaxx()/2-width/2,(5*getmaxy()/6-4*getmaxy()/6-10)/2+4*getmaxy()/6+10-height/2,ceas);
    if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
    else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");

    for(int i=0; i<z4; i++) cn=10*cn+(ceas[i]-'0');
    copie_cn=cn;
    strcpy(copie_ceas,ceas);
}

void citire5()
{
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,5);
    cn=0;
    char c;
    int width,height;
    int pct_buton_timp_selectat[10]= {getmaxx()/3+10,3*getmaxy()/6+20,getmaxx()/3+10,4*getmaxy()/6-10,2*(getmaxx()/3)-10,4*getmaxy()/6-10,2*(getmaxx()/3)-10,3*getmaxy()/6+20,getmaxx()/3+10,3*getmaxy()/6+20};
    int pct_buton_timp[10]= {2*(getmaxx()/3)-80,3*getmaxy()/6+10,2*(getmaxx()/3)-80,3*getmaxy()/6+50,2*(getmaxx()/3),3*getmaxy()/6+50,2*(getmaxx()/3),3*getmaxy()/6+10,2*(getmaxx()/3)-80,3*getmaxy()/6+10};
    int pct_puton_timp_off[10]= {2*(getmaxx()/3)-79,3*getmaxy()/6+11,2*(getmaxx()/3)-79,3*getmaxy()/6+49,2*(getmaxx()/3)-41,3*getmaxy()/6+49,2*(getmaxx()/3)-41,3*getmaxy()/6+11,2*(getmaxx()/3)-79,3*getmaxy()/6+11};
    int pct_puton_timp_on[10]= {2*(getmaxx()/3)-39,3*getmaxy()/6+11,2*(getmaxx()/3)-39,3*getmaxy()/6+49,2*(getmaxx()/3),3*getmaxy()/6+49,2*(getmaxx()/3),3*getmaxy()/6+11,2*(getmaxx()/3)-39,3*getmaxy()/6+11};
    int pct_buton5[10]= {getmaxx()/3,3*getmaxy()/6+10,getmaxx()/3,4*getmaxy()/6,2*(getmaxx()/3),4*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6+10};

    width=textwidth(ceas);
    height=textheight(ceas);
    fillpoly(5,pct_buton_timp_selectat);
    fillpoly(5,pct_buton_timp);

    setfillstyle(SOLID_FILL,2);
    fillpoly(5,pct_puton_timp_on);
    setfillstyle(SOLID_FILL,0);

    outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,ceas);
    if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
    else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");

    while (ismouseclick(WM_LBUTTONDOWN)==NULL)
    {
        if(kbhit())
        {
            c=getch();
            if(c!=8 && z4<=6 && c<=57 && c>=48)
            {
                ceas[z4]=c;
                ceas[z4+1]=NULL;
                z4++;
            }
            else if(c==8 && z4>0)
            {
                z4--;
                ceas[z4]=NULL;
            }
            width=textwidth(ceas);
            height=textheight(ceas);
            fillpoly(5,pct_buton_timp_selectat);
            fillpoly(5,pct_buton_timp);

            setfillstyle(SOLID_FILL,2);
            fillpoly(5,pct_puton_timp_on);
            setfillstyle(SOLID_FILL,0);

            outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,ceas);
            if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
            else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");
        }
    }

    fillpoly(5,pct_buton5);
    fillpoly(5,pct_buton_timp);
    setfillstyle(SOLID_FILL,2);
    fillpoly(5,pct_puton_timp_on);
    setfillstyle(SOLID_FILL,0);

    width=textwidth(ceas);
    height=textheight(ceas);
    outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,ceas);
    if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
    else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");

    for(int i=0; i<z4; i++) cn=10*cn+(ceas[i]-'0');
    copie_cn=cn;
    strcpy(copie_ceas,ceas);
}

//RARES
void meniu2()
{
    setfillstyle(SOLID_FILL,0);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,5);
    setcolor(15);
    clearviewport();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
    int pct_buton1[10]= {getmaxx()/3,getmaxy()/6+10,getmaxx()/3,2*getmaxy()/6,2*(getmaxx()/3),2*getmaxy()/6,2*(getmaxx()/3),getmaxy()/6+10,getmaxx()/3,getmaxy()/6+10};
    int pct_buton2[10]= {getmaxx()/3,2*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6,2*(getmaxx()/3),2*getmaxy()/6+10,getmaxx()/3,2*getmaxy()/6+10};
    int pct_buton3[10]= {getmaxx()/3,3*getmaxy()/6+10,getmaxx()/3,4*getmaxy()/6,2*(getmaxx()/3),4*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6+10};
    int pct_buton5[10]= {getmaxx()/3,4*getmaxy()/6+10,getmaxx()/3,5*getmaxy()/6,2*(getmaxx()/3),5*getmaxy()/6,2*(getmaxx()/3),4*getmaxy()/6+10,getmaxx()/3,4*getmaxy()/6+10};
    int pct_buton_timp[10]= {2*(getmaxx()/3)-80,4*getmaxy()/6+10,2*(getmaxx()/3)-80,4*getmaxy()/6+50,2*(getmaxx()/3),4*getmaxy()/6+50,2*(getmaxx()/3),4*getmaxy()/6+10,2*(getmaxx()/3)-80,4*getmaxy()/6+10};
    int pct_puton_timp_off[10]= {2*(getmaxx()/3)-79,4*getmaxy()/6+11,2*(getmaxx()/3)-79,4*getmaxy()/6+49,2*(getmaxx()/3)-41,4*getmaxy()/6+49,2*(getmaxx()/3)-41,4*getmaxy()/6+11,2*(getmaxx()/3)-79,4*getmaxy()/6+11};
    int pct_puton_timp_on[10]= {2*(getmaxx()/3)-39,4*getmaxy()/6+11,2*(getmaxx()/3)-39,4*getmaxy()/6+49,2*(getmaxx()/3),4*getmaxy()/6+49,2*(getmaxx()/3),4*getmaxy()/6+11,2*(getmaxx()/3)-39,4*getmaxy()/6+11};

    if(strcmp(nume1,"JUCATOR 1")==0 || strcmp(nume1,"PLAYER 1")==0)
    {
        strcpy(nume1,"");
        z2=0;
    }
    if(strcmp(nume2,"JUCATOR 2")==0 || strcmp(nume2,"PLAYER 2")==0)
    {
        strcpy(nume2,"");
        z3=0;
    }

    int x,y;
    int width,height;
    fillpoly(5,pct_buton1);
    fillpoly(5,pct_buton2);
    fillpoly(5,pct_buton3);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);
    settextstyle(10,HORIZ_DIR,5);

    width=textwidth(puncte);
    height=textheight(puncte);
    outtextxy(getmaxx()/2-width/2,(2*getmaxy()/6-getmaxy()/6-10)/2+getmaxy()/6+10-height/2,puncte);
    if(limba==0) outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMAR PUNCTE:");
    else outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMBER OF POINTS:");

    width=textwidth(nume1);
    height=textheight(nume1);
    outtextxy(getmaxx()/2-width/2,(3*getmaxy()/6-2*getmaxy()/6-10)/2+2*getmaxy()/6+10-height/2,nume1);
    if(limba==0) outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"JUCATOR 1:");
    else outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"PLAYER 1:");

    width=textwidth(nume2);
    height=textheight(nume2);
    outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,nume2);
    if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"JUCATOR 2:");
    else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"PLAYER 2:");

    if(timp==0)
    {
        settextstyle(10,HORIZ_DIR,5);

        fillpoly(5,pct_buton5);
        fillpoly(5,pct_buton_timp);
        setfillstyle(SOLID_FILL,4);
        fillpoly(5,pct_puton_timp_off);
        setfillstyle(SOLID_FILL,0);

        if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
        else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");
        setbkcolor(0);
    }
    else if(timp==1)
    {

        fillpoly(5,pct_buton5);
        fillpoly(5,pct_buton_timp);
        setfillstyle(SOLID_FILL,2);
        fillpoly(5,pct_puton_timp_on);
        setfillstyle(SOLID_FILL,0);

        width=textwidth(ceas);
        height=textheight(ceas);
        outtextxy(getmaxx()/2-width/2,(5*getmaxy()/6-4*getmaxy()/6-10)/2+4*getmaxy()/6+10-height/2,ceas);
        if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
        else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");
    }

    settextstyle(10,HORIZ_DIR,5);
    if(limba==0)
    {
        settextstyle(10,HORIZ_DIR,8);
        width=textwidth("DOI JUCATORI");
        height=textheight("DOI JUCATORI");
        outtextxy(getmaxx()/2-width/2,20,"DOI JUCATORI");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");
        outtextxy(getmaxx()-textwidth("INCEPE")-40,getmaxy()-80,"INCEPE");

        settextstyle(8,HORIZ_DIR,5);
    }
    else
    {
        settextstyle(10,HORIZ_DIR,8);
        width=textwidth("MULTIPLAYER");
        height=textheight("MULTIPLAYER");
        outtextxy(getmaxx()/2-width/2,20,"MULTIPLAYER");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");
        outtextxy(getmaxx()-textwidth("START")-40,getmaxy()-80,"START");

        settextstyle(8,HORIZ_DIR,5);
    }
    while(1)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=getmaxy()/6+10 && y<=2*getmaxy()/6) citire1();
            else if(x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=2*getmaxy()/6+10 && y<=3*getmaxy()/6) citire2();
            else if(x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=3*getmaxy()/6+10 && y<=4*getmaxy()/6) citire3();
            else if(timp==0 && x>=2*(getmaxx()/3)-79 && x<=2*(getmaxx()/3)-41 && y>=4*getmaxy()/6+11 && y<=4*getmaxy()/6+49)
            {
                timp=1;
                settextstyle(10,HORIZ_DIR,5);

                fillpoly(5,pct_buton5);
                fillpoly(5,pct_buton_timp);
                setfillstyle(SOLID_FILL,2);
                fillpoly(5,pct_puton_timp_on);
                setfillstyle(SOLID_FILL,0);

                width=textwidth(ceas);
                height=textheight(ceas);
                outtextxy(getmaxx()/2-width/2,(5*getmaxy()/6-4*getmaxy()/6-10)/2+4*getmaxy()/6+10-height/2,ceas);
                if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
                else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");
            }
            else if(timp==1 && x>=2*(getmaxx()/3)-39 && x<=2*(getmaxx()/3) && y>=4*getmaxy()/6+11 && y<=4*getmaxy()/6+49)
            {
                timp=0;
                settextstyle(10,HORIZ_DIR,5);

                fillpoly(5,pct_buton5);
                fillpoly(5,pct_buton_timp);
                setfillstyle(SOLID_FILL,4);
                fillpoly(5,pct_puton_timp_off);
                setfillstyle(SOLID_FILL,0);
                if(limba==0) outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIMP:");
                else outtextxy(getmaxx()/3+1,4*getmaxy()/6+10,"TIME:");
                setbkcolor(0);
            }
            else if(timp==1 && x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=4*getmaxy()/6+10 && y<=5*getmaxy()/6) citire4();
            else if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if((limba==0 && x<=getmaxx()-40 && x>=getmaxx()-textwidth("INCEPE")-40 && y>=getmaxy()-80 && y<=getmaxy()-80+textheight("INCEPE")) || (limba==1 && x<=getmaxx()-40 && x>=getmaxx()-textwidth("START")-40 && y>=getmaxy()-80 && y<=getmaxy()-80+textheight("START")))
            {
                if(n>200 || n==0 || n<5 || (cn<5 && timp==1) || (cn>60 && timp==1)) eroare_puncte();
                else
                {
                    mod_joc=1;
                    men=-1;
                    desenareTabla(n);
                    break;
                }
            }
            else if((limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40) || (limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40)) meniu1();
            else if(x<=getmaxx()-40 && y<=getmaxy()-80 && x>=getmaxx()-120 && y>=getmaxy()-160)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}

//RARES
void meniu3()
{
    setfillstyle(SOLID_FILL,0);
    clearviewport();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,5);
    int width,height;
    int x,y;
    bool ok=0;

    n=0;
    strcpy(nume1,"");
    z1=0;
    strcpy(nume2,"");
    z2=0;
    strcpy(puncte,"");
    z3=0;
    strcpy(ceas,"");
    z4=0;
    if(strcmp(nume1,"JUCATOR 1")==0 || strcmp(nume1,"PLAYER 1")==0)
    {
        strcpy(nume1,"");
        z2=0;
    }
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);
    settextstyle(10,HORIZ_DIR,5);
    if(limba==0)
    {
        settextstyle(10,HORIZ_DIR,8);

        width=textwidth("JOC CU CALCULATORUL:");
        height=textheight("JOC CU CALCULATORUL:");
        outtextxy(getmaxx()/2-width/2,20,"JOC CU CALCULATORUL:");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");

        settextstyle(10,HORIZ_DIR,7);
        width=textwidth("ANTRENAMENT");
        height=textheight("ANTRENAMENT");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2-100,"ANTRENAMENT");

        width=textwidth("STRATEGIC");
        height=textheight("STRATEGIC");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2+100,"STRATEGIC");
    }
    else
    {
        settextstyle(10,HORIZ_DIR,8);

        width=textwidth("COMPUTER GAME:");
        height=textheight("COMPUTER GAME:");
        outtextxy(getmaxx()/2-width/2,20,"COMPUTER GAME:");

        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");

        settextstyle(10,HORIZ_DIR,7);
        width=textwidth("TRAINING");
        height=textheight("TRAINING");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2-100,"TRAINING");

        width=textwidth("STRATEGIC");
        height=textheight("STRATEGIC");
        outtextxy(getmaxx()/2-width/2,getmaxy()/2+100,"STRATEGIC");
    }
    while(ok==0)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(limba==0)
            {
                width=textwidth("ANTRENAMENT");
                height=textheight("ANTRENAMENT");
            }
            else
            {
                width=textwidth("TRAINING");
                height=textheight("TRAINING");
            }
                if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2-100 && y<=getmaxy()/2-100+height)
            {
                mod_joc=2;
                meniu4();
            }

            if(limba==0)
            {
                width=textwidth("ANTRENAMENT");
                height=textheight("ANTRENAMENT");
            }
            else
            {
                width=textwidth("TRAINING");
                height=textheight("TRAINING");
            }
                if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2+100 && y<=getmaxy()/2+100+height)
            {
                mod_joc=3;
                meniu4();
            }

            else if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if((limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40) || (limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40)) meniu1();
            else if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}
void meniu4()
{
    setfillstyle(SOLID_FILL,0);
    clearviewport();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);

    int pct_buton1[10]= {getmaxx()/3,getmaxy()/6+10,getmaxx()/3,2*getmaxy()/6,2*(getmaxx()/3),2*getmaxy()/6,2*(getmaxx()/3),getmaxy()/6+10,getmaxx()/3,getmaxy()/6+10};
    int pct_buton2[10]= {getmaxx()/3,2*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6,2*(getmaxx()/3),2*getmaxy()/6+10,getmaxx()/3,2*getmaxy()/6+10};
    int pct_buton5[10]= {getmaxx()/3,3*getmaxy()/6+10,getmaxx()/3,4*getmaxy()/6,2*(getmaxx()/3),4*getmaxy()/6,2*(getmaxx()/3),3*getmaxy()/6+10,getmaxx()/3,3*getmaxy()/6+10};
    int pct_buton_timp[10]= {2*(getmaxx()/3)-80,3*getmaxy()/6+10,2*(getmaxx()/3)-80,3*getmaxy()/6+50,2*(getmaxx()/3),3*getmaxy()/6+50,2*(getmaxx()/3),3*getmaxy()/6+10,2*(getmaxx()/3)-80,3*getmaxy()/6+10};
    int pct_puton_timp_off[10]= {2*(getmaxx()/3)-79,3*getmaxy()/6+11,2*(getmaxx()/3)-79,3*getmaxy()/6+49,2*(getmaxx()/3)-41,3*getmaxy()/6+49,2*(getmaxx()/3)-41,3*getmaxy()/6+11,2*(getmaxx()/3)-79,3*getmaxy()/6+11};
    int pct_puton_timp_on[10]= {2*(getmaxx()/3)-39,3*getmaxy()/6+11,2*(getmaxx()/3)-39,3*getmaxy()/6+49,2*(getmaxx()/3),3*getmaxy()/6+49,2*(getmaxx()/3),3*getmaxy()/6+11,2*(getmaxx()/3)-39,3*getmaxy()/6+11};

    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,5);
    if(strcmp(nume1,"JUCATOR 1")==0 || strcmp(nume1,"PLAYER 1")==0)
    {
        strcpy(nume1,"");
        z2=0;
    }

    int x,y;
    int width,height;

    fillpoly(5,pct_buton1);
    fillpoly(5,pct_buton2);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);
    if(timp==0)
    {
        settextstyle(10,HORIZ_DIR,5);
        fillpoly(5,pct_buton5);
        fillpoly(5,pct_buton_timp);

        setfillstyle(SOLID_FILL,4);
        fillpoly(5,pct_puton_timp_off);
        setfillstyle(SOLID_FILL,0);

        width=textwidth(ceas);
        height=textheight(ceas);
        if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
        else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");
        setbkcolor(0);
    }
    else if(timp==1)
    {
        settextstyle(10,HORIZ_DIR,5);
        fillpoly(5,pct_buton5);
        fillpoly(5,pct_buton_timp);

        setfillstyle(SOLID_FILL,2);
        fillpoly(5,pct_puton_timp_on);
        setfillstyle(SOLID_FILL,0);

        width=textwidth(ceas);
        height=textheight(ceas);
        outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,ceas);
        if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
        else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");
    }

    settextstyle(10,HORIZ_DIR,5);

    width=textwidth(puncte);
    height=textheight(puncte);
    outtextxy(getmaxx()/2-width/2,(2*getmaxy()/6-getmaxy()/6-10)/2+getmaxy()/6+10-height/2,puncte);
    if(limba==0) outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMAR PUNCTE:");
    else outtextxy(getmaxx()/3+1,getmaxy()/6+10,"NUMBER OF POINTS:");

    width=textwidth(nume1);
    height=textheight(nume1);
    outtextxy(getmaxx()/2-width/2,(3*getmaxy()/6-2*getmaxy()/6-10)/2+2*getmaxy()/6+10-height/2,nume1);
    if(limba==0) outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"JUCATOR 1:");
    else outtextxy(getmaxx()/3+1,2*getmaxy()/6+10,"PLAYER 1:");
    setcolor(15);
    settextstyle(10,HORIZ_DIR,5);
    if(limba==0)
    {
        settextstyle(10,HORIZ_DIR,8);
        if(mod_joc==2)
        {
            width=textwidth("JOC DE ANTRENAMENT");
            height=textheight("JOC DE ANTRENAMENT");
            outtextxy(getmaxx()/2-width/2,20,"JOC DE ANTRENAMENT");
        }
        else if(mod_joc==3)
        {
            width=textwidth("JOC DE STRATEGIE");
            height=textheight("JOC DE STRATEGIE");
            outtextxy(getmaxx()/2-width/2,20,"JOC DE STRATEGIE");
        }


        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");
        outtextxy(getmaxx()-textwidth("INCEPE")-40,getmaxy()-80,"INCEPE");

        settextstyle(8,HORIZ_DIR,5);
    }
    else
    {
        settextstyle(10,HORIZ_DIR,8);
        if(mod_joc==2)
        {
            width=textwidth("TRAINING GAME");
            height=textheight("TRAINING GAME");
            outtextxy(getmaxx()/2-width/2,20,"TRAINING GAME");
        }
        else if(mod_joc==3)
        {
            width=textwidth("STRATEGY GAME");
            height=textheight("STRATEGY GAME");
            outtextxy(getmaxx()/2-width/2,20,"STRATEGY GAME");
        }
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");
        outtextxy(getmaxx()-textwidth("START")-40,getmaxy()-80,"START");

        settextstyle(10,HORIZ_DIR,5);
    }
    while(1)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=getmaxy()/6+10 && y<=2*getmaxy()/6) citire1();
            if(x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=2*getmaxy()/6+10 && y<=3*getmaxy()/6) citire2();
            else if(timp==0 && x>=2*(getmaxx()/3)-79 && x<=2*(getmaxx()/3)-41 && y>=3*getmaxy()/6+11 && y<=3*getmaxy()/6+49)
            {

                timp=1;
                settextstyle(10,HORIZ_DIR,5);
                fillpoly(5,pct_buton5);
                fillpoly(5,pct_buton_timp);

                setfillstyle(SOLID_FILL,2);
                fillpoly(5,pct_puton_timp_on);
                setfillstyle(SOLID_FILL,0);

                width=textwidth(ceas);
                height=textheight(ceas);
                outtextxy(getmaxx()/2-width/2,(4*getmaxy()/6-3*getmaxy()/6-10)/2+3*getmaxy()/6+10-height/2,ceas);
                if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
                else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");

            }
            else if(timp==1 && x>=2*(getmaxx()/3)-39 && x<=2*(getmaxx()/3) && y>=3*getmaxy()/6+11 && y<=3*getmaxy()/6+49)
            {
                timp=0;
                settextstyle(10,HORIZ_DIR,5);
                fillpoly(5,pct_buton5);
                fillpoly(5,pct_buton_timp);

                setfillstyle(SOLID_FILL,4);
                fillpoly(5,pct_puton_timp_off);
                setfillstyle(SOLID_FILL,0);

                if(limba==0) outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIMP:");
                else outtextxy(getmaxx()/3+1,3*getmaxy()/6+10,"TIME:");
                setbkcolor(0);
            }
            else if(timp==1 && x>=getmaxx()/3 && x<=2*(getmaxx()/3) && y>=3*getmaxy()/6+10 && y<=4*getmaxy()/6) citire5();
            if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            if((limba==0 && x<=getmaxx()-40 && x>=getmaxx()-textwidth("INCEPE")-40 && y>=getmaxy()-80 && y<=getmaxy()-80+textheight("INCEPE")) || (limba==1 && x<=getmaxx()-40 && x>=getmaxx()-textwidth("START")-40 && y>=getmaxy()-80 && y<=getmaxy()-80+textheight("START")))
            {
                if(n>200 || n==0 || n<5 || (cn<5 && timp==1) || (cn>60 && timp==1)) eroare_puncte();
                else
                {
                    men=-1;
                    desenareTabla(n);
                    break;
                }
            }
            if((limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40) || (limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40)) meniu3();
            else if(x<=getmaxx()-40 && y<=getmaxy()-80 && x>=getmaxx()-120 && y>=getmaxy()-160)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-160,getmaxx()-40,getmaxy()-80);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}

//OCTAVIAN
void info()
{
    int xc,yc,maxx,maxy,width,height;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    cleardevice();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,7);
    setbkcolor(0);
    setcolor(15);
    if(limba==0)
    {
        width=textwidth("DESPRE JOC");
        height=textheight("DESPRE JOC");
        outtextxy(getmaxx()/2-width/2,20,"DESPRE JOC");
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");
        settextstyle(10,HORIZ_DIR,3);
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+textheight("A"),"  Tabla de joc contine un numar de puncte(MAX:200). Pe rand, fiecare dintre");
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+3*textheight("A"),"Castigatorul este cel care reuseste sa traseze ultimul segment.       ");
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+2*textheight("A"),"cei doi jucatori trebuie sa traseze un segment conform regulamentului.");
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+5*textheight("A"),"   Acelasi punct nu poate fi capatul a doua sau mai multe segmente.");
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+7*textheight("A"),"   Segmentele NU se pot intretaia.");
        readimagefile("intersectie.jpg",getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+textwidth("   Segmentele nu se pot intretaia.")+10,yc+6*textheight("A"),getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+textwidth("   Segmentele nu se pot intretaia.")+150,yc+6*textheight("A")+150);
        readimagefile("L.jpg",getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+7*textheight("A")+150,getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+25,yc+7*textheight("A")+175);
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+50,yc+7*textheight("A")+150,"- numarul de puncte libere la un moment dat;");
        readimagefile("U.jpg",getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+8*textheight("A")+175,getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+25,yc+8*textheight("A")+200);
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+50,yc+8*textheight("A")+175,"- numarul de puncte utilizate la un moment dat;");
        readimagefile("B.jpg",getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+9*textheight("A")+200,getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+25,yc+9*textheight("A")+225);
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+50,yc+9*textheight("A")+200,"- numarul de puncte blocate la un moment dat;");
        readimagefile("stea.jpg",getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2,yc+10*textheight("A")+225,getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+25,yc+10*textheight("A")+250);
        outtextxy(getmaxx()/2-textwidth("   Tabla de joc contine un numar anume de puncte. Pe rand, fiecare dintre")/2+50,yc+10*textheight("A")+225,"- punctele blocate sunt reprezentate prin stele;");
    }
    else
    {
        width=textwidth("ABOUT THE GAME");
        height=textheight("ABOUT THE GAME");
        outtextxy(getmaxx()/2-width/2,20,"ABOUT THE GAME");
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");
        settextstyle(10,HORIZ_DIR,3);
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+textheight("A"),"  The game board contains a number of points(MAX:200). In turn, each of");
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+2*textheight("A"),"the two players must draw a segment according to the rules. The winner ");
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+3*textheight("A"),"is the one who manages to draw the last segment.                       ");
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+5*textheight("A"),"   The same point cannot be the end of two or more segments.");
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+7*textheight("A"),"   Segments CANNOT intersect.");
        readimagefile("intersectie.jpg",getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+textwidth("   Segments cannot intersect.")+10,yc+6*textheight("A"),getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+textwidth("   Segments cannot intersect.")+150,yc+6*textheight("A")+125);
    readimagefile("L.jpg",getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+7*textheight("A")+150,getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+25,yc+7*textheight("A")+175);
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+50,yc+7*textheight("A")+150,"- the number of free points at a time;");
        readimagefile("U.jpg",getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+8*textheight("A")+175,getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+25,yc+8*textheight("A")+200);
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+50,yc+8*textheight("A")+175,"- the number of points used at a time;");
        readimagefile("B.jpg",getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+9*textheight("A")+200,getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+25,yc+9*textheight("A")+225);
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+50,yc+9*textheight("A")+200,"- the number of points blocked at a time;");
        readimagefile("stea.jpg",getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2,yc+10*textheight("A")+225,getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+25,yc+10*textheight("A")+250);
        outtextxy(getmaxx()/2-textwidth("   The game board contains a certain number of points. In turn, each of")/2+50,yc+10*textheight("A")+225,"- blocked points are represented by stars;");
    }
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);
    while(1)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
           int x=mousex();
           int y=mousey();
            if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if((limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40) || (limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40)) meniu_prim();
            else if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}

//OCTAVIAN
void stea( int xc,int yc,int r,int color,int umpluta)
{
    setcolor(color);
    float beta=2*3.14159265/10,alfa=3.14159265*3/2;
    int x[101],y[101];
    for(int i=0;i<=10;i++)
    {
        if(i%2==0)
        {
            x[i]=xc+r*cos(alfa+beta*i);
        y[i]=yc+r*sin(alfa+beta*i);
        }
        else{
            x[i]=xc+r/2*cos(alfa+beta*i);
        y[i]=yc+r/2*sin(alfa+beta*i);
        }

    }
    for(int i =0;i<10;i++)
         line(x[i],y[i],x[i+1],y[i+1]);
    if(umpluta!=0)
    {
        setfillstyle(SOLID_FILL,color);
        floodfill(xc,yc,color);
    }

}

//OCTAVIAN
void initializare_segmente()
{
    for(int i=0; i<=nrseg; i++)
    {
        seg[i].p1.x=0;
        seg[i].p1.y=0;
        seg[i].p2.x=0;
        seg[i].p2.y=0;
    }
    nrseg=0;
}
//OCTAVIAN
void dimensiuni_tabla(int &xc, int &yc, int &maxx, int &maxy)
{
    xc=getmaxx()/4/10*10;
    yc=getmaxy()/6/10*10;
    if(xc/10%2==1) xc+=10;
    if(yc/10%2==1) yc+=10;

    maxx=getmaxx()/10*10;
    maxy=getmaxy()/10*10;
    if(maxx/10%2==1) maxx+=10;
    if(maxy/10%2==1) maxy+=10;
}
//OCTAVIAN
void initializare_puncte()
{
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);

    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
            if(a[i][j].check!=0)
            {
                a[i][j].check=0;
                a[i][j].tip_pct=0;
            }
}

//OCTAVIAN
int distanta_pct_dr(int x1,int y1,int x2, int y2,int xm,int ym)
{
    int a,b,c,d;
    a=y2-y1;
    b=x1-x2;
    c=y1*x2-x1*y2;
    d=abs(a*xm+b*ym+c)/sqrt(a*a+b*b);
    return d;
}
//OCTAVIAN
void adauga_seg(int x1,int y1,int x2,int y2)
{
    seg[nrseg].p1.x=x1/10;
    seg[nrseg].p1.y=y1/10;
    seg[nrseg].p2.x=x2/10;
    seg[nrseg].p2.y=y2/10;
    nrseg++;
}

//OCTAVIAN
bool validitate(int x1, int y1, int x2,int y2,char eroare[])
{
    int i,j,l;
    bool ok=true;
    if(x1==x2)
    {
        j=min(y1,y2);
        l=max(y1,y2);
        for(i=j+20; i<l; i=i+20)
            if(a[x1/10][i/10].check!=0)
            {
                ok= false;
                if(limba==0) strcpy(eroare,"Intersectie cu puncte coliniare pe axa OY!");
                else strcpy(eroare,"Intersection with collinear points on the OY axis!");
            }
    }
    else if (y1==y2)
    {
        j=min(x1,x2);
        l=max(x1,x2);
        for(i=j+20; i<l; i=i+20)
            if(a[i/10][y1/10].check!=0)
            {
                ok= false;
                if(limba==0) strcpy(eroare,"Intersectie cu puncte coliniare pe axa OX!");
                else strcpy(eroare,"Intersection with collinear points on the OX axis!");
            }
    }
    else
    {
        int X1=min(x1,x2),Y1=min(y1,y2),X2=max(x1,x2),Y2=max(y1,y2);
        for(i=X1+20; i<X2; i=i+20)
            if(distanta_pct_dr(x1,y1,x2,y2,i,Y1)<8 && a[i/10][Y1/10].check!=0)
            {
                int d=distanta_pct_dr(x1,y1,x2,y2,i,Y1);
                if(limba==0) sprintf(eroare,"Intersectie cu puncte cu distanta %d",d);
                else sprintf(eroare,"Intersection with points with distance %d",d);

                ok= false;
            }
            else if( a[i/10][Y2/10].check!=0 && distanta_pct_dr(x1,y1,x2,y2,i,Y2)<8)
            {
                int d=distanta_pct_dr(x1,y1,x2,y2,i,Y2);
                if(limba==0) sprintf(eroare,"Intersectie cu puncte cu distanta %d",d);
                else sprintf(eroare,"Intersection with points with distance %d",d);
                ok= false;
            }
        for(i=Y1+20; i<Y2; i=i+20)
            if(distanta_pct_dr(x1,y1,x2,y2,X1,i)<8 && a[X1/10][i/10].check!=0)
            {
                int d=distanta_pct_dr(x1,y1,x2,y2,X1,i);
                if(limba==0) sprintf(eroare,"Intersectie cu puncte cu distanta %d",d);
                else sprintf(eroare,"Intersection with points with distance %d",d);
                ok= false;
            }
            else if( a[X2/10][i/10].check!=0 && distanta_pct_dr(x1,y1,x2,y2,X2,i)<8)
            {
                int d=distanta_pct_dr(x1,y1,x2,y2,X2,i);
                if(limba==0) sprintf(eroare,"Intersectie cu puncte cu distanta %d",d);
                else sprintf(eroare,"Intersection with points with distance %d",d);
                ok= false;
            }
        for(i=X1; i<X2; i=i+20)
            for(j=Y1; j<Y2; j=j+20)
                if(distanta_pct_dr(x1,y1,x2,y2,i,j)<8 && a[i/10][j/10].check!=0 && (i!=X1 || j!=Y1))
                {
                    int d=distanta_pct_dr(x1,y1,x2,y2,i,j);
                    if(limba==0) sprintf(eroare,"Intersectie cu puncte cu distanta %d",d);
                    else sprintf(eroare,"Intersection with points with distance %d",d);
                    ok= false;
                }

    }
    int X1=min(x1,x2),Y1=min(y1,y2),X2=max(x1,x2),Y2=max(y1,y2);
    x1/=10;
    y1/=10;
    x2/=10;
    y2/=10;
    for(i=0; i<nrseg; i++)
    {
        int X3=min(seg[i].p1.x,seg[i].p2.x),Y3=min(seg[i].p1.y,seg[i].p2.y),X4=max(seg[i].p1.x,seg[i].p2.x),Y4=max(seg[i].p1.y,seg[i].p2.y);

        if( ( (seg[i].p1.x-x1)*(y2-y1)-(x2-x1)*(seg[i].p1.y-y1) )*( (seg[i].p2.x-x1)*(y2-y1)-(x2-x1)*(seg[i].p2.y-y1) )<=0 && ( (x1-seg[i].p1.x)*(seg[i].p2.y-seg[i].p1.y)-(seg[i].p2.x-seg[i].p1.x)*(y1-seg[i].p1.y) )*( (x2-seg[i].p1.x)*(seg[i].p2.y-seg[i].p1.y)-(seg[i].p2.x-seg[i].p1.x)*(y2-seg[i].p1.y) )<=0)
        {
            ok= false;
            if(limba==0) sprintf(eroare,"Intersectie cu alte segmente!");
            else sprintf(eroare,"Intersection with other segments!");
        }
    }
    return ok;
}

//OCTAVIAN
void puncte_blocate()
{

    int xc,yc,maxx,maxy;

    char text[50];
    dimensiuni_tabla(xc,yc,maxx,maxy);
    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {
            if(a[i][j].tip_pct==2)
            {
                for(int h=xc/10+1; h<=maxx/10-xc/10-1; h++)
                    {
                        for(int k=yc/10+1; k<=maxy/10-yc/10-1; k++)
                        {
                            if(a[h][k].tip_pct==2 && (i!=h || j!=k))
                                if(validitate(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y,text)==true)
                                    goto urmatorul;
                        }

                    }
                    a[i][j].tip_pct=3;
                    setcolor(0);
                    setfillstyle(SOLID_FILL, 0);
                    fillellipse(a[i][j].x,a[i][j].y,8,8);
                    stea(a[i][j].x,a[i][j].y,8,15,1);
                    blocate++;
                    libere--;
                    urmatorul:
                    cout<<"";
            }
        }
}

//OCTAVIAN
void modificare_date()
{
    libere-=2;
    utilizate+=2;
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    puncte_blocate();
    char u[5],l[5],b[5];
    setcolor(WHITE);
    sprintf(l,"%d ",libere);
    sprintf(u,"%d",utilizate);
    sprintf(b,"%d",blocate);
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(maxx-xc-140,getmaxy()/10-textheight(l)/2,l);
    outtextxy(maxx-xc-75,getmaxy()/10-textheight(u)/2,u);
    outtextxy(maxx-xc-10,getmaxy()/10-textheight(b)/2,b);
}

//OCTAVIAN
void creste_scor(int c)
{
    int xc,yc,maxx,maxy;
    char scor1[5],scor2[5];
    dimensiuni_tabla(xc,yc,maxx,maxy);
    if(c==0)
    {
        sco1++;
        sprintf(scor1,"%d",sco1);
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,8);
        outtextxy(xc/2-textwidth(scor1)/2,maxy/2-textheight(scor1)/2,scor1);
    }
    else
    {
        sco2++;
        sprintf(scor2,"%d",sco2);
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,8);
        outtextxy(maxx-xc/2-textwidth(scor2)/2,maxy/2-textheight(scor2)/2,scor2);
    }
}


//OCTAVIAN
void mesaj_final()
{
    int x,y;
    delay(1000);
    cleardevice();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    setbkcolor(0);
    settextstyle(10,HORIZ_DIR,5);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);

    if(limba==0)
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"ACASA");
    }
    else
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"HOME");
    }

    char catigator[50];
    if(sco1>sco2)
        sprintf(catigator,"%s",nume1);
    else if(sco1<=sco2)
        sprintf(catigator,"%s",nume2);
    setcolor(14);
    int r=290;

    outtextxy(getmaxx()/2-textwidth(catigator)/2,getmaxy()/2-3*textheight(catigator),catigator);
    if(limba == 0)
    {
        setcolor(15);
        outtextxy(getmaxx()/2-textwidth("este castigatorul!")/2,getmaxy()/2+6*textheight("este castigatorul!"),"este castigatorul!");
    }
    else
    {
        setcolor(15);
        outtextxy(getmaxx()/2-textwidth("is the winner!")/2,getmaxy()/2+6*textheight("is the winner!"),"is the winner!");
    }
        stea(getmaxx()/2,getmaxy()/2-2*textheight(catigator),r+1,14,1);
        setcolor(0);
        setbkcolor(14);
        outtextxy(getmaxx()/2-textwidth(catigator)/2,getmaxy()/2-3*textheight(catigator),catigator);
    while(1)
    {
        setcolor(14);
        stea(getmaxx()/2,getmaxy()/2-2*textheight(catigator),r,14,0);
        stea(getmaxx()/2,getmaxy()/2-2*textheight(catigator),r+1,14,0);
        delay(50);
        setcolor(0);
        stea(getmaxx()/2,getmaxy()/2-2*textheight(catigator),r,0,0);
        r++;
        setbkcolor(0);
        setcolor(15);
        if(r==300)
            r=290;
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }
        if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
        else if((limba==1 && x<=textwidth("HOME")+40 && x>=40 && y>=40 && y<=textheight("HOME")+40) || (limba==0 && x<=textwidth("ACASA")+40 && x>=40 && y>=40 && y<=textheight("ACASA")+40)) meniu_prim();
        if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
    }

}

//RARES
bool exista(char nume[30])
{
    if (FILE *fis = fopen(nume, "rb"))
        {
            fclose(fis);
            return 1;
        }
    else
        return 0;
}

//RARES
void salvare(char nume[30])
{
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
     FILE *fis = fopen(nume,"wb");

    fwrite(&nrseg, sizeof(nrseg),1,fis);
    fwrite(&sco1, sizeof(sco1),1,fis);
    fwrite(&sco2, sizeof(sco2),1,fis);
    fwrite(&n, sizeof(n),1,fis);
    fwrite(&tura, sizeof(tura),1,fis);
    fwrite(&cn, sizeof(cn),1,fis);
    fwrite(&copie_cn, sizeof(copie_cn),1,fis);
    fwrite(&z1, sizeof(z1),1,fis);
    fwrite(&z2, sizeof(z2),1,fis);
    fwrite(&z3, sizeof(z3),1,fis);
    fwrite(&z4, sizeof(z4),1,fis);
    fwrite(&utilizate, sizeof(utilizate),1,fis);
    fwrite(&libere, sizeof(libere),1,fis);
    fwrite(&blocate, sizeof(blocate),1,fis);
    fwrite(&mod_joc, sizeof(mod_joc),1,fis);
    fwrite(&timp, sizeof(timp),1,fis);
    fwrite(&puncte, sizeof(puncte),1,fis);
    fwrite(&nume1, sizeof(nume1),1,fis);
    fwrite(&nume2, sizeof(nume2),1,fis);
    fwrite(&ceas, sizeof(ceas),1,fis);
    fwrite(&copie_ceas, sizeof(copie_ceas),1,fis);
    for(int i=0;i<nrseg;i++)
        fwrite(&seg[i], sizeof(struct segmente),1,fis);
    fwrite(&mutare, sizeof(struct segmente),1,fis);
    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {
            fwrite(&a[i][j], sizeof(struct pct),1,fis);
        }

    fclose(fis);
}

//RARES
void citire(char nume[30])
{
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
     FILE *fis = fopen(nume,"rb");

    fread(&nrseg, sizeof(nrseg),1,fis);
    fread(&sco1, sizeof(sco1),1,fis);
    fread(&sco2, sizeof(sco2),1,fis);
    fread(&n, sizeof(n),1,fis);
    fread(&tura, sizeof(tura),1,fis);
    fread(&cn, sizeof(cn),1,fis);
    fread(&copie_cn, sizeof(copie_cn),1,fis);
    fread(&z1, sizeof(z1),1,fis);
    fread(&z2, sizeof(z2),1,fis);
    fread(&z3, sizeof(z3),1,fis);
    fread(&z4, sizeof(z4),1,fis);
    fread(&utilizate, sizeof(utilizate),1,fis);
    fread(&libere, sizeof(libere),1,fis);
    fread(&blocate, sizeof(blocate),1,fis);
    fread(&mod_joc, sizeof(mod_joc),1,fis);
    fread(&timp, sizeof(timp),1,fis);
    fread(&puncte, sizeof(puncte),1,fis);
    fread(&nume1, sizeof(nume1),1,fis);
    fread(&nume2, sizeof(nume2),1,fis);
    fread(&ceas, sizeof(ceas),1,fis);
    fread(&copie_ceas, sizeof(copie_ceas),1,fis);
    for(int i=0;i<nrseg;i++)
        fread(&seg[i], sizeof(struct segmente),1,fis);
    fread(&mutare, sizeof(struct segmente),1,fis);
    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {
            fread(&a[i][j], sizeof(struct pct),1,fis);
        }

    fclose(fis);
}

//RARES
bool intrebare(char nume[30])
{
    settextstyle(10,HORIZ_DIR,5);
    char text[50];
    int x,y;
    bool ok;
    if(limba==1)
        strcpy(text,"DO YOU WANT TO SAVE CHANGES TO ");
    else
        strcpy(text,"DORITI SA SALVATI MODIFICARILE IN ");
    strcat(text,nume);
    strcat(text,"?");
    int maxx=getmaxx();
    int maxy=getmaxy();
    int tx=textwidth(text);
    int ty=textheight(text);
    setcolor(15);
    outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
    if(limba==0)
    {
        tx=textwidth("DA");
        ty=textheight("DA");
        outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"DA");
        tx=textwidth("NU");
        ty=textheight("NU");
        outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NU");
    }
    else if(limba==1)
    {
        tx=textwidth("YES");
        ty=textheight("YES");
        outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"YES");
        tx=textwidth("NO");
        ty=textheight("NO");
        outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NO");
    }
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            ok=0;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if((limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40) || (limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40))
                {
                    salvare("back.sv");
                    citire("back.sv");
                    desenareTabla_sv();
                    ok=1;
                }
            else if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
                ok=1;
            }
            if(limba==0)
            {
                tx=textwidth("NU");
                ty=textheight("NU");
                if(x>=maxx/2+50 && y>=maxy/12*11-ty/2+50 && x<=maxx/2+50+tx && y<=maxy/12*11-ty/2+50+ty)
                {
                    setcolor(0);
                    int tx=textwidth(text);
                    int ty=textheight(text);
                    outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
                    tx=textwidth("DA");
                    ty=textheight("DA");
                    outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"DA");
                    tx=textwidth("NU");
                    ty=textheight("NU");
                    outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NU");
                    setcolor(15);
                    return 0;
                }

                tx=textwidth("DA");
                ty=textheight("DA");
                if(x>=maxx/2-tx-50 && y>=maxy/12*11-ty/2+50 && x<=maxx/2-50 && y<=maxy/12*11-ty/2+50+ty) return 1;
            }
            else if(limba==1)
            {
                tx=textwidth("NO");
                ty=textheight("NO");
                if(x>=maxx/2+50 && y>=maxy/12*11-ty/2+50 && x<=maxx/2+50+tx && y<=maxy/12*11-ty/2+50+ty)
                {
                    setcolor(0);
                    int tx=textwidth(text);
                    int ty=textheight(text);
                    outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
                    tx=textwidth("YES");
                    ty=textheight("YES");
                    outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"YES");
                    tx=textwidth("NO");
                    ty=textheight("NO");
                    outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NO");
                    setcolor(15);
                    return 0;
                }

                tx=textwidth("YES");
                ty=textheight("YES");
                if(x>=maxx/2-tx-50 && y>=maxy/12*11-ty/2+50 && x<=maxx/2-50 && y<=maxy/12*11-ty/2+50+ty) return 1;
            }
            if(ok==0)
            {
                for(int i=1; i<=3; i++)
                {
                    setcolor(0);
                    tx=textwidth(text);
                    ty=textheight(text);
                    outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
                    if(limba==1)
                    {
                        tx=textwidth("YES");
                        ty=textheight("YES");
                        outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"YES");
                        tx=textwidth("NO");
                        ty=textheight("NO");
                        outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NO");
                    }
                    else
                    {
                        tx=textwidth("DA");
                        ty=textheight("DA");
                        outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"DA");
                        tx=textwidth("NU");
                        ty=textheight("NU");
                        outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NU");
                    }
                    delay(300);
                    setcolor(15);
                    tx=textwidth(text);
                    ty=textheight(text);
                    outtextxy(maxx/2-tx/2,maxy/12*11-ty/2,text);
                    if(limba==1)
                    {
                        tx=textwidth("YES");
                        ty=textheight("YES");
                        outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"YES");
                        tx=textwidth("NO");
                        ty=textheight("NO");
                        outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NO");
                    }
                    else
                    {
                        tx=textwidth("DA");
                        ty=textheight("DA");
                        outtextxy(maxx/2-tx-50,maxy/12*11-ty/2+50,"DA");
                        tx=textwidth("NU");
                        ty=textheight("NU");
                        outtextxy(maxx/2+50,maxy/12*11-ty/2+50,"NU");
                    }
                    delay(300);
                }
            }
        }
    }
}

//RARES
void meniu_salvari()
{
    int x,y;
    int width,height;
    cleardevice();

    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    setbkcolor(0);
    settextstyle(10,HORIZ_DIR,5);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);

    if(limba==0)
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");
    }
    else
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");
    }

    setbkcolor(0);

    if(limba==0)
    {
        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        width=textwidth("SALVARI");
        height=textheight("SALVARI");
        outtextxy(getmaxx()/2-width/2,20,"SALVARI");

        settextstyle(10,HORIZ_DIR,7);
        if(exista("salvare1.sv")==0)
        {
            width=textwidth("SALVARE 1");
            height=textheight("SALVARE 1");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2-200,"SALVARE 1");
        }
        else
        {
            width=textwidth("*SALVARE 1*");
            height=textheight("*SALVARE 1*");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2-200,"*SALVARE 1*");
        }

        if(exista("salvare2.sv")==0)
        {
            width=textwidth("SALVARE 2");
            height=textheight("SALVARE 2");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2,"SALVARE 2");
        }
        else
        {
            width=textwidth("*SALVARE 2*");
            height=textheight("*SALVARE 2*");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2,"*SALVARE 2*");
        }

        if(exista("salvare3.sv")==0)
        {
            width=textwidth("SALVARE 3");
            height=textheight("SALVARE 3");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2+200,"SALVARE 3");
        }
        else
        {
            width=textwidth("*SALVARE 3*");
            height=textheight("*SALVARE 3*");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2+200,"*SALVARE 3*");
        }
    }
    else
    {
        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        width=textwidth("SAVES");
        height=textheight("SAVES");
        outtextxy(getmaxx()/2-width/2,20,"SAVES");

        settextstyle(10,HORIZ_DIR,7);
        if(exista("salvare1.sv")==0)
        {
            width=textwidth("SAVE 1");
            height=textheight("SAVE 1");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2-200,"SAVE 1");
        }
        else
        {
            width=textwidth("*SAVE 1*");
            height=textheight("*SAVE 1*");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2-200,"*SAVE 1*");
        }

        if(exista("salvare2.sv")==0)
        {
            width=textwidth("SAVE 2");
            height=textheight("SAVE 2");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2,"SAVE 2");
        }
        else
        {
            width=textwidth("*SAVE 2*");
            height=textheight("*SAVE 2*");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2,"*SAVE 2*");
        }

        if(exista("salvare3.sv")==0)
        {
            width=textwidth("SAVE 3");
            height=textheight("SAVE 3");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2+200,"SAVE 3");
        }
        else
        {
            width=textwidth("*SAVE 3*");
            height=textheight("*SAVE 3*");
            outtextxy(getmaxx()/2-width/2,getmaxy()/2+200,"*SAVE 3*");
        }
    }
    while(1)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(limba==0)
            {
                if(exista("salvare1.sv")==0)
                {
                    width=textwidth("SALVARE 1");
                    height=textheight("SALVARE 1");
                }
                else
                {
                    width=textwidth("*SALVARE 1*");
                    height=textheight("*SALVARE 1*");
                }
            }
            else
            {
                if(exista("salvare1.sv")==0)
                {
                    width=textwidth("SAVE 1");
                    height=textheight("SAVE 1");
                }
                else
                {
                    width=textwidth("*SAVE 1*");
                    height=textheight("*SAVE 1*");
                }
            }
                if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2-200 && y<=getmaxy()/2-200+height)
            {
                if(men==1)
                    {
                        if(limba==0 && intrebare("SALVARE 1")==1)
                        {
                            salvare("salvare1.sv");
                            citire("salvare1.sv");
                            men=cmen;
                            desenareTabla_sv();
                        }
                        else if(limba==1 && intrebare("SAVE 1")==1)
                        {
                            salvare("salvare1.sv");
                            citire("salvare1.sv");
                            men=cmen;
                            desenareTabla_sv();
                        }
                    }
                else if(exista("salvare1.sv")==1 && men==0)
                    {
                        citire("salvare1.sv");
                        desenareTabla_sv();
                    }
                else if(exista("salvare1.sv")==0 && men==0)
                    {
                        if(limba==0)
                            eroare_trasare("Nu exista joc salvat");
                        else
                            eroare_trasare("There is no saved game");
                    }

            }

            if(limba==0)
            {
                if(exista("salvare2.sv")==0)
                {
                    width=textwidth("SALVARE 2");
                    height=textheight("SALVARE 2");
                }
                else
                {
                    width=textwidth("*SALVARE 2*");
                    height=textheight("*SALVARE 2");
                }
            }
            else
            {
                if(exista("salvare2.sv")==0)
                {
                    width=textwidth("SAVE 2");
                    height=textheight("SAVE 2");
                }
                else
                {
                    width=textwidth("*SAVE 2*");
                    height=textheight("*SAVE 2*");
                }
            }
            if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2 && y<=getmaxy()/2+height)
            {

                if(men==1)
                    {
                        if(limba==0 && intrebare("SALVARE 2")==1)
                        {
                            salvare("salvare2.sv");
                            citire("salvare2.sv");
                            men=cmen;
                            desenareTabla_sv();
                        }
                        else if(limba==1 && intrebare("SAVE 2")==1)
                        {
                            salvare("salvare2.sv");
                            citire("salvare2.sv");
                            men=cmen;
                            desenareTabla_sv();
                        }
                    }
                else if(exista("salvare2.sv")==1 && men==0)
                    {
                        citire("salvare2.sv");
                        desenareTabla_sv();
                    }
                else if(exista("salvare2.sv")==0 && men==0)
                    {
                        if(limba==0)
                            eroare_trasare("Nu exista joc salvat");
                        else
                            eroare_trasare("There is no saved game");
                    }

            }

            if(limba==0)
            {
                if(exista("salvare3.sv")==0)
                {
                    width=textwidth("SALVARE 3");
                    height=textheight("SALVARE 3");
                }
                else
                {
                    width=textwidth("*SALVARE 3*");
                    height=textheight("*SALVARE 3*");
                }
            }
            else
            {
                if(exista("salvare3.sv")==0)
                {
                    width=textwidth("SAVE 3");
                    height=textheight("SAVE 3");
                }
                else
                {
                    width=textwidth("*SAVE 3*");
                    height=textheight("*SAVE 3*");
                }
            }
            if(x>=getmaxx()/2-width/2 && x<=getmaxx()/2+width/2 && y>=getmaxy()/2+200 && y<=getmaxy()/2+200+height)
            {
                if(men==1)
                    {
                        if(limba==0 && intrebare("SALVARE 3")==1)
                        {
                            salvare("salvare3.sv");
                            citire("salvare3.sv");
                            men=cmen;
                            desenareTabla_sv();
                        }
                        else if(limba==1 && intrebare("SAVE 3")==1)
                        {
                            salvare("salvare3.sv");
                            citire("salvare3.sv");
                            men=cmen;
                            desenareTabla_sv();
                        }
                    }
                else if(exista("salvare3.sv")==1 && men==0)
                    {
                        citire("salvare3.sv");
                        desenareTabla_sv();
                    }
                else if(exista("salvare3.sv")==0 && men==0)
                    {
                        if(limba==0)
                            eroare_trasare("Nu exista joc salvat");
                        else
                            eroare_trasare("There is no saved game");
                    }

            }

            if(x<=getmaxx()-40 && x>=getmaxx()-80 && y>=40 && y<=80) exit(1);
            else if((limba==1 && x<=textwidth("BACK")+40 && x>=40 && y>=40 && y<=textheight("BACK")+40) || (limba==0 && x<=textwidth("INAPOI")+40 && x>=40 && y>=40 && y<=textheight("INAPOI")+40))
                if(men==1)
                    {
                        salvare("back.sv");
                        citire("back.sv");
                        men=cmen;
                        desenareTabla_sv();
                    }
                else if(men==0)
                    {
                        meniu_prim();
                    }
            if(x<=getmaxx()-40 && y<=getmaxy()-40 && x>=getmaxx()-120 && y>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
        }
}


//RARES
void desenareTabla_sv()
{
    int x1,y1,n1,m1;
    cmen=men;
    cleardevice();
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,5);
    if(strcmp(nume1,"")==0)
        if(limba==0)
        {
            strcpy(nume1,"JUCATOR 1");
            z2=10;
        }
        else
        {
            strcpy(nume1,"PLAYER 1");
            z2=9;
        }
    if(strcmp(nume2,"")==0 && mod_joc==1)
        if(limba==0)
        {
            strcpy(nume2,"JUCATOR 2");
            z3=10;
        }
        else
        {
            strcpy(nume2,"PLAYER 2");
            z3=9;
        }
    if(mod_joc==2 || mod_joc==3)
        if(limba==0)
        {
            strcpy(nume2,"CALCULATORUL");
            z3=13;
        }
        else
        {
            strcpy(nume2,"THE COMPUTER");
            z3=13;
        }

    char u[5],l[5],b[5];
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    setbkcolor(0);
    setcolor(WHITE);
    settextstyle(10,HORIZ_DIR,7);

    if(mod_joc==1)
        if(limba==0)outtextxy(getmaxx()/2-textwidth("1v1")/2,getmaxy()/12-textheight("1v1")/2,"1v1");
        else outtextxy(getmaxx()/2-textwidth("1v1")/2,getmaxy()/12-textheight("1v1")/2,"1v1");
    if(mod_joc==2)
        if(limba==0)outtextxy(getmaxx()/2-textwidth("ANTRENAMENT")/2,getmaxy()/12-textheight("ANTRENAMENT")/2,"ANTRENAMENT");
        else outtextxy(getmaxx()/2-textwidth("TRAINING")/2,getmaxy()/12-textheight("TRAINING")/2,"TRAINING");
    if(mod_joc==3)
        if(limba==0)outtextxy(getmaxx()/2-textwidth("STRATEGIE")/2,getmaxy()/12-textheight("STRATEGIE")/2,"STRATEGIE");
        else outtextxy(getmaxx()/2-textwidth("STRATEGY")/2,getmaxy()/12-textheight("STRATEGY")/2,"STRATEGY");

    setcolor(15);
    //colturi tabla
    line(xc-5,yc-5,xc-5,yc-5+50);
    line(xc-5,yc-5,xc+50-5,yc-5);
    line(maxx-xc+5,yc-5,maxx-xc+5,yc+50-5);
    line(maxx-xc+5,yc-5,maxx-xc-50+5,yc-5);
    line(maxx-xc+5,maxy-yc+5,maxx-xc+5,maxy-yc-50+5);
    line(maxx-xc+5,maxy-yc+5,maxx-xc-50+5,maxy-yc+5);
    line(xc-5,maxy-yc+5,xc-5,maxy-yc-50+5);
    line(xc-5,maxy-yc+5,xc+50-5,maxy-yc+5);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);

    if(limba==0)
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");
        outtextxy(40,50+textheight("INAPOI"),"SALVEAZA");
        if(timp==1) outtextxy(xc-25,getmaxy()/14-textheight("TIMP:")/2,"TIMP:");
    }
    else
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");
        outtextxy(40,50+textheight("BACK"),"SAVE");
        if(timp==1) outtextxy(xc-25,getmaxy()/14-textheight("TIME:")/2,"TIME:");
    }

    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {

            if((a[i][j].tip_pct==1 || a[i][j].tip_pct==2)&& a[i][j].check==1)
            {
                setcolor(15);
                setfillstyle(SOLID_FILL, 15);
                fillellipse(a[i][j].x,a[i][j].y,8,8);
            }
            else if((a[i][j].tip_pct==3)&& a[i][j].check==1)
                stea(a[i][j].x,a[i][j].y,8,15,1);

        }

    for(int i=0;i<nrseg; i++)
    {
        line(seg[i].p1.x*10,seg[i].p1.y*10,seg[i].p2.x*10,seg[i].p2.y*10);
        setcolor(15);
        setfillstyle(SOLID_FILL, 15);
        fillellipse(seg[i].p1.x*10,seg[i].p1.y*10,8,8);
        fillellipse(seg[i].p2.x*10,seg[i].p2.y*10,8,8);
    }


    char scor1[5],scor2[5];
    sprintf(scor1,"%d",sco1);
    sprintf(scor2,"%d",sco2);
    setcolor(WHITE);
    settextstyle(10,HORIZ_DIR,8);
    outtextxy(xc/2-textwidth(scor1)/2,maxy/2-textheight(scor1)/2,scor1);
    outtextxy(maxx-xc/2-textwidth(scor2)/2,maxy/2-textheight(scor2)/2,scor2);
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(xc/2-textwidth(nume1)/2,maxy/2+2*textheight(nume1),nume1);
    outtextxy(maxx-xc/2-textwidth(nume2)/2,maxy/2+2*textheight(nume2),nume2);

    settextstyle(10,HORIZ_DIR,5);
    setcolor(WHITE);
    sprintf(l,"%d",libere);
    sprintf(u,"%d",utilizate);
    sprintf(b,"%d",blocate);
    outtextxy(maxx-xc-140,getmaxy()/14-textheight("L")/2,"L");
    outtextxy(maxx-xc-75,getmaxy()/14-textheight("L")/2,"U");
    outtextxy(maxx-xc-10,getmaxy()/14-textheight("L")/2,"B");
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(maxx-xc-140,getmaxy()/10-textheight(l)/2,l);
    outtextxy(maxx-xc-75,getmaxy()/10-textheight(u)/2,u);
    outtextxy(maxx-xc-10,getmaxy()/10-textheight(b)/2,b);

    settextstyle(10,HORIZ_DIR,5);
    if(mod_joc==1)
        play1();
    else if(mod_joc==2)
        play2();
    else play3();
}


//OCTAVIAN
void desenareTabla(int n)
{
    cleardevice();
    cmen=men;
    readimagefile("fundal.jpg",0,0,getmaxx(),getmaxy());
    if(sunet==1)
        readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    else if(sunet==0)
        readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(10,getmaxy()-20,"Dascalu Rares-Vasilica && Gavril Octavian");
    settextstyle(10,HORIZ_DIR,5);
    if(strcmp(nume1,"")==0)
        if(limba==0)
        {
            strcpy(nume1,"JUCATOR 1");
            z2=10;
        }
        else
        {
            strcpy(nume1,"PLAYER 1");
            z2=9;
        }
    if(strcmp(nume2,"")==0 && mod_joc==1)
        if(limba==0)
        {
            strcpy(nume2,"JUCATOR 2");
            z3=10;
        }
        else
        {
            strcpy(nume2,"PLAYER 2");
            z3=9;
        }
    if(mod_joc==2 || mod_joc==3)
        if(limba==0)
        {
            strcpy(nume2,"CALCULATORUL");
            z3=13;
        }
        else
        {
            strcpy(nume2,"THE COMPUTER");
            z3=13;
        }
    sco1=0;
    sco2=0;
    libere=n;
    utilizate=0;
    blocate=0;
    tura=0;
    initializare_puncte();
    initializare_segmente();
    char u[5],l[5],b[5];
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    setbkcolor(0);
    setcolor(WHITE);
    settextstyle(10,HORIZ_DIR,7);

    if(mod_joc==1)
        if(limba==0)outtextxy(getmaxx()/2-textwidth("1v1")/2,getmaxy()/12-textheight("1v1")/2,"1v1");
        else outtextxy(getmaxx()/2-textwidth("1v1")/2,getmaxy()/12-textheight("1v1")/2,"1v1");
    if(mod_joc==2)
        if(limba==0)outtextxy(getmaxx()/2-textwidth("ANTRENAMENT")/2,getmaxy()/12-textheight("ANTRENAMENT")/2,"ANTRENAMENT");
        else outtextxy(getmaxx()/2-textwidth("TRAINING")/2,getmaxy()/12-textheight("TRAINING")/2,"TRAINING");
    if(mod_joc==3)
        if(limba==0)outtextxy(getmaxx()/2-textwidth("STRATEGIE")/2,getmaxy()/12-textheight("STRATEGIE")/2,"STRATEGIE");
        else outtextxy(getmaxx()/2-textwidth("STRATEGY")/2,getmaxy()/12-textheight("STRATEGY")/2,"STRATEGY");

    setcolor(15);
    //colturi tabla
    line(xc-5,yc-5,xc-5,yc-5+50);
    line(xc-5,yc-5,xc+50-5,yc-5);
    line(maxx-xc+5,yc-5,maxx-xc+5,yc+50-5);
    line(maxx-xc+5,yc-5,maxx-xc-50+5,yc-5);
    line(maxx-xc+5,maxy-yc+5,maxx-xc+5,maxy-yc-50+5);
    line(maxx-xc+5,maxy-yc+5,maxx-xc-50+5,maxy-yc+5);
    line(xc-5,maxy-yc+5,xc-5,maxy-yc-50+5);
    line(xc-5,maxy-yc+5,xc+50-5,maxy-yc+5);
    readimagefile("butonX.jpg",getmaxx()-80,40,getmaxx()-40,80);

    if(limba==0)
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"INAPOI");
        outtextxy(40,50+textheight("INAPOI"),"SALVEAZA");
        if(timp==1) outtextxy(xc-25,getmaxy()/14-textheight("TIMP:")/2,"TIMP:");
    }
    else
    {
        setcolor(WHITE);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(40,40,"BACK");
        outtextxy(40,50+textheight("BACK"),"SAVE");
        if(timp==1) outtextxy(xc-25,getmaxy()/14-textheight("TIME:")/2,"TIME:");
    }

    srand(time(0));
    for(int i=1; i<=n; i++)
    {
        int x=(10*(2*rand()+1))%(maxx-xc);
        int y=(10*(2*rand()+1))%(maxy-yc);
        while(a[x/10][y/10].check!=0 || (x<xc || x>(maxx-xc)) || (y<yc || y>(maxy-yc)))
        {
            x=(10*(2*rand()+1))%(maxx-xc);
            y=(10*(2*rand()+1))%(maxy-yc);
        }

        a[x/10][y/10].x=x;
        a[x/10][y/10].y=y;

        setcolor(15);
        setfillstyle(SOLID_FILL, 15);
        fillellipse(x,y,8,8);
        a[x/10][y/10].check=1;
        a[x/10][y/10].tip_pct=2;
    }
    char scor1[5],scor2[5];
    sprintf(scor1,"%d",sco1);
    sprintf(scor2,"%d",sco2);
    setcolor(WHITE);
    settextstyle(10,HORIZ_DIR,8);
    outtextxy(xc/2-textwidth(scor1)/2,maxy/2-textheight(scor1)/2,scor1);
    outtextxy(maxx-xc/2-textwidth(scor2)/2,maxy/2-textheight(scor2)/2,scor2);
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(xc/2-textwidth(nume1)/2,maxy/2+2*textheight(nume1),nume1);
    outtextxy(maxx-xc/2-textwidth(nume2)/2,maxy/2+2*textheight(nume2),nume2);
    settextstyle(10,HORIZ_DIR,5);
    setcolor(WHITE);
    sprintf(l,"%d",libere);
    sprintf(u,"%d",utilizate);
    sprintf(b,"%d",blocate);
    outtextxy(maxx-xc-140,getmaxy()/14-textheight("L")/2,"L");
    outtextxy(maxx-xc-75,getmaxy()/14-textheight("L")/2,"U");
    outtextxy(maxx-xc-10,getmaxy()/14-textheight("L")/2,"B");
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(maxx-xc-140,getmaxy()/10-textheight(l)/2,l);
    outtextxy(maxx-xc-75,getmaxy()/10-textheight(u)/2,u);
    outtextxy(maxx-xc-10,getmaxy()/10-textheight(b)/2,b);

    settextstyle(10,HORIZ_DIR,5);
    if(mod_joc==1)
        play1();
    else if(mod_joc==2)
        play2();
    else play3();
}

//OCTAVIAN
void simulare_puncte_blocate(int &bloc)
{

    int xc,yc,maxx,maxy;
    bool ok;
    dimensiuni_tabla(xc,yc,maxx,maxy);

    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {
            ok=true;
            if(a[i][j].tip_pct==2)
            {
                for(int h=xc/10+1; h<=maxx/10-xc/10-1; h++)
                    for(int k=yc/10+1; k<=maxy/10-yc/10-1; k++)
                    {
                        char text[50];
                        if(a[h][k].tip_pct==2 && (i!=h || j!=k) && validitate(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y,text)==true)
                            ok=false;
                    }
                if(ok==true)
                {
                    bloc++;
                }
            }
        }
}
//OCTAVIAN
void memoreaza_mutare(int x1,int y1, int x2,int y2)
{
    mutare.p1.x=x1;
    mutare.p1.y=y1;
    mutare.p2.x=x2;
    mutare.p2.y=y2;
}
//OCTAVIAN
void sterge_seg()
{
    seg[nrseg].p1.x=0;
    seg[nrseg].p1.y=0;
    seg[nrseg].p2.x=0;
    seg[nrseg].p2.y=0;
    nrseg--;
}
//OCTAVIAN
int posibile_mutari()
{
    int xc,yc,maxx,maxy,nr=0;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    char text[50];
    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {
            if(a[i][j].tip_pct==2)
            {
                for(int h=xc/10+1; h<=maxx/10-xc/10-1; h++)
                    for(int k=yc/10+1; k<=maxy/10-yc/10-1; k++)
                        if(a[h][k].tip_pct==2 && validitate(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y,text)==true && (i!=h || j!=k))
                        {
                            nr++;
                        }
            }
        }
    return nr;
}
//OCTAVIAN
void rand_jucator(int c)
{
    int xc,yc,maxx,maxy,x1,y1,x2,y2;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    setcolor(15);
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(xc/2-textwidth(nume1)/2,maxy/2+2*textheight(nume1),nume1);
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(maxx-xc/2-textwidth(nume2)/2,maxy/2+2*textheight(nume2),nume2);
    if(c==0)
    {
        settextstyle(10,HORIZ_DIR,4);
        x1=xc/2-textwidth(nume1)/2;
        y1=maxy/2+2*textheight(nume1)+1;
        x2=xc/2+textwidth(nume1)/2;
        y2=maxy/2+3*textheight(nume1)-1;
    }
    else
    {
        settextstyle(10,HORIZ_DIR,4);
        x1=maxx-xc/2-textwidth(nume2)/2;
        y1=maxy/2+2*textheight(nume2)+1;
        x2=maxx-xc/2+textwidth(nume2)/2;
        y2=maxy/2+3*textheight(nume2)-1;
    }
        setcolor(15);
        line(x1,y1,x1+5,y1);
        line(x1,y1,x1,y1+5);
        line(x1,y2,x1,y2-5);
        line(x1,y2,x1+5,y2);
        line(x2,y1,x2-5,y1);
        line(x2,y1,x2,y1+5);
        line(x2,y2,x2-5,y2);
        line(x2,y2,x2,y2-5);
}
//OCTAVIAN
void desenare_strategica(int c)
{
    int xc,yc,maxx,maxy,v[100],bmax,maxblocate=-1,min_mutari=9999999,k;

    dimensiuni_tabla(xc,yc,maxx,maxy);
    setcolor(0);
    outtextxy(xc-25,getmaxy()/10-textheight(ceas)/2,"      ");
    setcolor(15);
    if(c==1)
    {
        setcolor(14);
    }
    rand_jucator(c);
    k=n%4;
    if(k==0 || k==3) bmax=n/3+1;
    else bmax=n/3;
    int l=0;
    v[l]=l*4+k;
    while(v[l]<bmax) v[++l]=l*4+k;
    v[l]=bmax;
    int poz=0,ok=0;
    char text[50];
    for(int i=xc/10+1; i<=maxx/10-xc/10-1; i++)
        for(int j=yc/10+1; j<=maxy/10-yc/10-1; j++)
        {
            if(a[i][j].tip_pct==2)
            {
                for(int h=xc/10+1; h<=maxx/10-xc/10-1; h++)
                    for(int k=yc/10+1; k<=maxy/10-yc/10-1; k++)
                        if(a[h][k].tip_pct==2 && validitate(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y,text)==true && (i!=h || j!=k))
                        {
                            int copie_blocate=blocate;
                            adauga_seg(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y);
                            a[a[h][k].x/10][a[h][k].y/10].tip_pct=1;
                            a[a[i][j].x/10][a[i][j].y/10].tip_pct=1;

                            simulare_puncte_blocate(copie_blocate);
                            if(blocate==v[poz] && copie_blocate==blocate && min_mutari>=posibile_mutari())
                            {
                                ok=1;
                                min_mutari=posibile_mutari();
                                memoreaza_mutare(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y);
                            }
                            else if(blocate>v[poz] && poz<l && copie_blocate<=v[poz+1] && copie_blocate>maxblocate && min_mutari>=posibile_mutari())
                            {
                                ok=1;
                                maxblocate=copie_blocate;
                                min_mutari=posibile_mutari();
                                memoreaza_mutare(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y);
                                poz++;
                            }
                            else if(blocate<v[poz] && copie_blocate>maxblocate && copie_blocate<=v[poz] && min_mutari>=posibile_mutari())
                            {
                                ok=1;
                                maxblocate=copie_blocate;
                                min_mutari=posibile_mutari();
                                memoreaza_mutare(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y);
                            }
                            else if(min_mutari>=posibile_mutari())
                            {
                                ok=1;
                                min_mutari=posibile_mutari();
                                memoreaza_mutare(a[i][j].x,a[i][j].y,a[h][k].x,a[h][k].y);
                            }
                            sterge_seg();
                            a[a[h][k].x/10][a[h][k].y/10].tip_pct=2;
                            a[a[i][j].x/10][a[i][j].y/10].tip_pct=2;
                        }
                if(ok==1)
                    goto gasit;
            }
        }
gasit:
    int x1=mutare.p1.x;
    int y1=mutare.p1.y;
    int x2=mutare.p2.x;
    int y2=mutare.p2.y;
    setcolor(14);
    adauga_seg(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL, 14);
    delay(500);
    fillellipse(x1,y1,8,8);
    delay(500);
    fillellipse(x2,y2,8,8);
    delay(500);
    line(x1,y1,x2,y2);
    delay(500);
    setcolor(15);
    line(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL, 15);
    fillellipse(x1,y1,8,8);
    fillellipse(x2,y2,8,8);
    a[x2/10][y2/10].tip_pct=1;
    a[x1/10][y1/10].tip_pct=1;
    creste_scor(c);
    modificare_date();
}

//OCTAVIAN
void desenaresegmentAUTO(int c)
{
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    setcolor(0);
    outtextxy(xc-25,getmaxy()/10-textheight(ceas)/2,"      ");
    setcolor(15);
    if(c==1)
    {
        setcolor(14);
    }
    rand_jucator(c);
    int x=(10*(2*rand()+1))%(maxx-xc);
    int y=(10*(2*rand()+1))%(maxy-yc);
    while(1)
    {
        x=(10*(2*rand()+1))%(maxx-xc);
        y=(10*(2*rand()+1))%(maxy-yc);
        if(a[x/10][y/10].tip_pct==2 && (x>xc && x<(maxx-xc)) && (y>yc && y<(maxy-yc)))
                break;
    }
    int x1=x;
    int y1=y;

    x=(10*(2*rand()+1))%(maxx-xc);
    y=(10*(2*rand()+1))%(maxy-yc);
    char text[50];
    while(1)
    {
        x=(10*(2*rand()+1))%(maxx-xc);
        y=(10*(2*rand()+1))%(maxy-yc);
        if(a[x/10][y/10].tip_pct==2 && (x1!=x || y1!=y) && (x>xc && x<(maxx-xc)) && (y>yc && y<(maxy-yc)) && validitate(a[x1/10][y1/10].x,a[x1/10][y1/10].y,a[x/10][y/10].x,a[x/10][y/10].y,text)==true)
                break;

    }
    int x2=x;
    int y2=y;
    setcolor(14);
    adauga_seg(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL, 14);
    fillellipse(x1,y1,8,8);
    delay(500);
    fillellipse(x2,y2,8,8);
    delay(500);
    line(x1,y1,x2,y2);
    delay(500);
    setcolor(15);
    line(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL, 15);
    fillellipse(x1,y1,8,8);
    fillellipse(x2,y2,8,8);
    a[x2/10][y2/10].tip_pct=1;
    a[x1/10][y1/10].tip_pct=1;
    creste_scor(c);
    modificare_date();
}

//RARES
void desenaresegment(int c)
{
    std::thread t1(countdown);
    cn=copie_cn;
    settextstyle(10,HORIZ_DIR,5);
    if(timp==0) cn=-2;
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    int x1,y1,x2,y2,i,j;
    bool c1,c2;
    rand_jucator(c);
punct1:
    c1=0;
    while(1)
    {
        if(cn==-1) mesaj_final();
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x1=mousex();
            y1=mousey();
            settextstyle(10,HORIZ_DIR,5);
            if(x1<=getmaxx()-40 && x1>=getmaxx()-80 && y1>=40 && y1<=80) exit(1);
            else if(x1<=getmaxx()-40 && y1<=getmaxy()-40 && x1>=getmaxx()-120 && y1>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
            if((limba==1 && x1<=textwidth("BACK")+40 && x1>=40 && y1>=40 && y1<=textheight("BACK")+40) || (limba==0 && x1<=textwidth("INAPOI")+40 && x1>=40 && y1>=40 && y1<=textheight("INAPOI")+40))
                if(men==0)
                {
                    cn=-2;
                    t1.join();
                    meniu_salvari();
                }
                else if(mod_joc==1)
                {
                    cn=-2;
                    t1.join();
                    meniu2();
                }
                else if(mod_joc==2 || mod_joc==3)
                {
                    cn=-2;
                    t1.join();
                    meniu4();
                }
            if((limba==1 && x1<=textwidth("SAVE")+40 && x1>=40 && y1>=50+textheight("BACK") && y1<=50+textheight("BACK")+textheight("SAVE")) || (limba==0 && x1<=textwidth("SALVEAZA")+40 && x1>=40 && y1>=50+textheight("INAPOI") && y1<=50+textheight("INAPOI")+textheight("SALVEAZA")))
                {
                    cn=-2;
                    t1.join();
                    men=1;
                    meniu_salvari();
                }
            settextstyle(10,HORIZ_DIR,3);
            for(i=xc/10+1; i<=maxx/10-xc/10-1; i++)
                for(j=yc/10+1; j<=maxy/10-yc/10-1; j++)
                {
                    if(((a[i][j].x-x1)*(a[i][j].x-x1)+(a[i][j].y-y1)*(a[i][j].y-y1))<64)
                    {
                        x1=a[i][j].x;
                        y1=a[i][j].y;
                        if(a[x1/10][y1/10].tip_pct==2) c1=1;
                    }
                }
            if(c1==1)
            {
                setcolor(14);
                setfillstyle(SOLID_FILL, 14);
                fillellipse(x1,y1,8,8);
            }
            if(a[x1/10][y1/10].tip_pct==1) goto punct1;

            break;
        }
    }
punct2:
    c2=0;
    while(1)
    {
        if(cn==-1) mesaj_final();
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x2=mousex();
            y2=mousey();
            settextstyle(10,HORIZ_DIR,5);
            if(x2<=getmaxx()-40 && x2>=getmaxx()-80 && y2>=40 && y2<=80) exit(1);
            else if(x2<=getmaxx()-40 && y2<=getmaxy()-40 && x2>=getmaxx()-120 && y2>=getmaxy()-120)
            {
                if(sunet==1)
                {
                    readimagefile("mute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(NULL,NULL,SND_ASYNC);
                    sunet=0;
                }
                else if(sunet==0)
                {
                    readimagefile("unmute.jpg",getmaxx()-120,getmaxy()-120,getmaxx()-40,getmaxy()-40);
                    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
                    sunet=1;
                }
            }
            if((limba==1 && x2<=textwidth("BACK")+40 && x2>=40 && y2>=40 && y2<=textheight("BACK")+40) || (limba==0 && x2<=textwidth("INAPOI")+40 && x2>=40 && y2>=40 && y2<=textheight("INAPOI")+40))
                if(men==0)
                {
                    cn=-2;
                    t1.join();
                    meniu_salvari();
                }
                else if(mod_joc==1)
                {
                    cn=-2;
                    t1.join();
                    meniu2();
                }
                else if(mod_joc==2 || mod_joc==3)
                {
                    cn=-2;
                    t1.join();
                    meniu4();
                }
            if((limba==1 && x1<=textwidth("SAVE")+40 && x1>=40 && y1>=50+textheight("BACK") && y1<=50+textheight("BACK")+textheight("SAVE")) || (limba==0 && x1<=textwidth("SALVEAZA")+40 && x1>=40 && y1>=50+textheight("INAPOI") && y1<=50+textheight("INAPOI")+textheight("SALVEAZA")))
                {
                    cn=-2;
                    t1.join();
                    men=1;
                    meniu_salvari();
                }
            settextstyle(10,HORIZ_DIR,3);
            for(i=xc/10+1; i<=maxx/10-xc/10-1; i++)
                for(j=yc/10+1; j<=maxy/10-yc/10-1; j++)
                {
                    if(((a[i][j].x-x2)*(a[i][j].x-x2)+(a[i][j].y-y2)*(a[i][j].y-y2))<64)
                    {
                        x2=a[i][j].x;
                        y2=a[i][j].y;
                        if(a[x2/10][y2/10].tip_pct==2) c2=1;
                    }
                }
            break;
        }
    }
    char eroare[50];
    if(x1==x2 && y1==y2)
    {
        if(c1==1 && c2==1)
        {
            setcolor(15);
            setfillstyle(SOLID_FILL,15);
            fillellipse(x1,y1,8,8);
        }
        goto punct1;
    }
    if(c1==1 && c2==1 && validitate(x1,y1,x2,y2,eroare))
    {
        if(timp==1 && cn==-1) mesaj_final();
        setcolor(14);
        line(x1,y1,x2,y2);
        adauga_seg(x1,y1,x2,y2);
        setfillstyle(SOLID_FILL,14);
        fillellipse(x2,y2,8,8);
        a[x2/10][y2/10].tip_pct=1;
        a[x1/10][y1/10].tip_pct=1;
        cn=-2;
        delay(500);
        setcolor(15);
        line(x1,y1,x2,y2);
        setfillstyle(SOLID_FILL, 15);
        fillellipse(x1,y1,8,8);
        fillellipse(x2,y2,8,8);
        creste_scor(c);
        modificare_date();
        t1.join();
    }
    else if(c1==1 && c2==1)
    {
        if(strlen(eroare)>10)
            eroare_trasare(eroare);
        a[x2/10][y2/10].tip_pct=2;
        a[x1/10][y1/10].tip_pct=2;
        goto punct2;
    }
    else if(c1==1)
    {
        a[x1/10][y1/10].tip_pct=2;
        goto punct2;
    }
    else goto punct1;

}
//OCTAVIAN
void play3()
{
    while(libere!=0)
    {
        if(tura==0)
        {
            desenaresegment(0);
            tura=1;
        }
        else
        {
            desenare_strategica(1);
            tura=0;
        }
    }
    mesaj_final();
}
//OCTAVIAN
void play2()
{
    while(libere!=0)
    {
        if(tura==0)
        {
            desenaresegment(0);
            tura=1;
        }
        else
        {
            desenaresegmentAUTO(1);
            tura=0;
        }
    }
    mesaj_final();
}

//RARES
void play1()
{

    while(libere!=0)
    {
        if(tura==0)
        {
            desenaresegment(0);
            tura=1;
        }
        else
        {
            desenaresegment(1);
            tura=0;
        }
    }
    mesaj_final();
}

//RARES
void countdown()
{
    int puncte_nr[10];
    int xc,yc,maxx,maxy;
    dimensiuni_tabla(xc,yc,maxx,maxy);
    if(timp==0) goto sfarsit;
    while(cn>=0)
    {
        if(cn>9)
        {
            ceas[0]=cn/10+'0';
            ceas[1]=cn%10+'0';
            ceas[2]=NULL;
            strcat(ceas,"sec");
        }
        else
        {
            ceas[0]=cn+'0';
            ceas[1]=NULL;
            strcat(ceas,"sec ");
        }
        setcolor(15);
        settextstyle(10,HORIZ_DIR,4);
        outtextxy(xc-25,getmaxy()/10-textheight(ceas)/2,ceas);
        if(cn!=0) delay(1000);
        else delay(0);
        if(cn==-2)
        {
            delay(0);
        }
        cn--;
    }
    sfarsit:
    strcpy(ceas,copie_ceas);
}

int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth,screenHeight,"",-3,-3);
    PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
    sunet=1;
    meniu_prim();
    getch();
    return 0;
}
