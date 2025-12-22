#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
#define all(a) a.begin(),a.end()  

void solve()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    fr(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll l(0),r(a[n-1]-a[0]),ans(n);
    while(l<=r)
    {
        ll mid = l + (r-l)/2;
        ll fir(a[0]),count(1);
        fr(i,1,n)
        {
            if(a[i]-fir <= 2*mid)
            {

            }
            else
            {
                count++;
                fir=a[i];
            }
        }
        if(count<=k)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
}

signed main()
{ 
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t;
    // while(t--) 
    solve();
}
