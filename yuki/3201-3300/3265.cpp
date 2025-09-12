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


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> num,sum;

int N,M;
ll A[202020],P[202020],L[202020],R[202020];
int Q;
int X,Y,U,V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll ret=0;
	FOR(i,N) {
		cin>>A[i]>>L[i]>>R[i];
		P[i]=i+1;
		ret+=A[i]*(R[i]-L[i]+1);
		num.add(L[i],1);
		num.add(R[i]+1,-1);
		sum.add(i+1,A[i]);
	}
	FOR(i,N) {
		ret-=sum(R[i])-sum(L[i]-1);
	}
	
	
	cin>>Q;
	while(Q--) {
		cin>>X>>Y>>U>>V;
		X--;
		ret-=A[X]*(R[X]-L[X]+1);
		num.add(L[X],-1);
		num.add(R[X]+1,1);
		ret+=num(P[X])*A[X];
		ret+=sum(R[X])-sum(L[X]-1);
		sum.add(P[X],-A[X]);
		
		
		P[X]=Y;
		L[X]=U;
		R[X]=V;
		
		sum.add(P[X],A[X]);
		ret+=A[X]*(R[X]-L[X]+1);
		ret-=sum(R[X])-sum(L[X]-1);
		ret-=A[X]*num(P[X]);
		num.add(L[X],1);
		num.add(R[X]+1,-1);
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
