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


int C[1010];
int K[1010];
int did[1010];
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int N=status.size();
        ZERO(C);
        ZERO(did);
        int i;
        FOR(i,N) K[i]=status[i];
        queue<int> Q;
        FORR(i,initialBoxes) {
			C[i]=1;
			if(K[i]==1) did[i]=1, Q.push(i);
		}
		int ret=0;
		while(Q.size()) {
			int x=Q.front();
			Q.pop();
			ret+=candies[x];
			
			FORR(c,containedBoxes[x]) {
				C[c]=1;
				if(K[c]==1 && did[c]==0) {
					did[c]=1;
					Q.push(c);
				}
			}
			FORR(c,keys[x]) {
				K[c]=1;
				if(C[c]==1 && did[c]==0) {
					did[c]=1;
					Q.push(c);
				}
			}
		}
		return ret;
        
    }
};
