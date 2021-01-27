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
char a[200005];
int n,st;
char b[3] = {'1','1','0'};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> a+1;
    ll m = 1LL*INF*10;
    if(n == 1) {
    	if(a[1] == '0') cout << m;
    	else cout << m*2;
    	return 0;
    }
    int st;
    if(a[1] == '0') st = 2;
    else if(a[1] == '1'&&a[2] == '0') st = 1;
    else st = 0;
    for(int i = 1;i <= n;i++) {
    	if(a[i] != b[st%3]) {
    		cout << 0;
    		return 0;
    	}
    	st++;
    }
    st--;
    cout << m-st/3;
}
