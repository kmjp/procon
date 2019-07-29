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

int in[5050];
set<int> S[5050];



class Solution {
	public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        int i;
        FOR(i,N) {
			in[i]=0;
			S[i].clear();
		}
		FORR(r,relations) {
			S[r[0]-1].insert(r[1]-1);
			in[r[1]-1]++;
		}
		
		int did=0;
		int step=0;
		vector<int> Q;
		FOR(i,N) if(in[i]==0) Q.push_back(i);
		
		while(Q.size()) {
			did+=Q.size();
			vector<int> R;
			step++;
			FORR(q,Q) FORR(s,S[q]) if(--in[s]==0) R.push_back(s);
			swap(R,Q);
		}
		
		
		if(did<N) return -1;
		return step;
        
        
    }
};

