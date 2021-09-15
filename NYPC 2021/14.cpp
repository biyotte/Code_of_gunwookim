    #include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 2e18+5;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
typedef unsigned long long ull;
int T;
ll C[100005][205];
ll k,cut[205];

ll nCr(ll n,ll r) {
    if(cut[r] <= n) return llINF/2+1;
    if(n <= 100000&&r <= 200&&C[n][r]) return C[n][r];
    __int128 val = 1;
    for(ll i = 1;i <= r;i++) {
        val *= (n-r+i);
        val /= i;
    }
    if(n <= 100000&&r <= 200) C[n][r] = (ll)val;
    return (ll)val;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    cut[0] = llINF/2;
    cut[1] = llINF/2;
    cut[2] = 1LL*INF*2;
    cut[3] = 2000000;
    cut[4] = 100000;
    for(ll i = 5;i <= 200;i++) {
        __int128 val = 1;
        C[i][i] = 1;
        for(ll j = i;j <= 100000;j++) {
            val *= (j+1);
            val /= (j-i+1);
            if(val > llINF/2) {
                cut[i] = j+1;
                break;
            }
            C[j+1][i] = (ll)val;
        }
    }
    while(T--) {
        cin >> k;
        //k = T;
        if(k <= 3) {
            cout << -1+(k-1)*2 << '\n';
            continue;
        }
        ll ans = 4,R,mid,l,r;
        ull val;
        for(int st = 0;st <= 62;st += 2) {
            for(int len = max(0,2-st/2);len <= 62-st;len++) {
                R = st/2,val,mid;
                l = st, r = cut[R+len]+1;
                int i;
                while(l < r) {
                    mid = (l + r) >> 1LL;
                    val = nCr(mid,R);
                    for(i = R+len;i > R+1;i -= 2) {
                        val += nCr(mid+len+2,i);
                        if(val >= k) break;
                    }
                    if(val+(val < k&&i == R+1&&len ? nCr(mid+len+1,R+1) : 0) >= k) r = mid;
                    else l = mid+1;
                }
                val = nCr(l,R);
                for(i = R+len;i > R+1;i -= 2) {
                    val += nCr(l+len+2,i);
                    if(val > k) break;
                }
                val += (i == R+1&&len&&val <= k ? nCr(l+len+1,R+1) : 0);
                if(val == k) {
                    //cout << val << ' ' << st << ' ' << len << ' ' << l << ' ' << R << '\n';
                    ans += 1+(l != st);
                }
                if(l == st&&val >= k) break;
            }
        }
        cout << ans << '\n';
        //if(ans !=  ans2) return 0;
    }
}
