class MinStack {
public:
    vector<int> class_vector;
    MinStack() {
        
    }
    
    void push(int val) {
        class_vector.push_back(val);
    }
    
    void pop() {
        class_vector.erase(class_vector.end()-1);
    }
    
    int top() {
        return class_vector[class_vector.size()-1];
    }
    
    int getMin() {
        int min = INT_MAX;
      for (int i = 0 ; i < class_vector.size();i++)
      {
        if (class_vector[i] < min)
        {
          min = class_vector[i];
        }
      }
      return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */