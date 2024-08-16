#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n*m)
// Space complexity: O(N)
vector<int> spirallyTraverse(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, right = m - 1;
    int bottom = n - 1, left = 0;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        // right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{   
    vector<vector<int>> matrix = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12}};
    vector<int> ans = spirallyTraverse(matrix);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}