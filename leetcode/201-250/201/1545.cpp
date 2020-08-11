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
    char findKthBit(int n, int k) {
		string S="0";
		while(n>1) {
			n--;
			string T=S;
			S+="1";
			int i;
			FOR(i,T.size()) S+=T[T.size()-1-i]^1;
		}
        return S[k-1];
    }
};
