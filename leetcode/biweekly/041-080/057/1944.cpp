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
    vector<int> canSeePersonsCount(vector<int>& heights) {
		vector<int> S,ret;
		reverse(ALL(heights));
		FORR(c,heights) {
			int rem=0;
			while(S.size()&&S.back()<c) S.pop_back(), rem++;
			if(S.size()) rem++;
			ret.push_back(rem);
			
			S.push_back(c);
		}
        reverse(ALL(ret));
        return ret;
    }
};

