#include <vector>
#include <iostream>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
        // if (studentCount > m)
        // {
        //     return false;
        // }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{   
    if(m > n){
        return -1;
    }
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main(){

    vector<int> arr = {2,8,8,4,5};
    int n = arr.size();
    int students = 6;

    int ans = allocateBooks(arr,n,students);

    cout<<ans<<endl;

    return 0;
}


