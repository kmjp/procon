#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W,K,L,R;
string S[555];

ll D[2][555][555];
char from[2][555][555];
int fromdy[2][555][555];
int fromdx[2][555][555];
string A[2]={"RLDU","LRUD"};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>L>>R;
	FOR(y,H) cin>>S[y];
	
	if((R-L)%2==0) {
		cout<<"No"<<endl;
		return;
	}
	
	FOR(y,H) FOR(x,W) {
		D[0][y][x]=D[1][y][x]=1LL<<60;
	}
	D[0][0][0]=D[1][H-1][W-1]=0;
	queue<int> Q;
	Q.push(0);
	Q.push(H*W+(H-1)*W+W-1);
	while(Q.size()) {
		int id=Q.front()/H/W;
		int cy=Q.front()/W%H;
		int cx=Q.front()%W;
		Q.pop();
		FOR(i,4) {
			int dy[]={0,0,1,-1};
			int dx[]={1,-1,0,0};
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			if(D[id][ty][tx]==1LL<<60) {
				D[id][ty][tx]=D[id][cy][cx]+1;
				from[id][ty][tx]=A[id][i];
				fromdy[id][ty][tx]=-dy[i];
				fromdx[id][ty][tx]=-dx[i];
				Q.push(id*H*W+ty*W+tx);
			}
		}
	}
	
	FOR(y,H) FOR(x,W) {
		if(D[0][y][x]>L||(D[0][y][x]%2==L%2)) continue;
		if(D[1][y][x]>K-R||(D[1][y][x]%2!=(K-R)%2)) continue;
		int t=0;
		if(y&&y+1<H&&S[y-1][x]=='.'&&S[y+1][x]=='.') t=1;
		if(x&&x+1<W&&S[y][x-1]=='.'&&S[y][x+1]=='.') t=2;
		if(t==0) continue;
		
		int cy=y,cx=x;
		string S;
		while(cy||cx) {
			S+=from[0][cy][cx];
			int dy=fromdy[0][cy][cx];
			int dx=fromdx[0][cy][cx];
			cy+=dy;
			cx+=dx;
		}
		reverse(ALL(S));
		while(S.size()<K-D[1][y][x]) {
			if(t==1) S+="UD";
			if(t==2) S+="LR";
		}
		cy=y,cx=x;
		
		while(cy<H-1||cx<W-1) {
			S+=from[1][cy][cx];
			int dy=fromdy[1][cy][cx];
			int dx=fromdx[1][cy][cx];
			cy+=dy;
			cx+=dx;
		}
		cout<<"Yes"<<endl;
		cout<<S<<endl;
		return;
		
	}
	cout<<"No"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
