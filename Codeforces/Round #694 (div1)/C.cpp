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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int st = 1,val;
	cout << "? 1" << endl;
	cin >> val;
	for(int i = 2;i <= 500;i++) {
		cout << "? " << st << endl;
		cin >> val;
		if(val != k) {
			if(val < k) {
				for(int j = st+1;j <= st+i+3;j++) {
					int wi = (j-1)%n+1;
					cout << "? " << wi << endl;
					cin >> val;
					if(val == k) {
						cout << "! " << wi << endl;
						return 0;
					}
				}
			}
			else {
				for(int j = st-1;j <= st-i-3;j--) {
					int wi = (j-1+1000*n)%n+1;
					cout << "? " << wi << endl;
					cin >> val;
					if(val == k) {
						cout << "! " << wi << endl;
						return 0;
					}
				}
			}
		}
		st = (st+(i-1)-1)%n+1;
	}
	return -1;
}