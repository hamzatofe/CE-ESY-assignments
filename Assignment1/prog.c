#include <stdio.h>
#include <string.h>

#define SIZE 5   // حجم المخزن

char buffer[SIZE];
int start = 0;
int end = -1;
int count = 0;

// التحقق من الامتلاء
int isFull() {
    return count == SIZE;
}

// التحقق من الفراغ
int isEmpty() {
    return count == 0;
}

// إضافة حرف
void enqueue(char value) {
    if (isFull()) {
        printf("Overflow: Buffer is full!\n");
        return;
    }

    end = (end + 1) % SIZE;
    buffer[end] = value;
    count++;
}

// حذف حرف
char dequeue() {
    if (isEmpty()) {
        printf("Underflow: Buffer is empty!\n");
        return '\0';
    }

    char value = buffer[start];
    start = (start + 1) % SIZE;
    count--;
    return value;
}

// التابع الرئيسي
int main() {
    char name[50];

    // ادخال الاسم
    printf("Enter your name: ");
    scanf("%s", name);

    int len = strlen(name);

    // ادخال كل حرف 
    for (int i = 0; i < len; i++) {
        enqueue(name[i]);
    }

    //CE-ESY عرض الناتج + إضافة
    printf("Result: ");
    while (!isEmpty()) {
        printf("%c", dequeue());
    }
    printf("_CE-ESY\n");

    // التأكد أن المخزن فارغ
    if (isEmpty()) {
        printf("Buffer is now empty.\n");
    }

    return 0;
}
