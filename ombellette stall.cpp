#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,D,balptr=1;
		cin>>N>>D;
		vector<int>E(N+1,0),U(N+1,0),Bal(N+1,0);
		for(int day=1;day<=N;day++)
		{
			cin>>E[day];
		}
		for(int day=1;day<=N;day++)
		{
			cin>>U[day];
		}
		for(int day=1;day<=N;day++)
		{
			int Need=U[day];
			while(balptr<day-D)
			{
				balptr++;
			}
			while(Need>0 && balptr<day)
			{
				int Baluse=min(Need,Bal[balptr]);
				Need-=Baluse;
				Bal[balptr]-=Baluse;
				if(Bal[balptr]==0)
				{
					balptr++;
				}	
			}
			Bal[day]=E[day]-Need;
		}
		int Baleggs=0;
		for(int day=N-D+1;day<=N;day++)
		{
			Baleggs+=Bal[day];
		}
		cout<<Baleggs<<endl;
	}
}
