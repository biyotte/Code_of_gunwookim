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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[3005],d[3005],cnt[3005],t[3005];

void update(int x,int val) {
	for(;x <= n;x += x&-x) t[x] += val;
}

int query(int l,int r) {
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		d[n] = 0;
		for(int i = n-1;i >= 1;i--) {
			d[i] = INF;
			if(a[i] == 0) continue;
			int cnt = 0;
			for(int j = i+1;j <= i+a[i];j++) {
				if(a[j] == 0&&j != n) continue;
				if(d[j] < INF) cnt++;
				if(!cnt) continue;
				d[i] = min(d[i],d[j]+cnt-1);

				update(j+a[j],1);
			}
			for(int j = i+1;j <= i+a[i];j++) {
				if(a[j] == 0&&j != n) continue;
				update(j+a[j],-1);
			}
			cout << i << " -> " << d[i] << "\n";
		}
		cout << d[1] << '\n';
	}
}