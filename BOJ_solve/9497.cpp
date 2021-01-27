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
int n,m;
int a[100],b[100];
set <int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int gcd = __gcd(n-1,m-1);
	if(gcd == n-1||gcd == m-1) cout << max(n,m);
	else {
		
	}
}

//    2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
// 2  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
// 3  3  3  6  5  9  7 12  9 15 11 18 13 21 15 24 17
// 4  4  6  4 10 12  7 16 18 10 22 24 13 28 30 16 34
// 5  5  5 10  5 15 12 20  9 25 19 30 13 35 26 40 17
// 6  6  9 12 15  6 21 24 27 30 11 36 39 42 45 16 51
// 7  7  7  7 12 21  7 28 22 18 27 42 13 49 37 29 42
// 8  8 12 16 20 24 28  8 36 40 44 48 52 56 15 64 68

// 짝수, 짝수 -> n*m/2
// 짝수, 홀수 -> n*m/2 or 이상한 숫자
// 홀수, 홀수 -> 이상한 숫자