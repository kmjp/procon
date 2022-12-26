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
string A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A>>B;
		
		int AA=0;
		int BB=0;
		
		if(A[5]=='P') AA+=12*60;
		if(B[5]=='P') BB+=12*60;
		if(!(A[0]=='1'&&A[1]=='2')) AA+=(10*(A[0]-'0')+A[1]-'0')*60;
		if(!(B[0]=='1'&&B[1]=='2')) BB+=(10*(B[0]-'0')+B[1]-'0')*60;
		AA+=(A[3]-'0')*10+(A[4]-'0');
		BB+=(B[3]-'0')*10+(B[4]-'0');
		
		if(AA<BB) {
			_P("First\n");
		}
		else {
			_P("Second\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
