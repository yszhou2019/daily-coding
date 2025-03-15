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

## Greedy

### About PQ in cpp / sort

`priority_queue`

- PQ默认comp是less，但是root节点是最大的元素
- sort默认comp也是less，但是顺序是从小到大
- 如何快速清空PQ？PQ没有clear method，并且逐一pop过于耗时。因此可以构建一个新的pq。考虑comp比较复杂，可以 `pq = decltype(pq)(comp);`
- 快速清空PQ，可能需要c++2a的支持

### Sort + PQ

- 通常的题目描述，给定若干资源，要挑选k个，完成最优化目标
- IPO，给定若干个项目（每个项目需要一定的资金量要求和获利)，在初始资金下，最多完成k个项目，求可以达到的最大资金量。（思路：对项目按照资金量要求进行排序+PQ，PQ root是"可实现的"最大收益)
  - 核心思路，贪心
  - 先按照初始资金量进行排序
  - 不断看可以做的任务，对于所有可以做的任务中，挑个利润最大的；如果没有可做任务，那么就停止
  - 迭代project的时候，因为需要不断向后看，因此用while (cnt < k)作为外层循环，内层循环向后看用另外一个while loop
- 857 Minimum Cost to Hire K Workers，雇佣k个工人的最低代价
  - 核心思路，贪心
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
  - 按照attr2反方向排序
  - 然后用PQ 大根堆/小根堆 维护 top K sum，不断迭代即可
- Maximum Number of Events That Can Be Attended
