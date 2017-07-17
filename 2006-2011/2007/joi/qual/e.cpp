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

int A,B,C;
int state[301];
int N;
int X[1010],Y[1010],Z[1010],R[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>N;
	FOR(i,301) state[i]=2;
	FOR(i,N) cin>>X[i]>>Y[i]>>Z[i]>>R[i];
	FOR(x,1000) {
		FOR(i,N) {
			if(R[i]==1) {
				state[X[i]]=state[Y[i]]=state[Z[i]]=1;
			}
			else {
				if(state[X[i]]==1 && state[Y[i]]==1) state[Z[i]]=0;
				if(state[Y[i]]==1 && state[Z[i]]==1) state[X[i]]=0;
				if(state[Z[i]]==1 && state[X[i]]==1) state[Y[i]]=0;
			}
		}
	}
	FOR(i,A+B+C) cout<<state[i+1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
