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

int N,M;
ll X[333],Y[333];
double E[333][333];

int cross(int a,int b,int c,int d) {
	ll XX[3],YY[3];
	XX[0]=X[b]-X[a]; YY[0]=Y[b]-Y[a];
	XX[1]=X[c]-X[a]; YY[1]=Y[c]-Y[a];
	XX[2]=X[d]-X[a]; YY[2]=Y[d]-Y[a];
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if(c1>=0&&c2>=0||c1<=0&&c2<=0) return 0;
	XX[0]=X[d]-X[c]; YY[0]=Y[d]-Y[c];
	XX[1]=X[a]-X[c]; YY[1]=Y[a]-Y[c];
	XX[2]=X[b]-X[c]; YY[2]=Y[b]-Y[c];
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	if(c1>=0&&c2>=0||c1<=0&&c2<=0) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	N*=2;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) {
		E[x][y]=hypot(X[x]-X[y],Y[x]-Y[y]);
		if(x==y) continue;
		
		FOR(i,N/2) {
			if(x/2==i) continue;
			if(y/2==i) continue;
			if(cross(x,y,i*2,i*2+1)) E[x][y]=1LL<<60;
		}
	}
	FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	
	while(M--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		_P("%.12lf\n",E[(a-1)*2+(b-1)][(c-1)*2+(d-1)]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
