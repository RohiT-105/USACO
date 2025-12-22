#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
#define pb push_back
#define nl "\n"
#define fr(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,a,b) for (ll i = a; i >= b; i--)
#define all(a) a.begin(),a.end()
// vll primes;
// vll prime(ll n)
// {
//     if (n == 0) return {};
//     ll limit = 2;
//     while (true)
//     {
//         limit = n * (limit < 6 ? 12 : log(limit) * 2);
//         vector<bool> is_prime(limit, true);
//         is_prime[0] = is_prime[1] = false;
//         fr(i, 2, limit)
//         {
//             if (i * i >= limit) break;
//             if (is_prime[i])
//             {
//                 for (ll j = i * i; j < limit; j += i)
//                 {
//                     is_prime[j] = false;
//                 }
//             }
//         }
//         vll primes;
//         fr(i, 2, limit)
//         {
//             if (primes.size() == n) break;
//             if (is_prime[i]) primes.pb(i);
//         }
//         if (primes.size() >= n) return primes;
//         limit *= 2;
//     }
// }
 

vector<vll> adj(201);
ll ans(0),step;
void dfs(ll n, vector<ll>& visited)
{
    visited[n]=1;
    step++;
    ans=max(ans,step);
    for(auto x:adj[n])
    {
        if(!visited[x]) dfs(x,visited); 
    }
}
void solve()
{
    ll t;
    cin>>t;
    vll x(t+1),y(t+1),d(t+1);
    fr(i,1,t+1) cin>>x[i]>>y[i]>>d[i];
    fr(i,1,t+1)
    {
        fr(j,1,t+1)
        {
            double dist=sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            if(dist<=d[i]) adj[i].pb(j);
        }
    }
    fr(i,1,t+1)
    {
        vll visited(t+1,0);
        step=0;
        dfs(i,visited);
    }   
    cout<<ans;
}
signed main()
{
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}
