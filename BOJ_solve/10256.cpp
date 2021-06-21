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
int n,m,pv;
char in[1000005],in2[105];

struct Node {
	int ch[26];
	ll cnt;
	int fail;
}trie[2000005];

void Clear(int x) {
	for(int j : {0,2,6,19}) trie[x].ch[j] = 0;
	trie[x].cnt = 0, trie[x].fail = 0;
}

void Insert(int now,int nl) {
	if(nl == m+1) {
		trie[now].cnt = 1;
		return;
	}
	if(!trie[now].ch[in2[nl]-'A']) trie[now].ch[in2[nl]-'A'] = ++pv, Clear(pv);
	Insert(trie[now].ch[in2[nl]-'A'],nl+1);
}

void Make_fail() {
	queue <int> q;
	q.push(1);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i : {0,2,6,19}) {
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

ll Query() {
	ll ans = 0;
	for(int nl = 1,x = 1,nx;nl <= n;nl++) {
		nx = in[nl]-'A';
		while(x^1&&!trie[x].ch[nx]) x = trie[x].fail;
		if(trie[x].ch[nx]) x = trie[x].ch[nx];
		ans += trie[x].cnt;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		cin >> in+1 >> in2+1;
		pv = 1;
		Clear(1);
		trie[1].fail = 1;
		for(int i = 1;i <= m;i++) {
			for(int j = i;j <= m;j++) {
				reverse(in2+i,in2+j+1);
				Insert(1,1);
				reverse(in2+i,in2+j+1);
			}
		}
		Make_fail();
		cout << Query() << '\n';
	}
}