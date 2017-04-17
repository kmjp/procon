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
ll L,T;
ll X[101010],W[101010];
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>T;
	int id=-1;
	L*=2;
	T*=2;
	FOR(i,N) {
		cin>>X[i]>>W[i];
		X[i]*=2;
		if(W[i]==1 && id==-1) id=i;
	}
	if(id==-1) {
		FOR(i,N) {
			X[i]=((X[i]-T)%L+L)%L;
			_P("%d\n",X[i]/2);
		}
		return;
	}
	ll hit=0;
	vector<ll> V;
	FOR(i,N) {
		if(W[i]==1) V.push_back((X[i]+T)%L);
		else V.push_back(((X[i]-T)%L+L)%L);
	}
	sort(ALL(V));
	
	FOR(i,N) if(W[i]==2) {
		ll dif=(i>id)?(X[i]-X[id]):(L+X[i]-X[id]);
		ll TT=T;
		if(dif/2<=TT) {
			hit++;
			TT-=dif/2;
		}
		hit+=TT/(L/2);
	}
	ll tid=(id+hit)%N;
	ll TX=(X[id]+T)%L;
	
	for(i=N-1;i>=0;i--) if(V[i]==TX) {
		FOR(j,N) {
			ret[(tid+j)%N]=V[(i+j)%N]/2;
		}
		break;
	}
	
	FOR(i,N) _P("%lld\n",ret[i]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
