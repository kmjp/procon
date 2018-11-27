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
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

vector<int> R[10101],C[10101];

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
		UF<10000> uf;
		int i,N=stones.size();
		FOR(i,10000) R[i].clear(), C[i].clear();
		FOR(i,N) {
			R[stones[i][0]].push_back(i);
			C[stones[i][1]].push_back(i);
		}
		
		FOR(i,10000) {
			if(R[i].size()) {
				FORR(r,R[i]) uf(r,R[i][0]);
			}
			if(C[i].size()) {
				FORR(r,C[i]) uf(r,C[i][0]);
			}
		}
		int ret=0;
		FOR(i,N) if(uf[i]==i) ret++;
		return N-ret;
		
		
        
    }
};
