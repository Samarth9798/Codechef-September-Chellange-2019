#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

ll N, M;

void subtask1()
{
	if(N == 1)
	{
		return;
	}
	vector<string> ans;
	vector<pair<ll,ll>> v;
	v.push_back({0,N-1});
	while(1)
	{
		vector<pair<ll,ll>> x = v;
		if(x.size() == 0) break;
		string s(N, '0');
		v.clear();
		for(ll i = 0; i < x.size(); i++)
		{
			ll l = x[i].first;
			ll r = x[i].second;
			ll mid = (l+r)/2;
			for(ll j = l; j <= mid; j++) s[j] = '1';
			if(l < mid)
				v.push_back({l,mid});
			if(mid+1 < r)
				v.push_back({mid+1, r});
		}
		ans.push_back(s);
	}
	
	cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}

void subtask2()
{
    if(M == 0)
    {
        cout << 0;
        return;
    }
    
    vector<string> ans;
    set<int> adj[N+5];
    for(int i = 0; i < M; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    
    map<set<int>, vector<int>> m;
    for(int i = 1; i <= N; i++)
    {
        m[adj[i]].push_back(i);
    }
    
    //check if possible or not
    for(auto it = m.begin(); it != m.end(); it++)
    {
        set<int> s = it->first;
        vector<int> v = it->second;
        int vis[N+5];
        memset(vis, 0, sizeof(vis));
        for(ll i : s) vis[i] = 1;
        for(ll i : v) vis[i] = 1;
        for(int i = 1; i <= N; i++)
        {
            if(vis[i] == 0)
            {
                cout << -1;
                return;
            }
        }
    }
    
    vector<int> f;
    unordered_map<int, vector<int>> hash;
    int cnt = 1;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        f.push_back(cnt);
        hash[cnt++] = it->second;
    }
    
    vector<vector<int>> v;
    v.push_back(f);
    while(1)
    {
        vector<vector<int>> curr = v;
        if(curr.size() == 0) break;
        
        v.clear();
        string s(N, '0');
        
        for(int i = 0; i < curr.size(); i++)
        {
            f = curr[i];
            int mid = f.size()/2;
            vector<int> L,R;
            for(int j = 0; j < mid; j++) L.push_back(f[j]);
            for(int j = mid; j < f.size(); j++) R.push_back(f[j]);
            
            for(int j = 0; j < L.size(); j++)
            {
                vector<int> V = hash[L[j]];
                for(int k = 0; k < V.size(); k++)
                {
                    int x = V[k];
                    s[x-1] = '1';
                }
            }
            
            if(L.size() > 1) v.push_back(L);
            if(R.size() > 1) v.push_back(R);
        }
        
        ans.push_back(s);
    }
    
    if(ans.size() == 0)
    {
        cout << -1;
        return;
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}

int main()
{
    fast
    
    cin >> N >> M;

    if(M == (N*(N-1))/2)
    {
    	subtask1();
    	return 0;
    }

    subtask2();
}
