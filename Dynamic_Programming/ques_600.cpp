//solution of 0 ms best case 
class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(32);
        fib[0] = 1;
        fib[1] = 2;
        for(int i = 2;i<32;i++)
        fib[i]=fib[i-1]+fib[i-2];
        

        int ans = 0;
        int prevbit = 0;

        for(int i=30;i>=0;i--){
            int currbit = (n>>i)&1;
            if(currbit==1){
                ans+=fib[i];
                if(prevbit==1){
                    return ans;
                    }
                }
            prevbit=currbit;
            }
        return ans+1; 
    }
};