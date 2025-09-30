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
ll P,Q;
ll X[202020],A[202020],B[202020];
ll AA[202020],BB[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q;
	FOR(i,N) {
		cin>>X[i]>>A[i]>>B[i];
		A[i]=min(A[i],X[i]);
		B[i]=min(B[i],X[i]);
		if(A[i]+B[i]<X[i]) {
			cout<<"No"<<endl;
			return;
		}
		int fb=0,fa=0;
		if(X[i]>A[i]) {
			BB[i]=X[i]-A[i];
			Q-=X[i]-A[i];
		}
		if(X[i]>B[i]) {
			AA[i]=X[i]-B[i];
			P-=X[i]-B[i];
		}
		X[i]-=AA[i]+BB[i];
		A[i]-=AA[i];
		B[i]-=BB[i];
		assert(X[i]==A[i]&&X[i]==B[i]);
	}
	FOR(i,N) {
		ll a=min(P,X[i]);
		AA[i]+=a;
		BB[i]+=X[i]-a;
		P-=a;
		Q-=X[i]-a;
	}
	if(P<0||Q<0) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		FOR(i,N) cout<<AA[i]<<" "<<BB[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
