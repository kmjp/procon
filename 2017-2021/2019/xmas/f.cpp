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
string S[1010];

int dfs(int num) {
	int i,j,k,l,r,x,y;
	int L=1010,R=-1,U=1010,D=-1;
	string T[1010];
	if(num>=4) return 4;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		L=min(L,x);
		U=min(U,y);
		D=max(D,y);
		R=max(R,x);
	}
	if(L==1010) return num;
	int ret=1010;
	FOR(i,2) FOR(j,2) {
		int SY=i?U:(D-(H/2-1));
		int SX=j?L:(R-(W/2-1));
		
		FOR(y,H) T[y]=S[y];
		
		for(y=max(0,SY);y<min(H,SY+H/2);y++) {
			for(x=max(0,SX);x<min(W,SX+W/2);x++) {
				S[y][x]='#';
			}
		}
		ret=min(ret,dfs(num+1));
		FOR(y,H) S[y]=T[y];
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	cout<<dfs(0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
