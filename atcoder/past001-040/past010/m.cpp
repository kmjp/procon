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
int P[505050];
int A[505050],B[505050],C[505050];
map<int,int> cand;

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
BIT<int,22> bit;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<int> Ps={-1,1<<30};
	FOR(i,N) {
		cin>>P[i];
		Ps.push_back(P[i]);
	}
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		if(A[i]==1) {
			cin>>C[i];
			Ps.push_back(C[i]);
		}
	}
	sort(ALL(Ps));
	FOR(i,N) {
		P[i]=lower_bound(ALL(Ps),P[i])-Ps.begin();
		cand[P[i]]=i;
		bit.add(P[i],1);
	}
	FOR(i,Q) {
		if(A[i]==1) {
			x=B[i]-1;
			bit.add(P[x],-1);
			P[x]=lower_bound(ALL(Ps),C[i])-Ps.begin();
			cand[P[x]]=x;
			bit.add(P[x],1);
		}
		else if(A[i]==2) {
			x=B[i]-1;
			y=bit(P[x])-1;
			cout<<N-y<<endl;
		}
		else {
			x=N+1-B[i];
			y=bit.lower_bound(x);
			cout<<cand[y]+1<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
