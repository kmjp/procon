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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		map<int,int> M;
		FORR(a,matches) M[a[0]]+=0,M[a[1]]+=1;
		
		vector<int> A,B;
		FORR(a,M) {
			if(a.second==0) A.push_back(a.first);
			if(a.second==1) B.push_back(a.first);
		}
		return {A,B};
    }
};
