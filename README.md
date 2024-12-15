- ## Approach 2:- Two Pointers

    - ### Intuition:
        The goal is to modify the `nums` array in-place such that each number appears at most twice. The key intuition is to iterate over the array, place each element in the correct position in the array, and ensure that no more than two duplicates of any element are placed.

        We can solve this problem by using two pointers:
        1. **`index`**: This pointer iterates through the original array.
        2. **`actual_Index`**: This pointer keeps track of where the next valid number should be placed in the array.

        #### Key Points:
        - If a number appears more than twice, only the first two occurrences should remain.
        - Use the `index` pointer to scan through the array, and use the `actual_Index` pointer to place the elements in their final positions.
        - After placing each element, skip any duplicate elements in the array to ensure we don't re-process them.

    - ### Approach:
        1. **Initialize Two Pointers**:
            - `actual_Index`: A pointer that will keep track of where the next valid number should be placed in the `nums` array.
            - `index`: A pointer that will iterate through the original array.

        2. **Iterate through the array**:
            - For each element at `nums[index]`, copy it to `nums[actual_Index]` and increment `actual_Index`.
        
        3. **Handle Duplicates**:
            - If the next element `nums[index + 1]` is equal to `nums[index]`, copy the element again at `nums[actual_Index]` and increment `actual_Index`.
        
        4. **Skip Over Duplicates**:
            - Use a temporary pointer `tempIndex` to skip over all duplicate elements in the array.
            - Set `index = tempIndex` to move `index` to the next unique number.

        5. **Return the Length of the Modified Array**:
            - After processing all elements, the number of valid elements will be stored in `actual_Index`, which is then returned as the result.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```

        - **C++ Solution**
            ```cpp []
            class Solution {
            public:
                int removeDuplicates(vector<int>& nums) {
                    // Step 1: Initialize two pointers: actual_Index to track where we will place the modified elements
                    // and index to iterate through the original array.
                    int actual_Index = 0, index = 0, n = nums.size();

                    // Step 2: Iterate through the array while the index is less than the length of the array
                    while (index < n) {
                        // Step 3: Place the current element at actual_Index and move actual_Index forward
                        nums[actual_Index] = nums[index];
                        ++actual_Index;  // Increment actual_Index to point to the next available position

                        // Step 4: If the next element is the same as the current element, place it again at actual_Index
                        if (index + 1 < n && nums[index] == nums[index + 1]) {
                            nums[actual_Index] = nums[index];  // Place the duplicate element
                            ++actual_Index;  // Move actual_Index forward
                        }

                        // Step 5: Skip all the duplicate elements by finding the next unique element
                        int tempIndex = index + 1;
                        while (tempIndex < n && nums[tempIndex] == nums[index]) 
                            ++tempIndex;  // Move tempIndex forward until a different number is found
                        
                        // Step 6: Move the main index to the next unique element
                        index = tempIndex;
                    }

                    // Step 7: Return the length of the modified array
                    return actual_Index;
                }
            };        
            ```

    - ### Time Complexity:
        - **$O(n)$**: The `index` pointer iterates over the array exactly once, and for each element, we only need to check the next one (if it's a duplicate). Skipping duplicates happens in linear time. Therefore, the time complexity is **$O(n)$**, where $n$ is the length of the `nums` array.

    - ### Space Complexity:
        - **$O(1)$**: The algorithm modifies the array in-place without using extra space for another data structure (apart from a few integer variables like `index`, `actual_Index`, and `tempIndex`). Hence, the space complexity is **$O(1)$**.