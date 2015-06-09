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

int N;
ll X[51],Y[51];
int C[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>C[i];
	
	int ret=0;
	FOR(x,2) {
		set<int> S[7];
		FOR(i,N) {
			ll yy=Y[i] + ((x==0)?(-2):3)*X[i];
			S[(yy%7+7)%7].insert(C[i]);
		}
		
		int ng=0;
		FOR(i,7) {
			if(S[i].size()>1) ng++;
			int num=0;
			FOR(j,7) num+=S[j].count(i+1);
			if(num>1) ng++;
		}
		if(ng) continue;
		
		int num=0;
		FOR(i,7) num += S[i].size()==0;
		int pat=1;
		FOR(i,num) pat*=(i+1);
		ret+=pat;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
