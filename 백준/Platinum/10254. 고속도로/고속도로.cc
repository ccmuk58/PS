#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e9 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
struct Point
{
    ll x, y;
    auto operator<=>(const Point &other) const = default;
};
struct Line
{
    Point a, b;
    auto operator<=>(const Line &other) const = default;
};
Point operator+(Point l, Point r)
{
    return Point(l.x + r.x, l.y + r.y);
}
Point operator-(Point l, Point r)
{
    return Point(l.x - r.x, l.y - r.y);
}
ll operator*(Point l, Point r)
{
    return (ll)l.x * r.x + (ll)l.y * r.y;
}
ll operator/(Point l, Point r)
{
    return (ll)l.x * r.x - (ll)l.y * r.y;
}

ll ccw(Point a, Point b, Point c)
{
    Point v1 = {b.x - a.x, b.y - a.y};
    Point v2 = {c.x - b.x, c.y - b.y};
    ll w = v1.x * v2.y - v1.y * v2.x;
    if (w < 0)
        return -1; // cw
    else if (w > 0)
        return 1; // ccw
    else
        return 0; // 일직선
}
ll vccw(Point a, Point b)
{
    ll w = a.x * b.y - a.y * b.x;
    if (w < 0)
        return -1; // cw
    else if (w > 0)
        return 1; // ccw
    else
        return 0; // 일직선
}
ll dist(Point a, Point b)
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
ll dist2(Point a, Point b)
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}
bool yxCmp(const Point &a, const Point &b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x <= b.x;
}
Point stp;
bool angleCmp(const Point& a, const Point& b) 
{
	ll c = ccw(stp, a, b);
	if(c==0)
	{
		return dist2(stp,a) <= dist2(stp,b);
	}
	return c>0;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    while (T--)
    {
        vector<Point> p;
        vector<Line> l;
        ll ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> X >> Y;
            p.push_back({X, Y});
        }
        sort(p.begin(), p.end(), yxCmp);
        vector<Point> cvh(N + 1);
		stp=p[0];
		sort(p.begin()+1, p.end(), angleCmp);
        cvh[0] = p[0];
        cvh[1] = p[1];

        p.push_back(p[0]);
        ll top = 2;

        for (int i = 2; i <= N; i++)
        {
            while (top >= 2)
            {
                Point p1 = cvh[top - 2];
                Point p2 = cvh[top - 1];
                ll a = ccw(p1, p2, p[i]);

                if (a >= 0)
                {
                    break;
                }
                top--;
            }
            cvh[top] = p[i];
            top++;
        }
        top--;

        ll minX = INT64_MAX;
        ll maxX = INT64_MIN;
        ll minXi = -1;
        ll maxXi = -1;

        for (int i = 0; i < top; i++)
        {
            if (minX > cvh[i].x)
            {
                minX = cvh[i].x;
                minXi = i;
            }
            if (maxX < cvh[i].x)
            {
                maxX = cvh[i].x;
                maxXi = i;
            }
        }

        ll idx1 = minXi;
        ll idx2 = maxXi;
        Point ansA = cvh[idx1];
        Point ansB = cvh[idx2];
        ll maxD = dist2(ansA, ansB);

        for (int i = 0; i < top; i++)
        {
			Point p1 = cvh[(idx1) % top];
			Point np1 = cvh[(idx1+1) % top];
			Point p2 = cvh[(idx2) % top];
			Point np2 = cvh[(idx2+1) % top];
            ll d = dist2(p1, p2);
            if (d > maxD)
            {
                maxD = d;
                ansA = p1;
                ansB = p2;
            }
			
			Point v1 = np1-p1;
			Point v2 = p2-np2;
			if(vccw(v1,v2) > 0)
			{
				idx1++;
			}
			else
			{
				idx2++;
			}
        }

        cout << ansA.x << " " << ansA.y << " " << ansB.x << " " << ansB.y << "\n";
    }
}