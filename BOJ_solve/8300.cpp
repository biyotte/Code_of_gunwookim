#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
#define get(a,x) (((a[x/64] >> (x & 63)) & 1) == 1)
#define set(a,x) (a[x/64] |= 1llu << (x & 63))
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e16;
const long long mod = 998244353;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef unsigned long long ull;
typedef long long ll;

int Minusbit (ull &x,ull y) {
	ull tmp = x;
	x -= y;
	return tmp < x;
}

int LCS(string a,string b) {
	vector <ull> ch[256];
	int n = a.length(), m = b.length();
	int sz = m/64+1;
	for(int i = 0;i < 256;i++) ch[i].resize(sz);
	for(int i = 0;i < m;i++) set(ch[b[i]],i);

	vector <ull> d(sz);
	for(int i = 0;i < m;i++) {
		if(a[0] == b[i]) {
			set(d,i); break;
		}
	}

	for(int i = 1;i < n;i++) {
		ull add_bit = 1, minus_bit = 0;
		for(int j = 0;j < sz;j++) {
			ull x = ch[a[i]][j] | d[j];
			ull tmp1 = (d[j] << 1) | add_bit;
			add_bit = d[j] >> 63;

			ull tmp2 = x;
			minus_bit = Minusbit(tmp2,minus_bit);
			minus_bit += Minusbit(tmp2,tmp1);

			d[j] = x & (x ^ tmp2);
		}
	}
	int ans = 0;
	for(int i = 0;i < m;i++) if(get(d,i)) ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string a; cin >> a;
	string b,c;
	int ans = n;
	for(int i = 0;i < n-1;i++) {
		b.clear(), c.clear();
		for(int j = 0;j <= i;j++) b += a[j];
		for(int j = i+1;j < n;j++) c += a[j];
		ans = min(ans,n-LCS(b,c)*2);
	}
	cout << ans;
}