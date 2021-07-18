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
vector<int> R;
vector<pair<int,int>> Q[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void dfs(int cur) {
	bt.add(cur,1);
	
	FORR(q,Q[cur]) {
		int v=q.first;
		int i;
		int cur=0;
		for(i=19;i>=0;i--) {
			if(v&(1<<i)) {
				if(bt(cur+(1<<i)-1)-bt(cur-1)==0) {
					cur^=1<<i;
				}
			}
			else {
				if(bt(cur+(2<<i)-1)-bt(cur+(1<<i)-1)) {
					cur^=1<<i;
				}
			}
		}
		R[q.second]=cur^v;
	}
	
	FORR(e,E[cur]) dfs(e);
	bt.add(cur,-1);
	
}

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int N=parents.size();
        int root;
        int i;
        FOR(i,N) E[i].clear(), Q[i].clear();
        FOR(i,N) {
			if(parents[i]==-1) root=i;
			else E[parents[i]].push_back(i);
		}
		R.resize(queries.size());
		FOR(i,queries.size()) {
			Q[queries[i][0]].push_back({queries[i][1],i});
		}
		
		dfs(root);
		
		
		return R;
    }
};
