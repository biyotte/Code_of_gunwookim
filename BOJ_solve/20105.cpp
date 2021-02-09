#include "advisor.h"
#include "assistant.h"
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
set <int> in,hubo;

void Assist(unsigned char *A,int n,int k,int r) {
    for(int i = 0;i < k;i++) {
        if(!A[i]) hubo.insert(i);
        else in.insert(i);
    }
    for(int i = 0;i < n;i++) {
        int now = GetRequest();
        if(in.find(now) != in.end()) in.erase(now);
        else PutBack(*hubo.begin()), hubo.erase(hubo.begin());
        if(!A[i+k]) hubo.insert(now);
        else in.insert(now);
    }
}

int bit[200005],nx[200005],on[200005];
priority_queue <pi> q;
vec v[100005];

void ComputeAdvice(int *C,int n,int k,int m) {
    for(int i = 0;i < k;i++) v[i].pb(i);
    for(int i = 0;i < n;i++) v[C[i]].pb(i+k);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < (int)v[i].size()-1;j++) nx[v[i][j]] = v[i][j+1];
        if(!v[i].empty()) nx[v[i].back()] = INF;
    }
    memset(on,-1,sizeof(on));
    for(int i = 0;i < k;i++) q.push({nx[i],i}), on[i] = i;
    for(int i = 0;i < n;i++) {
        if(on[C[i]] != -1) bit[on[C[i]]] = 1;
        else on[q.top().y] = -1, q.pop();
        on[C[i]] = i+k;
        q.push({nx[i+k],C[i]});
    }
    for(int i = 0;i < n+k;i++) WriteAdvice(bit[i]);
}