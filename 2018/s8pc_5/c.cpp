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

int Q;
string S;

int hoge(string S) {
	int N=S.size();
	int A=0,B=0,T=N/4;
	int cur=0;
	int O=0,C=0;
	int i;
	
	FORR(c,S) {
		if(c=='(') O++;
		else C++;
	}
	if(O!=C) return 0;
	
	A=B=T;
	int dif=0;
	FOR(i,N) {
		if(S[i]=='(') O--;
		if(S[i]==')') C--;
		
		if(S[i]=='(' && A) {
			A--;
			S[i]='.';
			dif++;
		}
		if(S[i]==')' && C<B) {
			B--;
			S[i]='.';
			dif--;
			if(dif<0) return 0;
		}
	}
	if(dif) return 0;
	FORR(c,S) {
		if(c==')') dif++;
		if(c=='(') dif--;
		if(dif<0) return 0;
	}
	
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>S;
		if(hoge(S)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
