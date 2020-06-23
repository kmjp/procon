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

class UF {
	public:
	int um; vector<int> par,rank,cnt;
	UF(int um) {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
		int sum=0;
		int i,j;
		{
			UF uf(n);
			vector<pair<int,int>> P;
			FOR(i,edges.size()) P.push_back({edges[i][2],i});
			sort(ALL(P));
			FORR(e,P) if(uf[edges[e.second][0]]!=uf[edges[e.second][1]]) {
				sum+=e.first;
				uf(edges[e.second][0],edges[e.second][1]);
			}
		}
		vector<vector<int>> R(2);
		FOR(i,edges.size()) {
			{
				UF uf(n);
				vector<pair<int,int>> P;
				FOR(j,edges.size()) if(i!=j) P.push_back({edges[j][2],j});
				int sum2=0;
				sort(ALL(P));
				FORR(e,P) if(uf[edges[e.second][0]]!=uf[edges[e.second][1]]) {
					sum2+=e.first;
					uf(edges[e.second][0],edges[e.second][1]);
				}
				cout<<i<<" "<<sum<<" "<<sum2<<endl;
				if(uf.count(0)!=n || sum!=sum2) {
					R[0].push_back(i);
					continue;
				}
			}
			{
				UF uf(n);
				vector<pair<int,int>> P;
				FOR(j,edges.size()) P.push_back({edges[j][2],j});
				int sum2=edges[i][2];
				uf(edges[i][0],edges[i][1]);
				sort(ALL(P));
				FORR(e,P) if(uf[edges[e.second][0]]!=uf[edges[e.second][1]]) {
					sum2+=e.first;
					uf(edges[e.second][0],edges[e.second][1]);
				}
				if(uf.count(0)==n && sum==sum2) {
					R[1].push_back(i);
					continue;
				}
			}
			
			
			
		}
		
		return R;
		
		
		
		
        
    }
};
