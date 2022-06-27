

class Solution {
  static bool comparator(vector<int> A, vector<int> B)
  {
    return A[1] <= B[1];
  }
  
  struct Node {
  Node* arr[2];
  int value = 0;
  
  bool checkbit(int bit)
  {
    return arr[bit] != NULL;
  }
  
  Node* nextnode(int bit)
  {
    return arr[bit];
  }
  
  void setbit(int bit)
  {
    arr[bit] = new Node();
  }
};

void insert(Node* Root, int n)
{
  Node* temp = Root;
  
  for (int i = 32; i > 0; i--)
  {
    int curr_bit = ((n >> (i-1)) & 1);
    
    if (!temp -> checkbit(curr_bit))
      temp -> setbit(curr_bit);
    
    temp = temp -> nextnode(curr_bit);
  }
  temp -> value = n;
}

int max_xor (Node* Root, int n)
{
  Node* temp = Root;
  int Xor = 0;
  for (int i = 32; i > 0;i--)
  {
    int curr_bit = ((n >> (i-1)) & 1);
    
    curr_bit = (curr_bit) ? 0 : 1;
    
    if (temp -> checkbit(curr_bit))
    {
      Xor = 2*Xor + 1;
      temp = temp -> nextnode(curr_bit);
    }
    else if (temp -> checkbit(!curr_bit))
    {
      Xor = 2*Xor;
      temp = temp -> nextnode(!curr_bit);
    }
    else
    {
      return n ^ temp -> value;
    }
  }
  return Xor;
}
  
   void show_vector(vector<vector<int>> vect)
{
  cout << "Printing Vector" << endl;
  cout <<" ---------------" << endl;
 for (int i = 0; i < vect.size(); i++)
 {
  for (int j = 0; j < vect[0].size(); j++)
   cout << vect[i][j] << " ";
  cout << endl;
 }
  cout << "Ending Vector" << endl;
   }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      
      for (int i = 0; i < queries.size(); i++)
      {
        int temp = queries[i][0];
        queries[i][0] = queries[i][1];
        queries[i][1] = temp;
        queries[i].push_back(i);
      }
      
      sort(nums.begin(),nums.end());
      sort(queries.begin(),queries.end());
          
        // show_vector(queries);
       // cout << "Here" << endl;
      vector<int> final_answer(queries.size(),0);
      Node* Root = new Node();
      
      int j = 0;
      
      int flag = false;
      for (int i = 0; i < queries.size(); i++)
      {
        while (j < nums.size() && nums[j] <= queries[i][0])
        {
          insert(Root,nums[j]);
          flag = true;
          j++;
        }
          final_answer[queries[i][2]] = (flag) ? max_xor(Root,queries[i][1]) : -1 ;
      }
      return final_answer;
    }
};