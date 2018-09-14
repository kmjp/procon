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

int N,K;
int X[101010],Y[101010],Xid[101010],Xpid[101010],Xmid[101010];

vector<int> Xs,cand[101010];
vector<pair<int,int>> XpY,XmY;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> XpYbit,XmYbit,XpYnum,XmYnum;

int prevnum(BIT<ll,20>& bit,int L) {
	ll v=bit(L);
	int i;
	for(i=20;i>=0;i--) {
		if(L-(1<<i)>=0 && bit(L-(1<<i))>=v) L-=1<<i;
	}
	return L-1;
	
}

int nexnum(BIT<ll,20>& bit,int L) {
	ll v=bit(L);
	int i;
	for(i=19;i>=0;i--) {
		if(L+(1<<i)<N+1 && bit(L+(1<<i))==v) L+=1<<i;
	}
	return L+1;
	
}

ll score(int R,int L,ll x) {
	ll ret=0;
	ret+=XpYbit(R)-x*XpYnum(R);
	ret+=XmYbit(L)+x*XmYnum(L);
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs.push_back(X[i]);
		XpY.push_back({X[i]+Y[i],i});
		XmY.push_back({-X[i]+Y[i],i});
		
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	sort(ALL(XpY));
	sort(ALL(XmY));
	FOR(i,N) {
		Xpid[XpY[i].second]=i+1;
		Xmid[XmY[i].second]=i+1;
		XpYnum.add(i+1,1);
		XpYbit.add(i+1,XpY[i].first);
		Xid[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		cand[Xid[i]].push_back(i);
	}
	
	ll ret=1LL<<60;
	int L=0,R=K;
	FOR(i,Xs.size()) {
		x=Xs[i];
		while(XpYnum(R)+XmYnum(L)>K) {
			int PR=prevnum(XpYnum,R);
			int PL=prevnum(XmYnum,L);
			if(PR==-1) L=PL;
			else if(PL==-1) R=PR;
			else {
				if(score(PR,L,x)<=score(R,PL,x)) R=PR;
				else L=PL;
			}
		}
		while(XpYnum(R)+XmYnum(L)<K) {
			int PR=nexnum(XpYnum,R);
			int PL=nexnum(XmYnum,L);
			if(PR>=N+1) L=PL;
			else if(PL>=N+1) R=PR;
			else {
				if(score(PR,L,x)<=score(R,PL,x)) R=PR;
				else L=PL;
			}
		}
		
		while(1) {
			int PR=prevnum(XpYnum,R);
			int PL=nexnum(XmYnum,L);
			if(PR==-1) break;
			if(PL>=N+1) break;
			if(score(R,L,x)<=score(PR,PL,x)) break;
			R=PR;
			L=PL;
		}
		while(1) {
			int PR=nexnum(XpYnum,R);
			int PL=prevnum(XmYnum,L);
			if(PR>=N+1) break;
			if(PL==-1) break;
			if(score(R,L,x)<=score(PR,PL,x)) break;
			R=PR;
			L=PL;
		}
		assert(XpYnum(R)+XmYnum(L)==K);
		ret=min(ret,score(R,L,x));
		
		
		FORR(e,cand[i]) {
			XpYnum.add(Xpid[e],-1);
			XpYbit.add(Xpid[e],-(X[e]+Y[e]));
			XmYnum.add(Xmid[e],1);
			XmYbit.add(Xmid[e],-X[e]+Y[e]);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
