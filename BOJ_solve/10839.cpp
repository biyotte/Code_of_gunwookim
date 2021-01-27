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
int n,s,e;
int st[100005],top;

struct Point {
	ll x,y;
}a[100005];

int ccw(int x,int y,int z) { // 1 : 시계, -1 : 반시계
	ll op = a[x].x*a[y].y+a[y].x*a[z].y+a[z].x*a[x].y;
	op -= a[x].y*a[y].x+a[y].y*a[z].x+a[z].y*a[x].x;
	if(op > 0) return 1;
	else if(op < 0) return -1;
	return 0;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
	}
	a[n+1].x = a[1].x;
	cin >> s >> e; s++, e++;
	int sw = 0;
	if(s == 1) s += n;
	if(e == 1) e += n;
	if(s > e) swap(s,e), sw = 1;
	for(int i = s;i <= e;i++) {
		while(top >= 2&&ccw(st[top-1],st[top],i) >= 0) top--;
		st[++top] = i;
	}
	cout << top << '\n';
	if(sw) reverse(st+1,st+top+1);
	for(int i = 1;i <= top;i++) cout << (st[i] == n+1 ? 0 : st[i]-1) << ' ';
}
