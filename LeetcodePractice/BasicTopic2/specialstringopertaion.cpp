class Solution {
public:
    char processStr(string s, long long k) {
        int n= s.length();
        long long l=0;
        for(char c: s){
            if(c=='*'){
                if(l>0)l--;
            }else if(c=='#'){
                l*=2;
            }else if(c=='%')continue;
            else {
                l++;
            }
        }
        if(k>=l)return '.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                l++;
            }else if(s[i]=='%'){
                k=l-k-1;
            }else if(s[i]=='#'){
                l=l/2;
                k=(k>=l)?k-l:k;
            }else{
                l--;
            }
            if(k==l)return s[i];
        }
        return '.';
    }
};