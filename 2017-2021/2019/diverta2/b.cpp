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
ll X[51],Y[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	int mi=N;
	FOR(x,N) FOR(y,N) if(x!=y) {
		ll dx=X[x]-X[y];
		ll dy=Y[x]-Y[y];
		int num=0;
		FOR(i,N) {
			int ok=0;
			FOR(j,N) if(i!=j) {
				ll xx=X[j]-X[i];
				ll yy=Y[j]-Y[i];
				if(X[j]-X[i]==dx&&Y[j]-Y[i]==dy) ok=1;
			}
			num+=1-ok;
			
		}
		mi=min(mi,num);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
