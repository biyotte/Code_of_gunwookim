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
const long long llINF = 4e18+10;
const long long mod = 20070713;
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
int n,a[1000005],top;
int sumL[1000005],sumR[1000005];
ll dL[1000005],dR[1000005];
pl s[1000005];

/*

d[i] : i번 상소문까지 처리했을 때 최소 비용
d[i] = min(d[j]+(sum[i]-sum[j])*i)
d[i] = min(sum[j]*-i+d[j])+sum[i]*i+i
d[i] = -max(sum[j]*i-d[j])+sum[i]*i+i
*/

ld getX(pl x,pl y) {return (ld)(x.y-y.y)/(y.x-x.x);}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) sumL[i] = sumL[i-1]+a[i];
    for(int i = n;i >= 1;i--) sumR[i] = sumR[i+1]+a[i];
    //dL[1] = sumL[1];
    s[++top] = {0,0};
    for(int i = 1;i <= n;i++) {
        int l = 1, r = top;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(getX(s[mid],s[mid+1]) <= i) l = mid+1;
            else r = mid;
        }
        dL[i] = -(s[l].x*i+s[l].y)+1LL*sumL[i]*i+i;
        if(!a[i]) continue;
        while(top > 1&&getX(s[top-1],s[top]) > getX(s[top],{sumL[i],-dL[i]})) top--;
        s[++top] = {sumL[i],-dL[i]};
    }
    top = 0;
    s[++top] = {0,0};
    for(int i = n;i >= 1;i--) {
        int l = 1, r = top;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(getX(s[mid],s[mid+1]) <= (n-i+1)) l = mid+1;
            else r = mid;
        }
        dR[i] = -(s[l].x*(n-i+1)+s[l].y)+1LL*sumR[i]*(n-i+1)+(n-i+1);
        if(!a[i]) continue;
        while(top > 1&&getX(s[top-1],s[top]) > getX(s[top],{sumR[i],-dR[i]})) top--;
        s[++top] = {sumR[i],-dR[i]};
    }
    vec v;
    v.pb(0);
    for(int i = 1;i <= n;i++) if(a[i]) v.pb(i);
    v.pb(n+1);
    ll ans = llINF;
    for(int i = 1;i < v.size();i++) {
        ans = min(ans,dL[v[i-1]]+dR[v[i]]);
    }
    cout << ans;
}