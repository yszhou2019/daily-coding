## Common Compile Errors

- integer overflow
  - Line 26: Char 32: runtime error: signed integer overflow: 35009 * 99761764 cannot be represented in type 'int' (solution.cpp)
  - error code: `sum * e % mod` 三个都是integer32
  - solution: 用 int64 进行计算，最后要结果的时候再转化为 int32

## Binary Tree

- 最基本的是DFS
- 从root节点到任一目标节点的路径，可用DFS完成
- DFS / BFS 时间复杂度 O(N)， N 为节点总数

### LCA

- LCA，lowest common ancestor，最基本的问题是，如何求两个目标节点之间的LCA？
- 最基本的思路，依次使用dfs求出两个节点的路径（从root出发的路径)，然后找到最后一个common的节点即可
- LCA，下个问题，如何若干目标节点的LCA？或者说，给定一个set，包含了若干节点，求这个set的LCA？
- 思路是类似的，dfs的时候保存所有目标节点的路径；最后遍历这些路径，找到LCA即可
- LCA，对于完全二叉树，有个性质，（如果节点按照层次遍历，编号，1,2,3,...)，那么任一一个节点，编号➗2，即可得到parent 节点的编号。
  - 也就是对于完全二叉树而言，得到一个目标节点的路径，只需要O(logN)时间
  - 而对于普通二叉树，需要O(N)来得到一个目标节点的路径

