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

int N,Q;
int X[202020],Y[202020];
char S[202020];
map<pair<int,int>,vector<int>> M;
void solve() {
	int i,j,k,l,r,x,y; string s;

	scanf("%d%d",&N,&Q);
	scanf("%s",S);
	M[{0,0}].push_back(0);
	FOR(i,N) {
		X[i+1]=X[i];
		Y[i+1]=Y[i];
		if(S[i]=='L') X[i+1]--;
		if(S[i]=='R') X[i+1]++;
		if(S[i]=='U') Y[i+1]++;
		if(S[i]=='D') Y[i+1]--;
		M[{X[i+1],Y[i+1]}].push_back(i+1);
	}
	
	while(Q--) {
		int TX,TY,L,R;
		scanf("%d%d%d%d",&TX,&TY,&L,&R);
		L--;
		int ok=0;
		
		auto it=M.find({TX,TY});
		if(it!=M.end()) {
			if(it->second[0]<=L||R<=it->second.back()) ok=1;
		}
		int AX=X[L];
		int AY=Y[L];
		int BX=X[R];
		int BY=Y[R];
		int CX=AX+BX-TX;
		int CY=AY+BY-TY;
		it=M.find({CX,CY});
		if(it!=M.end()) {
			auto x=lower_bound(ALL(it->second),L)-it->second.begin();
			if(x<it->second.size()&&it->second[x]<=R) ok=1;
		}
		
		
		if(ok) {
			_P("YES\n");
		}
		else {
			_P("NO\n");
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
