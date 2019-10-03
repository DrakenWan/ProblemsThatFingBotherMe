#include<iostream>
#include<stack>

using namespace std;


void calculateStockSpan(int [], int n, int[]);

int main()
 {
     int n;

     //cout<<"Enter the number of days:";
     cin >> n;
     int S[n], stock[n];
     
     //cout<<"Enter stock prices for each day:-\n";
     for(int i=0; i<n; i++)
      cin>>stock[i];

     calculateStockSpan(S,n,stock);

    
    for(int i=0; i<n; i++)
        cout<<S[i]<<" ";
     return 0;
 }

 void calculateStockSpan(int S[], int n, int stock[])
  {
      stack<int> s1;
      s1.push(0);
      S[0] = 1;
      for(int i=1; i<n; i++)
        {
            while( !s1.empty() && stock[s1.top()] <= stock[i] ) 
                s1.pop();
            
            //found below part from gfg.com
            S[i] = (s1.empty()) ? (i + 1) : (i - s1.top());
            s1.push(i);
        }
  }