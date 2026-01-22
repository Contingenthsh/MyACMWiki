#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

void solve() {
	int n;
	std::cin >> n;
	std::vector<ll> a(n), b;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::unordered_set<ll> s;
	[&](this auto&& self, int x) ->void {
		if (x >= n) {
			ll res = 0;
			for (int i = 0; i < b.size(); i++) {
				res ^= b[i];
			}
			
			s.insert(res);
			return;
		}
		for (int i = 0; i < b.size(); i++) {
			b[i] += a[x];
			self(x + 1);
			b[i] -= a[x];
		}
		
		b.push_back(a[x]);
		self(x + 1);
		b.pop_back();
	} (0);
	
	std::cout << s.size() << '\n';
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