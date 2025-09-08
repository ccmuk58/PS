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

ll ans = 0;
vector<ll> v;
int cut=-1;
int dupcnt=1;
const int SIZE = 26;

struct Node{
	Node* child[SIZE];
	int cnt;

	Node()
	{
		cnt=0;
		for (int i = 0; i < SIZE; i++) {
            child[i] = nullptr;
        }
	}
};
struct Trie{
	private:
	Node* root;
public:
	Trie()
	{
		root = new Node();
	}

	void insert(const string& str)
	{
		Node* cur = root;
		for(int i=0; i<str.length(); i++)
		{
			int idx = str[i]-'a';
			if(!cur->child[idx])
			{
				if(cut==str.length()-1)
				{
					cut = i;
				}
				cur->child[idx] = new Node();
			}
			cur = cur->child[idx];
		}
		cur->cnt+=1;
		dupcnt = cur->cnt;
	}

	

};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	string str;
	Trie trie;
	for(int i=0; i<N; i++)
	{
		cin >> str;
		cut=str.length()-1;
		dupcnt=1;
		trie.insert(str);
		for(int j=0; j<=cut; j++)
		{
			cout << str[j];
		}
		if(dupcnt>1)
		{
			cout << dupcnt;
		}
		cout << "\n";
	}

}