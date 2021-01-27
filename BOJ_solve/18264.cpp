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
int n,m,k;
char a[100005];
int d[100005][30];
int sum[100005][30];
int dist[30][30];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	cin >> a+1;
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= m;j++) cin >> dist[i][j];
	}
	for(int l = 1;l <= m;l++) {
		for(int i = 1;i <= m;i++) {
			for(int j = 1;j <= m;j++) {
				dist[i][j] = min(dist[i][j],dist[i][l]+dist[l][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			d[i][j] = d[i-1][j] = INF;
			sum[i][j] = sum[i-1][j]+dist[a[i]-'a'+1][j];
		}
	}
	for(int i = 1;i <= n;i++) {
		int mn = INF;
		if(i >= k) for(int j = 1;j <= m;j++) mn = min(mn,d[i-k][j]);
		if(i == k) mn = 0;
		for(int j = 1;j <= m;j++) {
			d[i][j] = min(d[i][j],d[i-1][j]+sum[i][j]-sum[i-1][j]);
			if(i >= k) d[i][j] = min(d[i][j],mn+sum[i][j]-sum[i-k][j]);
		}
	}
	int mn = INF;
	for(int i = 1;i <= m;i++) mn = min(mn,d[n][i]);
	cout << mn;
}
