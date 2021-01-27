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
const long long llINF = 1e17;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
ll A,B;
int a[20],b[20],st,S;
ll d[20][140][4],mn[20][140][4],ans,ans2 = llINF;

ll go(int x,int s,int bt) {
	if(x == 0) {
		if(s != S) mn[x][s][bt] = llINF;
		return (s == S);
	}
	if(d[x][s][bt] != -1) return d[x][s][bt];
	ll &ret = d[x][s][bt]; ret = 0;
	ll m = llINF;
	if(!bt) for(int i = 0;i <= 9;i++) ret += go(x-1,s+i,bt), m = min(m,mn[x-1][s+i][bt]+(ll)pow(10,x-1)*i);
	else if(bt == 3) for(int i = a[x];i <= b[x];i++) ret += go(x-1,s+i,(i == a[x])*2+(i == b[x])), m = min(m,mn[x-1][s+i][(i == a[x])*2+(i == b[x])]+(ll)pow(10,x-1)*i);
	else if(bt == 2) for(int i = a[x];i <= 9;i++) ret += go(x-1,s+i,(i == a[x])*2), m = min(m,mn[x-1][s+i][(i == a[x])*2]+(ll)pow(10,x-1)*i);
	else for(int i = 0;i <= b[x];i++) ret += go(x-1,s+i,(i == b[x])), m = min(m,mn[x-1][s+i][(i == b[x])]+(ll)pow(10,x-1)*i);
	mn[x][s][bt] = m;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> A >> B >> S;
	memset(d,-1,sizeof(d));
	for(int i = 1;i <= 15;i++) a[i] = A%10, A /= 10;
	for(int i = 1;i <= 15;i++) {
		b[i] = B%10, B /= 10;
		if(b[i]) st = i;
	}
	for(int i = a[st];i <= b[st];i++) ans += go(st-1,i,(i == a[st])*2+(i == b[st])), ans2 = min(ans2,mn[st-1][i][(i == a[st])*2+(i == b[st])]+(ll)pow(10,st-1)*i);
	cout << ans << '\n' << ans2;
}