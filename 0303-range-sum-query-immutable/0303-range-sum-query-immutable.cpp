class NumArray {
public:
    using ll = long long;
    vector<ll> pre;
    NumArray(vector<int>& nums) : pre(nums.size(), 0) {
        int n = nums.size();
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
    }

    int sumRange(int left, int right) {
        return pre[right] - (left == 0 ? 0 : pre[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */