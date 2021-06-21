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
int n,d[1000005],mx,num2,c[1000005];
struct Query {
	int op;
	int x,y;
}q[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> q[i].op >> q[i].x;
		if(q[i].op & 2) cin >> q[i].y;
		d[i] = -INF;
	}
	d[1] = 0;
	c[1] = 1;
	for(int i = 1;i <= n;i++) {
		int x = q[i].x, y = q[i].y;
		if(q[i].op & 1) c[x] = 1, d[x] = ++mx;
		else {
			if(c[x]) c[y] = 1;
			num2++;
			d[y] = max(d[y],d[x]);
			d[x]--;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(!c[i]) cout << "-1 ";
		else cout << n-d[i]-num2 << ' ';
	}
}