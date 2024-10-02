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
int A[603],B[603];
int R[303];

int cross(int a,int b,int c,int d) {
	ll XX[3],YY[3];
	XX[0]=A[b]-A[a]; YY[0]=B[b]-B[a];
	XX[1]=A[c]-A[a]; YY[1]=B[c]-B[a];
	XX[2]=A[d]-A[a]; YY[2]=B[d]-B[a];
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if(c1>0&&c2>0||c1<0&&c2<0) return 0;
	XX[0]=A[d]-A[c]; YY[0]=B[d]-B[c];
	XX[1]=A[a]-A[c]; YY[1]=B[a]-B[c];
	XX[2]=A[b]-A[c]; YY[2]=B[b]-B[c];
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	if(c1>0&&c2>0||c1<0&&c2<0) return 0;
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	FOR(i,N) cin>>A[N+i]>>B[N+i];
	FOR(i,N) R[i]=N+i;
	sort(V,V+N,cmp);
	int up=1;
	while(up) {
		up=0;
		FOR(i,N) FOR(j,i) if(cross(i,R[i],j,R[j])) swap(R[i],R[j]), up=1;
	}
	FOR(i,N) FOR(j,i) assert(cross(i,R[i],j,R[j])==0);
	FOR(i,N) cout<<R[i]+1-N<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
