from RSA_Function import *

def welcome():
    print("############################################")
    print("Welcome to use Public Key Encryption")
    print("Enter the letter correspnoding to your choice:")
    print("e)encrype   d)decode ")
    print("g)get keys  q)quit   ")
    choose = input()
    choose =choose[0:1]
    return choose

def main():
    choose = welcome()

    if choose is 'e':
        pub_key = input("Please input Public Key:")
        pub_key = pub_key.split(' ')
        print("Now the file source.txt will be encryped...")
        encrype(int(pub_key[0]),int(pub_key[1]))
        print("source.txt has been enctyped successful!")
    elif choose is 'd':
        pri_key = input("Please input Private Key:")
        pri_key = pri_key.split(' ')
        print("Now the file result.txt will be decoded...")
        encrype(int(pri_key[0]),int(pri_key[1]))
        print("result.txt has been decoded successful!")

        
        
main()
