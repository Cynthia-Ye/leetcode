# 罗马数字与整数互相转换

[TOC]

## 一、罗马数字特点

**1. 基本字符：7个基本字符**

```python
single_num = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
```

**2. 相减和累加规则：增加了6组复合字符**

- I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
- X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
- C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

```python
multi_num = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
```

**放在左邻是减，放在右邻是加：**如果某一位比后一位值小，则从总值中减去，否则做加法。

**3. 唯一表示规则：**
10进制数字转换成罗马数字时，对于罗马数字从左到右的每一位，选择尽可能大的符号值。对于 140，最大可以选择的符号值为 C=100。接下来，对于剩余的数字 40，最大可以选择的符号值为XL=40。因此，140 的对应的罗马数字为 C+XL=CXL。



## 二、Leetcode 13.罗马数字转整数

标签：字符串，数学

字符串的题目，python

利用罗马数字的相减和累加规则：

1. 累加
2. 放在左邻是减，放在右邻是加：如果某一位比后一位值小，则从总值中减去，否则做加法。



初步做的时候思路是这样的：

 **思路一：**

-  罗马数字只有单字符和2个字符两种组合形式，哈希表分别列出所有可能。

-  对字符串进行遍历，2 个字符优先于 1 个字符：
   - 先判断2个字符的组合在哈希表中是否存在，存在则取对应值做加法，并向后移2个字符。不存在则取1 个字符对应值做加法，并向后移 1 个字符。

-  遍历结束返回结果

```python
class Solution:
    single_num = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    multi_num = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
    def romanToInt(self, s: str) -> int:
        sum = 0
        i = 0
        while i < len(s) - 1:
            num = self.multi_num.get(s[i:i+2], -1)
            if num != -1:
                i += 2
            else:
                num = self.single_num[s[i]]
                i += 1
            sum += num
        if i == len(s) - 1:
            sum += self.single_num[s[i]]
        return sum
```



学习了题解的思路：

**思路二：**

如果某一位比后一位值小，则从总值中减去，否则做加法。

```python
class Solution:
    num_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    def romanToInt(self, s: str) -> int:
        num = 0
        for i in range(len(s) - 1):
            if self.num_dict[s[i]] < self.num_dict[s[i + 1]]:
                num -= self.num_dict[s[i]]
            else:
                num += self.num_dict[s[i]]
        return num + self.num_dict[s[-1]]
```



## 三、Leetcode 12. 整数转罗马数字

标签：字符串，贪心

**方法一：硬编码**

将每个数字在每一位上的表示形式硬编码，利用罗马数字的累加特性，直接拼接

注意：使用字符串方法处理数字时，注意str和int的相互转换

```python
class Solution:
    all_num = [{1:'I', 2:'II', 3:'III', 4:'IV', 5:'V', 6:'VI', 7:'VII', 8:'VIII', 9:'IX'},
               {1:'X', 2:'XX', 3:'XXX', 4:'XL', 5:'L', 6:'LX', 7:'LXX', 8:'LXXX', 9:'XC'},
               {1:'C', 2:'CC', 3:'CCC', 4:'CD', 5:'D', 6:'DC', 7:'DCC', 8:'DCCC', 9:'CM'},
               {1:'M', 2:'MM', 3:'MMM'}]
    def intToRoman(self, num: int) -> str:
        roma = ""
        numstr = str(num)
        for i in range(len(numstr)):
            digit = int(numstr[len(numstr) - 1 - i])
            if digit != 0:
                roma = self.all_num[i][digit] + roma
        return roma
```



**方法二：贪心算法**

罗马数字的唯一表示规则：对于罗马数字从左到右的每一位，选择尽可能大的符号值。对于 140，最大可以选择的符号值为 C=100。接下来，对于剩余的数字 40，最大可以选择的符号值为XL=40。因此，140 的对应的罗马数字为 C+XL=CXL。

因此可以将罗马数字的共13个独特符号，按从大到小顺序排列，依次找到剩余数值可以减的最大值。

代码待补充

