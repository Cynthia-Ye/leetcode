
def maxDistance(nums1, nums2) -> int:
    if not nums1 or not nums2:
        return 0
    imin = -1
    for i in range(len(nums1)):
        if nums1[i] > nums2[-1]:
            imin = i
        else:
            break
    imin += 1
    maxdiff = len(nums2) - 1 - imin
    for j in range(len(nums2) - 2, -1, -1):
        for i in range(imin - 1, -1, -1):
            if nums1[i] <= nums2[j]:
                imin = i
            else:
                continue
        if imin < 0:
            break
        maxdiff = max(maxdiff, j - imin)
    return max(maxdiff, 0)


nums1 = [2,2,2]
nums2 = [10,10,1]
maxDistance(nums1, nums2)

'''
[55,30,5,4,2]
[100,20,10,10,5]
[2,2,2]
[10,10,1]
[30,29,19,5]
[25,25,25,25,25]
'''
'''
class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        def dfs(offset, nums1, nums2):
            if (nums1[-1] > nums2[0]):
                return 0
            if nums1[0] <= nums2[-1]:
                return len(nums2) - 1 - offset
            if len(nums1) == 1 and len(nums2) == 1:
                return 0
            elif len(nums1) == 1:
                return dfs(offset, nums1, nums2[0:-1])
            elif len(nums2) == 1:
                return dfs(offset + 1, nums1[1:], nums2)
            newnums1 = nums1[1:]
            newnums2 = nums2[0:-1]
            return max(dfs(offset + 1, newnums1, nums2), dfs(offset, nums1, newnums2))
        
        if not nums1 or not nums2:
            return 0
        return dfs(0, nums1, nums2)

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        if not nums1 or not nums2:
            return 0
        imin = -1
        for i in range(len(nums1)):
            if nums1[i] <= nums2[-1]:
                imin = i
            else:
                break
        if imin < 0:
            return 0
        maxdiff = len(nums2) - 1 - imin
        for j in range(len(nums2) - 2, -1, -1):
            for i in range(imin - 1, -1, -1):
                if nums1[i] <= nums2[j]:
                    imin = i
                else:
                    continue
            if imin < 0:
                break
            maxdiff = max(maxdiff, j - imin)
        return maxdiff
'''