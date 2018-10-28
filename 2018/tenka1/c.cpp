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
ll A[101010];
ll B[101010];
ll hoge() {
	int i;
	ll ret=0;
	FOR(i,N-1) ret+=abs(B[i]-B[i+1]);
	//FOR(i,N) cout<<B[i]<<" ";
	//cout<<endl;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	ll ma=0;
	ll ret=0;
	if(N%2==0) {
		FOR(i,N/2) {
			B[i*2+1]=A[i];
			B[i*2]=A[i+N/2];
		}
		ma=max(ma,hoge());
	}
	else {
		B[N-1]=A[N/2];
		FOR(i,N/2) {
			B[(i*2)+1]=A[i];
			B[(i*2)]=A[N/2+1+i];
		}
		ma=max(ma,hoge());
		FOR(i,N/2) {
			B[(N/2-1-i)*2]=A[i];
			B[1+(i*2)]=A[N/2+1+i];
		}
		ma=max(ma,hoge());
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
