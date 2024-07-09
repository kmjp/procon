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
	set<ll> V;
	ll x;
	struct node {
		ll v;
		node *nex[2];
		node() {
			nex[0]=nex[1]=NULL;v=0;
		};
		void add(ll s,int pos=20) {
			v++;
			if(pos>=0) {
				int c=(s>>pos)&1;
				if(!nex[c]) {
					nex[c]=new node();
				}
				nex[c]->add(s,pos-1);
			}
		}
		ll gr(int pos,ll x) { // sum [0,s-1]
			ll num=1LL<<(pos);
			if(x&(1LL<<pos)) {
				if(!nex[1]) return 0;
				if(nex[1]->v<num) {
					return nex[1]->gr(pos-1,x);
				}
				else {
					if(!nex[0]) return num;
					return (num)^nex[0]->gr(pos-1,x);
				}
			}
			else {
				if(!nex[0]) return 0;
				if(nex[0]->v<num) {
					return nex[0]->gr(pos-1,x);
				}
				else {
					if(!nex[1]) return num;
					return (num)^nex[1]->gr(pos-1,x);
				}
			}
			return 0;
		}
		
	};
	node root;
	BinarySumTrie() {
		x=0;
	}
	void add(ll s) {
		s^=x;
		if(V.count(s)) return;
		V.insert(s);
		root.add(s);
	}
	ll gr() {
		return root.gr(20,x);
	}
};

int N;
vector<int> E[202020];
BinarySumTrie bs[202020];
int G[202020];
vector<int> V;
void dfs(int cur,int pre) {
	ll x=0;
	bs[cur].add(0);
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		bs[e].x^=x;
		x^=G[e];
		bs[cur].x^=G[e];
		if(bs[cur].V.size()<bs[e].V.size()) {
			swap(bs[cur],bs[e]);
		}
		FORR(v,bs[e].V) bs[cur].add(v^bs[e].x);
	}
	G[cur]=bs[cur].gr();
	
}

void dfs2(int cur,int pre,int g) {
	
	FORR(e,E[cur]) if(e!=pre) g^=G[e];
	if(g==0) V.push_back(cur+1);
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,g^G[e]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	
	if(G[0]) {
		dfs2(0,0,0);
		cout<<"Alice"<<endl;
		cout<<V.size()<<endl;
		sort(ALL(V));
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
	}
	else {
		cout<<"Bob"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
