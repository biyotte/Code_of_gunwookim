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
int n,g,ans,wi[10],len[10];
int d6[10][10][10][10][10][10],d5[10][10][10][10][10],d4[10][10][10][10],d3[10][10][10],d2[10][10],d1[10];

struct Path {
	int x1,x2,x3,x4,x5,x6;
}p6[10][10][10][10][10][10],p5[10][10][10][10][10],p4[10][10][10][10],p3[10][10][10],p2[10][10],p1[10];
char c6[10][10][10][10][10][10],c5[10][10][10][10][10],c4[10][10][10][10],c3[10][10][10],c2[10][10],c1[10];
char a[10][10];

int f1(int x) {return x;}

int f6(int x1,int x2,int x3,int x4,int x5,int x6) {
	int & ret = d6[x1][x2][x3][x4][x5][x6];
	if(ret != -1) return ret;
	ret = INF;
	for(int st = 1;st <= 6;st++) {
		char wh;
		if(st == 1) wh = a[1][x1];
		if(st == 2) wh = a[2][x2];
		if(st == 3) wh = a[3][x3];
		if(st == 4) wh = a[4][x4];
		if(st == 5) wh = a[5][x5];
		if(st == 6) wh = a[6][x6];
		if(wh == '!') continue;
		int w1,w2,w3,w4,w5,w6;
		w1 = x1,w2 = x2,w3 = x3,w4 = x4,w5 = x5,w6 = x6;
		if(a[1][x1] == wh) w1--;
		if(a[2][x2] == wh) w2--;
		if(a[3][x3] == wh) w3--;
		if(a[4][x4] == wh) w4--;
		if(a[5][x5] == wh) w5--;
		if(a[6][x6] == wh) w6--;
		int val = f6(w1,w2,w3,w4,w5,w6);
		if(ret > val+1) ret = val+1, p6[x1][x2][x3][x4][x5][x6] = {w1,w2,w3,w4,w5,w6}, c6[x1][x2][x3][x4][x5][x6] = wh;
		else if(ret == val+1&&c6[x1][x2][x3][x4][x5][x6] > wh) p6[x1][x2][x3][x4][x5][x6] = {w1,w2,w3,w4,w5,w6}, c6[x1][x2][x3][x4][x5][x6] = wh;
		ret = min(ret,f6(w1,w2,w3,w4,w5,w6)+1);
	}
	return ret;
}

int f5(int x1,int x2,int x3,int x4,int x5) {
	int & ret = d5[x1][x2][x3][x4][x5];
	if(ret != -1) return ret;
	ret = INF;
	for(int st = 1;st <= 5;st++) {
		char wh;
		if(st == 1) wh = a[1][x1];
		if(st == 2) wh = a[2][x2];
		if(st == 3) wh = a[3][x3];
		if(st == 4) wh = a[4][x4];
		if(st == 5) wh = a[5][x5];
		if(wh == '!') continue;
		int w1,w2,w3,w4,w5;
		w1 = x1,w2 = x2,w3 = x3,w4 = x4,w5 = x5;
		if(a[1][x1] == wh) w1--;
		if(a[2][x2] == wh) w2--;
		if(a[3][x3] == wh) w3--;
		if(a[4][x4] == wh) w4--;
		if(a[5][x5] == wh) w5--;
		int val = f5(w1,w2,w3,w4,w5);
		if(ret > val+1) ret = val+1, p5[x1][x2][x3][x4][x5] = {w1,w2,w3,w4,w5}, c5[x1][x2][x3][x4][x5] = wh;
		else if(ret == val+1&&c5[x1][x2][x3][x4][x5] > wh) p5[x1][x2][x3][x4][x5] = {w1,w2,w3,w4,w5}, c5[x1][x2][x3][x4][x5] = wh;
		ret = min(ret,f5(w1,w2,w3,w4,w5)+1);
	}
	return ret;
}

