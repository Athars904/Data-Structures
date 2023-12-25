#include <iostream>
using namespace std;

// Function to reverse a number recursively
int reverseNumber(int num, int rev = 0)
{
    if (num == 0)
        return rev;
    else
        return reverseNumber(num / 10, rev * 10 + num % 10);
}

int main()
{
    int num;
    cout << "Enter a number to reverse: ";
    cin >> num;

    int reversed_num = reverseNumber(num);
    cout << "The reversed number is: " << reversed_num;

    return 0;
}
