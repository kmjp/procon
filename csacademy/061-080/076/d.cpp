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
map<int,int> M;
vector<pair<ll,ll>> V;

ll hoge(ll X,ll Y1,ll Y2) {
	if(Y1>Y2) swap(Y1,Y2);
	
	if(Y2-Y1==X) return (Y1+Y2)*(X+1)/2;
	if(Y1+Y2-1<X) return (Y1*(Y1+1)+Y2*(Y2+1))/2;
	
	ll D=Y2-Y1;
	ll ret=(Y2+(Y2-(D-1)))*D/2;
	X-=D;
	
	if(X%2==0) {
		return ret+2*hoge(X/2-1,Y1-(X/2-1),Y1)+(Y1-(X/2));
	}
	else {
		return ret+2*hoge(X/2,Y1-(X/2),Y1);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		M[y]=max(M[y],x);
	}
	
	FORR(m,M) V.push_back(m);
	FOR(i,V.size()-1) V[i+1].second=max(V[i+1].second,V[i].second-(V[i+1].first-V[i].first));
	for(i=V.size()-2;i>=0;i--) V[i].second=max(V[i].second,V[i+1].second-(V[i+1].first-V[i].first));
	
	ll ret=0;
	ret+=V[0].second*(V[0].second-1)/2;
	ret+=V.back().second*(V.back().second-1)/2;
	FOR(i,V.size()-1) ret+=hoge(V[i+1].first-V[i].first,V[i].second,V[i+1].second);
	for(i=1;i<V.size()-1;i++) ret-=V[i].second;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
