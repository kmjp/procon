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

int A,B,C,D;
ll mo=1000000007;

ll comb(int P_,int Q_) {
	static const int N_=4020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	
	ll ret=0;
	FOR(x,A-C+1) FOR(y,B-D+1) (ret += comb((A-C-x)+(B-D-y),(B-D-y)) * hcomb(D,x) % mo * hcomb(C,y))%=mo;
	cout<<ret * comb(C+D,D) % mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
