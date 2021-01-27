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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int k,n,x,co,len[25005];
char a[25005][21];
vector <char> ans;

struct Trie {
	char val;
	int cnt,dep,nx[26];
}trie[1000005];

void insert(int now,int x,int y) {
	trie[now].dep = max(trie[now].dep,len[x]-y+1);
	if(y == len[x]) {
		trie[now].cnt++;
		return;
	}
	if(!trie[now].nx[a[x][y+1]-'a']) {
		trie[now].nx[a[x][y+1]-'a'] = ++co;
		trie[co].val = a[x][y+1];
	}
	insert(trie[now].nx[a[x][y+1]-'a'],x,y+1);
}

void query(int now) {
	if(now^1) ans.pb(trie[now].val);
	if(trie[now].cnt) ans.pb('P');
	vecpi v;
	for(int i = 0;i < 26;i++) {
		if(trie[now].nx[i]) v.pb({trie[trie[now].nx[i]].dep,trie[now].nx[i]});
	}
	sort(all(v));
	for(pi i : v) {
		query(i.y);
		ans.pb('-');
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	trie[++co].val = '!';

	for(int i = 1;i <= n;i++) {
		cin >> a[i]+1; len[i] = strlen(a[i]+1);
		insert(1,i,0);
	}
	query(1);
	cout << ans.size()-trie[1].dep+1 << '\n';
	for(int i = 0;i <= ans.size()-trie[1].dep;i++) cout << ans[i] << '\n';
}
