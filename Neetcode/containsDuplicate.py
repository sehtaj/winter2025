#Input: A list of integers (nums).
#Output: A boolean (True if duplicates exist, otherwise False).

#The function iterates through the list, storing elements in a dictionary (seen). 
# If an element is already in the dictionary, it means a duplicate exists, and we return True.
# Otherwise, we store the element and continue.

# Time complexity: O(n)
# Space complexity: O(n)

def containsDuplicate(nums):
    seen = {}
    for num in nums:
        if num in seen:
            return True
        seen[num] = True
    return False




