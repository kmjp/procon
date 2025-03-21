#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int P[202020];
int S[20][1202020];
ll cnt[202020];
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
	void build(int MV=-1) { //MVはサイズ指定
		if(MV==-1) MV=NV2;
		int i,j,x,y;
		FOR(i,NV) FOR(x,MV) table[i+1][x]=comp(table[i][x],(x+(1<<i)<MV)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};

RMQ<int,18> rmq;
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		rmq.set(i,P[i]);
	}
	rmq.build(N);
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		deque<array<int,3>> D;
		D.push_back({x-1,y-x+1,0});
		while(D.size()) {
			auto p=D.front();
			D.pop_front();
			int len=p[1];
			int lv=p[2];
			if((len>>lv)>1) {
				
				S[lv][p[0]]++;
				x=((len>>(lv+1))<<(lv+1));
				S[lv][p[0]+x]--;
				if((len>>lv)%2) {
					D.push_front({p[0]+x,1<<lv,lv});
				}
				D.push_back({p[0],x,lv+1});
				continue;
			}
			if(D.empty()) break;
			auto q=D.front();
			D.pop_front();
			int len2=q[1];
			int lv2=q[2];
			if(len2>>lv2>1) {
				D.push_front({q[0]+(1<<lv2),len2-(1<<lv2),lv2});
			}
			q[1]=1<<lv2;
			x=rmq.query(p[0],p[0]+(1<<lv));
			y=rmq.query(q[0],q[0]+(1<<lv2));
			if(x>y) {
				cnt[x]++;
				D.push_back(p);
			}
			else {
				cnt[y]++;
				D.push_back(q);
			}
		}
	}
	
	FOR(i,19) {
		FOR(j,N) if(S[i][j]) {
			S[i][j+(2<<i)]+=S[i][j];
			x=rmq.query(j,j+(2<<i));
			cnt[x]+=S[i][j];
		}
	}
	FOR(i,N) cout<<cnt[i+1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
