#include "cpp_standards.h"
#include "cpp_structs.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        unordered_map<string, int> umap;
        set<int> s;
        for (int i = 0; i < words.size(); ++i) {
            umap[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string tmp = words[i];
            int len = (int) tmp.size();
            reverse(tmp.begin(), tmp.end());
            if (umap.count(tmp) && umap[tmp] != i) {
                result.push_back({i, umap[tmp]});
            }
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                if (isValid(tmp, 0, len - d - 1) && umap.count(tmp.substr(len - d))) {
                    result.push_back({i, umap[tmp.substr(len - d)]});
                }
                if (isValid(tmp, d, len - 1) && umap.count(tmp.substr(0, d))) {
                    result.push_back({umap[tmp.substr(0, d)], i});
                }
            }
        }
        return result;
    }

private:
    bool isValid(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};

int main() {
    vector<string> words = {"a", ""};
    print(words);
    Solution s;
    print(s.palindromePairs(words));
}