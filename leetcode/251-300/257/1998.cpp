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

vector<int> A[202020],B[202020];
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
		UF<202020> uf;
		int i,j;
		FOR(i,nums.size()) {
			int x=nums[i];
			uf(100000+x,i);
			for(int y=2;y*y<=x;y++) if(x%y==0) {
				uf(100000+y,i);
				uf(100000+x/y,i);
			}
		}
		FOR(i,nums.size()) {
			A[uf[i]].push_back(i);
			B[uf[i]].push_back(nums[i]);
		}
		FOR(i,202020) if(A[i].size()) {
			sort(ALL(A[i]));
			sort(ALL(B[i]));
			FOR(j,A[i].size()) {
				nums[A[i][j]]=B[i][j];
			}
			A[i].clear();
			B[i].clear();
		}
        FOR(i,nums.size()-1) if(nums[i]>nums[i+1]) return 0;
        return 1;
    }
};
