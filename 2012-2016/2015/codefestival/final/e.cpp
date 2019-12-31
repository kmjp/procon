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

int L;
string S;

int hoge(int v) {
	int i;
	for(i=L-1;i>=0;i--) {
		if(S[i]=='!') v=(v==0)?1:0;
		else v=-v;
	}
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	
	FOR(i,L) if(S[i]=='!') break;
	
	if(i==L) {
		if(L%2) cout<<"-"<<endl;
		else cout<<endl;
		return;
	}
	
	int v0=hoge(0);
	int v1=hoge(1);
	
	if(v0==0) {
		if(v1==1) cout<<"!!"<<endl;
		if(v1==-1) cout<<"-!!"<<endl;
	}
	else {
		if(v0==1) cout<<"!"<<endl;
		if(v0==-1) cout<<"-!"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
