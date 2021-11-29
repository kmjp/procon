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
    int countWords(vector<string>& words1, vector<string>& words2) {
		map<string,int> M1,M2;
		FORR(a,words1) M1[a]++;
		FORR(a,words2) M2[a]++;
		int ret=0;
		FORR(a,M1) if(a.second==1&&M2[a.first]==1) ret++;
		return ret;
        
    }
};
