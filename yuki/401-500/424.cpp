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
UF<500000> uf;


int H,W;
int SX,SY,GX,GY;
string S[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>SX>>SY>>GX>>GY;
	FOR(y,H) cin>>S[y];
	
	FOR(y,H) {
		FOR(x,W-1) if(abs(S[y][x]-S[y][x+1])<=1) uf(y*50+x,y*50+x+1);
		FOR(x,W-2) if(S[y][x]==S[y][x+2]&&S[y][x+1]<S[y][x]) uf(y*50+x,y*50+x+2);
	}
	FOR(x,W) {
		FOR(y,H-1) if(abs(S[y][x]-S[y+1][x])<=1) uf(y*50+x,y*50+x+50);
		FOR(y,H-2) if(S[y][x]==S[y+2][x]&&S[y+1][x]<S[y][x]) uf(y*50+x,y*50+x+100);
	}
	
	
	
	if(uf[(SX-1)*50+(SY-1)]==uf[(GX-1)*50+(GY-1)]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
