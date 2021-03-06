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
int n,t3;
int h,m;
double st;
char g;

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d", &n);
	scanf("%d:%d UTC%lf",&h,&m,&st);
	scanf("%c",&g);
	t3 = st*2-(int)st*2;
	while(n--) {
		double now;
		int nt3;
		scanf("UTC%lf",&now);
		scanf("%c",&g);
		nt3 = now*2-(int)now*2;
		int nh = h+(now-st), nm = m+(t3-nt3)*30;
		if(nm < 0) nh--, nm += 60;
		if(nm > 60) nh++, nm -= 60;
		nh = (nh+24)%24;
		printf("%02d:%02d\n",nh,nm);
	}
}