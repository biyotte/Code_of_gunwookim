#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int n,m,k,co,root,d[100005],sz[100005],c[100005],inbcc[100005],it[100005];
vector <int> tv[100005],v[100005],bridge[100005];
vector <pi> nobridge;
vector <vector <pi>> bcc;
stack <pi> S;
set <int> leaf[100005];

int get_sz(int x) {
	c[x] = 1;
	for(int i : v[x]) {
		if(c[i]) continue;
		sz[x] += get_sz(i);
	}
	return sz[x] += (v[x].size() == 1);
}
int rd[100005];

int dfs(int x,int p = -1) {
	//cout << x << ' ' << p << '\n';
	if(d[x]) return d[x];
	int ans = d[x] = ++co,ch = 0;
	rd[x] = co;
	for(int i : tv[x]) {
		if(i == p) {
			if(!ch) ch = 1;
			else if(ch != -1) {
				int tmp = dfs(i,x);
				if(ans >= tmp) bridge[x].push_back(i);
				else nobridge.push_back({x,i});
				d[x] = min(d[x],tmp);
				ch = -1;
			}
			continue;
		}
		int tmp = dfs(i,x);
		if(ans >= tmp) bridge[x].push_back(i);
		else nobridge.push_back({x,i});
		d[x] = min(d[x],tmp);
	}
	return d[x];
}

void dfs2(int x) {
	inbcc[x] = co;
	for(int i : bridge[x]) {
		if(inbcc[i]) continue;
		dfs2(i);
	}
}

void dfs3(int x) {
	c[x] = 1;
	if(v[x].size() == 1) leaf[co].insert(x);
	for(int i : v[x]) {
		if(c[i]) continue;
		dfs3(i);
	}
}

int get_root(int x) {
	c[x] = 1;
	for(int i : v[x]) {
		if(c[i]) continue;
		if(sz[i] > sz[1]/2) return get_root(i);
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y;
		cin >> x >> y;
		tv[x].push_back(y);
		tv[y].push_back(x);
	}
	dfs(1); co = 0;
	for(int i = 1;i <= n;i++) {
		if(!inbcc[i]) {
			co++;
			dfs2(i);
		}
		it[inbcc[i]] = i;
	}
	k = co;
	for(pi i : nobridge) {
		v[inbcc[i.first]].push_back(inbcc[i.second]);
		v[inbcc[i.second]].push_back(inbcc[i.first]);
	}
	get_sz(1); co = 0;
	memset(c,0,sizeof(c)); root = get_root(1);
	#if 1
	for(int i = 1;i <= k;i++) {
		//cout << i << "," << it[i] << " : ";
		//sort(v[i].begin(),v[i].end()); v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		//for(int j : v[i]) {
		//	cout << j << ' ';
		//}
		//cout << '\n';
	}
	#endif
	#if 1
	int rcnt = 0,Cnt = 0;
	for(int i = 1;i <= k;i++) {
		rcnt += (v[i].size() == 1); 
	}
	//cout << (rcnt+1)/2 << '\n';
	#endif
	#if 1
	memset(c,0,sizeof(c)); co = 0;
	c[root] = 1;
	for(int i : v[root]) {
		++co; dfs3(i);
	}
	priority_queue <pair<int,int>> q;
	for(int i = 1;i <= co;i++) {
		q.push({(int)leaf[i].size(),i});
	}
	#if 0
	for(int i = 1;i <= co;i++) {
		for(auto j : leaf[i]) {
			cout << j << ' ';
		}
		cout << '\n';
 	}
	#endif
	vector <pi> Ans;
	while(q.size() >= 2) {
		pi x = q.top(); q.pop();
		pi y = q.top(); q.pop();
		//cout << "{" << x.first << ',' << x.second << "},{" << y.first << "," << y.second << "}\n"; 
		for(int i = 1;i <= y.first;i++) {
			Ans.push_back({it[*leaf[x.second].begin()],it[*leaf[y.second].begin()]});
			leaf[x.second].erase(leaf[x.second].begin());
			leaf[y.second].erase(leaf[y.second].begin());
		}
		if(leaf[x.second].size() != 0) q.push({leaf[x.second].size(),x.second});
	}
	if(!q.empty()) {
		//cout << q.top().first << ' ' << q.top().second << '\n';
		pi x = q.top();
		for(int i = 1;i <= x.first;i++) {
			Ans.push_back({it[*leaf[x.second].begin()],it[root]});
			leaf[x.second].erase(leaf[x.second].begin()); Cnt++;
		}
	}
	#endif
	cout << Ans.size() << '\n';
	for(pi i : Ans) cout << i.first << ' ' << i.second << '\n';
 	return 0;
}