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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int d[101][101][2001][2];
int a[105],b[105],T[105];
int n,m,k;
struct Monster {int a,b,t;}A[105];
int dist(int x,int y) {return abs(x-y);}
bool cmp(Monster x,Monster y) {return x.a < y.a;}
//d[l][r][t][fl] : t시간에 l~r 구간의 포켓몬을 봤고 fl이 마지막일때 (fl=0 : l, fl=1 : r) 가능한 최대 사탕 양

int go(int l,int r,int t,int fl) {
	if(t > 2000) return -INF;
	if(d[l][r][t][fl] != -1) return d[l][r][t][fl];
	int wa = (!fl ? a[l] : a[r]), wb = (!fl ? b[l] : b[r]), wt = (!fl ? T[l] : T[r]);
	d[l][r][t][fl] = max((l >= 2 ? go(l-1,r,t+dist(wa,a[l-1]),0) : 0),(r <= m ? go(l,r+1,t+dist(wa,a[r+1]),1) : 0))+(t <= wt)*wb;
	return d[l][r][t][fl];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> m;
	for(int i = 1;i <= m;i++) {
		cin >> a[i] >> b[i] >> T[i];
		A[i] = {a[i],b[i],T[i]-1};
	}
	A[m+1] = {k,0,-1};
	sort(A+1,A+m+2,cmp);
	memset(d,-1,sizeof(d));
	for(int i = 1;i <= m+1;i++) {
		a[i] = A[i].a, b[i] = A[i].b, T[i] = A[i].t;
	}
	for(int i = 1;i <= m+1;i++) {
		if(a[i] == k) {
			cout << go(i,i,0,0);
			return 0;
		}
	}
}
