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
const long long llINF = 1e18+10;
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
int n;
int L[105],R[105];
int d[105][105];
// d[l][r] : l~r구간에서 선공이 무조건 이길 수 있는가?

int go(int l,int r) {
	int &ret = d[l][r];
	if(ret != -1) return ret;
	ret = 0;
	vec v;
	for(int i = 1;i <= n;i++) {
		if(l <= L[i]&&R[i] <= r) {
			int le = go(l,L[i]);
			int ri = go(R[i],r);
			v.pb(le^ri);
		}
	}
	sort(all(v)), v.erase(unique(all(v)),v.end());
	for(int i = 0;i < v.size();i++) {
		if(i != v[i]) return ret = i;
	}
	return ret = v.size();
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		memset(d,-1,sizeof(d));
		for(int i = 1;i <= n;i++) {
			cin >> L[i] >> R[i];
		}
		cout << (go(1,100) ? "Alice" : "Bob") << '\n';
	}
}
