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



ll S[205050];
vector<int> D[402020];
vector<int> A[402020];

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int i,j;
        int N=nums.size();
        FOR(i,N) {
			S[i+1]=S[i]+nums[i];
			int x=k-nums[i]+200000;
			D[x].push_back(i);
		}
        FOR(i,402020) {
			A[i].resize(D[i].size()+1);
		}
		int ret=0;
		for(i=1;i<N;i++) {
			if(S[i]*2==S[N]) {
				ret++;
			}
			else {
				ll dif=S[N]-S[i]-S[i];
				if(abs(dif)>200000) continue;
				dif+=200000;
				if(D[dif].size()) {
					int x=lower_bound(ALL(D[dif]),i)-D[dif].begin();
					A[dif][x]--;
					A[dif][0]++;
				}
				
				dif=400000-dif;
				if(D[dif].size()) {
					int x=lower_bound(ALL(D[dif]),i)-D[dif].begin();
					A[dif][x]++;
				}
			}
		}
		FOR(i,402020) if(D[i].size()) {
			FOR(j,A[i].size()-1) {
				if(j) A[i][j]+=A[i][j-1];
				ret=max(ret,A[i][j]);
			}
			D[i].clear();
			A[i].clear();
		}
		
		
		return ret;
    }
};
