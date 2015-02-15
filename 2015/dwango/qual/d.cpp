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


int N,L;
ll tot=0;
vector<pair<ll,ll> > BB,CC;
ll mi=1LL<<62;

ll dodo(ll v) {
	int i,x,y;
	ll cx=0,cy=0;
	if(v<0) v+=tot;

	FOR(y,CC.size()) {
		if(v>=CC[y].first) v-=CC[y].first;
		else {
			cy=CC[y].first-v;
			break;
		}
	}
	
	ll ret=0;
	
	for(x=0,cx=BB[x].first ;;) {
		ll m=min(cx,cy);
		ret += m*min(abs(BB[x].second-CC[y].second),L-abs(BB[x].second-CC[y].second));
		cx-=m;
		cy-=m;
		if(cx==0) {
			if(++x>=BB.size()) break;
			cx=BB[x].first;
		}
		if(cy==0) {
			if(++y>=CC.size()) y=0;
			cy=CC[y].first;
		}
	}
	mi=min(mi,ret);
	return ret;
}

void test(ll LL,ll RR) {
	
	if(RR-LL<=9) {
		for(ll x=LL;x<=RR;x++) dodo(x);
		return;
	}
	
	ll m1=(2*LL+RR)/3;
	ll m2=(LL+2*RR)/3;
	ll d1=dodo(m1),d2=dodo(m2);
	if(d1<d2) test(LL,m2);
	else if(d1>d2) test(m1,RR);
	else test(m1,m2);
}
void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>r>>y>>z;
		x=min(y,z);
		tot+=y-x;
		if(y>x) BB.push_back(make_pair(y-x,r));
		if(z>x) CC.push_back(make_pair(z-x,r));
	}
	dodo(-tot+1);
	dodo(tot-1);
	test(-tot+1,tot-1);
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
