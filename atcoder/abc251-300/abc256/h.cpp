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

int N,Q;
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
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	M[0]=0;
	M[N+1]=0;
	FOR(i,N) {
		cin>>x;
		bt.add(i+1,i+1,x);
		M[i+1]=x;
	}
	while(Q--) {
		int L,R;
		cin>>i>>L>>R;
		
		if(i==1||i==2) {
			R++;
			int v;
			cin>>v;
			auto it=M.lower_bound(L+1);
			it--;
			M[L]=it->second;
			it=M.lower_bound(R+1);
			it--;
			M[R]=it->second;
			if(i==1) {
				int nex=L;
				while(nex<R) {
					auto it=M.lower_bound(nex);
					x=it->first;
					y=next(it)->first;
					r=it->second;
					bt.add(x,y-1,-r);
					r/=v;
					if(r) {
						M[x]=r;
						bt.add(x,y-1,r);
					}
					else {
						if(prev(it)->second) {
							M[x]=0;
						}
						else {
							M.erase(x);
						}
					}
					nex=y;
				}
			}
			else {
				int nex=L;
				while(nex<R) {
					auto it=M.lower_bound(nex);
					x=it->first;
					y=next(it)->first;
					r=it->second;
					bt.add(x,y-1,-r);
					nex=y;
					M.erase(it);
				}
				M[L]=v;
				bt.add(L,R-1,v);
			}
		}
		else if(i==3) {
			cout<<bt.total(R)-bt.total(L-1)<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
