#include <iostream>
#include "ncaa.h"
#include <ctime>
#include <random>

using namespace std;

double bout( region * w1, region * w2, default_random_engine * gptr);

int main()
{   default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));

    uniform_int_distribution<int> Sread(1,100);
    int x = Sread(*gptr);


    region * section[15];
    region * section2[15];
    for(int i=0; i<15; i++){section[i]=NULL;
                            section2[i]=NULL;}

    region * tptr=NULL;
    int num1, T;
    int num2;
    cout<<"How many wrestlers will compete on Team 1?"<<endl;
    cin>>num1;
    cout<<"Stats are as follows;"<<endl;
    for(int i=0; i<num1; i++)
    {
     tptr = new region(gptr);
     tptr->display();

     T = tptr->getType();

     if(section[T]==NULL){section[T] = tptr;}

     else{if(section[T]->getPscore()<tptr->getPscore())
            {
                delete section[T];
                section[T]=tptr;
            }
     }
    }
    cout<<endl;
    cout<<"Team 1"<<endl;

    for(int i=0; i<15; i++)
    {   cout<<"wt class #"<<i<<": ";
        if(section[i]!=NULL)section[i]->display();
        else{cout<<"position is empty"<<endl;}
    }

    cout<<endl;
    cout<<"How many wrestlers are on Team 2?"<<endl;
    cin>>num2;
    cout<<"stats are as follows;"<<endl;
    for(int i=0; i<num2; i++)
    {cout<<"creating team 2 #"<<i<<endl;
     tptr = new region(gptr);
     tptr->display();

     T = tptr->getType();

     if(section2[T]==NULL){section2[T] = tptr; cout<<"assigning at "<<T<<endl;}
     else{
            if(section2[T]->getPscore()<tptr->getPscore())
            {
                delete section2[T];
                section2[T]=NULL;
                section2[T]=tptr;
                cout<<"replacing at "<<T<<endl;
            }
        }
    }
    cout<<endl;
    cout<<"Team 2"<<endl;

      for(int i=0; i<15; i++)
        {
        cout<<"wt class #"<<i<<": ";
        if(section2[i]!=NULL){section2[i]->display();}
        else{cout<<"position is empty0"<<endl;}
        }


    cout<<"*************************"<<endl;
    {

    int teamS1=0;
    int teamS2=0;
    double diff=0;
    for(int i=0; i<14; i++)
    {
        diff=bout(section[i], section2[i], gptr);
        cout<<"Diff = "<<diff<<endl;
        if(diff>0)
        {
            if(diff>17){teamS1=teamS1+6;}
            else if(diff>15){teamS1=teamS1+5;}
            else if(diff>8) {teamS1-teamS1+4;}
            else if(diff>1) {teamS1-teamS1+3;}
        }
        else
        {
            diff=abs(diff);
            if(diff>15){teamS2=teamS2+6;}
            else if(diff>15){teamS2=teamS2+5;}
            else if(diff>8) {teamS2-teamS2+4;}
            else if(diff>1) {teamS2-teamS2+3;}
        }
        }

    cout<<"Team 1 score: "<<teamS1<<endl;
    cout<<"Team 2 score: "<<teamS2<<endl;
 return 0;
 }
}

double bout( region * w1, region * w2, default_random_engine * gptr)
{
    double s1;
    double s2;
    double diff=0;

    if((w1==NULL)&&(w2==NULL)){return 0;}
    else if((w1!=NULL)&&(w2==NULL)){return 16;}
    else if((w1==NULL&&w2!=NULL)){return -16;}
    else{
    double a1;
    a1 = w1->getPscore();
    double a2;
    a2 = w2->getPscore();

    normal_distribution<double> a1dist(a1, 15);
    normal_distribution<double> a2dist(a2, 15);

    s1 = a1dist(*gptr);
    s2 = a2dist(*gptr);
    w1->display();
    cout<<"  versus "<<endl;
    w2->display();
    diff=s1-s2;
    if(s1>s2){cout<<"Team 1 wins! "<<s1<<" to "<<s2<<endl;}
    else if(s2>s1){cout<<"Team 2 wins! "<<s2<<" to "<<s1<<endl;}

    return diff;
    }
}
