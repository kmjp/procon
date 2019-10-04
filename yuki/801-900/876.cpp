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
BIT<ll,20> sum,num;

int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		sum.add(i+1,x);
		sum.add(i+2,-x);
	}
	FOR(i,N-1) {
		if(sum(i+1)!=sum(i+2)) num.add(i+1,1);
	}
	
	FOR(i,Q) {
		int T,L,R;
		cin>>T>>L>>R;
		if(T==1) {
			cin>>x;
			if(sum(L-1)!=sum(L)) num.add(L-1,-1);
			if(sum(R)!=sum(R+1)) num.add(R,-1);
			sum.add(L,x);
			sum.add(R+1,-x);
			if(sum(L-1)!=sum(L)) num.add(L-1,1);
			if(sum(R)!=sum(R+1)) num.add(R,1);
		}
		else {
			cout<<1+num(R-1)-num(L-1)<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
