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

int S;
ll X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	while(S--) {
		cin>>X>>Y;
		
		if(X*2==Y) {
			cout<<0<<endl;
			continue;
		}
		if(X*2>Y) X=Y-X;
		ll ret=0;
		// X/Y=B/2A -> 2AX=YB 2X<Y‚æ‚è2AX‚ªY‚Ì”{”‚É‚È‚é‚à‚Ì
		ret+=100000000/Y;
		// X/Y=(B*B-1)/2AB -> 2ABX=(B*B-1)Y 
		for(ll B=1;B*B<=Y;B++) if(Y%B==0) {
			if(B>1&&(B*B-1)%X==0) {
				ll A2=(Y/B)*((B*B-1)/X);
				if(A2%2==0&&A2/2>B&&A2/2<=100000000&&(A2+B)%2==1) ret++;
			}
			
			if(B*B<Y) {
				ll TB=Y/B;
				if((TB*TB-1)%X==0) {
					ll A2=(Y/TB)*((TB*TB-1)/X);
					if(A2%2==0&&A2/2>TB&&A2/2<=100000000&&(A2+TB)%2==1) ret++;
				}
			}
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
