x1,y1,x2,y2,x3,y3,x4,y4 = map(int,input().split())
print(1 if ((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))*((x2-x1)*(y4-y1)-(y2-y1)*(x4-x1))<0 else 0)