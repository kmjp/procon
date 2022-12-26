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

void solve() {
	int i,j,k,l,r,x,y; string s;
	cout<<"12 62 3 38 35 59 1 13"<<endl;
	cout<<"46 47 14 61 11 4 43 2"<<endl;
	cout<<"53 30 9 10 42 26 27 15"<<endl;
	cout<<"18 54 17 44 49 28 32 19"<<endl;
	cout<<"36 21 33 22 7 8 50 40"<<endl;
	cout<<"34 41 25 52 60 63 20 29"<<endl;
	cout<<"45 56 57 31 58 23 6 39"<<endl;
	cout<<"51 48 55 16 64 24 5 37"<<endl;
}

/*
from PIL import Image,ImageDraw

for i in range(64):
	f = "pieces/p_%d.png" % (i+1)
	img = Image.open(f).convert("RGB")
	draw=ImageDraw.Draw(img)
	draw.text((16,16),"%d" % (i+1), fill=(127,0,255))
	draw.text((8,8),"%d" % (i+1), fill=(255,0,127))
	img.save("a_%d.png" % (i+1))
*/

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
