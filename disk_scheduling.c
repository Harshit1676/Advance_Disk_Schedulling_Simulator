#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void fcfs(int req[], int n, int head);
void sstf(int req[], int n, int head);
void scan(int req[], int n, int head, int size, int dir);
void cscan(int req[], int n, int head, int size, int dir);
void sort(int arr[], int n);

int main() {
    int size, n, head, dir;
    int req[MAX];

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0=left,1=right): ");
    scanf("%d", &dir);

    fcfs(req, n, head);
    sstf(req, n, head);
    scan(req, n, head, size, dir);
    cscan(req, n, head, size, dir);

    return 0;
}

void fcfs(int req[], int n, int head) {
    int total = 0, current = head;
    printf("\nFCFS Head Path: %d", current);

    for (int i = 0; i < n; i++) {
        int diff = abs(req[i] - current);
        total += diff;
        current = req[i];
        printf(" -> %d", current);
    }

    printf("\nTotal Movement: %d", total);
    printf("\nAverage Seek Time: %.2f", (float)total/n);
    printf("\nThroughput: %.4f\n", (float)n/total);
}

void sstf(int req[], int n, int head) {
    int visited[MAX] = {0};
    int total = 0, completed = 0, current = head;

    printf("\nSSTF Head Path: %d", current);

    while (completed < n) {
        int min = 999999, index = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int diff = abs(req[i] - current);
                if (diff < min) {
                    min = diff;
                    index = i;
                }
            }
        }
        visited[index] = 1;
        total += abs(req[index] - current);
        current = req[index];
        printf(" -> %d", current);
        completed++;
    }

    printf("\nTotal Movement: %d", total);
    printf("\nAverage Seek Time: %.2f", (float)total/n);
    printf("\nThroughput: %.4f\n", (float)n/total);
}

void sort(int arr[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
}

void scan(int req[], int n, int head, int size, int dir) {
    int arr[MAX], i, j, total=0, current=head;

    for (i=0;i<n;i++) arr[i]=req[i];
    sort(arr,n);

    printf("\nSCAN Head Path: %d", current);

    if (dir == 1) { // right
        int idx=0;
        while (idx<n && arr[idx]<head) idx++;

        for (j=idx;j<n;j++){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }

        if (current != size-1) {
            total += abs((size-1)-current);
            current = size-1;
            printf(" -> %d", current);
        }

        for (j=idx-1;j>=0;j--){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }

    } else {
        int idx = n-1;
        while (idx>=0 && arr[idx]>head) idx--;

        for (j=idx;j>=0;j--){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }

        if (current != 0) {
            total += abs(current-0);
            current = 0;
            printf(" -> %d", current);
        }

        for (j=idx+1;j<n;j++){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Movement: %d", total);
    printf("\nAverage Seek Time: %.2f", (float)total/n);
    printf("\nThroughput: %.4f\n", (float)n/total);
}

void cscan(int req[], int n, int head, int size, int dir) {
    int arr[MAX], total=0, current=head;

    for (int i=0;i<n;i++) arr[i]=req[i];
    sort(arr,n);

    printf("\nC-SCAN Head Path: %d", current);

    if (dir == 1) {
        int idx=0;
        while (idx<n && arr[idx]<head) idx++;

        for (int j=idx;j<n;j++){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }

        total += abs((size-1)-current);
        current = size-1;
        printf(" -> %d", current);

        total += (size-1);
        current = 0;
        printf(" -> %d", current);

        for (int j=0;j<idx;j++){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }

    } else {
        int idx = n-1;
        while (idx>=0 && arr[idx]>head) idx--;

        for (int j=idx;j>=0;j--){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }

        total += abs(current-0);
        current = 0;
        printf(" -> %d", current);

        total += (size-1);
        current = size-1;
        printf(" -> %d", current);

        for (int j=n-1;j>idx;j--){
            total += abs(arr[j]-current);
            current = arr[j];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Movement: %d", total);
    printf("\nAverage Seek Time: %.2f", (float)total/n);
    printf("\nThroughput: %.4f\n", (float)n/total);
}
