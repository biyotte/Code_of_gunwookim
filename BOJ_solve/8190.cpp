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
const long long llINF = 2e18;
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
int n,m,k,st[205];
ll p1[100005],p2[100005];
ll h1[100005],h2[100005];
const ll hmod1 = 1e9+409;
const ll hmod2 = 1e9+433;
string in[205];
int len[205];
char a[100005];

bool isSame(int l,int r,int l2,int r2) {
	ll v11 = (h1[r]-h1[l-1]*p1[r-l+1]%hmod1+hmod1)%hmod1;
	ll v12 = (h2[r]-h2[l-1]*p2[r-l+1]%hmod2+hmod2)%hmod2;

	ll v21 = (h1[r2]-h1[l2-1]*p1[r2-l2+1]%hmod1+hmod1)%hmod1;
	ll v22 = (h2[r2]-h2[l2-1]*p2[r2-l2+1]%hmod2+hmod2)%hmod2;
	return (v11*hmod2+v12 == v21*hmod2+v22);
}

struct Ret {
	ll a[201][201];
}one,ans;

Ret plu(Ret &A,Ret &B) {
	Ret d;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			d.a[i][j] = llINF;
		}
	}
	for(int l = 1;l <= n;l++) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				d.a[i][j] = min(d.a[i][j],A.a[i][l]+B.a[l][j]);
			}
		}
	}
	return d;
}

Ret mpow(int M) {
	Ret ret,now;
	if(M < 0) return ret;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			ret.a[i][j] = now.a[i][j] = one.a[i][j];
		}
	}
	while(M) {
		if(M % 2) ret = plu(ret,now);
		now = plu(now,now);
		M /= 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> in[i];
		len[i] = in[i].length();
		st[i] = m+1;
		for(int j = 0;j < len[i];j++) a[++m] = in[i][j];
	}
	p1[0] = p2[0] = 1;
	for(int i = 1;i <= m;i++) {
		p1[i] = p1[i-1]*257%hmod1;
		p2[i] = p2[i-1]*257%hmod2;
		h1[i] = (h1[i-1]*257+a[i])%hmod1;
		h2[i] = (h2[i-1]*257+a[i])%hmod2;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			int g = min(len[i],len[j])-(i == j);
			while(g&&!isSame(st[i]+len[i]-g,st[i]+len[i]-1,st[j],st[j]+g-1)) g--;
			one.a[i][j] = len[j]-g;
		}
	}
	ans = mpow(k-2);
	ll rans = llINF;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) rans = min(rans,ans.a[i][j]+len[i]);
	}
	cout << rans;
}