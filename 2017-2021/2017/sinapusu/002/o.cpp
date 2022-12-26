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

int N;
double hit[10],home[10],out[10];
int V[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,9) {
		double a,b,c;
		cin>>a>>b;
		c=1-a-b;
		hit[i]=a+c*a+c*c*a;
		home[i]=b+c*b+c*c*b;
		out[i]=1-hit[i]-home[i];
		V[i]=i;
	}
	double ma=0;
	do {
		double prob[8][4]={};
		double sc[8][4]={};
		
		prob[0][0]=1;
		FOR(i,9) {
			double nprob[8][4]={};
			double nsc[8][4]={};
			
			FOR(y,4) {
				FOR(x,8) if(prob[x][y]>0) {
					if(y==3) {
						nprob[x][y] += prob[x][y];
						nsc[x][y] +=   prob[x][y]*sc[x][y];
					}
					else {
						//home
						nprob[0][y] += prob[x][y]*home[V[i]];
						nsc[0][y] +=   prob[x][y]*home[V[i]]*(sc[x][y]+__builtin_popcount(x)+1);
						//hit
						nprob[((x<<1)&7)+1][y] += prob[x][y]*hit[V[i]];
						nsc[((x<<1)&7)+1][y]   += prob[x][y]*hit[V[i]]*(sc[x][y]+((x&4)>>2));
						
						//out
						nprob[x][y+1] += prob[x][y]*out[V[i]];
						nsc[x][y+1] +=   prob[x][y]*out[V[i]]*sc[x][y];
					}
				}
			}
			
			FOR(y,4) {
				FOR(j,8) {
					prob[j][y]=nprob[j][y];
					sc[j][y]=(nprob[j][y]==0)?0:(nsc[j][y]/nprob[j][y]);
				}
			}
		}
		double tot=0;
		FOR(y,4) FOR(x,8) tot += prob[x][y]*sc[x][y];
		ma=max(ma,tot);
		
	} while(next_permutation(V,V+9));
	
	_P("%.12lf\n",ma);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
