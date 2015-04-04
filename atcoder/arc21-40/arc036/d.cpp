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
	UF(int um_=200005) { um=um_; ufrank=vector<int>(um,0); ufcnt=vector<int>(um,1); for(int i=0;i<um;i++) ufpar.push_back(i);}
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

UF uf;
int N,Q;

void solve() {
	int i,j,k,l,w,r,x,y,z; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>w>>x>>y>>z;
		if(w==1) {
			uf.unite(x*2,y*2+z&1);
			uf.unite(x*2+1,y*2+(1-z&1));
		}
		else {
			if(uf[x*2]==uf[y*2]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
