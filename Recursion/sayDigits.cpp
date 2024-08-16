#include <iostream>
using namespace std;

void sayDigits(int number,string arr[]){

    if(number == 0){
        return;
    }

    int digit = number%10;
    number = number/10;
    sayDigits(number,arr); 

    cout<<arr[digit]<<" ";
}

int main()
{   
    int number;
    cout<<"Enter the number:";
    cin >> number;

    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};


    sayDigits(number,arr);

    return 0;
}