int f4(int x1,int x2,int x3,int x4) {
	int & ret = d4[x1][x2][x3][x4];
	if(ret != -1) return ret;
	ret = INF;
	for(int st = 1;st <= 4;st++) {
		char wh;
		if(st == 1) wh = a[1][x1];
		if(st == 2) wh = a[2][x2];
		if(st == 3) wh = a[3][x3];
		if(st == 4) wh = a[4][x4];
		if(wh == '!') continue;
		int w1,w2,w3,w4;
		w1 = x1,w2 = x2,w3 = x3,w4 = x4;
		if(a[1][x1] == wh) w1--;
		if(a[2][x2] == wh) w2--;
		if(a[3][x3] == wh) w3--;
		if(a[4][x4] == wh) w4--;
		int val = f4(w1,w2,w3,w4);
		if(ret > val+1) ret = val+1, p4[x1][x2][x3][x4] = {w1,w2,w3,w4}, c4[x1][x2][x3][x4] = wh;
		else if(ret == val+1&&c4[x1][x2][x3][x4] > wh) p4[x1][x2][x3][x4] = {w1,w2,w3,w4}, c4[x1][x2][x3][x4] = wh;
		ret = min(ret,f4(w1,w2,w3,w4)+1);
	}
	return ret;
}

int f3(int x1,int x2,int x3) {
	int & ret = d3[x1][x2][x3];
	if(ret != -1) return ret;
	ret = INF;
	for(int st = 1;st <= 3;st++) {
		char wh;
		if(st == 1) wh = a[1][x1];
		if(st == 2) wh = a[2][x2];
		if(st == 3) wh = a[3][x3];
		if(wh == '!') continue;
		int w1,w2,w3;
		w1 = x1,w2 = x2,w3 = x3;
		if(a[1][x1] == wh) w1--;
		if(a[2][x2] == wh) w2--;
		if(a[3][x3] == wh) w3--;
		int val = f3(w1,w2,w3);
		if(ret > val+1) ret = val+1, p3[x1][x2][x3] = {w1,w2,w3}, c3[x1][x2][x3] = wh;
		else if(ret == val+1&&c3[x1][x2][x3] > wh) p3[x1][x2][x3] = {w1,w2,w3}, c3[x1][x2][x3] = wh;
		ret = min(ret,f3(w1,w2,w3)+1);
	}
	return ret;
}

int f2(int x1,int x2) {
	int & ret = d2[x1][x2];
	if(ret != -1) return ret;
	ret = INF;
	for(int st = 1;st <= 2;st++) {
		char wh;
		if(st == 1) wh = a[1][x1];
		if(st == 2) wh = a[2][x2];
		if(wh == '!') continue;
		int w1,w2;
		w1 = x1,w2 = x2;
		if(a[1][x1] == wh) w1--;
		if(a[2][x2] == wh) w2--;
		int val = f2(w1,w2);
		if(ret > val+1) ret = val+1, p2[x1][x2] = {w1,w2}, c2[x1][x2] = wh;
		else if(ret == val+1&&c2[x1][x2] > wh) p2[x1][x2] = {w1,w2}, c2[x1][x2] = wh;
		ret = min(ret,f2(w1,w2)+1);
	}
	return ret;
}

