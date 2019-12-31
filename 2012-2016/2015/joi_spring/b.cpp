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

int N,N4;
string S;
string T;
vector<int> dif;

int cmp(int v,int rot) {
	if(T[v]=='?') return 0;
	return (S[(v+rot+N4)%N4]!=T[v]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N4=1<<(2*N);
	cin>>S;
	for(i=N-1;i>=0;i--) {
		FOR(x,1<<(2*i)) T+="J";
		FOR(x,1<<(2*i)) T+="O";
		FOR(x,1<<(2*i)) T+="I";
	}
	T+="?";
	
	
	FOR(i,T.size()-1) if(T[i]!=T[i+1]) dif.push_back(i+1);
	dif.push_back(0);
	int cur=0;
	FOR(i,N4) cur+=cmp(i,0);
	int ret=cur;
	int rot;
	for(int rot=1;rot<N4;rot++) {
		FORR(d,dif) cur-=cmp(d,rot-1);
		FORR(d,dif) cur+=cmp((d-1+N4)%N4,rot);
		ret=min(ret,cur);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
