#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
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
int n;
int a[100005];
vec rev;

// not solved

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		rev.pb(a[i]);
	}
	sort(all(rev));
	for(int i = 1;i <= n;i++) {
		a[i] = lower_bound(all(rev),a[i])-rev.begin()+1;
	}
	queue <int> q;
	for(int i = 1;i <= n;i++) {
		while(!q.empty()&&q.front())
	}
}
