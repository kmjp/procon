#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
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

int N,T;
string S[1010];
int sy,sx;
int row[1010];
int col[1010];
vector<int> OR,OC;
UF<160000> uf;


bool okok(int ty,int tx,int w1,int w2) {
	int i,x,y;
	
	// 0-up/down 1-left/right
	(w1==0)?row[sy]--:col[sx]--;
	(w2==0)?row[ty]--:col[tx]--;
	
	OR.push_back(sy);
	OR.push_back(ty);
	OC.push_back(sx);
	OC.push_back(tx);

	int ng=0;
	FORR(r,OR) ng+=row[r]&1;
	FORR(r,OC) ng+=col[r]&1;
	
	OR.pop_back();
	OR.pop_back();
	OC.pop_back();
	OC.pop_back();
	(w1==0)?row[sy]++:col[sx]++;
	(w2==0)?row[ty]++:col[tx]++;
	if(ng) return false;
	
	uf.reinit();
	
	FOR(y,N) {
		FOR(x,N-1) {
			if(S[y][x]=='#' || S[y][x+1]=='#') continue;
			if(y==sy && (x==sx||(x+1)==sx) && w1==0) continue;
			if(y==ty && (x==tx||(x+1)==tx) && w2==0) continue;
			uf(y*400+x,y*400+x+1);
			x++;
		}
	}
	FOR(x,N) {
		FOR(y,N-1) {
			if(S[y][x]=='#' || S[y+1][x]=='#') continue;
			if((y==sy||(y+1)==sy) && x==sx && w1==1) continue;
			if((y==ty||(y+1)==ty) && x==tx && w2==1) continue;
			if(uf[y*400+x]==uf[(y+1)*400+x]) return false;
			uf(y*400+x,(y+1)*400+x);
			y++;
		}
	}
	
	return uf.count(sy*400+sx)==T;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) if(S[y][x]=='s') sy=y,sx=x,S[y][x]='.';
		FOR(x,N) if(S[y][x]=='.') row[y]++,col[x]++,T++;
	}
	FOR(i,N) if(row[i]%2) OR.push_back(i);
	FOR(i,N) if(col[i]%2) OC.push_back(i);
	if(OR.size()>2 || OC.size()>2) return _P("IMPOSSIBLE\n");
	
	FOR(y,N) FOR(x,N) if(S[y][x]=='.' && (y!=sy||x!=sx)) {
		FOR(i,2) FOR(j,2) if(okok(y,x,i,j)) return _P("POSSIBLE\n");
	}
	_P("IMPOSSIBLE\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
