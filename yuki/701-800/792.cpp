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
vector<string> V;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) {
		int A[20];
		FOR(j,N+1) cin>>A[j];
		if(A[N]==0) continue;
		string S="(";
		FOR(j,N) {
			if(A[j]==0) S+="¬";
			S+="P_";
			if(j<9) S+='0'+(j+1);
			else {
				S+="1";
				S+='0'+(j-9);
			}
			if(j!=N-1) S+="∧";
		}
		S+=")";
		V.push_back(S);
	}
	
	cout<<"A=";
	if(V.empty()) {
		cout<<"⊥"<<endl;
	}
	else if(V.size()==1<<N) {
		cout<<"⊤"<<endl;
	}
	else {
		FOR(i,V.size()) {
			if(i) cout<<"∨";
			cout<<V[i];
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
