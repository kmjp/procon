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

int N,L;
int X[101010];
int T[101010];
int LL[101010], RR[101010];
string D[101010];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	
	FOR(i,N) cin>>X[i]>>D[i];
	FOR(i,N) if(D[i]=="R") LL[i]=((i>0)?(LL[i-1]):0)+1;
	for(i=N-1;i>=0;i--) if(D[i]=="L") RR[i]=((i<N-1)?(RR[i+1]):0)+1;
	
	MINUS(T);
	FOR(i,N) {
		if(i==0 && D[i]=="L") T[i]=1;
		if(i==N-1 && D[i]=="R") T[i]=L;
		if(i<N-1 && D[i]=="R" && D[i+1]=="L") {
			if(LL[i]>=RR[i+1]) {
				T[i]=X[i+1]-1;
				T[i+1]=X[i+1];
			}
			else {
				T[i]=X[i];
				T[i+1]=X[i]+1;
			}
			i++;
		}
	}
	
	FOR(i,N) {
		if(D[i]=="L") {
			if(T[i]==-1) T[i]=T[i-1]+1;
			ret +=X[i]-T[i];
		}
	}
	for(i=N-1;i>=0;i--) {
		if(D[i]=="R") {
			if(T[i]==-1) T[i]=T[i+1]-1;
			ret +=T[i]-X[i];
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}


