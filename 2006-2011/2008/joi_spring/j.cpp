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

int lef[140][140][140];
int N;
ll X[200],Y[200];
int dp[128][128];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) if(x!=y) FOR(z,N) if(z!=x && z!=y) {
		ll dx1=X[y]-X[x];
		ll dy1=Y[y]-Y[x];
		ll dx2=X[z]-X[x];
		ll dy2=Y[z]-Y[x];
		
		lef[x][y][z]=(dx1*dy2-dx2*dy1)>0;
	}
	int ma=0;
	double PI=atan(1)*4;
	FOR(x,N) for(y=x+1;y<N;y++) {
		ZERO(dp);
		dp[x][y]=2;
		vector<pair<double,int>> V;
		double ay=atan2(Y[y]-Y[x],X[y]-X[x]);
		V.push_back({-2,x});
		V.push_back({-1,y});
		FOR(z,N) if(z>x&&lef[x][y][z]) {
			double az=atan2(Y[z]-Y[x],X[z]-X[x])-ay;
			while(az<0) az+=PI;
			while(az>=PI) az-=PI;
			V.push_back({az,z});
		}
		sort(ALL(V));
		for(i=1;i<V.size();i++) {
			FOR(j,i) {
				ma=max(ma,dp[V[j].second][V[i].second]);
				for(k=i+1;k<V.size();k++) if(lef[V[j].second][V[i].second][V[k].second]) dp[V[i].second][V[k].second]=max(dp[V[i].second][V[k].second],dp[V[j].second][V[i].second]+1);
			}
		}
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
