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

int N,M;
int A[101010],B[101010],C[101010],E[101010];

int SB[101010];
ll SC[101010];
int iscycle[101010];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<101010> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int P=0,X=0,Y,Z;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		E[A[i]]++;
		E[B[i]]++;
		if(uf[A[i]]!=uf[B[i]]) {
			SB[uf[A[i]]]=SB[uf[B[i]]]=SB[uf[A[i]]]+SB[uf[B[i]]];
			SC[uf[A[i]]]=SC[uf[B[i]]]=SC[uf[A[i]]]+SC[uf[B[i]]];
			uf(A[i],B[i]);
		}
		if(A[i]!=B[i]) P++;
		SB[uf[A[i]]]++;
		SC[uf[A[i]]]+=C[i]-1;
	}
	
	FOR(i,N) iscycle[i]=1;
	FOR(i,N) {
		if(E[i]!=2) iscycle[uf[i]]=0;
	}
	
	
	vector<ll> shortc,O;
	ll Tin=0,Tout=0;
	
	FOR(i,N) if(uf[i]==i) {
		if(uf.count(i)!=SB[i]) iscycle[i]=0;
		// long cycle
		//cout<<"!"<<i<<" "<<uf.count(i)<<" "<<SB[i]<<" "<<iscycle[i]<<" "<<SC[i]<<endl;
		if(iscycle[i]) {
			if(SB[i]==1) {
				if(SC[i]>1) shortc.push_back(SC[i]-1);
			}
			else {
				X++;
				Tin+=SC[i];
			}
		}
	}
	
	FOR(i,M) {
		if(iscycle[uf[A[i]]]==0) {
			//cout<<"!add"<<i<<" "<<A[i]<<" "<<B[i]<<" "<<C[i]<<endl;
			if(A[i]!=B[i]) Tout+=C[i]-1;
			else if(C[i]>1) O.push_back(C[i]-1);
		}
	}

	sort(ALL(shortc));
	sort(ALL(O));
	reverse(ALL(shortc));
	reverse(ALL(O));
	
	shortc.insert(shortc.begin(),0);
	O.insert(O.begin(),0);
	for(i=1;i<shortc.size();i++) shortc[i]+=shortc[i-1];
	for(i=1;i<O.size();i++) O[i]+=O[i-1];

	int mi=1<<30;
	int z;
	/*
	cout<<P<<" "<<X<<" "<<Tout<<" "<<Tin<<endl;
	FORR(s,shortc) cout<<s<<" ";
	cout<<endl;
	FORR(s,O) cout<<s<<" ";
	cout<<endl;
	*/
	FOR(y,shortc.size()) FOR(z,O.size()) if((X+y==0 || Tout+O[z]>0) && Tout+Tin+shortc[y]+O[z]>=X) {
		mi=min(mi,P+X+2*y+z);
	}
	
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
