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

int N,M;
int T[5150505];

int A[101010];
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		if(l[0]==0) return r;
		if(r[0]==0) return l;
		int step=l[1]+r[1];
		while(l[0]!=r[0]) {
			if(l[0]>r[0]) {
				step+=l[2];
				l[0]=T[l[0]];
			}
			else {
				step+=r[2];
				r[0]=T[r[0]];
			}
		}
		return {l[0],step,l[2]+r[2]};
	};
	
	SegTree_1(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry]={v,0,1};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<int,3>,1<<20> st;
set<int> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=5050505;i++) T[i]=i;
	for(i=2;i<=5000500;i++) {
		if(T[i]==i) {
			for(j=i;j<=5000000;j+=i) T[j]=T[j]/i*(i-1);
		}
	}
	
	cin>>N>>M;
	S.insert(N);
	FOR(i,N) {
		cin>>A[i];
		if(A[i]>1) S.insert(i);
		st.update(i,A[i]);
	}
	while(M--) {
		int L,R;
		cin>>i>>L>>R;
		L--;
		if(i==1) {
			int cur=L;
			while(1) {
				auto it=S.lower_bound(cur);
				cur=*it;
				if(cur>=R) break;
				A[cur]=T[A[cur]];
				if(A[cur]==1) S.erase(cur);
				st.update(cur,A[cur]);
				cur++;
			}
		}
		else {
			auto a=st.getval(L,R);
			cout<<a[1]<<endl;
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
