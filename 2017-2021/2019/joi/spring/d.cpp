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

template<int NV> class SegTree_Lazy {
public:
	vector<ll> A,C,D;
	void clear() {
		A.clear();
		C.clear();
		D.clear();
		A.resize(NV*2,1LL<<40);
		C.resize(NV*2,-1LL<<40);
		D.resize(NV*2,-1LL<<40);
	}

	ll getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return -1LL<<40;
		if(x<=l && r<=y) return D[k];
		
		update(l,(l+r)/2,C[k],l,(l+r)/2,k*2);
		update((l+r)/2,r,C[k],(l+r)/2,r,k*2+1);
		C[k]=-1LL<<40;
		D[k]=max({D[k],D[2*k],D[2*k+1]});
		
		return max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int y,ll v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			C[k]=max(C[k],v);
			D[k]=max(D[k],C[k]-A[k]);
		}
		else if(l < y && x < r) {
			update(l,(l+r)/2,C[k],l,(l+r)/2,k*2);
			update((l+r)/2,r,C[k],(l+r)/2,r,k*2+1);
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			C[k]=-1LL<<40;
			D[k]=max({D[k],D[2*k],D[2*k+1]});
		}
		//cout<<"update "<<x<<" "<<y<<" "<<v<<" "<<l<<" "<<r<<" "<<k<<" "<<C[k]<<" "<<D[k]<<endl;
	}
	void updateA(int x,int y,ll v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			A[k]=v;
			C[k]=-1LL<<40;
		}
		else if(l < y && x < r) {
			C[2*k]=max(C[2*k],C[k]);
			C[2*k+1]=max(C[2*k+1],C[k]);
			D[2*k]=max(D[2*k],C[2*k]-A[2*k]);
			D[2*k+1]=max(D[2*k+1],C[2*k+1]-A[2*k+1]);
			C[k]=-1LL<<40;
			updateA(x,y,v,l,(l+r)/2,k*2);
			updateA(x,y,v,(l+r)/2,r,k*2+1);
			A[k]=min(A[2*k],A[2*k+1]);
			D[k]=max({D[k],D[2*k],D[2*k+1]});
		}
		//cout<<"update "<<x<<" "<<y<<" "<<v<<" "<<l<<" "<<r<<" "<<k<<" "<<C[k]<<" "<<D[k]<<endl;
	}
	
};

int N;
int H[202020],A[202020],B[202020];
int Q;
int L[202020],R[202020];
ll ret[202020];

SegTree_Lazy<1<<18> st;
vector<int> add[201010],del[201010],query[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>H[i]>>A[i]>>B[i];
		if(i+A[i]<N) add[i+A[i]].push_back(i);
		if(i+B[i]<N) del[i+B[i]].push_back(i);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		R[i]--;
		query[R[i]].push_back(i);
	}
	MINUS(ret);
	
	FOR(i,2) {
		st.clear();
		//cout<<"--------------"<<endl;
		FOR(x,N) {
			FORR(a,add[x]) {
				//cout<<"add "<<x<<" "<<a<<" "<<H[a]<<endl;
				st.updateA(a,a+1,H[a]);
			}
			int TL=max(0,x-B[x]);
			int TR=x-A[x];
			if(TL<=TR) {
				//cout<<"up "<<x<<" "<<TL<<" "<<TR<<" "<<H[x]<<endl;
				st.update(TL,TR+1,H[x]);
			}
			FORR(a,del[x]) {
				//cout<<"del "<<x<<" "<<a<<" "<<H[a]<<endl;
				st.updateA(a,a+1,1LL<<40);
			}
			FORR(q,query[x]) {
				//cout<<"Q"<<q<<" "<<L[q]<<" "<<R[q]<<" "<<st.getval(L[q],R[q]+1).first<<endl;
				ret[q]=max(ret[q],st.getval(L[q],R[q]+1));
			}
				
		}
		
		
		FOR(x,N) H[x]=1000000001-H[x];
	}
	
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
