#include<stdio.h>
#include<stdlib.h>

struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *head, *tail; // Khởi tạo Node
//Them nut moi voi gia tri x
struct Node* GetNewNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//Them phan tu vao dau danh sach
void InsertAtHead(int x)
{
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//Them phan tu vao cuoi danh sach
void InsertAtTail(int x)
{
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
//Xoa tại cuoi danh sach
void DeleteAtTail()
{
    if(head == NULL) {
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}
//Ham in danh sach
void NhapXuat()
{
    struct Node* temp = head;
    printf("\nDanh sach: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//hàm main
int main() {
    head = NULL; // dua head ve Null
    printf("In danh sach");
    NhapXuat();
    int option, data, location;
    while (1) {
        printf("\t\t=============MENU OF CHOICE===============\n");
        printf("\t\t|1. Them vao dau                         |\n");
        printf("\t\t|2. Them vao cuoi                        |\n");
        printf("\t\t|3. Xoa tai cuoi danh sach               |\n");
        printf("\t\t|4. Thoat                                |\n");
        printf("Moi Ban Chon: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Nhap du lieu: ");
            scanf("%d", &data);
            InsertAtHead(data);
            NhapXuat();
        } else if (option == 2) {
            printf("Nhap du lieu them vao cuoi: ");
            scanf("%d", &data);
            InsertAtTail(data);
            NhapXuat();
        } else if (option == 3) {
            printf("Thuc hien xoa di phan tu cuoi danh sach");
            DeleteAtTail();
            NhapXuat();
        } else if (option == 4) {
            break;
        }
    }
}
