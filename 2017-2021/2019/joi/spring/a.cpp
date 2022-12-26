#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
int X[101010],Y[101010];
vector<int> Xs,Ys;
int A[101010],B[101010],C[101010];
int ret[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> BB,XB,YB;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	Xs.push_back(0);
	Ys.push_back(0);
	Xs.push_back(1<<30);
	Ys.push_back(1<<30);
	vector<pair<int,int>> ev1,ev2;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
		ev1.push_back({Y[i],Q+i});
		ev2.push_back({X[i]+Y[i],Q+i});
	}
	
	FOR(i,Q) {
		cin>>A[i]>>B[i]>>C[i];
		if(A[i]+B[i]>=C[i]) {
			ev1.push_back({B[i],i});
		}
		else {
			ev2.push_back({C[i],i});
		}
	}
	
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	sort(ALL(ev1));
	reverse(ALL(ev1));
	FORR(e,ev1) {
		if(e.second>=Q) {
			i=e.second-Q;
			x=lower_bound(ALL(Xs),X[i])-Xs.begin();
			BB.add(x,1);
		}
		else {
			i=e.second;
			x=lower_bound(ALL(Xs),A[i])-Xs.begin();
			ret[i]=BB((1<<19)-1)-BB(x-1);
		}
	}
	sort(ALL(ev2));
	reverse(ALL(ev2));
	int add=0;
	FORR(e,ev2) {
		if(e.second>=Q) {
			i=e.second-Q;
			x=lower_bound(ALL(Xs),X[i])-Xs.begin();
			XB.add(x,1);
			y=lower_bound(ALL(Ys),Y[i])-Ys.begin();
			YB.add(y,1);
			add++;
		}
		else {
			i=e.second;
			x=lower_bound(ALL(Xs),A[i])-Xs.begin();
			y=lower_bound(ALL(Ys),B[i])-Ys.begin();
			ret[i]+=XB((1<<19)-1)-XB(x-1);
			ret[i]+=YB((1<<19)-1)-YB(y-1);
			ret[i]-=add;
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
