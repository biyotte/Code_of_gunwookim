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
const int mod = 998244353;
const long long hashmod = 1e9+9;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char a[505][505],b[505][505];
ll ha[505][505],hb[505][505];
int n,m;
ll mpow[505],mrev[505];

ll fpow(ll x,ll mm) {
    if(!mm) return 1;
    ll tmp = fpow(x,mm/2);
    tmp = tmp*tmp % hashmod;
    if(mm % 2) return tmp*x%hashmod;
    return tmp;
}

ll getHashA(int x,int l,int r) {
	return ((ha[x][r]-ha[x][l-1]+hashmod)%hashmod)*mrev[l-1]%hashmod;
}

ll getHashB(int x,int l,int r) {
	return ((hb[x][r]-hb[x][l-1]+hashmod)%hashmod)*mrev[l-1]%hashmod;
}

bool isok(int wi) {
	for(int l = 1;l <= m-wi+1;l++) {
		int ch = 1; set <ll> s;
		for(int i = 1;i <= n;i++) s.insert(getHashA(i,l,l+wi-1));
		for(int i = 1;i <= n;i++) {
			if(s.find(getHashB(i,l,l+wi-1)) != s.end()) {
				ch = 0;
				break;
			}
		}
		if(ch) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i]+1;
	for(int i = 1;i <= n;i++) cin >> b[i]+1;
	mpow[0] = mrev[0] = 1;
	for(int i = 1;i <= m;i++) mpow[i] = (mpow[i-1]*31)%hashmod;
	for(int i = 1;i <= m;i++) mrev[i] = fpow(mpow[i],hashmod-2);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			ha[i][j] = (ha[i][j-1]+(a[i][j]-'A')*mpow[j-1])%hashmod;
			hb[i][j] = (hb[i][j-1]+(b[i][j]-'A')*mpow[j-1])%hashmod;
		}
	}
	int l = 0,r = m;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	cout << l;
} 
