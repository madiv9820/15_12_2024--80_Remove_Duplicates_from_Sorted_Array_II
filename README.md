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
                    # We iterate through the sorted items of num_Count so that the numbers are placed in sorted order
                    for num, freq in sorted(num_Count.items()):
                        # If the number appears more than once, add it twice to extra_memory
                        if freq > 1: extra_memory += [num] * 2  # Add the number twice if it appears more than once
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
            - Counting the frequencies using the `map` takes **$O(n*log(n))$** time because inserting an element into a `map` takes **$O(log(n)$** time, and we perform this operation for each of the $n$ elements in `nums`.
            - Building the `extra_memory` array by iterating over the `map` takes **$O(n)$** time, as we iterate through each unique number and its frequency.

        Overall, the time complexity is dominated by the **$O(n*log(n))$** due to the use of the `map`.

    - ### Space Complexity:
        - **$O(n)$**:
            - The `map` stores the frequency of each number, which takes **$O(n)$** space in the worst case when all numbers are unique.
            - The `extra_memory` vector also stores the result array, which takes **$O(n)$** space in the worst case.

        Thus, the space complexity is **$O(n)$** due to the additional space used by the `map` and `extra_memory`.