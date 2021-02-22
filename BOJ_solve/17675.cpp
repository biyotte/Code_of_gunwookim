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
const long long mod = 998244353;
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
int n,d[1000005][4][2]; // d[i][j][k] : 어떤 st부터 i번 문자까지 k(0 : B와같이, 1 : B역순으로)상태로 만들었고 그 전에 사용한 연산이 j(0 : 아무것도 안함, 1 : 0로 만들기, 2 : 1로 만들기)일때 최소 횟수 
char a[1000005],b[1000005];

int go(int x,int op,int fl) {
	if(x == n+1) return 0;
	if(d[x][op][fl] != -1) return d[x][op][fl];
	int &ret = d[x][op][fl]; ret = INF;
	int na = a[x]-'0', nb = b[x]-'0';
	for(int i = 0;i < 3;i++) {
		for(int j = 0;j < 2;j++) {
			int us = 0,nx = na;
			if(i == 1) nx = 0;
			if(i == 2) nx = 1;
			if(j) nx ^= 1;
			if(op != i&&i) us++;
			if(fl != j&&j) us++;
			if(nx == nb) ret = min(ret,go(x+1,i,j)+us);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1 >> b+1;
	memset(d,-1,sizeof(d));
	cout << go(1,3,0);
}