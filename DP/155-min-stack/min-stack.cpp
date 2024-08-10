class MinStack {
public:
    int arr[100000];
        int i;
        int minele;
    MinStack() {
         i=-1;
         minele=INT_MAX;
        
    }
    
    void push(int val) {
         i++;
        arr[i]=val;
       
       minele=min(minele,val);
        
    }
    
    void pop() {
        if(arr[i]==minele){
             int  newminele=INT_MAX;
            for(int k=0;k<i;k++){
                cout<<arr[k]<<"*"<<endl;
                newminele=min(newminele,arr[k]);  
            }
            minele=newminele;
        }
       
        i=i-1;
        
    }
    
    int top() {
        return arr[i];
    }
    
    int getMin() {
        return minele;
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