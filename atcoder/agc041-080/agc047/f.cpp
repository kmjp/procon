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
int X[202020],Y[202020];
vector<int> Xs,Ys,Y2s;
int cand[202020];
int Y2[202020];

int start[202020],len[202020],type[202020];
ll ret[202020];

int dist(int a,int b) {
	return abs(Xs[X[a]]-Xs[X[b]])+abs(Ys[Y[a]]-Ys[Y[b]]);
}

vector<ll> hoge(int L,int R,int turn,int miy,int may) {
	int NL=L,NR=R;
	if(turn==0) {
		if(NR+1<M&&(type[NR+1]==1||type[NR+1]==2)&&Y2[NR+1]==miy-1) NR++, miy--;
		if(NL&&(type[NL-1]==1||type[NL-1]==2)&&Y2[NL-1]==may+1) NL--, may++;
	}
	else {
		if(NR+1<M&&(type[NR+1]==0||type[NR+1]==2)&&Y2[NR+1]==may+1) NR++, may++;
		if(NL&&(type[NL-1]==0||type[NL-1]==2)&&Y2[NL-1]==miy-1) NL--, miy--;
	}
	
	if(NL==L&&NR==R) return {0,0};
	vector<ll> A=hoge(NL,NR,turn^1,miy,may);
	vector<ll> ret={1LL<<60,1LL<<60};
	int NLx=cand[start[NL]];
	int NRx=cand[start[NR]+len[NR]-1];
	int Lx=cand[start[L]];
	int Rx=cand[start[R]+len[R]-1];
	
	if(NL<L&&NR>R) {
		ret[0]=min(ret[0],A[0]+dist(NLx,NRx)+dist(Lx,NRx)-len[NL]-len[NR]);
		ret[0]=min(ret[0],A[1]+dist(NLx,NRx)+dist(Lx,NLx)-len[NL]-len[NR]);
		ret[1]=min(ret[1],A[0]+dist(NLx,NRx)+dist(Rx,NRx)-len[NL]-len[NR]);
		ret[1]=min(ret[1],A[1]+dist(NLx,NRx)+dist(Rx,NLx)-len[NL]-len[NR]);
	}
	else if(NL<L) {
		ret[0]=A[0]+dist(Lx,NLx)-len[NL];
		ret[1]=A[0]+dist(Rx,NLx)-len[NL];
	}
	else if(NR>R) {
		ret[0]=A[1]+dist(Lx,NRx)-len[NR];
		ret[1]=A[1]+dist(Rx,NRx)-len[NR];
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
		ret[i]=1LL<<60;
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		cand[X[i]]=i;
	}
	
	int cur=0;
	while(cur<N) {
		start[M]=cur;
		len[M]=1;
		Y2[M]=Y[cand[cur]];
		Y2s.push_back(Y[cand[cur]]);
		if(cur+1<N&&Y[cand[cur+1]]==Y[cand[cur]]+1) {
			type[M]=0;
			while(cur+1<N&&Y[cand[cur+1]]==Y[cand[cur]]+1) {
				len[M]++;
				cur++;
			}
		}
		else if(cur+1<N&&Y[cand[cur+1]]==Y[cand[cur]]-1) {
			type[M]=1;
			while(cur+1<N&&Y[cand[cur+1]]==Y[cand[cur]]-1) {
				len[M]++;
				cur++;
			}
		}
		else {
			type[M]=2;
		}
		cur++;
		M++;
	}
	sort(ALL(Y2s));
	FOR(i,M) {
		Y2[i]=lower_bound(ALL(Y2s),Y2[i])-Y2s.begin();
	}
	FOR(i,M) {
		vector<ll> V;
		int Lx=cand[start[i]];
		int Rx=cand[start[i]+len[i]-1];
		if(type[i]==0||type[i]==2) {
			V=hoge(i,i,0,Y2[i],Y2[i]);
			for(x=start[i];x<start[i]+len[i];x++) {
				ret[cand[x]]=min(ret[cand[x]],V[0]+dist(Rx,Lx)+dist(Rx,cand[x])-(len[i]-1));
				ret[cand[x]]=min(ret[cand[x]],V[1]+dist(Rx,Lx)+dist(Lx,cand[x])-(len[i]-1));
			}
		}
		if(type[i]==1||type[i]==2) {
			V=hoge(i,i,1,Y2[i],Y2[i]);
			for(x=start[i];x<start[i]+len[i];x++) {
				ret[cand[x]]=min(ret[cand[x]],V[0]+dist(Rx,Lx)+dist(Rx,cand[x])-(len[i]-1));
				ret[cand[x]]=min(ret[cand[x]],V[1]+dist(Rx,Lx)+dist(Lx,cand[x])-(len[i]-1));
			}
		}
	}
	FOR(i,N) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
