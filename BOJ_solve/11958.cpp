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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
bool area_c[5000005];
int Q,c[100005];
int ans[155][155],sum[500];
int K,L,M,n,over;
vec p;

void area() {
	for(int i = 2;i <= 5000000;i++) {
		if(area_c[i]) continue;
		if(i > 150) p.pb(i);
		if(i >= 3000) continue;
		for(int j = i*i;j <= 5000000;j += i) area_c[j] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> Q;
	area();
	n = p.size();
	for(int i = 0;i < n;i++) {
		if(i&&!over&&p[i]-p[i-1]-1 >= 150) over = p[i-1]+1;
		for(int j = i;j < n-1&&p[j]-p[i] < 150;j++) {
			for(int k = p[j];k < p[j+1]&&k-p[i] < 150;k++) {
				ans[k-p[i]+1][j-i+1] = p[i];
			}
		}
	}
	for(int i = 2;i <= 500;i++) {
		sum[i] = sum[i-1]+(1-area_c[i]);
	}
	while(Q--) {
		cin >> K >> L >> M;
		int ch = -1;
		for(int i = 1;i <= M;i++) {
			if(max(0,sum[i+K-1]-sum[M])+min(K,M-i+1) == L) {
				ch = i;
				break;
			}
		}
		for(int i = M+1;i <= 350;i++) {
			if(sum[i+K-1]-sum[i-1] == L) {
				if(ch == -1) ch = i;
				break;
			}
		}
		if(ch != -1) cout << ch << '\n';
		else if(!L) cout << over << '\n';
		else cout << (ans[K][L] ? ans[K][L] : -1) << '\n';
	}
}