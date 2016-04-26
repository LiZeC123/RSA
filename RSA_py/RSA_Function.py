BITWIDTH = 2
import os
from math import sqrt

def rsa(m,e,n):
    binary = []
    while e > 0:
        binary.append(e % 2)
        e = e // 2

    power = m % n
    x = 1
    for i in binary:
        if i == 1:
            x = (x * power) % n

        power = (power * power) % n

    return x

def create_primer_number():
    print("Create primer number list...\n")
    fp_primer_number=open("primer_number.txt","w")
    for i in range(5000,9999):
        if IsPrimerNumber(i):
            fp_primer_number.write(str(i) + '\n')

    fp_primer_number.close
    print("primer number done !\n")
        

def IsPrimerNumber(n):
    flag = True
    for i in range(2,int(sqrt(n))):
        if n % i == 0 :
            flag = False
            break

    return flag   

#将source中的字符转化为数字
def pre_treat():
    fp_source = open("source.txt","r")
    source = fp_source.read()
    #空格补足
    polish = len(source) % BITWIDTH
    if polish != 0:
        polish = BITWIDTH - polish
        for i in range(polish):
            source =source + ' '
    #编码
    bs_source = source.encode("utf-8")
    fp_worked = open("worked.txt","w")
    #按照位宽合并
    for i in range(0,len(bs_source),BITWIDTH):
        temp = 0
        for j in range(BITWIDTH):
            temp = temp + bs_source[i+j] * pow(10,3*(BITWIDTH-j-1))
        fp_worked.write(str(temp) + '\n')          
    fp_worked.close
    fp_source.close
    
def encrype(e,n):
    pre_treat()
    fp_worked = open("worked.txt","r")
    fp_result = open("result.txt","w")
    str_work = fp_worked.read()
    str_work = str_work[:-1] #去除最后一行的\n
    list_work = str_work.split("\n")
    
    for num in list_work:
        temp = rsa(int(num),e,n)
        fp_result.write(str(temp) + '\n')

    fp_worked.close
    fp_result.close

def decode(d,n):
    fp_result = open("result.txt","r")
    fp_source = open("source.txt","w")
    list_result = fp_result.read()
    list_result = list_result[:-1] #去除最后一行的\n
    list_result = list_result.split("\n")
    
    for num in list_result:
        #用私钥求出原文
        temp_num = rsa(int(num),d,n)
        #根据位宽拆分写入
        temp_list =[]
        for i in range(BITWIDTH):
            temp_list.append( temp_num // pow(10,3*(BITWIDTH - i - 1)))
            temp_num = temp_num % pow(10,3*(BITWIDTH - i - 1))
        for i in temp_list:
            fp_source.write(chr(i))
            
    fp_source.close
    fp_result.close
    

    
