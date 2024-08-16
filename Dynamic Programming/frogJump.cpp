#include <iostream>
#include <vector>
using namespace std;

int calculate(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int left = calculate(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if (index > 1)
    {
        right = calculate(index - 2, heights, dp) +
                abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(left, right);
}

//BOTTOM-UP APPROACH
int frogJumpBottom(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

//SPACE OPTIMIZATION
int frogJumpSpace(int n, vector<int> &heights)
{
    int first = 0;
    int second = 0;
    int current;
    for (int i = 1; i < n; i++)
    {
        int left = second + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = first + abs(heights[i] - heights[i - 2]);
        }
        current = min(left, right);
        first = second;
        second = current;
    }
    return second;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    calculate(n - 1, heights, dp);
    return dp[n - 1];
}

int main()
{
    return 0;
}