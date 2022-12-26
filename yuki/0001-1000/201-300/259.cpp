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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

BIT<ll,20> lbt,rbt;

int N,Q;
int X,T,Y,Z;

void solve() {
	int i,j,k,l,r,x,y,z,t; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>s>>t>>y>>z;
		if(s=="L") {
			y += t;
			y = ((y%(2*N))+2*N)%(2*N);
			lbt.add(y+1,z);
		}
		if(s=="R") {
			y -= t;
			y = ((y%(2*N))+2*N)%(2*N);
			rbt.add(y+1,z);
		}
		if(s=="C") {
			ll sum=0;
			
			ll L=y+t,R=z-1+t;
			L = ((L%(2*N))+2*N)%(2*N);
			R = ((R%(2*N))+2*N)%(2*N);
			if(R<L) sum += lbt.total(R+1) + lbt.total(2*N)-lbt.total(L);
			else sum += lbt.total(R+1) - lbt.total(L);
			
			L=2*N-1-(z-1)+t,R=2*N-1-y+t;
			L = ((L%(2*N))+2*N)%(2*N);
			R = ((R%(2*N))+2*N)%(2*N);
			if(R<L) sum += lbt.total(R+1) + lbt.total(2*N)-lbt.total(L);
			else sum += lbt.total(R+1) - lbt.total(L);
			
			L=y-t,R=z-1-t;
			L = ((L%(2*N))+2*N)%(2*N);
			R = ((R%(2*N))+2*N)%(2*N);
			if(R<L) sum += rbt.total(R+1) + rbt.total(2*N)-rbt.total(L);
			else sum += rbt.total(R+1) - rbt.total(L);
			
			L=2*N-1-(z-1)-t,R=2*N-1-y-t;
			L = ((L%(2*N))+2*N)%(2*N);
			R = ((R%(2*N))+2*N)%(2*N);
			if(R<L) sum += rbt.total(R+1) + rbt.total(2*N)-rbt.total(L);
			else sum += rbt.total(R+1) - rbt.total(L);
			
			cout<<sum<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
