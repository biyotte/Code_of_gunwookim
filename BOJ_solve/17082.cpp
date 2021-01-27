#include <bits/stdc++.h>
using namespace std;
int n,m,Q,a[200005];
int x,y,sum[200005];
multiset <int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m >> Q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> x, sum[x]++;
	for(int i = 1;i <= m;i++) cin >> x, sum[x+1]--;
	for(int i = 1;i <= n;i++) {
		sum[i] += sum[i-1];
		if(sum[i] < 0) {
			while(Q--) {cout << (int)1e9 << '\n';}
			return 0;
		}
		if(sum[i]) s.insert(a[i]);
	}
	while(Q--) {
		cin >> x >> y;
		if(sum[x]) s.erase(s.find(a[x])), s.insert(a[y]);
		if(sum[y]) s.erase(s.find(a[y])), s.insert(a[x]);
		swap(a[x],a[y]), cout << *prev(s.end()) << '\n';
	}
}