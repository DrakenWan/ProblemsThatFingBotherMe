/*
    You are given an array full of characters representing the four directions
    you have to reduce the array to the shortest path
    The given implementation is good example however consider an array [ n , e, s, w]
    the result of this should be


*/
#include<iostream>
#define DIRARRSIZE 2
using namespace std;

class stack
{
    char arr[100];
    int top;
    public:
        stack() {
            top = -1;
        }

        bool isEmpty();
        void push(char);
        char pop();
        char returnTop();
        void displayStack();
};

char stack::returnTop() {
    if(!isEmpty())
        return arr[top];
    else
        return 'o';
}

bool stack::isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

void stack::push(char maal) {
    arr[++top] = maal;
}

char stack::pop() {
    if(isEmpty())
        return  'o';
    return arr[top--];
}

void stack::displayStack() {
    if(!isEmpty())
        {
            for(int i=0; i<top+1; i++)
                cout<<arr[i]<<"  ";
        }
}

bool in(char direction, char array[])
{
    int i, flag = 0;
    for(i=0; i < DIRARRSIZE; i++)
        if(direction == array[i])
            { flag = 1; break;}
    if(flag == 1) return true;
    else return false;
}

int main()
{
    char d[] = {'n', 'n', 'w', 'e', 'e', 'w', 's', 'n', 'e', 'e'};
    char d1[] = {'n', 'e', 's', 'w'};
    int len = 4;
    char yAxis[] = {'n', 's'}, xAxis[] = {'e','w'};

    stack s1;
    s1.push(d[0]);
    for(int i=1; i<len; i++)
     {
        if( in(d1[i], yAxis))
         {
             if( in(s1.returnTop(), yAxis))
                {
                    if( s1.returnTop() != d1[i])
                        cout<<s1.pop();
                    else
                        s1.push(d1[i]);
                }
             else
                s1.push(d1[i]);
         }

        if( in(d1[i], xAxis))
         {
             if( in(s1.returnTop(), xAxis))
                {
                    if( s1.returnTop() != d1[i])
                        cout<<s1.pop();
                    else
                        s1.push(d1[i]);
                }
             else
                s1.push(d1[i]);
         }
     }

    //cout<<in('n', xAxis)<<endl<<in('n', yAxis);
    s1.displayStack();
    return 0;
}