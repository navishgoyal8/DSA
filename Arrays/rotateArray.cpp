#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    vector<int> arr = {1,2,3,4,5,6};
    int n = arr.size();
    vector<int> temp(n);

    int k ;
    cout<<"Enter the value of rotation:";
    cin >> k;

   int i=0;
   int index = 0;
   while(index<n){

    i = (index+k)%n;
    temp[i] = arr[index];
    index++;
   }

   for(auto i:temp){
    cout<<i<<" ";
   }


    return 0;
}