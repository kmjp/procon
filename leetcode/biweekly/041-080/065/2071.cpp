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
	vector<int> T,W;
	int P,S;
	int ok(int v) {
		multiset<int> Q[2];
		int i;
		if(v>W.size()||v>T.size()) return 0;
		FOR(i,v) Q[1].insert(W[i]);
		int p=P;
		FOR(i,v) {
			int t=T[v-1-i];
			while(Q[1].size()&&*Q[1].rbegin()>=t) {
				Q[0].insert(*Q[1].rbegin());
				Q[1].erase(Q[1].find(*Q[1].rbegin()));
			}
			
			if(Q[0].size()) {
				Q[0].erase(Q[0].begin());
			}
			else {
				if(p==0) return 0;
				p--;
				auto it=Q[1].lower_bound(t-S);
				if(it==Q[1].end()) return 0;
				Q[1].erase(it);
			}
		}
		return 1;
	}
	
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        T=tasks;
        W=workers;
        P=pills;
        S=strength;
        
        sort(ALL(T));
        sort(ALL(W));
        reverse(ALL(W));
        int ma=0;
        int i;
        for(i=20;i>=0;i--) if(ok(ma+(1<<i))) ma+=1<<i;
        return ma;
    }
};
