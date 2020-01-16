def change(str):
    rel = ""
    for i in range(1,len(str)-1):
        if(str[i]=='('): 
            rel += ')'
        else: rel += "("
    return rel

def balance(str):
    if(str[0]==')'): 
        return False
    left = 0
    for i,val in enumerate(str):
        if(val=="("): 
            left+=1
        else:
            left-=1            
            if(left<0): return False
    if(left == 0): return True

def findSlash(str):
    num =0
    for idx, value in enumerate(str):
        if value == ")":
            num -=1
        if value == "(":
            num +=1
        if num == 0:
            return idx
    
def solution(p):
    answer = ''
    if(len(p)==0):
        return p

    slash = findSlash(p)        
    u = p[:slash+1]
    v = p[slash+1:]
    if(balance(u)):
        return u + solution(v)
    else:
        v_=v
        u_=u
        answer += '(' + solution(v)
        v=v_
        u=u_
        answer += ')' + change(u)
        return answer 
    return answer
