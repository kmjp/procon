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

int N,M;
int T[101010];

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(x,NV2) table[i+1][x]=comp(table[i][x],(x+(1<<i)<NV2)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};

RMQ<int,18> rmq;
vector<int> V;
int L[101010],R[101010];

int cmp(int A,int B) {
	int L1=L[A],R1=R[A];
	int L2=L[B],R2=R[B];
	if(L1<=L2&&R2<=L1) return 0;
	if(L2<=L1&&R1<=L2) return 1;
	
	int AL=L1,AR=R1;
	int BL=L2,BR=R2;
	if(L2<=L1) AL=max(AL,R2+1);
	if(R2>=R1) AR=min(AR,L2-1);
	if(L1<=L2) BL=max(BL,R1+1);
	if(R1>=R2) BR=min(BR,L1-1);
	
	return rmq.query(AL,AR+1)<=rmq.query(BL,BR+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		rmq.set(i+1,x);
	}
	rmq.build();
	cin>>M;
	FOR(i,M) {
		V.push_back(i);
		cin>>L[i]>>R[i];
	}
	sort(ALL(V),cmp);
	FORR(v,V) cout<<(v+1)<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
