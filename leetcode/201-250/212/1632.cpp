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
UF<500*500> uf;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
		uf.reinit();
		int RM[505]={};
		int CM[505]={};
		
		int H=matrix.size();
		int W=matrix[0].size();
		vector<vector<int>> R=matrix;
		int y,x;
		map<int,vector<int>> V;
		FOR(y,H) FOR(x,W) {
			R[y][x]=0;
			V[matrix[y][x]].push_back(y*1000+x);
		}
		
		FOR(y,H) {
			map<int,int> M;
			FOR(x,W) {
				if(M.count(matrix[y][x])) uf(y*500+x,M[matrix[y][x]]);
				M[matrix[y][x]]=y*500+x;
			}
		}
		FOR(x,W) {
			map<int,int> M;
			FOR(y,H) {
				if(M.count(matrix[y][x])) uf(y*500+x,M[matrix[y][x]]);
				M[matrix[y][x]]=y*500+x;
			}
		}
		
		FORR(v,V) {
			FORR(a,v.second) {
				y=a/1000;
				x=a%1000;
				int ma=max(RM[y],CM[x]);
				int ty=uf[y*500+x]/500;
				int tx=uf[y*500+x]%500;
				R[ty][tx]=max(R[ty][tx],ma+1);
			}
			FORR(a,v.second) {
				y=a/1000;
				x=a%1000;
				int ty=uf[y*500+x]/500;
				int tx=uf[y*500+x]%500;
				R[y][x]=R[ty][tx];
				RM[y]=max(RM[y],R[y][x]);
				CM[x]=max(CM[x],R[y][x]);
			}
		}
		
		return R;
        
    }
};
