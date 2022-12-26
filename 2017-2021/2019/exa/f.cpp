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

int H,W,Q;
string LR,UD;
int SY,SX,TY,TX;

vector<int> CY[202020];
vector<int> CX[202020];
int LU[202020],LD[202020];
int RU[202020],RD[202020];
int UL[202020],UR[202020];
int DL[202020],DR[202020];

int revx[202020],revy[202020];
ll dist[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	cin>>LR>>UD;
	
	
	int U=W-1,D=W-1;
	for(i=W-1;i>=0;i--) {
		if(UD[i]=='N') U=i;
		if(UD[i]=='S') D=i;
		CX[i].push_back(U);
		CX[i].push_back(D);
	}
	U=D=0;
	FOR(i,W) {
		if(UD[i]=='N') U=i;
		if(UD[i]=='S') D=i;
		CX[i].push_back(U);
		CX[i].push_back(D);
	}
	int L=0,R=0;
	FOR(i,H) {
		if(LR[i]=='W') L=i;
		if(LR[i]=='E') R=i;
		CY[i].push_back(L);
		CY[i].push_back(R);
	}
	L=R=H-1;
	for(i=H-1;i>=0;i--) {
		if(LR[i]=='W') L=i;
		if(LR[i]=='E') R=i;
		CY[i].push_back(L);
		CY[i].push_back(R);
	}
	
	while(Q--) {
		cin>>SY>>SX>>TY>>TX;
		SY--;
		SX--;
		TY--;
		TX--;
		vector<int> Xs,Ys;
		FORR(y,CY[SY]) Ys.push_back(y);
		FORR(y,CY[TY]) Ys.push_back(y);
		FORR(x,CX[SX]) Xs.push_back(x);
		FORR(x,CX[TX]) Xs.push_back(x);
		
		sort(ALL(Xs));
		sort(ALL(Ys));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		Ys.erase(unique(ALL(Ys)),Ys.end());
		
		FOR(i,Xs.size()) revx[Xs[i]]=i;
		FOR(i,Ys.size()) revy[Ys[i]]=i;
		FOR(y,Ys.size()) FOR(x,Xs.size()) dist[y][x]=1LL<<60;
		priority_queue<pair<ll,int>> PQ;
		
		dist[revy[SY]][revx[SX]]=0;
		PQ.push({0,revy[SY]*10+revx[SX]});
		
		while(PQ.size()) {
			ll co=-PQ.top().first;
			int cy=PQ.top().second/10;
			int cx=PQ.top().second%10;
			PQ.pop();
			if(dist[cy][cx]!=co) continue;
			
			if(LR[Ys[cy]]=='W' && cx) {
				ll nc=co+abs(Xs[cx]-Xs[cx-1]);
				if(nc<dist[cy][cx-1]) {
					dist[cy][cx-1]=nc;
					PQ.push({-nc,(cy)*10+cx-1});
				}
			}
			if(LR[Ys[cy]]=='E' && cx<Xs.size()-1) {
				ll nc=co+abs(Xs[cx]-Xs[cx+1]);
				if(nc<dist[cy][cx+1]) {
					dist[cy][cx+1]=nc;
					PQ.push({-nc,(cy)*10+cx+1});
				}
			}
			if(UD[Xs[cx]]=='N' && cy) {
				ll nc=co+abs(Ys[cy]-Ys[cy-1]);
				if(nc<dist[cy-1][cx]) {
					dist[cy-1][cx]=nc;
					PQ.push({-nc,(cy-1)*10+cx});
				}
			}
			if(UD[Xs[cx]]=='S' && cy<Ys.size()-1) {
				ll nc=co+abs(Ys[cy]-Ys[cy+1]);
				if(nc<dist[cy+1][cx]) {
					dist[cy+1][cx]=nc;
					PQ.push({-nc,(cy+1)*10+cx});
				}
			}
		}
		if(dist[revy[TY]][revx[TX]]==1LL<<60) dist[revy[TY]][revx[TX]]=-1;
		cout<<dist[revy[TY]][revx[TX]]<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
