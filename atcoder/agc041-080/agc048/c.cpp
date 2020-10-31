#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> TL,TR;;

int N,L;
int A[101010],B[101010];
int T[101010];
map<int,int> le,ri;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	A[0]=B[0]=0;
	FOR(i,N) {
		cin>>A[i+1];
		A[i+1]-=i+1;
	}
	A[N+1]=B[N+1]=L-N;
	FOR(i,N) {
		cin>>B[i+1];
		B[i+1]-=i+1;
	}
	
	N+=2;
	
	FOR(i,N) if(ri.count(A[i])==0) ri[A[i]]=i;
	for(i=N-1;i>=0;i--) if(le.count(A[i])==0) le[A[i]]=i;
	
	
	FOR(i,N) {
		if(A[i]==B[i]) T[i]=i;
		if(A[i]<B[i]) {
			if(ri.count(B[i])==0) return _P("-1\n");
			T[i]=ri[B[i]];
			TR.set(T[i],1);
		}
		if(A[i]>B[i]) {
			if(le.count(B[i])==0) return _P("-1\n");
			T[i]=le[B[i]];
			TL.set(T[i],1);
		}
	}
	ll ret=0;
	FOR(i,N) {
		if(A[i]<B[i]) {
			ret++;
			ret+=TR(T[i]-1)-TR(i);
		}
		if(A[i]>B[i]) {
			ret++;
			ret+=TL(i-1)-TL(T[i]);
		}
	}
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
