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
int X[3],Y[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		cin>>X[0]>>Y[0]>>X[1]>>Y[1]>>X[2]>>Y[2];
		int a=abs(X[0]-X[2])+abs(Y[0]-Y[2]);
		int b=max(abs(X[1]-X[2]),abs(Y[1]-Y[2]));
		if(a<b) cout<<"First"<<endl;
		else if(a>b) cout<<"Second"<<endl;
		else cout<<"Same time"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
