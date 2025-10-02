#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

bool pn[152];

void era()
{
    for (int i = 2; i < 150; i++)
    {
        for (int j = i * i; j < 150; j += i)
        {
            pn[j] = false;
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    fill(pn + 2, pn + 151, true);

    era();
    vector<int> pv;
    for (int i = 2; i < 150; i++)
    {
        if (pn[i])
            pv.push_back(i);
    }
    int a = -1;
    int b = -1;
    int c = -1;
    int d = -1;
    int e = -1;
    int f = -1;
    int g = -1;
    int h = -1;
	int z=0;
	int z1=0;
	int z2=0;
	int z3=0;
	int z4=0;
	int z5=0;
    int k = 0;
    int l = 0;

    if (N <= 2)
    {
        cout << -1;
        return 0;
    }
    if (N == 3)
    {
        for (int i = 0; i < pv.size(); i++)
        {
            for (int j = i; j < pv.size(); j++)
            {
                for (int k = j + 1; k < pv.size(); k++)
                {
                    a = pv[i];
                    b = pv[j];
                    c = pv[k];
                    int s = a * a + b * b + c * c;
                    if (s % a == 0 && s % b == 0 && s % c == 0)
                    {
                        d = a;
                        e = b;
                        f = c;
                        i = 500;
                        j = 500;
                        k = 500;
                        break;
                    }
                }
            }
        }
        cout << d << " " << e << " " << f;
        return 0;
    }
    if (N == 4)
    {

        for (int i = 0; i < pv.size(); i++)
        {
            for (int j = i; j < pv.size(); j++)
            {
                for (int k = j; k < pv.size(); k++)
                {

                    for (int l = k + 1; l < pv.size(); l++)
                    {
                        a = pv[i];
                        b = pv[j];
                        c = pv[k];
                        d = pv[l];
                        int s = a * a + b * b + c * c + d * d;
                        if (s % a == 0 && s % b == 0 && s % c == 0 && s % d == 0)
                        {
                            e = a;
                            f = b;
                            g = c;
                            h = d;
                            i = 500;
                            j = 500;
                            k = 500;
                            l = 500;
                            break;
                        }
                    }
                }
            }
        }
        cout << e << " " << f << " " << g << " " << h << " ";
        return 0;
    }
	if (N == 6)
    {

        for (int i = 0; i < pv.size(); i++)
        {
            for (int j = i; j < pv.size(); j++)
            {
                for (int k = j; k < pv.size(); k++)
                {

                    for (int l = k; l < pv.size(); l++)
                    {
                    for (int m = l; m < pv.size(); m++)
					{
						for (int n = m+1; n < pv.size(); n++)
						{
	
							a = pv[i];
							b = pv[j];
							c = pv[k];
							d = pv[l];
							e = pv[m];
							f = pv[n];
							int s = a * a + b * b + c * c + d * d + e*e + f*f;
							if (s % a == 0 && s % b == 0 && s % c == 0 && s%d==0 && s%e==0 && s%f==0)
							{
								z = a;
								z1 = b;
								z2 = c;
								z3 = d;
								z4 = e;
								z5 = f;
								i = 500;
								j = 500;
								k = 500;
								l = 500;
								n = 500;
								m = 500;
								break;
							}
						}
						
					}
				}
                }
            }
		}
            cout <<   z << " " << z1 << " " <<z2 << " " << z3 << " " << z4 << " " << z5<< " ";
            return 0;
        }

    if (N % 2 == 1)
    {
        cout << "2 2 2 ";
        for (int i = 3; i < N; i++)
        {
            cout << 3 << " ";
        }
        return 0;
    }
    else
    {

        cout << "2 2 2 2 2 2 ";
        for (int i = 6; i < N; i++)
        {
            cout << 3 << " ";
        }
	}
	// 8 : 9 9 4 4 4 4 4 4
    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < b; i++)
        {
            cout << a << " ";
        }

        for (int i = 0; i < a; i++)
        {
            cout << b << " ";
        }
    }
}