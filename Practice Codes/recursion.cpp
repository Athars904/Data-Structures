#include<iostream>
using namespace std;
int NumberOfZeros(long int x)
{
    if (x==0)
    {
        return 1;
    }
    else if (x<10)
    {
        return 0;
    }
    int lastdigit=x%10;
    int remaiming=x/10;
    int zeros=NumberOfZeros(remaiming);
    if (lastdigit==0)
    {
        return zeros+1;
    }
    else
    {
        return zeros;
}
}
int main()
{
    cout << NumberOfZeros(2000032);
}