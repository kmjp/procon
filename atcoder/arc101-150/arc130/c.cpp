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

string A,B;
int C[2][10],D[2][10];
string X,Y;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	FORR(c,A) C[0][c-'0']++;
	FORR(c,B) C[1][c-'0']++;
	
	int num=0;
	X=A,Y=B;
	//‘«‚µ‚Ä10
	for(x=1;x<=9;x++) {
		for(y=1;y<=9;y++) if(x+y>=10&&C[0][x]&&C[1][y]) {
			string S,T;
			int tmp=1;
			FOR(i,10) D[0][i]=C[0][i],D[1][i]=C[1][i];
			D[0][x]--;
			D[1][y]--;
			S+='0'+x;
			T+='0'+y;
			for(i=1;i<=8;i++) {
				j=9-i;
				while(D[0][i]&&D[1][j]) {
					D[0][i]--;
					D[1][j]--;
					S+='0'+i;
					T+='0'+j;
					tmp++;
				}
			}
			for(i=1;i<=9;i++) {
				for(j=1;j<=9;j++) if(i+j>=9) {
					while(D[0][i]&&D[1][j]) {
						D[0][i]--;
						D[1][j]--;
						S+='0'+i;
						T+='0'+j;
						tmp++;
					}
				}
			}
			
			reverse(ALL(S));
			reverse(ALL(T));
			while(S.size()<A.size()&&T.size()<B.size()) {
				FOR(i,10) {
					if(D[0][i]) {
						D[0][i]--;
						S+='0'+i;
						break;
					}
				}
				FOR(i,10) {
					if(D[1][i]) {
						D[1][i]--;
						T+='0'+i;
						break;
					}
				}
			}
			reverse(ALL(S));
			reverse(ALL(T));
			
			
			for(i=9;i>=1;i--) while(D[0][i]) {
				if(i==9) tmp++;
				D[0][i]--;
				S+='0'+i;
			}
			for(i=9;i>=1;i--) while(D[1][i]) {
				if(i==9) tmp++;
				D[1][i]--;
				T+='0'+i;
			}
			
			reverse(ALL(S));
			reverse(ALL(T));
			if(tmp>num) {
				num=tmp;
				X=S;
				Y=T;
			}
			
			
		}
	}
	
	cout<<X<<endl;
	cout<<Y<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
