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
int n,m,pv = 1,len,Q;
int d[1005][305];
char in[5005],a[300005];
vec order;

// not solved

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

int Query() {
	for(int i = 1;i <= n;i++) {
		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1;
		for(int i = 1;i <= m;i++) {
		cin >> in+1;
		len = strlen(in+1);
		Insert(1,1);
	}
	cout << Query() << '\n';
}