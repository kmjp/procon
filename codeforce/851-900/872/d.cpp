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
int A[1010101];
int nex[1010101];
int pos[1010101];

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
BIT_r<ll,21> sum,cur;

int L[1010101],R[1010101],X[1010101],Y[1010101];
vector<int> ev[1010101];
ll ret[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i+1];
	}
	for(i=N-1;i>=0;i--) {
		if(pos[A[i+1]]) {
			nex[i+1]=pos[A[i+1]];
		}
		else {
			nex[i+1]=N+1;
		}
		pos[A[i+1]]=i+1;
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>X[i]>>Y[i];
		ev[L[i]].push_back(i);
		ev[R[i]+1].push_back(i);
	}
	set<pair<int,int>> seg={{N+1,-1}};
	for(i=N;i>=1;i--) {
		x=nex[i];
		while(1) {
			auto it=seg.begin();
			j=it->first;
			if(j>=x) break;
			y=next(it)->first;
			k=it->second;
			seg.erase(it);
			if(y<=x) {
				sum.add(j,y-1,-1LL*(k-i)*i);
				cur.add(j,y-1,-1LL*(k-i));
			}
			else {
				sum.add(j,x-1,-1LL*(k-i)*i);
				cur.add(j,x-1,-1LL*(k-i));
				seg.insert({x,k});
			}
			
		}
		sum.add(i,i,1LL*i*i);
		cur.add(i,i,i);
		seg.insert({i,i});
		
		
		FORR(e,ev[i]) {
			if(i==R[e]+1) {
				ret[e]-=sum.total(Y[e])-(i-1)*cur.total(Y[e]);
				ret[e]+=sum.total(X[e]-1)-(i-1)*cur.total(X[e]-1);
			}
			else {
				ret[e]+=sum.total(Y[e])-(i-1)*cur.total(Y[e]);
				ret[e]-=sum.total(X[e]-1)-(i-1)*cur.total(X[e]-1);
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
