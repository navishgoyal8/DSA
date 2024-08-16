#include <iostream>
#include <vector>
using namespace std;

void PrintOutputSubset(int i,int n,int set[],int targetSum,vector<int> subset){

    if(targetSum == 0){
        cout << "[ ";

        for(int i=0;i<subset.size();i++){
            cout<<subset[i]<<" ";
        }

        cout<<" ]";

        return;
    }

    if(i == n){
        return;
    }

    PrintOutputSubset(i+1,n,set,targetSum,subset);

    if(set[i] <= targetSum){

        subset.push_back(set[i]);
        PrintOutputSubset(i+1,n,set,targetSum - set[i],subset);
        subset.pop_back();
    }
}

int main()
{   
    int set[] = {5,7,10,12,15,18,20};
    int sum = 35;
    int n = sizeof(set)/sizeof(set[0]);
    vector<int> subset;

    PrintOutputSubset(0,n,set,sum,subset);

    return 0;
}