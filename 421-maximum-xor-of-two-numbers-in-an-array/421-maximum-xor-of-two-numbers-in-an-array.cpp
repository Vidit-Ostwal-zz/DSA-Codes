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

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
      if (nums.size() <= 1)
        return 0;
      
      Node* Root = new Node();
      insert(Root, nums[0]);
      
      int answer =  INT_MIN;
      
      for (int i = 1; i < nums.size(); i++)
      {
         // cout << "Here" << endl;
        answer = max(answer,max_xor(Root,nums[i]));
        insert (Root,nums[i]);
      }
      return answer;
      
    }
};