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

int N,K;
int A[101010];
string S[101010];
int is[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(K==N) {
		cout<<endl;
		return;
	}
	
	FOR(i,K) {
		cin>>A[i];
		A[i]--;
		is[A[i]]=1;
	}
	FOR(i,N) cin>>S[i];
	string T=S[A[0]];
	for(i=1;i<K;i++) {
		if(T.size()>S[A[i]].size()) T=T.substr(0,S[A[i]].size());
		FOR(x,S[A[i]].size()) if(S[A[i]][x] != T[x]) {
			T=T.substr(0,x);
			break;
		}
	}
	
	
	
	
	int ma=1;
	FOR(i,N) if(is[i]==0) {
		if(T==S[i].substr(0,T.size())) {
			return _P("-1\n");
		}
		else {
			FOR(x,T.size()) {
				if(x<S[i].size() && T[x]==S[i][x]) {
					ma=max(ma,x+2);
				}
				if(x>=S[i].size() || T[x]!=S[i][x]) break;
			}
		}
	}
	cout<<T.substr(0,ma)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
