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
	V bit[1<<ME],val[1<<ME];
	V total(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bt1,bt2;

int N,M;
int X[101010],A[101010],B[101010];
vector<int> V[101010];
int R1,R2,R3;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int R3=0;
	FOR(i,N) {
		cin>>X[i]>>A[i]>>B[i];
		if(X[i]>=3) R3++, i--, N--;
		else {
			V[A[i]].push_back(i);
			if(X[i]==1) bt1.add(B[i],1),R1++;
			if(X[i]==2) bt2.add(B[i],1),R2++;
		}
	}
	
	int mi=101010;
	for(i=100001;i>=0;i--) {
		FORR(e,V[i]) {
			if(X[e]==0) {
				bt1.add(B[e],1),R1++;
			}
			if(X[e]==1) {
				bt1.add(B[e],-1),R1--;
				bt2.add(B[e],1),R2++;
			}
			if(X[e]==2) {
				bt2.add(B[e],-1),R2--;
				R3++;
			}
		}
		
		int need=M-min(M,R2+R3);
		if(need>R1) continue;
		
		int diff=(1<<18)-1;
		for(j=17;j>=0;j--) if(R1-bt1.total(diff-(1<<j)-1)<need) diff-=1<<j;
		mi=min(mi,R3+(R2-bt2.total(diff-2)));
		
	}
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
