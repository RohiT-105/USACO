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
 

vector<vll> adj(3001);
vll visited(3001),components;
void dfs(ll n)
{
    visited[n]=1;
    for(auto x:adj[n])
    {
        if(!visited[x]) dfs(x); 
    }
}
void dfs2(ll n,vector<ll>& visit)
{
    visit[n]=1;
    for(auto x:adj[n])
    {
        if(!visit[x]) dfs2(x,visit); 
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    fr(i,0,m)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    fr(i,1,n+1)
    {
        if(!visited[i])
        {
            components.pb(i);
            dfs(i);
        }
    }
    if(components.size()==1) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
    vll rem(n+1,0);
    fr(i,0,n-1)
    {
        ll r;
        cin>>r;
        rem[r]=1;
        fr(i,0,adj[r].size())
        {
            fr(j,0,adj[adj[r][i]].size())
            {
                if(adj[adj[r][i]][j]==r)
                {
                    adj[adj[r][i]].erase(adj[adj[r][i]].begin()+j);
                }
            }
        }
        adj[r]={};
        vll comp,visit(n+1,0);
        fr(i,1,n+1)
        {
            if(!visit[i] && !rem[i])
            {
                comp.pb(i);
                dfs2(i,visit);
            }
        }
        if(comp.size()==1) cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
    }
}
signed main()
{
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t; cin>>t; 
    // while(t--) 
    solve();
}
