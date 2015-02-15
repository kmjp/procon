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

int N;
map<int,int> M;
int A[1010000];
int L[1010000],R[1010000];
ll ret,dif;


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,20> bt,bt2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], M[A[i]]=0;
	
	x=0;
	ITR(it,M) it->second=++x;
	FOR(i,N) A[i]=M[A[i]], R[A[i]]++;
	
	FOR(i,N) bt2.update(A[i],1);
	FOR(i,N) {
		bt2.update(A[i],-1);
		ret += 1LL*bt.total(A[i]-1)*bt2.total(A[i]-1);
		ret += 1LL*(i-bt.total(A[i]))*((N-i-1)-bt2.total(A[i]));
		bt.update(A[i],1);
	}
	FOR(i,N) {
		dif -= 1LL*L[A[i]]*R[A[i]];
		ret -= dif;
		L[A[i]]++;
		R[A[i]]--;
		dif += 1LL*L[A[i]]*R[A[i]];
	}
	
	
	cout<<ret-dif<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
