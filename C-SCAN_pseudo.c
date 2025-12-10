FUNCTION C_SCAN(requests, n, head, size, direction):
    sort requests
    IF direction == right:
        service right side
        go to end
        jump to 0
        service left side
    ELSE:
        service left side
        go to 0
        jump to end
        service right side
