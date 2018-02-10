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
ll A[101];

vector<pair<int,int>> V;
void add(int x,int y) {
	A[y]+=A[x];
	V.push_back({x+1,y+1});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0,mi=0;
	FOR(i,N) {
		cin>>A[i];
		if(A[ma]<A[i]) ma=i;
		if(A[mi]>A[i]) mi=i;
	}
	if(A[ma]>-A[mi]) {
		FOR(i,N) if(i!=ma) add(ma,i);
		FOR(i,N-1) add(i,i+1);
	}
	else {
		FOR(i,N) if(i!=mi) add(mi,i);
		for(i=N-1;i>=1;i--) add(i,i-1);
	}
	
	cout<<V.size()<<endl;
	FORR(r,V) cout<<r.first<<" "<<r.second<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
