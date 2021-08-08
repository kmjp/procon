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

vector<int> manacher(string S) {
	int L=S.size(),i,j,k;
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && S[(i-j)/2]==S[(i+j+1)/2]) {
			j++;
		}
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k&&i+k<rad.size(); k++) {
			rad[i+k]=min(rad[i-k],rad[i]-k);
		}
	}
	return rad;
}

class Solution {
public:
    long long maxProduct(string s) {
		int N=s.size();
		vector<int> V=manacher(s);
		vector<int> A,L(N),R(N);
		int i;
		FOR(i,N) {
			int a=(V[i*2]+1)/2;
			L[i+a-1]=max(L[i+a-1],a);
			R[i-a+1]=max(R[i-a+1],a);
		}
		for(i=N-2;i>=0;i--) {
			L[i]=max(L[i],L[i+1]-1);
		}
		for(i=1;i<N;i++) {
			R[i]=max(R[i],R[i-1]-1);
		}
		for(i=1;i<N;i++) L[i]=max(L[i],L[i-1]);
		for(i=N-2;i>=0;i--) R[i]=max(R[i],R[i+1]);
		ll ret=0;
		FOR(i,N-1) {
			ll a=1LL*(L[i]*2-1)*(R[i+1]*2-1);
			ret=max(ret,a);
		}
		
		return ret;
        
    }
};
