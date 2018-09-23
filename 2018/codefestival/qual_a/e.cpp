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

int X,Y,N,S;
ll A[202020],B[202020];

int LB[202020],RB[202020],NG[202020],TNG;
int TLB,TRB;

vector<pair<ll,ll>> ev;

int ok(ll d) {
	int i,j;
	
	ev.clear();
	TLB=TRB=TNG=0;
	
	FOR(i,N) {
		LB[i]=X+Y+1;
		RB[i]=-1;
		
		FOR(j,S+1) {
			ll tot=A[i]*j+B[i]*(S-j);
			
			if(0<=tot && tot<=d) {
				LB[i]=min(LB[i],j);
				RB[i]=max(RB[i],j);
				ev.push_back({tot+1,(1LL*i<<30)+(j*2)});
			}
			else if(tot>d) {
				ev.push_back({tot-d,(1LL*i<<30)+(j*2)+1});
				ev.push_back({tot+1,(1LL*i<<30)+(j*2)});
			}
		}
		if(LB[i]<X+Y+1) {
			TLB+=LB[i];
			TRB+=RB[i];
			NG[i]=0;
			
		}
		else {
			NG[i]=1;
			TNG++;
		}
	}
	
	sort(ALL(ev));
	ll pre=-1;
	FORR(e,ev) {
		if(pre!=e.first) {
			if(TNG==0 && TLB<=X && X<=TRB) return 1;
		}
		pre=e.first;
		int add=e.second&1;
		int x=(e.second>>30);
		int y=(e.second>>1)&((1<<29)-1);
		
		if(NG[x]==0) {
			TLB-=LB[x];
			TRB-=RB[x];
		}
		if(add==0) {
			// rem
			if(RB[x]==y) RB[x]--;
			if(LB[x]==y) LB[x]++;
			
			if(NG[x]==0 && LB[x]>RB[x]) {
				NG[x]=1;
				TNG++;
			}
		}
		else {
			// add
			if(NG[x]) {
				TNG--;
				NG[x]=0;
				LB[x]=RB[x]=y;
			}
			if(y==LB[x]-1) LB[x]--;
			if(y==RB[x]+1) RB[x]++;
		}
		if(NG[x]==0) {
			TLB+=LB[x];
			TRB+=RB[x];
		}
	}
	if(TNG==0 && TLB<=X && X<=TRB) return 1;
	
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	S=(X+Y)/N;
	
	ll D=(1LL<<47)-1;
	for(i=46;i>=0;i--) if(ok(D-(1LL<<i))) D-=1LL<<i;
	cout<<D<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