<!---LeetCode Topics Start-->
# LeetCode Topics
## Array
|  |
| ------- |
| [0034-find-first-and-last-position-of-element-in-sorted-array](https://github.com/yszhou2019/daily-coding/tree/master/0034-find-first-and-last-position-of-element-in-sorted-array) |
| [0035-search-insert-position](https://github.com/yszhou2019/daily-coding/tree/master/0035-search-insert-position) |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0303-range-sum-query-immutable](https://github.com/yszhou2019/leetcode/tree/master/0303-range-sum-query-immutable) |
| [0307-range-sum-query-mutable](https://github.com/yszhou2019/leetcode/tree/master/0307-range-sum-query-mutable) |
| [0436-find-right-interval](https://github.com/yszhou2019/daily-coding/tree/master/0436-find-right-interval) |
| [0658-find-k-closest-elements](https://github.com/yszhou2019/daily-coding/tree/master/0658-find-k-closest-elements) |
| [0699-falling-squares](https://github.com/yszhou2019/leetcode/tree/master/0699-falling-squares) |
| [0704-binary-search](https://github.com/yszhou2019/daily-coding/tree/master/0704-binary-search) |
| [0875-koko-eating-bananas](https://github.com/yszhou2019/daily-coding/tree/master/0875-koko-eating-bananas) |
| [1011-capacity-to-ship-packages-within-d-days](https://github.com/yszhou2019/daily-coding/tree/master/1011-capacity-to-ship-packages-within-d-days) |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
| [1521-find-a-value-of-a-mysterious-function-closest-to-target](https://github.com/yszhou2019/leetcode/tree/master/1521-find-a-value-of-a-mysterious-function-closest-to-target) |
| [1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array](https://github.com/yszhou2019/leetcode/tree/master/1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array) |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
| [2569-handling-sum-queries-after-update](https://github.com/yszhou2019/leetcode/tree/master/2569-handling-sum-queries-after-update) |
| [2916-subarrays-distinct-element-sum-of-squares-ii](https://github.com/yszhou2019/leetcode/tree/master/2916-subarrays-distinct-element-sum-of-squares-ii) |
| [3069-distribute-elements-into-two-arrays-i](https://github.com/yszhou2019/leetcode/tree/master/3069-distribute-elements-into-two-arrays-i) |
| [3072-distribute-elements-into-two-arrays-ii](https://github.com/yszhou2019/leetcode/tree/master/3072-distribute-elements-into-two-arrays-ii) |
| [3097-shortest-subarray-with-or-at-least-k-ii](https://github.com/yszhou2019/leetcode/tree/master/3097-shortest-subarray-with-or-at-least-k-ii) |
| [3171-find-subarray-with-bitwise-or-closest-to-k](https://github.com/yszhou2019/leetcode/tree/master/3171-find-subarray-with-bitwise-or-closest-to-k) |
| [3187-peaks-in-array](https://github.com/yszhou2019/leetcode/tree/master/3187-peaks-in-array) |
## Design
|  |
| ------- |
| [0303-range-sum-query-immutable](https://github.com/yszhou2019/leetcode/tree/master/0303-range-sum-query-immutable) |
| [0307-range-sum-query-mutable](https://github.com/yszhou2019/leetcode/tree/master/0307-range-sum-query-mutable) |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
| [2286-booking-concert-tickets-in-groups](https://github.com/yszhou2019/leetcode/tree/master/2286-booking-concert-tickets-in-groups) |
## Prefix Sum
|  |
| ------- |
| [0303-range-sum-query-immutable](https://github.com/yszhou2019/leetcode/tree/master/0303-range-sum-query-immutable) |
## Divide and Conquer
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0307-range-sum-query-mutable](https://github.com/yszhou2019/leetcode/tree/master/0307-range-sum-query-mutable) |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
## Binary Indexed Tree
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0307-range-sum-query-mutable](https://github.com/yszhou2019/leetcode/tree/master/0307-range-sum-query-mutable) |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
| [2286-booking-concert-tickets-in-groups](https://github.com/yszhou2019/leetcode/tree/master/2286-booking-concert-tickets-in-groups) |
| [2916-subarrays-distinct-element-sum-of-squares-ii](https://github.com/yszhou2019/leetcode/tree/master/2916-subarrays-distinct-element-sum-of-squares-ii) |
| [3072-distribute-elements-into-two-arrays-ii](https://github.com/yszhou2019/leetcode/tree/master/3072-distribute-elements-into-two-arrays-ii) |
| [3187-peaks-in-array](https://github.com/yszhou2019/leetcode/tree/master/3187-peaks-in-array) |
## Segment Tree
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0307-range-sum-query-mutable](https://github.com/yszhou2019/leetcode/tree/master/0307-range-sum-query-mutable) |
| [0699-falling-squares](https://github.com/yszhou2019/leetcode/tree/master/0699-falling-squares) |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
| [1521-find-a-value-of-a-mysterious-function-closest-to-target](https://github.com/yszhou2019/leetcode/tree/master/1521-find-a-value-of-a-mysterious-function-closest-to-target) |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
| [2286-booking-concert-tickets-in-groups](https://github.com/yszhou2019/leetcode/tree/master/2286-booking-concert-tickets-in-groups) |
| [2569-handling-sum-queries-after-update](https://github.com/yszhou2019/leetcode/tree/master/2569-handling-sum-queries-after-update) |
| [2916-subarrays-distinct-element-sum-of-squares-ii](https://github.com/yszhou2019/leetcode/tree/master/2916-subarrays-distinct-element-sum-of-squares-ii) |
| [3072-distribute-elements-into-two-arrays-ii](https://github.com/yszhou2019/leetcode/tree/master/3072-distribute-elements-into-two-arrays-ii) |
| [3171-find-subarray-with-bitwise-or-closest-to-k](https://github.com/yszhou2019/leetcode/tree/master/3171-find-subarray-with-bitwise-or-closest-to-k) |
| [3187-peaks-in-array](https://github.com/yszhou2019/leetcode/tree/master/3187-peaks-in-array) |
## Stack
|  |
| ------- |
| [1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array](https://github.com/yszhou2019/leetcode/tree/master/1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array) |
## Greedy
|  |
| ------- |
| [0303-range-sum-query-immutable](https://github.com/yszhou2019/leetcode/tree/master/0303-range-sum-query-immutable) |
| [0307-range-sum-query-mutable](https://github.com/yszhou2019/leetcode/tree/master/0307-range-sum-query-mutable) |
| [1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array](https://github.com/yszhou2019/leetcode/tree/master/1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array) |

`priority_queue`
- PQ默认comp是less，但是root节点是最大的元素
- sort默认comp也是less，但是顺序是从小到大
- 如何快速清空PQ？PQ没有clear method，并且逐一pop过于耗时。因此可以构建一个新的pq。考虑comp比较复杂，可以 `pq = decltype(pq)(comp);`
- 快速清空PQ，可能需要c++2a的支持
#
## Sort + PQ
|  |
| ------- |
  - 核心思路，贪心
  - 先按照初始资金量进行排序
  - 不断看可以做的任务，对于所有可以做的任务中，挑个利润最大的；如果没有可做任务，那么就停止
  - 迭代project的时候，因为需要不断向后看，因此用while (cnt < k)作为外层循环，内层循环向后看用另外一个while loop
- 857 Minimum Cost to Hire K Workers，雇佣k个工人的最低代价
  - 题目要求，对于一组工人，最终的花费=sum of quality  * 最高时薪
  - 贪心思路，按照时薪进行排序（从低时薪到高时薪)
  - 然后迭代每个工人，用PQ 大根堆，存储quality最少的k个元素，每次有k个元素就进行局部贪心
  - 用PQ 来完成线性时间维护top K 的sum
- 1383 Maximum Performance of a Team，**至多**选k个工人，得到的最大产出
  - 题目要求，一组工人，产出=sum of speed * 最低效率
  - 贪心思路，对效率进行排序，从高到低排序
  - 然后迭代工人，用PQ 小根堆，存储 top K speed
  - PQ完成线性时间维护 top K sum
- 2542 Maximum Subsequence Score
  - 定义得分= sum of nums1[slice] * min of nums2[slice]，求最大得分
  - 贪心思路，数组组合为vector `<PII>` ，然后按照nums2从大到小排序
  - 不断迭代，用PQ 大根堆 维护 top K sum，每次得到k个元素后用 sum * min 更新结果
- **回顾**上面三道题
  - 定义优化目标=sum of attr1 * min/max(attr2)
  - 按照attr2反方向排序(迭代方向、排序方向其实无所谓，都可以写出对应的正确解法)
  - 然后用PQ 大根堆/小根堆 维护 top K sum，不断迭代即可
- 1353 Maximum Number of Events That Can Be Attended
  - 题干描述，若干会议，每个会议只要被参加一天，就被视作参加；求最多参加多少会议
  - 贪心思路，如果n个会议都是同一天开始，那么哪个会议结束的越早，就优先参加哪个会议
  - 对天数进行迭代，每天看看(1)有哪些会议可以参加，添加到PQ中；(2)然后哪些会议已经超时、不能参加，从PQ中移出；(3)如果PQ有会议可以参加，那就pop并更新count
  - PQ采用小根堆，记录每个会议的结束时间
  - 如何表示一个会议被参加过？首先，会议要想被参加，必须要enqueue，并且没有被pop queue；然后每天只能参加一个，那就是最早结束的那个会议，并remove from queue
  - ```cpp
            int i{}, n = events.size();
            for (int d = 1; d <= 100'000; d++) {
                while (i < n && events[i][0] <= d) {
                    pq.push(events[i][1]);
                    i++;
                }
                while (!pq.empty() && pq.top() < d)
                    pq.pop();
                // pick up the most close to stop one
                if (!pq.empty()) {
                    res++;
            }
    ```
- 1834 Single-Threaded CPU
  - 题干描述，给出CPU的任务选择策略，以及若干任务的提交时间和运行时间，求CPU完成任务的先后顺序
  - CPU执行任务的时候，按照时间的流逝，选择任务执行
  - 贪心思路，按照任务的提交时间排序，然后迭代，每次把若干可以被执行的任务放到任务池PQ中，选择优先级最高的任务进行处理
  - 先给每个任务添加属性 idx并按照 less进行排序；PQ用小根堆，用来存储可执行的任务
  - 简言之，提交任务，PQ优中选优，挑选最高优先级的进行执行，不断重复
  - 具体代码1，while里面不断检查，把所有donable（任务已经提交) push PQ；如果一个任务都没有提交到queue并且PQ为空并且还有任务，那么时间cur直接跳到下个任务的开始时间；否则，从PQ选择一个最好的任务进行执行
            while (res.size() != n) {
                // pick out donable tasks
                bool found{};
                while (i < n && cur >= tasks[i][0]) {
                    pq.push({tasks[i][1], tasks[i][2]});
                    found = true;
                // jump to next start time
                if (!found && i < n && pq.empty()) {
                    cur = tasks[i][0];
                    continue;
                // pick up the most prior one and execute
                auto [p, i] = pq.top();
                cur += p;
                res.push_back(i);
                pq.pop();
  - 具体代码2，按照提交顺序，迭代所有任务；如果cur还没有到提交时间，那么优先执行手头的任务，也就是候选池的任务；如果执行完毕之后还没有到提交时间，那么cur跳到当前提交时间，并提交任务
        for (int i = 0; i < n; i++) {
            // far reach
            while (!pq.empty() && cur < tasks[i][0]) {
                auto [dura, j] = pq.top();
                cur += dura;
                res.push_back(j);
            if (cur < tasks[i][0])
                cur = tasks[i][0];
            pq.push({tasks[i][1], tasks[i][2]});
        }
        while (!pq.empty()) {
            auto [_, j] = pq.top();
            res.push_back(j);
            pq.pop();
- 1851 Minimum Interval to Include Each Query
  - offline queries TODO
  - 思路，先对queries进行按照从小到大进行排序。对intervals也进行排序。
  - 贪心思路，对每个query迭代，PQ 先把左端点符合条件的interval进行push，再pop不符合条件的右端点，剩下来的 pq.top就是最短区间（PQ存储 dura, right)
- 630 Course Schedule III
  - 题目描述，一堆课程，每个课程有ddl和耗时，对最多能修的课程数量求最大值（对数量进行贪心)
  - 什么样的贪心策略，可以得到最多的课程数量？
  - 贪心策略，优先选择耗时短的， or ddl更早的课程。通过列举反例，我优先选择耗时短，其次选择ddl更早的课程。或者，持续时间，然后最晚开始时间（尽量无课可修的减少等待的时间)
  - 以时间为变量，far reach后面的课程
<!---LeetCode Topics Start-->
# LeetCode Topics
## Array
|  |
| ------- |
## Dynamic Programming
|  |
| ------- |
| [1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array](https://github.com/yszhou2019/leetcode/tree/master/1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array) |
## Monotonic Stack
|  |
| ------- |
| [1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array](https://github.com/yszhou2019/leetcode/tree/master/1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array) |
## Binary Search
|  |
| ------- |
| [0034-find-first-and-last-position-of-element-in-sorted-array](https://github.com/yszhou2019/daily-coding/tree/master/0034-find-first-and-last-position-of-element-in-sorted-array) |
| [0035-search-insert-position](https://github.com/yszhou2019/daily-coding/tree/master/0035-search-insert-position) |
| [0278-first-bad-version](https://github.com/yszhou2019/daily-coding/tree/master/0278-first-bad-version) |
| [0367-valid-perfect-square](https://github.com/yszhou2019/daily-coding/tree/master/0367-valid-perfect-square) |
| [0436-find-right-interval](https://github.com/yszhou2019/daily-coding/tree/master/0436-find-right-interval) |
| [0658-find-k-closest-elements](https://github.com/yszhou2019/daily-coding/tree/master/0658-find-k-closest-elements) |
| [0704-binary-search](https://github.com/yszhou2019/daily-coding/tree/master/0704-binary-search) |
| [0875-koko-eating-bananas](https://github.com/yszhou2019/daily-coding/tree/master/0875-koko-eating-bananas) |
| [1011-capacity-to-ship-packages-within-d-days](https://github.com/yszhou2019/daily-coding/tree/master/1011-capacity-to-ship-packages-within-d-days) |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
| [1237-find-positive-integer-solution-for-a-given-equation](https://github.com/yszhou2019/daily-coding/tree/master/1237-find-positive-integer-solution-for-a-given-equation) |
| [1521-find-a-value-of-a-mysterious-function-closest-to-target](https://github.com/yszhou2019/leetcode/tree/master/1521-find-a-value-of-a-mysterious-function-closest-to-target) |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
| [2286-booking-concert-tickets-in-groups](https://github.com/yszhou2019/leetcode/tree/master/2286-booking-concert-tickets-in-groups) |
| [3171-find-subarray-with-bitwise-or-closest-to-k](https://github.com/yszhou2019/leetcode/tree/master/3171-find-subarray-with-bitwise-or-closest-to-k) |
## Ordered Set
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0699-falling-squares](https://github.com/yszhou2019/leetcode/tree/master/0699-falling-squares) |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
## Merge Sort
|  |
| ------- |
| [1649-create-sorted-array-through-instructions](https://github.com/yszhou2019/leetcode/tree/master/1649-create-sorted-array-through-instructions) |
## Simulation
|  |
| ------- |
| [3069-distribute-elements-into-two-arrays-i](https://github.com/yszhou2019/leetcode/tree/master/3069-distribute-elements-into-two-arrays-i) |
| [3072-distribute-elements-into-two-arrays-ii](https://github.com/yszhou2019/leetcode/tree/master/3072-distribute-elements-into-two-arrays-ii) |
## Bit Manipulation
|  |
| ------- |
| [1521-find-a-value-of-a-mysterious-function-closest-to-target](https://github.com/yszhou2019/leetcode/tree/master/1521-find-a-value-of-a-mysterious-function-closest-to-target) |
| [3097-shortest-subarray-with-or-at-least-k-ii](https://github.com/yszhou2019/leetcode/tree/master/3097-shortest-subarray-with-or-at-least-k-ii) |
| [3171-find-subarray-with-bitwise-or-closest-to-k](https://github.com/yszhou2019/leetcode/tree/master/3171-find-subarray-with-bitwise-or-closest-to-k) |
## Sliding Window
|  |
| ------- |
| [0658-find-k-closest-elements](https://github.com/yszhou2019/daily-coding/tree/master/0658-find-k-closest-elements) |
| [3097-shortest-subarray-with-or-at-least-k-ii](https://github.com/yszhou2019/leetcode/tree/master/3097-shortest-subarray-with-or-at-least-k-ii) |
## Sparse Table
|  |
| ------- |
| [1521-find-a-value-of-a-mysterious-function-closest-to-target](https://github.com/yszhou2019/leetcode/tree/master/1521-find-a-value-of-a-mysterious-function-closest-to-target) |
## 摩尔投票算法
|  |
| ------- |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
## Sqrt Decomposition
|  |
| ------- |
| [1157-online-majority-element-in-subarray](https://github.com/yszhou2019/leetcode/tree/master/1157-online-majority-element-in-subarray) |
## Hash Table
|  |
| ------- |
| [2916-subarrays-distinct-element-sum-of-squares-ii](https://github.com/yszhou2019/leetcode/tree/master/2916-subarrays-distinct-element-sum-of-squares-ii) |
## Sorting
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0436-find-right-interval](https://github.com/yszhou2019/daily-coding/tree/master/0436-find-right-interval) |
| [0658-find-k-closest-elements](https://github.com/yszhou2019/daily-coding/tree/master/0658-find-k-closest-elements) |
## Sweep Line
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
## Heap (Priority Queue)
|  |
| ------- |
| [0218-the-skyline-problem](https://github.com/yszhou2019/leetcode/tree/master/0218-the-skyline-problem) |
| [0658-find-k-closest-elements](https://github.com/yszhou2019/daily-coding/tree/master/0658-find-k-closest-elements) |
## Two Pointers
|  |
| ------- |
| [0658-find-k-closest-elements](https://github.com/yszhou2019/daily-coding/tree/master/0658-find-k-closest-elements) |
| [1237-find-positive-integer-solution-for-a-given-equation](https://github.com/yszhou2019/daily-coding/tree/master/1237-find-positive-integer-solution-for-a-given-equation) |
## Math
|  |
| ------- |
| [0367-valid-perfect-square](https://github.com/yszhou2019/daily-coding/tree/master/0367-valid-perfect-square) |
| [1237-find-positive-integer-solution-for-a-given-equation](https://github.com/yszhou2019/daily-coding/tree/master/1237-find-positive-integer-solution-for-a-given-equation) |
## Interactive
|  |
| ------- |
| [0278-first-bad-version](https://github.com/yszhou2019/daily-coding/tree/master/0278-first-bad-version) |
| [1237-find-positive-integer-solution-for-a-given-equation](https://github.com/yszhou2019/daily-coding/tree/master/1237-find-positive-integer-solution-for-a-given-equation) |
<!---LeetCode Topics End-->