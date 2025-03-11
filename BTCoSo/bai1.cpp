#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


void docFile(const char *tenTep, int a[], int *n) {
    FILE *file = fopen(tenTep, "r");
    if (!file) {
        printf("Không thể mở file %s\n", tenTep);
        exit(1);
    }
    *n = 0;
    while (fscanf(file, "%d", &a[*n]) == 1) (*n)++;
    fclose(file);
}

void ghiFile(const char *tenTep, const char *tenThuatToan, int a[], int n) {
    FILE *file = fopen(tenTep, "w");
    if (!file) {
        printf("Không thể mở file %s\n", tenTep);
        exit(1);
    }
    fprintf(file, "%s:\n", tenThuatToan);
    for (int i = 0; i < n; i++) fprintf(file, "%d ", a[i]);
    fprintf(file, "\n");
    fclose(file);
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        bool cont = true;
        while ((j >= 0) && cont) {
            if (a[j] > x) {
                a[j + 1] = a[j];
                j--;
            } else {
                cont = false;
            }
        }
        a[j + 1] = x;
    }
}

void Interchange(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void BubbleSort(int a[], int n) {
    int i, j;
    for (i = n - 1; i >= 1; i--) {  
        for (j = 0; j <= i - 1; j++) {  
            if (a[j] > a[j + 1]) {  
                swap(a[j], a[j + 1]);  
            }
        }
    }
}
void Selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        
        int minval = a[i];
        int kmin = i;
        for (int j = i + 1; j < n; j++) {
            if (minval > a[j]) {
                minval = a[j];
                kmin = j;
            }
        }
        
        swap(a[i], a[kmin]);
    }
}

int main() {
    const char *input = "input.txt";
    const char *output = "output.txt";

    int a[MAX_SIZE], n;
    docFile(input, a, &n);      
    Insertion(a, n);            
    ghiFile(output, "sap xep chen", a, n);  
    Interchange(a,n);
    ghiFile(output,"sap xep doi cho truc tiep",a,n);
    BubbleSort(a,n);
    ghiFile(output,"sap xep noi bot",a,n);
    Selection(a,n);
    ghiFile(output,"sap xep chon",a,n);

    return 0;
}
