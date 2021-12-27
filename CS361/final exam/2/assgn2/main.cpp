///Name: Zephaniah Amonoo-Harrison
///UIN: 01085332
#include <iostream>
#include <cstdlib>

using namespace std;
class Shape{
    private:int NumSides;

    public:Shape*next;

        void set_sides(int n)
        {
            NumSides=n;
        }

        int get_side()
        {
            return NumSides;
        }

        void display()
        {
            printf("%d sides",NumSides);
        }
};

class Rect:public Shape{
    private:int width,height,area;

    public:Rect(int w,int h)
        {
            width=w;
            height=h;
            area=w*h;
        }

        void display()
        {
            printf(" = rectangle %d, %d, area %d\n",width,height,area);
        }
};

class Tri:public Shape{

private:int perimeter, side[3];

public:
    Tri(int x,int y,int z)
    {
        side[0] = x;
        side[1] = y;
        side[2] = z;

        perimeter = x+y+z;
    }

    void display()
    {
        printf(" = triangle %d, %d, %d, perimeter %d\n",side[0],side[1],side[2],perimeter);
    }
};


int main()
{
    int numberofsides;

    cout<<"Number of sides?"<<endl;
    cin>>numberofsides;

    Shape*shape_head = NULL;
    Shape*temp = NULL;

    for(int i=0;i<numberofsides;i++)
    {
        int k=(rand()%4) + 2;

        Shape*new_node=new Shape();

        new_node->set_sides(k);
        new_node->next=NULL;

        if(i==0)
        {
            shape_head=new_node;
        }
        else
        {

            temp=shape_head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
        }

    }

    temp=shape_head;

    while(temp!=NULL)
    {
        int side=temp->get_side();

        temp->display();

        if(side==4)
        {
            int w=(rand()%10) + 1;
            int h=(rand()%10) + 1;

            Rect my_rect(w,h);

            my_rect.display();
        }
        else if(side==3)
        {
            int x=(rand()%10) + 1;
            int y=(rand()%10) + 1;
            int z=(rand()%10) + 1;

            Tri my_tri(x,y,z);

            my_tri.display();
        }
        else
        {
            cout<<endl;
        }

        temp=temp->next;
    }

    return 0;
}



