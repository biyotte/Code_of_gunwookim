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
int n,w[200005];
int a[200005],c[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    vec ans;
    for(int i = 1;i <= n;i++) cin >> a[i], w[a[i]] = i;
    for(int i = 1;i <= n;i++) {
    	for(int j = w[i]-1;j >= i;j--) {
    		if(c[j]) {
    			cout << "-1";
    			return 0;
    		}
    		c[j] = 1;
    		w[a[j]]++;
    		swap(a[j],a[j+1]);
    		ans.pb(j);
    	}
    }
    memset(c,0,sizeof(c));
    if((int)ans.size() != n-1) {
    	cout << "-1";
    	return 0;
    }
    for(int i : ans) {
    	cout << i << '\n';
    }
}
