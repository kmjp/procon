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
BIT<ll,20> btL,btR,btLS,btRS;

int N,Q;
string S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		if(S[i]=='(') btL.add(i,1),btLS.add(i,i);
		if(S[i]==')') btR.add(i,1),btRS.add(i,i);
	}
	while(Q--) {
		cin>>x;
		x--;
		if(S[x]=='(') {
			btL.add(x,-1),btLS.add(x,-x);
			btR.add(x,1),btRS.add(x,x);
			S[x]=')';
		}
		else {
			btL.add(x,1),btLS.add(x,x);
			btR.add(x,-1),btRS.add(x,-x);
			S[x]='(';
		}
		
		k=0;
		for(i=20;i>=0;i--) {
			int tk=k+(1<<i);
			if(btL(N)<tk) continue;
			if(btR(N)<tk) continue;
			
			int L=N,R=0;
			for(j=20;j>=0;j--) {
				if(btL(L-(1<<j))>=tk) L-=1<<j;
				if(btR(N)-btR(R+(1<<j)-1)>=tk) R+=1<<j;
			}
			if(L<R) k=tk;
		}
		int m=0;
		ll ret=1LL*k*(2*k+k-1)/2-1LL*k*(k-1)/2;
		
		for(i=20;i>=0;i--) {
			int tm=m+(1<<i);
			if(btL(N)<k+tm) continue;
			if(btR(N)<k+tm) continue;
			int L=N,R=0;
			for(j=20;j>=0;j--) {
				if(btL(L-(1<<j))>=k+tm) L-=1<<j;
				if(btR(N)-btR(R+(1<<j)-1)>=k+tm) R+=1<<j;
			}
			
			int M=L-R-1;
			int A=btL(R);
			int B=btR(N)-btR(L);
			if(A+B-(M+1)>0) {
				m=tm;
				ret=1LL*(2*(A+M+2)+B-1)*B/2-1LL*A*(A-1)/2+(btRS(L)-btRS(R-1)-1LL*(R-A)*(k+tm-B))-(btLS(L)-btLS(R-1)-1LL*(R-A)*(k+tm-A));
				/*
				cout<<k<<" "<<tm<<" "<<L<<" "<<R<<" "<<A<<" "<<B<<endl;
				cout<<(btRS(L)-btRS(R-1)-1LL*(R-A)*(k+tm-B))<<endl;
				cout<<btRS(L)-btRS(R-1)<<endl;
				cout<<S<<" "<<ret<<endl;
				*/
			}
		}
		
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
