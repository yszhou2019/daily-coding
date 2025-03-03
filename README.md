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
- minimum cost to hire K workers
