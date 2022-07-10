class SmallestInfiniteSet {
  int j = 1;
  priority_queue<int,vector<int>,greater<int>> pq;
  unordered_map<int,int>mapp;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
      int option1 = INT_MAX;  
      
      if (!pq.empty())
        option1 = pq.top();
      int option2 = j;
      
      if (option1 < option2)
      {
        pq.pop();
        mapp[option1]--;
        return option1;
      }
      return j++;
          
    }
    
    void addBack(int num) {
      
      if (j <= num)
        return;
      
      if (mapp[num])
        return;
      
      pq.push(num);
      mapp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */