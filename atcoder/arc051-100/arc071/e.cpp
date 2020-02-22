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

string S,T;
int SS[101010],TS[101010];
int Q;
int A,B,C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T>>Q;
	FOR(i,S.size()) SS[i+1]=SS[i]+(S[i]-'A')+1;
	FOR(i,T.size()) TS[i+1]=TS[i]+(T[i]-'A')+1;
	
	while(Q--) {
		cin>>A>>B>>C>>D;
		
		if((SS[B]-SS[A-1])%3==(TS[D]-TS[C-1])%3) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
