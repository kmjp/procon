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

string S,S2;
int L;
int FO;
int h[101000], nex[101000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	S2=S;
	L=S.size();
	FO=L/2;
	
	FOR(i,L) if(S[i]=='(') FO--;
	MINUS(nex);
	
	x=0,y=-1;
	FOR(i,L) {
		if(S[i]=='(') h[i]=h[i-1]+1;
		else if(S[i]==')') h[i]=h[i-1]-1;
		else {
			if(y>=0) nex[y]=i;
			y=i;
			if(FO) S2[i]='(', h[i]=h[i-1]+1, FO--;
			else S2[i]=')', h[i]=h[i-1]-1;
		}
	}
	
	FOR(i,L) if(S2[i]=='(' && nex[i]>=0 && S2[nex[i]]==')') {
		if(count(h+i,h+nex[i],1)==0) return _P("No\n");
	}
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
