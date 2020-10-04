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
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int R=rowSum.size();
		int C=colSum.size();
		vector<int> V(C);
		vector<vector<int>> ret;
		int i;
		FOR(i,R) ret.push_back(V);
		while(1) {
			int tx=-1,ty=-1;
			int x,y;
			FOR(y,R) if(rowSum[y]>0 && (ty==-1||rowSum[y]<rowSum[ty])) ty=y;
			FOR(x,C) if(colSum[x]>0 && (tx==-1||colSum[x]<colSum[tx])) tx=x;
			if(tx==-1) break;
			int mi=min(rowSum[ty],colSum[tx]);
			ret[ty][tx]=mi;
			rowSum[ty]-=mi;
			colSum[tx]-=mi;
		}
		return ret;
		
        
    }
};

