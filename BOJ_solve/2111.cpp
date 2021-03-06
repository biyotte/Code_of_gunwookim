#include <bits/stdc++.h>
#include <complex>
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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;

typedef complex<double> comp;
typedef vector<comp> vc;
const double P = acos(-1);

int tmp[100005];
int n,m,co,num;
int p[MAXN+5],c[MAXM+5];
int pidx[MAXN+5],now[MAXN+5],low[MAXN+5];
bool isCactus = true;
vec v[MAXN+5];
stack <pi> st;
vector <vec> bcc;
vector <vecpi> edge;

void FFT(vc &a,comp w) {
	int n = a.size();
	if(n == 1) return;
	vc even(n/2),odd(n/2);
	for(int i = 0;i < n;i++) {
		if(i&1) odd[i/2] = a[i];
		else even[i/2] = a[i];
	}
	FFT(even,w*w), FFT(odd,w*w);
	comp tw(1,0);
	for(int i = 0;i < n/2;i++) {
		a[i] = even[i]+odd[i]*tw;
		a[i+n/2] = even[i]-odd[i]*tw;
		tw *= w;
	}
}

void calc(vc a,vc b,vc &ans) {
	int n = 1;
	while(n <= max(a.size(),b.size())) n *= 2;
	n *= 2;
	a.resize(n), b.resize(n);
	ans.resize(n);
	comp w(cos(2*P/n),sin(2*P/n));
	FFT(a,w), FFT(b,w);
	for(int i = 0;i < n;i++) ans[i] = a[i]*b[i];
	FFT(ans,comp(1,0)/w);
	for(int i = 0;i < n;i++) {
		ans[i] /= comp(n,0);
		ans[i] = comp(round(ans[i].real()),round(ans[i].imag()));
	}
}

void getAns(vc a,vc b,vc &ans) {
	int n = a.size(), m = b.size();
	calc(a,b,ans);
	int go = 0;
	for(auto i : ans) tmp[++go] = i.real();
	ans.clear();
	for(int i = n+m-1;i >= 0;i--) {
		if(!i&&tmp[i]%10 == 0) continue;
		ans.push_back(tmp[i]%10);
		if(i) tmp[i-1] += tmp[i]/10;
	}
	reverse(ans.begin(),ans.end());
}

void BCCdfs(int x,int la) {
	now[x] = low[x] = ++co;
	for(int nx : v[x]) {
		if(nx == la) continue;
		if(now[x] > now[nx]) st.push({x,nx});
		if(now[nx]) low[x] = min(low[x],now[nx]);
		else {
			BCCdfs(nx,x);
			low[x] = min(low[x],low[nx]);
			if(now[x] <= low[nx]) {
				vecpi tmp;

				while(st.top() != make_pair(x,nx)) {
					tmp.pb(st.top()); st.pop();
				}
				if(st.empty()) exit(-1);
				tmp.pb(st.top()); st.pop();
				edge.pb(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int cn,x,y; cin >> cn >> x;
		if(!cn) return -1;
		cn--;
		while(cn--) {
			cin >> y;
			if(x == y) return -1;
			v[x].pb(y), v[y].pb(x);
			x = y;
		}
	}
	int com = 0;
	for(int i = 1;i <= n;i++) if(!now[i]) com++, BCCdfs(i,-1);
	if(com >= 2) return -1;
	for(vecpi E : edge) {
		vec tmp;
		for(pi i : E) tmp.pb(i.x), tmp.pb(i.y);
		sort(all(tmp)), tmp.erase(unique(all(tmp)),tmp.end());
		bcc.pb(tmp);
	}
	m = bcc.size();
	vc ans,ans2;
	int tc = 1;
	ans.pb(1);
	for(int i = 0;i < m;i++) {
		int V = bcc[i].size(), E = edge[i].size();
		if(V != E&&V != E+1) {
            cout << 0;
            return 0;
		}
		if(V == E) {
			vc tmp;
			int val = E+1;
			while(val) {
				tmp.pb(val%10);
				val /= 10;
			}
			if(tc) ans2.clear(), getAns(ans,tmp,ans2);
			else ans.clear(), getAns(ans2,tmp,ans);
			tc ^= 1;
		}
	}
	if(!tc) swap(ans,ans2);
	for(auto i : ans) cout << i.real();
}
