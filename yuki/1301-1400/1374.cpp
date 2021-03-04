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


int N;
int C[101010];
ll R[2][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	sort(C,C+N);
	
	//++;
	int step=0;
	for(i=N-1;i>=0;i--,step^=1) {
		if(step==0) R[0][0]+=C[i];
		else R[0][0]-=C[i];
	}
	//--
	FOR(i,N) {
		if(i%2==0) R[1][1]-=C[i];
		else R[1][1]+=C[i];
	}
	//+-
	int a=N-1,b=0;
	while(a>=b) {
		R[0][1]+=C[a--];
		if(a>=b) R[0][1]+=C[b++];
	}
	//-+
	a=0,b=N-1;
	while(a<=b) {
		R[1][0]-=C[a++];
		if(a<=b) R[1][0]-=C[b--];
	}
	
	cout<<max(min(R[0][0],R[0][1]),min(R[1][0],R[1][1]))<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
