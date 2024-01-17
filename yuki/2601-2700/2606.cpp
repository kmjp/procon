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

struct PalindromicTree {
	struct node {
		map<char,int> next;
		int len, sufflink,num,first;
		ll val=0;
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
			V[s].num++;
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
		V[n].num++;
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

int N;
string S;
PalindromicTree pt;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	pt.init(S);
	ll ma=0;
	FOR(i,N) pt.add(i);
	for(i=pt.V.size()-1;i>=3;i--) if(pt.V[i].sufflink) {
		pt.V[pt.V[i].sufflink].num+=pt.V[i].num;
	}
	for(i=3;i<pt.V.size();i++) {
		pt.V[i].val=1LL*pt.V[i].len*pt.V[i].num+pt.V[pt.V[i].sufflink].val;
		ma=max(ma,pt.V[i].val);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
