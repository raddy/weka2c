import re,sys,os
from collections import defaultdict

if len(sys.argv)<2:
	sys.exit('Usage: %s weka-text-tree-source' % sys.argv[0])
	
if not os.path.exists(sys.argv[1]):
    sys.exit('ERROR: File %s was not found!(nub)' % sys.argv[1])
 
logfile = open(sys.argv[1], "r").readlines()   
rownum=1
lastdepths = defaultdict()
vartypes = defaultdict()
prevdepth=-1;
braces=0
conditionals=""
returntype=""
indent_style="  "
base = indent_style #yeah, some people might have this be different...
for line in logfile:
    depth=(line.count("|"))
    i=depth
    indent = ""
    j=0
    while (j<depth):
    	indent+=indent_style
    	j+=1
    prefix=""
    ndeps = defaultdict()
    for dep in sorted(lastdepths.iterkeys(),reverse=True):
    	if (depth<dep):
    		affix = base+(dep)*indent_style
    		conditionals+=affix+"}\n"
    	else:
    		ndeps[dep] = lastdepths[dep]
    lastdepths = ndeps
    if (depth in lastdepths):
    	full=base+indent+"}\n"+base+indent+"else{\n"
    	conditionals+=(prefix+full)
    	lastdepths[depth] = rownum
    else:
    	varname=((re.search(r'\w+',line)).group())
    	oper=((re.search(r'[<=>]+',line)).group())
    	postop = (line[(line.find(oper)):len(line)])
    	num=((re.search(r'[\d.\w-]+',postop)).group())
    	stringtype = re.search(r'[a-zA-Z]',num)
    	if stringtype:
    		vartypes[varname] = "string"
    	else:
    		signloc = num.find("-")
    		if (signloc>0):
    			vartypes[varname] = "string"
    		else:
    			vartypes[varname] = "double"
    	full="if ("+varname+" "+oper+" "+num+"){\n"
    	lastdepths[depth]=rownum
    	conditionals+=base+(indent+prefix+full)
    	braces+=1
    res=""
    if (line.count(":")>0):
    	remainder = (line[(line.find(":")):len(line)])
    	res = ((re.search(r'[\d\w.-]+',remainder)).group())
    	ret = re.search(r'[a-zA-Z]',res)
    	if ret or returntype=="string":
    		conditionals+=base+indent + indent_style+"return \"" + res +"\";\n"
    		returntype="string"
    	else:
    		conditionals+=base+indent + indent_style+"return "  + res +";\n"
    		signloc = res.rfind("-")
    		if (signloc>0):
    			returntype="string"
    		else:
	    		if (returntype!="string"):
    				returntype="double"
    prevdepth=depth
    rownum+=1
i=0
while (i <= prevdepth):
    	indent_size = (prevdepth-i)*indent_style
    	conditionals+=base+indent_size+"}\n"
    	i+=1
    	braces-=1

output="#include <iostream>\n\nusing namespace std;\n\n"
output+=returntype+" classify("
numvars = (len(vartypes.items()))
i=1
for name in vartypes:
	output+=vartypes[name]+" "
	if (i<numvars):
		output+=name+", "
	else:
		output+=name+"){\n\n"
	i+=1
output+=conditionals+"\n}"

outname=sys.argv[1]+".cpp"
outfile=open(outname,"w")
outfile.write(output)
print(output)

