class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> leftMoves(n);
        vector<int> rightMoves(n);

        int balls{};
        for (int i = 0; i < n; i++) {
            leftMoves[i] = (i == 0 ? 0 : leftMoves[i - 1]) + balls;
            balls += boxes[i] - '0';
        }

        balls = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightMoves[i] = (i == n - 1 ? 0 : rightMoves[i + 1]) + balls;
            balls += boxes[i] - '0';
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = leftMoves[i] + rightMoves[i];
        return res;
    }
};