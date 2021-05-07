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
const int MAXM = 1000001;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int Q;
int t[4000005],cnt[4000005];

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		if(!t[x]) cnt[x]++;
		t[x] += val;
		if(!t[x]) cnt[x]--;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = t[x*2]+t[x*2+1];
	cnt[x] = cnt[x*2]+cnt[x*2+1];
}

int query(int x,int l,int r) {
	if(l == r) return 0;
	int mid = (l + r) >> 1;
	if(cnt[x*2] == mid-l+1) return t[x*2]+query(x*2+1,mid+1,r);
	return query(x*2,l,mid);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> Q;
	while(Q--) {
		int x,y; cin >> x >> y;
		update(1,1,MAXM,y,3-2*x);
		cout << query(1,1,MAXM) << '\n';
	}
} 