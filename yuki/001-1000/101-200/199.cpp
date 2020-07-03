#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int X[5],Y[5];
int P[5];

template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

bool ok() {
	int i;
	pair<ll,ll> PP[5];
	FOR(i,5) PP[i]=make_pair(X[P[i]],Y[P[i]]);
	
	FOR(i,5) {
		ll c1=veccross(PP[i],PP[(i+1)%5],PP[(i+2)%5]);
		ll c2=veccross(PP[i],PP[(i+1)%5],PP[(i+3)%5]);
		ll c3=veccross(PP[i],PP[(i+1)%5],PP[(i+4)%5]);
		if(c1*c2>=0 || c3*c2>=0) return false;
		
	}
	/*
	if(veccross(PP[i],PP[1],PP[2])*veccross(PP[0],PP[1],PP[3])>=0) return false;
	if(veccross(PP[0],PP[1],PP[2])*veccross(PP[0],PP[1],PP[3])>=0) return false;
	if(veccross(PP[0],PP[1],PP[4])*veccross(PP[0],PP[1],PP[3])>=0) return false;
	if(veccross(PP[1],PP[2],PP[0])*veccross(PP[1],PP[2],PP[4])>=0) return false;
	if(veccross(PP[1],PP[2],PP[3])*veccross(PP[1],PP[2],PP[4])>=0) return false;
	if(veccross(PP[2],PP[3],PP[0])*veccross(PP[2],PP[3],PP[1])>=0) return false;
	if(veccross(PP[2],PP[3],PP[0])*veccross(PP[2],PP[3],PP[4])>=0) return false;
	if(veccross(PP[3],PP[4],PP[1])*veccross(PP[3],PP[4],PP[0])>=0) return false;
	if(veccross(PP[3],PP[4],PP[1])*veccross(PP[3],PP[4],PP[2])>=0) return false;
	if(veccross(PP[4],PP[0],PP[2])*veccross(PP[4],PP[0],PP[1])>=0) return false;
	if(veccross(PP[4],PP[0],PP[2])*veccross(PP[4],PP[0],PP[3])>=0) return false;
	*/
	return true;
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,5) {
		cin>>X[i]>>Y[i];
		P[i]=i;
	}
	do {
		if(ok()) return _P("YES\n");
	} while(next_permutation(P,P+5));
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
