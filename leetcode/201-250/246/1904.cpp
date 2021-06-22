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
    int numberOfRounds(string startTime, string finishTime) {
        int S=((startTime[0]-'0')*10+(startTime[1]-'0'))*60+((startTime[3]-'0')*10+(startTime[4]-'0'));
        int T=((finishTime[0]-'0')*10+(finishTime[1]-'0'))*60+((finishTime[3]-'0')*10+(finishTime[4]-'0'));
        
        if(T<S) T+=24*60;
        int ret=0;
        while(S<T) {
			if(S%15==0&&S+15<=T) ret++;
			S++;
		}
        return ret;
    }
};
