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

string A[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	
	if(A[0]=="?") {
		if(A[1]=="2" && A[2]=="3") cout<<4<<endl;
		else cout<<1<<endl;
	}
	if(A[1]=="?") {
		cout<<14<<endl;
	}
	if(A[2]=="?") {
		if(A[0]=="2" && A[1]=="3") cout<<1<<endl;
		else cout<<4<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
