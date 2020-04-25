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

int Q;
ll N,Y,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>Y>>X;
		int step=min({Y,N-1-Y,X,N-1-X});
		
		ll ret=2*(N-1+(N-1-2*(step-1)))*step;
		Y-=step;
		X-=step;
		N-=2*step;
		if(Y==0) {
			ret+=X;
		}
		else if(X==N-1) {
			ret+=(N-1)+Y;
		}
		else if(Y==N-1) {
			ret+=2*(N-1)+(N-1-X);
		}
		else {
			ret+=3*(N-1)+(N-1-Y);
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
