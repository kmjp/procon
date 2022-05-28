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

ll N,L,R;

int num[202020];
int A[502020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bit;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	
	int AL,AR,BL,BR;
	
	FOR(i,N) {
		num[i]=N-1-i;
		if(L) {
			if(L<=num[i]) {
				AL=i,AR=i+L;
				L=0;
			}
			else {
				L-=num[i];
			}
		}
		if(R) {
			if(R<=num[i]) {
				BL=i,BR=i+R;
				R=0;
			}
			else {
				R-=num[i];
			}
		}
	}
	FOR(i,N) A[i]=i+1;
	
	
	if(AL==BL) {
		for(x=AR;x<=BR;x++) {
			swap(A[AL],A[x]);
		}
	}
	else {
		for(x=AR;x<N;x++) {
			swap(A[AL],A[x]);
		}
		int step=BL-AL-1;
		if(step) {
			rotate(A+AL+1,A+N-step,A+N);
			reverse(A+AL+1,A+AL+step+1);
		}
		for(x=BL+1;x<=BR;x++) {
			swap(A[BL],A[x]);
		}
	}
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
