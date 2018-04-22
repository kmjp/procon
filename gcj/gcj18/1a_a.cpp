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

int T,testcase;
int H,W,A,B;
string S[101];


void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	A++;
	B++;
	int num=0;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) c=(c=='@'), num+=c;
	}
	
	if(num%(A*B)) return _P("Case #%d: IMPOSSIBLE\n",TC);
	if(num==0) return _P("Case #%d: POSSIBLE\n",TC);
	
	vector<int> P(A+1,-1),Q(B+1,-1);
	
	j=0;
	FOR(y,H) {
		FOR(x,W) j+=S[y][x];
		if(j%(num/A)==0) P[j/(num/A)]=y;
	}
	j=0;
	FOR(x,W) {
		FOR(y,H) j+=S[y][x];
		if(j%(num/B)==0) Q[j/(num/B)]=x;
	}
	if(count(ALL(P),-1)>1 || count(ALL(Q),-1)>1) return _P("Case #%d: IMPOSSIBLE\n",TC);
	

	FOR(i,A) FOR(j,B) {
		int tot=0;
		for(y=P[i]+1;y<=P[i+1];y++) for(x=Q[j]+1;x<=Q[j+1];x++) tot+=S[y][x];
		if(tot!=num/(A*B)) return _P("Case #%d: IMPOSSIBLE\n",TC);
	}
	return _P("Case #%d: POSSIBLE\n",TC);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
