#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), pre(n + 1, -1);
	std::vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		l[i] = std::max(pre[a[i]], pre[a[i] - 1]) + 1;
		pre[a[i]] = i;
	}	
	
	std::vector<int> lst(n + 1, n);
	for (int i = n - 1; i >= 0; i--) {
		r[i] = lst[a[i] - 1] - 1;
		lst[a[i]] = i;
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans + 1ll * (i - l[i] + 1) * (r[i] - i + 1);
	}
	std::cout << ans << '\n';
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