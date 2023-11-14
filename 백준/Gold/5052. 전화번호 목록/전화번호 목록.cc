#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 10;

struct Trie {
    bool isEnd;
    Trie* node[LIMIT];
    Trie() : isEnd(false) { memset(node, 0, sizeof(node)); }

    void Insert(const char* key) {
        if (*key == '\0') {
            isEnd = true;
			return;
        } 
		int cur = *key - '0';
		if (node[cur] == NULL) 
			node[cur] = new Trie();
		node[cur]->Insert(key + 1);
    }
    bool Find(const char* str) {
        int cur = *str - '0';
		if(*str == '\0')
		{
			if(isEnd == true) return true;
			else return false;
		}
        else if (node[cur] == NULL) return false;
		else if(isEnd == true) return false;
        return node[cur]->Find(str + 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
		Trie* root = new Trie();
		vector<string> v;
		string resultStr = "YES";
		cin >> n;
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            v.push_back(s);
            root->Insert(s.c_str());
        }
		for(int j = 0; j < n; j++)
		{

			if(root->Find(v[j].c_str()) == false)
				resultStr = "NO";
		}
		cout << resultStr + "\n";
    }
}