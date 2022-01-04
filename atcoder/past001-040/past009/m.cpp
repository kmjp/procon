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

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,ll val,int pos=60) {
		v += val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	ll get(ll s,int pos=60) { // sum [0,s-1]
		if(pos<0) return 0;
		int c=(s>>pos)&1;
		if(c) return (nex[0]?nex[0]->v:0)+(nex[1]?nex[1]->get(s,pos-1):0);
		else return (nex[0]?nex[0]->get(s,pos-1):0);
	}
	ll lower_bound(ll v,int pos=60) { // sum [0,s-1]
		if(pos<0) return 0;
		if((nex[0]?nex[0]->v:0)>=v) {
			return nex[0]->lower_bound(v,pos-1);
		}
		else {
			v-=(nex[0]?nex[0]->v:0);
			return (1LL<<pos)|(nex[1]?nex[1]->lower_bound(v,pos-1):0);
		}
	}
};

int N,Q;
string S[101010];
map<string,int> M;
BinarySumTrie bst;

ll encode(string S,int id) {
	S=S+"`````";
	ll cur=0;
	int i;
	FOR(i,5) cur=cur*27+S[i]-'`';
	return (cur<<20)|id;
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>S[i];
		bst.add(encode(S[i],i),1);
	}
	FOR(i,Q) {
		int X;
		string T;
		cin>>X>>T;
		ll v=bst.lower_bound(X);
		bst.add(v,-1);
		v=v&((1<<20)-1);
		S[v]=T;
		bst.add(encode(S[v],v),1);
	}
	FOR(i,N) cout<<S[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
