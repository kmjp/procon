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

int N;
ll A,B,S[101010];
ll mo=1000000007;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
};

BIT<ll,20> BTA,BTB;
vector<int> VA,VB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	S[0]=-1LL<<60;
	cin>>S[1];
	
	int LA=0,LB=0;
	
	BTA.add(0,1);
	BTB.add(0,1);
	VA.push_back(0);
	VB.push_back(0);
	for(i=2;i<=N;i++) {
		cin>>S[i];
		
		while(LA<i-2&&S[i]-S[LA+1]>=A) LA++;
		while(LB<i-2&&S[i]-S[LB+1]>=B) LB++;
		
		BTB.add(i-1,BTA.total(LA)%mo);
		BTA.add(i-1,BTB.total(LB)%mo);
		
		if(S[i]<S[i-1]+A) {
			FORR(r,VB) BTB.set(r,0);
			VB.clear();
		}
		if(S[i]<S[i-1]+B) {
			FORR(r,VA) BTA.set(r,0);
			VA.clear();
		}
		VA.push_back(i-1);
		VB.push_back(i-1);
	}
	
	cout<<(BTA.total(N+1)+BTB.total(N+1))%mo<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
