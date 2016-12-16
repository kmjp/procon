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

struct PalindromicTree {
	struct node {
		map<char,int> next;
		int len, sufflink,num,first;
	};
	string S;
	vector<node> V;
	int n,s; // num,suff
	
	bool add(int pos) {
		char ch=S[pos];
		int c=s, cl=0;
		while(1) {
			cl=V[c].len;
			if(pos-1-cl>=0 && S[pos-1-cl]==ch) break;
			c=V[c].sufflink;
		}
		
		if(V[c].next.count(ch)) {
			s = V[c].next[ch];
			return false;
		}
		
		s=++n;
		V[n].len=V[c].len+2;
		V[n].first=pos;
		V[c].next[ch]=n;
		
		if(V[n].len==1) { // even length
			V[n].sufflink=2;
			V[n].num=1;
			return true;
		}
		
		while(1) {
			c=V[c].sufflink;
			cl=V[c].len;
			if(pos-1-cl>=0 && S[pos-1-cl]==ch) {
				V[n].sufflink=V[c].next[ch];
				break;
			}
		}
		V[n].num=1+V[V[n].sufflink].num;
		return true;
	}
	
	void init(string S) {
		this->S=S;
		V.clear();
		V.resize(S.size()+10);
		
		n=s=2;
		V[1].first=V[2].first=-1;
		V[1].len=-1;
		V[2].len=0;
		V[1].sufflink=V[2].sufflink=1;
	}
};

int L;
string S;
int pnode[505050];
ll pre[505050],post[505050],dp[505050];
ll pl[505050],gpl[505050];
deque<pair<int,pair<int,int>>> G,G1,G2;

void solve() {
	int i,j,k,l,r,x,y,m=0; string s;
	cin>>S;
	S="0"+S;
	L=S.size();
	
	PalindromicTree pt;
	pt.init(S);
	FOR(i,L) {
		pt.add(i);
		pnode[i]=pt.s;
		pre[i]=(pt.V[pnode[i]].len==i);
	}
	x=pnode[L-1];
	while(x>=3) {
		post[L-pt.V[x].len]=1;
		x=pt.V[x].sufflink;
	}
	for(i=L;i>=0;i--) post[i]+=post[i+1];

	pre[0]=0;
	for(j=1;j<L;j++) {
		G1.clear();
		FORR(g,G) if(g.first>1 && S[g.first-1]==S[j]) G1.push_back({g.first-1,g.second});
		G2.clear();
		r=-j;
		FORR(g,G1) {
			
			if(g.first-r!=g.second.first) {
				G2.push_back({g.first,{g.first-r,1}});
				if(g.second.second>1) G2.push_back({g.first+g.second.first,{g.second.first,g.second.second-1}});
			}
			else G2.push_back(g);
			r=g.first+(g.second.second-1)*g.second.first;
		}
		if(j>1 && S[j-1]==S[j]) {
			G2.push_back({j-1,{j-1-r,1}});
			r=j-1;
		}
		G2.push_back({j,{j-r,1}});
		G.clear();
		auto gg=G2.front();
		G2.pop_front();
		FORR(g,G2) {
			if(g.second.first==gg.second.first) gg.second.second+=g.second.second;
			else G.push_back(gg), gg=g;
		}
		G.push_back(gg);
		FORR(g,G) {
			r=g.first+(g.second.second-1)*g.second.first;
			int m=pre[r-1];
			if(g.second.second>1 && g.first-g.second.first>0) m+=gpl[g.first-g.second.first];
			if(g.second.first<g.first) gpl[g.first-g.second.first]=m;
			pl[j]+=m;
		}
	}
	
	ll ret=0;
	for(i=1;i<L;i++) ret+=pl[i]*post[i+2];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
