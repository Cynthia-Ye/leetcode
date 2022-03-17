#
# @lc app=leetcode.cn id=783 lang=python3
#
# [783] 二叉搜索树节点最小距离
#
# https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
#
# algorithms
# Easy (58.91%)
# Likes:    172
# Dislikes: 0
# Total Accepted:    56.6K
# Total Submissions: 96K
# Testcase Example:  '[4,2,6,1,3]'
#
# 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
# 
# 注意：本题与
# 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
# 相同
# 
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：root = [4,2,6,1,3]
# 输出：1
# 
# 
# 示例 2：
# 
# 
# 输入：root = [1,0,48,null,null,12,49]
# 输出：1
# 
# 
# 
# 
# 提示：
# 
# 
# 树中节点数目在范围 [2, 100] 内
# 0 
# 
# 
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        self.vals = []
        self.midOrder(root)
        return min((self.vals[i + 1] - self.vals[i]) for i in range(len(self.vals) - 1))
    def midOrder(self, root):
        if not root:
            return
        self.midOrder(root.left)
        self.vals.append(root.val)
        self.midOrder(root.right)
        return
        
# @lc code=end

