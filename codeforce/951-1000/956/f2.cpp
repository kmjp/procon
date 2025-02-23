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

int T,N;
ll K;
ll A[101010];
int po;

struct BinarySumTrie {
	static BinarySumTrie nodes[8<<20];
	int nex[2];
	int v;
	BinarySumTrie() {
		nex[0]=nex[1]=-1;
		v=-1;
	}
	void add(int s,int val,int pos=29) {
		v=max(v,val);
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(nex[c]==-1) nex[c]=po++;
			nodes[nex[c]].add(s,val,pos-1);
		}
	}
	int pick(int val,int t,int pos=29) { // sum [0,s-1]
		if(pos<0) return v;
		int ret=-1;
		int p=1<<pos;
		if((val&p)&&(t&p)) {
			if(nex[1]>=0) ret=max(ret,nodes[nex[1]].v);
			if(nex[0]>=0) ret=max(ret,nodes[nex[0]].pick(val^p,t,pos-1));
		}
		else if((val&p)) {
			if(nex[1]>=0) ret=max(ret,nodes[nex[1]].pick(val^p,t,pos-1));
		}
		else if(t&p) {
			if(nex[0]>=0) ret=max(ret,nodes[nex[0]].v);
			if(nex[1]>=0) ret=max(ret,nodes[nex[1]].pick(val^p,t,pos-1));
		}
		else {
			if(nex[0]>=0) ret=max(ret,nodes[nex[0]].pick(val^p,t,pos-1));
		}
		return ret;
	}
};
BinarySumTrie BinarySumTrie::nodes[8<<20];
int bst;
int R[101010];

ll num(int v) {
	ll sum=0;
	int i,j;
	int bst=po++;
	int lef=-1;
	FOR(i,N) {
		lef=max(lef,BinarySumTrie::nodes[bst].pick(A[i],v));
		sum+=lef+1;
		BinarySumTrie::nodes[bst].add(A[i],i);
	}
	return sum;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;

	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		
		
		int ret=(1<<30)-1;
		for(i=29;i>=0;i--) {
			po=0;
			if(num(ret-(1<<i))>=K) ret-=(1<<i);
			FOR(j,po+1) {
				BinarySumTrie::nodes[j].nex[0]=BinarySumTrie::nodes[j].nex[1]=-1;
				BinarySumTrie::nodes[j].v=-1;
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
