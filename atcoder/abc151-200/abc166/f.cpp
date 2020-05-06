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

int N,X[3];
int C[101010][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X[0]>>X[1]>>X[2];
	
	string T;
	FOR(i,N) {
		cin>>s;
		if(s=="AB") {
			C[i][0]=0,C[i][1]=1;
		}
		else if(s=="BC") {
			C[i][0]=1,C[i][1]=2;
		}
		else {
			C[i][0]=2,C[i][1]=0;
		}
	}
	
	FOR(i,N) {
		if(X[C[i][0]]==0 && X[C[i][1]]==0) return _P("No\n");
		if(X[C[i][0]]==1 && X[C[i][1]]==1) {
			if(i==N-1 || C[i][0]==C[i+1][0]) goto pat0;
			if(C[i+1][1]==C[i][0]) goto pat0;
			goto pat1;
			
		}
		else if(X[C[i][0]]>=X[C[i][1]]) {
			pat1:
			T+='A'+C[i][1];
			X[C[i][0]]--;
			X[C[i][1]]++;
		}
		else {
			pat0:
			T+='A'+C[i][0];
			X[C[i][0]]++;
			X[C[i][1]]--;
		}
	}
	cout<<"Yes"<<endl;
	FORR(c,T) cout<<c<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
