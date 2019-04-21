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

ll S[1010];
ll AL[1010];
ll BL[1010];
ll AR[1010];
ll BR[1010];


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		int N=A.size();
		ZERO(S);
		int i,j,k;
		AL[0]=BL[0]=-(1LL<<60);
		FOR(i,N) {
			S[i+1]=S[i]+A[i];
			if(i+1>=L) AL[i+1]=max(AL[i],S[i+1]-S[i+1-L]);
			else AL[i+1]=-(1LL<<60);
			if(i+1>=M) BL[i+1]=max(BL[i],S[i+1]-S[i+1-M]);
			else BL[i+1]=-(1LL<<60);
		}
		AR[N+1]=BR[N+1]=-(1LL<<60);
		for(i=N-1;i>=0;i--) {
			if(i+L<=N) AR[i+1]=max(AR[i+2],S[i+L]-S[i]);
			else AR[i+1]=-(1LL<<60);
			if(i+M<=N) BR[i+1]=max(BR[i+2],S[i+M]-S[i]);
			else BR[i+1]=-(1LL<<60);
		}
		ll ret=0;
		FOR(i,N-1) {
			ret=max(ret,AL[i+1]+BR[i+2]);
			ret=max(ret,BL[i+1]+AR[i+2]);
		}
		return ret;
        
    }


};

