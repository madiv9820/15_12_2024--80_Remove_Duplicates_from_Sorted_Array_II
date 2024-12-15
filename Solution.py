from typing import List
from collections import Counter

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Step 1: Count the occurrences of each number in the list using Counter
        num_Count = Counter(nums)
        
        # Step 2: Create an empty list to store the updated list of numbers
        extra_memory = []
        
        # Step 3: Iterate through each unique number in nums (using set to avoid duplicates)
        for num in set(nums):
            # If the number appears more than once, add it twice to extra_memory
            if num_Count[num] > 1: extra_memory += [num] * 2  # Add the number twice if it appears more than once
            else: extra_memory += [num]  # If the number appears only once, add it once
        
        # Step 4: Copy the elements from extra_memory back to nums
        for index in range(len(extra_memory)): nums[index] = extra_memory[index]
        
        # Step 5: Return the length of the modified nums list (which is stored in extra_memory)
        return len(extra_memory)