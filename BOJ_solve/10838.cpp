#include <bits/stdc++.h>
#define MAXN 200005
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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,sum,h[100005],c,ch[100005];
int p[100005],b[100005],xh,yh;
set <int> s;
 
int high(int x) {
    sum = 0;
    while(1) {
        if(x == 0) return sum;
        sum++;
        x = p[x];
    }
}
 
void lca(int x,int y) {
    if(x == y) return;
    if(ch[x] == c) xh = h[x];
    else {
        xh = high(x);
        h[x] = xh;
        ch[x] = c;
    }
    if(ch[y] == c) yh = h[y];
    else {
        yh = high(y);
        h[y] = yh;
        ch[y] = c;
    }
    while(1) {
        if(x == y) return;
        if(xh > yh) {
            xh--;
            s.insert(b[x]);
            x = p[x];
        }
        else if(xh < yh) {
            yh--;
            s.insert(b[y]);
            y = p[y];
        }
        else {
            xh--;
            s.insert(b[x]);
            x = p[x];
            yh--;
            s.insert(b[y]);
            y = p[y];
        }
    }
}
 
void paint(int x,int y,int z) {
    if(x == y) return;
    if(ch[x] == c) xh = h[x];
    else {
        xh = high(x);
        h[x] = xh;
        ch[x] = c;
    }
    if(ch[y] == c) yh = h[y];
    else {
        yh = high(y);
        h[y] = yh;
        ch[y] = c;
    }
    while(1) {
        if(x == y) return;
        if(xh > yh) {
            xh--;
            b[x] = z;
            x = p[x];
        }
        else if(xh < yh) {
            yh--;
            b[y] = z;
            y = p[y];
        }
        else {
            xh--;
            b[x] = z;
            x = p[x];
            yh--;
            b[y] = z;
            y = p[y];
        }
    }
}
 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int x,y,z,tr;
    cin >> n >> k;
    p[0] = -1;
    b[0] = -1;
    for(int i = 1;i < n;i++) h[i] = 1;
    for(int i = 1;i <= k;i++) {
        cin >> tr;
        if(tr == 1) {
            cin >> x >> y >> z;
            paint(x,y,z);
        }
        else if(tr == 2) {
            cin >> x >> y;
            p[x] = y;
            c++;
        }
        else {
            cin >> x >> y;
            s.clear();
            lca(x,y);
            cout << s.size() << '\n';
        }
    }
}