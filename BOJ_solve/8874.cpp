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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int h[5005][205],v[5005][205],opt[205][205];

struct Tree {
    int d[201][201];
}t[1100];

Tree merge(Tree &L,Tree &R) {
    Tree ret;
    for(int i = 1;i <= m;i++) {
        ret.d[m][i] = INF*2;
        for(int j = 1;j <= m;j++) {
            if(ret.d[m][i] > L.d[m][j]+R.d[j][i]) {
                opt[m][i] = j;
                ret.d[m][i] = L.d[m][j]+R.d[j][i];
            }
        }
    }
    for(int i = 1;i <= m;i++) {
        ret.d[i][1] = INF*2;
        for(int j = 1;j <= m;j++) {
            if(ret.d[i][1] > L.d[i][j]+R.d[j][1]) {
                opt[i][1] = j;
                ret.d[i][1] = L.d[i][j]+R.d[j][1];
            }
        }
    }
    for(int i = m-1;i >= 1;i--) {
        for(int j = 2;j <= m;j++) {
            ret.d[i][j] = INF*2;
            for(int k = opt[i][j-1];k <= opt[i+1][j];k++) {
                if(ret.d[i][j] > L.d[i][k]+R.d[k][j]) {
                    opt[i][j] = k;
                    ret.d[i][j] = L.d[i][k]+R.d[k][j];
                }
            }
        }
    }
    return ret;
}

Tree Make(int x) {
    Tree ret;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= m;j++) ret.d[i][j] = INF;
    }
    for(int i = 1;i <= m;i++) ret.d[i][i] = 0;
    for(int w = 1;w <= 20;w++) {
        int i = 20*(x-1)+w;
        for(int j = 1;j <= m;j++) {
            for(int k = 2;k <= m;k++) ret.d[j][k] = min(ret.d[j][k],ret.d[j][k-1]+h[i][k-1]);
            for(int k = m-1;k >= 1;k--) ret.d[j][k] = min(ret.d[j][k],ret.d[j][k+1]+h[i][k]);
            for(int k = 1;k <= m;k++) ret.d[j][k] += v[i][k];
        }
    }
    return ret;
}

void update(int x,int l,int r,int wi) {
    if(wi < l||r < wi) return;
    if(l == r) {
        t[x] = Make(l);
        return;
    }
    int mid = (l + r) >> 1;
    update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
    t[x] = merge(t[x*2],t[x*2+1]);
}

void build(int x,int l,int r) {
    if(l == r) {
        t[x] = Make(l);
        return;
    }
    int mid = (l + r) >> 1;
    build(x*2,l,mid), build(x*2+1,mid+1,r);
    t[x] = merge(t[x*2],t[x*2+1]);
}

void init(int R, int C, int H[5000][200], int V[5000][200]) {
    memset(h,0x3f,sizeof(h));
    n = R, m = C;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j < m;j++) h[i][j] = H[i-1][j-1];
    }
    for(int i = 1;i < n;i++) {
        for(int j = 1;j <= m;j++) v[i][j] = V[i-1][j-1];
    }
    build(1,1,n/20+(n%20 > 0));
}

void changeH(int x, int y, int val) {
    h[x+1][y+1] = val;
    update(1,1,n/20+(n%20 > 0),x/20+1);
}

void changeV(int x, int y, int val) {
    v[x+1][y+1] = val;
    update(1,1,n/20+(n%20 > 0),x/20+1);
}

int escape(int sy,int ey) {
    sy++, ey++;
    return t[1].d[sy][ey];
}

int H[5000][200],V[5000][200];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int R,C,Q;
    cin >> R >> C;
    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C-1;j++) {
            cin >> H[i][j];
        }
    }
    for(int i = 0;i < R-1;i++) {
        for(int j = 0;j < C;j++) {
            cin >> V[i][j];
        }
    }
    init(R,C,H,V);
    cin >> Q;
    while(Q--) {
        int op,x,y,z;
        cin >> op >> x >> y;
        if(op <= 2) cin >> z;
        if(op == 1) changeH(x,y,z);
        if(op == 2) changeV(x,y,z);
        if(op == 3) cout << escape(x,y) << '\n';
    }
}
