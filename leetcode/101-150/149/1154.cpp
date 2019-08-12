
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

    int dayOfYear(string date) {
		int Y=0,M=0,D=0;
        Y+=(date[0]-'0')*1000;
        Y+=(date[1]-'0')*100;
        Y+=(date[2]-'0')*10;
        Y+=(date[3]-'0')*1;
        M+=(date[5]-'0')*10;
        M+=(date[6]-'0')*1;
        D+=(date[8]-'0')*10;
        D+=(date[9]-'0')*1;
        M--;
        
        int Ds[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(Y%400==0) Ds[1]++;
        else if(Y%100!=0 && Y%4==0) Ds[1]++;
        
        int i;
        FOR(i,M) D+=Ds[i];
        
        return D;
    }









};

