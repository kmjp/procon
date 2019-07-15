
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

ll from[1<<16],to[1<<16];

class Solution {
public:

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		int T=req_skills.size();
		int N=people.size();
		map<string,int> M;
		
		int i,j;
		FOR(i,T) M[req_skills[i]]=1<<i;
		
		FOR(i,1<<T) from[i]=-1LL;
		from[0]=0;
		
		FOR(i,N) {
			int mask=0;
			FORR(s,people[i]) mask |= M[s];
			
			FOR(j,1<<T) {
				ll ns=j | mask;
				ll np=from[j] | (1LL<<i);
				
				if(__builtin_popcountll(np)<__builtin_popcountll(from[ns])) {
					from[ns]=np;
				}
			}
		}
		
		vector<int> R;
		FOR(i,N) if(from[(1<<T)-1] & (1LL<<i)) R.push_back(i);
		return R;
        
    }    
};

