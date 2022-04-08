#include <bits/stdc++.h>

int main(int, char**) {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; 
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int N; 
        scanf("%d", &N);
        vector<pair<int, int64_t>> P(N);
        int64_t total = 0;
        for (auto& x : P) {
            cin >> x.first >> x.second;
            total += x.first * x.second;
        }

        auto function = [&](int64_t x) -> bool {
            if (x <= 1) {
                return false;
            }

            int64_t cur_sum = 0;
            int64_t v = x;

            for (auto x : P) {
                

            }


        

        };

        int64_t ans = 0;



        printf("Case #%d: %d\n", i, i);
    }

    return 0;
}