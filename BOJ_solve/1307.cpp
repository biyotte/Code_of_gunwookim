#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int N,co;
int m3[305][305];
int m4[305][305];
int m6[305][305];

void make3(int n) {
	int x = n, y = n/2+1;
	m3[x][y] = ++co;
	for(int go = 2;go <= n*n;go++) {
		if(x == n&&y == n) {
			m3[x-1][y] = ++co;
			x--;
		}
		else if(x == n) m3[x = 1][++y] = ++co;
		else if(y == n) m3[++x][y = 1] = ++co;
		else if(m3[x+1][y+1]) m3[--x][y] = ++co;
		else m3[++x][++y] = ++co;
	}
}

void make4(int n) {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) m4[i][j] = (i-1)*n+j;
	}
	for(int i = 1;i <= n/2;i++) {
		for(int j = 1;j <= n;j++) {
			if(i <= n/4&&(j <= n/4||j >= n/4*3+1)) continue;
			if(i > n/4&&n/4 < j&&j <= n/4*3) continue;
			swap(m4[i][j],m4[n-i+1][n-j+1]);
		}
	}
}

void make6(int n) {
	make3(n/2);
	for(int i = 1;i <= n/2;i++) {
		for(int j = 1;j <= n/4;j++) {
			m6[i][j] = 3*n*n/4;
		}
	}
	m6[n/4+1][1] = 0, m6[n/4+1][n/4+1] = 3*n*n/4;
	for(int i = n/2+1;i <= n;i++) {
		for(int j = n/4+1;j <= n/2;j++) {
			m6[i][j] = 3*n*n/4;
		}
	}
	m6[n/2+n/4+1][n/4+1] = 0, m6[n/2+n/4+1][1] = 3*n*n/4;
	for(int i = 1;i <= n/2;i++) {
		for(int j = n/2+1;j <= n/2+n/4+2;j++) {
			m6[i][j] = 2*n*n/4;
			m6[i+n/2][j] = n*n/4;
		}
		for(int j = n/2+n/4+3;j <= n;j++) {
			m6[i][j] = n*n/4;
			m6[i+n/2][j] = 2*n*n/4;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			m6[i][j] += m3[(i-1)%(n/2)+1][(j-1)%(n/2)+1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	if(N % 2) {
		make3(N);
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= N;j++) cout << m3[i][j] << ' ';
			cout << '\n';
		}
	}
	else {
		if(N % 4) {
			make6(N);
			for(int i = 1;i <= N;i++) {
				for(int j = 1;j <= N;j++) cout << m6[i][j] << ' ';
				cout << '\n';
			}
		}
		else {
			make4(N);
			for(int i = 1;i <= N;i++) {
				for(int j = 1;j <= N;j++) cout << m4[i][j] << ' ';
				cout << '\n';
			}
		}
	}
}
