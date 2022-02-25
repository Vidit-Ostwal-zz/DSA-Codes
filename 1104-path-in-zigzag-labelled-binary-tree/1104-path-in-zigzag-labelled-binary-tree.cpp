class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
      vector<vector<int>> final_vector;
      
      int size = log10(label)/log10(2);
      
      int i = 0;
      bool flag =true;
      while ( i <= size)
      {
        int st = pow(2,i);
        int ed = pow(2,i+1);
        i++;
        
        vector<int> temp;
        while (st < ed)
        {
          temp.push_back(st);
          st++;
        }
        if (!flag)
          reverse(temp.begin(),temp.end());
        flag = !flag;
        final_vector.push_back(temp);
      }
      
      vector<int> answer;
      int index = find(final_vector[final_vector.size()-1].begin(),final_vector[final_vector.size()-1].end(),label) - final_vector[final_vector.size()-1].begin();
      answer.push_back(final_vector[final_vector.size()-1][index]);
      int i1 = final_vector.size()-2;
      
      while ( i1 >= 0)
      {
        answer.push_back(final_vector[i1][index/2]);
        index = index/2;
        i1--;
      }
      reverse(answer.begin(),answer.end());
      return answer;
    }
};