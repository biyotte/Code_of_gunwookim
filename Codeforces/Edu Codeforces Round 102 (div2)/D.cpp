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
int n,Q;
int l[200005],r[200005],mnl[200005],mnr[200005],mxl[200005],mxr[200005];
char s[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> Q >> s+1;
		for(int i = 0;i <= n+1;i++) l[i] = r[i] = 0, mnl[i] = mnr[i] = 0, mxl[i] = mxr[i] = 0;
		for(int i = 1;i <= n;i++) l[i] = l[i-1]+(s[i] == '+' ? 1 : -1);
		for(int i = n;i >= 1;i--) r[i] = r[i+1]+(s[i] == '-' ? 1 : -1);
		for(int i = 1;i <= n;i++) {
			mnl[i] = min(mnl[i-1],l[i]);
			mxl[i] = max(mxl[i-1],l[i]);
		}
		for(int i = n;i >= 1;i--) {
			mnr[i] = min(mnr[i+1],r[i]);
			mxr[i] = max(mxr[i+1],r[i]);
		}
		while(Q--) {
			int L,R; cin >> L >> R;
			int now = l[L-1];
			int mn = mnl[L-1], mx = mxl[L-1];
			mn = min(mn,mnr[R+1]+now-r[R+1]), mx = max(mx,mxr[R+1]+now-r[R+1]);
			cout << mx-mn+1 << '\n';
		}
	}
}