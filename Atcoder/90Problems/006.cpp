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
const long long llINF = 1e18+10;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,la;
char a[100005];
priority_queue <pair<char,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> a+1;
	for(int i = 1;i <= n-k;i++) q.push({'z'-a[i]+'a',-i});
	for(int i = n-k+1;i <= n;i++) {
		q.push({'z'-a[i]+'a',-i});
		while(-q.top().y < la) q.pop();
		cout << (char)('z'-q.top().x+'a');
		la = -q.top().y; q.pop();
	}
}
