#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

void odd_case(ll N, ll M)
{
    ll ans = 4;
	M = M - (2*N);
	ll n1 = N/2;
	ll n2 = (N/2 + 1);
	ll n = n1 + n2;
	ll temp = M/n;
	ans = ans + 2*temp - (M%n == 0);

	if(M%n != 0)
	{
		M = M - (temp * n);
		if(M > n1)
			ans += 1;
	}

	if(ans > N)
		ans = N;
		
	cout << ans << "\n";
}

void even_case(ll N, ll M)
{
    ll ans = 4;
	M = M - (2*N);
	ll n = N/2;
	ans = ans + M/n - (M%n == 0);
	
	if(ans > N)
		ans = N;
		
	cout << ans << "\n";
}

int main()
{
	fast

	ll T;
	cin >> T;

	while(T--)
	{
		ll N, M;
		cin >> N >> M;

		if(N == 1)
		{
			if(M > 1)
				cout << -1 << "\n";
			else if(M == 1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if(N == 2)
		{
			if(M > 3 or M < 1)
				cout << -1 << "\n";
			else if(M == 1)	
				cout << 1 << "\n";
			else
				cout << 2 << "\n";
		}
		else
		{
			ll temp = (N * (N - 1))/2 + N;
			if(M > temp or M < N-1)
				cout << -1 << "\n";
			else
			{
				if(M <= N+1)
					cout << 2 << "\n";
				else if(M <= 2*N)
					cout << 3 << "\n";
				else if(N&1)
				{
					odd_case(N, M);
				}
				else
				{
					even_case(N, M);
				}
			}
		}
	}
}
