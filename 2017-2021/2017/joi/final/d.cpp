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

int H,W;
ll A,B,C;
int N;
int Y[101010],X[101010];
ll D[505][505];
ll D2[505][505][5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>A>>B>>C;
	cin>>N;
	H++,W++;
	FOR(y,H) FOR(x,W) D[y][x]=1LL<<60;
	queue<int> Q;
	FOR(i,N) {
		cin>>Y[i]>>X[i];
		D[Y[i]][X[i]]=0;
		Q.push(Y[i]*1000+X[i]);
	}
	while(Q.size()) {
		y=Q.front()/1000;
		x=Q.front()%1000;
		Q.pop();
		int dd[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=y+dd[i];
			int tx=x+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(D[ty][tx]>D[y][x]+C) {
				D[ty][tx]=D[y][x]+C;
				Q.push(ty*1000+tx);
			}
		}
	}
	priority_queue<pair<ll,int>> PQ;
	FOR(y,H) FOR(x,W) FOR(i,5) D2[y][x][i]=1LL<<60;
	D2[Y[0]][X[0]][4]=0;
	PQ.push({0,Y[0]*1000+X[0]+4000000});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int id=PQ.top().second/1000000;
		int cy=PQ.top().second%1000000/1000;
		int cx=PQ.top().second%1000;
		PQ.pop();
		//cout<<cy<<cx<<id<<" "<<co<<endl;
		if(cy==Y[N-1]&&cx==X[N-1]) {
			cout<<co<<endl;
			return;
		}
		if(D2[cy][cx][id]!=co) continue;
		
		int dd[4]={1,0,-1,0};
		if(id==4) {
			FOR(i,4) {
				if(D2[cy][cx][i]>co+B) {
					D2[cy][cx][i]=co+B;
					PQ.push({-D2[cy][cx][i],cy*1000+cx+i*1000000});
				}
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D2[ty][tx][4]>co+C) {
					D2[ty][tx][4]=co+C;
					PQ.push({-D2[ty][tx][4],ty*1000+tx+4000000});
				}
			}
		}
		else {
			if(D2[cy][cx][4]>co+D[cy][cx]) {
				D2[cy][cx][4]=co+D[cy][cx];
				PQ.push({-D2[cy][cx][4],cy*1000+cx+4000000});
			}
			int ty=cy+dd[id];
			int tx=cx+dd[id^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(D2[ty][tx][id]>co+A) {
				D2[ty][tx][id]=co+A;
				PQ.push({-D2[ty][tx][id],ty*1000+tx+id*1000000});
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
