// TIME COMPLEXICITY ---> O(NLOGN + N*M)     NLOGN IS FOR SORTING
// SPACE COMPLEXICITY ---> O(M)     WHERE M IS THE DEADLINE

#include <iostream>
#include <vector>
using namespace std;

vector<int> jobScheduling(vector<vector<int>> &jobs){
    int deadline = jobs[0][1];
    int current;
    for(int i=1;i<jobs.size();i++){
        current = jobs[i][1];
        if(current > deadline){
            deadline = current;
        }
    }

    vector<int> ans(deadline,-1);

    
    

}

int main()
{    
    vector<vector<int>> jobs;
    vector<int> ans;

    jobs = {{1,2,30},{2,2,40},{3,1,10},{4,1,10}};

    ans = jobScheduling(jobs); 
    return 0;
}