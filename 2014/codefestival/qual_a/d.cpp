#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,K;
ll po[20];

ll dodo(int cur,int mask) {
	if(cur<0) return 0;
	int i,mask2;
	ll mi=1LL<<60;
	ll cd=A/po[cur]%10;
	ll momo=A%(po[cur+1]);
	
	FOR(i,10) {
		int mask2;
		if(i==0 && mask==0) mask2=0;
		else mask2 = mask | (1<<i);
		int dg=__builtin_popcount(mask2);
		if(dg>K) continue;
		
		ll val=po[cur]*i;
		if(cd==i) val+=dodo(cur-1,mask2);
		else {
			int ds;
			if(i>cd) for(ds=0;ds<10;ds++) if(mask2&(1<<ds)) break;
			if(i<cd) for(ds=9;ds>=0;ds--) if(mask2&(1<<ds)) break;
			if(dg<K) ds=(i>cd)?0:9;
			val+=(po[cur]-1)/9*ds;
		}
		if(abs(val-momo)<abs(mi-momo)) mi=val;
	}
	return mi;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>K;
	po[0]=1;
	FOR(i,19) po[i+1]=po[i]*10;
	for(j=17;j>=0;j--) if(A/po[j]%10>0) break;
	cout << abs(A-dodo(j,0)) << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
