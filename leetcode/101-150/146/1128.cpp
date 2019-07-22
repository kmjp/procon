
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
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int num[10][10]={};
        ll ret=0;
        FORR(d,dominoes) {
			int a=min(d[0],d[1]);
			int b=max(d[0],d[1]);
			ret+=num[a][b];
			num[a][b]++;
		}
		return ret;
    }
};

