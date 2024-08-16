#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    int arr1[] = {1,2,2,2,3,4};
    int arr2[] = {3,3,4};

    vector<int> arr3;

    int first = 0;
    int second = 0;

    while(first<6 && second<3){

        if(arr1[first] ==  arr2[second]){
            arr3.push_back(arr1[first]);
            first++;
            second++;
        }

        if(arr1[first]>arr2[second]){
            second++;
        }
        if (arr1[first] < arr2[second])
        {
            first++;
        }

    }

    for(auto i: arr3){
        cout<<i<<" ";
    }

    return 0;
}

