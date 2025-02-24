def topKFrequent(nums,k):

# Purpose: returns the top k most frequent elements in an array
# topKFrequent: List[int], int -> List[int]

# Time complexity: O(nlogn)
# Space complexity: O(n)    

    seen = {}

    for item in nums:
        if item in seen:
            seen[item] += 1
        else:
            seen[item] = 1

    sorted_nums = sorted(seen.keys(), key=lambda x: seen[x], reverse=True)

    result = []
    for i in range(k):
        result.append(sorted_nums[i])  

    return result 


#edge cases
#print(topKFrequent([1, 1, 2, 2, 3, 3], 2))  #Expected Output: [1, 2] 
#print(topKFrequent([4, 4, 4, 6, 6, 2, 2, 2, 1], 3))  # Expected Output: [4, 2, 6] 
#print(topKFrequent([], 2))  #Expected Output []
#print(topKFrequent([5, 5, 5, 5], 2))  #Expected Output [5]
        
