
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

int N;
int A[20202];
vector<int> B;
int C[20202];
int S[20202][202];

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
		int i,x;
		ZERO(C);
		ZERO(S);
		N=arr.size();
		FOR(i,N) {
			A[i]=arr[i];
			C[A[i]]++;
		}
		B.clear();
		FOR(i,20002) if(C[i]>100) B.push_back(i);
		ZERO(C);
		
		FOR(i,B.size()) {
			FOR(x,N) {
				S[x+1][i]=S[x][i];
				if(A[x]==B[i]) S[x+1][i]++;
			}
		}
		
		
        
    }
    
    int query(int left, int right, int threshold) {
		int ret=-1;
        if(threshold>100) {
			int i;
			FOR(i,B.size()) {
				if(S[right+1][i]-S[left][i]>=threshold) ret=B[i];
			}
		}
		else {
			int i;
			for(i=left;i<=right;i++) {
				C[A[i]]++;
				if(C[A[i]]>=threshold) ret=A[i];
			}
			for(i=left;i<=right;i++) C[A[i]]--;
		}
        return ret;
    }
};


