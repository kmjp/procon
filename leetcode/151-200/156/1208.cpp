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
    int equalSubstring(string s, string t, int maxCost) {
		
		vector<int> C;
		int i;
		FOR(i,s.size()) C.push_back(abs(s[i]-t[i]));
		int L,R=0,ma=0,cur=0;
		FOR(L,s.size()) {
			if(R<L) R=L,cur=0;
			while(R<s.size()&&cur+C[R]<=maxCost) cur+=C[R],R++;
			//cout<<L<<" "<<R<<" "<<cur<<endl;
			ma=max(ma,R-L);
			
			cur-=C[L];
		}
		return ma;
		
		
		
        
    }
};


