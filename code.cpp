#include <iostream>
#include <algorithm>

int main() {
    long long a, b, c, d, e, f;
    if (!(std::cin >> a >> b >> c >> d >> e >> f)) return 0;

    long long T = f * b * a + e * a + d;
    long long day_seconds = c * b * a;
    long long limit = std::min({a, b, c});
    long long min_s = -1;

    for (long long v = 0; v < limit; ++v) {
        long long Tv = v * b * a + v * a + v;
        long long n3;
        if (Tv >= T) {
            n3 = 0;
        } else {
            n3 = (T - Tv + day_seconds - 1) / day_seconds;
        }
        long long current_T_prime = Tv + n3 * day_seconds;
        long long current_s = current_T_prime - T;
        if (min_s == -1 || current_s < min_s) {
            min_s = current_s;
        }
    }
    std::cout << min_s << std::endl;
    return 0;
}
