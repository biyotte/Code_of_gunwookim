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
int n,nn,a[1 << 20],x,y;

int result;
char ch;

int readInt () {
	result = 0;
	ch = getchar();
	while (true) {
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0'||ch > '9') break;
		result = result*10+(ch-'0');
	}
	return result;
}

int main() {
	n = readInt();
	nn = 1 << n;
	for(int i = 0;i < nn;i++) a[i] = readInt();
	srand(time(NULL));
	if(n == 0) {
		cout << "-1";
		return 0;
	}
	for(int i = 1;i <= 110000000;i++) {
		x = rand()%(nn-1), y = rand()%(nn-x-1)+x+1;
		if(a[x]+a[y] < a[x|y]+a[x&y]) {
			cout << x << ' ' << y << '\n';
			return 0;
		}
	}
	cout << "-1";
}