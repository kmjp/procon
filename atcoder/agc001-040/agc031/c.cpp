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


int N,A,B;

vector<int> hoge(int C) {
	vector<int> R;
	int x,y;
	if(__builtin_popcount(C)==1) {
		FOR(x,N) if(C&(1<<x)) break;
		R.push_back(0);
		R.push_back(1<<x);
		return R;
	}
	FOR(x,N) if(C&(1<<x)) break;
	FOR(y,N) if(x!=y && (C&(1<<y))) break;
	vector<int> T=hoge(C^(1<<x)^(1<<y));
	
	R=T;
	reverse(ALL(T));
	FORR(t,T) R.push_back(t^(1<<x));
	reverse(ALL(T));
	int step=0;
	FORR(t,T) {
		if(step==0) {
			R.push_back(t^(1<<x)^(1<<y));
			R.push_back(t^(1<<y));
		}
		else {
			R.push_back(t^(1<<y));
			R.push_back(t^(1<<x)^(1<<y));
		}
		step^=1;
	}
	return R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	if(__builtin_popcount(A)%2==__builtin_popcount(B)%2) {
		cout<<"NO"<<endl;
		return;
	}
	int C=A^B;
	int sub=C^((1<<N)-1);
	vector<int> V;
	V.push_back(0);
	FOR(i,N) if(sub&(1<<i)) {
		vector<int> V2=V;
		reverse(ALL(V));
		FORR(v,V) V2.push_back((1<<i)|v);
		swap(V,V2);
	}
	
	vector<int> W=hoge(C);
	
	vector<int> R;
	FORR(w,W) {
		FORR(v,V) R.push_back(w^v^A);
		reverse(ALL(V));
	}
	FOR(i,R.size()-1) {
		assert(__builtin_popcount(R[i]^R[i+1])==1);
	}
	assert(R[0]==A);
	assert(R.back()==B);
	
	cout<<"YES"<<endl;
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
