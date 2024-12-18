#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next=NULL;
	return newNode;
}

void insertHead(Node** head,int value){
	Node* newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;
}

void insertLast(Node** head, int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	free(temp);
}

void insertAtPosition(Node** head, int position, int value){
	Node* newNode = createNode(value);
	if(position == 0){
		insertHead(head,value);
	}
	
	Node* temp = *head;
	int index = 0;
	while(temp != NULL && index < position - 1){
	 	temp = temp->next;
    	index++;
	}
	if (temp == NULL) {
        printf("Vi tri nam ngoai pham vi danh sach.\n");
        printf("Them phan tu that bai");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\nDa them vao vi tri %d\n",position);
	free(temp);
}

void deleteHead(Node** head){
	Node* temp = *head;
	if (temp == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
	*head = temp->next;  
    return;
	
}

void deleteLast(Node** head){

    Node* temp = *head;
	if (temp == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
	Node* prev = NULL;
	while (temp->next != NULL) {
    	prev = temp;
    	temp = temp->next;
	}
 	prev->next = NULL;
 	free(temp);
}

void deleteElement(Node** head,int num){
	Node* temp = *head;
	int index = 0;
	Node* prev = NULL;
	while(temp->data !=  num){
	  	prev = temp;  
        temp = temp->next;  
        index++;
	
	}
	prev->next = temp->next;
	free(temp);
}

int searchElement(Node* head, int num) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == num) {
            return index; 
        }
        temp = temp->next;
        index++;
    }
    return -1; 
    free(temp);
}

void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d-->",temp->data );
		temp = temp->next;
		
	}
	printf("NULL\n");
}



int main(){
	Node* head = NULL;
	int value;
	int choice;
	int pos;
	do{
		printf("\n_______________________ %% Menu %% _________________________________\n");
		printf("0. Thoat.\n");
		printf("1. Them phan tu vao dau danh sach.\n");
		printf("2. Them phan tu vao cuoi danh sach.\n");
		printf("3. Chen phan tu vao vi tri cu the.\n");
		printf("4. Xoa phan tu dau danh sach.\n");
		printf("5. Xoa phan tu cuoi danh sach.\n");
		printf("6. Xoa phan tu theo gia tri.\n");
		printf("7. Tim kiem phan tu theo gia tri.\n");
		printf("8. In danh sach gia tri theo man hinh.\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
			case 1 :
				printf("Nhap gia tri cua ban: ");
				scanf("%d", &value);
				insertHead(&head,value);
				printf("\nThem vao dau thanh cong\n");
				break;
			case 2 :
			 	printf("Nhap gia tri cua ban: ");
				scanf("%d", &value);
				insertLast(&head,value);
				printf("\nThem vao cuoi thanh cong\n");
				break;
			case 3 :
			
				printf("Nhap gia tri cua ban: ");
				scanf("%d", &value);
				printf("Nhap vi tri can dien: ");
				scanf("%d",&pos);
				insertAtPosition(&head,pos,value);
				break;
			case 4 :
				deleteHead(&head);
				printf("Xoa phan tu dau thanh cong\n");
				break;
			case 5 :
				deleteLast(&head);
				printf("Xoa phan tu cuoi thanh cong\n");
				break;
			case 6 :
				printf("Nhap gia tri can xoa: ");
				scanf("%d",&value);
				deleteElement(&head,value);
				break;
			case 7 :
				printf("Nhap gia tri cua ban: ");
				scanf("%d", &value);
				
				int result = searchElement(head,value);
				if(result !=-1){
					printf("Tim thay gia tri %d trong danh sach\n",value);
				}else{
					printf("Ko tim thay gia tri %d trong danh sach\n",value);
				}
				break;
			case 8 :
				printf("\nDanh sach lien ket: ");
				printList(head);
				break;
			default:
				printf("Gia tri nhap ko hop le\n");
				
		}
	}while(1 == 1);
	return 0;
}
