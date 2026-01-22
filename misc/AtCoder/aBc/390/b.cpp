#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

void solve() {
	int n;
	std::cin >> n;
	std::vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}	
	
	bool bad = false;
	for (int i = 0; i < n - 1; i++) {
		if (a[0] * a[i + 1] != a[1] * a[i]) {
			bad = true;
		}
	}
	
	if (bad) std::cout << "No\n";
	else std::cout << "Yes\n";
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