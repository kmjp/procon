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
    vector<int> arrayRankTransform(vector<int>& arr) {
		map<int,int> M;
		FORR(a,arr) M[a]=0;
		int x=1;
		FORR(m,M) m.second=x++;
		FORR(a,arr) a=M[a];
		return arr;
        
    }
};
