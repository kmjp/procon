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

int N,M;
int A[202020];
int T[202020],X[202020],Y[202020];
int B[202020];

vector<int> C;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void update(int x,int v) {
	if(B[x]==v) return;
	if(B[x]>max(B[x-1],B[x+1])) {
		bt.add(B[x]+1,1);
		bt.add(max(B[x-1],B[x+1])+1,-1);
	}
	bt.add(min({B[x],B[x-1],B[x+1]})+1,-1);
	bt.add(1,1);
	
	B[x]=v;
	int a;
	
	bt.add(1,-1);
	bt.add(min({B[x],B[x-1],B[x+1]})+1,1);
	
	if(B[x]>max(B[x-1],B[x+1])) {
		bt.add(B[x]+1,-1);
		bt.add(max(B[x-1],B[x+1])+1,1);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	C.push_back(0);
	C.push_back(1);
	C.push_back(1<<30);
	for(i=1;i<=N;i++) {
		cin>>A[i];
		C.push_back(A[i]);
	}
	FOR(i,M) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>X[i];
			C.push_back(X[i]);
		}
		else {
			cin>>X[i]>>Y[i];
			C.push_back(Y[i]);
		}
	}
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	
	
	for(i=1;i<=N;i++) B[i]=1;
	bt.add(1,1);
	bt.add(2,-1);
	
	for(i=1;i<=N;i++) {
		update(i,lower_bound(ALL(C),A[i])-C.begin());
	}
	FOR(i,M) {
		if(T[i]==1) {
			cout<<bt(lower_bound(ALL(C),X[i])-C.begin())<<endl;
		}
		else {
			update(X[i],lower_bound(ALL(C),Y[i])-C.begin());
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
