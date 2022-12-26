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

int M;
ll X[505050],Y[505050];
ll NX[2],NY[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) cin>>X[i]>>Y[i];
	cout<<"? 0 0"<<endl;
	cin>>NX[0]>>NY[0];
	cout<<"? 1 0"<<endl;
	cin>>NX[1]>>NY[1];
	
	cout<<"!"<<endl;
	if(NX[1]-NX[0]==1) {
		FOR(i,M) cout<<X[i]+NX[0]<<" "<<Y[i]+NY[0]<<endl;
	}
	else if(NX[1]-NX[0]==-1) {
		FOR(i,M) cout<<-X[i]+NX[0]<<" "<<-Y[i]+NY[0]<<endl;
	}
	else if(NY[1]-NY[0]==1) {
		FOR(i,M) cout<<-Y[i]+NX[0]<<" "<<X[i]+NY[0]<<endl;
	}
	else if(NY[1]-NY[0]==-1) {
		FOR(i,M) cout<<Y[i]+NX[0]<<" "<<-X[i]+NY[0]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
