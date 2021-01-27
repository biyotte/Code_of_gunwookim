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
const long long llINF = 1e18;
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int sum[1000005];
int n;
vec v[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		char ch;
		int x;
		cin >> ch >> x;
		if(ch == 's') v[x].pb(i);
		else v[x].pb(-i);
	}
	for(int i = 1;i <= 1000000;i++) {
		int cnt = 0,mn = 0;
		for(int j = 0;j < v[i].size();j++) {
			cnt += (v[i][j] < 0 ? -1 : 1);
			mn = min(mn,cnt); 
		}
		if(cnt) continue;
		for(int j = 0;j < v[i].size();j++) {
			cnt += (v[i][j] < 0 ? -1 : 1);
			if(mn^cnt) continue;
			sum[-v[i][j]]++;
			if(j == v[i].size()-1) sum[0]++, sum[v[i][0]]--;
			else sum[v[i][j+1]]--;
		}
	}
	int cnt = 0,ans = 0,wi = 1;
	for(int i = 0;i <= n;i++) {
		if(cnt > ans) ans = cnt, wi = i;
		cnt += sum[i];
	}
	cout << wi << ' ' << ans;
}
