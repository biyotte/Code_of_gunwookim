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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char ina[65],inb[65];
int a[65],b[65],ansMax[65],ansMin[65];
int n,cnt[10],cnt2[10];

int dfsMax(int now) {
    if(now == n+1) return 1;
    if(cnt[a[now]]) {
        cnt[a[now]]--;
        if(dfsMax(now+1)) {
            ansMax[now] = a[now];
            return 1;
        }
        cnt[a[now]]++;
    }
    for(int i = a[now]+1;i < 10;i++) {
        if(cnt[i]) {
            ansMax[now] = i;
            cnt[i]--;
            for(int j = 0;j < 10;j++) {
                while(cnt[j]) cnt[j]--, ansMax[++now] = j;
            }
            return 1;
        }
    }
    return 0;
}

int dfsMin(int now) {
    if(now == n+1) return 1;
    if(cnt2[a[now]]&&now != n) {
        cnt2[a[now]]--;
        if(dfsMin(now+1)) {
            ansMin[now] = a[now];
            return 1;
        }
        cnt2[a[now]]++;
    }
    for(int i = a[now]-1;i >= (now == 1);i--) {
        if(cnt2[i]) {
            ansMin[now] = i;
            cnt2[i]--;
            for(int j = 9;j >= 0;j--) {
                while(cnt2[j]) cnt2[j]--, ansMin[++now] = j;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> ina+1 >> inb+1; n = strlen(ina+1);
    for(int i = 1;i <= n;i++) {
        a[i] = ina[i]-'0', b[i] = inb[i]-'0';
        cnt[b[i]]++; cnt2[b[i]]++;
    }
    if(dfsMax(1)) {for(int i = 1;i <= n;i++) cout << ansMax[i]; cout << '\n';}
    else cout << "0\n";
    if(dfsMin(1)) {for(int i = 1;i <= n;i++) cout << ansMin[i]; cout << '\n';}
    else cout << "0\n";
}
