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

/*
paste 13.txt	1.txt	59.txt	35.txt	38.txt	3.txt	62.txt	12.txt  >> b
paste 2.txt	43.txt	4.txt	11.txt	61.txt	14.txt	47.txt	46.txt  >> b
paste 15.txt	27.txt	26.txt	42.txt	10.txt	9.txt	30.txt	53.txt  >> b
paste 19.txt	32.txt	28.txt	49.txt	44.txt	17.txt	54.txt	18.txt  >> b
paste 40.txt	50.txt	8.txt	7.txt	22.txt	33.txt	21.txt	36.txt  >> b
paste 29.txt	20.txt	63.txt	60.txt	52.txt	25.txt	41.txt	34.txt  >> b
paste 39.txt	6.txt	23.txt	58.txt	31.txt	57.txt	56.txt	45.txt  >> b
paste 37.txt	5.txt	24.txt	64.txt	16.txt	55.txt	48.txt	51.txt  >> b
*/

void solve() {
	int i,j,k,l,r,x,y; string s;
	cout<<".....input...."<<endl;
	cout<<"....f...n....."<<endl;
	cout<<"....l...b....."<<endl;
	cout<<"snowy..path..."<<endl;
	cout<<"....i...l....."<<endl;
	cout<<"...snowman..d."<<endl;
	cout<<"....g...n.o.o."<<endl;
	cout<<".....c..c.u.m."<<endl;
	cout<<"x..shortest.a."<<endl;
	cout<<"m....n..d.p.i."<<endl;
	cout<<"accepted.bunny"<<endl;
	cout<<"s....e....t..."<<endl;
	cout<<".....s........"<<endl;
	cout<<"...integral..."<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
