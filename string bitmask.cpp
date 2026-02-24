#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string S;
		cin>>S;
		int flag=0;
		for(char ch:S)
		{
			flag=flag|(1<<(ch -'a'));
		}
		cout<<((flag==(1<<26)-1)?"yes":"no")<<endl;
	}

}
