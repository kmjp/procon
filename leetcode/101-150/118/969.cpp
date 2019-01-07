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
    vector<int> pancakeSort(vector<int>& A) {
		int N=A.size();
		vector<int> R;
		int i,j;
        for(i=N;i>=1;i--) {
			if(A[i-1]==i) continue;
			FOR(j,N) if(A[j]==i) break;
			if(j!=0) {
				R.push_back(j+1);
				reverse(A.begin(),A.begin()+j+1);
			}
			R.push_back(i);
			reverse(A.begin(),A.begin()+i);
		}
		return R;
        
    }
};
