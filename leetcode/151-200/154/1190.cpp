
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Solution {
public:
    string reverseParentheses(string s) {
		int i,j;
		FOR(i,s.size()) {
			if(s[i]=='(') {
				j=i;
			}
			if(s[i]==')') {
				string T,U;
				U=s.substr(j+1,i-j-1);
				reverse(ALL(U));
				T=s.substr(0,j)+U+s.substr(i+1);
				return reverseParentheses(T);
				
				
			}
		}
		return s;
		
        
    }
};
