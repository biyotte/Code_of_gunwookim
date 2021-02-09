#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,val;
int l,r,lv,rv,mv,mlv,mrv;

int ask(int idx) {
	cout << "? " << idx << endl;
	int tmp; cin >> tmp;
	return tmp;
}

void answer(int x) {
	cout << "! " << x << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	l = 1, r = n;
	while(l <= r) {
		if(l == r) answer(l);
		if(l+1 == r) {
			int v1 = ask(l), v2 = ask(r);
			if(v1 < v2) answer(l);
			else answer(r);
		}
		int mid = (l + r) >> 1;
		mv = ask(mid);
		mlv = ask(mid-1), mrv = ask(mid+1);
		if(mlv < mv) {
			r = mid;
		}
		else if(mrv < mv) {
			l = mid;
		}
		else answer(mid);
	}
}
