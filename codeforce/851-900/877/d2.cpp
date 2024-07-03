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
string S;
set<int> A,B;

template<class V,int NV> class SegTree_1 {
public:
	vector<pair<int,int>> val;
	pair<int,int> comp(pair<int,int> l,pair<int,int> r){
		pair<int,int> p={min(l.first,l.second+r.first),l.second+r.second};
		return p;
	}
	
	SegTree_1(){
		val.resize(NV*2);
	};
	pair<int,int> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry]={min(0,v),v};
		while(entry>1) {
			entry>>=1;
			val[entry]=comp(val[entry*2],val[entry*2+1]);
		}
	}
};
SegTree_1<int,1<<20> Ost,Cst;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N-1) {
		if(S[i]=='('&&S[i+1]=='(') A.insert(i);
		if(S[i]==')'&&S[i+1]==')') B.insert(i+1);
	}
	FOR(i,N) {
		if(S[i]=='(') {
			Ost.update(i,1);
			Cst.update(N-1-i,-1);
		}
		else {
			Ost.update(i,-1);
			Cst.update(N-1-i,1);
		}
	}
	A.insert(N);
	B.insert(-1);
	
	while(Q--) {
		cin>>x;
		x--;
		if(x&&S[x-1]=='('&&S[x]=='(') A.erase(x-1);
		if(x+1<N&&S[x+1]=='('&&S[x]=='(') A.erase(x);
		if(x&&S[x-1]==')'&&S[x]==')') B.erase(x);
		if(x+1<N&&S[x]==')'&&S[x+1]==')') B.erase(x+1);
		S[x]='('+')'-S[x];
		if(x&&S[x-1]=='('&&S[x]=='(') A.insert(x-1);
		if(x+1<N&&S[x+1]=='('&&S[x]=='(') A.insert(x);
		if(x&&S[x-1]==')'&&S[x]==')') B.insert(x);
		if(x+1<N&&S[x]==')'&&S[x+1]==')') B.insert(x+1);
		
		if(S[x]=='(') {
			Ost.update(x,1);
			Cst.update(N-1-x,-1);
		}
		else {
			Ost.update(x,-1);
			Cst.update(N-1-x,1);
		}
		int ok=1;
		if(N%2) ok=0;
		x=*A.begin();
		if(Ost.getval(0,x+1).first<0) ok=0;
		y=*B.rbegin();
		if(Cst.getval(0,N-1-y).first<0) ok=0;
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
