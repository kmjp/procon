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

string A,B,S;
int C,D;
int p10[101];
int all[101][55][1000];

int hoge(string v) {
	int ret=0;
	int L=v.size();
	
	int did=0;
	int mo=0;
	int d,i;
	
	for(int same=0;same<L/2;same++) {
		FOR(d,v[same]-'0') {
			int nmo=(mo+d*(p10[same]+p10[L-1-same]))%C;
			int ndid=did+2*d;
			FOR(i,C) if(ndid<=D && (i*p10[same+1]+nmo)%C==0) (ret+=all[L-(same+1)*2][i][D-ndid])%=10000;
		}
		mo+=(v[same]-'0')*(p10[same]+p10[L-1-same])%C;
		did+=2*(v[same]-'0');
	}
	
	string s=v.substr(0,L/2),s2=s;
	reverse(ALL(s2));
	s+=s2;
	if(s<=v && did==D && mo%C==0) ret++;
	
	return ret%10000;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	if(A.back()!='0') A.back()--;
	
	p10[i]=1%C;
	for(i=1;i<=100;i++) p10[i]=p10[i-1]*10%C;
	
	all[0][0][0]=1;
	int d;
	for(i=2;i<=90;i+=2) {
		for(d=0;d<=9;d++) {
			int left=d*(1+p10[i-1])%C;
			FOR(x,C) for(y=0;y<=9*i;y++) {
				int nm=x*10+left;
				(all[i][nm%C][y+2*d]+=all[i-2][x][y])%=10000;
			}
		}
	}
	cout<<(20000+hoge(B)-hoge(A))%10000<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
