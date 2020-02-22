import sys
import re

print(len(re.findall(' (TAKAHASHIKUN|[Tt]akahashikun)(?=[ \.])',raw_input()+" "+raw_input())))
