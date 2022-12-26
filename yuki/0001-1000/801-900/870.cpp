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
	
	X[0]=2;
	X[1]=3;
	X[2]=7;
	Y[0]=8;
	Y[1]=Y[2]=9;
	
	cin>>N;
	FOR(i,N) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		FOR(j,3) if(x1==X[j]&&y1==Y[j]) X[j]=x2,Y[j]=y2;
	}
	
	if(X[0]==5&&X[1]==4&&X[2]==6&&Y[0]==8&&Y[1]==8&&Y[2]==8) {
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
