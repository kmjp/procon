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
    int connectSticks(vector<int>& sticks) {
		multiset<int> M;
		FORR(a,sticks) M.insert(a);
		ll ret=0;
		while(M.size()>1) {
			int a=*M.begin();
			M.erase(M.begin());
			int b=*M.begin();
			M.erase(M.begin());
			ret+=a+b;
			M.insert(a+b);
			
		}
        return ret;
    }
};
