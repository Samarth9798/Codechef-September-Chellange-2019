#include <stdio.h>
typedef long long int ll;
const ll mod = 1e9+7;

ll min(ll a, ll b)
{
    if(a < b)
        return a;
    return b;
}
int main()
{
	ll T;
	scanf("%lld",&T);
    ll v[5005][5005];
    for(ll i = 1; i <= 5000; i++)
    {
        ll temp = i*i;
        for(ll j = 1; j <= i; j++)
        {
            v[i][j] = temp/j;
        }
    }
    
	while(T--)
	{
	    ll A,B,C;
	    scanf("%lld %lld %lld", &A, &B, &C);
        A -= 1;
        C -= 1;
        if(A == 0 || C == 0)
        {
            printf("0\n");
            continue;
        }
        ll total_triplets = ((A * B)%mod * C)%mod;
        ll x = 0,a[B+1],si = 0;
        for(ll i = 1; i <= B; i++)
        {
            ll it = min(A, i);
            si = 0;
            for(ll j = 1; j <= it; j++)
            {
                ll z = min(v[i][j], C);
                x = (x + z);
                a[si++] = v[i][j];
            }
            for(ll j = 1; j < si; j++)
            {
                ll prev = a[j-1],curr = a[j];
                if(curr > A) continue;
                ll z = min(C, j), y;
                if(prev > A)
                {
                    y = A - curr;
                    y = (y * z);
                }
                else
                {
                    y = prev - curr;
                    y = (y * z);
                }
                x = (x + y);
            }
            if(x >= mod)
                x %= mod;
        }
        ll ans = (total_triplets - x)%mod;
        if(ans < 0) ans = mod + ans;
        printf("%lld\n", ans);
	}
}
