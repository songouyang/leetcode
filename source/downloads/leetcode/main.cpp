#include "cpp_standards.h"
#include "cpp_structs.h"

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket: tickets) {
            routes[ticket.first].insert(ticket.second);
        }
        helper("JFK");
        reverse(result.begin(), result.end());
        return result;
    }

private:
    map<string, multiset<string>> routes;
    vector<string> result;

    void helper(string start) {
        while (routes[start].size()) {
            auto tmp = *routes[start].begin();
            routes[start].erase(routes[start].begin());
            helper(tmp);
        }
        result.push_back(start);
    }
};


int main() {
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {2, 1},
            {3},
    };
    vector<pair<int, int>> edge = {
            {1, 0},
            {1, 2},
            {1, 3}
    };
    vector<int> nums = {4, 1, 8, 2, 6};
    vector<pair<string, string>> tickets = {
            {"MUC", "LHR"},
            {"JFK", "MUC"},
            {"SFO", "SJC"},
            {"LHR", "SFO"}
    };
    print(tickets);
    Solution s;
    print(s.findItinerary(tickets));
}