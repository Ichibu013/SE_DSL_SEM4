table = {}


def create(b):
    for i in range(b):
        table[ i ] = None


def linear_prob(key, b):
    for i in range(0, b):
        hashl = (key + i) % 10
        if table[ hashl ] == None:
            table[ hashl ] = key
            break
    return hashl


def quadratic_prob(key, b):
    for i in range(0, b):
        hashq = (key + (i * i)) % 10
        if table[ hashq ] == None:
            table[ hashq ] = key
            break
    return hashq


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


b = int(input("Enter the Size of table: "))
create(b)
while (1):
    ch = input("Enter probling mode[1 - LP | 2 - QP]: ")
    if ch == '1':
        for i in range(b):
            key = int(input("\nEnter key value: "))
            linsert(key, b)
            for i in range(b):
                print(table[ i ], end = "|")
    if ch == '2':
        for i in range(b):
            key = int(input("\nEnter key value: "))
            qinsert(key, b)
            for i in range(b):
                print(table[ i ], end = "|")