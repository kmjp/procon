#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int X[1001],Y[1001],H[1001],TH[1001];
priority_queue<pair<int,int> > E[1001];
ll T[1001];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1001) while(E[i].size()) E[i].pop();
	FOR(i,1001) T[i]=1LL<<40;
	T[0]=0;
	
	ZERO(TH);
	cin>>N>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i]>>H[i];
		E[X[i]-1].push(make_pair(-H[i],Y[i]-1));
		E[Y[i]-1].push(make_pair(-H[i],X[i]-1));
	}
	
	ll tot=0;
	int np=1;
	
	while(np<N) {
		int mh=10000000;
		FOR(i,N) if(T[i]<1LL<<40) mh=min(mh,TH[i]);
		
		int num=0;
		pair<int,int> ev;
		ev.first=-9999999;
		x=-1;
		FOR(i,N) if(T[i]<1LL<<40 && TH[i]==mh) {
			num++;
			if(E[i].size() && ev.first<E[i].top().first) ev=E[i].top(), x=i;
		}
		ev.first*=-1;
		E[x].pop();
		tot+=(ev.first-mh)*(ll)num;
		FOR(i,N) if(T[i]<1LL<<40 && TH[i]==mh) TH[i]=ev.first;
		if(T[ev.second]==1LL<<40) T[ev.second]=tot;
		
		np=0;
		FOR(i,N) np+=T[i]<(1LL<<40);
	}
	FOR(i,N) _P("%lld%s", T[i],(i==(N-1))?"\n":" ");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	int T;
	cin>>T;
	FOR(i,T) {
		_P("Case #%d:\n",i+1);
		solve();
	}
	return 0;
}
