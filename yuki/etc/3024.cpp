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
vector<int> V;

set<double> hoge(int L,int R) {
	set<double> S;
	if(L==R) {
		S.insert(V[L]);
	}
	else {
		for(int M=L;M<R;M++) {
			set<double> a=hoge(L,M);
			set<double> b=hoge(M+1,R);
			FORR(r,a) FORR(r2,b) {
				S.insert(r+r2);
				S.insert(r-r2);
				S.insert(r*r2);
				if(abs(r2)>1e-9) S.insert(r/r2);
			}
		}
		
	}
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, V.push_back(x);
	sort(ALL(V));
	do {
		for(x=1;x<=N;x++) for(y=1;x+y<=N;y++) {
			set<double> S=hoge(0,x-1);
			set<double> T=hoge(x,x+y-1);
			FORR(r,S) FORR(r2,T) if(abs(r-r2)<1e-6) return _P("YES\n");
		}
		
	} while(next_permutation(ALL(V)));
	
	return _P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
