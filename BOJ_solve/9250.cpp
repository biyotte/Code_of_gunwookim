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
int n,pv = 1,len;
char in[10005];

struct Node {
	int ch[26];
	int cnt;
	int fail;
}trie[1000005];

void Insert(int now,int nl) {
	if(nl == len+1) {
		trie[now].cnt++;
		return;
	}
	if(!trie[now].ch[in[nl]-'a']) trie[now].ch[in[nl]-'a'] = ++pv;
	Insert(trie[now].ch[in[nl]-'a'],nl+1);
}

void Make_fail() {
	queue <int> q;
	q.push(1);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0;i < 26;i++) {
			int y = trie[x].ch[i];
			if(y) {
				int w = trie[x].fail;
				while(w^1&&!trie[w].ch[i]) w = trie[w].fail;
				if(trie[w].ch[i]&&trie[w].ch[i]^y) trie[y].fail = trie[w].ch[i];
				else trie[y].fail = 1;
				if(trie[trie[y].fail].cnt) trie[y].cnt = 1;
				q.push(y);
			}
		}
	}
}

bool Query() {
	for(int nl = 1,x = 1,nx;nl <= len;nl++) {
		nx = in[nl]-'a';
		while(x^1&&!trie[x].ch[nx]) x = trie[x].fail;
		if(trie[x].ch[nx]) x = trie[x].ch[nx];
		if(trie[x].cnt) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	trie[1].fail = 1;
	for(int i = 1;i <= n;i++) {
		cin >> in+1;
		len = strlen(in+1);
		Insert(1,1); // trie에 문자열 삽입
	}
	Make_fail(); // fail 구성
	int Q; cin >> Q;
	while(Q--) {
		cin >> in+1;
		len = strlen(in+1);
		cout << (Query() ? "YES\n" : "NO\n");
	}
}