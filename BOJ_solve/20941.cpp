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
const long long llINF = 1e18+10;
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
int n;
char st[1200005][25];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> st[0]+1;
	for(int i = 2;i <= n+1;i++) {
		for(int j = 0;j < (1 << (n-1));j++) {
			if(j % (1 << i) < (1 << (i-2))||j % (1 << i) >= (1 << i)-(1 << (i-2))) {
				if(st[0][i-1] == '1') st[j][i-1] = '1';
				else st[j][i-1] = '0';
			}
			else {
				if(st[0][i-1] == '1') st[j][i-1] = '0';
				else st[j][i-1] = '1';
			}
		}
	}
	for(int i = 0;i < (1 << (n-1));i++) {
		cout << st[i]+1 << '\n';
		for(int j = 1;j <= n;j++) cout << (char)('1'-st[i][j]+'0');
		cout << '\n';
	}
}
