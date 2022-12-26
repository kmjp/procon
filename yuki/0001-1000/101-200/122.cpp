#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int V[7][2];
ll mo=1000000007;
ll ret;
ll up[2][20200];
ll sup[2][20200];
ll down[2][20200];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>V[0][0]>>V[0][1];
	cin>>V[4][0]>>V[4][1];
	cin>>V[1][0]>>V[1][1];
	cin>>V[5][0]>>V[5][1];
	cin>>V[2][0]>>V[2][1];
	cin>>V[6][0]>>V[6][1];
	cin>>V[3][0]>>V[3][1];
	
	
	for(i=1;i<=20000;i++) {
		FOR(j,4) {
			int a=j%4, b=(j+1)%4, c=(j+2)%4, d=(j+3)%4;
			if(V[a][0]<=i && i<=V[a][1]) {
				ll B=max(0,min(i,V[b][1]+1)-V[b][0]);
				ll C=max(0,min(i,V[c][1]+1)-V[c][0]);
				ll D=max(0,min(i,V[d][1]+1)-V[d][0]);
				ll BC=max(0,min(i,min(V[b][1],V[c][1])+1)-max(V[b][0],V[c][0]));
				ll BD=max(0,min(i,min(V[b][1],V[d][1])+1)-max(V[b][0],V[d][0]));
				ll CD=max(0,min(i,min(V[c][1],V[d][1])+1)-max(V[c][0],V[d][0]));
				ll BCD=max(0,min(i,min(V[b][1],min(V[c][1],V[d][1]))+1)-max(V[b][0],max(V[c][0],V[d][0])));
				
				if(B&&C&&D) {
					down[0][i] += B*C*D;
					down[0][i] -= BC*D;
					down[0][i] -= CD*B;
					down[0][i] -= BD*C;
					down[0][i] += 2*BCD;
				}
				
				B=max(0,V[b][1]-max(i,V[b][0]-1));
				C=max(0,V[c][1]-max(i,V[c][0]-1));
				D=max(0,V[d][1]-max(i,V[d][0]-1));
				BC=max(0,min(V[b][1],V[c][1])-max(i,max(V[b][0],V[c][0])-1));
				BD=max(0,min(V[b][1],V[d][1])-max(i,max(V[b][0],V[d][0])-1));
				CD=max(0,min(V[c][1],V[d][1])-max(i,max(V[c][0],V[d][0])-1));
				BCD=max(0,min(V[b][1],min(V[c][1],V[d][1]))-max(i,max(V[b][0],max(V[c][0],V[d][0]))-1));
				if(B&&C&&D) {
					up[0][i] += B*C*D;
					up[0][i] -= BC*D;
					up[0][i] -= CD*B;
					up[0][i] -= BD*C;
					up[0][i] += 2*BCD;
				}
			}
		}
		
		FOR(j,3) {
			int a=j+4, b=(j+1)%3+4, c=(j+2)%3+4;
			if(V[a][0]<=i && i<=V[a][1]) {
				ll B=max(0,min(i,V[b][1]+1)-V[b][0]);
				ll C=max(0,min(i,V[c][1]+1)-V[c][0]);
				ll BC=max(0,min(i,min(V[b][1],V[c][1])+1)-max(V[b][0],V[c][0]));
				down[1][i] += B*C-BC;
				
				B=max(0,V[b][1]-max(i,V[b][0]-1));
				C=max(0,V[c][1]-max(i,V[c][0]-1));
				BC=max(0,min(V[b][1],V[c][1])-max(i,max(V[b][0],V[c][0])-1));
				up[1][i] += B*C-BC;
			}
		}
		
		down[0][i]=(mo+down[0][i]%mo)%mo;
		down[1][i]=(mo+down[1][i]%mo)%mo;
		up[0][i]=(mo+up[0][i]%mo)%mo;
		up[1][i]=(mo+up[1][i]%mo)%mo;
	}
	
	for(i=1;i<=20002;i++) sup[0][i]=(sup[0][i-1]+up[0][i])%mo;
	for(i=1;i<=20002;i++) sup[1][i]=(sup[1][i-1]+up[1][i])%mo;
		
	for(i=1;i<=20000;i++) {
		ret += (sup[0][20002]-sup[0][i])*down[1][i]%mo;
		ret += (sup[1][20002]-sup[1][i])*down[0][i]%mo;
		ret %= mo;
		ret += mo;
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
