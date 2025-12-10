FUNCTION FCFS(requests, n, head):
    current = head
    total = 0
    PRINT current
    FOR i = 0 to n-1:
        move = ABS(requests[i] - current)
        total += move
        current = requests[i]
        PRINT "->", current
    average = total / n
    throughput = n / total
    PRINT results
