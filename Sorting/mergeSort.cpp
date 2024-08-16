#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end)
{

    int mid = start + (end - start) / 2;

    int first = mid - start + 1;
    int second = end - mid;

    int *arr1 = new int[first];
    int *arr2 = new int[second];

    int mainArrayIndex = start;
    for (int i = 0; i < first; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }

    for (int i = 0; i < second; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < first && index2 < second)
    {

        if (arr1[index1] < arr2[index2])
        {
            arr[mainArrayIndex++] = arr1[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

    while (index1 < first)
    {
        arr[mainArrayIndex++] = arr1[index1++];
    }

    while (index2 < second)
    {
        arr[mainArrayIndex++] = arr2[index2++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    vector<int> arr = {8, 2, 1, 7, 5, 6, 3};

    int start = 0;
    int end = arr.size() - 1;

    mergeSort(arr, start, end);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}