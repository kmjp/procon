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
int A[402020];

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,ll val,int pos=29) {
		v += val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	int pick(ll val,int pos=29) { // sum [0,s-1]
		if(pos<0) return 0;
		
		int tar=0;
		if(val&(1LL<<pos)) {
			if(nex[1]&&nex[1]->v) tar=1;
			else tar=0;
		}
		else {
			if(nex[0]&&nex[0]->v) tar=0;
			else tar=1;
		}
		return (tar<<pos)+nex[tar]->pick(val,pos-1);
	}
};

BinarySumTrie root;


int dfs(vector<int> V,int d) {
	vector<int> A,B;
	if(V.size()==0) return 0;
	if(d<0) return 0;
	
	FORR(v,V) {
		if(v&(1<<d)) A.push_back(v^(1<<d));
		else B.push_back(v);
	}
	
	if(A.size()%2==0 && B.size()%2==0) {
		int a=dfs(A,d-1);
		int b=dfs(B,d-1);
		return max(a,b);
	}
	else {
		BinarySumTrie root;
		FORR(a,A) root.add(a,1);
		int mi=1<<30;
		FORR(b,B) {
			int x=root.pick(b);
			mi=min(mi,(b^x)|(1<<d));
		}
		return mi;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	FOR(i,2*N) {
		cin>>x;
		V.push_back(x);
	}
	
	
	
	cout<<dfs(V,29)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
