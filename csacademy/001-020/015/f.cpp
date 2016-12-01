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

ll mo=1000000007;
int N,M;
template<int um> class UF {
	public:
	vector<int> par;
	UF() {for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		return par[x]=y;
	}
};
UF<1010000> uf[20];
int L,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>L>>X>>Y;
		X--,Y--;
		FOR(k,20) {
			if(L&(1<<k)) {
				uf[k](X,Y);
				L -= 1<<k;
				X += 1<<k;
				Y += 1<<k;
			}
		}
	}
	
	for(i=19;i>=0;i--) {
		FOR(x,N-(1<<(i+1))+1) if(x!=uf[i+1][x]) {
			y=uf[i+1][x];
			uf[i](x,y);
			uf[i](x+(1<<i),y+(1<<i));
		}
	}
	
	ll ret=1;
	FOR(i,N) if(uf[0][i]==i) ret = ret*26%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
