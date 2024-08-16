// check whether a string is palindrome or not

#include <iostream>
using namespace std;

bool isPalindrome(string str, int i, int j)
{
    if (i >= j)
    {
        return true;
    }

    if (str[i] == str[j])
    {
        i++;
        j--;
        isPalindrome(str, i, j);
    }
    else
    {
        return false;
    }

}

int main()
{
    string str;
    cout << "Enter the string:";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << "STRING IS PALINDROME!";
    }
    else
    {
        cout << "STRING IS NOT A PALINDROME!";
    }

    return 0;
}