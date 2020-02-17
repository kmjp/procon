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
    bool isPossible(vector<int>& target) {
		int N=target.size();
		ll S=0;
		map<int,int> M;
		FORR(t,target) {
			M[t]++;
			S+=t;
		}
		while(M.rbegin()->first>1) {
			int t=M.rbegin()->first;
			ll p=t-(S-t);
			if(p<=0) return 0;
			M[t]--;
			if(M[t]==0) M.erase(t);
			M[p]++;
			S-=(t-p);
		}
		
		return (M[1]==N);
    }
};


