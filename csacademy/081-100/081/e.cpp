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

int T,N;
ll X[2020],Y[2020];
vector<int> E[2020];
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

int P[2020];
int C[2020];
int lef[2020],ri[2020];
int vis[2020];
ll D[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		UF<2020> uf;
		cin>>N;
		FOR(i,N) {
			cin>>X[i]>>Y[i];
			C[i]=0;
			lef[i]=(i+N-1)%N;
			ri[i]=(i+1)%N;
			vis[i]=0;
		}
		vis[0]=1;
		FOR(i,N) {
			D[i]=(X[i]-X[0])*(X[i]-X[0])+(Y[i]-Y[0])*(Y[i]-Y[0]);
			P[i]=0;
		}
		FOR(i,N-1) {
			ll be=1LL<<60;
			int tar=0;
			FOR(x,N) if(vis[x]==0) {
				if(D[x]<be) be=D[x],tar=x;
			}
			vis[tar]=1;
			C[P[tar]]++;
			FOR(x,N) if(vis[x]==0) {
				ll nd=(X[x]-X[tar])*(X[x]-X[tar])+(Y[x]-Y[tar])*(Y[x]-Y[tar]);
				if(nd<D[x]) {
					D[x]=nd;
					P[x]=tar;
				}
			}
		}
		
		set<int> cand;
		FOR(i,N) if(C[i]==0) cand.insert(i);
		while(cand.size()) {
			if(cand.size()==1 && *cand.begin()==0) break;
			int cur;
			
			FORR(c,cand) {
				cur=c;
				if(c==0) continue;
				if(P[cur]==lef[cur]||P[cur]==ri[cur]) break;
			}
			cand.erase(cur);
			cout<<cur+1<<" "<<P[cur]+1<<endl;
			ri[lef[cur]]=ri[cur];
			lef[ri[cur]]=lef[cur];
			
			if(--C[P[cur]]==0) cand.insert(P[cur]);
			
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
