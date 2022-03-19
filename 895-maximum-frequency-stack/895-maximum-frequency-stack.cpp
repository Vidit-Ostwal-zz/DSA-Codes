class FreqStack {
  unordered_map<int,int> map1;
  unordered_map<int,stack<int>> map2;
  int max_freq = 0;
public:
    FreqStack() {
      
    }
    
    void push(int val) {
      map1[val]++;
      
      int curr_freq = map1[val];
      map2[curr_freq].push(val);
      
      if (curr_freq > max_freq)
        max_freq = curr_freq;
    }
    
    int pop() {
        int answer = map2[max_freq].top();
      map2[max_freq].pop();
      
      map1[answer]--;
      
      if (map2[max_freq].size() == 0)
        max_freq--;
      
      return answer;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */