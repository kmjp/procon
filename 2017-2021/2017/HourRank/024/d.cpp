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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;


int N,M,X;
ll K;
int A[202020],B[202020];

ll hoge(ll v) {
	ZERO(bt.bit);
	ll num=0;
	int i,j;
	
	for(i=N-1;i>=0;i--) {
		if(i+X>=M) continue;
		if(i==N-1) {
			for(j=i+X;j<M;j++) bt.add(B[j],1);
		}
		else {
			bt.add(B[i+X],1);
		}
		
		ll v2=abs(v)/abs(A[i]);
		if(A[i]>0) {
			if(v<0) {
				v2=-v2;
				if(abs(v)%abs(A[i])) v2--;
			}
			v2=max(-1LL<<18,min(1LL<<18,v2))+(1<<19);
			num+=bt(v2);
		}
		else {
			if(v>=0) {
				v2=-v2;
				v2=max(-1LL<<18,min(1LL<<18,v2))+(1<<19);
				num+=bt((1<<20)-2)-bt(v2-1);
			}
			else {
				if(abs(v)%abs(A[i])) v2++;
				v2=max(-1LL<<18,min(1LL<<18,v2))+(1<<19);
				num+=bt((1<<20)-2)-bt(v2-1);
				
			}
		}
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i], B[i]+=1<<19;
	
	ll ret=1LL<<40;
	for(i=41;i>=0;i--) {
		if(hoge(ret-(1LL<<i))>=K) ret-=1LL<<i;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
