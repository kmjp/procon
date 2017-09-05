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

int H,W;
int A[303][303];
int cnt[101010];
int L[101010],R[101010],T[101010],D[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,101000) L[i]=T[i]=500,R[i]=D[i]=-1;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x], cnt[A[y][x]]++;
		L[A[y][x]]=min(L[A[y][x]],x);
		T[A[y][x]]=min(T[A[y][x]],y);
		R[A[y][x]]=max(R[A[y][x]],x);
		D[A[y][x]]=max(D[A[y][x]],y);
	}
	
	FOR(i,101000) if(cnt[i]) {
		int lr=R[i]-L[i]+1;
		int td=D[i]-T[i]+1;
		if(lr*td!=cnt[i]) return _P("0\n");
		if(lr!=td) return _P("0\n");
	}
	_P("1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
