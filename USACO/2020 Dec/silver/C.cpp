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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,sz[1005],ind[1005];
int p[1005];

struct Cow {
	int x,y; char op;
	int endtime = -1;
}a[1005];

struct Time {int x,y,time,time2,who;};
vector <Time> crush;

bool cmp(Time x,Time y) {return x.time < y.time;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].op >> a[i].x >> a[i].y;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(a[i].op^a[j].op) {
				if(a[i].op == 'E') {
					if(a[i].x < a[j].x&&a[i].y > a[j].y) {
						if(a[j].x-a[i].x > a[i].y-a[j].y) crush.pb({i,j,a[j].x-a[i].x,a[i].y-a[j].y,i});
						if(a[j].x-a[i].x < a[i].y-a[j].y) crush.pb({i,j,a[i].y-a[j].y,a[j].x-a[i].x,j});
					}
				}
			}
		}
	}
	sort(all(crush),cmp);
	for(Time now : crush) {
		int x = now.x, y = now.y, time = now.time, time2 = now.time2, who = now.who;
		if(a[who].endtime != -1) continue;
		if(a[x^y^who].endtime != -1&&a[x^y^who].endtime < time2) continue;
		p[who] = x^y^who, ind[x^y^who]++;
		a[who].endtime = time;
	}
	queue <int> q;
	for(int i = 1;i <= n;i++) {
		sz[i] = 1;
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		sz[p[x]] += sz[x];
		if(!--ind[p[x]]) q.push(p[x]);
	}
	for(int i = 1;i <= n;i++) cout << sz[i]-1 << '\n';
}