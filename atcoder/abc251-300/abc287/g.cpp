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

int N;
ll A[202020],B[202020];
int Q;
ll T[202020],X[202020],Y[202020];

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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> Xs={0};
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		Xs.push_back(A[i]);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>X[i]>>Y[i];
			X[i]--;
			Xs.push_back(Y[i]);
		}
		if(T[i]==2) {
			cin>>X[i]>>Y[i];
			X[i]--;
		}
		if(T[i]==3) {
			cin>>X[i];
		}
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(Xs),A[i])-Xs.begin();
		num.add(A[i],B[i]);
		sum.add(A[i],Xs[A[i]]*B[i]);
	}
	FOR(k,Q) {
		if(T[k]==1) {
			i=X[k];
			num.add(A[i],-B[i]);
			sum.add(A[i],-Xs[A[i]]*B[i]);
			A[i]=lower_bound(ALL(Xs),Y[k])-Xs.begin();
			num.add(A[i],B[i]);
			sum.add(A[i],Xs[A[i]]*B[i]);
		}
		if(T[k]==2) {
			i=X[k];
			num.add(A[i],-B[i]);
			sum.add(A[i],-Xs[A[i]]*B[i]);
			B[i]=Y[k];
			num.add(A[i],B[i]);
			sum.add(A[i],Xs[A[i]]*B[i]);
		}
		if(T[k]==3) {
			ll a=X[k];
			ll tot=num(1<<19);
			ll tot2=sum(1<<19);
			if(tot<a) {
				cout<<-1<<endl;
			}
			else {
				ll rem=tot-a;
				x=num.lower_bound(rem);
				y=num(x-1);
				tot2-=sum(x-1);
				tot2-=(rem-y)*Xs[x];
				cout<<tot2<<endl;
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
