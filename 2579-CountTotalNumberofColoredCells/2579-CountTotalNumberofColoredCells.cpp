class Solution {
public:
    long long coloredCells(int n) {
       long long int res=5;
       if(n<=1)return n;
       if(n==2)return 5;
       int i=3;
       while(i<=n){
        res= res+(4*(i-1));
        i++;
       }
       return res;
    }
};