# [80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii?envType=study-plan-v2&envId=top-interview-150) (All Approaches)

- ## Approach 1:- Using Hashmaps

    - ### Intuition:
        The problem is to remove duplicates from the array and modify the array in place. We need to ensure that if a number appears more than once, it should appear twice in the result (if the frequency is more than 1), and if a number appears only once, it should appear once. The challenge is to do this efficiently while also modifying the original array.

        - **Key Idea**: Use a `map` (or `unordered_map`) to count the frequency of each number in the array. Then, use this frequency data to build a new version of the array where each number appears the correct number of times (i.e., at most twice).
        - We can then update the original array `nums` with the new values and return the length of the updated list.

    - ### Approach:
        1. **Count Frequencies**:
            - Use a `map<int, int>` (or `unordered_map`) to store the frequency of each number in the array `nums`. The key is the number itself, and the value is the count of its occurrences.
        
        2. **Build the Result Array**:
            - Create an empty vector `extra_memory` to store the final result with the correct number of duplicates.
            - Iterate through each unique number in the `map`:
                - If the frequency of the number is 1, add it once to `extra_memory`.
                - If the frequency of the number is greater than 1, add it twice to `extra_memory`.
        
        3. **Update the Original Array**:
            - Copy the elements from `extra_memory` back into the original array `nums` (in-place).
            - This step ensures that the original array is modified and contains the correct number of elements.

        4. **Return the Length**:
            - Return the length of the `extra_memory` array, which gives the size of the updated array.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        
        - **C++ Solution**
            ```cpp []
            class Solution {
            public:
                int removeDuplicates(vector<int>& nums) {
                    // Step 1: Create a map to count the frequency of each number in nums
                    map<int, int> num_Count;  // Key: number, Value: frequency of the number
                    
                    // Step 2: Count the occurrences of each number in the nums vector
                    for(const int& num: nums) ++num_Count[num];  // Iterate through nums and update frequency
                    
                    // Step 3: Create a vector to store the result, which will hold the modified nums
                    vector<int> extra_memory;

                    // Step 4: Iterate over the map (num_Count) to build the updated array
                    for(auto p = num_Count.begin(); p != num_Count.end(); ++p) {
                        int num = p->first;  // The number
                        int freq = p->second;  // The frequency of the number
                        
                        // Always push the number once to the extra_memory vector
                        extra_memory.push_back(num);
                        
                        // If the number appears more than once, push it again (it should appear twice)
                        if(freq > 1)  extra_memory.push_back(num);
                    }

                    // Step 5: Copy the elements from extra_memory back to the nums vector
                    for(int index = 0; index < extra_memory.size(); ++index)
                        nums[index] = extra_memory[index];  // Update the nums vector with elements from extra_memory

                    // Step 6: Return the size of the modified nums array (the number of elements in extra_memory)
                    return extra_memory.size();
                }
            };
            ```

    - ### Time Complexity:
        - **$O(n*log(n))$**: 
            - Counting the frequencies using the `map` takes **$O(n*log(n))$** time because inserting an element into a `map` takes **$O(log(n)$** time, and we perform this operation for each of the $n\ $ elements in `nums`.
            - Building the `extra_memory` array by iterating over the `map` takes **$O(n)$** time, as we iterate through each unique number and its frequency.

        Overall, the time complexity is dominated by the **$O(n*log(n))$** due to the use of the `map`.

    - ### Space Complexity:
        - **$O(n)$**:
            - The `map` stores the frequency of each number, which takes **$O(n)$** space in the worst case when all numbers are unique.
            - The `extra_memory` vector also stores the result array, which takes **$O(n)$** space in the worst case.

        Thus, the space complexity is **$O(n)$** due to the additional space used by the `map` and `extra_memory`.

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