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
ll mo=1000000007;
ll p2[2020];

ll cr(int a,int b) {
	ll ret=1LL*X[a]*Y[b]-1LL*X[b]*Y[a];
	return (ret%mo+mo)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,2001) p2[i+1]=p2[i]*2%mo;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	double pi=atan(1)*4;
	ll ret=0;
	FOR(i,N) {
		vector<pair<double,int>> V;
		FOR(j,N) if(i!=j) {
			double d=atan2(Y[j]-Y[i],X[j]-X[i]);
			V.push_back({d,j});
			V.push_back({d+2*pi,j});
		}
		sort(ALL(V));
		for(j=r=0;j<N-1;j++) {
			while(V[r].first<V[j].first+pi) r++;
			(ret+=(p2[r-j-1]+mo-1)*cr(i,V[j].second))%=mo;
		}
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
