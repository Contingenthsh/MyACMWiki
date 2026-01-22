#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

void solve() {
	int h, w;
	std::cin >> h >> w;
	std::vector<std::string> s(h);
	for (int i = 0; i < h; i++) {
		std::cin >> s[i];
	}	
	
	int li = h, hi = 0, lj = w, hj = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				li = std::min(li, i);
				hi = std::max(hi, i);
				lj = std::min(lj, j);
				hj = std::max(hj, j);
			}
		}
	}
	
	for (int i = li; i <= hi; i++) {
		for (int j = lj; j <= hj; j++) {
			if (s[i][j] == '.') {
				std::cout << "No\n";
				return;
			}
		}
	}
	std::cout << "Yes\n";
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