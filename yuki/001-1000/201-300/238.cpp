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
int L;

int palin(string SS) {
	int i;
	FOR(i,SS.size()) if(SS[i]!=SS[SS.size()-1-i]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	
	if(palin(S)) {
		string T=S.substr(0,L/2)+S[L/2]+S.substr(L/2);
		cout<<T<<endl;
		return;
	}
	
	FOR(i,L) if(S[i]!=S[L-1-i]) {
		string T=S.substr(0,i)+S[L-1-i]+S.substr(i);
		if(palin(T)) {
			cout<<T<<endl;
			return;
		}
		T=S.substr(0,L-1-i+1)+S[i]+S.substr(L-1-i+1);
		if(palin(T)) {
			cout<<T<<endl;
			return;
		}
		break;
	}
	cout<<"NA"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
