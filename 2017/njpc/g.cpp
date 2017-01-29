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
double D,X[1010],Y[1010];
pair<double,int> P[1010];
double TX[1010],TY[1010];
double dist[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double PI=atan(1)*4;
	cin>>N>>D;
	FOR(i,N) cin>>X[i]>>Y[i];
	srand(clock());
	
	vector<pair<int,pair<double,double>>> V;
	double cx=0,cy=0;
	FOR(i,N+1) {
		cx=cy=0;
		FOR(j,N) cx+=X[j],cy+=Y[j];
		cx/=N;
		cy/=N;
		double ave=0;
		FOR(j,N) ave+=hypot(X[j]-cx,Y[j]-cy);
		ave/=N;
		
		FOR(j,N) P[j]={atan2(Y[j]-cy,X[j]-cx),j};
		sort(P,P+N);
		
		if(i==N) break;
		
		//_P("(%lf,%lf) %lf\n",cx,cy,ave);
		int id=0;
		FOR(j,N) {
			TX[j]=cx-ave*cos(j*2*PI/N);
			TY[j]=cy-ave*sin(j*2*PI/N);
			dist[j]=hypot(X[P[j].second]-TX[j],Y[P[j].second]-TY[j]);
			//_P("%d:%d (%lf,%lf) (%lf) -> (%lf,%lf) d:%lf\n",i,P[j].second,X[P[j].second],Y[P[j].second],P[j].first,TX[j],TY[j],dist[j]);
			if(dist[j]>dist[id]) id=j;
		}
		
		if(dist[id]<=D/2) continue;
		
		int tar=P[id].second;
		double dx=TX[id]-X[tar];
		double dy=TY[id]-Y[tar];
		
		X[tar] += dx/dist[id]*D;
		Y[tar] += dy/dist[id]*D;
		
		V.push_back({tar+1,{X[tar],Y[tar]}});
	}
	
	_P("%d\n",V.size());
	FORR(r,V) _P("%d %.8lf %.8lf\n",r.first,r.second.first,r.second.second);
	
	FOR(i,N) _P("%d%c",1+P[i].second,(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
