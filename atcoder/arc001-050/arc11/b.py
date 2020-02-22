import sys
import re

m={"b":"1","c":"1","d":"2","w":"2","t":"3","j":"3","f":"4",
"q":"4","l":"5","v":"5","s":"6","x":"6","p":"7","m":"7",
"h":"8","k":"8","n":"9","g":"9","z":"0","r":"0"," ":" "}

N=input()
W=list(raw_input())
s=""
for w in W:
	s += m.get(w.lower(),"")
print(re.sub(" +"," ",s).strip())
