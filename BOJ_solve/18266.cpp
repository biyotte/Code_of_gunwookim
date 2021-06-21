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
int n,L,w[50005];
int lsum[50005],rsum[50005];

// not solved

struct Cow {
	int w,x,d,time;
}a[50005];

bool cmpx(Cow x,Cow y) {
	return x.x < y.x;
}

bool cmp(Cow x,Cow y) {
	return x.time < y.time;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> L;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].w >> a[i].x >> a[i].d;
		if(a[i].d == 1) a[i].time = L-a[i].w;
		else a[i].time = a[i].w;
	}
	sort(a+1,a+n+1,cmpx);
	for(int i = 1;i <= n;i++) {
		w[i] = a[i].x;
		rsum[i] = rsum[i-1]+(a[i].d == 1);
	}
	sort(a+1,a+n+1,cmp);
	
}