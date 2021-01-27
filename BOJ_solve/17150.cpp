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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int go,n,ans[2][500005];

struct Misul {
	int p,s,idx;
	bool operator < (const Misul &x) const {return s < x.s;}
}in[500005];
multiset <Misul> a[2][500005];

bool cmp(Misul x,Misul y) {
	return x.p < y.p;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; 
	for(int i = 0;i < 2;i++) {
		for(int j = 1;j <= n;j++) cin >> in[j].p;
		for(int j = 1;j <= n;j++) cin >> in[j].s, in[j].idx = j;
		sort(in+1,in+n+1,cmp), go = 0;
		in[0].p = -INF;
		for(int j = 1;j <= n;j++) {
			if(in[j].p != in[j-1].p) go++;
			a[i][go].insert(in[j]);
		}
	}
	go = 0;
	for(int i = 1,j = 1;go < n;) {
		if(a[0][i].size() < a[1][j].size()) {
			for(auto k : a[0][i]) {
				auto it = a[1][j].upper_bound({k.p,k.s-1,k.idx});
				if(it == a[1][j].begin()) {
					cout << "impossible";
					return 0;
				}
				it--;
				ans[0][++go] = k.idx;
				ans[1][go] = it->idx;
				a[1][j].erase(it);
			}
			i++;
		}
		else {
			for(auto k : a[1][j]) {
				auto it = a[0][i].upper_bound(k);
				if(it == a[0][i].end()) {
					cout << "impossible";
					return 0;
				}
				ans[1][++go] = k.idx;
				ans[0][go] = it->idx;
				a[0][i].erase(it);
			}
			j++;
		}
	}
	for(int i = 0;i < 2;i++) {
		for(int j = 1;j <= n;j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}