# twoSum() return indices of the two numbers such that they add up to a specific target.
#twoSum: List[int], int -> List[int]
#Time complexity: O(n)
#Space complexity: O(n)

def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        diff = target - num
        if diff in seen:
            return [seen[diff], i]
        seen[num] = i
    return []    

#edge cases

#twoSum([2,7,11,15], 9) 
#twoSum([3,2,4], 6) 
#twoSum([3,3], 6) 
#twoSum([2,7,11,15], 26) 
#twoSum([2,7,11,15], 17) 