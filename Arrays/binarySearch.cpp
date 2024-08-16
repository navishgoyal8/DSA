#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int start = 0;
    int end = 9;

    int mid = start + (end - start) / 2;
    int key = 11;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            cout << "Element is found!" << endl;
            break;
        }

        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        if (arr[mid] < key)
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return 0;
}