#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{   
    vector<int> arr1 = {1,2,4,0};
    int first = arr1.size();

    vector<int> arr2 = {8,6};
    int second = arr2.size();

    vector<int> arr3;
    
    int firstNum = 0;

    for(int i=0;i<first;i++){
        firstNum = firstNum + arr1[i]*pow(10,first-i-1);
    }

    int secondNum = 0;

    for (int i = 0; i < second; i++)
    {
        secondNum = secondNum + arr2[i] * pow(10, second - i - 1);
    }

    int thirdNum = firstNum + secondNum;
    int num = thirdNum;
    cout<<thirdNum<<endl;

    while(thirdNum){
        int a = thirdNum%10;
        cout<<a<<endl;
        arr3.push_back(a);
        thirdNum = thirdNum/10;
    }
    
    int start = 0;
    int end = arr3.size()-1;

    while(start<=end){
        swap(arr3[start],arr3[end]);
        start++;
        end--;
    }

    for(auto i:arr3){
        cout<<i<<" ";
    }

    return 0;
}