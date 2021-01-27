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
int n,m,t[800005],la[800005];
int sum[800005];
pi a[100005];
vec rev,co[200005];

void push(int x,int l,int r) {
	if(la[x]) {
		t[x] += la[x];
		if(l^r) la[x*2] += la[x], la[x*2+1] += la[x];
		la[x] = 0;
	}
}

void update(int x,int l,int r,int rl,int rr,int val) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x] = val;
		push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
	t[x] = max(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int gar1,L,gar2,R;
		cin >> gar1 >> R >> gar2 >> L;
		a[i] = {L,R};
		rev.pb(L), rev.pb(R);
	}
	sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
	m = rev.size();
	for(int i = 1;i <= n;i++) {
		a[i].x = lower_bound(all(rev),a[i].x)-rev.begin()+1;
		a[i].y = lower_bound(all(rev),a[i].y)-rev.begin()+1;
		co[a[i].x].pb(i);
		update(1,1,m,a[i].x,a[i].y,1);
	}
	int ans = 0;
	for(int i = 1;i <= m;i++) {
		sum[i] += sum[i-1];
		for(int j : co[i]) {
			sum[a[j].x]++, sum[a[j].y+1]--;
			update(1,1,m,a[j].x,a[j].y,-1);
		}
		ans = max(ans,sum[i]+t[1]);
		
	}
	cout << ans;
}