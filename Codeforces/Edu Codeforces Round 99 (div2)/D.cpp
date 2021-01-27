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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,x;
int a[505];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> n >> x;
        for(int i = 1;i <= n;i++) {
        	cin >> a[i];
        }
        vec g;
        for(int i = 1;i < n;i++) {
        	if(a[i] > a[i+1]) {
        		g.pb(i+1);
        	}
        }
        if(g.empty()) {
        	cout << "0\n";
        	continue;
        }
        int wi = g.back(),cnt = 0;
    	for(int i = 1;i < wi;i++) {
    		if(x < a[i]) swap(x,a[i]), cnt++;
    	}
    	int ch = 0;
    	for(int i = 1;i < n;i++) {
    		if(a[i] > a[i+1]) ch = 1;
    	}
    	if(ch) cout << "-1\n";
    	else cout << cnt << '\n';

    }
}
