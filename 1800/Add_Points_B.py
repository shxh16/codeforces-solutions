import sys
from collections import Counter
import math
input = sys.stdin.readline
def gcd_array(a):
    gcd = 0
    for i in a:
        gcd = math.gcd(gcd,i)
        if(gcd == 1):
            return 1
    return gcd
n = int(input())
a = list(map(int,input().split()))
a.sort()
n_diff = [a[1] - a[0]]
min_occur_diff = a[1] - a[0]
for i in range(1,n - 1):
    min_occur_diff = min(min_occur_diff,a[i+1] - a[i])
    n_diff.append(a[i+1] - a[i])
counter_diff = Counter(n_diff)
most_repeating_diff = 0
for i in counter_diff:
    most_repeating_diff = max(most_repeating_diff,counter_diff[i])
if(most_repeating_diff == (n-1)):
    print(0)
else:
    gcd = gcd_array(n_diff)
    i = 1
    count = 0
    for i in range(n-1):
        count += ((a[i+1] - a[i])//gcd) - 1
    print(count)
