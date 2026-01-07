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

int N,T,Q;
int L[101010],R[101010],V[101010];
int QL[101010],QR[101010];
ll X[101010];
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
int ret[101010];
vector<int> cand[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T>>Q;
	FOR(i,T) {
		cin>>L[i]>>R[i]>>V[i];
		bt.add(L[i],R[i],V[i]);
	}
	FOR(i,Q) {
		cin>>QL[i]>>QR[i]>>X[i];
		if(bt.total(QR[i])-bt.total(QL[i]-1)<X[i]) ret[i]=-1;
		else ret[i]=T;
	}
	
	for(j=19;j>=0;j--) {
		FOR(i,T+1) {
			cand[i].clear();
		}
		FOR(i,N+1) {
			bt.add(i,i,-bt.total(i));
		}
		FOR(i,Q) if(ret[i]-(1<<j)>0) cand[ret[i]-(1<<j)].push_back(i);
		FOR(i,T) {
			bt.add(L[i],R[i],V[i]);
			FORR(c,cand[i+1]) {
				if(bt.total(QR[c])-bt.total(QL[c]-1)>=X[c]) ret[c]=i+1;
			}
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
