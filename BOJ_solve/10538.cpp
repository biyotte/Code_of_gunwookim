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
int n,k,pv = 1,len,Q;
int d[1005][305];
char in[20];
vec order;

struct Node {
	int ch[3];
	int cnt;
	int fail;
}trie[100005];

void Insert(int now,int nl) {
	if(nl == len+1) {
		trie[now].cnt++;
		return;
	}
	if(!trie[now].ch[in[nl]-'A']) trie[now].ch[in[nl]-'A'] = ++pv; 
	Insert(trie[now].ch[in[nl]-'A'],nl+1);
}

void Make_fail() {
	queue <int> q;
	q.push(1);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		order.pb(x);
		for(int i = 0;i < 3;i++) {
			int y = trie[x].ch[i];
			if(y) {
				int w = trie[x].fail;
				while(w^1&&!trie[w].ch[i]) w = trie[w].fail;
				if(trie[w].ch[i]&&trie[w].ch[i]^y) trie[y].fail = trie[w].ch[i];
				else trie[y].fail = 1;
				trie[y].cnt += trie[trie[y].fail].cnt;
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	trie[1].fail = 1;
	for(int i = 1;i <= n;i++) {
		cin >> in+1;
		len = strlen(in+1);
		Insert(1,1);
	}
	Make_fail();
	reverse(all(order));
	for(int i = 0;i <= k;i++) for(int j = 1;j <= pv;j++) d[i][j] = -INF;
	d[0][1] = 0;
	for(int i = 0;i <= k;i++) {
		for(int pp = 0;pp < pv;pp++) {
			int j = order[pp];
			int fail = trie[j].fail;
			d[i][fail] = max(d[i][fail],d[i][j]);
			for(int l = 0;l < 3;l++) {
				d[i+1][trie[j].ch[l]] = max(d[i+1][trie[j].ch[l]],d[i][j]+trie[trie[j].ch[l]].cnt);
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= pv;i++) ans = max(ans,d[k][i]);
	cout << ans;
}