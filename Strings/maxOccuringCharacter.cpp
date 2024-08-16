#include <iostream>
using namespace std;

char getMaxOccuringChar(string str)
{
    int arr[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int index = ch - 'a';
        arr[index]++;
    }

    int maxi = -1;
    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
            ans = i;
        }
    }

    return ans + 'a';
}

int main()
{   string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout << "Max occuring character: " << getMaxOccuringChar(str) << endl;

    return 0;
}