#include <iostream>
#include <vector>   
using namespace std;

vector<int> rearrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;
    for(int i=0;i<n;i++){
        if(nums[i] < 0){
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else{
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return ans;
}

// When number of positive and negative numbers are not equal
vector<int> alternateNumbers(vector<int> &arr){
    vector<int> pos, neg;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    return arr;
}

int main()
{   
    vector<int> nums = {1,2,-3,-4,-1,4};
    vector<int> ans = rearrangeArray(nums);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

    cout << endl;
    vector<int> alternate = {1, 2, -3, -4, 1, 4};
    vector<int> alternateAns = alternateNumbers(alternate);
    for(int i=0;i<alternateAns.size();i++){
        cout << alternateAns[i] << " ";
    }
    return 0;
}