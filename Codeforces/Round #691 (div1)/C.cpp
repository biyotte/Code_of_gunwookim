#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[106], b[106], sum[106], sumA[106], selected[106][106], selectedA[106][106];
double dp[106][106];
bool visited[106][106];

double f(int, int);
double left(int, int);
double spill(int, int);

double f(int i, int j) {
    if (!j) return 0;
    if (!i) {
        selected[i][j] = b[0];
        selectedA[i][j] = a[0];
        return b[0];
    }
    if (visited[i][j]) return dp[i][j];
    visited[i][j] = true;
    dp[i][j] = max(f(i - 1, j) + min(b[i] / 2., selectedA[i - 1][j] - f(i - 1, j)), b[i] + f(i - 1, j - 1) + min(spill(i - 1, j - 1) / 2., 0. + a[i] - b[i]));
    if (dp[i][j] == f(i - 1, j) + min(b[i] / 2., selectedA[i - 1][j] - f(i - 1, j))) selected[i][j] = selected[i - 1][j], selectedA[i][j] = selected[i - 1][j];
    else selected[i][j] = selected[i - 1][j - 1] + b[i], selectedA[i][j] = selectedA[i - 1][j - 1] + a[i];
    return dp[i][j];
}

double spill(int i, int j) {
    return sum[i] - 2 * f(i, j) + selected[i][j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
    for (int i = 0; i < n; i++) sum[i] = b[i] + (i ? sum[i - 1] : 0), sumA[i] = a[i] + (i ? sumA[i - 1] : 0);
    for (int i = 0; i < n; i++) printf("%.12f ", f(n - 1, i + 1));
}