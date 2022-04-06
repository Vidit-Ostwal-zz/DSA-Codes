class Solution {
  int mini = INT_MAX;
  int diff = INT_MAX;
  
  void check_all (vector<int> ToC, int target, int pre, int index,int count)
  {
    // cout << pre << endl;
    if (index == ToC.size() || pre >= target)
    {
      if (abs(pre-target) <= diff)
      {
        if (pre - target == diff)
          mini = min (mini,pre);
        else
          mini = pre;
          
        diff = abs(pre-target);
      }
      return;
    }
    
    if (abs(pre-target) <= diff)
      {
       
      if (pre - target == diff)
          mini = min (mini,pre);
        else
          mini = pre;
      
       diff = abs(pre-target);
      }
    
    if (count < 2)
      check_all(ToC,target,pre+ToC[index],index,count+1);
    
     check_all(ToC,target,pre,index+1,0);
  }
  
  
  void check_all1(vector<int> ToC, int target, int pre, int index)
  {
    if (index == ToC.size() || pre >= target)
    {
      if (abs(pre-target) < diff)
      {
        diff = abs(pre-target);
        mini = pre;
      }
      return;
    }
    
    check_all1(ToC,target,pre+ToC[index],index);
    check_all1(ToC,target,pre,index+1);
  }
public:
    int closestCost(vector<int>& baseCost, vector<int>& toppingCosts, int target) {
        
      for (int i = 0; i < baseCost.size(); i++)
      {
        check_all (toppingCosts,target, baseCost[i],0,0);
        // check_all1 (toppingCosts,target, baseCost[i],0);
      }
      return mini;
    }
};