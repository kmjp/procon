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

int H,W;
string S[606];
int A[606][606][2][2][2][2];

int get(int L,int R,int U,int D,int l,int r,int u,int d) {
	return A[D][R][l][r][u][d]-A[D][L][l][r][u][d]-A[U][R][l][r][u][d]+A[U][L][l][r][u][d];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) {
		int l,r,u,d;
		FOR(l,2) FOR(r,2) FOR(d,2) FOR(u,2) {
			A[y+1][x+1][l][r][u][d]=A[y+1][x][l][r][u][d]+A[y][x+1][l][r][u][d]-A[y][x][l][r][u][d];
			if(S[y][x]=='.') {
				int add=0;
				if((l==1||(x==0||S[y][x-1]=='#'))&&(r==0&&x+1<W&&S[y][x+1]=='.')) add=1;
				if((u==1||(y==0||S[y-1][x]=='#'))&&(d==0&&y+1<H&&S[y+1][x]=='.')) add=1;
				if((l==1||(x==0||S[y][x-1]=='#'))&&(u==1||(y==0||S[y-1][x]=='#'))&&(r==1||x+1==W||S[y][x+1]=='#')&&(d==1||y+1==H||S[y+1][x]=='#')) add=1;
				A[y+1][x+1][l][r][u][d]+=add;
			}
		}
	}
	
	int Q;
	cin>>Q;
	while(Q--) {
		int L,R,U,D;
		cin>>U>>L>>D>>R;
		U--,D--,L--,R--;
		H=D-U+1;
		W=R-L+1;
		
		int ret=0;
		if(H==1&&W==1) {
			ret=get(L,L+1,U,U+1,1,1,1,1);
		}
		else if(H==1) {
			
			ret+=get(L,L+1,U,U+1,1,0,1,1); //1マス目
			ret+=get(L+1,R,U,U+1,0,0,1,1); //2-R-1マス目
			ret+=get(R,R+1,U,U+1,0,1,1,1); //2-R-1マス目
		}
		else if(W==1) {
			ret+=get(L,L+1,U+0,U+1,1,1,1,0); //1マス目
			ret+=get(L,L+1,U+1,D+0,1,1,0,0); //2-D-1マス目
			ret+=get(L,L+1,D+0,D+1,1,1,0,1); //2-D-1マス目
		}
		else {
			ret+=get(L+0,L+1,U+0,U+1,1,0,1,0); //左上
			ret+=get(L+0,L+1,D+0,D+1,1,0,0,1); //左下
			ret+=get(R+0,R+1,U+0,U+1,0,1,1,0); //右上
			ret+=get(R+0,R+1,D+0,D+1,0,1,0,1); //右下
			ret+=get(L+0,L+1,U+1,D+0,1,0,0,0); //左
			ret+=get(R+0,R+1,U+1,D+0,0,1,0,0); //右
			ret+=get(L+1,R+0,U+0,U+1,0,0,1,0); //上
			ret+=get(L+1,R+0,D+0,D+1,0,0,0,1); //下
			ret+=get(L+1,R+0,U+1,D+0,0,0,0,0); //真ん中
		}
		cout<<ret<<endl;
			
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
