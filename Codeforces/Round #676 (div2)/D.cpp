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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
ll x,y;
ll ac[6],c[7];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> x >> y;
		swap(x,y);
		for(int i = 0;i < 6;i++) cin >> ac[i];
		for(int roof = 0;roof <= 100;roof++) {
			for(int i = 0;i < 6;i++) {
				int l = (i+5)%6,r = (i+1)%6;
				ac[i] = min(ac[i],ac[l]+ac[r]);
			}
		}
		for(int i = 0;i < 6;i++) c[i+1] = ac[i];
		//for(int i = 0;i < 6;i++) cout << c[i] << ' ';
		if(x == 0&&y == 0) {
			cout << "0\n";
			continue;
		}
		if(x == 0) {
			if(y < 0) cout << c[3]*abs(y);
			else cout << c[6]*y;
		}
		else if(y == 0) {
			if(x < 0) cout << c[5]*abs(x);
			else cout << c[2]*x;
		}
		else {
			if(x < 0&&y < 0) {
				x *= -1, y *= -1;
				ll mn = min(x,y);
				cout << c[4]*mn+(x-mn)*c[5]+(y-mn)*c[3];
			}
			else if(x < 0&&y > 0) {
				x *= -1;
				cout << x*c[5]+y*c[6];
			}
			else if(x > 0&&y < 0) {
				y *= -1;
				cout << x*c[2]+y*c[3];
			}
			else {
				ll mn = min(x,y);
				cout << c[1]*mn+(x-mn)*c[2]+(y-mn)*c[6];
			}
		}
		cout << '\n';
	}
}