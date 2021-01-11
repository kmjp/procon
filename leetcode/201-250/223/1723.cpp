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

int S[1<<12];

int from[1<<12],to[1<<12];

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
		int N=jobs.size();
		int i,mask;
		FOR(mask,1<<N) {
			S[mask]=0;
			FOR(i,N) if(mask&(1<<i)) S[mask]+=jobs[i];
			from[mask]=1<<30;
		}
		
		from[0]=0;
		while(k--) {
			FOR(mask,1<<N) to[mask]=1<<30;
			FOR(mask,1<<N) if(from[mask]<1<<30) {
				int cand=mask^((1<<N)-1);
				for(int sm=cand; sm>0; sm=(sm-1)&cand) {
					to[mask|sm]=min(to[mask|sm],max(from[mask],S[sm]));
				}
			}
			
			swap(from,to);
		}
		
		return from[(1<<N)-1];
        
    }
};

