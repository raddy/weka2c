import re,sys,os
from collections import defaultdict

if len(sys.argv)<2:
	sys.exit('Usage: %s weka-text-tree-source' % sys.argv[0])
	
if not os.path.exists(sys.argv[1]):
    sys.exit('ERROR: File %s was not found!(nub)' % sys.argv[1])
 
logfile = open(sys.argv[1], "r").readlines()   
rownum=1
lastdepths = defaultdict() #GLOBAL VAR USED AS SUCH
vartypes = defaultdict() #GLOBAL VAR USED AS SUCH
prevdepth=-1;
braces=0                #GLOBAL VAR USED AS SUCH
conditionals=""
returntype=""           #GLOBAL VAR USED AS SUCH
indent_style="  "
base = indent_style #yeah, some people might have this be different...

def header():
    return "#include <iostream>\n\nusing namespace std;\n\n"

def functionCall(funcname,vartypes):
    fc = " "+ funcname + "("
    numvars = (len(vartypes.items()))
    i=1
    for name in vartypes:
        fc+=vartypes[name]+" "
        if (i<numvars):
            fc+=name+", "
        else:
            fc+=name+"){\n\n"
        i+=1
    return fc

def getResult(line):
    global returntype
    res=""
    if (line.count(":")>0):
        remainder = (line[(line.find(":")):len(line)])
        res = ((re.search(r'[\d\w.-]+',remainder)).group())
        ret = re.search(r'[a-zA-Z]',res)
        if ret or returntype=="string":
            returntype="string"
            return base+indent + indent_style+"return \"" + res +"\";\n"
        else:
            signloc = res.rfind("-")
            if (signloc>0):
                returntype="string"
            else:
                if (returntype!="string"):
                    returntype="double"
            return base+indent + indent_style+"return "  + res +";\n"

def eofBraces(braces,prevdepth): #not so sure about this, n2b tested
    i=0
    eof=""
    while (braces>0):
        indent_size = (prevdepth-i)*indent_style
        eof+=base+indent_size+"}\n"
        i+=1
        braces-=1
    return eof

def closingBraces():
    global lastdepths
    global braces
    ndeps = defaultdict() #temp dictionary for modification
    cbraces=""
    for dep in sorted(lastdepths.iterkeys(),reverse=True):
        if (depth<dep):
            affix = base+(dep)*indent_style
            cbraces+=affix+"}\n"
            braces-=1
        else:
            ndeps[dep] = lastdepths[dep]
    lastdepths = ndeps
    return cbraces

def checkType(num):
    stringtype = re.search(r'[a-zA-Z]',num)
    if stringtype:
        return "string"
    else:
        signloc = num.find("-")
        if (signloc>0):
            return "string"
        else:
            return "double"

def buildLine(line):
    global vartypes
    varname=((re.search(r'[-_\w]+',line)).group())
    oper=((re.search(r'[<=>]+',line)).group())
    postop = (line[(line.find(oper)):len(line)])
    num=((re.search(r'[\d.\w-]+',postop)).group())
    vartypes[varname] = checkType(num)
    if vartypes[varname] == "string":
        num="\""+num+"\""
    if oper=="=":
        oper="=="
    full="if ("+varname+" "+oper+" "+num+"){\n"
    return full;

def indentSize(depth):
    return indent_style*depth


## "MAIN"

for line in logfile:
    depth=(line.count("|"))
    indent=indentSize(depth)
    prefix=""
    conditionals+=closingBraces()
    if (depth in lastdepths):
    	full=base+indent+"}\n"+base+indent+"else"
    	conditionals+=(prefix+full)
    else:
    	braces+=1
        conditionals+=base+indent
    res=""
    lastdepths[depth]=rownum
    conditionals+=buildLine(line)
    result = getResult(line)
    if result:
        conditionals+=result
    prevdepth=depth
    rownum+=1
conditionals+=eofBraces(braces,prevdepth)
#file header bs
output=header()
output+=returntype+ functionCall("classify",vartypes)
output+=conditionals+"\n}"

outname=sys.argv[1]+".cpp"
outfile=open(outname,"w")
outfile.write(output)
print(output)

