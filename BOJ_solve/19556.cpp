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
const long long llINF = 1e16;
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
int n,x,l,r,val;

// not solved (22 scores)

int ask(int what) {
	cout << "? " << what << endl;
	int tmp; cin >> tmp;
	return tmp;
}

void answer(int what) {
	cout << "= " << what << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if(n == 1) answer(1);
	if(n == 2) {
		ask(1);
		val = ask(2);
		answer(1+!val);
	}
	if(n == 4) {
		ask(1);
		val = ask(4);
		if(!val) answer(4);
		val = ask(2);
		if(!val) answer(3);
		val = ask(3);
		if(!val) answer(2);
		answer(1);
	}
	val = ask((n+1)/2);
	val = ask(1);
	int rval = ask(n);
	if(!rval) answer(n);
	if(val) {
		l = (n+1)/2+2, r = n-1;
		int x = (n+1)/2+1;
		for(int len = (n-(n+1)/2)-1;len >= 1;len--) {
			val = ask(x);
			if(!val) answer(len+1);
			if(x-1 == r) x = l++;
			else x = r--;
		}
		answer(1);
		return 0;
	}
	else {
		if(n == 3) answer(2);
		l = 3, r = n-1;
		int x = 2;
		for(int len = n-2;len >= n-((n+1)/2);len--) {
			val = ask(x);
			if(!val) answer(len+1);
			if(x-1 == r) x = l++;
			else x = r--;
		}
		answer(n-((n+1)/2));
		return 0;
	}
}
