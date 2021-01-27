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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll a[100005],sum[100005],B,L;

bool isok(int st) {
	for(int r = st;r <= n;r++) {
		int l = r-st+1;
		int mid = (l + r + 1) >> 1;
		if(a[mid]*(mid-l+1)-(sum[mid]-sum[l-1])+(sum[r]-sum[mid])-a[mid]*(r-mid) <= B) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> L >> B;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	int l = 1,r = n;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(isok(mid)) l = mid;
		else r = mid-1;
	}
	cout << l;
} 
