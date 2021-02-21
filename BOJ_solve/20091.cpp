#include "mountains.h"
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
int d[2005][2005];
int n,a[2005];

int maximum_deevs(std::vector<int> y) {
	n = y.size();
	for(int i = 1;i <= n;i++) a[i] = y[i-1];
	for(int i = 1;i <= n;i++) {
		d[i][i] = d[i-1][i] = 1;
		int lx = i-1,sum = 1;
		for(int j = i-2;j >= 1;j--) {
			if(1LL*(a[i]-a[lx])*(i-j) >= 1LL*(a[i]-a[j])*(i-lx)) {
				sum += d[j+1][lx-1];
				lx = j;
			}
			d[j][i] = max(d[j][i-1],d[j][lx-1]+sum);
		}
	}
	return d[1][n];
}
