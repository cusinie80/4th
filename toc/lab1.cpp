#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string input;
	char state='A';
	cout<<"Enter input string : ";
	cin>>input;
	for(int i=0;i<input.length();i++)
	{
		switch(state)
		{
			case 'A':
				state=(input[i]=='1')?'B':'X';
				break;
			case 'B':
				state=(input[i]=='0')?'C':'X';
				break;
			case 'C':
				state=(input[i]=='0')?'D':'X';
				break;
			case 'D':
				state=(input[i]=='1')?'E':'X';
				break;
			case 'E':
				state='X';
				break;
			case 'X':
				state='X';
				break;
		}
	}
	if(state=='E')
		cout<<"DFA accepts the string : "<<input;
	else
		cout<<"DFA rejects the string : "<<input;
	return 0;
}