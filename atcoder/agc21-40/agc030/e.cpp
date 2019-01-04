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
string S,T;

vector<int> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	
	if(N<3) {
		int ret=0;
		FOR(i,N) ret+=S[i]!=T[i];
		cout<<ret<<endl;
		return;
	}
	
	if(S[0]=='1') A.push_back(0);
	if(T[0]=='1') B.push_back(0);
	for(i=1;i<N;i++) {
		if(S[i]!=S[i-1]) A.push_back(i);
		if(T[i]!=T[i-1]) B.push_back(i);
	}
	
	int mi=1<<30;
	for(int D=-(N+2);D<=N+2;D++) if(D%2==0) {
		int tot=0;
		FOR(i,A.size()) {
			y=i+D;
			if(y<0) r=0;
			else if(y>=B.size()) r=N;
			else r=B[y];
			tot+=abs(A[i]-r);
		}
		FOR(i,B.size()) {
			y=i-D;
			if(y>=0 && y<A.size()) continue;
			if(y<0) r=0;
			else r=N;
			tot+=abs(B[i]-r);
		}
		
		mi=min(mi,tot);
	}
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
