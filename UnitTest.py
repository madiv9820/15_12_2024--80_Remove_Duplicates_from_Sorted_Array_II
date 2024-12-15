from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testcases = {1: ([1,1,1,2,2,3], 5, [1,1,2,2,3]),
                            2: ([0,0,1,1,1,1,2,3,3], 7, [0,0,1,1,2,3,3]),
                            3: ([-1,0,0,0,0,3,3], 5, [-1,0,0,3,3])}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_case_1(self):
        nums, n, output = self.__testcases[1]
        result = self.__obj.removeDuplicates(nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, n)
        nums = nums[:n]
        self.assertTrue(all(n == o for n,o in zip(nums, output)))

    @timeout(0.5)
    def test_case_2(self):
        nums, n, output = self.__testcases[2]
        result = self.__obj.removeDuplicates(nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, n)
        nums = nums[:n]
        self.assertTrue(all(n == o for n,o in zip(nums, output)))

    @timeout(0.5)
    def test_case_3(self):
        nums, n, output = self.__testcases[3]
        result = self.__obj.removeDuplicates(nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, n)
        nums = nums[:n]
        self.assertTrue(all(n == o for n,o in zip(nums, output)))

if __name__ == '__main__': unittest.main()