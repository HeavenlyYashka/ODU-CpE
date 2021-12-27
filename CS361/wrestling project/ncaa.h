#include <iostream>
#include <random>

using namespace std;

class region
{
public:
    region(){}
    ~region(){}
    region(default_random_engine * gptr)
        {
        uniform_int_distribution<int> tdist(0,14);
        uniform_int_distribution<int> pdist(1,100);
        type = tdist(*gptr);
        pscore = pdist(*gptr);
        full = true;
        }
    void unload(){full = false;}
    void display(){cout<<"wrestling class: "<<type<<" ability score: "<<pscore;
    cout << endl;
                  }
    int getType(){return type;}
    int getPscore(){return pscore;}


private:
    bool full;
    int type;
    int pscore;
};

