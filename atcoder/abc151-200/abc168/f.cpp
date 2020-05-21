#include <bits/stdc++.h>
using namespace std;
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

int N,M;
int X1[1010],X2[1010],Y[1010];
int X[1010],Y1[1010],Y2[1010];

int HNG[4040][4040];
int VNG[4040][4040];

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
UF<4000*4000> uf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> Xs,Ys;
	Xs.push_back(-1<<30);
	Xs.push_back(0);
	Xs.push_back(1<<30);
	Ys.push_back(-1<<30);
	Ys.push_back(0);
	Ys.push_back(1<<30);
	FOR(i,N) {
		cin>>Y1[i]>>Y2[i]>>X[i];
		Xs.push_back(X[i]);
		Ys.push_back(Y1[i]);
		Ys.push_back(Y2[i]);
	}
	FOR(i,M) {
		cin>>Y[i]>>X1[i]>>X2[i];
		Xs.push_back(X1[i]);
		Xs.push_back(X2[i]);
		Ys.push_back(Y[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y1[i]=lower_bound(ALL(Ys),Y1[i])-Ys.begin();
		Y2[i]=lower_bound(ALL(Ys),Y2[i])-Ys.begin();
		VNG[Y1[i]][X[i]]++;
		VNG[Y2[i]][X[i]]--;
	}
	FOR(i,M) {
		X1[i]=lower_bound(ALL(Xs),X1[i])-Xs.begin();
		X2[i]=lower_bound(ALL(Xs),X2[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		HNG[Y[i]][X1[i]]++;
		HNG[Y[i]][X2[i]]--;
	}
	
	
	FOR(x,Xs.size()) FOR(y,Ys.size()) {
		if(x) HNG[y][x]+=HNG[y][x-1];
		if(y) VNG[y][x]+=VNG[y-1][x];
		if(x&&VNG[y][x]==0) uf(y*4000+x,y*4000+x-1);
		if(y&&HNG[y][x]==0) uf(y*4000+x,(y-1)*4000+x);
	}
	
	
	int rx,ry;
	rx=lower_bound(ALL(Xs),0)-Xs.begin();
	ry=lower_bound(ALL(Ys),0)-Ys.begin();
	if(uf[ry*4000+rx]==uf[0]) return _P("INF\n");
	
	ll ret=0;
	FOR(x,Xs.size()-1) FOR(y,Ys.size()-1) if(uf[ry*4000+rx]==uf[y*4000+x]) {
		ret+=1LL*(Ys[y+1]-Ys[y])*(Xs[x+1]-Xs[x]);
	}
	cout<<ret<<endl;
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
