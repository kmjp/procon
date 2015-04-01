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

class UF {
	public:
	int um;
	vector<int> ufpar,ufrank,ufcnt;
	UF(int um_=100002) { um=um_; ufrank=vector<int>(um,0); ufcnt=vector<int>(um,1); for(int i=0;i<um;i++) ufpar.push_back(i);}
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

UF uf;
int num[40];
vector<int> E[40];
ll mask[40];

string S;
set<char> M;
map<int,int> R;

ll getcov(int cur,ll cmask,vector<int>& V) {
	if(cur==V.size()) return cmask;
	ll ret=getcov(cur+1,cmask | (1LL<<V[cur]),V);
	
	FORR(r,E[V[cur]]) if(r<V[cur] && ((cmask&(1LL<<r))==0)) return ret;
	
	ll ret2=getcov(cur+1,cmask,V);
	if(__builtin_popcountll(ret2)<__builtin_popcountll(ret)) ret=ret2;
	return ret;
}


ll pat(vector<int>& V) {
	ll cov=getcov(0,0,V);
	int val[31],mask,i;
	vector<int> C,NC;
	map<int,ll> M;
	FORR(r,V) {
		if(cov & (1LL<<r)) C.push_back(r);
		else NC.push_back(r);
	}
	
	FOR(mask,1<<C.size()) {
		int tot=0;
		ll p=1;
		FOR(i,C.size()) val[C[i]]=(mask&(1<<i))!=0;
		FOR(i,C.size()) {
			FORR(r,E[C[i]]) if(r<C[i] && (cov&(1LL<<r))) {
				if(val[C[i]]==val[r]) tot--;
				else tot++;
			}
		}
		FOR(i,NC.size()) {
			int n[2]={};
			FORR(r,E[NC[i]]) n[val[r]]++;
			tot+=abs(n[0]-n[1]);
			if(n[0]==n[1]) p*=2;
		}
		M[tot]+=p;
	}
	
	return M.rbegin()->second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	for(i=0;i<S.size();i+=2) {
		if(isupper(S[i])) S[i]-='A';
		else S[i]=S[i]-'a'+26;
	}
	for(i=0;i<S.size();i+=4) {
		if(S[i]!=S[i+2]) {
			E[S[i]].push_back(S[i+2]);
			E[S[i+2]].push_back(S[i]);
			mask[S[i]] |= 1LL<<S[i+2];
			mask[S[i+2]] |= 1LL<<S[i];
		}
		num[S[i]]++;
		num[S[i+2]]++;
		uf.unite(S[i],S[i+2]);
	}
	
	ll ret=1;
	FOR(i,30) if(uf[i]==i && num[i]) {
		vector<int> V;
		FOR(x,30) if(uf[x]==i) V.push_back(x);
		ret *= pat(V);
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
