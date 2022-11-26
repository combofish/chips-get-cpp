/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
    // function start.
private:
    bool backtracking(const string &s,
                      const unordered_set<string> &wordSet,
                      vector<bool> &memory,
                      int startIndex) {
        if (startIndex >= s.size())
            return true;

        if (!memory[startIndex]) return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) {
            string tmp = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(tmp) != wordSet.end() && backtracking(s, wordSet, memory, i + 1))
                return true;
        }

        memory[startIndex] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), true);
        return backtracking(s, wordSet, memory, 0);
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool rel = true;

    IC(s, wordDict, rel);
    IC(solution->wordBreak(s, wordDict) == rel);

    // code end

    delete solution;
    return 0;
}


