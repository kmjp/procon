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
int T[1010],X1[1010],X2[1010],Y1[1010],Y2[1010];
int SX,SY,TX,TY;
vector<int> Xs,Ys;

int H,W;
int L[4020][4020],R[4020][4020];
int U[4020][4020],D[4020][4020];
ll dist[4020][4020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>SX>>SY>>TX>>TY;
	Xs.push_back(SX);
	Xs.push_back(TX);
	Ys.push_back(SY);
	Ys.push_back(TY);
	
	FOR(i,M) {
		cin>>T[i]>>X1[i]>>X2[i]>>Y1[i]>>Y2[i];
		Xs.push_back(X1[i]);
		Xs.push_back(X1[i]+1);
		Xs.push_back(X2[i]);
		Xs.push_back(X2[i]+1);
		Ys.push_back(Y1[i]);
		Ys.push_back(Y1[i]+1);
		Ys.push_back(Y2[i]);
		Ys.push_back(Y2[i]+1);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	H=Ys.size();
	W=Xs.size();
	
	SX=lower_bound(ALL(Xs),SX)-Xs.begin();
	SY=lower_bound(ALL(Ys),SY)-Ys.begin();
	TX=lower_bound(ALL(Xs),TX)-Xs.begin();
	TY=lower_bound(ALL(Ys),TY)-Ys.begin();
	FOR(i,M) {
		X1[i]=lower_bound(ALL(Xs),X1[i])-Xs.begin();
		X2[i]=lower_bound(ALL(Xs),X2[i])-Xs.begin();
		Y1[i]=lower_bound(ALL(Ys),Y1[i])-Ys.begin();
		Y2[i]=lower_bound(ALL(Ys),Y2[i])-Ys.begin();
		if(T[i]==1) {
			D[Y1[i]][X1[i]]++;
			D[Y2[i]][X2[i]+1]++;
			D[Y1[i]][X2[i]+1]--;
			D[Y2[i]][X1[i]]--;
			U[Y1[i]+1][X1[i]]++;
			U[Y2[i]+1][X2[i]+1]++;
			U[Y1[i]+1][X2[i]+1]--;
			U[Y2[i]+1][X1[i]]--;
		}
		else {
			R[Y1[i]][X1[i]]++;
			R[Y2[i]+1][X2[i]]++;
			R[Y1[i]][X2[i]]--;
			R[Y2[i]+1][X1[i]]--;
			L[Y1[i]][X1[i]+1]++;
			L[Y2[i]+1][X2[i]+1]++;
			L[Y1[i]][X2[i]+1]--;
			L[Y2[i]+1][X1[i]+1]--;
		}
	}

	FOR(y,H) FOR(x,W) {
		dist[y][x]=1LL<<60;
		if(y&&x) {
			L[y][x]-=L[y-1][x-1];
			R[y][x]-=R[y-1][x-1];
			U[y][x]-=U[y-1][x-1];
			D[y][x]-=D[y-1][x-1];
		}
		if(y) {
			L[y][x]+=L[y-1][x];
			R[y][x]+=R[y-1][x];
			U[y][x]+=U[y-1][x];
			D[y][x]+=D[y-1][x];
		}
		if(x) {
			L[y][x]+=L[y][x-1];
			R[y][x]+=R[y][x-1];
			U[y][x]+=U[y][x-1];
			D[y][x]+=D[y][x-1];
		}
	}
	dist[SY][SX]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,SY*10000+SX});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/10000;
		int cx=Q.top().second%10000;
		Q.pop();
		if(co!=dist[cy][cx]) continue;
		//cout<<cy<<" "<<cx<<" "<<co<<endl;
		if(cx>0) {
			ll d=co;
			if(L[cy][cx]==0) d++;
			if(L[cy][cx-1]==0) d+=Xs[cx]-Xs[cx-1]-1;
			if(dist[cy][cx-1]>d) {
				dist[cy][cx-1]=d;
				Q.push({-d,(cy*10000)+cx-1});
			}
		}
		if(cx+1<W) {
			ll d=co;
			if(R[cy][cx]==0) d+=Xs[cx+1]-Xs[cx];
			if(dist[cy][cx+1]>d) {
				dist[cy][cx+1]=d;
				Q.push({-d,(cy*10000)+cx+1});
			}
		}
		if(cy>0) {
			ll d=co;
			if(U[cy][cx]==0) d++;
			if(U[cy-1][cx]==0) d+=Ys[cy]-Ys[cy-1]-1;
			if(dist[cy-1][cx]>d) {
				dist[cy-1][cx]=d;
				Q.push({-d,((cy-1)*10000)+cx});
			}
		}
		if(cy+1<H) {
			ll d=co;
			if(D[cy][cx]==0) d+=Ys[cy+1]-Ys[cy];
			if(dist[cy+1][cx]>d) {
				dist[cy+1][cx]=d;
				Q.push({-d,((cy+1)*10000)+cx});
			}
		}
	}
	
	cout<<dist[TY][TX]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
