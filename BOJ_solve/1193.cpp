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
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,sum,i;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(sum = 0,i = 1;sum+i < n;sum += i,i++);
	if(i & 1) cout << i+1-n+sum << '/' << n-sum;
	else cout << n-sum << '/' << i+1-n+sum;
}