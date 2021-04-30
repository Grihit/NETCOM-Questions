#include <bits/stdc++.h>
using namespace ::std;

int main()
{
	char ip[30],c;
	cout<<"\nEnter the IP address: ";
	gets(ip);
    int i = 0,num = 0, j = 1;;
    while (ip[i] != '.')
    {
        i++;
    }
    i--;
    while (i >= 0)
    {
        num = num + (ip[i] - '0') * j;
        j = j * 10;
        i--;
    }
    if (num >=1 && num <= 126)
        c = 'A';
    else if (num >= 128 && num <= 191)
        c = 'B';
    else if (num >= 192 && num <= 223)
        c = 'C';
    else if (num >= 224 && num <= 239)
        c = 'D';
    else
        c = 'E';
    cout<<"\nThe class of the IP address "<<ip<<" is "<<c;
    return 0;
}

