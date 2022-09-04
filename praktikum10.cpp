#include <stdio.h>

struct strcmp{
    char dname[10], fname[10][10];
    int fcnt;
} dir;

int main(){
    int i, ch;
    char f[30];
    dir.fcnt = 0;
    printf("\nEnter name of directory -- ");
    scanf("%s", dir.dname);
    while (1){
		printf("\n\n1. Create File\t2. Delete File\t3. Search File \n4. Display Files\t5. Exit\nEnter your choice -- ");
		scanf("%d",&ch);
	switch(ch) {
        case 1:
            printf("\nMasukkan nama file -- ");
            scanf("%s", dir.fname[dir.fcnt]);
            dir.fcnt++;
            break;
        case 2:
            printf("\nMasukkan nama file-- ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++){
                if (strcmp (f, dir.fname[i]) == 0){
                    printf("File %s terhapus", f);
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("File %s tidak ditemukan", f);
            else
                dir.fcnt--;
            break;
        case 3:
            printf("\nMasukkan nama file-- ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++){
                if (strcmp(f, dir.fname[i]) == 0){
                    printf("File %s ditemukan ", f);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("File %s tidak ditemukan", f);
            break;
        case 4:
            if (dir.fcnt == 0)
                printf("\nDirektori kosong");
            else{
                printf("\nThe Files are -- ");
                for (i = 0; i < dir.fcnt; i++)
                    printf("\t%s", dir.fname[i]);
            }
            break;
        default:
            exit(0);
	}
    }
}
