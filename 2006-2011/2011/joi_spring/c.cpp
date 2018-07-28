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
UF<1500> uf;

int N;
int P[1010];
int C[1010][1010];
int NC[4];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		NC[P[i]]++;
	}
	FOR(y,N) FOR(x,N) cin>>C[y][x];
	
	int pat=0;
	int ret=0;
	if(NC[1]) {
		FOR(y,N) FOR(x,y) if(P[y]==1 || P[x]==1) pat++, ret+=C[y][x];
	}
	else if(NC[2]) {
		pat=N-1;
		ret=1<<30;
		FOR(i,N) {
			int tot=0;
			FOR(j,N) tot+=C[i][j];
			ret=min(ret,tot);
		}
		if(NC[2]==2) {
			x=y=-1;
			FOR(i,N) if(P[i]==2) {
				if(x==-1) x=i;
				else y=i;
			}
			int tot=C[x][y];
			FOR(i,N) tot+=min(C[x][i],C[y][i]);
			ret=min(ret,tot);
		}
	}
	else {
		vector<pair<int,pair<int,int>>> V;
		FOR(y,N) FOR(x,y) V.push_back({C[y][x],{x,y}});
		sort(ALL(V));
		FORR(v,V) {
			if(uf[v.second.first]!=uf[v.second.second]) {
				pat++;
				ret+=v.first;
				uf(v.second.first,v.second.second);
			}
		}
			
	}
	
	cout<<pat<<" "<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
