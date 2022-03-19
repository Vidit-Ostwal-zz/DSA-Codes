class TopVotedCandidate {
  vector<int> persons;
  vector<int> times;
  vector<int> answer;
  
  int maxi;
  int max_vote = 0;
  unordered_map<int,int> map;
  
public:
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   if (nums[mid] == target)
    return mid;
    
   if (nums[mid] > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return ed;
}
  
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this ->persons = vector<int> (persons.begin(),persons.end());
      this -> times = vector<int> (times.begin(),times.end());
      
      /*Answer Vector*/
      for (int i = 0; i < times.size(); i++)
      {
        map[persons[i]]++;
        
        if (map[persons[i]] >= max_vote)
        {
          max_vote = map[persons[i]];
          maxi = persons[i];
        }
        answer.push_back(maxi);
      }
    }
    
    int q(int t) {
      int temp = Binary_Search(times,0,times.size()-1,t);
        return answer[temp];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */