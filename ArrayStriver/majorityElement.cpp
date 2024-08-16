#include <iostream>
#include <vector>
#include <map>
using namespace std;

// T.C = O(NlogN) + o(n)
int majorityElement(vector<int> v){
    map<int,int> mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]++;
    }

    for(auto it: mpp){
        if(it.second > v.size()/2){
            return it.first;
        }
    }

    return -1;
}

int majorityElementMooreVotingAlgo(vector<int> v){
    int count = 0;
    int candidate = 0;
    for(int i=0;i<v.size();i++){
        if(count == 0){
            count = 1;
            candidate = v[i];
        }
        if(candidate == v[i]){
            count++;
        }
        else{
            count--;
        }
    }

    int count2 = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] == candidate){
            count2++;
        }
    }

    if(count2 > v.size()/2){
        return candidate;
    }

    return -1;
}
int main()
{   
    vector<int> v = {2,2,1,1,1,2,2};
    cout << majorityElement(v) << endl;
    cout << majorityElementMooreVotingAlgo(v) << endl;
    return 0;
}