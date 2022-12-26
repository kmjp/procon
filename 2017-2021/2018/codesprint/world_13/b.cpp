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

int N,M,A,B,C[3];
map<string,int> S;
int V[101010][3];
map<string,int> mp;
vector<string> VS;
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

UF<101010> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>A>>B>>C[0]>>C[1]>>C[2];
	FOR(i,N) {
		cin>>s>>x;
		VS.push_back(s);
		mp[s]=VS.size()-1;
		V[mp[s]][0]=x==1;
		V[mp[s]][1]=x==2;
		V[mp[s]][2]=x==3;
	}
	
	FOR(i,M) {
		string a,b;
		cin>>a>>b;
		x=uf[mp[a]];
		y=uf[mp[b]];
		if(uf[x]==uf[y]) continue;
		if(V[x][0]+V[y][0]>C[0]) continue;
		if(V[x][1]+V[y][1]>C[1]) continue;
		if(V[x][2]+V[y][2]>C[2]) continue;
		if(uf.count(x)+uf.count(y)>B) continue;
		FOR(j,3) V[x][j]=V[y][j]=V[x][j]+V[y][j];
		uf(x,y);
	}
	
	int ma=0;
	FOR(i,N) if(uf[i]==i) {
		if(uf.count(i)<A) continue;
		if(uf.count(i)>ma) ma=uf.count(i);
		
	}
	vector<string> ret;
	FOR(i,N) if(uf.count(i)==ma) ret.push_back(VS[i]);
	sort(ALL(ret));
	if(ret.empty()) ret.push_back("no groups");
	FORR(r,ret) cout<<r<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
