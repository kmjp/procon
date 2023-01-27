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
ll X[101010],Y[101010];
vector<pair<int,double>> E[101010];
double D[101010];
int cross(int a,int b,int c,int d) {
	ll XX[3],YY[3];
	XX[0]=X[b]-X[a]; YY[0]=Y[b]-Y[a];
	XX[1]=X[c]-X[a]; YY[1]=Y[c]-Y[a];
	XX[2]=X[d]-X[a]; YY[2]=Y[d]-Y[a];
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	if(c1>0&&c2>0||c1<0&&c2<0) return 0;
	XX[0]=X[d]-X[c]; YY[0]=Y[d]-Y[c];
	XX[1]=X[a]-X[c]; YY[1]=Y[a]-Y[c];
	XX[2]=X[b]-X[c]; YY[2]=Y[b]-Y[c];
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	if(c1>0&&c2>0||c1<0&&c2<0) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+2) cin>>X[i]>>Y[i];
	FOR(i,N) {
		ll dx=X[i]-X[(i+1)%N];
		ll dy=Y[i]-Y[(i+1)%N];
		double d=hypot(dx,dy);
		E[i].push_back({(i+1)%N,d});
		E[(i+1)%N].push_back({i,d});
	}
	
	vector<int> t={N,N+1};
	FOR(i,N) {
		ll dx=X[(i+N-1)%N]-X[i];
		ll dy=Y[(i+N-1)%N]-Y[i];
		ll px=X[(i+1)%N]-X[i];
		ll py=Y[(i+1)%N]-Y[i];
		
		FORR(n,t) {
			ll nx=X[n]-X[i];
			ll ny=Y[n]-Y[i];
			double d=hypot(nx,ny);
			if(dx*ny-dy*nx>=0||px*ny-py*nx<=0) {
				
				E[i].push_back({n,d});
				E[n].push_back({i,d});
			}
		}
	}
	
	int ok=1;
	FOR(i,N) {
		if(cross(N,N+1,i,(i+1)%N)) ok=0;
	}
	if(ok) {
		double d=hypot(X[N]-X[N+1],Y[N]-Y[N+1]);
		E[N].push_back({N+1,d});
	}
	FOR(i,N+2) D[i]=1e20;
	D[N]=0;
	priority_queue<pair<double,int>> Q;
	Q.push({0,N});
	while(Q.size()) {
		double co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(D[cur]!=co) continue;
		FORR2(e,d,E[cur]) if(D[e]>co+d) {
			D[e]=co+d;
			Q.push({-D[e],e});
		}
	}
	_P("%.12lf\n",D[N+1]);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
