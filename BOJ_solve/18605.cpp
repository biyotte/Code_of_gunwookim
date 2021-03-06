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
int T;
int n,c[100005];
int a[100005],b[100005];
priority_queue <pair<int,pi>> po,pt,mo,mt;

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		while(!po.empty()) po.pop();
		while(!pt.empty()) pt.pop();
		while(!mo.empty()) mo.pop();
		while(!mt.empty()) mt.pop();
		for(int i = 1;i <= n;i++) {
			cin >> a[i] >> b[i];
			c[i] = 0;
			po.push({a[i],{i,0}});
			pt.push({a[i]+b[i],{i,0}});
		}
		int ans = 0;
		for(int tc = 1;tc <= 2*n;tc++) {
			while(!po.empty()&&c[po.top().y.x] != po.top().y.y) po.pop();
			if(po.empty()) return 0;
			ans += po.top().x;
			int idx = po.top().y.x;
			c[idx]++;
			mo.push({-po.top().x,{idx,c[idx]}});
			po.pop();
			if(c[idx] < 2) po.push({b[idx],{idx,c[idx]}});
			if(c[idx] == 2) mt.push({-a[idx]-b[idx],{idx,2}});
			while(1) {
				while(!mt.empty()&&c[mt.top().y.x] != mt.top().y.y) mt.pop();
				while(!pt.empty()&&c[pt.top().y.x] != pt.top().y.y) pt.pop();
				if(mt.empty()||pt.empty()) break;
				if(-mt.top().x >= pt.top().x) break;
				ans += pt.top().x+mt.top().x;
				int pidx = pt.top().y.x, midx = mt.top().y.x;
				c[pidx] = 2;
				c[midx] = 0;
				pt.pop(), mt.pop();
				po.push({a[midx],{midx,0}});
				pt.push({a[midx]+b[midx],{midx,0}});
				mo.push({-a[pidx],{pidx,2}});
				mt.push({-a[pidx]-b[pidx],{pidx,2}});
			}
			while(1) {
				while(!mo.empty()&&c[mo.top().y.x] != mo.top().y.y) mo.pop();
				while(!po.empty()&&c[po.top().y.x] != po.top().y.y) po.pop();
				if(mo.empty()||po.empty()) break;
				if(-mo.top().x >= po.top().x) break;
				cout << po.top().x << ", " << po.top().y.x << ' ' << mo.top().x << ", " << mo.top().y.x << '\n';
				ans += po.top().x+mo.top().x;
				int pidx = po.top().y.x, midx = mo.top().y.x;
				int pval = po.top().x, mval = -mo.top().y.x;
				c[pidx]++;
				c[midx]--;
				po.pop(), mo.pop();
				mo.push({-pval,{pidx,c[pidx]}});
				if(c[pidx] < 2) po.push({b[pidx],{pidx,c[pidx]}});
				if(c[pidx] == 2) mt.push({-a[pidx]-b[pidx],{pidx,2}});

				po.push({mval,{midx,c[midx]}});
				if(c[midx]) mo.push({-a[midx],{midx,c[midx]}});
				if(!c[midx]) pt.push({a[midx]+b[midx],{midx,0}});
				
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}