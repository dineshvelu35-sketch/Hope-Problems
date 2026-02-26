#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,curr,ans;
	cin>>N;
	map<int,int>mp;
	for(int i=0;i<N;i++)
	{
		cin>>curr;
		if(mp.find(curr-1)!=mp.end())
		{
			mp[curr]=mp[curr-1]+1;
			ans=max(ans,mp[curr]);
		}
		else
		{
			mp[curr]=1;
		}
	}
	cout<<ans;
	
}
