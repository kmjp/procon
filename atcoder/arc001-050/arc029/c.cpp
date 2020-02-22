#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class UF {
	public:
	static const int ufmax=100052;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	int count(int x) {return ufcnt[find(x)];}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int N,M;
int ok[100002];
vector< pair<int,ll> > V;
UF uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		V.push_back(make_pair(x,i*100000LL+i));
	}
	FOR(i,M) {
		cin>>x>>y>>j;
		x--;y--;
		V.push_back(make_pair(j,x*100000LL+y));
	}
	sort(V.begin(),V.end());
	ll tot=0;
	ITR(it,V) {
		int c=it->first;
		int s=it->second/100000,t=it->second%100000;
		
		if(s==t) {
			if(ok[uf[s]]==0) ok[uf[s]]=1, tot+=c;
		}
		else if(uf[s]!=uf[t] && (!ok[uf[s]] || !ok[uf[t]])) {
			int ok2=ok[uf[s]] | ok[uf[t]];
			uf.unite(s,t);
			ok[uf[s]]=ok2;
			tot+=c;
		}
	}
	cout << tot << endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
