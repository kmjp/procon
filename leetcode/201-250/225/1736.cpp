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
    string maximumTime(string time) {
        if(time[3]=='?') time[3]='5';
        if(time[4]=='?') time[4]='9';
        if(time[0]=='?') {
			if(time[1]>='4'&&time[1]<='9') time[0]='1';
			else time[0]='2';
		}
        if(time[1]=='?') {
			if(time[0]=='2') time[1]='3';
			else time[1]='9';
		}
		return time;
    }
};

