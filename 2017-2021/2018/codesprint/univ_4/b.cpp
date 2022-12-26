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

int N,M;
int S[505],R[505];
int K[505],C[505];
vector<int> A;
vector<double> B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>S[i];
	FOR(i,N) cin>>K[i];
	FOR(i,N) FOR(j,K[i]) A.push_back(S[i]);
	FOR(i,M) cin>>R[i];
	FOR(i,M) cin>>C[i];
	FOR(i,M) FOR(j,C[i]) B.push_back(R[i]*sqrt(2));
	
	sort(ALL(A));
	sort(ALL(B));
	reverse(ALL(A));
	int ret=0;
	FORR(c,A) {
		if(B.size()&&B.back()>=c) {
			ret++;
			B.pop_back();
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
