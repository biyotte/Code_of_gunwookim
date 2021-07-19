#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
vector <int> v[20005];
vector <int> v2[20005];
int m,w,w2,c[20005],c2[20005],f1,f2,mid;
map <pair <int,int>,int> ma,check;
vector <pair<int,int>> vi;
vector <int> cross;
vector <pair<int,int>> line;
int ind[20005],p[20005],n;
vector <int> ra,rb;
int res[10005],cn;

int next_move(int x) {
	cn++;
	int y,z;
	if(x < 0) {
		cout << -x << " 0" << endl;
	}
	else {
		cout << x << " 1" << endl;
	}
	if(cn == n) return 0;
	cn++;
	cin >> y >> z;
	if(z) return y;
	return -y;
}

int f(int x) {
    if(x < 0) return abs(x);
    return x+10000;
}
 
void Check() {
    int f = 1;
    for(int i = 0;i < m;i++) {
        if(ra[i]*res[abs(ra[i])] > 0||rb[i]*res[abs(rb[i])] > 0) continue;
        f = 0;
        break;
    }
    //if(f&&s) while(1);
    while(f);
}
 
void makeWin(int x) {
    if(c2[abs(p[abs(x)])]) while(1);
    if(x > 0) {
        int r = next_move(p[x]);
 
        res[abs(p[x])] = (p[x] < 0 ? -1 : 1);
        res[abs(r)] = (r < 0 ? -1 : 1);
        c2[abs(r)] = c2[abs(p[x])] = 1;
 
    }
    else {
        int r = next_move(-p[-x]);
 
        res[abs(-p[-x])] = (-p[-x] < 0 ? -1 : 1);
        res[abs(r)] = (r < 0 ? -1 : 1);
 
        c2[abs(r)] = c2[abs(-p[-x])] = 1;
    }
}
 
void Fill(int iswin) {
    int s = iswin;
    for(int i = 1;i <= n;i++) {
        if(c2[i]||c[i]) continue;
        int r = next_move(-i);
        c2[abs(r)] = c2[i] = 1;
 
        res[i] = -1;
        res[abs(r)] = (r < 0 ? -1 : 1);
 
        if(c[abs(r)]&&!iswin) {
            makeWin(r);
            iswin = 1;
        }
    }
    //if(!iswin) while(1);
    for(int i : cross) {
        if(c2[i]) continue;
        int r = next_move(-i);
 
        res[i] = -1;
        res[abs(r)] = (r < 0 ? -1 : 1);
 
        c2[abs(r)] = c2[i] = 1;
    }
    Check();
}
 
