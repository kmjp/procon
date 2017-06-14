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

ll N,D;
ll X[101010],Y[101010];
pair<pair<ll,ll>,int> P[101010];
vector<int> V;
double L[101010],R[101010];
double ret[101010];

double cross(int a,int b) {
	double MX=(X[a]+X[b])/2.0;
	double MY=(Y[a]+Y[b])/2.0;
	double DX=(Y[b]-Y[a]);
	double DY=(X[b]-X[a]);
	double r=MY/DY;
	return MX+r*DX;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		P[i]={{X[i],Y[i]},i};
		L[i]=1e10;
		R[i]=-1e10;
	}
	sort(P,P+N);
	FOR(i,N) {
		if(V.size() && X[V.back()]==X[P[i].second]) continue;
		x=P[i].second;
		L[x]=-1e18;
		R[x]=1e18;
		double tar=-1e18;
		while(V.size()>=2) {
			int a=V[V.size()-2];
			int b=V[V.size()-1];
			
			double t1=cross(a,b);
			double t2=cross(b,x);
			
			if(t1<t2) break;
			L[b]=1e10;
			R[b]=-1e10;
			V.pop_back();
		}
		
		if(V.size()>=1) {
			R[V.back()]=L[x]=cross(V.back(),x);
		}
		V.push_back(x);
		
	}
	
	FOR(i,N) {
		if(L[i]<R[i]) ret[i]=max(0.0,min(R[i],1.0*D)-max(L[i],0.0));
		_P("%.12lf\n",ret[i]);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
