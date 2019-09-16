#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;
const ll mod = 1e9+7;
const ll MAX = 2e5;

ll fact[200005], a[200005];
ll power(ll x, ll p)
{
    ll res = 1;
    while(p > 0)
    {
        if(p&1)
            res = (res * x)%mod;
        p >>= 1;
        x = (x * x)%mod;
    }
    return res;
}

ll ncr(ll n, ll k)
{
    if(n < k)
        return 0;
	ll res;
	ll temp = (fact[k] * fact[n-k])%mod;
	temp = power(temp, mod-2);
	res = (fact[n] * temp)%mod;
	return res;
}

//code from gfg: "Summation of GCD of all the pairs up to N"
ll phi[200010], result[200010]; 
void computeTotient() 
{ 
    phi[1] = 1; 
    for (ll i = 2; i < 200001; i++) 
    { 
        if (!phi[i]) 
        { 
            phi[i] = i-1; 
            for (ll j = (i << 1); j < 200001; j += i) 
            { 
                if (!phi[j]) 
                    phi[j] = j; 
  
                phi[j] = (phi[j]/i)*(i-1); 
            } 
        } 
    } 
}  
void sumOfGcdPairs() 
{ 
    computeTotient(); 
  
    for (ll i = 1; i < 200005; ++i) 
    { 
        for (ll j = 2; i*j < 200005; ++j) 
            result[i*j] = (result[i*j] + i*phi[j])%mod; 
    } 
    for (ll i = 2; i < 200005; i++) 
        result[i] = (result[i] + result[i-1])%mod; 
} 
//end

void solve1(ll K)
{
    a[0] = a[1] = 0;
	sumOfGcdPairs();
    for(ll i = 2; i <= MAX; i++)
    {
    	ll q = ncr(i, K);
    	ll p = result[i];
    	q = power(q, mod-2);
    	a[i] = (p * q)%mod;
    }
}

void sumOfGcdK(ll K)
{
    vector<ll> fac[MAX+5];
    ll cnt[MAX+5];
    memset(cnt, 0, sizeof(cnt));
    
    for(ll i = 2; i <= MAX; i++)
    	fac[i].push_back(1);
    	
    cnt[1] = MAX;
    for(ll i = 2; i <= MAX; i++)
    {
        cnt[i] = 1;
    	for(ll j = 2*i; j <= MAX; j = j + i)
    	{
    	    cnt[i]++;
    		fac[j].push_back(i);
    	}
    }
    
    ll m[MAX+5], v[MAX+5], curr = 0;
    memset(m, 0, sizeof(m));
    for(ll i = MAX; i >= 1; i--)
    {
        ll c = ncr(cnt[i], K);
        c = (c - m[i])%mod;
        for(ll j = 0; j < fac[i].size(); j++)
        {
            ll x = fac[i][j];
            m[x] = (m[x] + c)%mod;
        }
        curr = (curr + (i * c))%mod;
    }
    curr = (curr%mod + mod)%mod;
    result[MAX] = curr;
    
    memset(m, 0, sizeof(m));
   	for(ll i = MAX-1; i >= K; i--)
   	{
   		ll total = 0, si = 0;
   		for(ll j = fac[i+1].size()-1; j >= 0; j--)
   		{
   			ll x = fac[i+1][j];
   			ll c = ncr(cnt[x]-1, K-1);
   		    c = (c - m[x])%mod;
   			for(ll k = 0; k < fac[x].size(); k++)
   			{
   				ll y = fac[x][k];
   				m[y] = (m[y] + c)%mod;
   			    v[si++] = y;
   			}
   			total = (total + (c * x))%mod;
   			cnt[x]--;
   		}
   		curr = (curr - total)%mod;
   		curr = (curr%mod + mod)%mod;
   		
   		result[i] = curr;
   		
   		for(ll j = 0; j < si; j++) m[v[j]] = 0;
   	}
}

void solve2(ll K)
{
    for(ll i = 0; i < K; i++)
        a[i] = 0;
    sumOfGcdK(K);
    for(ll i = K; i <= MAX; i++)
    {
        ll q = ncr(i, K);
        ll p = result[i];
        q = power(q, mod-2);
        a[i] = (p * q)%mod;
    }
}

int main()
{
    fast
    ll Q,K;
    cin >> Q >> K;
    
    fact[0] = 1;
    for(ll i = 1; i <= 200001; i++)
    	fact[i] = (fact[i-1]*i)%mod;

    if(K == 2)
    {
    	solve1(K);
    }
    else
    {
        solve2(K);
    }
    while(Q--)
    {
    	ll N;
    	cin >> N;
    	cout << a[N] << "\n";
    }
}
