#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int,int> pi;
int n;
int a[300005],wi[300005],wi2[300005];
int t[2400005];

void update(int x,int l,int r,int wi) {
    if(wi < l||r < wi) return;
    if(l == r) {
        t[x] = 1; return;
    }
    int mid = (l + r) >> 1;
    update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
    t[x] = t[x*2]+t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
    if(rl > rr) return 0;
    if(rl <= l&&r <= rr) return t[x];
    if(rl > r||l > rr) return 0;
    int mid = (l + r) >> 1;
    return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], wi2[++a[i]] = i;
    for(int i = 1;i <= n;i++) {
        wi[i] = i;
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += query(1,1,2*n,n+wi[a[i]],2*n);
        update(1,1,2*n,n+wi[a[i]]);
    }
    vector <ll> Ans;
    for(int i = n;i >= 1;i--) {
        ans -= n-wi[a[i]];
        ans += wi[a[i]]-1;
        Ans.push_back(ans);
    }
    reverse(Ans.begin(),Ans.end());
    for(ll i : Ans) cout << i << '\n';
}
