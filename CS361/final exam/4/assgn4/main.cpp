///Name: Zephaniah Amonoo-Harrison
///UIN: 01085332
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Box{
    private:
    int id;
    public:
    Box(int d)
    {
        id=d;
    }
    int box_id()
    {
        return id;
    }
};

void showlist(list <Box> b)
{
    list <Box> :: iterator it;
    for(it=b.begin(); it!=b.end(); ++it)
    cout<< it->box_id() <<" ";
    cout << '\n'<<endl;
}

int main()
{
    int a,i,c;
    cout<<"How many boxes would you like to create?"<<endl;
    cin>>a;
    list<Box> lst;
    int uniq[a]={0};
    priority_queue<int> pq;
    for(int i=0;i<a;i++)
    {
        int r=rand()%100+1;
        Box b(r);
        lst.push_back(b);
    }
    cout<<"Showing generated boxes\n"<<endl;
    showlist(lst);

    list <Box> :: iterator it;
    for(it=lst.begin(); it!=lst.end(); ++it)
    pq.push(it->box_id());

    cout<<"\nShowing content in priority queue\n"<<endl;
    for(i=0;i<a;i++)
        {
            int val=pq.top();
            pq.pop();
            cout<<val<<" "<<endl;
            for(c=0;c<a;c++)
                {
                    if(val==uniq[c])
                    break;
                    if (uniq[c]==0)
                        {
                            uniq[c]=val;
                            break;
                        }
    }
    }

    cout<<"\nShowing content for a third time\n"<<endl;
    for(i=0;i<a;i++)
    {
        if(uniq[i]==0)
        break;
        cout<<uniq[i]<<" "<<endl;
    }
    return 0;
}
