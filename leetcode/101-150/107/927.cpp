#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))


class Solution {
public:
	vector<int> threeEqualParts(vector<int>& A) {
		int i;
		int N=A.size();
		int N1=count(ALL(A),1);
		if(N1%3) return {-1,-1};
		if(N1==0) return {0,2};
		int L0=0;
		FOR(i,N) {
			if(A[N-1-i]) break;
			L0++;
		}
		int X,Y;
		int L1=0;
		FOR(i,N) if(A[i]) {
			L1++;
			if(L1==N1/3) X=i+L0;
			if(L1==N1*2/3) Y=i+L0;
		}
		
		vector<int> V[3];
		FOR(i,N) {
			int id=(i<=X)?0:((i<=Y)?1:2);
			if(A[i] || V[id].size()) V[id].push_back(A[i]);
		}
		
		if(V[0]!=V[1]) return {-1,-1};
		if(V[0]!=V[2]) return {-1,-1};
		if(V[1]!=V[2]) return {-1,-1};
		return {X,Y+1};
		
		
	}
};
