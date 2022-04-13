class Solution {
  unordered_map<int,int> map;
  vector<int> temp;
  
//   int max_length(vector<int> A, vector<int> temp, int i)
//   {
//     if (i == A.size())
//       return temp.size();
    
//     if (temp.size() < 2)
//     {
//       int option1 = max_length(A,temp,i+1);
//       temp.push_back(A[i]);
//       int option2 = max_length(A,temp,i+1);
//       return max(option1,option2);
//     }
//     else if (A[i] == temp[temp.size()-1] + temp[temp.size()-2])
//     {
//       int option1 = max_length(A,temp,i+1);
//       temp.push_back(A[i]);
//       int option2 = max_length(A,temp,i+1);
//       return max(option1,option2);
//     }
//     return max_length(A,temp,i+1);
      
//   }
  
  int max_length1(int i, int j)
  {
    int sum = temp[i] + temp[j];
    int prev1 = temp[j];
    int prev2 = temp[i];
    int count=  2;
    while (map.find(sum) != map.end())
    {
      prev2 = prev1;
      prev1 = sum;
      sum = prev2 + prev1;
      count++;
    }
    // cout << count << "    " << i << "     " << j << endl;
    return count;
  }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
      
      temp = vector<int>(arr.begin(),arr.end());
      for (int i = 0; i < arr.size(); i++)
        map[arr[i]] = i;
      
      int answer = INT_MIN;
      for (int i = 0; i < arr.size(); i++)
        for (int j = i+1; j < arr.size(); j++)
          answer  = max(answer,max_length1(i,j));
      return (answer > 2) ? answer : 0;
    }
};