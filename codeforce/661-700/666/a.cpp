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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	if(N==1) {
		cout<<"1 1"<<endl;
		cout<<-A[0]<<endl;
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		return;
	}
	
	cout<<"1 "<<N<<endl;
	FOR(i,N) {
		cout<<-A[i]*N;
		if(i!=N-1) cout<<" ";
	}
	cout<<endl;
	cout<<"1 "<<(N-1)<<endl;
	FOR(i,N-1) {
		if(i==0) cout<<A[i]*(N-1);
		else cout<<0;
		if(i!=N-1) cout<<" ";
	}
	cout<<endl;
	cout<<"2 "<<N<<endl;
	FOR(i,N-1) {
		cout<<A[i+1]*(N-1);
		if(i!=N-1) cout<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
