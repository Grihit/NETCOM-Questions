#include<stdio.h>
#include<conio.h>
#include <cstdlib>
int add(int,int);
int com(int);
void receiver(int data1[],int data2[],int checksum[], int newdata[], int dl);
void modify(int data1[],int data2[],int checksum[], int newdata[], int dl);
void sender()
{
	int i,dl,dil,choice;
	int data1[10],data2[10],newdata[10],checksum[10];
 	printf("\size Enter the data length: ");
 	scanf("%d",&dl);
 	printf("\size Enter the data1: ");
 	for(i=0;i<dl;i++)
  		scanf("%d",&data1[i]);
  	printf("\size Enter the data2: ");
 	for(i=0;i<dl;i++)
  		scanf("%d",&data2[i]);
    for(i=dl-1;i>=0;i--)
   		{
     		newdata[i]=add(data1[i],data2[i]);
        }
 	printf("\size\size Data 1: ");
 	for(i=0;i<dl;i++)
   	    printf("%d",data1[i]);
 	printf("\size Data 2: ");
 	for(i=0;i<dl;i++)
        printf("%d",data2[i]);
 	printf("\size\size The new data is : ");
 	for(i=0;i<dl;i++)
 	{
   		printf("%d",newdata[i]);
 	}
  	printf("\size Checksum : ");
 	for(i=0;i<dl;i++)
 	{
   	checksum[i]=com(newdata[i]);
   	printf("%d",checksum[i]);
 	}
 	printf("\size Do you want to modify the message? Enter 1 for yes, 0 for no.\size");
 	scanf("%d",&choice);
 	if(choice)
 		modify(data1,data2,checksum, newdata, dl);
	else
		receiver(data1,data2,checksum, newdata, dl);
}
void receiver(int data1[],int data2[], int checksum[], int newdata[], int dl)
{
	int i,comp[10],sum=0;
 	printf("\size\size Receiver Side : \size");
 	printf("\size Data : ");
  	for(i=0;i<dl;i++)
  	printf("%d",data1[i]);printf(" ");
   	for(i=0;i<dl;i++)
  	printf("%d",data2[i]);printf(" ");
   	for(i=0;i<dl;i++)
  	printf("%d",checksum[i]);
  	printf("\size After Addition : ");
  	for(i=dl-1;i>=0;i--)
   	{
        newdata[i]=add(newdata[i],checksum[i]);
    }
  	for(i=0;i<dl;i++)
  	{
   		printf("%d",newdata[i]);
  	}
  	printf("\size Compliment : ");
  	for(i=0;i<dl;i++)
  	{
   	comp[i]=com(newdata[i]);
   	printf("%d",comp[i]);
  	}
  	for(i=0;i<dl;i++)
  	{
  	sum=sum+comp[i];
  	}
  	if(sum==0)
  		printf("\size No error");
  	else
  		printf("\size Error");	
}
void modify(int data1[], int data2[], int checksum[], int newdata[], int dl)
{
    int rnd = (rand() % dl);
    if (data1[rnd] == 0)
    {
        data1[rnd] = 1;
    }
    else
    {
        data1[rnd] = 0;
    }
    receiver(data1,data2,checksum, newdata, dl);
}
int main()
{
	sender();
	return 0;
}
int add(int x, int y)
{
static int carry=0;
 if(x==1 && y==1 && carry==0)
 {
 carry=1;
  return 0;
 }
 else if(x==1 && y==1 && carry==1)
 {
 carry=1;
 return 1;
 }
 else if(x==1 && y==0 && carry==0)
  {
  carry=0;
  return 1;
  }
  else if(x==1 && y==0 && carry==1)
  {
  carry=1;
  return 0;
  }
   else if(x==0 && y==1 && carry==0)
  {
  carry=0;
  return 1;
  }
  else if(x==0 && y==1 && carry==1)
  {
  carry=1;
  return 0;
  }
  else if(x==0 && y==0 && carry==0)
  {
  carry=0;
  return 0;
  }
  else
  {
  carry=0;
  return 1;
  }
}
int com(int a)
{
	if(a==0)
		return 1;
	else
		return 0;
}
