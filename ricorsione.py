def recursione (n):
    n=n-1
    if n==1:
        print(f" sei uscito {n}")
        return 0
    else:
        print(f" sei entrato nel l else {n}")
        num=recursione(n)

def  controllo(n):
    if n<1:
        print(f" non puoi mettere un numero minore di 1 come {n}")
        n=int(input(" che numero vuoi inserire? "))
        num=controllo(n)
        return num
    else:
        print(f" il numero {n} va bene")
        return n
n=int(input(" che numero vuoi inserire? "))
num=controllo(n)
recursione(num)
