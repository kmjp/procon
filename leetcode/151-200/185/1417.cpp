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
    string reformat(string s) {
		string A,B;
		FORR(c,s) {
			if(c>='0' && c<='9') A+=c;
			else B+=c;
		}
		
		if(A.size()<B.size()) swap(A,B);
		if(A.size()>B.size()+1) return "";
		string R;
		int i;
		FOR(i,A.size()) {
			R+=A[i];
			if(i<B.size()) R+=B[i];
		}
		return R;
        
    }
};
