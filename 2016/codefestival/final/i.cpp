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

int H,W;
string S[202];
ll ret;
int even[202][202];
ll mo=1000000007;
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	ret=1;
	if(H%2) {
		FOR(x,W) if(S[H/2][x]!=S[H/2][W-1-x]) {
			ret=2;
			break;
		}
		for(y=H/2;y<H-1;y++) swap(S[y],S[y+1]);
		H--;
	}
	if(W%2) {
		FOR(y,H) if(S[y][W/2]!=S[H-1-y][W/2]) {
			ret*=2;
			break;
		}
		FOR(y,H) S[y]=S[y].substr(0,W/2)+S[y].substr(W/2+1,W/2);
		W--;
	}
	
	if(H&&W) {
		FOR(y,H/2) FOR(x,W/2) {
			map<char,int> M;
			M[S[y][x]]++;
			M[S[H-1-y][x]]++;
			M[S[y][W-1-x]]++;
			M[S[H-1-y][W-1-x]]++;
			
			if(M.size()==4) {
				uf(y,200+x);
				even[y][x]=1;
				ret=ret*12%mo;
			}
			else if(M.size()==3) {
				ret=ret*12%mo;
			}
			else if(M.size()==2) {
				if(M.begin()->second==2) ret=ret*6%mo;
				else ret=ret*4%mo;
			}
		}
		
		j=H/2+W/2;
		FOR(y,H/2)  if(uf[y]==y) j--;
		FOR(x,W/2)  if(uf[x+200]==x+200) j--;
		FOR(i,j) ret=ret*2%mo;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
