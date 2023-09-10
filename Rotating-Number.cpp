#include <iostream>
using namespace std;

int leftCircular( int digit1, int digit2, int digit3, int digit4, int numShift, int Add)
{
	int NewNumber,temp1,temp2;
	for(int i=1; i<=numShift; i++)
	{
		temp1=digit4;
		digit4=digit1;
		digit1=digit2;
		
		temp2=digit3;
		digit3=temp1;
		digit2=temp2;
	}
	//Incrementing
	digit1=(digit1+Add)*1000;
	digit2=(digit2+Add)*100;
	digit3=(digit3+Add)*10;
	digit4=digit4+Add;
	NewNumber=digit1+digit2+digit3+digit4;
	return NewNumber;
}

int rightCircular( int digit1, int digit2, int digit3, int digit4, int numShift, int Add)
{
	int NewNumber,temp1,temp2;
	for(int i=1; i<=numShift; i++)
	{
		temp1=digit4;
		temp2=digit1;
		digit4=digit3;
		digit1=temp1;
		
		digit3=digit2;
		digit2=temp2;	
	}
	//Incrementing
	digit1=(digit1+Add)*1000;
	digit2=(digit2+Add)*100;
	digit3=(digit3+Add)*10;
	digit4=digit4+Add;
	NewNumber=digit1+digit2+digit3+digit4;
	return NewNumber;
}

int main()
{
	int num1,num2,num3,num4,number,digit1,digit2,digit3,digit4;
	char choice1,choice2;
	
	//Taking inputs
	cout<<"Enter the input"<<endl;
	cin>>choice1;
	cin>>num1;
	cin>>num2;
	cin>>choice2;
	cin>>num3;
	cin>>num4;
	cin>>number;
	
	//Separating digits
	digit1=number/1000;
	digit2=(number%1000)/100;
	digit3=(number%100)/10;
	digit4=number%10;
	
	//Calling first shift
	if (choice1=='l' || choice1=='L')
	number= leftCircular(digit1,digit2,digit3,digit4,num1,num2);
	else
	number= rightCircular(digit1,digit2,digit3,digit4,num1,num2);
	
	//Separating digits of first shift
	digit1=number/1000;
	digit2=(number%1000)/100;
	digit3=(number%100)/10;
	digit4=number%10;
	
	//Calling second shift
	if (choice2=='l' || choice2=='L')
	number= leftCircular(digit1,digit2,digit3,digit4,num3,num4);
	else
	number= rightCircular(digit1,digit2,digit3,digit4,num3,num4);
	
	//Outputing final result
	cout<<endl<<"The result is: "<<number;
}
