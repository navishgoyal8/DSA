#include <iostream>
using namespace std;

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isAlphaNumeric(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

bool checkPalindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

bool isPalindrome(string s)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isAlphaNumeric(s[i]))
        {
            char ch = toLowerCase(s[i]);
            temp.push_back(ch);
        }
    }

    return checkPalindrome(temp);
}

int main()
{   
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    int n = str.length();
    if(isPalindrome(str)){
        cout<<"Yes, it is a palindrome"<<endl;
    }
    else{
        cout<<"No, it is not a palindrome"<<endl;
    }

 
    return 0;
}