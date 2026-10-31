class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());

        int n = spells.size(), m = potions.size();
        vector<int> res{};
        for (auto s : spells) {
            auto it = lower_bound(potions.begin(), potions.end(),
                                  (success + s - 1) / s);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};