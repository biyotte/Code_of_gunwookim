#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,c[5005];
vec v[5005];

struct Point {
	double x1,y1,x2,y2;
	double gx,gy;
}a[5005];

bool isok(int x,int y) {
	if(x == y) return false;
	double l = max(a[x].x1,a[y].x1), r = min(a[x].x2,a[y].x2);
	if(l <= r) return (a[x].gx*l+a[x].gy <= a[y].gx*l+a[y].gy);
	return false;
}

stack <int> st;

void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	for(int i : v[x]) dfs(i);
	st.push(x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		if(a[i].x1 > a[i].x2) swap(a[i].x1,a[i].x2), swap(a[i].y1,a[i].y2);
		if(a[i].x1 == a[i].x2) a[i].gx = 0;
		else a[i].gx = (double)(a[i].y1-a[i].y2)/(a[i].x1-a[i].x2);
		a[i].gy = (double)a[i].y1-a[i].gx*a[i].x1;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(isok(i,j)) v[i].pb(j);
		}
	}
	for(int i = 1;i <= n;i++) dfs(i);
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
