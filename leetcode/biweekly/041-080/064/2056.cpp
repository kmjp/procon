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

int dy[3][8]={
	{1,-1,0,0},
	{1,1,-1,-1},
	{1,1,1,0,0,-1,-1,-1},
};
int dx[3][8]={
	{0,0,1,-1},
	{1,-1,1,-1},
	{1,0,-1,1,-1,1,0,-1},
};
int ty[4],tx[4];
int S[4];
int ret;
class Solution {
public:
	void dfs(vector<vector<int>> V,int mask) {
		int i,j;
		if(mask==0) return;
		FOR(i,V.size()) {
			if(mask&(1<<i)) {
				V[i][0]+=ty[i];
				V[i][1]+=tx[i];
				if(V[i][0]<=0||V[i][0]>8||V[i][1]<=0||V[i][1]>8) return;
			}
		}
		FOR(j,V.size()) FOR(i,j) if(V[i]==V[j]) return;
		ret++;
		FOR(j,16) if((mask&j)==j) dfs(V,j);
		
		
	}
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int i;
        FOR(i,pieces.size()) {
			if(pieces[i]=="rook") S[i]=0;
			if(pieces[i]=="bishop") S[i]=1;
			if(pieces[i]=="queen") S[i]=2;
		}
		ret=1;
		int mask,j;
		FOR(mask,1<<(3*pieces.size())) {
			FOR(i,pieces.size()) {
				int j=(mask>>(3*i))&7;
				ty[i]=dy[S[i]][j];
				tx[i]=dx[S[i]][j];
				if(ty[i]==0&&tx[i]==0) break;
			}
			if(i!=pieces.size()) continue;
			FOR(i,(1<<pieces.size())) {
				FOR(j,pieces.size()) {
					if((i&(1<<j))==0&&((mask>>(3*j))&7)) break;
				}
				if(j==pieces.size()) dfs(positions,i);
			}
		}
		return ret;
    }
};

