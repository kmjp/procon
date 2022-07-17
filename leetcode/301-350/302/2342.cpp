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
    int maximumSum(vector<int>& nums) {
        int ret=-1;
        map<int,int> M;
        FORR(v,nums) {
			int x=v,y=0;
			while(x) {
				y+=x%10;
				x/=10;
			}
			if(M.count(y)) ret=max(ret,M[y]+v);
			M[y]=max(M[y],v);
			
		}
		return ret;
    }
};
