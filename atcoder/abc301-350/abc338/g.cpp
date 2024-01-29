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

string S;
int N;
int O[1010101];
const ll mo=998244353;
ll p10[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	p10[0]=1;
	FOR(i,1010100) p10[i+1]=p10[i]*10%mo;
	
	cin>>S;
	S+='+';
	N=S.size();
	FOR(i,N) {
		O[i+1]=O[i]+(S[i]!='+'&&S[i]!='*');
	}
	int pre=0;
	ll ret=0;
	FOR(i,N) {
		if(S[i]=='+') {
			int L=O[pre+1];
			int R=O[N]-O[i]+1;
			//ç∂ë§
			ll A=1,B=0;
			for(x=pre;x<i;x++) {
				if(S[x]=='*') {
					A=A*B%mo;
					B=0;
				}
				else {
					B=(B*10+S[x]-'0')%mo;
					if(x==i-1) {
						(ret+=A*B%mo*L%mo*R)%=mo;
					}
					else {
						(ret+=A*B%mo*L)%=mo;
					}
				}
			}
			//âEë§
			A=1,B=0,k=0;
			for(x=i-1;x>pre;x--) {
				if(S[x]=='*') {
					A=A*B%mo;
					B=k=0;
				}
				else {
					B=(B+p10[k++]*(S[x]-'0'))%mo;
					(ret+=A*B%mo*R)%=mo;
				}
			}
			{
				ll A=0,B=0,C=0,k=0;
				for(x=pre+1;x<=i-2;x++) {
					if(S[x]=='*') {
						A=(A*B+C)%mo;
						B=C=k=0;
					}
					else {
						y=S[x]-'0';
						B=(B*10+y)%mo;
						k++;
						C=(C*10+y*k)%mo;
						(ret+=A*B+C)%=mo;
					}
				}
			}
			
			pre=i+1;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
