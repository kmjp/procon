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
ll A[1010101],B[1010101];
ll S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		S-=B[i];
	}
	
	if(N==2) {
		if(A[0]+A[1]==B[0]+B[1]) {
			cout<<abs(A[0]-B[0])<<endl;
		}
		else {
			cout<<"-1"<<endl;
		}
		return;
	}
	
	
	if(S<0 || S%(N-2)) {
		cout<<-1<<endl;
		return;
	}
	S/=N-2;
	ll add=0;
	FOR(i,N) {
		if(B[i]<A[i]-S || (abs(B[i]%2) != abs((A[i]-S)%2))) {
			cout<<-1<<endl;
			return;
		}
		add+=(B[i]-(A[i]-S))/2;
	}
	if(add==S) {
		cout<<S<<endl;
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
