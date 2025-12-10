FUNCTION SSTF(requests, n, head):
    visited[n] = {0}
    current = head
    total = 0
    count = 0
    WHILE count < n:
        min = INF
        index = -1
        FOR i=0 to n-1:
            IF !visited[i]:
                diff = ABS(requests[i] - current)
                IF diff < min:
                    min = diff
                    index = i
        visited[index] = 1
        total += min
        current = requests[index]
        PRINT "->", current
        count++
    PRINT total, average, throughput
