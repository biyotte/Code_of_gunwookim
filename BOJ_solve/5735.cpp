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
int n,m,pv,len,Q;
string in;

struct Node {
	int ch[300];
	int cnt;
	int fail;
}trie[100005];

void Clear(int x) {
	for(int j = 0;j < 300;j++) trie[x].ch[j] = 0;
	trie[x].cnt = 0, trie[x].fail = 0;
}

void Insert(int now,int nl) {
	if(nl == len) {
		trie[now].cnt = 1;
		return;
	}
	if(!trie[now].ch[in[nl]]) trie[now].ch[in[nl]] = ++pv, Clear(pv);
	Insert(trie[now].ch[in[nl]],nl+1);
}

void Make_fail() {
	queue <int> q;
	q.push(1);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0;i < 300;i++) {
			int y = trie[x].ch[i];
			if(y) {
				int w = trie[x].fail;
				while(w^1&&!trie[w].ch[i]) w = trie[w].fail;
				if(trie[w].ch[i]&&trie[w].ch[i]^y) trie[y].fail = trie[w].ch[i];
				else trie[y].fail = 1;
				trie[y].cnt |= trie[trie[y].fail].cnt;
				q.push(y);
			}
		}
	}
}

int Query() {
	int ret = 0;
	for(int nl = 0,x = 1,nx;nl < len;nl++) {
		nx = in[nl];
		while(x^1&&!trie[x].ch[nx]) x = trie[x].fail;
		if(trie[x].ch[nx]) x = trie[x].ch[nx];
		if(trie[x].cnt) {
			ret++;
			x = 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(1) {
		cin >> n >> Q;
		if(!n) break;
		pv = 1;
		Clear(1);
		trie[1].fail = 1;
		for(int i = 1;i <= n;i++) {
			cin >> in;
			len = in.length();
			Insert(1,0); // trie에 문자열 삽입
		}
		Make_fail(); // fail 구성
		int ans = 0;
		char gar;
		getline(cin,in);
		while(Q--) {
			getline(cin,in);
			len = in.length();
			ans += Query();
		}
		cout << ans << '\n';
	}
}