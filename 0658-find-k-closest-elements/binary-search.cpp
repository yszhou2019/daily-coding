class Solution {
public:
    using PII = pair<int, int>;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // map arr -> {abs(ele-x), original value}
        vector<PII> cache{};
        for (int i = 0; i < arr.size(); i++)
            cache.push_back({abs(arr[i] - x), arr[i]});

        // sort
        sort(cache.begin(), cache.end());

        // compose results
        vector<int> res(k);
        transform(cache.begin(), cache.begin() + k, res.begin(),
                  [&arr](auto& ele) { return ele.second; });
        sort(res.begin(), res.end());
        return res;
    }
};