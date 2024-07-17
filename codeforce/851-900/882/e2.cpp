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

int A[5][5][5];
int N;
int ret[5050];
string B="";

int ask(int a,int b,int c) {
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	cout<<"? "<<(a+1)<<" "<<(b+1)<<" "<<(c+1)<<endl;
	if(B.size()) return A[B[a]-'0'][B[b]-'0'][B[c]-'0'];
	cin>>a;
	return a;
}

void slow() {
	int R[9][9][9];
	int a,b,c;
	FOR(a,N) for(b=a+1;b<N;b++) for(c=b+1;c<N;c++) {
		R[a][b][c]=ask(a,b,c);
	}
	
	int mask,i;
	int B[9],C[9];
	int ok=0;
	FOR(mask,1<<(2*N)) {
		FOR(i,N) B[i]=(mask>>(2*i))%4+1;
		int ng=0;
		FOR(a,N) for(b=a+1;b<N;b++) for(c=b+1;c<N;c++) if(R[a][b][c]!=A[B[a]][B[b]][B[c]]) ng=1;
		if(ng==0) {
			ok++;
			FOR(a,N) C[a]=B[a];
		}
	}
	
	if(ok==1) {
		cout<<"!";
		FOR(a,N) cout<<" "<<C[a];
		cout<<endl;
	}
	else {
		cout<<"! -1"<<endl;
	}
	
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(x=1;x<=4;x++) {
		for(y=1;y<=4;y++) {
			for(k=1;k<=4;k++) {
				if(k>=y+x) continue;
				if(y>=x+k) continue;
				if(x>=y+k) continue;
				int s=x+y+k;
				A[x][y][k]=s*(s-2*x)*(s-2*y)*(s-2*k);
			}
		}
	}
	
	cin>>N;
	
	if(N<9) {
		slow();
	}
	int a[5][3]={};
	MINUS(a);
	int t=0;
	FOR(x,9) for(y=x+1;y<9;y++) for(k=y+1;k<9;k++) {
		i=ask(x,y,k);
		for(j=1;j<=4;j++) if(i==A[j][j][j]) {
			t=j;
			a[t][0]=x,a[t][1]=y,a[t][2]=k;
			ret[x]=ret[y]=ret[k]=t;
		}
	}
	
	if(t==1) {
		vector<int> C;
		int A0=a[t][0];
		int A1=a[t][1];
		FOR(i,N) if(t==1&&ret[i]==0) {
			x=ask(A0,A1,i);
			if(x!=0) {
				ret[i]=1;
			}
			else {
				FORR(c,C) {
					y=ask(A0,i,c);
					if(y==A[1][2][2]) t=2;
					if(y==A[1][3][3]) t=3;
					if(y==A[1][4][4]) t=4;
					if(t>1) {
						a[t][0]=i;
						a[t][1]=c;
						ret[i]=ret[c]=t;
						break;
					}
				}
				if(t>1) break;
				C.push_back(i);
			}
		}
	}
	
	if(t!=1) {
		int A0=a[t][0];
		int A1=a[t][1];
		FOR(i,N) if(ret[i]==0) {
			y=ask(i,A0,A1);
			FOR(j,4) if(A[t][t][j+1]==y) ret[i]=j+1;
		}
	}
	FOR(i,N) if(ret[i]==0) {
		cout<<"! -1"<<endl;
		return;
	}
	cout<<"!";
	FOR(i,N) cout<<" "<<ret[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
