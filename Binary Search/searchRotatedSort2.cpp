#include <iostream>
#include <vector>
using namespace std;

int searchRotatedSort1(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return true;
        }
        
        //To Check which side is sorted left or right
        if(arr[mid] == arr[low] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            // left half is sorted
            if (arr[low] <= key && arr[mid] >= key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // right half is sorted
            if (arr[mid] <= key && arr[high] >= key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}
int main()
{
    vector<int> arr = {4, 4,5, 1, 2, 3};
    int key;
    cout << "Enter the key:";
    cin >> key;
    cout << searchRotatedSort1(arr, key);

    return 0;
}