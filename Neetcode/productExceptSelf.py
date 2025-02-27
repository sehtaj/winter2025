# purpose: to compute the product of all the elements in the array except self
# list[int]) -> List[int]

#Time complexity: O(n)
#Space complexity: O(n)
def productExceptSelf(nums):


    product = 1
    zero_count = 0

    for num in nums:
        if num != 0:
            product *= num
        else:
            zero_count += 1

    output = []
    for i in range(0, len(nums)):
        if zero_count > 1:
            output.append(0)  
        elif zero_count == 1:
            if nums[i] == 0:
                output.append(product)
            else:
                output.append(0) 
        else:
            output.append(product // nums[i])  

    return output

# edge cases
# print(productExceptSelf([1, 2, 0, 4])) 
# print(productExceptSelf([0, 0, 2, 3]))  
# print(productExceptSelf([1, 2, 0, 4]))  
# print(productExceptSelf([0, 0, 2, 3]))  
# print(productExceptSelf([10]))  
# print(productExceptSelf([0]))   
# print(productExceptSelf([-1, 2, -3, 4])) 