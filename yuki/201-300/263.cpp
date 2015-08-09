#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
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


string S,T,V;
vector<ll> dp[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	V=S+"[\\"+T;
	dp[0].resize(V.size()+5);
	dp[1].resize(V.size()+5);
	
	
	PalindromicTree pt;
	pt.init(V);
	
	
	FOR(i,V.size()) {
		pt.add(i);
		if(i<S.size()) dp[0][pt.s]++;
		if(i>=S.size()+1) dp[1][pt.s]++;
	}
	ll ret=0;
	for(i=pt.n;i>=3;i--) {
		ret += dp[0][i]*dp[1][i];
		dp[0][pt.V[i].sufflink]+=dp[0][i];
		dp[1][pt.V[i].sufflink]+=dp[1][i];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
