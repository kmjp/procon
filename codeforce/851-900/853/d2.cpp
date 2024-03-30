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

int T,N;
string A,B;
vector<int> R;

void op(int x) {
	int i;
	assert(x);
	if(x>0) {
		for(i=0;i+x<N;i++) A[i]^=A[i+x];
	}
	else {
		for(i=N-1;i+x>=0;i--) A[i]^=A[i+x];
	}
	R.push_back(x);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		R.clear();
		
		FORR(c,A) c=c=='1';
		FORR(c,B) c=c=='1';
		if(A==B) {
			cout<<0<<endl;
			continue;
		}
		if(count(ALL(B),1)==0) {
			cout<<-1<<endl;
			continue;
		}
		if(count(ALL(A),1)==0) {
			cout<<-1<<endl;
			continue;
		}
		FOR(x,N) if(A[x]) break;
		FOR(y,N) if(B[y]) break;
		
		if(A[y]!=B[y]) op(x-y);
		FOR(i,N) if(A[i]) break;
		for(x=y+1;x<N;x++) if(A[x]!=B[x]) op(i-x);
		for(i=N-1;i>=0;i--) if(A[i]) break;
		for(x=y-1;x>=0;x--) if(A[x]!=B[x]) op(i-x);
		
		
		
		cout<<R.size()<<endl;
		FORR(r,R) cout<<r<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
