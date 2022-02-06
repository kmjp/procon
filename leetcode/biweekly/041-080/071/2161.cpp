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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int> A,B,C;
		FORR(a,nums) {
			if(a<pivot) A.push_back(a);
			if(a==pivot) B.push_back(a);
			if(a>pivot) C.push_back(a);
		}
		FORR(b,B) A.push_back(b);
		FORR(b,C) A.push_back(b);
		return A;
			
        
    }
};