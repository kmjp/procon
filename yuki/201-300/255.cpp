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


vector<ll> V;
ll N;
int Q;
int X[161010];
ll L[161010],R[161010];

template<int NV> class SegTree_Lazy {
public:
	vector<ll> val,tot;
	vector<char> clean;
	SegTree_Lazy(){val.resize(NV*2); tot.resize(NV*2);clean.resize(NV*2);};
	ll getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(clean[k]) return 0;
		if(x<=l && r<=y) return tot[k];
		x=max(x,l);
		y=min(y,r);
		return val[k]*(V[y]-V[x]) + getval(x,y,l,(l+r)/2,k*2) + getval(x,y,(l+r)/2,r,k*2+1);
	}
	
	void probclean(int v) {
		if(v<=2*NV) clean[v]=1, val[v]=tot[v]=0;
	}
	void doclean(int v) {
		clean[v]=val[v]=tot[v]=0;
		probclean(2*v);
		probclean(2*v+1);
	}

	void clear(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return;
		if(clean[k]) return;
		if(x<=l && r<=y) {
			clean[k]=1;
			val[k]=tot[k]=0;
		}
		else {
			if(clean[2*k]) doclean(2*k);
			if(clean[2*k+1]) doclean(2*k+1);
			
			val[2*k]+=val[k];
			tot[2*k]+=val[k]*(V[(l+r)/2]-V[l]);
			val[2*k+1]+=val[k];
			tot[2*k+1]+=val[k]*(V[r]-V[(l+r)/2]);
			val[k]=0;
			clear(x,y,l,(l+r)/2,k*2);
			clear(x,y,(l+r)/2,r,k*2+1);
			tot[k]=tot[2*k]+tot[2*k+1];
		}
	}
	void inc(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return;
		if(clean[k]) doclean(k);
		
		if(x<=l && r<=y) {
			val[k]++;
			tot[k]+=V[r]-V[l];
		}
		else {
			inc(x,y,l,(l+r)/2,k*2);
			inc(x,y,(l+r)/2,r,k*2+1);
			tot[k]=val[k]*(V[r]-V[l])+tot[2*k]+tot[2*k+1];
		}
	}
};
SegTree_Lazy<1<<19> st[5];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	V.push_back(0);
	V.push_back(N+3);
	FOR(i,Q) {
		cin>>X[i]>>L[i]>>R[i];
		L[i]++,R[i]++;
		V.push_back(L[i]);
		V.push_back(R[i]+1);
	}
	
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	while(V.size()<(1<<19)+5) V.push_back(V.back());
	ll bonus[5]={};
	ll mo=1000000000;
	mo*=1000000000;
	mo+=9;
	
	FOR(i,Q) {
		int LL=lower_bound(ALL(V),L[i])-V.begin();
		int RR=lower_bound(ALL(V),R[i]+1)-V.begin();
		
		if(X[i]==0) {
			ll bo[5]={};
			int be=0;
			FOR(j,5) {
				bo[j]=st[j].getval(LL,RR);
				if(bo[j]>bo[be]) be=j;
			}
			FOR(j,5) if(be>=0 && j!=be && bo[j]==bo[be]) be=-1;
			if(be!=-1) (bonus[be]+=bo[be])%=mo;
		}
		else {
			FOR(j,5) {
				if(X[i]==j+1) st[j].inc(LL,RR);
				else st[j].clear(LL,RR);
			}
		}
	}
	FOR(i,5) cout<<((bonus[i]+st[i].getval(0,V.size()))%mo) << " \n"[i==4];
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