void win_game (int N, std::vector<int> a, std::vector<int> b) {
    ra = a,rb = b;
    m = a.size();
    n = N;
    for(int i = 0;i < m;i++) vi.push_back({min(a[i],b[i]),max(b[i],a[i])});
    sort(vi.begin(),vi.end());
    vi.erase(unique(vi.begin(),vi.end()),vi.end());
    int t = 0;
    for(auto i : vi) {
        v2[i.first+10000].push_back(i.second);
        v2[i.second+10000].push_back(i.first);
        v[i.first+10000].push_back(t);
        v[i.second+10000].push_back(t);
        t++;
    }
    for(int i = 1;i <= n+10000;i++) {
        if(v2[i].size() >= 2) {
            w = i;
            //w = abs(i-10000);
            break;
        }
    }
    int t1,t2;
    if(w) {
		if(abs(vi[v[w][0]].x) == abs(w-10000)) t1 = vi[v[w][0]].y;
		else t1 = vi[v[w][0]].x;
 
		if(abs(vi[v[w][1]].x) == abs(w-10000)) t2 = vi[v[w][1]].y;
		else t2 = vi[v[w][1]].x;
		c[abs(w-10000)] = 1;
		int r = next_move(-(w-10000));
		c[abs(r)] = 1;
 
        res[abs(w-10000)] = (-(w-10000) < 0 ? -1 : 1);
        res[abs(r)] = (r < 0 ? -1 : 1);
 
		if(!c[abs(t1)]) {
 
		    r = next_move(-t1);
		    c[abs(r)] = c[abs(t1)] = 1;
 
            res[abs(-t1)] = (-t1 < 0 ? -1 : 1);
            res[abs(r)] = (r < 0 ? -1 : 1);
 
		}
		else if(!c[abs(t2)]) {
		    r = next_move(-t2);
		    c[abs(r)] = c[abs(t2)] = 1;
 
            res[abs(-t2)] = (-t2 < 0 ? -1 : 1);
            res[abs(r)] = (r < 0 ? -1 : 1);
		}
		for(int i = 1;i <= n;i++) {
		    if(!c[i]) {
		        r = next_move(-i);
		        c[abs(r)] = c[i] = 1;
 
                res[i] = -1;
                res[abs(r)] = (r < 0 ? -1 : 1);
		    }
		}
		Check();
		return;
	}
	int A = 0,B = 0;
 
	for(int i = 0;i < m;i++) {
        //a[i] *= -1; b[i] *= -1;
        if(a[i] > b[i]) swap(a[i],b[i]);
        if(ma[{a[i],b[i]}] == 1) continue;
        ma[{a[i],b[i]}] = 1;
        line.push_back({a[i],b[i]});
	}
	m = line.size();
	for(int i = 0;i < m;i++) {
        a[i] = line[i].x;
        b[i] = line[i].y;
	}
    for(int i = 0;i < m;i++) {
        if(ma[{-b[i],-a[i]}] == 1) {
            ma[{-b[i],-a[i]}] = 0;
            ma[{a[i],b[i]}] = 0;
            c[abs(a[i])] = c[abs(b[i])] = 1;
            A++;
            cross.push_back(abs(a[i]));
            cross.push_back(abs(b[i]));
            if(a[i] > 0) p[a[i]] = b[i];
            else p[-a[i]] = -b[i];
 
            if(b[i] > 0) p[b[i]] = a[i];
            else p[-b[i]] = -a[i];
        }
    }
    for(int i = 0;i < m;i++) {
        //cout << a[i] << ' ' << b[i] << '\n';
        //cout << f(a[i]) << ' ' << f(b[i]) << '\n';
        ind[f(a[i])] = b[i];
        ind[f(b[i])] = a[i];
    }
    for(int i = 1;i <= n;i++) {
        if(c[i]) continue;
        B++;
        //cout <<ind[i] << ' ' << ind[f(i)] << '\n';
        if(ind[i]&&ind[f(i)]) w = ind[i],w2 = ind[f(i)],mid = i;
    }
    if(mid) {
        //cout << "!";
        //cout <<w << ' ' << w2<< ' ' << mid << '\n';
        //w *= -1;
        //w2 *= -1;
        int r = next_move(-w);
        c2[abs(r)] = c2[abs(w)] = 1;
 
        res[abs(-w)] = (-w < 0 ? -1 : 1);
        res[abs(r)] = (r < 0 ? -1 : 1);
 
        if(abs(r) == mid) {
            r = next_move(-w2);
 
            res[abs(w2)] = (-w2 < 0 ? -1 : 1);
            res[abs(r)] = (r < 0 ? -1 : 1);
 
            c2[abs(r)] = c2[abs(w2)] = 1;
        }
        else {
            r = next_move(-mid);
 
            res[abs(-mid)] = (-mid < 0 ? -1 : 1);
            res[abs(r)] = (r < 0 ? -1 : 1);
 
            c2[abs(r)] = c2[mid] = 1;
 
        }
        Fill(1);
        return;
    }
    //cout << "!";
    if(B % 2 == 0||!A) return;
    //cout << "!";
    Fill(0);
}

int N,M;

vector <int> A,B;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for(int i = 1;i <= M;i++) {
		int x,y; cin >> x >> y;
		A.push_back(x), B.push_back(y);
	}
	win_game(N,A,B);
	if(!cn) cout << "-1 -1" << endl;
}
