#include <iostream>
using namespace std;

string removeOccurences(string s,string part){

    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part),part.length());
    }

    return s;  
}

int main()
{   
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    string part;
    cout<<"Enter the part to remove: ";
    getline(cin,part);

    cout<<"After removing the part: "<<removeOccurences(str,part)<<endl;
    
    return 0;
}