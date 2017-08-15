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

int X,Y,Z,N;
ll A[101010],B[101010],C[101010];
pair<int,int> P[101010];
ll XS,YS,ZS;
set<pair<int,int>> XX,YY,ZY;
int inz[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Z;
	N=X+Y+Z;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		P[i]={B[i]-A[i],i};
	}
	
	sort(P,P+N);
	FOR(i,N) {
		x=P[i].second;
		if(i<X) {
			XS+=A[x];
			XX.insert({A[x]-C[x],x});
		}
		else {
			YS+=B[x];
			YY.insert({B[x]-C[x],x});
			
			if(YY.size()>Y) {
				auto it=YY.begin();
				ZY.insert(*it);
				x=it->second;
				YY.erase(it);
				YS-=B[x];
				ZS+=C[x];
				inz[x]=1;
			}
			
		}
	}
	
	ll ret=XS+YS+ZS;
	
	for(i=X;i<X+Z;i++) {
		x=P[i].second;
		if(inz[x]==1) {
			ZS-=C[x];
			ZY.erase({B[x]-C[x],x});
			inz[x]=0;
		}
		else {
			YS-=B[x];
			auto it=*ZY.rbegin();
			ZY.erase(it);
			inz[it.second]=0;
			ZS-=C[it.second];
			YS+=B[it.second];
		}
		
		XS+=A[x];
		XX.insert({A[x]-C[x],x});
		auto it=XX.begin();
		x=it->second;
		XX.erase(it);
		XS-=A[x];
		ZS+=C[x];
		
		ret=max(ret,XS+YS+ZS);
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
