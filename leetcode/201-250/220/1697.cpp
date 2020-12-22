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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		UF<101010> uf;
		int i;
		vector<pair<int,int>> P,Q;
		
		FOR(i,edgeList.size()) P.push_back({edgeList[i][2],i});
		FOR(i,queries.size()) Q.push_back({queries[i][2],i});
        sort(ALL(P));
        reverse(ALL(P));
        sort(ALL(Q));
        vector<bool> ret(queries.size());
        
        FORR(q,Q) {
			int c=q.first;
			int id=q.second;
			while(P.size()&&P.back().first<c) {
				
				uf(edgeList[P.back().second][0],edgeList[P.back().second][1]);
				P.pop_back();
			}
			ret[id]=uf[queries[id][1]]==uf[queries[id][0]];
			
		}
        return ret;
        
    }
};


