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
int n,m;
int a[105],c[105];
pi q[1005];

struct Ans {int x,y,g;};
vector <Ans> ans;

bool cmp(int x,int y) {
	return a[x] > a[y];
}

int Get(int l,int r) {
	return rand()%(r-l+1)+l;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= m;i++) {
		cin >> q[i].x >> q[i].y;
	}
	while(1) {
		int fl = 1;
		ans.clear();
		for(int i = 1;i <= n;i++) a[i] = c[i];
		for(int i = 1;i <= m;i++) {
			if(max(0,2-a[q[i].y]) > min(2,a[q[i].x])) {fl = 0; break;}
			int g = Get(max(0,2-a[q[i].y]),min(2,a[q[i].x]));
			a[q[i].x] -= g, a[q[i].y] -= 2-g;
			ans.pb({q[i].x,q[i].y,g});
		}
		if(!fl) continue;
		int nv = 0;
		for(int i = 1;i <= n;i++) {
			while(a[i] > 1) {
				ans.pb({i,i%n+1,2});
				a[i] -= 2;
			}
			if(a[i]) {
				if(nv) ans.pb({nv,i,1}), nv = 0;
				else nv = i;
			}
		}
		cout << ans.size() << '\n';
		for(Ans i : ans) {
			cout << i.x << ' ' << i.y << ' ' << i.g << '\n';
		}
		break;
	}
}