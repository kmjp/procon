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

int T;
ll X;

int ispar(ll v) {
	vector<int> V;
	while(v) {
		V.push_back(v%10);
		v/=10;
	}
	int i;
	FOR(i,V.size()) if(V[i]!=V[V.size()-1-i]) return 0;
	return 1;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<ll> C;
	for(i=1;i<=100000;i++) {
		string S=to_string(i);
		string T=S;
		string U=S;
		reverse(ALL(T));
		reverse(ALL(U));
		T+=S;
		U+=S.substr(1);
		if(T[0]!='0') C.push_back(atoll(T.c_str()));
		if(U[0]!='0') C.push_back(atoll(U.c_str()));
	}
	
	cin>>T;
	while(T--) {
		cin>>X;
		int ok=0;
		FORR(c,C) if(X%c==0 && ispar(X/c)) {
			ok=1;
			cout<<"Yes"<<endl;
			cout<<c<<endl;
			cout<<X/c<<endl;
			break;
		}
		if(ok==0) cout<<"No"<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
