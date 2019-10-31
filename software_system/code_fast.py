def fast_code(F_p,S_p):
    div_m = (1-F_p) + (F_p/S_p)
    S = 1 / div_m
    return S


#S_p // spped upが達成される。
#F_p //　並列可能なコードの割合

F_p = 0.999
S_p = [2,4,8]
for i in S_p:
    print(fast_code(F_p,i))
print("################")
F_p = 0.01
S_p = [10,100,1000]
for i in S_p:
    print(fast_code(F_p,i))
