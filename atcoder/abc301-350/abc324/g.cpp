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

int N;
int A[202020];

int L[202020],R[202020];
int VL[202020],VR[202020];
int len[202020];
template<class V,int NV> class SegTree_1 {
public:
	vector<vector<V>> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val.resize(NV*2);};
	V getval(int x,int y,V v,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) {
			return lower_bound(ALL(val[k]),v+1)-val[k].begin();
		}
		return getval(x,y,v,l,(l+r)/2,k*2)+getval(x,y,v,(l+r)/2,r,k*2+1);
	}
	void set(int entry,V v) {
		val[entry+NV].clear();
		val[entry+NV].push_back(v);
	}
	void build() {
		for(int i=2*NV-1;i>=NV;i--) sort(ALL(val[i]));
		for(int i=NV-1;i>=1;i--) {
			val[i].clear();
			int a=0,b=0;
			int x=i*2,y=i*2+1;
			while(a<val[x].size() || b<val[y].size()) {
				if(a==val[x].size()) {
					val[i].push_back(val[y][b++]);
				}
				else if(b==val[y].size()) {
					val[i].push_back(val[x][a++]);
				}
				else if(val[x][a]<val[y][b]) {
					val[i].push_back(val[x][a++]);
				}
				else {
					val[i].push_back(val[y][b++]);
				}
			}
		}
	}
};
SegTree_1<int,1<<18> st;
int Q;

int getlen(int v) {
	if(L[v]>R[v]||VL[v]>VR[v]) return 0;
	int num=st.getval(L[v],R[v]+1,VR[v]);
	if(VL[v]) num-=st.getval(L[v],R[v]+1,VL[v]-1);
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		st.set(i,A[i]);
	}
	st.build();
	
	L[0]=0;
	R[0]=N-1;
	VL[0]=1;
	VR[0]=N;
	len[0]=N;
	cin>>Q;
	for(i=1;i<=Q;i++) {
		int t,s,x;
		cin>>t>>s>>x;
		
		if(t==1) {
			y=len[s];
			if(y<=x) {
				L[i]=1;
				R[i]=0;
				VL[i]=1;
				VR[i]=0;
				
			}
			else if(x==0) {
				L[i]=L[s];
				R[i]=R[s];
				VL[i]=VL[s];
				VR[i]=VR[s];
				L[s]=R[s]+1;
			}
			else {
				
				R[i]=R[s];
				VL[i]=VL[s];
				VR[i]=VR[s];
				for(j=20;j>=0;j--) if(R[s]-(1<<j)>=L[s]) {
					R[s]-=(1<<j);
					if(getlen(s)<x) R[s]+=(1<<j);
				}
				L[i]=R[s]+1;
			}
		}
		else if(t==2) {
			L[i]=L[s];
			R[i]=R[s];
			if(VR[s]<=x) {
				VL[i]=0;
				VR[i]=-1;
			}
			else if(x<VL[s]) {
				VL[i]=VL[s];
				VR[i]=VR[s];
				VL[s]=VR[s]+1;
			}
			else {
				VL[i]=x+1;
				VR[i]=VR[s];
				VR[s]=x;
			}
		}
		len[s]=getlen(s);
		len[i]=getlen(i);
		cout<<len[i]<<endl;
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
