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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;

struct Line {
	int x,y1,y2;
}L[2005];

bool cmp(pair<int,pi> x,pair<int,pi> y) {
	ll xgrow = 1LL*x.y.x*y.y.y;
	ll ygrow = 1LL*x.y.y*y.y.x;
	if(xgrow^ygrow) return xgrow < ygrow;
	return x.x > y.x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> L[i].y1 >> L[i].y2 >> L[i].x;
		if(L[i].y1 > L[i].y2) swap(L[i].y1,L[i].y2);	
	}
	vector <pair<int,pi>> arr;
	int ans = 0;
	for(int st = 1;st <= n;st++) {
		arr.clear();
		int sum = 0;
		for(int i = 1;i <= n;i++) {
			if(L[st].x == L[i].x) {
				if(L[st].y1 >= L[i].y1&&L[st].y1 <= L[i].y2) sum += L[i].y2-L[i].y1;
			}
			else if(L[st].x > L[i].x) {
				arr.pb({L[i].y2-L[i].y1,{L[st].y1-L[i].y2,L[st].x-L[i].x}});
				arr.pb({L[i].y1-L[i].y2,{L[st].y1-L[i].y1,L[st].x-L[i].x}});
			}
			else {
				arr.pb({L[i].y2-L[i].y1,{L[i].y1-L[st].y1,L[i].x-L[st].x}});
				arr.pb({L[i].y1-L[i].y2,{L[i].y2-L[st].y1,L[i].x-L[st].x}});
			}
		}
		sort(all(arr),cmp);
		ans = max(ans,sum);
		for(auto i : arr) {
			sum += i.x;
			ans = max(ans,sum);
		}
	}
	cout << ans;
}