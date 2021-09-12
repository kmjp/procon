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


vector<int> E[101010];
int P[21][200005],D[200005];
	vector<int> ret,nums;
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur) {
	FORR(e,E[cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
}
void dfs2(int cur) {
	FORR(e,E[cur]) {
		dfs2(e);
		ret[cur]=max(ret[cur],ret[e]);
	}
}

class Solution {
public:
	
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
		int N=parents.size();
		int i,x;
		vector<int> rev(100011,-1);
		ret.resize(N);
		FOR(i,N) {
			E[i].clear();
		}
		FOR(i,N) {
			if(i) E[parents[i]].push_back(i);
			rev[nums[i]]=i;
			ret[i]=1;
		}
		
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		int cur=rev[1];
		if(cur>=0) {
			ret[cur]=2;
			for(i=2;i<=100000;i++) {
				if(rev[i]==-1) break;
				cur=lca(cur,rev[i]);
				ret[cur]=max(ret[cur],i+1);
			}
		}
		dfs2(0);
        return ret;
    }
};
