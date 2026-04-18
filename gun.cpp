#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n,h,k;
        cin>>n>>h>>k;
        vector<long long> a(n);
        for(auto &x:a)cin>>x;
        
        long long total=0;
        for(auto x:a)total+=x;
        vector<long long> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
        	pre[i+1]=pre[i]+a[i]; 
        }
        vector<long long>suf_max(n+2,0);
        for(int i=n-1;i>=0;i--)
        { 
        	suf_max[i]=max(suf_max[i+1],a[i]);
        }
        vector<long long> pre_min(n+1,LLONG_MAX);
        for(int i=0;i<n;i++)
        {
        	pre_min[i+1]=min(pre_min[i],a[i]);
        }
        auto best_gain=[&](long long rem)->long long 
        {
            if(rem<=0 || rem>=n)
            {
            	return 0LL;
            }
            if(pre_min[rem]==LLONG_MAX || suf_max[rem]<=pre_min[rem])
            {
            	return 0LL;
            }
            return suf_max[rem] - pre_min[rem];
        };
        long long ans=LLONG_MAX;
        for(int p=1;p<=n;p++)
        {
            long long dmg_per_round=total;
            long long base=pre[p]+best_gain(p);
            long long r;
            if(base>=h)
            {
                r=0;
            } 
            else 
            {
                r=(h-base+total-1)/total;
            }
            long long T=r*(n+k)+p;
            ans=min(ans,T);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
