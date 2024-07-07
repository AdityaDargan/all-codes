#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <stack>
#include <set>
#define ll long long
using namespace std;

class seg_tree
{
public:
	ll n;
	vector<ll> tr;
	seg_tree(vector<ll> v)
	{
		n = v.size();
		tr.resize(4 * n);
		fill(tr.begin(), tr.end(), 0);
		for (ll i = 0; i < n; i++)
			update(i, v[i]);
	}
	ll getsum(ll qs, ll qe, ll s = 0, ll e = -1, ll ci = 0)
	{
		if (e == -1)
			e = n - 1;
 
		if (qs > e || qe < s)
			return 0;
		else if (qs <= s && e <= qe)
			return tr[ci];
 
		ll mid = (s + e) / 2;
		return getsum(qs, qe, s, mid, 2 * ci + 1) + getsum(qs, qe, mid + 1, e, 2 * ci + 2);
	}
	ll update(ll ind, ll dat, ll s = 0, ll e = -1, ll ci = 0)
	{
		if (e == -1)
			e = n - 1;
 
		if (s > ind || e < ind)
			return tr[ci];
		else if (s == e)
		{
			tr[ci] = dat;
			return dat;
		}
 
		ll mid = (s + e) / 2;
		return tr[ci] = update(ind, dat, s, mid, 2 * ci + 1) + update(ind, dat, mid + 1, e, 2 * ci + 2);
	}
};
bool check(ll x, vector<ll> &a, ll n)
{
	ll diff = (2 * n) - 1;
	for (ll i = x; i < x + n; i++)
	{
		if (a[i] != a[i + diff])
			return 0;
		diff -= 2;
	}
	return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t = 1;
	cin >> t;
	for (ll ii = 1; ii <= t; ii++)
	{
		cout << "Case #" << ii << ": ";
		ll n;
		cin >> n;
		vector<ll> a(n), b(n);
		for(ll i=0; i<n;i++)
		{
			cin >> a[i];
		}
		for(ll i=0;i<n;i++)
		{
			cin >> b[i];
			a.push_back(b[i]);
		}
		vector<ll> c(4 * n);
		for(ll i=0;i<2*n;i++)
		{
			a.push_back(a[i]);
		}
		for(ll i=0;i<4 * n;i++)
		{
			if (a[i] > a[(i + n) % (2 * n)])
				c[i] = -1;
			else if (a[i] < a[(i + n) % (2 * n)])
				c[i] = 1;
			else
				c[i] = 0;
		}
		seg_tree s(c);
		ll ans = -1;
		if (n % 2 == 0)
		{
			for (ll i = 0; i < 2 * n; i++)
			{
				if ((s.getsum(i, i + ((n / 2) - 1)) == (n / 2)) && (s.getsum(i + (n / 2), i + n - 1) == -(n / 2)))
				{
					if (check(i, a, n))
					{
						ans = i;
						break;
					}
					else
						i += n - 1;
				}
			}
		}
		else
		{
			for (ll i = 0; i < 2 * n; i++)
			{
				if ((s.getsum(i, i + ((n / 2) - 1)) == (n / 2)) && (s.getsum(i + (n / 2) + 1, i + n - 1) == -(n / 2)))
				{
					if (check(i, a, n))
					{
						ans = i;
						break;
					}
					else
						i += n - 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}