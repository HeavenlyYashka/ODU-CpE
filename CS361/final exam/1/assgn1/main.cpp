///Name: Zephaniah Amonoo-Harrison
///UIN: 01085332
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <queue>

using namespace std;
class DataSample
{
    private:
    int ID=0;
    double Freq=0.0;
    double Mag=0.0;
    public:
    DataSample()
    {
        this->ID=0;
        this->Freq=0;
        this->Mag=0;
    }
    void set(int i)
    {
        this->ID=i;
        this->Freq=(rand()%3000000)+300;
        this->Mag=(rand()%50000)+10000;
    }

    void display() const
    {
        cout<<"ID = "<<this->ID<<endl;
        cout<<"Frequency = "<<this->Freq<<endl;
        cout<<"Magnitude = "<<this->Mag<<endl;
    }
    double getId()
    {
        return this->ID;
    }
    double getFreq()
    {
        return this->Freq;
    }
    double getMag()
    {
        return this->Mag;
    }

};
struct CompareFreq
{
    bool operator()(DataSample& d1, DataSample& d2)
    {
        if (d1.getFreq() > d2.getFreq()) return true;
        return false;
    }
};

int main()
{
    srand(time(0));

    DataSample *value=NULL;
    priority_queue<DataSample,vector<DataSample>,CompareFreq>Q1;
    priority_queue<DataSample,vector<DataSample>,CompareFreq>Q2;
    priority_queue<DataSample,vector<DataSample>,CompareFreq>Q3;
    priority_queue<DataSample,vector<DataSample>,CompareFreq>Q4;

    cout<<"Insert count"<<endl;
    int objectcount=0;
    cin>>objectcount;
    value=new DataSample[objectcount];

    for(int i=0;i<objectcount;i++)
    {
        value[i].set(i+1);
        value[i].display();
        if(value[i].getMag()>=40000)
            {
                Q4.push(value[i]);
            }
        else if(value[i].getMag()>=30000)
        {
            Q3.push(value[i]);
        }
        else if(value[i].getMag()>=20000)
        {
            Q2.push(value[i]);
        }
        else
        {
            Q1.push(value[i]);
        }
    }

    priority_queue<DataSample,vector<DataSample>,CompareFreq> Temp;
    cout<<"Q1 contains = "<<endl;
    Temp=Q1;
    while (!Temp.empty())
    {
        Temp.top().display();
        Temp.pop();
    }
    cout <<'\n'<<endl;

    cout<<"Q2 contains = "<<endl;
    Temp=Q2;
    while (!Temp.empty())
    {
        Temp.top().display();
        Temp.pop();
    }
    cout <<'\n'<<endl;;

    cout<<"Q3 contains = "<<endl;
    Temp=Q3;
    while (!Temp.empty())
    {
        Temp.top().display();
        Temp.pop();
    }
    cout <<'\n'<<endl;

    cout<<"Q4 contains = "<<endl;
    Temp=Q4;
    while (!Temp.empty())
    {
        Temp.top().display();
        Temp.pop();
    }
    cout <<'\n'<<endl;
    return 0;
}
