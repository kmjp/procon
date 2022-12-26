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

template<class V,int NV> class RMQ_2D {
private:
	V table[NV][1<<NV][1<<NV];
	int NV2;
public:
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	RMQ_2D() { init();}
	void init(){ NV2=1<<NV;int i,j,x,y; FOR(i,NV) FOR(x,NV2) FOR(y,NV2) table[i][x][y]=def;}
	void set(int x,int y,V v){ table[0][x][y]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV-1) FOR(x,NV2) FOR(y,NV2) {
			int sz=1<<i;
			table[i+1][x][y]=comp(comp(table[i][x][y],table[i][x+sz][y]),
				comp(table[i][x][y+sz],table[i][x+sz][y+sz]));
		}
	}
	V query(int L,int T,int S) { //[L,L+S), [T,T+S)
		int level=0;
		while(1<<(level+1) <= S) level++;
		return comp(comp(table[level][L][T],table[level][L+S-(1<<level)][T]),
			comp(table[level][L][T+S-(1<<level)],table[level][L+S-(1<<level)][T+S-(1<<level)]));
	}
	
};

int Q;
int H,W,K;
int X[400][400];
int S[355][355];

int num[182];
RMQ_2D<int,9> rmq_u,rmq_d,rmq_l,rmq_r;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=180;i++) {
		for(j=1;j<=i;j++) num[i] += (2*j-1)*(2*j-1);
	}
	
	cin>>Q;
	while(Q--) {
		rmq_u.init();
		rmq_d.init();
		rmq_l.init();
		rmq_r.init();
		
		cin>>H>>W>>K;
		FOR(y,H) FOR(x,W) {
			cin>>X[y][x];
			S[y+1][x+1]=X[y][x]+S[y+1][x]+S[y][x+1]-S[y][x];
			rmq_u.set(y,x,X[y][x]+y);
			rmq_d.set(y,x,X[y][x]-y);
			rmq_l.set(y,x,X[y][x]+x);
			rmq_r.set(y,x,X[y][x]-x);
		}
		
		rmq_u.build();
		rmq_d.build();
		rmq_l.build();
		rmq_r.build();
		
		
		int ma=0;
		for(int h=1;h<180;h++) {
			for(y=h-1;y+(h-1)<H;y++) {
				for(x=h-1;x+(h-1)<W;x++) {
					
					int tot=S[y+h][x+h]-S[y-(h-1)][x+h]-S[y+h][x-(h-1)]+S[y-(h-1)][x-(h-1)];
					if(tot+K<num[h]) continue;
					
					int ma_u = rmq_u.query(y-(h-1),x-(h-1),2*h-1)-y;
					int ma_d = rmq_d.query(y-(h-1),x-(h-1),2*h-1)+y;
					int ma_l = rmq_l.query(y-(h-1),x-(h-1),2*h-1)-x;
					int ma_r = rmq_r.query(y-(h-1),x-(h-1),2*h-1)+x;
					
					if(max({ma_u,ma_d,ma_l,ma_r})>h) continue;
					ma=h;
					goto out;
				}
			}
			out:
			;
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
