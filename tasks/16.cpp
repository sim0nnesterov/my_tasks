#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

struct Point {
    ld x, y;
    bool operator!=(const Point &other) const {
        return other.x != x || other.y != y;
    }
    bool operator==(const Point &other) const {
        return other.x == x && other.y == y;
    }
    Point operator*(const ld k) const {
        return {x * k, y * k};
    }
};

Point nll = {1e18, 1};

struct Vector {
    ld x, y;
    Vector(Point &a, Point &b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    ld len() {
        return hypot(x, y);
    }
};

struct Line {
    ld a, b, c;
    Line(Point &a, Point &b) {
        this->a = a.y - b.y;
        this->b = b.x - a.x;
        c = - this->a * a.x - this->b * a.y;
    }
};

ld dot_product(Vector &a, Vector &b) {
    return a.x * b.x + a.y * b.y;
}

ld cross_product(Vector &a, Vector &b) {
    return a.x * b.y - a.y * b.x;
}

ld distP_P(Point &a, Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

ld distP_S(Point &p, Point &a, Point &b) {
    Vector ap(a, p), bp(b, p), ab(a, b);
    ll dot1 =  dot_product(ab, ap), dot2 = dot_product(ab, bp);
    if (dot1 < 0) {
        return distP_P(p, a);
    }
    if (dot2 > 0) {
        return distP_P(p, b);
    }
    return abs(cross_product(ap, ab)) / distP_P(a, b);
}

ld distP_R(Point &p, Point &a, Point &b) {
    Vector d(a, b), ap(a, p);
    if (dot_product(d, ap) < 0) {
        return distP_P(p, a);
    }
    return abs(cross_product(ap, d)) / distP_P(a, b);
}

ld distP_L(Point &p, Point &a, Point &b) {
    Vector pa(p, a), pb(p, b);
    return abs(cross_product(pa, pb)) / distP_P(a, b);
}

bool on_S(Point &p, Point &a, Point &b) {
    return (p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x)) && (p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y));
}

bool S_I(Point a, Point b, Point c, Point d) {
    Vector ab(a, b), ac(a, c), ad(a, d), cd(c, d), ca(c, a), cb(c, b);
    ld cp1 = cross_product(ab, ac), cp2 = cross_product(ab, ad), cp3 = cross_product(cd, ca), cp4 = cross_product(cd, cb);
    if (((cp1 > EPS && cp2 < -EPS) || (cp1 < -EPS && cp2 > EPS)) && ((cp3 > EPS && cp4 < -EPS) || (cp3 < -EPS && cp4 > EPS))) {
        return true;
    }
    if (abs(cp1) < EPS && on_S(c, a, b)) {
        return true;
    }
    if (abs(cp2) < EPS && on_S(d, a, b)) {
        return true;
    }
    if (abs(cp3) < EPS && on_S(a, c, d)) {
        return true;
    }
    if (abs(cp4) < EPS && on_S(b, c, d)) {
        return true;
    }
    return false;
}

ld distS_S(Point &a, Point &b, Point &c, Point &d) {
    if (S_I(a, b, c, d)) {
        return 0;
    }
    return min({distP_S(a, c, d), distP_S(b, c, d), distP_S(c, a, b), distP_S(d, a, b)});
}

bool eq(ld a, ld b) {
    ld c = abs(a - b);
    return c <= EPS;
}

bool on_R(Point &p, Point &o, Point &d) {
    Vector od(o, d), op(o, p);
    return dot_product(od, op) >= -EPS;
}

Point L_I(Line p, Line q) {
    ld det = p.a * q.b - q.a * p.b;
    if (eq(p.a * q.b, q.a * p.b)) {
        if (eq(p.a * q.c, q.a * p.c) && eq(p.b * q.c, q.b * p.c)) {
            return nll * -1;
        }
        return nll;
    }
    ld x = (p.b * q.c - q.b * p.c) / det, y = (p.c * q.a - q.c * p.a) / det;
    return {x, y};
}

ld distS_R(Point &a, Point &b, Point &c, Point &d) {
    Line l1(a, b), l2(c, d);
    Point r = L_I(l1, l2);
    if (r != nll && r != nll * -1 && on_S(r, a, b) && on_R(r, c, d)) {
        return 0;
    }
    if (r == nll * -1 && (on_R(a, c, d) || on_R(b, c, d))) {
        return 0;
    }
    ld n1 = distP_R(a, c, d), n2 = distP_R(b, c, d), n3 = distP_S(c, a, b);
    return min({n1, n2, n3});
}

ld distS_L(Point &a, Point &b, Point &c, Point &d) {
    Line l1(a, b), l2(c, d);
    Point r = L_I(l1, l2);
    if (r != nll && r != nll * -1 && on_S(r, a, b)) {
            return 0;
    }
    return min(distP_L(a, c, d), distP_L(b, c, d));
}

ld distR_R(Point &a, Point &b, Point &c, Point &d) {
    Line l1(a, b), l2(c, d);
    Point r = L_I(l1, l2);
    if (r != nll && r != nll * -1 && on_R(r, a, b) && on_R(r, c, d)) {
        return 0;
    }
    if (r == nll * -1 && (on_R(a, c, d) || on_R(c, a, b))) {
        return 0;
    }
    return min(distP_R(a, c, d), distP_R(c, a, b));
}

ld distL_R(Point &a, Point &b, Point &c, Point &d) {
    Line l1(a, b), l2(c, d);
    Point r = L_I(l1, l2);
    if (r != nll && on_R(r, c, d)) {
        return 0;
    }
    if (r == nll * -1) {
        return 0;
    }
    return distP_L(c, a, b);
}

ld distL_L(Point &a, Point &b, Point &c, Point &d) {
    Line l1(a, b), l2(c, d);
    Point r = L_I(l1, l2);
    if (r != nll) {
        return 0;
    }
    return distP_L(a, c, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    cout << fixed << setprecision(10);
    cout << distP_P(a, c) << '\n';
    cout << distP_S(a, c, d) << '\n';
    cout << distP_R(a, c, d) << '\n';
    cout << distP_L(a, c, d) << '\n';
    cout << distP_S(c, a, b) << '\n';
    cout << distS_S(a, b, c, d) << '\n';
    cout << distS_R(a, b, c, d) << '\n';
    cout << distS_L(a, b, c, d) << '\n';
    cout << distP_R(c, a, b) << '\n';
    cout << distS_R(c, d, a, b) << '\n';
    cout << distR_R(a, b, c, d) << '\n';
    cout << distL_R(c, d, a, b) << '\n';
    cout << distP_L(c, a, b) << '\n';
    cout << distS_L(c, d, a, b) << '\n';
    cout << distL_R(a, b, c, d) << '\n';
    cout << distL_L(a, b, c, d) << '\n';
    return 0;
}
