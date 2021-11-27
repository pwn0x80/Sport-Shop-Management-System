#include "config.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
enum access state;

DATA_ACCESS data_access;
struct node {
  int data;
  int sno;
  char item[200];
  int price;
  int quantity;
  struct node *next;
} *first = NULL, *last = NULL;

struct e_node {
  char name[200];
  int contact;
  char sex[200];
  struct e_node *e_next;
} *head = NULL, *tail;

int insert_employ(struct e_node *k, char *sex, char *name, int contact) {
  struct e_node *t;
  int i;
  if (k == NULL) {
    head = (struct e_node *)malloc(sizeof(struct e_node));
    strcpy(head->sex, sex);
    strcpy(head->name, name);
    head->contact = contact;
    head->e_next = NULL;
    tail = head;
  } else {
    while (k == NULL) {
      tail = k;
      k = k->e_next;
    }
    t = (struct e_node *)malloc(sizeof(struct e_node));
    strcpy(t->sex, sex);
    strcpy(t->name, name);
    t->contact = contact;

    tail->e_next = t;
    tail = t;
  }
  return 0;
}

void e_display(struct e_node *p) {
  int i = 1;
  while (p) {

    printf("\n%d) Employee: %s ", i, p->name);
    printf("\nEnter Employee's contact details: %d\n", p->contact);
    printf("Sex: %s\n", p->sex);
    p = p->e_next;
    i++;
  }
  printf("\n");
}
int e_countNodes() {
  int count = 0;
  struct e_node *temp;

  temp = head;

  while (temp != NULL) {
    count++;
    temp = temp->e_next;
  }

  return count;
}

int e_Delete(struct e_node *p, int index) {
  struct e_node *q = NULL;
  int x = -1, i;
  int c = e_countNodes();
  printf("%d", c);
  if (index < 1 || index > c)
    return -1;
  if (index == 1) {
    q = head;
    x = head->contact;
    head = head->e_next;
    free(q);
    return x;
  } else {
    for (i = 0; i < index - 1; i++) {
      q = p;
      p = p->e_next;
    }
    q->e_next = p->e_next;
    x = p->contact;
    free(p);
    return x;
  }
}

// for item
int insert(struct node *p, char *item, int price, int quantity) {
  struct node *t;
  int i;
  if (p == NULL) {
    first = (struct node *)malloc(sizeof(struct node));
    strcpy(first->item, item);
    first->price = price;
    first->quantity = quantity;
    first->next = NULL;
    last = first;
  } else {
    while (p == NULL) {
      last = p;

      p = p->next;
    }
    t = (struct node *)malloc(sizeof(struct node));
    strcpy(t->item, item);
    t->price = price;
    t->quantity = quantity;
    last->next = t;
    last = t;
  }
  return 0;
}

void display(struct node *p) {
  int i = 1;
  while (p) {

    printf("\n%d) Item Name: %s ", i, p->item);
    printf("\nItem Price (Rs.): %d\n", p->price);
    printf("Item Quantity (per pcs): %d\n", p->quantity);
    p = p->next;
    i++;
  }
  printf("\n");
}

int countNodes() {
  int count = 0;
  struct node *temp;

  temp = first;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  return count;
}

int Delete(struct node *p, int index) {
  struct node *q = NULL;
  int x = -1, i;
  int c = countNodes();
  printf("%d", c);
  if (index < 1 || index > c)
    return -1;
  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  } else {
    for (i = 0; i < index - 1; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int main() {
  // struct node *a;

  char item[20], e_name[20], e_sex[20];
  int price, e_contact;
  int quantity, no, w = 0;
  int i;

  system("clear");
  print_image();
  sleep(1);
  system("clear");
  while (true) {
    w = 0;
    printf(BLU "Shop Management List\n\n" RESET);

    printf("1) Employee Credentials\n");
    printf("2) Product Specifications\n");
    printf("3) Exit\n");
    printf(BLU "Enter Your Choice\n" RESET);
    scanf("%d", &i);

    switch (i) {
    case 1:
      while (w == 0) {
        printf("1) Admin Login \n");

        printf("2) Enter New Employee \n");
        printf("3) Review Employee Credentials\n");
        printf("4) Delete Employee Credentials\n");
        printf("5) Back\n");
        printf(BLU "Enter Your Choice\n" RESET);
        scanf("%d", &i);

        switch (i) {
        case 1:

          printf(MAG "Enter Admin Login Credentials\n" RESET);

          scanf("%s", data_access.user);
          Mode();
          if (data_access.mode_set == 1) {
            printf(GRN "User ID Credentials logged in successfully\n" RESET);
          } else {
            printf(RED "Incorrect user ID\n" RESET);
          }
          break;
        case 2: // For Addition
          /* code */
          if (data_access.mode_set == 1) {
            printf("\nEnter Employee Name\n");
            scanf("%s", e_name);
            printf("Enter Employee Contact Number\n");
            scanf("%d", &e_contact);
            printf("Enter Employee Sex\n");
            scanf("%s", e_sex);
            insert_employ(head, e_sex, e_name, e_contact);
          } else {
            printf(RED "Need administrator's permission\n" RESET);
          }

          break;

        case 3: // For display
          e_display(head);
          /* code */
          break;

        case 4: // For Delete

          if (data_access.mode_set == 1) {
            e_display(head);
            printf(BLU "Employee Number to deleted" RESET);
            scanf("%d", &no);
            e_Delete(head, no);
            e_display(head);
          } else {
            printf(RED "Need administrator's permission\n" RESET);
          }

          /* code */
          break;

        case 5:
          w = 1;
          break;
        }
      }
      break;

    case 2:
      while (w == 0) {
        printf("1) Add Sport Item\n");

        printf("2) view item detail\n");
        printf("3) Delete item detail\n");
        printf("4) back\n");
        printf(BLU "Enter Your Choice\n" RESET);
        scanf("%d", &i);
        switch (i) {
        case 1: // For Addition
                /* code */
          printf("Item Name: ");
          scanf("%s", item);
          printf("Item price: ");
          scanf("%d", &price);
          printf("Item quantity: ");
          scanf("%d", &quantity);
          insert(first, item, price, quantity);

          break;

        case 2: // For Search
          /* code */
          display(first);

          break;

        case 3: // For Delete
          /* code */
          printf("Delete Item: ");
          scanf("%d", &no);
          Delete(first, no);
          break;

        case 4:
          w = 1;
          break;
        }
      }
      break;

    case 3:
      exit(0);
      break;

    default:
      printf("Invalid input.\n");
      break;
    }
  }
}