int F1(int x1) {
	int & ret = d1[x1];
	if(ret != -1) return ret;
	ret = INF;
	for(int st = 1;st <= 1;st++) {
		char wh;
		if(st == 1) wh = a[1][x1];
		if(wh == '!') continue;
		int w1;
		w1 = x1;
		if(a[1][x1] == wh) w1--;
		int val = F1(w1);
		if(ret > val+1) ret = val+1, p1[x1] = {w1}, c1[x1] = wh;
		else if(ret == val+1&&c1[x1] > wh) p1[x1] = {w1}, c1[x1] = wh;
		ret = min(ret,F1(w1)+1);
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i]+1, a[i][0] = '!', len[i] = strlen(a[i]+1), wi[i] = 1;
	for(int i = 1;i <= n;i++) {
		reverse(a[i]+1,a[i]+len[i]+1);
	}
	if(n == 1) {
		memset(d1,-1,sizeof(d1));
		d1[0] = 0;
		c1[0] = '!';
		ans = F1(len[1]);
		vector <char> an;
		int x1,t1;
		x1 = len[1];
		char wh = c1[x1];
		for(;1;) {
			if(wh == '!') break;
			an.pb(wh);
			t1 = p1[x1].x1;
			x1 = t1;
			wh = c1[x1];
		}
		for(char i : an) cout << i;
	}
	if(n == 2) {
		memset(d2,-1,sizeof(d2));
		d2[0][0] = 0;
		c2[0][0] = '!';
		ans = f2(len[1],len[2]);
		vector <char> an;
		int x1,x2,t1,t2;
		x1 = len[1], x2 = len[2];
		char wh = c2[x1][x2];
		for(;1;) {
			if(wh == '!') break;
			an.pb(wh);
			t1 = p2[x1][x2].x1;
			t2 = p2[x1][x2].x2;
			x1 = t1, x2 = t2;
			wh = c2[x1][x2];
		}
		for(char i : an) cout << i;
	}
	if(n == 3) {
		memset(d3,-1,sizeof(d3));
		d3[0][0][0] = 0;
		c3[0][0][0] = '!';
		ans = f3(len[1],len[2],len[3]);
		vector <char> an;
		int x1,x2,x3,t1,t2,t3;
		x1 = len[1], x2 = len[2], x3 = len[3];
		char wh = c3[x1][x2][x3];
		for(;1;) {
			if(wh == '!') break;
			an.pb(wh);
			t1 = p3[x1][x2][x3].x1;
			t2 = p3[x1][x2][x3].x2;
			t3 = p3[x1][x2][x3].x3;
			x1 = t1, x2 = t2, x3 = t3;
			wh = c3[x1][x2][x3];
		}
		for(char i : an) cout << i;
	}
	if(n == 4) {
		memset(d4,-1,sizeof(d4));
		d4[0][0][0][0] = 0;
		c4[0][0][0][0] = '!';
		ans = f4(len[1],len[2],len[3],len[4]);
		vector <char> an;
		int x1,x2,x3,x4,t1,t2,t3,t4;
		x1 = len[1], x2 = len[2], x3 = len[3], x4 = len[4];
		char wh = c4[x1][x2][x3][x4];
		for(;1;) {
			if(wh == '!') break;
			an.pb(wh);
			t1 = p4[x1][x2][x3][x4].x1;
			t2 = p4[x1][x2][x3][x4].x2;
			t3 = p4[x1][x2][x3][x4].x3;
			t4 = p4[x1][x2][x3][x4].x4;
			x1 = t1, x2 = t2, x3 = t3, x4 = t4;
			wh = c4[x1][x2][x3][x4];
		}
		for(char i : an) cout << i;
	}
	if(n == 5) {
		memset(d5,-1,sizeof(d5));
		d5[0][0][0][0][0] = 0;
		c5[0][0][0][0][0] = '!';
		ans = f5(len[1],len[2],len[3],len[4],len[5]);
		vector <char> an;
		int x1,x2,x3,x4,x5,t1,t2,t3,t4,t5;
		x1 = len[1], x2 = len[2], x3 = len[3], x4 = len[4], x5 = len[5];
		char wh = c5[x1][x2][x3][x4][x5];
		for(;1;) {
			if(wh == '!') break;
			an.pb(wh);
			t1 = p5[x1][x2][x3][x4][x5].x1;
			t2 = p5[x1][x2][x3][x4][x5].x2;
			t3 = p5[x1][x2][x3][x4][x5].x3;
			t4 = p5[x1][x2][x3][x4][x5].x4;
			t5 = p5[x1][x2][x3][x4][x5].x5;
			x1 = t1, x2 = t2, x3 = t3, x4 = t4, x5 = t5;
			wh = c5[x1][x2][x3][x4][x5];
		}
		for(char i : an) cout << i;
	}
	if(n == 6) {
		memset(d6,-1,sizeof(d6));
		d6[0][0][0][0][0][0] = 0;
		c6[0][0][0][0][0][0] = '!';
		ans = f6(len[1],len[2],len[3],len[4],len[5],len[6]);
		vector <char> an;
		int x1,x2,x3,x4,x5,x6,t1,t2,t3,t4,t5,t6;
		x1 = len[1], x2 = len[2], x3 = len[3], x4 = len[4], x5 = len[5], x6 = len[6];
		char wh = c6[x1][x2][x3][x4][x5][x6];
		for(;1;) {
			if(wh == '!') break;
			an.pb(wh);
			t1 = p6[x1][x2][x3][x4][x5][x6].x1;
			t2 = p6[x1][x2][x3][x4][x5][x6].x2;
			t3 = p6[x1][x2][x3][x4][x5][x6].x3;
			t4 = p6[x1][x2][x3][x4][x5][x6].x4;
			t5 = p6[x1][x2][x3][x4][x5][x6].x5;
			t6 = p6[x1][x2][x3][x4][x5][x6].x6;
			x1 = t1, x2 = t2, x3 = t3, x4 = t4, x5 = t5, x6 = t6;
			wh = c6[x1][x2][x3][x4][x5][x6];
		}
		for(char i : an) cout << i;
	}
}