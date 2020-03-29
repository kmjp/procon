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
int C[505050];
vector<int> B[505050];
int L[505050],R[505050];

template<class V,int NV> class RMQ_ma {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-(1<<20);
	V comp(V l,V r){ return max(l,r);};
	RMQ_ma() {
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
template<class V,int NV> class RMQ_mi {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=(1<<20);
	V comp(V l,V r){ return min(l,r);};
	RMQ_mi() {
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

RMQ_mi<int,19> ri;
RMQ_ma<int,19> le;


map<int,pair<int,int>> memo[505050];
pair<int,int> hoge(int PL,int PR) {
	if(memo[PL].count(PR)) return memo[PL][PR];
	int OL=PL;
	int OR=PR;
	
	int i;
	for(i=19;i>=0;i--) if(OR+(1<<i)<N && ri.query(OR+1,OR+(1<<i)+1)>=OL) OR+=1<<i;
	for(i=19;i>=0;i--) if(OL>=(1<<i) && le.query(OL-(1<<i),OL)<=OR) OL-=1<<i;
	
	if(OL!=PL || OR!=PR) return memo[PL][PR]=hoge(OL,OR);
	else return memo[PL][PR]={PL,PR};
	
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>C[i];
		C[i]--;
	}
	FOR(i,N) L[i]=-1,R[i]=N+1;
	
	FOR(i,N) {
		if(i) ri.set(i,L[C[i-1]]);
		cin>>x;
		while(x--) {
			cin>>y;
			B[i].push_back(y-1);
			L[y-1]=i;
		}
	}
	for(i=N-1;i>=0;i--) {
		if(i<N-1) le.set(i,R[C[i]]);
		FORR(b,B[i]) R[b]=i;
	}
	
	ri.build();
	le.build();
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		auto a=hoge(x-1,x-1);
		if(a.first<=y-1&&y-1<=a.second) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
