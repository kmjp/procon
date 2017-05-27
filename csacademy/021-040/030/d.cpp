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

int K,N;
string S[1010101];
map<string,int> M;
int tar[1010101];
int ma[1010101];
int dif[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>S[i];
	sort(S,S+N);
	
	FOR(i,N) {
		ma[i]=1010101;
		s=S[i];
		
		while(s.size()) {
			if(M.count(s)) {
				tar[i]=M[s];
				ma[tar[i]]=min(ma[tar[i]],(int)S[i].size());
				break;
			}
			s.pop_back();
		}
		M[S[i]]=i;
	}
	FOR(i,N) {
		dif[S[i].size()]++;
		dif[ma[i]]--;
	}
	
	int ret=0;
	for(i=1;i<=1000002;i++) {
		dif[i]+=dif[i-1];
		if(dif[i]>=K) return _P("%d\n",i);
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
