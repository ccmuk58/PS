#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

struct Block {
    int addr, size;
    bool used;
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    list<Block> mem;
    mem.push_back({1, 100000, false});
    unordered_map<string, list<Block>::iterator> var;
    string str, substr;
	
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        substr = str.substr(0, 5);

        if(substr == "print")
        {
            substr = str.substr(6, 4);
            if(var.count(substr)>0 && var[substr] != mem.end())
                cout << var[substr]->addr << "\n";
            else
                cout << 0 << "\n";
        }
        else if(substr == "free(")
        {
            substr = str.substr(5, 4);
            if(var.count(substr)==0 || var[substr] == mem.end())
                continue;

            auto it = var[substr];
            it->used = false;

            // 뒤 블록 병합
            auto nxt = next(it);
            if(nxt != mem.end() && !nxt->used)
            {
                it->size += nxt->size;
                mem.erase(nxt);
            }

            // 앞 블록 병합
            if(it != mem.begin())
            {
                auto prv = prev(it);
                if(!prv->used)
                {
                    prv->size += it->size;
                    mem.erase(it);
                }
            }

            var[substr] = mem.end();
        }
        else	// malloc("asdf")
        {
            substr = str.substr(0, 4);
            string nstr;
            for(int j = 12; j < (int)str.length(); j++)
            {
                if(str[j] == ')') break;
                nstr.push_back(str[j]);
            }
            int n = stoi(nstr);

            auto it = mem.end();
            for(auto cur = mem.begin(); cur != mem.end(); ++cur)
            {
                if(!cur->used && cur->size >= n)
                {
                    it = cur;
                    break;
                }
            }

            if(it == mem.end())
            {
                var[substr] = mem.end();
            }
            else
            {
                int rem = it->size - n;
                it->used = true;
                it->size = n;

                // 남은 공간 새 free 블록으로 삽입
                if(rem > 0)
                {
                    auto ins = next(it);
                    mem.insert(ins, {it->addr + n, rem, false});
                }

                var[substr] = it;
            }
        }
    }
}