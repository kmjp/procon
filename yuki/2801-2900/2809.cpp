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
ll A[303030];
int X[303030],Y[303030];
ll Z[303030];

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
BIT<int,20> num,val;
set<int> U;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<ll> Vs;
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		Vs.push_back(A[i]);
		U.insert(i);
	}
	FOR(i,Q) {
		cin>>X[i];
		if(X[i]==1) {
			cin>>Y[i]>>Z[i];
			Y[i]--;
			Vs.push_back(Z[i]);
		}
		else if(X[i]==3) {
			cin>>Y[i];
			Y[i]--;
		}
	}
	sort(ALL(Vs));
	Vs.erase(unique(ALL(Vs)),Vs.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(Vs),A[i])-Vs.begin();
	}
	FOR(i,Q) {
		if(X[i]==1) {
			x=Y[i];
			if(U.count(x)==0) {
				y=val.lower_bound(num(x));
				num.add(x,-1);
				val.add(y,-1);
				U.insert(x);
			}
			A[x]=lower_bound(ALL(Vs),Z[i])-Vs.begin();
		}
		else if(X[i]==2) {
			FORR(x,U) {
				num.add(x,1);
				val.add(A[x],1);
			}
			U.clear();
		}
		else {
			x=Y[i];
			if(U.count(x)) {
				cout<<Vs[A[x]]<<endl;
			}
			else {
				x=num(x);
				y=val.lower_bound(x);
				cout<<Vs[y]<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
