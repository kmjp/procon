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

int T,N,M;
int A[101010],B[101010],C[101010];
int ret[101010];
vector<int> cand[2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		int any=-1;
		FOR(i,N+1) cand[0][i].clear(),cand[1][i].clear();
		FOR(i,N) cin>>A[i];
		FOR(i,N) {
			cin>>B[i];
			if(A[i]==B[i]) cand[0][B[i]].push_back(i);
			else cand[1][B[i]].push_back(i);
		}
		FOR(i,M) cin>>C[i];
		int ok=1;
		for(i=M-1;i>=0;i--) {
			if(cand[1][C[i]].size()) {
				any=cand[1][C[i]].back();
				ret[i]=any;
				cand[1][C[i]].pop_back();
			}
			else if(cand[0][C[i]].size()) {
				any=cand[0][C[i]].back();
				ret[i]=any;
				cand[0][C[i]].pop_back();
			}
			else if(any>=0) {
				ret[i]=any;
			}
			else {
				ok=0;
			}
		}
		FOR(i,N) if(cand[1][i+1].size()) ok=0;
		if(ok==0) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			FOR(i,M) cout<<ret[i]+1<<" ";
			cout<<endl;
		}
	}
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
