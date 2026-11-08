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

int T,N,K;
int A[404040];
vector<int> P[404040];

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
};
BIT_r<ll,21> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,K) P[i].clear();
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			P[A[i]].push_back(i);
			bt.add(i,i,-bt.total(i));
		}
		FOR(i,K) {
			x=P[i][0];
			bt.add(0,0,x);
			bt.add(1,x,-1);
			x=P[i].back();
			bt.add(x+1,N-1,1);
			FOR(j,P[i].size()-1) {
				x=P[i][j];
				y=P[i][j+1];
				bt.add(x+1,y-1,1);
				bt.add((x+y)/2+1,y,-2);
				bt.add(y,y,1);
				if((y-x)%2) {
					bt.add((x+y)/2+1,(x+y)/2+1,1);
				}	
			}
		}
		ll ret=1LL<<60;
		FOR(i,N) ret=min(ret,bt.total(i));
		FOR(i,K) ret-=abs(i-(K-1)/2);
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
