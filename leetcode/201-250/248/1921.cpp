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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		vector<double> V;
		int i;
		FOR(i,dist.size()) {
			V.push_back(dist[i]*1.0/speed[i]);
		}
		sort(ALL(V));
		FOR(i,V.size()) {
			if(V[i]<=i) return i;
		}
		return V.size();
        
    }
};
