#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string.h>
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;

const ll maxn = 101;
const ll mod = 1e9+7;


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll w[n],p[n],i;
    // max price: k
    // find max weight we can buy in price <= k
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    for(i=0;i<n;i++){
        cin>>w[i];
    }
    ll dp[n+1][k+1],j;
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            ll x=j-p[i-1];
            if(x>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][x]+w[i-1]);
            }
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[n][k]<<"\n";
    cerr<<"\nTime elapsed:"<< 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
