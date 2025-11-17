#include <stdio.h>
#include <stdlib.h>

struct canbo {
    long maso; char ten[8];
};
struct node {
    canbo info;
    node *next;
};
struct danhsach {
    node *head;
    node *tail;
};

// 1. Khoi tao danh sach lien ket
void khoitao(danhsach &d) {
    d.head = d.tail = NULL;
}

// 2. Kiem tra danh sach rong
int isEmpty(danhsach d) {
    return (d.head == NULL);
}

node *taoNode(canbo x) {
    node *p = (node *)malloc(sizeof(node));
    p->info = x;
    p->next = NULL;
    return p;
}


// 3. Them phan tu vao dau danh sach
void push_front(danhsach &d, canbo x) {
    node *p = taoNode(x);
    if (isEmpty(d)) {
        d.head = d.tail = p;
    } else {
        p->next = d.head;
        d.head = p;
    }
}

// 4. Them phan tu vao cuoi danh sach
void push_back(danhsach &d, canbo x) {
    node *p = taoNode(x);
    if (isEmpty(d)) {
        d.head = d.tail = p;
    } else {
        d.tail->next = p;
        d.tail = p;
    }
}

// 5. Them phan tu vao sau vi tri k (bat dau tu 1)
void push_after_k(danhsach &d, canbo x, long k) {
    node *p = taoNode(x);
    if (isEmpty(d)) {
        printf("Danh sach rong\n");
        free(p);
        return;
    }
    node *q = d.head;
    int cnt = 1;
    while (q != d.tail && cnt < k) {
        q = q->next;
        cnt++;
    }
    if (cnt < k) {
        printf("Vi tri khong hop le\n");
        free(p);
    } else {
        p->next = q->next;
        q->next = p;
        if (q == d.tail) {
            d.tail = p;
        }
    }
}

// 6. Them phan tu vao truoc vi tri k (bat dau tu 1)
void push_before_k(danhsach &d, canbo x, long k) {
    push_after_k(d, x, k - 1);
}

// 7. Xoa phan tu o dau danh sach
void pop_front(danhsach &d) {
    if (isEmpty(d)) {
        printf("Danh sach rong\n");
        return;
    }
    node *p = d.head;
    d.head = d.head->next;
    free(p);
    if (d.head == NULL) {
        d.tail = NULL;
    }
}

// 8. Xoa phan tu o cuoi danh sach
void pop_back(danhsach &d) {
    if (isEmpty(d)) {
        printf("Danh sach rong\n");
        return;
    }
    if (d.head == d.tail) {
        free(d.head);
        d.head = d.tail = NULL;
        return;
    }
    node *q = d.head;
    while (q->next != d.tail) {
        q = q->next;
    }
    free(d.tail);
    d.tail = q;
    d.tail->next = NULL;
}

// 9. Xoa phan tu o vi tri k (bat dau tu 1)
void pop_k(danhsach &d, long k) {
    if (isEmpty(d)) {
        printf("Danh sach rong\n");
        return;
    }
    if (k == 1) {
        pop_front(d);
        return;
    }
    node *q = d.head;
    int cnt = 1;
    while (q->next != NULL && cnt < k - 1) {
        q = q->next;
        cnt++;
    }
    if (q->next == NULL) {
        printf("Vi tri khong hop le\n");
    } else {
        node *p = q->next;
        q->next = p->next;
        if (p == d.tail) {
            d.tail = q;
        }
        free(p);
    }
}

// 10. Xoa toan bo danh sach
void clear(danhsach &d) {
    while (!isEmpty(d)) {
        pop_front(d);
    }
}

// 11. In danh sach
void printList(danhsach d) {
    node *p = d.head;
    while (p != NULL) {
        printf("%ld %s\n", p->info.maso, p->info.ten);
        p = p->next;
    }
}

// 12. Doc danh sach tu tep
void readList(danhsach &d) {
    FILE *f = fopen("input.txt", "r");
    khoitao(d);
    canbo x;
    while (fscanf(f, "%ld %s", &x.maso, x.ten) != EOF) {
        push_back(d, x);
    }
    fclose(f);
}

// 13. In danh sach ra tep
void printListFile(danhsach d) {
    FILE *f = fopen("output.txt", "w");
    node *p = d.head;
    while (p != NULL) {
        fprintf(f, "%ld %s\n", p->info.maso, p->info.ten);
        p = p->next;
    }
    fclose(f);
}

int main() {

}