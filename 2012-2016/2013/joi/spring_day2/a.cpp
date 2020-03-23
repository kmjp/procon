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

int N,M,C;
int X[202020],Y[201010];
int BX1[202020],BY1[202020],BX2[202020],BY2[202020];
vector<int> Xs,Ys;
vector<pair<int,int>> Xev[606060];
vector<pair<int,int>> Yev[606060];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;
multiset<int> S;
vector<vector<int>> E;

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	Xs.push_back(-1);
	Xs.push_back(1<<30);
	Ys=Xs;
	cin>>N>>M>>C;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
	}
	FOR(i,M) {
		cin>>BX1[i]>>BY1[i]>>BX2[i]>>BY2[i];
		Xs.push_back(BX1[i]);
		Xs.push_back(BX2[i]);
		Ys.push_back(BY1[i]);
		Ys.push_back(BY2[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		Xev[X[i]].push_back({Y[i],M+i});
		Yev[Y[i]].push_back({X[i],M+i});
	}
	FOR(i,M) {
		BX1[i]=lower_bound(ALL(Xs),BX1[i])-Xs.begin();
		BX2[i]=lower_bound(ALL(Xs),BX2[i])-Xs.begin();
		BY1[i]=lower_bound(ALL(Ys),BY1[i])-Ys.begin();
		BY2[i]=lower_bound(ALL(Ys),BY2[i])-Ys.begin();
		Xev[BX1[i]].push_back({-1,i});
		Xev[BX2[i]].push_back({1<<20,M+N+i});
		Yev[BY1[i]].push_back({-1,i});
		Yev[BY2[i]].push_back({1<<20,M+N+i});
	}
	
	S.insert(1<<30);
	FOR(i,Ys.size()) {
		int pre=-1;
		sort(ALL(Yev[i]));
		FORR(ev,Yev[i]) {
			int e=ev.second;
			if(e<M) {
				S.insert(BX1[e]);
				bt.add(BX1[e],1);
				bt.add(BX2[e]+1,-1);
			}
			else if(e<N+M) {
				e-=M;
				if(pre>=0) {
					if(bt(X[pre])==0 && *S.lower_bound(X[pre])>X[e]) {
						E.push_back({abs(Xs[X[e]]-Xs[X[pre]]),e,pre});
					}
				}
				pre=e;
				
			}
			else {
				e-=N+M;
				S.erase(S.find(BX1[e]));
				bt.add(BX1[e],-1);
				bt.add(BX2[e]+1,1);
			}
		}
	}
	FOR(i,Xs.size()) {
		int pre=-1;
		sort(ALL(Xev[i]));
		FORR(ev,Xev[i]) {
			int e=ev.second;
			if(e<M) {
				S.insert(BY1[e]);
				bt.add(BY1[e],1);
				bt.add(BY2[e]+1,-1);
			}
			else if(e<N+M) {
				e-=M;
				if(pre>=0) {
					if(bt(Y[pre])==0 && *S.lower_bound(Y[pre])>Y[e]) {
						E.push_back({abs(Ys[Y[e]]-Ys[Y[pre]]),e,pre});
					}
				}
				pre=e;
				
			}
			else {
				e-=N+M;
				S.erase(S.find(BY1[e]));
				bt.add(BY1[e],-1);
				bt.add(BY2[e]+1,1);
			}
		}
	}
	
	sort(ALL(E));
	vector<ll> cand,S;
	int num=N;
	S.push_back(0);
	FORR(e,E) {
		if(uf[e[1]]!=uf[e[2]]) {
			num--;
			cand.push_back(e[0]);
			S.push_back(S.back()+e[0]);
			uf(e[1],e[2]);
		}
	}
	while(C--) {
		cin>>x>>y;
		if(y<num) {
			cout<<-1<<endl;
		}
		else {
			ll ret=1LL*num*x;
			y-=num;
			l=min((ll)y,(ll)(cand.end()-lower_bound(ALL(cand),x)));
			ret+=1LL*l*x+S[cand.size()-l];
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
