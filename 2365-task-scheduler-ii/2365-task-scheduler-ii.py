class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        Dict = defaultdict(int)
        time = 1
        for i in tasks:
          d = int(Dict[i])
          time = max(time,d)
          Dict.update({i : time + space + 1}) 
          time += 1
        
        return time-1
          