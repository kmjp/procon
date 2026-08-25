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

int N,Q;
ll X[303030],Y[303030];
int U[303030],V[303030];
const int DI=100;

vector<pair<int,int>> ev[1003];
long double RX[302020],RY[303030];

long double area2(int a,int b,int c) {
	ll X1=X[b]-X[a];
	ll X2=X[c]-X[a];
	ll Y1=Y[b]-Y[a];
	ll Y2=Y[c]-Y[a];
	return abs(X1*Y2-X2*Y1);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[N+i]=X[i];
		Y[N+i]=Y[i];
	}
	FOR(i,Q) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		if(U[i]>V[i]) V[i]+=N;
		ev[U[i]/DI].push_back({V[i],i});
	}
	
	FOR(i,1003) if(ev[i].size()) {
		long double area=0;
		long double cx=0,cy=0;
		int CL=i*DI,CR=CL+1;
		sort(ALL(ev[i]));
		FORR2(TV,e,ev[i]) {
			int TU=U[e];
			
			while(CR<TV) {
				long double na=area2(CL,CR,CR+1);
				long double nx=(X[CL]+X[CR]+X[CR+1]);
				long double ny=(Y[CL]+Y[CR]+Y[CR+1]);
				
				cx=(nx*na+cx*area)/(na+area);
				cy=(ny*na+cy*area)/(na+area);
				area+=na;
				CR++;
			}
			while(TU<CL) {
				long double na=area2(CL-1,CL,CR);
				long double nx=(X[CL-1]+X[CL]+X[CR]);
				long double ny=(Y[CL-1]+Y[CL]+Y[CR]);
				
				cx=(nx*na+cx*area)/(na+area);
				cy=(ny*na+cy*area)/(na+area);
				area+=na;
				CL--;
			}
			while(TU>CL) {
				long double na=-area2(CL,CL+1,CR);
				long double nx=(X[CL]+X[CL+1]+X[CR]);
				long double ny=(Y[CL]+Y[CL+1]+Y[CR]);
				
				cx=(nx*na+cx*area)/(na+area);
				cy=(ny*na+cy*area)/(na+area);
				area+=na;
				CL++;
			}
			
			
			RX[e]=cx/3;
			RY[e]=cy/3;
		}
	}
	FOR(i,Q) _P("%.12lf %.12lf\n",(double)RX[i],(double)RY[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
