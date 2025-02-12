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
int X[202020],P[202020];
int D[202020];
int A[202020],B[202020],C[202020];
int rev;

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
BIT<ll,20> num,sum;

ll get(ll v) {
	if(v==0) return 0;
	ll ret=0;
	if(v%2==0) {
		int x=num.lower_bound(num(P[0])+v/2);
		ret+=2*(sum(x)-sum(P[0]));
		x=num.lower_bound(num(P[0])-v/2);
		ret-=(sum(P[0])-sum(x-1));
		ret-=(sum(P[0]-1)-sum(x));
	}
	else {
		int x=num.lower_bound(num(P[0])+v/2+1);
		ret+=(sum(x)-sum(P[0]));
		ret+=(sum(x-1)-sum(P[0]));
		x=num.lower_bound(num(P[0])-v/2);
		ret-=(sum(P[0])-sum(x-1));
		ret-=(sum(P[0]-1)-sum(x-1));
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> Xs;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>s;
		D[i]=s[0]=='L';
	}
	if(D[0]) rev=1;
	FOR(i,N) {
		if(rev) {
			X[i]=-X[i];
			D[i]^=1;
		}
		if((X[i]<=X[0])==(D[i]==0)) {
			Xs.push_back(X[i]);
		}
		else {
			X[i]=-1;
		}
	}
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		if(A[i]==1) {
			cin>>s;
			C[i]=s=="L";
			if(rev) {
				B[i]=-B[i];
				C[i]^=1;
			}
			if((B[i]<=X[0])==(C[i]==0)) {
				Xs.push_back(B[i]);
			}
			else {
				B[i]=-1;
			}
		}
		else {
			cin>>C[i];
		}
	}
	sort(ALL(Xs));
	FOR(i,N) if(X[i]!=-1) {
		P[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		num.add(P[i],1);
		sum.add(P[i],X[i]);
	}
	FOR(i,Q) {
		if(A[i]==1) {
			if(B[i]!=-1) {
				x=lower_bound(ALL(Xs),B[i])-Xs.begin();
				num.add(x,1);
				sum.add(x,B[i]);
				
			}
		}
		else {
			ll ret=get(C[i])-get(B[i]-1);
			cout<<ret/2<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
