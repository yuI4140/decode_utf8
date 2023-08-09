import os,sys
argc=len(sys.argv)-1
argv=sys.argv
isFlag=False
shared_lib="gcc -fPIC -shared -o ./lib/decode_utf8.so ./src/decode_utf8.c ./src/ConvertUTF.c" 
if argc==0:
    print("set -h flag for help") 
    exit()
if argv[1]=="-h":
    isFlag=True
    print("-sh : compile and return a *.so")
    print("-shl  : set a logger while it's compiling")
if argv[1]=="-sh":
    isFlag=True
    os.system(shared_lib) 
elif argv[1]=="-shl": 
    isFlag=True
    print(shared_lib) 
    os.system(shared_lib) 
if isFlag!=True:
    print("flag doesn't exits")
