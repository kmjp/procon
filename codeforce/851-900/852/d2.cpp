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

int N,P[202020],Q[202020];
int RP[202020],RQ[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		RP[P[i]-1]=i;
	}
	FOR(i,N) {
		cin>>Q[i];
		RQ[Q[i]-1]=i;
	}
	ll ret=0;
	//mex=0;
	x=min(RP[0],RQ[0]);
	y=max(RP[0],RQ[0]);
	ret+=1LL*x*(x+1)/2;
	ret+=1LL*(N-1-y)*(N-y)/2;
	ret+=1LL*(y-x-1)*(y-x)/2;
	int CL=N,CR=-1;
	//mex=N+1
	ret++;
	FOR(i,N-1) {
		CL=min({CL,RP[i],RQ[i]});
		CR=max({CR,RP[i],RQ[i]});
		x=min(RP[i+1],RQ[i+1]);
		y=max(RP[i+1],RQ[i+1]);
		if(CL<=x&&x<=CR) continue;
		if(CL<=y&&y<=CR) continue;
		if(y<CL) {
			x=y;
			y=N;
		}
		else if(x>CR) {
			y=x;
			x=-1;
		}
		ret+=1LL*(CL-x)*(y-CR);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
