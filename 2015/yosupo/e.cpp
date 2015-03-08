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

class UF {
	public:
	int um;
	vector<int> ufpar,ufrank,ufcnt;
	UF(int um_=201002) { um=um_; ufrank=vector<int>(um,0); ufcnt=vector<int>(um,1); for(int i=0;i<um;i++) ufpar.push_back(i);}
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int N,M,vis[201000],in[201000];
string S;
vector<int> E[201000];
UF uf;
set<int> cand;
set<pair<int,int> > EE;
void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>N>>S>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--, y--;
		assert(x<y);
		if(EE.count(make_pair(x,y))) continue;
		EE.insert(make_pair(x,y));
		
		E[x].push_back(y);
		E[y].push_back(x);
		in[x]++, in[y]++;
		if(S[x]=='B' && S[y]=='B') uf.unite(x,y);
	}
	
	FOR(i,N) if(S[i]=='W' && in[i]>1) cand.insert(i);
	
	int up=1;
	while(up) {
		up=0;
		queue<int> Q;
		ITR(it,cand) Q.push(*it);
		
		ZERO(vis);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			if(S[cur]=='B' || vis[cur]) continue;
			vis[cur]=1;
			
			map<int,int> MM;
			FORR(r,E[cur]) if(S[r]=='B') {
				if(++MM[uf[r]]>=2) {
					S[cur]='B';
					cand.erase(cur);
					FORR(r2,E[cur]) if(S[r2]=='B') uf.unite(cur,r2);
					FORR(r2,E[cur]) if(S[r2]=='W' && in[r2]>1) vis[r2]=0, Q.push(r2);
					up++;
					break;
				}
			}
		}
	}
	
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
