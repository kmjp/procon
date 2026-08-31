#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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
template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	V comp(V l,V r){ return __gcd(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build(int MV=-1) { //MVはサイズ指定
		if(MV==-1) MV=NV2;
		int i,j,x,y;
		FOR(i,NV) FOR(x,MV) table[i+1][x]=comp(table[i][x],(x+(1<<i)<MV)?table[i][x+(1<<i)]:0);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return 0;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};

RMQ<int,18> rmq;


class Solution {
public:
	int N;
	int get(int L,int R,int M) {
		if(M<L||M>=R) return rmq.query(L,R);
		if(L==M) return rmq.query(L+1,R);
		if(R==M+1) return rmq.query(L,R-1);
		return __gcd(rmq.query(L,M),rmq.query(M+1,R));
		
	}
    int maxValidSplits(vector<int>& nums) {
		N=nums.size();
		int i,j;
		
		FOR(i,N) {
			rmq.set(i,nums[i]);
		}
		rmq.build(N);
		
		int ma=0;
		FOR(i,N-1) if(rmq.query(0,i+1)==rmq.query(i+1,N)) ma++;
		FOR(i,N) {
			int g=get(0,N,i);
			int L=N;
			int R=0;
			
			for(j=16;j>=0;j--) {
				if(R-L+1+(4<<j)<ma) break;
				if(L-(1<<j)>=0&&get(0,L-(1<<j),i)==g) L-=1<<j;
				if(R+(1<<j)<N&&get(R+(1<<j),N,i)==g) R+=1<<j;
			}
			int ret=R-L+1;
			if(L<=i&&i<=R) ret--;
			ma=max(ma,ret);
		}
		return ma;
		
        
    }
};

