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
int X[5050];
int T[505*505];
int R[505*505];
int L[505];
vector<pair<int,int>> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i+1];
		T[X[i+1]]=i+1;
		L[i+1]=i;
		if(i) A.push_back({X[i+1],i+1});
	}
	
	sort(ALL(A));
	reverse(ALL(A));
	
	for(i=1;i<=N*N;i++) {
		if(T[i]) {
			R[i]=T[i];
			if(L[T[i]]) return _P("No\n");
			if(T[i]!=N) B.push_back({T[i],N-T[i]});
		}
		else if(A.size()) {
			R[i]=A.back().second;
			L[A.back().second]--;
			if(L[A.back().second]==0) A.pop_back();
		}
		else if(B.size()) {
			R[i]=B.back().first;
			B.back().second--;
			if(B.back().second==0) B.pop_back();
		}
		else return _P("No\n");
	}
	_P("Yes\n");
	FOR(i,N*N) _P("%d%c",R[i+1],(i==N*N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
