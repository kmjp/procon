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
int P[202020],I[202020];
int RP[202020],RI[202020];
int L[202020],R[202020];


void hoge(int PL,int PR,int IL,int IR) {
	if(PR-PL!=IR-IL) {
		cout<<-1<<endl;
		exit(0);
	}
	if(PR==PL) return;
	int x=RI[P[PL]];
	if(x<IL||x>=IR) {
		cout<<-1<<endl;
		exit(0);
	}
	int num=x-IL;
	if(num) {
		L[P[PL]]=P[PL+1];
		hoge(PL+1,PL+num+1,IL,IL+num);
	}
	if(PL+num+1!=PR) {
		R[P[PL]]=P[PL+num+1];
		hoge(PL+num+1,PR,IL+num+1,IR);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i+1];
		RP[P[i+1]]=i+1;
	}
	if(P[1]!=1) {
		cout<<-1<<endl;
		return;
	}
	
	FOR(i,N) {
		cin>>I[i+1];
		RI[I[i+1]]=i+1;
	}
	
	hoge(1,N+1,1,N+1);
	
	FOR(i,N) cout<<L[i+1]<<" "<<R[i+1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
