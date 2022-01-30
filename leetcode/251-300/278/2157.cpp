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
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int mask[202020];
class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
		UF<20202> uf;
		
		int i,N=words.size(),x;
		unordered_map<int,int> M;
		FOR(i,N) {
			mask[i]=0;
			FORR(c,words[i]) mask[i]|=1<<(c-'a');
			FOR(x,27) {
				int nm=mask[i];
				if(nm&(1<<x)) nm^=(1<<x);
				if(M.count(nm)) uf(i,M[nm]);
				M[nm]=i;
			}
		}
		
		int ma=0,cnt=0;
		FOR(i,N) {
			if(i==uf[i]) cnt++;
			ma=max(ma,uf.count(i));
		}
		return {cnt,ma};
		
		
        
    }
};
