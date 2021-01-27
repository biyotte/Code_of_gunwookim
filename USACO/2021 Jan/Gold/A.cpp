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
int n,c[26],ind[26];
char a[100005];
int cost[26][26],v[26][26];
int st[26][26];
vector <pair<pi,pi>> edge;

bool iscycle() {
	queue <int> q;
	for(int i = 0;i < 26;i++) {
		ind[i] = 0;
		for(int j = 0;j < 26;j++) {
			if(v[j][i]) ind[i]++;
		}
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0;i < 26;i++) {
			if(v[x][i]&&!--ind[i]) q.push(i);
		}
	}
	for(int i = 0;i < 26;i++) if(ind[i]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1; n = strlen(a+1);
	for(int i = 1;i < n;i++) {
		cost[a[i]-'a'][a[i+1]-'a']++;
		if(!st[a[i]-'a'][a[i+1]-'a']) st[a[i]-'a'][a[i+1]-'a'] = i;
	}
	for(int i = 0;i < 26;i++) {
		for(int j = 0;j < 26;j++) {
			edge.pb({{-cost[i][j],-st[i][j]},{i,j}});
		}
	}
	sort(all(edge));
	int ans = n;
	for(auto now : edge) {
		int co = -now.x.x, x = now.y.x, y = now.y.y;
		v[x][y] = 1;
		if(iscycle()) ans -= co;
		else v[x][y] = 0;
	}
	if(ans <= 0) while(1);
	cout << ans;
}


