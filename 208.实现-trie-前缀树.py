#
# @lc app=leetcode.cn id=208 lang=python3
#
# [208] 实现 Trie (前缀树)
#
# https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
#
# algorithms
# Medium (70.08%)
# Likes:    710
# Dislikes: 0
# Total Accepted:    106K
# Total Submissions: 148.6K
# Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
#
# Trie（发音类似 "try"）或者说 前缀树
# 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
# 
# 请你实现 Trie 类：
# 
# 
# Trie() 初始化前缀树对象。
# void insert(String word) 向前缀树中插入字符串 word 。
# boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false
# 。
# boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true
# ；否则，返回 false 。
# 
# 
# 
# 
# 示例：
# 
# 
# 输入
# ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
# [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
# 输出
# [null, null, true, false, true, null, true]
# 
# 解释
# Trie trie = new Trie();
# trie.insert("apple");
# trie.search("apple");   // 返回 True
# trie.search("app");     // 返回 False
# trie.startsWith("app"); // 返回 True
# trie.insert("app");
# trie.search("app");     // 返回 True
# 
# 
# 
# 
# 提示：
# 
# 
# 1 
# word 和 prefix 仅由小写英文字母组成
# insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
# 
# 
#

# @lc code=start
class TrieNode:
    def __init__(self):
        self.isWord = False
        self.children = {}

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        work = self.root
        for c in word:
            if c not in work.children:
                work.children[c] = TrieNode()
            work = work.children[c]
        work.isWord = True
        


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        work = self.root
        for c in word:
            if c not in work.children:
                return False
            work = work.children[c]
        return work.isWord


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        work = self.root
        for c in prefix:
            if c not in work.children:
                return False
            work = work.children[c]
        return True



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end

