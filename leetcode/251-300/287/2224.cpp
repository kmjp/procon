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
    int convertTime(string current, string correct) {
		int A=(current[0]-'0')*600+(current[1]-'0')*60+(current[3]-'0')*10+(current[4]-'0');
		int B=(correct[0]-'0')*600+(correct[1]-'0')*60+(correct[3]-'0')*10+(correct[4]-'0');
		B-=A;
		int ret=0;
		ret+=B/60;
		B%=60;
		ret+=B/15;
		B%=15;
		ret+=B/5;
		B%=5;
        ret+=B;
        return ret;
    }
};
