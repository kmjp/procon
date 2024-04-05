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

int N,M;
int A[1010][1010];
ll S[1010][1010];

template<class V,int NV> class RMQ_2D {
private:
	V table[NV][NV][1<<NV][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-(1LL<<60);
	V comp(V l,V r){ return max(l,r);};
	RMQ_2D() {
		int i,j,x,y;
		NV2=1<<NV;
		for(i=2;i<	NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(j,NV) FOR(x,NV2) FOR(y,NV2) table[i][j][x][y]=def;
	}
	void set(int x,int y,V v){ table[0][0][x][y]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(j,NV) FOR(x,NV2) FOR(y,NV2) {
			if(i<NV-1) table[i+1][j][x][y]=comp(table[i][j][x][y],(x+(1<<i)<NV2)?table[i][j][x+(1<<i)][y]:def);
			if(j<NV-1) table[i][j+1][x][y]=comp(table[i][j][x][y],(y+(1<<j)<NV2)?table[i][j][x][y+(1<<j)]:def);
		}
	}
	V query(int L,int R,int T,int B) { //[L,R), [T,B)
		L=max(0,L), R=min(R,NV2), T=max(0,T), B=min(B,NV2);
		if(R<=L || B<=T) return def;
		int WL=LG[R-L],HL=LG[B-T];
		return comp(comp(table[WL][HL][L][T],table[WL][HL][R-(1<<WL)][T]),
			comp(table[WL][HL][L][B-(1<<HL)],table[WL][HL][R-(1<<WL)][B-(1<<HL)]));
	}
	
};

//set‚µ‚Äbuild‚·‚éB‚±‚ê‚Å‚à400MB‚È‚Ì‚Å‚¿‚å‚Á‚Æ‘å‚«‚¢
RMQ_2D<ll,10> rmq;


ll get(int y,int x) {
	if(y<0||x<0||y+M>N||x+M>N) return -1LL<<60;
	return S[y+M][x+M]-S[y][x+M]-S[y+M][x]+S[y][x];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+A[y][x];
	}
	FOR(y,N) FOR(x,N) {
		rmq.set(x,y,get(y,x));
	}
	rmq.build();
	
	ll ret=-1;
	FOR(x,N) if(x>=M&&x+M<=N) {
		FOR(y,N) if(y>=M&&y+M<=N) {
			ret=max(ret,rmq.query(0,x-M+1,0,N)+rmq.query(x,N-M+1,0,y-M+1)+rmq.query(x,N-M+1,y,N));
			ret=max(ret,rmq.query(x,N-M+1,0,N)+rmq.query(0,x-M+1,0,y-M+1)+rmq.query(0,x-M+1,y,N));
			ret=max(ret,rmq.query(0,N,0,y-M+1)+rmq.query(0,x-M+1,y,N)+rmq.query(x,N,y,N));
			ret=max(ret,rmq.query(0,N,y,N)+rmq.query(0,x-M+1,0,y-M+1)+rmq.query(x,N,0,y-M+1));
		}
	}
	FOR(i,N) for(j=i+1;j<N;j++) {
		if(i>=M&&i+M<=j&&j+M<=N) {
			ret=max(ret,rmq.query(0,i-M+1,0,N)+rmq.query(i,j-M+1,0,N)+rmq.query(j,N,0,N));
			ret=max(ret,rmq.query(0,N,0,i-M+1)+rmq.query(0,N,i,j-M+1)+rmq.query(0,N,j,N));
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
