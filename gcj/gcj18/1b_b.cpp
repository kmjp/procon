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
int N;
int A[101010][2];

map<int,int> MM;

void dfs(int L,int R) {
	if(R-L<=2) {
		MM[R-L]++;
		return;
	}
	int M=(L+R)/2;
	dfs(L,M);
	dfs(M+1,R);
	
	set<pair<int,int>> B;
	for(int t=0;t<2;t++) {
		vector<int> LL,RR;
		int patL=-1<<30,patR=-1<<30;
		for(int i=M-1;i>=L;i--) {
			if(A[i][t]==A[M][t]) LL.push_back(-1<<30);
			else {
				if(patL==-1<<30) patL=A[i][t^1];
				if(patL!=A[i][t^1]) break;
				LL.push_back(A[i][t^1]);
			}
		}
		for(int i=M+1;i<R;i++) {
			if(A[i][t]==A[M][t]) RR.push_back(-1<<30);
			else {
				if(patR==-1<<30) patR=A[i][t^1];
				if(patR!=A[i][t^1]) break;
				RR.push_back(A[i][t^1]);
			}
		}
		
		if(patL==-1<<30 || patR==-1<<30 || patL==patR) {
			B.insert({M-LL.size(),M+1+RR.size()});
			continue;
		}
		
		int x;
		FOR(x,RR.size()) if(RR[x]!=-1<<30 && RR[x]!=patL) break;
		B.insert({M-(int)LL.size(),M+1+x});
		FOR(x,LL.size()) if(LL[x]!=-1<<30 && LL[x]!=patR) break;
		B.insert({M-x,M+1+(int)RR.size()});
	}
	
	FORR(r,B) MM[r.second-r.first]++;
	
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>r>>x>>y;
		A[i][0]=r+x;
		A[i][1]=r-y;
	}
	
	MM.clear();
	dfs(0,N);
	
	
	_P("Case #%d: %d %d\n",TC,MM.rbegin()->first,MM.rbegin()->second);
	
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
