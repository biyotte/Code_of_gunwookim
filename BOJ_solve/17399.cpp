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
int n,Q,dep[100005],sp[100005][20];
vec v[100005];

void dfs_init(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		sp[i][0] = x;
		dep[i] = dep[x]+1;
		dfs_init(i,x);
	}
}

void make_sparse() {
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) {
			sp[j][i] = sp[sp[j][i-1]][i-1];
		}
	}
}

int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[x]-(1 << i) >= dep[y]) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int Go(int x,int cnt) {
	for(int i = 19;i >= 0;i--) {
		if(cnt >= (1 << i)) cnt -= (1 << i), x = sp[x][i];
	}
	return x;
}

int dist(int x,int y) {
	return dep[x]+dep[y]-dep[LCA(x,y)]*2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dep[1] = 1, dfs_init(1,-1); make_sparse();
	cin >> Q;
	while(Q--) {
		int A,B,C; cin >> A >> B >> C;
		if(dep[A] % 2 != dep[B] % 2||dep[A] % 2 != dep[B] % 2||dep[A] % 2 != dep[B] % 2) {
			cout << "-1\n";
			continue;
		}
		int wi,mx = -1;
		int len = dist(A,B);
		if(mx < len) {
			if(dep[A] > dep[B]) wi = Go(A,len/2);
			else wi = Go(B,len/2);
			mx = len;
		}
		len = dist(B,C);
		if(mx < len) {
			if(dep[B] > dep[C]) wi = Go(B,len/2);
			else wi = Go(C,len/2);
			mx = len;
		}
		len = dist(A,C);
		if(mx < len) {
			if(dep[A] > dep[C]) wi = Go(A,len/2);
			else wi = Go(C,len/2);
			mx = len;
		}
		int lenA = dist(A,wi), lenB = dist(B,wi), lenC = dist(C,wi);
		if(lenA != lenB||lenA != lenC||lenB != lenC) {
			cout << "-1\n";
			continue;
		}
		cout << wi << '\n';
	}
}