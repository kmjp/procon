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

ll K,N,M;
ll S[101010],T[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<ll,int> C;
	C[-1]=0;
	cin>>K>>N>>M;
	FOR(i,K) {
		cin>>S[i];
		T[i]=S[i]+(N-M)*100;
		C[S[i]]=C[T[i]]=0;
	}
	C[1LL<<40]=0;
	x=0;
	FORR(m,C) m.second=x++;
	FOR(i,K) S[i]=C[S[i]],T[i]=C[T[i]];
	FOR(i,K) A.add(T[i],1);
	FOR(i,K) {
		A.add(T[i],-1);
		if(A(x)-A(S[i])<(K+11)/12) cout<<(i+1)<<endl;
		A.add(T[i],1);
	}
	cout<<"--------"<<endl;
	FOR(i,K) B.add(S[i],1);
	FOR(i,K) {
		if(B(x)-B(T[i])<(K+11)/12) cout<<(i+1)<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
