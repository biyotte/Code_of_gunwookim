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
const long long llINF = 2e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,pv[100005],c[1000005];
int wait[100005];
stack <int> st;
vecpi v[100005];
vec path;
vector <vec> ans;

void dfs(int x) {
	for(;pv[x] < v[x].size();pv[x]++) {
		if(c[v[x][pv[x]].y]) continue;
		c[v[x][pv[x]].y] = 1;
		dfs(v[x][pv[x]].x);
		path.pb(x);
	}
}

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if(ch == '-') break;
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') minus = true;
	else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0'||ch > '9') break;
		result = result*10+(ch-'0');
	}
	if(minus) return -result;
	else return result;
}

int main() {
	n = readInt(), m = readInt();
	for(int i = 1;i <= m;i++) {
		int x,y,val1,val2;
		x = readInt(), y = readInt();
		val1 = readInt(), val2 = readInt();
		if(val1^val2) {
			v[x].pb({y,i});
			v[y].pb({x,i});
		}
	}
	for(int i = 1;i <= n;i++) {
		if((int)v[i].size() & 1) {
			cout << "NIE";
			return 0;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(v[i].empty()) continue;
		path.clear();
		dfs(i);
		reverse(all(path));
		path.pb(i);
		for(int i : path) {
			if(!wait[i]) st.push(i);
			else {
				vec v2;
				v2.pb(i);
				while(!st.empty()) {
					if(st.top() == i) break;
					wait[st.top()] = 0;
					v2.pb(st.top()), st.pop();
				}
				v2.pb(i);
				ans.pb(v2);
			}
			wait[i] = 1;
		}
	}
	printf("%d\n",ans.size());
	for(vec i : ans) {
		printf("%d ",i.size()-1);
		for(int j : i) printf("%d ",j);
		printf("\n");
	}
}