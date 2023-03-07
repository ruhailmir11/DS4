'''
    Title: Bankers algorithm
    Author: Ruhail Mir
    Github: https://www.github.com/ruhailmir
    Instagram: https://www.instagram.com/ruhailmir
'''

import numpy as np

# "Process" vector size.
n = 5
work = np.array([3, 3, 2])

# processes conf ...
# Allocated Resources.
alloc = np.array([
        [0, 1, 0],
        [2, 0, 0],
        [3, 0, 2],
        [2, 1, 1],
        [0, 0, 2]
    ])

# Max allocations.
mmax = np.array([
        [7, 5, 3],
        [3, 2, 2],
        [9, 0, 2],
        [2, 2, 2],
        [4, 3, 3]
    ])

# Available Resources.
avail = np.array([3, 3, 2])

# generate the need matrix.
need = mmax - alloc

# helper function.
def is_less(need, work):
    return not False in (need <= work)

# main algorithm.
def determine_safe_sequence():
    global work, alloc, avail, need
    finish = np.array([False for _ in range(n)])

    safe = False
    safe_sequence = []
    max_check_limit = 1000
    counter = 0

    while not safe:
        if counter >= max_check_limit:
            print('Safe limit crossed, no possible solution')
            break

        for i in range(n):
            print('EOPCH: ', i)
            need_ = need[i]

            if finish[i] == False and is_less(need_, work):
                safe_sequence.append(i)
                work = work + alloc[i]
                finish[i] = True

            else:
                state = not False in finish

                if state == True:
                    print('System is in safe state.')
                    safe = True
                    break

        counter += 1

    if counter != max_check_limit:
        print('SAFE SEQUENCE: ', safe_sequence, end='\n\n')

def request_additional_resource(req, pr):
    global work, alloc, avail, need
    req = np.array(req)

    if is_less(req, need[pr]) and is_less(req, avail[pr]):
        print('Request by process:', pr, 'For', req, 'is granted.')
        avail = avail - req
        alloc[pr] = alloc[pr] + req
        need[pr] = need[pr] - req
        work = avail.copy()

        print('Determining safe state now ...')
        print()        
        determine_safe_sequence()


if __name__ == "__main__":
    determine_safe_sequence()
    request_additional_resource([1, 0, 2], 1)

# END