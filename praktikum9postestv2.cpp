#include <iostream>
#include <cstdlib>
using namespace std;
struct list{
	int seg;
	int base;
	int limit;
	struct list *next;
} *p;
void insert(struct list *q, int base, int limit, int seg){
	if(p == NULL){
		p = (struct list*) malloc(sizeof(struct list));
		p->limit = limit;
		p->base = base;
		p->seg = seg;
		p->next = NULL;
	}
	else{
		while(q->next != NULL){
		q = q->next;
		cout << "yes" << endl;
		}
		q->next = (struct list*) malloc(sizeof(struct list));
		q->next->limit = limit;
		q->next->base = base;
		q->next->seg = seg;
		q->next->next = NULL;
	}
}
int find(struct list *q, int seg){
	while(q->seg != seg){
		q = q -> next;
	}
	return q->limit;
}
int search(struct list *q, int seg){
	while(q->seg != seg){
		q = q -> next;
	}
	return q->base;
}
int main(){
	p = NULL;
	int seg, offset, limit, base, c, s, physical;
	cout << "Segmentasi\n";
	cout << "Untuk menghentikan, masukkan -1 saat mengisi nilai segmen \n\n";
	do{
		cout << "Masukkan nomor segmen : ";
		cin >> seg;
		if(seg != -1){
			cout << "Masukkan nilai dasar (base):";
			cin >> base;
			cout << "Masukkan nilai batas (limit):";
			cin >> limit;
			insert(p, base, limit, seg);
		}
	}while(seg != -1);
	cout << "Masukkan offset: ";
	cin >> offset;
	cout << "Masukkan nomor segmentasi : ";
	cin >> seg;
	c = find(p, seg);
	s = search(p, seg);
	if(offset < c){
		physical = s + offset;
		cout << "\nAlamat di memori fisik adalah " << physical << endl;
	}else{
		cout << "Error\n\n";
	}
}
