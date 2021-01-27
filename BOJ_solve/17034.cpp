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
int n,top[100005];
int a[100005],la;
stack <int> st[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		if(a[i] < la) {
			cout << i-1;
			return 0;
		}
		for(int j = a[i];j >= 1;j--) {
			if(top[j]) break;
			top[j] = a[i];
		}
		int wi = top[a[i]];
		while(!st[wi].empty()&&st[wi].top() < a[i]) {
			la = st[wi].top();
			st[wi].pop();
		}
		st[wi].push(a[i]);
	}
	cout << n;
}
