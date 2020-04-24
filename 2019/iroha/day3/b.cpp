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


string S[11][2];
int Q[11][3]= {
	{0,1,2},
	{3,4,5},
	{3,4,6},
	{3,4,7},
	{3,5,6},
	{3,5,7},
	{3,6,7},
	{4,5,6},
	{4,5,7},
	{4,6,7},
	{5,6,7},
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,11) {
		cout<<"? "<<Q[i][0]<<" "<<Q[i][1]<<" "<<Q[i][2]<<endl;
		cin>>S[i][0]>>S[i][1];
	}
	
	if(S[0][0]=="Square" || S[0][0]=="Rectangle") {
		int cnt=0;
		for(i=1;i<=10;i++) cnt+=S[i][0]==S[0][0];
		if(cnt==6) cout<<"! 1"<<endl;
		else cout<<"! 2"<<endl;
	}
	else {
		assert(0);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
