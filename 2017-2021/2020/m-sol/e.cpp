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


int N;
int X[15],Y[15],P[15];
ll ret[16];

ll xmin[1<<15][15];
ll ymin[1<<15][15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>P[i];
	}
	FOR(i,N+1) ret[i]=1LL<<60;
	
	FOR(i,1<<N) {
		FOR(j,N) {
			xmin[i][j]=abs(X[j])*1LL*P[j];
			ymin[i][j]=abs(Y[j])*1LL*P[j];
			FOR(x,N) if(i&(1<<x)) {
				xmin[i][j]=min(xmin[i][j],abs(X[j]-X[x])*1LL*P[j]);
				ymin[i][j]=min(ymin[i][j],abs(Y[j]-Y[x])*1LL*P[j]);
			}
		}
	}
	
	
	for(int xmask=0;xmask<1<<N;xmask++) {
		int lef=((1<<N)-1)^xmask;
		for(int ymask=lef; ymask>=0; ymask--) {
			ymask&=lef;
			ll sum=0;
			FOR(i,N) sum+=min(xmin[xmask][i],ymin[ymask][i]);
			y=__builtin_popcount(xmask|ymask);
			ret[y]=min(ret[y],sum);
		}
	}
	
	FOR(i,N) ret[i+1]=min(ret[i],ret[i+1]);
	FOR(i,N+1) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
