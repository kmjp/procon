#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N;
int P[404040],Q[404040];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>P[i];
		P[i]--;
	}
	FOR(i,2*N) {
		cin>>Q[i];
		Q[i]--;
	}
	S.resize(2*N,'_');
	set<int> cand;
	FOR(i,2*N) cand.insert(i);
	FOR(i,2*N) {
		if(i==0||P[i]!=*cand.begin()) S[P[i]]='(';
		cand.erase(P[i]);
	}
	FOR(i,2*N) cand.insert(i);
	FOR(i,2*N) {
		if(i==0||Q[i]!=*cand.rbegin()) S[Q[i]]='(';
		cand.erase(Q[i]);
	}
	FOR(i,2*N) cand.insert(i);
	for(i=2*N-1;i>=0;i--) {
		if(i==2*N-1||P[i]!=*cand.rbegin()) S[P[i]]=')';
		cand.erase(P[i]);
	}
	FOR(i,2*N) cand.insert(i);
	for(i=2*N-1;i>=0;i--) {
		if(i==2*N-1||Q[i]!=*cand.begin()) S[Q[i]]=')';
		cand.erase(Q[i]);
	}
	
	FORR(c,S) if(c=='_') {
		cout<<-1<<endl;
		return;
	}
	set<int> O,C;
	int cur=0;
	FOR(i,2*N) {
		if(S[i]=='(') O.insert(i);
		if(S[i]==')') C.insert(i);
	}
	FOR(i,2*N) {
		if(cur) {
			x=(O.size()?*O.begin():1<<20);
			y=(C.size()?*C.begin():1<<20);
		}
		else {
			x=(O.size()?*O.begin():1<<20);
			y=1<<20;
		}
		if(P[i]!=min(x,y)) {
			cout<<-1<<endl;
			return;
		}
		if(x<y) {
			cur++;
			O.erase(O.begin());
		}
		else {
			cur--;
			C.erase(C.begin());
		}
	}
	FOR(i,2*N) {
		if(S[i]=='(') O.insert(i);
		if(S[i]==')') C.insert(i);
	}
	FOR(i,2*N) {
		if(cur) {
			x=(O.size()?*O.rbegin():-1);
			y=(C.size()?*C.rbegin():-1);
		}
		else {
			x=(O.size()?*O.rbegin():-1);
			y=-1;
		}
		if(Q[i]!=max(x,y)) {
			cout<<-1<<endl;
			return;
		}
		if(x>y) {
			cur++;
			O.erase(*O.rbegin());
		}
		else {
			cur--;
			C.erase(*C.rbegin());
		}
	}
	
	
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
