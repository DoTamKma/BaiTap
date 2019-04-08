#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

typedef struct Node NODE;

NODE * CreateNewNode(int data) {
    NODE * newNode = (NODE *) malloc (sizeof(NODE));
    newNode -> data = data;
    return newNode;
}

void Display(NODE * tail) {
    NODE * current = tail;
    if (tail != NULL) {
        do {
            current = current -> next;
            printf(" %d\t ", current -> data);
        } while (current != tail);
    }
}

int Length(NODE * tail) {
    NODE * current = tail;
    int i = 1;
    if (tail == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != tail) {
            i++;
            current = current -> next;
        }
    }
    return i;
}

NODE * InsertAtHead(NODE * tail, int data) {
    NODE * newNode = CreateNewNode(data);
    if (tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = tail -> next;
        tail -> next = newNode;
    }
    return tail;
}

NODE * InsertAtEnd(NODE * tail, int data) {
    return InsertAtHead(tail, data) -> next;
}

NODE * Delete(NODE * tail, int location) {
    NODE * current, * previous = tail;
    int len = Length(tail), i;
    if (location < 1 || location > len) {
        printf("Vi tri khong hop le!!");
    } else if (len == 1) {
        tail = NULL;
        free(current);
    } else {
        current = tail -> next;
        for (i = 1; i < location; i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        if (current == tail) tail = previous;
        free(current);
    }

    return tail;
}

int main() {
    NODE * cll = NULL;
    int option, data, location;
    while (1) {
        Display(cll);
        printf("\nDo dai = %d\n", Length(cll));
        printf("\t\t=============MENU OF CHOICE===============\n");
        printf("\t\t|1. Them vao dau                         |\n");
        printf("\t\t|2. Them vao cuoi                        |\n");
        printf("\t\t|3. Xoa dua theo vi tri                  |\n");
        printf("\t\t|4. Thoat                                |\n");
        printf("Moi Ban Chon: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Nhap du lieu: ");
            scanf("%d", &data);
            cll = InsertAtHead(cll, data);
        } else if (option == 2) {
            printf("Nhap du lieu them vao cuoi: ");
            scanf("%d", &data);
            cll = InsertAtEnd(cll, data);
        } else if (option == 3) {
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &location);
            cll = Delete(cll, location);
        } else if (option == 4) {
            break;
        }
    }
    return 0;
}
