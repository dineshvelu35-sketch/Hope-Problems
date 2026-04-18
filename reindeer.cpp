#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) 
    {
        int N;
        cin>>N;
        vector<long long>W(N),P(N);
        for (int i=0;i<N;i++)
        {
            cin>>W[i]>>P[i];
        }
        vector<int>idx(N);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int a,int b) 
        {
            return W[a]+P[a]<W[b]+P[b];
        });
        vector<long long> prefW(N+1,0),sufP(N+1,0);
        for(int i=0;i<N;i++) 
        {
            prefW[i+1]=prefW[i]+W[idx[i]];
        }
        for(int i=N-1;i>=0;i--) 
        {
            sufP[i]=sufP[i+1]+P[idx[i]];
        }
        int lo=0,hi=N,ans=0;
        while(lo<=hi) 
        {
            int mid=(lo+hi)/2;
            if(sufP[mid]>=prefW[mid])
            {
                ans=mid;
                lo=mid+1;
            } 
            else 
            {
                hi=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
