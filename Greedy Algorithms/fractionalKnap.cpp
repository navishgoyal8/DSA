
// TIME COMPLEXICITY ---> O(nlogn + n)   n is for sorting
// SPACE COMPLEXICITY ---> O(1)  

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> &a,pair<int,int> &b){
    double r1 = (double)a.second/(double)a.first;
    double r2 = (double)b.second/(double)b.first;

    return r1>r2;
}

int main()
{   
    vector <pair<int,int>> items;
    int n = items.size();
    int w = 50;
    items.push_back(make_pair(10,60));
    items.push_back(make_pair(20, 100));
    items.push_back(make_pair(30, 120));
    // items.push_back(make_pair(40,25));
    // items.push_back(make_pair(42, 32));
    // items.push_back(make_pair(200, 45)); 

   sort(items.begin(),items.end(),comp);
   int curWeight = 0;
   double finalValue = 0.0;

   for(pair i: items){
    if(curWeight + i.first <= w){
        curWeight += i.first;
        finalValue += i.second;
        cout<<curWeight<<" "<<finalValue<<endl;
    }
    else
    {
        int remain = w - curWeight;
        finalValue += ((double)remain/i.first)*(i.second);
        cout<<remain<<" "<<finalValue;
        break;
    }

   }

   cout<<finalValue;
    return 0;
}