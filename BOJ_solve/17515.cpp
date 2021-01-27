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
int n,x;
queue <int> pos,pos2;
ll ans,ans2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> x;
        if(x*2 <= n) pos.push(i);
        if(x*2 > n+n%2) pos2.push(i);
    }
    for(int i = 1;i <= n;i++) {
    	cin >> x;
    	if(x*2 > n+n%2) {
    		ans += abs(pos.front()-i);
    		pos.pop();
    	}
    	if(x*2 <= n) {
    		ans2 += abs(pos2.front()-i);
    		pos2.pop();
    	}
    }
    cout << min(ans,ans2);
}