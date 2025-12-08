#include <bits/stdc++.h>

using namespace std;
using d_ = double;

struct cutoffs {
    d_ d, t_h, t_l;
};

d_ cdf(d_ y, d_ t) {
    if (y < 0) return 0;
    if (y < t) return t * y;
    return y * (1 + t) - t;
}

d_ mean_cdf01(d_ t) {
    return (1 - t + t * t) / 2.0;
}

cutoffs spear_cutoff(d_ d, d_ c) {
    cutoffs r{d, 0, 0};
    r.t_h = d + (1 - d) * (1 - d) / 2.0;
    r.t_l = (d / c) * (1 - d / 2.0) + (c * c - c) / (2 * c);
    return r;
}

d_ spears_win_vs_nash(d_ d, d_ c) {
    auto cut = spear_cutoff(d, c);
    d_ t_h = cut.t_h, t_l = cut.t_l;

    auto e_h = [&]() {
        d_ a = d, b = 1.0, t = t_h;
        d_ part1 = t * (min(b, t) * min(b, t) - a * a) / 2.0;
        if (t < a) part1 = 0;
        d_ part2 = 0;
        d_ lo = max(a, t);
        if (lo < b) {
            part2 = ((1 + t) * (b * b - lo * lo) / 2.0) - t * (b - lo);
        }
        return (part1 + part2) / (b - a);
    }();

    auto e_l = [&]() {
        d_ w_r = c / d, w_k = (d - c) / d;
        d_ t = t_l;
        d_ e_r = mean_cdf01(t);
        d_ a = c, b = d;
        d_ e_k = ((1 + t) * (b * b - a * a) / 2.0 - t * (b - a)) / (b - a);
        return w_r * e_r + w_k * e_k;
    }();

    d_ p_h = 1 - d, p_l = d;
    d_ java_win = p_h * e_h + p_l * e_l;
    return 1.0 - java_win;
}

d_ java_best_response_win(d_ d, d_ t_h, d_ t_l) {
    d_ r_h = mean_cdf01(t_h);
    d_ s_h = r_h / t_h;

    d_ r_l = mean_cdf01(t_l);
    d_ s_l = (r_l <= t_l * t_l) ? (r_l / t_l) : ((r_l + t_l) / (1 + t_l));

    d_ win_h;
    {
        d_ a = d, b = 1.0, t = t_h;
        d_ part1 = t * (min(b, t) * min(b, t) - a * a) / 2.0;
        if (t < a) part1 = 0;
        d_ part2 = 0;
        d_ lo = max(a, t);
        if (lo < b) part2 = ((1 + t) * (b * b - lo * lo) / 2.0 - t * (b - lo));
        win_h = (part1 + part2) / (b - a);
    }

    d_ win_l;
    {
        d_ a = 0.0, b = d;
        d_ w_keep = (b - s_l) / b;
        d_ w_redraw = 1 - w_keep;
        d_ redraw_win = mean_cdf01(t_l);

        d_ part1 = 0, part2 = 0;
        d_ t = t_l;
        if (s_l < t) {
            d_ hi = min(t, b);
            part1 = t * (hi * hi - s_l * s_l) / 2.0;
        }
        d_ lo = max(s_l, t);
        if (lo < b) {
            part2 = ((1 + t) * (b * b - lo * lo) / 2.0 - t * (b - lo));
        }
        d_ keep_win = (part1 + part2) / (b - s_l);
        win_l = w_redraw * redraw_win + w_keep * keep_win;
    }

    d_ p_h = 1 - d, p_l = d;
    return p_h * win_h + p_l * win_l;
}

int main() {
    const d_ c = (sqrt(5.0) - 1.0) / 2.0;

    d_ best_d = c, best_spears = 0;
    for (int i = 0; i <= 50000; ++i) {
        d_ d = c + (1 - c) * i / 50000.0;
        d_ sw = spears_win_vs_nash(d, c);
        if (sw > best_spears) {
            best_spears = sw;
            best_d = d;
        }
    }

    auto cut = spear_cutoff(best_d, c);
    d_ java_win = java_best_response_win(best_d, cut.t_h, cut.t_l);

    cout.setf(ios::fixed);
    cout << setprecision(10);
    cout << "nash cutoff c = " << c << '\n';
    cout << "spears optimal d =~ " << best_d << '\n';
    cout << "spears t_h = " << cut.t_h << ", t_l = " << cut.t_l << '\n';
    cout << "spears win vs nash = " << best_spears << " -> java wins " << (1 - best_spears) << '\n';
    cout << "java best-response win vs spears policy = " << java_win << '\n';
}
