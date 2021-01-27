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
int n,usex[3005],usey[3005];
pi ans[3005];

struct Rook {
	int x1,y1,x2,y2,idx;
}a[3005];

bool cmp(Rook x,Rook y) {
	if(x.x2 == y.x2) return x.y2 < y.y2;
	return x.x2 < y.x2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		a[i].idx = i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) {
		int x = 0,y = 0;
		for(int j = a[i].x1;j <= a[i].x2;j++) {
			if(!usex[j]) {
				usex[j] = 1, x = j;
				break;
			}
		}
		for(int j = a[i].y1;j <= a[i].y2;j++) {
			if(!usey[j]) {
				usey[j] = 1, y = j;
				break;
			}
		}
		if(!x||!y) {
			cout << "NIE";
			return 0;
		}
		ans[a[i].idx] = {x,y};
	}
	for(int i = 1;i <= n;i++) {
		cout << ans[i].x << ' ' << ans[i].y << '\n';
	}
}