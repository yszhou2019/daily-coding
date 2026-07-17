class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res{}, cur{};
        for (auto high: target){
            res += max(0, high-cur);
            cur = high;
        }
        return res;
    }
};