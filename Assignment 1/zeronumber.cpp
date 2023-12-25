#include<iostream>
using namespace std;
int countZeros(long int n) {
    if (n == 0) {
        return 1;
    } else if (n < 10) {
        return 0;
    } else if (n % 10 == 0) {
        return 1 + countZeros(n / 10);
    } else {
        return countZeros(n / 10);
    }
}
int main()
{
    cout << "===========================WELCOME============================" << endl;
    long int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "The number of zeros in " << num << " are " << countZeros(num);
}
