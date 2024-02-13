table = {}
flag = 0
s = None
def create(b):
    for i in range(b):
        table[ i ] = None

def linear_prob(key, b):
    for i in range(0, b-1):
        hashl = (key + i) % b
        if table[ hashl ] == None:
            table[ hashl ] = key
            break
        elif table[hashl] == s:
            return hashl
        else:
            flag = 1

def quadratic_prob(key, b):
    for i in range(0, b-1):
        hashq = (key + (i * i)) % b
        if table[ hashq ] == None:
            table[ hashq ] = key
            break
        elif table[hashq] == s:
            return hashq
        else:
            flag = 1

def linsert(key, b):
    hash = key % b
    if table[ hash ] == None:
        table[ hash ] = key
    else:
        linear_prob(key, b)

def qinsert(key, b):
    hash = key % b
    if table[ hash ] == None:
        table[ hash ] = key
    else:
        quadratic_prob(key, b)

def lsearch(key,b):
    ind = linear_prob(key,b)
    if table[ind] != key or flag == 1:
        print(key,"is not present in table. ")
    else:
        print(key,"is present at ",ind)

def qsearch(key,b):
    ind = quadratic_prob(key,b)
    if table[ind] != key or flag == 1:
        print(key,"is not present in table. ")
    else:
        print(key,"is present at ",ind)

b = int(input("Enter the Size of table: "))
create(b)
while (1):
    ch = input("Enter probling mode[1 - LP | 2 - QP]: ")
    if ch == '1':
        for i in range(b+1):
            key = int(input("\nEnter key value: "))
            if i+1 > b:
                print("Table is full")
                break
            else:
                linsert(key, b)
            for i in range(b):
                print(table[ i ], end = "|")
            chc = input("\nDo u want ot exit[y|n]:")
            if chc == 'y':
                break
        ch1 = int(input('\nWant to search[0|1]:'))
        if ch1==1:
            s = int(input("Search value:"))
            lsearch(s,b)
            break
        else:
            break
    if ch == '2':
        for i in range(b):
            key = int(input("\nEnter key value: "))
            if i+1 > b:
                print("Table is full")
                break
            else:
                qinsert(key, b)
            for i in range(b):
                print(table[ i ], end = "|")
            chc = input("\nDo u want ot exit[y|n]:")
            if chc == 'y':
                break
        ch1 = int(input('\nWant to search[0|1]:'))
        if ch1==1:
            s = int(input("Search value:"))
            lsearch(s,b)
            break
        else:
            break
