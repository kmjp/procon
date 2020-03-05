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
string C[2010];
ll D[2020][2020];
int R;
ll Y[101010],X[101010],S[101010],T[101010];
int NG[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>C[y];
		FOR(x,W) if(C[y][x]=='#') NG[y][x]=1<<25;
	}
	
	priority_queue<pair<ll,int>> Q;
	cin>>R;
	FOR(i,R) {
		cin>>Y[i]>>X[i]>>S[i]>>T[i];
		Y[i]--,X[i]--;
		S[i]*=2;
		T[i]*=2;
		Q.push({-(S[i]-1),i+R});
		Q.push({-(T[i]-1),i});
	}
	FOR(y,H) FOR(x,W) D[y][x]=1L<<60;
	D[0][0]=0;
	Q.push({0,2*R});
	while(Q.size()) {
		ll now=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(cur<R) {
			int cy=Y[cur];
			int cx=X[cur];
			NG[Y[cur]][X[cur]]--;
			int ok=0;
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0||ty>=H || tx<0||tx>=W||NG[ty][tx]>0) continue;
				if(D[ty][tx]<=now) ok=1;
			}
			//cout<<now<<" T "<<cur<<" "<<Y[cur]<<","<<X[cur]<<" "<<ok<<endl;
			if(ok) {
				D[cy][cx]=now+3;
				Q.push({-D[cy][cx],2*R+cy*2000+cx});
			}
		}
		else if(cur<2*R) {
			cur-=R;
			//cout<<now<<" S "<<cur<<" "<<Y[cur]<<","<<X[cur]<<endl;
			NG[Y[cur]][X[cur]]++;
			D[Y[cur]][X[cur]]=1LL<<60;
		}
		else {
			int cy=(cur-2*R)/2000;
			int cx=(cur-2*R)%2000;
			if(now!=D[cy][cx]) continue;
			//cout<<now<<"  "<<cy<<" "<<cx<<" "<<NG[cy][cx]<<endl;
			if(cy==H-1&&cx==W-1) {
				cout<<D[cy][cx]/2<<endl;
				return;
			}
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0||ty>=H || tx<0||tx>=W||NG[ty][tx]>0) continue;
				if(D[ty][tx]>D[cy][cx]+2) {
					D[ty][tx]=D[cy][cx]+2;
					Q.push({-D[ty][tx],2*R+ty*2000+tx});
				}
			}
			
		}
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
