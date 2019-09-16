#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

int main()
{
	fast

	ll N;
	cin >> N;

	ll a[N];
	for(int i = 0; i < N; i++)
		cin >> a[i];

	ll m[1000005];
	unordered_set<ll> s;
	memset(m, 0, sizeof(m));
    
    for(int i = 0; i < N; i++)
    {
        if(a[i] <= 1000000)
        {
            m[a[i]]++;
            s.insert(a[i]);
        }
    }
    
    ll pre[N+1];
    ll gcd = a[N-1];
    for(int i = N-1; i >= 0; i--)
    {
        gcd = __gcd(gcd, a[i]);
        pre[i] = gcd;
    }
    
	for(int i = 0; i < N-1; i++)
	{
		gcd = a[i];
		for(int j = i+1; j < N; j++)
		{
			gcd = __gcd(gcd, a[j]);
			if(gcd == pre[j])
			{
			    if(gcd <= 1000000)
			    {
    			    m[gcd] += (N - j);
    			    s.insert(gcd);
			    }
			    break;
			}
			if(gcd <= 1000000)
			{
				m[gcd]++;
				s.insert(gcd);
			}
		}
	}
    
	ll ans[1000005];
	memset(ans, 0, sizeof(ans));
	for(ll i : s)
	{
	    if(i > 1)
	    {
    		ll x = m[i];
    		for(ll j = i; j <= 1000000; j += i)
    		{
    			ans[j] += x;
    		}
	    }
	}

	if(m[1] > 0)
	{
		ll x = m[1];
		for(ll i = 1; i <= 1000000; i++)
			ans[i] += x;
	}

	ll Q;
	cin >> Q;
	while(Q--)
	{
		ll K;
		cin >> K;
		cout << ans[K] << "\n";
	}
}
