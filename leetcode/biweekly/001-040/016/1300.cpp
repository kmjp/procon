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
    int findBestValue(vector<int>& arr, int target) {
		map<int,int> M;
		ll S=0;
		FORR(a,arr) {
			M[a]++;
			S+=a;
		}
		
		ll val=1LL<<60;
		int cur=0;
		int hoge=0;
		int ret=0,i;
		for(i=100000;i>=0;i--) {
			if(M.count(i)) {
				hoge+=M[i];
				S-=1LL*M[i]*i;
				M.erase(i);
			}
			
			if(abs(target-(S+hoge*i))<=val) {
				val=abs(target-(S+hoge*i));
				ret=i;
			}
			
		}
		return ret;
		
        
    }
};
