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

vector<char> V[101010];;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		UF<101010> uf;
		int i,N=s.size();
		FOR(i,N) V[i].clear();
		FORR(p,pairs) uf(p[0],p[1]);
		FOR(i,N) V[uf[i]].push_back(s[i]);
		FOR(i,N) sort(ALL(V[i])),reverse(ALL(V[i]));
		string R;
		FOR(i,N) R.push_back(V[uf[i]].back()),V[uf[i]].pop_back();
		return R;
        
    }
};
