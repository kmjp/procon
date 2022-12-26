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

int N,M,Q;
int A[101010];
int T[101010];
int num[300][101010];
const int DIV=400;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) {
		cin>>A[i];
		A[i]%=M;
		num[i/DIV][A[i]]++;
	}
	while(Q--) {
		int L,R,D;
		cin>>L>>R>>D;
		L--;R--;
		int ret=0;
		while(L<=R && L%DIV) {
			num[L/DIV][A[L]]--;
			(A[L]+=D)%=M;
			num[L/DIV][A[L]]++;
			if((A[L]+T[L/DIV])%M==0) ret++;
			L++;
		}
		while(R>=L && R%DIV!=DIV-1) {
			num[R/DIV][A[R]]--;
			(A[R]+=D)%=M;
			num[R/DIV][A[R]]++;
			if((A[R]+T[R/DIV])%M==0) ret++;
			R--;
		}
		while(L<R) {
			(T[L/DIV]+=D)%=M;
			ret += num[L/DIV][(M-T[L/DIV])%M];
			L+=DIV;
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
