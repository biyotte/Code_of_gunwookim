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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,mn;
ll a[10005],b[10005];

void build(int st) {
	int x = st, ch = 1, val;
	mn = val = 0;
	while(ch||x != st) {
		ch = 0;
		b[x] = val;
		mn = min(mn,val);
		val += a[(x+1)%n+1]-a[x%n+1];
		x = (x+2)%n+1;
	}
}

void plus_chain(int st,int val) {
	int x = st, ch = 1;
	while(ch||x != st) {
		ch = 0;
		b[x] += val;
		x = (x+2)%n+1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n % 3) {
		build(1);
		plus_chain(1,(a[2]-b[1]-b[2]-b[3])/3);
	}
	else {
		build(1), plus_chain(1,1-mn);
		build(2), plus_chain(2,1-mn);
		build(3), plus_chain(3,a[2]-b[1]-b[2]);
	}
	for(int i = 1;i <= n;i++) cout << b[i] << '\n';
}