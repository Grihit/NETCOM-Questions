#include <stdio.h>
#include <math.h>
int input[32];
int code[32];
int ham_calc(int,int);
void Receiver(int,int);
void sender()
{
	int n,i,p_n = 0,c_l,j,k;
	printf("Please enter the length of the Data Word: ");
	scanf("%d",&n);
	printf("Please enter the Data Word:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
	}

	i=0;
	while(n>(int)pow(2,i)-(i+1))
	{
		p_n++;
		i++;
	}

	c_l = p_n + n;

	j=k=0;
	for(i=0;i<c_l;i++)
	{

		if(i==((int)pow(2,k)-1))
		{
			code[i]=0;
			k++;
		}
		else
		{
			code[i]=input[j];
			j++;
		}
	}
	for(i=0;i<p_n;i++)
	{
		int position = (int)pow(2,i);
		int value = ham_calc(position,c_l);
		code[position-1]=value;
	}
	printf("\nThe calculated Code Word is: ");
	for(i=0;i<c_l;i++)
		printf("%d",code[i]);
	printf("\n");
	Receiver( c_l,  p_n);
}
void Receiver(int c_l, int p_n)
	{
	    int i;
    printf("Enter the received Code Word:\n");
	for(i=0;i<c_l;i++)
		scanf("%d",&code[i]);

	int error_pos = 0;
	for(i=0;i<p_n;i++)
	{
		int p = (int)pow(2,i);
		int value = ham_calc(p,c_l);
		if(value != 0)
			error_pos+=p;
	}
	if(error_pos == 1)
		printf("The received Code Word is correct.\n");
	else
		printf("Error at bit position: %d\n",error_pos);
}
int ham_calc(int p,int c_l)
{
	int count=0,i,j;
	i=p-1;
	while(i<c_l)
	{
		for(j=i;j<i+p;j++)
		{
			if(code[j] == 1)
				count++;
		}
		i=i+2*p;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}
int main()
{
sender();
return 0;
}
