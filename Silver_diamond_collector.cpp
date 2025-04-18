#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
void solve()
{
    ll n,k,ans(0);
    cin>>n>>k;
    vll a(n);
    fr(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    vll dp(n,1),high(n,0);
    ll p1(0),p2(1);
    while(p1<n)
    {
        while(a[p2]-a[p1]<=k && p2<n)
        {
            dp[p1]=p2-p1+1;
            p2++;
        }
        p2--;
        p1++;
    }
    high[n-1]=dp[n-1];
    rep(i,n-2,0) high[i]=max(dp[i],high[i+1]);
    fr(i,0,n)
    {
        if(i+dp[i]<n) ans=max(ans,dp[i]+high[i+dp[i]]);
        else ans=max(ans,dp[i]);
    }
    // fr(i,0,n) cout<<dp[i]<<nl;
    // cout<<nl;
    // fr(i,0,n) cout<<high[i]<<nl;
    cout<<ans;
}

 
signed main()
{
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t;
    // while(t--) 
    solve();
}