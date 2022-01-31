class Solution {
  /*
  int recursive_solution(vector<int> values, int index, int prev_answer)
  {
    if (index == values.size())
      return 0;
    
    /*At a given value of the index, certain decision needs to be taken
    Stop Right there 
    int temp1 = prev_answer+values[index]-index;
    int temp2 = recursive_solution(values,index+1,prev_answer);
    int temp3 = recursive_solution(values,index+1,values[index]+index);
    
    return max(temp1,max(temp2,temp3));
  }*/
  
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    int st = values[0];
      int answer = -1;
      
      for (int i = 1; i < values.size(); i++)
      {
        answer = max(answer,st + values[i]-i);
        st = max(st,values[i]+i);
      }
      return answer;
    }
};