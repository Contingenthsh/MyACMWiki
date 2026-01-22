#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

constexpr int N = 5005;

void solve() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> cnt(3);
	std::vector a(3, std::vector<int> (N));	
	std::vector c(3, std::vector<int> (N));	
	std::vector dp(3, std::vector<int> (N));
	
	for (int i = 0; i < n; i++) {
		int tp, A, C;
		std::cin >> tp >> A >> C;
		tp--;
		cnt[tp]++;
		a[tp][cnt[tp]] = A;
		c[tp][cnt[tp]] = C;
	}
	
	for (int tp = 0; tp < 3; tp++) {
		for (int i = 1; i <= cnt[tp]; i++) {
			for (int j = x; j >= c[tp][i]; j--) {
				dp[tp][j] = std::max(dp[tp][j], 
					dp[tp][j - c[tp][i]] + a[tp][i]);
			}
		}
	}
	int max = 0;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= x; j++) {
			if (i + j > x) continue;
			int k = x - i - j;
			if (dp[0][i] && dp[1][j] && dp[2][k]) {
				max = std::max(max, std::min({dp[0][i], dp[1][j], dp[2][k]}));
			}
		}
 	}
	std::cout << max << '\n';
} 

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int tt = 1;
	// std::cin >> tt;
	while (tt--) {
		solve();
	}
	
	return 0;
}