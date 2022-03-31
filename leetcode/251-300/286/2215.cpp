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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		set<int> A,B;
		FORR(a,nums1) A.insert(a);
		FORR(a,nums2) B.insert(a);
		vector<int> X,Y;
		FORR(a,A) if(B.count(a)==0) X.push_back(a);
		FORR(a,B) if(A.count(a)==0) Y.push_back(a);
		return {X,Y};
        
    }
};
