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
int A[101010];
int B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		B[i]=A[i];
	}
	sort(B,B+N);
	
	int L=0,R=N-1;
	while(L<N && A[L]==B[L]) L++;
	while(R>=0 && A[R]==B[R]) R--;
	
	if(L==N) {
		ll ret=0;
		int pre=-1,cnt=0;
		int R=N;
		FOR(i,N) {
			if(A[i]!=pre) pre=A[i],cnt=0;
			cnt++;
			ret+=cnt;
		}
		cout<<ret<<endl;
		cout<<1<<" "<<1<<endl;
	}
	else {
		for(x=0;x<=R-L;x++) {
			if(A[L+x]!=B[R-x]) return _P("0\n");
		}
		cout<<1<<endl;
		cout<<(L+1)<<" "<<(R+1)<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
