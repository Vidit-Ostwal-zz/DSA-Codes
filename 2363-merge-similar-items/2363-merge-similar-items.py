class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
      Dict = defaultdict(int)
      for list in items1:
        Dict[list[0]] += list[1]
      
      for list in items2:
        Dict[list[0]] += list[1]
      
      List = []
      
      for key,value in Dict.items():
        List.append([key,value])
        
      List.sort()
      return List
        
        