#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int X[101],Y[101];
void rot(int from,int to) {
	X[to]=750+(750-Y[from]);
	Y[to]=750-(750-X[from]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	/*
	int ox=0,oy=750,id=104;
	ox=0,oy=750;id=100+4;
	id-=4; X[id]=ox+id, Y[id]=oy; for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(100+96);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(100+92);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(100+92)+(92+88);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(100+96)-(96+84);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(100+96)-(96+84)-(84+80);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(100+92)+(92+88)+(88+76);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	
	ox=200; id=72+4;
	id-=4; X[id]=ox+id, Y[id]=oy; for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(72+68);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(72+64);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(72+64)+(64+60);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(72+68)-(68+56);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(72+68)-(68+56)-(56+52);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(72+64)+(64+60)+(60+48);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);

	ox=200+72*2; id=44+4;
	id-=4; X[id]=ox+id, Y[id]=oy; for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(44+40);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(44+36);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(44+36)+(36+32);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(44+40)-(40+32);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(44+40)-(40+32)-(32+28);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(44+36)+(36+32)+(32+24);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	
	ox=200+72*2+44*2; id=16+4;
	id-=4; X[id]=ox+id, Y[id]=oy; for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy-(16+12);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(16+8);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	id-=4; X[id]=ox+id, Y[id]=oy+(16+8)+(8+4);	for(i=1;i<=3;i++) rot(id-(i-1),id-i);
	*/
	
	for(x=0;x<5;x++) for(y=0;y<5;y++) {
		i=x*5+y+1;
		int ox=x*300;
		int oy=y*300;
		X[101-i]=ox+(101-i);
		Y[101-i]=oy+(101-i);
		X[50+i]=ox+300-(50+i);
		Y[50+i]=oy+300-(50+i);
		X[51-i]=ox+300-(51-i);
		Y[51-i]=oy+(51-i);
		X[i]=ox+i;
		Y[i]=oy+300-i;
	}

	for(i=1;i<=100;i++) for(j=i+1;j<=100;j++) {
		if(X[i]==0 || X[j]==0) continue;
		if((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])<(i*i+j*j)) _P("NG %d %d\n",i,j);
	}
	FOR(i,100) _P("%d %d\n",X[i+1],Y[i+1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
