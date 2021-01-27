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
int n,sum,ans,a[505];
int d[501][50001];

int go(int x,int diff) {
	if(x == n+1) return (diff > 0)*(-INF);
	if(diff > sum/2) return -INF;
	int &ret = d[x][diff];
	if(ret != -1) return ret;
	return ret = max({go(x+1,diff),go(x+1,diff+a[x])+a[x],go(x+1,abs(diff-a[x]))+max(0,a[x]-diff)});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
	memset(d,-1,sizeof(d));
	ans = go(1,0); ans += sum-2*ans;
	cout << ans;
}