#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

class line
{
  public:
    ll sx;
    ll sy;
    ll ex;
    ll ey;
    ll w;
    int indeg;
	ll s;
    line(ll a, ll b, ll c, ll d, ll e)
    {
        sx = a;
        sy = b;
        ex = c;
        ey = d;
        w = e;
        indeg = 0;
		s = w;
    }
	void comp()
	{
		s = w*(indeg+1);
	}
	void subIndeg()
	{
		indeg--;
		comp();
	}
};

bool cmp(line l1, line l2)
{
	if(l1.w==l2.w)
	{
		return (l1.indeg < l2.indeg);
	}
	return (l1.w < l2.w);
}
int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
    ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0)
        return 1;
    else if (s == 0)
        return 0;
    else
        return -1;
}

bool isCross(line l1, line l2)
{

    pi p1 = {l1.sx, l1.sy};
    pi p2 = {l1.ex, l1.ey};
    pi p3 = {l2.sx, l2.sy};
    pi p4 = {l2.ex, l2.ey};

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0)
    {
        // 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2)
            swap(p2, p1);
        if (p3 > p4)
            swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }

    return p1p2 <= 0 && p3p4 <= 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    vector<line> l;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll sx, sy, ex, ey, w;
        cin >> sx >> sy >> ex >> ey >> w;
        l.push_back({sx, sy, ex, ey, w});
		for(int j=0; j<i; j++)
		{
			if(isCross(l[i], l[j]))
			{
				l[i].indeg++;
				l[j].indeg++;
				l[i].comp();
				l[j].comp();
			}
		}
    }

	ll ans = 0;
	for(int i=0; i<N; i++)
	{
		sort(l.begin()+i, l.end(), cmp);

		ans += l[i].s;
		for(int j=i+1; j<N; j++)
		{
			if(isCross(l[i], l[j]))
			{
				l[j].subIndeg();
			}
		}
	}
	cout << ans;
}