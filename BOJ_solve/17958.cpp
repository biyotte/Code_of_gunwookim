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
int n,cnt[27],mx,num;
char a[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1; n = strlen(a+1)/2;
	for(int i = 1;i <= 2*n;i++) {
		cnt[a[i]-'a']++;
	}
	for(int i = 0;i < 26;i++) {
		if(cnt[mx] < cnt[i]) mx = i;
		if(cnt[i]) num++;
	}
	if((n == 1&&cnt[mx] == 2*n)||(n != 1&&(cnt[mx] >= 2*n-1||(cnt[mx] == 2*n-2&&num == 2&&n != 2)))) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0;cnt[mx]&&i < n;i++) {
		cout << (char)('a'+mx);
		cnt[mx]--;
	}
	for(int i = 0;i < 26;i++) {
		if(mx == i||!cnt[i]) continue;
		cout << (char)('a'+i);
		cnt[i]--;
		while(cnt[mx] > 0) cnt[mx]--, cout << (char)('a'+mx);
		while(cnt[i] > 0) cnt[i]--, cout << (char)('a'+i);
	}
} 
