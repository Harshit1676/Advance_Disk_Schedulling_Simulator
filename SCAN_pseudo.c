FUNCTION SCAN(requests, n, head, size, direction):
    sort requests
    IF direction == right:
        service right side
        go to disk end
        service left side
    ELSE:
        service left side
        go to 0
        service right side
        