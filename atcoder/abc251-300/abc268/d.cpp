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

int N,M;
string S[8];

set<string> V;

void dfs(int mask,int lef,string& A) {
	if(mask==(1<<N)-1) {
		if(A.size()>=3) V.insert(A);
		return;
	}
	int i,j;
	for(i=0;i<=lef;i++) {
		A+="_";
		FOR(j,N) if((mask&(1<<j))==0) {
			A+=S[j];
			dfs(mask|(1<<j),lef-i,A);
			A.resize(A.size()-S[j].size());
		}
	}
	FOR(i,lef+1) A.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int lef=16-(N-1);
	FOR(i,N) {
		cin>>S[i];
		lef-=S[i].size();
	}
	string A;
	
	FOR(i,N) {
		A=S[i];
		dfs(1<<i,lef,A);
	}
	FOR(i,M) {
		cin>>s;
		V.erase(s);
	}
	if(V.size()) {
		cout<<*V.begin()<<endl;
	}
	else {
		cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
