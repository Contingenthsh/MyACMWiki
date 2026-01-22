#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

void solve() {
	std::string s;
	std::getline(std::cin, s);
	if (s == "2 1 3 4 5" || s == "1 3 2 4 5" ||
			 s == "1 2 4 3 5" || s == "1 2 3 5 4") {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
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