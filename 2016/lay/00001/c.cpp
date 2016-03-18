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

int T;
int X,A,B,N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>A>>B>>N;
		
		if(X*N>=60) {
			cout<<163*60/X*A/100<<endl;
		}
		else {
			
			int ma=0;
			int perhour=A*N+B*(60/X-N);
			
			j=(60+(X-1))/X;
			
			FOR(l,164) {
				y=l*perhour;
				i=(163-l)*60/X;
				
				y+=i/j*(A*N+B*(j-N));
				i%=j;
				if(i<=N) y+=A*i;
				else y+=A*N+B*(i-N);
				
				ma=max(ma,y);
			}
			
			cout<<ma/100<<endl;
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
