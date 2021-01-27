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
int n,m,a[1005][1005];
ll h[1005],w[1005],sw,ans;
int h2[1005][1005];

struct Stack {
	ll x,y,idx;
};

stack <Stack> s;

void getAns(int M) {
	while(!s.empty()) s.pop();
	s.push({0,0});
	sw = 0;
	for(int i = 1;i <= M+1;i++) {
		while(s.size() > 1&&s.top().y >= h[i]) {
			ll y = s.top().y; s.pop();
			ll len = s.top().y;
			ll wlen = (sw-s.top().x-w[s.top().idx]);
			ans += y*(wlen*(wlen+1)/2LL);
			ans -= max(len,h[i])*(wlen*(wlen+1)/2LL);
		}
		s.push({sw,h[i],i});
		sw += w[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin >> a[i][j];
	}
	for(int i = n;i >= 1;i--) {
		for(int j = 1;j <= m;j++) h2[i][j] = (a[i][j] == a[i+1][j] ? h2[i+1][j]+1 : 1);
		int la = 1;
		for(int j = 2;j <= m;j++) {
			if(a[i][j] != a[i][j-1]) {
				for(int l = la;l < j;l++) w[l-la+1] = 1, h[l-la+1] = h2[i][l];
				h[j-la+1] = w[j-la+1] = 0;
				getAns(j-la);
				la = j;
			}
		}
		for(int l = la;l <= m;l++) w[l-la+1] = 1, h[l-la+1] = h2[i][l];
		h[m-la+2] = w[m-la+2] = 0;
		getAns(m-la+1);
	}
	cout << ans;
}
