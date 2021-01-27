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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int ans[100005];
int p[100005],sz[100005];
int n,Q;

struct Edge {int x,y,z;};
struct Query {int k,v,idx;}q[100005];
vector <Edge> edge;

bool cmp(Edge x,Edge y) {return x.z < y.z;}
bool cmp2(Query x,Query y) {return x.k > y.k;}

int Find(int x) {return (x ^ p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x, sz[x] += sz[y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z;
		edge.pb({x,y,z});
	}
	sort(all(edge),cmp);
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].k >> q[i].v;
		q[i].idx = i;
	}
	sort(q+1,q+Q+1,cmp2);
	int go = n-2;
	for(int i = 1;i <= Q;i++) {
		while(go >= 0&&edge[go].z >= q[i].k) {
			merge(edge[go].x,edge[go].y);
			go--;
		}
		ans[q[i].idx] = sz[Find(q[i].v)]-1;
	}
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}
