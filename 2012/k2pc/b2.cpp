#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[101];
int cnt[10],ma[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,10) cin>>A[i];
	sort(A,A+10);
	reverse(A,A+10);
	
	FOR(i,N) {
		cin>>s;
		FOR(j,7) ma[j]=max(ma[j], cnt[j]=(s[j]=='X')?cnt[j]+1:0);
	}
	sort(ma,ma+7);
	reverse(ma,ma+7);
	FOR(i,7) if(ma[i]>A[i]) return _P("NO\n");
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
