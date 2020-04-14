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
    string entityParser(string text) {
		string R;
		int i;
		FOR(i,text.size()) {
			if(text[i]!='&') {
				R.push_back(text[i]);
			}
			else {
				if(i+6<=text.size()&&text.substr(i,6)=="&quot;") R+='"',i+=5;
				else if(i+6<=text.size()&&text.substr(i,6)=="&apos;") R+="'",i+=5;
				else if(i+5<=text.size()&&text.substr(i,5)=="&amp;") R+="&",i+=4;
				else if(i+4<=text.size()&&text.substr(i,4)=="&gt;") R+=">",i+=3;
				else if(i+4<=text.size()&&text.substr(i,4)=="&lt;") R+="<",i+=3;
				else if(i+7<=text.size()&&text.substr(i,7)=="&frasl;") R+="/",i+=6;
				else R.push_back(text[i]);
			}
		}
        return R;
    }
};


