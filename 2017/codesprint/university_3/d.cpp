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

int Q;
int N;
string S[1010];
int mex[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(y,N) cin>>S[y];
		int nim=0;
		FOR(y,N) {
			FOR(x,N) if(S[y][x]!='X') {
				mex[y][x]=0;
				set<int> Q;
				if(y && S[y-1][x]!='X') Q.insert(mex[y-1][x]);
				if(x && S[y][x-1]!='X') Q.insert(mex[y][x-1]);
				if(y && x && S[y-1][x-1]!='X') Q.insert(mex[y-1][x-1]);
				while(Q.count(mex[y][x])) mex[y][x]++;
				if(S[y][x]=='K') nim^=mex[y][x];
			}
		}
		
		if(nim==0) {
			cout<<"LOSE"<<endl;
		}
		else {
			int ok=0;
			FOR(y,N) FOR(x,N) if(S[y][x]=='K') {
				if(y&&S[y-1][x]!='X' && nim==(mex[y][x]^mex[y-1][x])) ok++;
				if(x&&S[y][x-1]!='X' && nim==(mex[y][x]^mex[y][x-1])) ok++;
				if(y&&x&&S[y-1][x-1]!='X' && nim==(mex[y][x]^mex[y-1][x-1])) ok++;
			}
			cout<<"WIN "<<ok<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
