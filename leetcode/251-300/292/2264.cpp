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
    string largestGoodInteger(string num) {
		string S="";
		int i;
		FOR(i,num.size()-2) {
			string T=num.substr(i,3);
			if(T[0]!=T[1]) continue;
			if(T[0]!=T[2]) continue;
			S=max(S,T);
		}
    return S;
        
    }
};
