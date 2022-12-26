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

int N;
int X[2020],Y[2020];
const ll mo=1000000007;


void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	ll ret=0;
	FOR(i,N) {
		vector<pair<double,int>> V;
		FOR(j,N) if(X[i]!=X[j]||Y[i]!=Y[j]) {
			double t=atan2(Y[j]-Y[i],X[j]-X[i]);
			if(t<0) t+=2*pi;
			V.push_back({t,j});
			V.push_back({t+2*pi,j});
		}
		sort(ALL(V));
		ll SX=0,SY=0;
		int L=0,R=0;
		FOR(L,V.size()/2) {
			if(V[L].first>=2*pi) break;
			double t=V[L].first;
			x=V[L].second;
			while(V[R].first<t+pi) {
				SX+=(X[V[R].second]-X[i]);
				SY+=(Y[V[R].second]-Y[i]);
				R++;
			}
			
			(ret+=(X[x]-X[i])*SY-(Y[x]-Y[i])*SX)%=mo;
			SX-=X[x]-X[i];
			SY-=Y[x]-Y[i];
			
		}
	}
	
	cout<<(ret%mo+mo)*((mo+1)/3)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
