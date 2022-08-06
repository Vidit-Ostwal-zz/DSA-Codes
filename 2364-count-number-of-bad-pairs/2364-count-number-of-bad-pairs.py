class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
      
      length = len(nums)
      
      for j in range(length):
        nums[j] -= j
      
      # print(nums)
      
      Dict = defaultdict(int)
      
      count = 0
      
      for i in range(length):
        count += Dict[nums[i]]
        Dict[nums[i]] += 1
      
      return int((length*(length-1))/2 - count)
      
        