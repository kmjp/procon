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
pair<int,int> X[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i].first;
	FOR(i,N) cin>>X[i].second;
	
	sort(X,X+N);
	
	int bit=0;
	int R=X[0].first+X[0].second;
	for(i=1;i<N;i++) {
		if(X[i].first>R) break;
		R=max(R,X[i].first+X[i].second);
	}
	if(i==N) bit |= 2;
	int L=X[N-1].first-X[N-1].second;
	for(i=N-2;i>=0;i--) {
		if(X[i].first<L) break;
		L=min(L,X[i].first-X[i].second);
	}
	if(i==-1) bit |= 1;
	
	if(bit==0) cout<<"NONE"<<endl;;
	if(bit==1) cout<<"RIGHT"<<endl;
	if(bit==2) cout<<"LEFT"<<endl;
	if(bit==3) cout<<"BOTH"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
