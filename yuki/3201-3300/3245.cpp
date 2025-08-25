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

int T;
ll N;

vector<int> V[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(int d=0;d*1111<10000;d++) {
		for(int c=0;d*1111+c*111<10000;c++) {
			for(int b=0;d*1111+c*111+b*11<10000;b++) {
				for(int a=0;d*1111+c*111+b*11+a<10000;a++) {
					int s=a+b+c+d;
					int v=d*1111+c*111+b*11+a;
					if(2*a>=s) continue;
					if(2*b>=s) continue;
					if(2*c>=s) continue;
					if(2*d>=s) continue;
					V[v]={a,b,c,d};
				}
			}
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		if(N%8) {
			cout<<-1<<endl;
			continue;
		}
		N/=8;
		
		if(N>=10000) {
			FOR(i,13) FOR(j,3) {
				if(i&&(N-i*111-j*1111)%12==0) {
					ll a=(N-i*111-j*1111)/12;
					cout<<a<<" "<<a<<" "<<i<<" "<<j<<endl;
					assert(i*2<a+a+i);
					assert(a*12+i*111+j*1111==N);
					i=j=100;
					break;
				}
			}
		}
		else {
			if(V[N].empty()) {
				cout<<-1<<endl;
			}
			else {
				ll a=V[N][0]+V[N][1]+V[N][2]+V[N][3];
				ll s=V[N][0]+V[N][1]*11+V[N][2]*111+V[N][3]*1111;
				assert(s==N);
				assert(V[N][0]*2<a);
				assert(V[N][1]*2<a);
				assert(V[N][2]*2<a);
				assert(V[N][3]*2<a);
				cout<<V[N][0]<<" "<<V[N][1]<<" "<<V[N][2]<<" "<<V[N][3]<<endl;
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
