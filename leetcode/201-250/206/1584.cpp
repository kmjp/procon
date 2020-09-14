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
    int minCostConnectPoints(vector<vector<int>>& points) {
		vector<pair<int,int>> V;
		int y,x;
		FOR(y,points.size()) FOR(x,y) {
			int d=abs(points[y][0]-points[x][0])+abs(points[y][1]-points[x][1]);
			V.push_back({d,y*1000+x});
		}
		sort(ALL(V));
		UF<1010> uf;
		ll ret=0;
		FORR(v,V) {
			y=v.second%1000;
			x=v.second/1000;
			if(uf[x]!=uf[y]) {
				ret+=v.first;
				uf(x,y);
			}
		}
        return ret;
    }
};

