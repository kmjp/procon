#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	if(S[0]=='+') S=S.substr(1);
	FOR(i,S.size()-1) {
		if(S[i]=='+' && S[i+1]=='+') S=S.substr(0,i)+"+"+S.substr(i+2);
		if(S[i]=='-' && S[i+1]=='-') S=S.substr(0,i)+"+"+S.substr(i+2);
		if(S[i]=='-' && S[i+1]=='+') S=S.substr(0,i)+"-"+S.substr(i+2);
		if(S[i]=='+' && S[i+1]=='-') S=S.substr(0,i)+"-"+S.substr(i+2);
	}
	for(i=1;i<S.size();i++) {
		if(S[i]=='+') S[i]='-';
		else if(S[i]=='-') S[i]='+';
	}
	
	if(sscanf(S.c_str(),"%d+%d",&i,&j)==2)  cout << i+j<<endl;
	else if(sscanf(S.c_str(),"%d-%d",&i,&j)==2)  cout << i-j<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
