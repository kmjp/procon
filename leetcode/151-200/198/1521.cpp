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


int nex[1<<20][20];

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
		int N=arr.size();
		int i,j;
		FOR(i,20) {
			nex[N][i]=N;
			for(j=N-1;j>=0;j--) {
				nex[j][i]=nex[j+1][i];
				if((arr[j]&(1<<i))==0) nex[j][i]=j+1;
			}
		}
        int ret=1<<30;
        FOR(i,N) {
			int cur=(1<<20)-1;
			int j=i,x;
			while(j<N) {
				int ne=N;
				FOR(x,20) if(cur&(1<<x)) ne=min(ne,nex[j][x]);
				if(ne==N) break;
				cur&=arr[ne-1];
				ret=min(ret,abs(cur-target));
				j=ne;
			}
		}
        
        
        return ret;
    }
};

