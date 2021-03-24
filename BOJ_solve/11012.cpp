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
const int MAXN = 1000000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
pi a[100005];

struct Node {
	Node *l, *r;
	int val;
	Node() {l = r = NULL; val = 0;}
};
Node *root[100005];

void build(Node *now,int l,int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	now->l = new Node(), now->r = new Node();
	build(now->l,l,mid), build(now->r,mid+1,r);
}

void update(Node *now,Node *pr,int l,int r,int wi) {
	if(l == r) {
		now->val++;
		return;
	}
	int mid = (l + r) >> 1;
	if(wi <= mid) {
		now->l = new Node(); now->r = pr->r;
		update(now->l,pr->l,l,mid,wi);
	}
	else {
		now->r = new Node(); now->l = pr->l;
		update(now->r,pr->r,mid+1,r,wi);
	}
	now->val = now->l->val+now->r->val;
}

int query(Node *L,Node *R,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return R->val-L->val;
	int mid = (l + r) >> 1;
	return query(L->l,R->l,l,mid,rl,rr)+query(L->r,R->r,mid+1,r,rl,rr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	build(root[0] = new Node(),0,MAXN);
	while(T--) {
		cin >> n >> Q;
		for(int i = 1;i <= n;i++) {
			int x,y; cin >> x >> y;
			a[i] = {y,x};
		}
		sort(a+1,a+n+1);
		for(int i = 1;i <= n;i++) {
			update(root[i] = new Node(),root[i-1],0,MAXN,a[i].y);
		}
		int ans = 0;
		while(Q--) {
			int x1,y1,x2,y2;
			cin >> x1 >> x2 >> y1 >> y2;
			int L = lower_bound(a+1,a+n+1,make_pair(y1-1,INF))-a-1;
			int R = lower_bound(a+1,a+n+1,make_pair(y2+1,0))-a-1;
			if(L >= R) continue;
			ans += query(root[L],root[R],0,MAXN,x1,x2);
		}
		cout << ans << '\n';
	}
}