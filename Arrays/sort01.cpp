#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {0, 1, 1, 0, 1, 1, 1};

    int start = 0;
    int end = 6;

    while (start < end)
    {

        while (start < end && arr[start] == 0)
        {
            start++;
        }
        while (start < end && arr[end] == 1)
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}