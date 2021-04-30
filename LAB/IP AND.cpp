#include <bits/stdc++.h>

using namespace std;

int AND(int a,int b)
{
	int c;
	if(a==1 && b==1)
		c=1;
	else
		c=0;
	return c;
}
int main()
{
	long int num,temp1;
	int mask,mbin[32],mbinc[32],farr[32],larr[32];
	cout<<"Enter the IP Address without any spacing: ";
	cin>>num;
	cout<<"\nEnter the mask: ";
	cin>>mask;
	for(int i=0;i<32;i++)
	{
		if(i<mask)
			mbin[i]=1;
		else
			mbin[i]=0;
	}
	temp1=num;
	int bNum1[32];
    int start=0,end=31;
    int i=0;
    for(int k=0;k<8;k++) 
	{
		if(temp1>0)
		{
        	bNum1[i] = temp1 % 2;
        	temp1 = temp1 / 2;
        	i++;
    	}
    	else
    	{
    		bNum1[i]=0;
			i++;
		}
	}
    while (start < end)
    {
        int temp = bNum1[start];
        bNum1[start] = bNum1[end];
        bNum1[end] = temp;
        start++;
        end--;
    }
    for(i=0;i<32;i++)
    {
    	if(mbin[i]==1)
    		mbinc[i]=0;
    	else
    		mbinc[i]=1;
	}
	for(i=0;i<32;i++)
	{
		farr[i]=AND(bNum1[i],mbin[i]);
		larr[i]=AND(bNum1[i],mbinc[i]);
	}
	cout<<"First Address: ";
	for(i=0;i<32;i++)
	{
		cout<<farr[i];
	}
	cout<<endl;
	cout<<"Last Address";
	for(i=0;i<32;i++)
	{
		cout<<larr[i];
	}
}
