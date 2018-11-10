#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
int S[102][102];

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int R=A.size();
		int C=A[0].size();
		int i,y,x;
		FOR(y,R) FOR(x,C+2) S[y][x]=1<<30;
		FOR(x,C) S[0][x+1]=A[0][x];
		for(y=1;y<R;y++) {
			for(x=1;x<=C;x++) S[y][x]=min({S[y-1][x-1],S[y-1][x],S[y-1][x+1]})+A[y][x-1];
		}
		return *min_element(&S[R-1][1],&S[R-1][C+1]);


	}
};

