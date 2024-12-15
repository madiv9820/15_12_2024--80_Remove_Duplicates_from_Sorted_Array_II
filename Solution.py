from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Initialize two pointers: actual_Index to track the position of the modified array,
        # index to iterate through the original array
        actual_Index, index, n = 0, 0, len(nums)

        # Step 1: Iterate through the array
        while index < n:
            # Step 2: Always place the current element at actual_Index and move actual_Index forward
            nums[actual_Index] = nums[index]
            actual_Index += 1  # Increment actual_Index to store the next element in the modified array
            
            # Step 3: If the next element is the same as the current one, place it again
            if index + 1 < n and nums[index] == nums[index + 1]:
                nums[actual_Index] = nums[index]  # Place the duplicate element
                actual_Index += 1  # Move actual_Index forward

            # Step 4: Move the index forward to skip over all the duplicate elements
            # Find the first element that is different from the current element
            tempIndex = index + 1
            while tempIndex < n and nums[tempIndex] == nums[index]:
                tempIndex += 1  # Skip over duplicates of the current number

            # Step 5: Update the main index to point to the first different element
            index = tempIndex

        # Step 6: Return the length of the modified array (number of valid elements)
        return actual_Index