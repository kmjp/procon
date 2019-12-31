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

int N;
int S[101010];
int C[101010];
vector<int> MP[101010];

int st[101010],len[101010];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int pre[101010],did[101010];
SegTree_1<int,1<<20> seg[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(st);
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		cin>>C[i];
		MP[C[i]].push_back(S[i]);
	}
	x = 0;
	FOR(i,101000) {
		MP[i].push_back(0),MP[i].push_back(1<<30);
		sort(ALL(MP[i]));
		MP[i].erase(unique(ALL(MP[i])),MP[i].end());
		st[i]=x;
		len[i]=MP[i].size();
		x+=len[i];
	}
	FOR(i,N) {
		S[i]=lower_bound(ALL(MP[C[i]]),S[i])-MP[C[i]].begin();
		did[i+1]=did[i];
		pre[i]=seg[0].getval(st[C[i]]+S[i]+1,st[C[i]]+len[C[i]]);
		x=-1;
		if(pre[i]>0) {
			x=seg[1].getval(st[C[i]]+S[i]+1,st[C[i]]+len[C[i]]);
			if(x>0) {
				x--;
				did[i+1]=max(did[i+1],did[x]+1);
			}
			seg[1].update(st[C[i]]+S[i],pre[i]);
		}
		seg[0].update(st[C[i]]+S[i],i+1);
		
		
	}
	
	cout<<did[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
