#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
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

SegTree_1<int,1<<20> st;
int nm[1002000];

int N;
ll A[102000],B[102000];
int num[102000];
vector<pair<int,int> > ev;
vector<int> V[101000];
vector<int> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		A[i]++,B[i]++;
		ev.push_back(make_pair(-A[i],i));
	}
	sort(ev.begin(),ev.end());
	FOR(j,ev.size()) {
		x=ev[j].second;
		num[x]=1+st.getval(B[x],1001005);
		if(num[x]>nm[A[x]]) {
			nm[A[x]]=num[x];
			st.update(A[x],nm[A[x]]);
		}
	}
	
	FOR(i,N) V[num[i]].push_back(i);
	x=-1;
	for(i=100000;i>=0;i--) if(V[i].size()) {
		if(x==-1) {
			x=V[i][0];
		}
		else {
			FOR(y,V[i].size()) {
				if(B[x]<=A[V[i][y]]) {
					x=V[i][y];
					break;
				}
			}
		}
		R.push_back(x);
	}
	
	_P("%d\n",R.size());
	FOR(i,R.size()) {
		if(i) _P(" ");
		_P("%d",R[i]+1);
	}
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
