class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto it = remove_if(courses.begin(), courses.end(),
                            [](auto& a) { return a[0] > a[1]; });
        courses.erase(it, courses.end());

        sort(courses.begin(), courses.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int n = courses.size(), sum{};
        priority_queue<int> pq{};
        for (int i = 0; i < n; i++) {
            pq.push(courses[i][0]);
            sum += courses[i][0];
            if (sum > courses[i][1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};