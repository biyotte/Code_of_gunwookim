#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e16;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,pv,ans,no[35];
int sumXor[100005];

struct Node {
	int p[2];
}trie[4000000];

void Clear() {
	memset(trie,0,sizeof(trie));
}

void update(int x) {
	int p = 1;
	for(int i = 0;i < 31;i++) {
		no[30-i] = x%2;
		x /= 2;
	}
	for(int i = 0;i < 31;i++) {
		int now = no[i];
		if(!trie[p].p[now]) trie[p].p[now] = ++pv;
		p = trie[p].p[now];
	}
}

void query(int x) {
	for(int i = 0;i < 31;i++) {
		no[30-i] = 1-x%2;
		x /= 2;
	}
	int gop = (1 << 30), p = 1;
	int ret = 0;
	for(int i = 0;i < 31;i++) {
		int now = no[i];
		if(!trie[p].p[now]) p = trie[p].p[now^1];
		else {
			p = trie[p].p[now];
			ret += gop;
		}
		gop /= 2;
	}
	ans = max(ans,ret);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		int Xor = 0,x;
		pv = 1;
		ans = 0;
		Clear();
		update(0);
		for(int i = 1;i <= n;i++) {
			cin >> x; Xor ^= x;
			query(Xor);
			update(Xor);
		}
		cout << ans << '\n';
	}
}