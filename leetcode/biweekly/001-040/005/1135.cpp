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


class Solution {
	public:
    int minimumCost(int N, vector<vector<int>>& conections) {
        FORR(c,conections) {
			vector<int> v=c;
			c={v[2],v[0]-1,v[1]-1};
		}
		sort(ALL(conections));
		UF<15000> uf;
		ll ret=0;
		int num=0;
		FORR(c,conections) {
			if(uf[c[1]]!=uf[c[2]]) {
				ret+=c[0];
				uf(c[1],c[2]);
				num++;
			}
		}
		if(num+1<N) return -1;
		return ret;
    }
};

