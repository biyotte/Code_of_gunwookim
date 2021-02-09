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
int a[100005],b[100005],b2[100005],m,m2;
int n;
queue <int> v[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], v[a[i]].push(i);
	for(int i = 1;i <= n;i++) {
		int la = INF,la2 = INF;
		if(!v[b[m]].empty()) la = v[b[m]].front();
		if(!v[b2[m2]].empty()) la2 = v[b2[m2]].front();
		if(la == i) la = INF+1;
		if(la2 == i) la2 = INF+1;
		if(la < la2) b[++m] = a[i];
		else b2[++m2] = a[i];
		v[a[i]].pop();
	}
	int ans = 0;
	for(int i = 0;i < m;i++) ans += (b[i] != b[i+1]);
	for(int i = 0;i < m2;i++) ans += (b2[i] != b2[i+1]);
	cout << ans;
}
