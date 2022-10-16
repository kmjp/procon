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
    int findMaxK(vector<int>& nums) {
		set<int> S;
		int ma=-1;
		FORR(n,nums) if(n<0) S.insert(-n);
		FORR(n,nums) if(n>0&&S.count(n)) ma=max(ma,n);
		return ma;
        
    }
};
