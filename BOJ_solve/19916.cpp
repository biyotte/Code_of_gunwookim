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
int n,m,a[2505][2505];
int L[2505][2505],R[2505][2505],U[2505][2505],D[2505][2505];
stack <pi> s;

void make_LRUD() {
	for(int i = 1;i <= n;i++) {
		s.push({INF,-1});
		for(int j = 1;j <= m;j++) {
			while(s.top().x < a[i][j]) s.pop();
			L[i][j] = s.top().y;
			s.push({a[i][j],j});
		}
		while(!s.empty()) s.pop();
	}
	for(int i = 1;i <= n;i++) {
		s.push({INF,-1});
		for(int j = m;j >= 1;j--) {
			while(s.top().x < a[i][j]) s.pop();
			R[i][j] = s.top().y;
			s.push({a[i][j],j});
		}
		while(!s.empty()) s.pop();
	}
	for(int i = 1;i <= m;i++) {
		s.push({INF,-1});
		for(int j = 1;j <= n;j++) {
			while(s.top().x < a[j][i]) s.pop();
			U[j][i] = s.top().y;
			s.push({a[j][i],j});
		}
		while(!s.empty()) s.pop();
	}
	for(int i = 1;i <= m;i++) {
		s.push({INF,-1});
		for(int j = n;j >= 1;j--) {
			while(s.top().x < a[j][i]) s.pop();
			D[j][i] = s.top().y;
			s.push({a[j][i],j});
		}
		while(!s.empty()) s.pop();
	}
	cout << '\n';
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cout << L[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cout << R[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cout << U[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cout << D[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin >> a[i][j];
	}
	make_LRUD();
}