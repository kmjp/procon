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


class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int from[6]={};
        int ret=0;
        int i;
        FOR(i,6) from[i]=-(1<<20);
        FORR(c,word) {
			if(c=='a') {
				from[0]=max(1,from[0]+1);
				FOR(i,6) if(i!=0) from[i]=-(1<<20);
			}
			else if(c=='e') {
				from[1]=max(from[0]+1,from[1]+1);
				FOR(i,6) if(i!=1) from[i]=-(1<<20);
			}
			else if(c=='i') {
				from[2]=max(from[2]+1,from[1]+1);
				FOR(i,6) if(i!=2) from[i]=-(1<<20);
			}
			else if(c=='o') {
				from[3]=max(from[2]+1,from[3]+1);
				FOR(i,6) if(i!=3) from[i]=-(1<<20);
			}
			else if(c=='u') {
				from[4]=max(from[3]+1,from[4]+1);
				FOR(i,6) if(i!=4) from[i]=-(1<<20);
			}
			else {
				FOR(i,6) from[i]=0;
			}
			ret=max(ret,from[4]);
		}
		return ret;
    }
};
