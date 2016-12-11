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
int S[1010];
int A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=N;i>=2;i--) {
		cout<<"Q "<<i;
		for(x=1;x<=i;x++) cout<<" "<<x;
		cout<<endl;
		cin>>S[i];
	}
	for(i=N-1;i>=2;i--) A[i]=S[i+1]-S[i];
	cout<<"Q 2 2 3"<<endl;
	cin>>x;
	A[0]=S[3]-x;
	A[1]=S[2]-A[0];
	cout<<"A";
	FOR(i,N) cout<<" "<<A[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
