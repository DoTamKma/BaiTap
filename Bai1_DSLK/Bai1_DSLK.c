#include<stdio.h>
#include<stdlib.h>

//khai bao danh sach
struct SoNguyen{
	int dulieu;
	struct SoNguyen *tiep;
};
typedef struct SoNguyen *node;//thay the kieu du lieu SoNguyen bang node
// cap phat bo nho
node ThemNut(int x)
{
    node tam; //khai bao 1 nut
    tam = (node)malloc(sizeof(struct SoNguyen));// cấp phát vùng nhớ
    tam->tiep = NULL;// con trỏ tiep trỏ tới giá trị null
    tam->dulieu = x; // gán giá trị cho node
    return tam;
}
// Thêm môt phần tử vào dánh sách liên kết
node ThemPhanTu(node head, int x)
{
    // them vào cuối danh sách
    node temp, p;
    temp = ThemNut(x);// gọi hàm themnut để khởi tạp temp
    if(head == NULL)
    {
        head =temp;
    }
    else
    {
        p= head;
        while(p->tiep !=NULL)
        {
            p = p->tiep;// duyệt danh sách đến cuối
        }
        p->tiep = temp; // Gán giá trị con tro cua phan tu cuoi bang temp

    }
    return head;
}
node XoaDau(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->tiep;
    }
    return head;
}
// Xóa phần tử tại ví trí bất kỳ
node XoaPhanTu(node head, int pos)
{
    if(pos == 0 || head == NULL){
    // Nếu vị trí chèn là 0, tức là thêm vào đầu
        head= XoaDau(head);
    }
    else{
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        node p = head;
        while(p->tiep->tiep != NULL && k != pos){
            p = p->tiep;
            ++k;
        }

        if(k != pos){
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định xóa cuối
            // Nếu bạn không muốn xóa, hãy thông báo vị trí xóa không hợp lệ
            printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->tiep = p->tiep->tiep;
        }
    }
    return head;
}
//sua gia tri phan tu
node SuaPhanTu(node head)
{
   int x, y;
   printf("Moi nhap gia tri muon sua: \n");
   scanf("%d",&x);
   node p= head;
   if(head ==NULL) return 0;
   while(p!=NULL)
   {
       if(p->dulieu == x)
       {
           printf("Moi nhap du lieu thay the: \n");
           scanf("%d",&y);
           p->dulieu = y;
           return head;
       }
   }
   return 0;
}

// Nhap danh sach liên kết
node Nhap(){
    node head;
    head = NULL;
    int n, x;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);

    for(int i = 0; i < n; ++i){
        printf("\nNhap vao gia tri: ");
        scanf("%d", &x);
        node temp,p;// Khai báo 2 node tạm temp và p
        temp = ThemNut(x);//Gọi hàm createNode để khởi tạo node temp có next trỏ tới NULL và giá trị là value
        if(head == NULL){
            head = temp;     //Nếu linked list đang trống thì Node temp là head luôn
        }
        else{
            p  = head;// Khởi tạo p trỏ tới head
            while(p->tiep != NULL){
                p = p->tiep;//Duyệt danh sách liên kết đến cuối. Node cuối là node có next = NULL
            }
            p->tiep = temp;//Gán next của thằng cuối = temp. Khi đó temp sẽ là thằng cuối(temp->next = NULL mà)
        }
    }
    return head;
}
//in danh sach
void In(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->tiep){
        printf("%d", p->dulieu);
    }
}

//Hàm lấy số phần tử của dánh sách liên kết
int LaySoPhanTu(node head){
    int size = 0;
    for(node p = head; p != NULL; p = p->tiep){
        size++;
    }
    printf("So luong phan tu la: %d",size);
    return size;
}
int main()
{
    node head;
    int x, y, pos;
    int chon=0;
    do
    {
        printf("\n");
        printf("\t\t\t =======================Moi_Lua_Chon===============\n");
        printf("\t\t\t |1. Nhap danh sach                               |\n");
        printf("\t\t\t |2. Them phan tu vao danh sach lien ket          |\n");
        printf("\t\t\t |3. Sua phan tu trong danh sach lien ket         |\n");
        printf("\t\t\t |4. Xoa phan tu trong danh sach lien ket         |\n");
        printf("\t\t\t |5. Lay so luong phan tu trong danh sach         |\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                head=Nhap();
                In(head);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d",&x);
                head=ThemPhanTu(head,x);
                In(head);
                break;
            case 3:
                head= SuaPhanTu(head);
                In(head);
                break;
            case 4:
                //printf("Nhap vi tri muon xoa: \n");
                //scanf("%d",pos);
                head= XoaPhanTu(head, pos);
                In(head);
                break;
            case 5:
                head= LaySoPhanTu(head);
                break;
            case 6:
                break;
            default:
                printf("Khong co lua chon!\n");
                break;

        }
    }while(chon!=6);
    return 0;
}
