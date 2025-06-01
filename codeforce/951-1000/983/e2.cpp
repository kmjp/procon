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


int T,N;
ll A[202020];
ll B[202020];
ll C[202020];

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
	int lower_bound(V val) { //’P’²‘‰Á‚ÌŽž‚Ì‚ÝŽg‚¦‚é
		V v0=0,v1=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) {
			if((ent+(1<<i)-1)*(v0+bit[0][ent+(1<<i)-1])+(v1+bit[1][ent+(1<<i)-1])<val) {
				v0+=bit[0][ent+(1<<i)-1];
				v1+=bit[1][ent+(1<<i)-1];
				ent+=(1<<i);
			}
		}
		return ent;
	}
};
BIT_r<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	/*
	N=13;
	x=5;
	for(i=x+2;i<N+x;i+=2) {
		FOR(j,N/2+1) {
			B[(i+j*2)%N]++;
			A[(i+j*2)%N]++;
			A[(i+j*2)%N]++;
			A[(i+j*2+1)%N]++;
			A[(i+j*2-1)%N]++;
		}
	}
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	FOR(i,N) cout<<B[i]<<" ";
	cout<<endl;
	*/
	cin>>T;
	while(T--) {
		cin>>N;
		int ma=0;
		FOR(i,4*N) bt.add(i,i,-bt.total(i));
		FOR(i,N) {
			cin>>A[i];
			B[i]=0;
			if(i%2==0) {
				x=i/2;
			}
			else {
				x=(i+N)/2;
			}
			bt.add(x+1,x+N/2,A[i]);
			bt.add(x+N/2+1,x+N/2+1,-1LL*A[i]*(N/2));
			bt.add(x+N/2+1,x+N,-A[i]);
			bt.add(x+N/2+1,x+N/2+1,1LL*A[i]*(1+N/2));
		}
		
		FOR(i,4*N) {
			x=i*2%N;
			B[x]+=bt.total(i);
		}
		
		
		FOR(i,N) {
			C[i]=A[i]+2*B[i]+B[(i+1)%N]+B[(i+N-1)%N];
			assert(C[i]==C[0]);
		}
		
		FOR(i,N) cout<<B[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
