 #include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
struct Mahasiswa {
    char npm[20];
    char nama[50];
    int semester;
    int umur;
    char prodi[50];
    char fakultas[50];
    char univ[50];
};
int jumlahmhs;
typedef struct Mahasiswa;
struct Mahasiswa info[50],temp;

bool baru(int jumlahmhs){ //fungsi untuk input data baru
	int a;
    for( a = 1; a <= jumlahmhs; a++) {
        printf("\nMasukkan NPM: ");
        scanf(" %[^\n]s", &info[a].npm);
        printf("\nMasukkan Nama: ");
        scanf(" %[^\n]c", &info[a].nama);
        printf("\nMasukkan Semester: ");
        scanf(" %d", &info[a].semester);
        printf("\nMasukkan Umur: ");
        scanf(" %d", &info[a].umur);
        printf("\nMasukkan Program Studi: ");
        scanf(" %[^\n]c", &info[a].prodi);
        printf("\nMasukkan Fakultas: ");
        scanf(" %[^\n]c", &info[a].fakultas);
        printf("\nMasukkan Universitas: ");
        scanf(" %[^\n]c", &info[a].univ);
      
    }
    return true;
}

void view() { //fungsi untuk menampilkan
	int a;
    for(a = 1; a<= jumlahmhs; a++) {
            printf("\n\nNPM   : %s", info[a].npm);
            printf("\nNama    : %s", info[a].nama);
            printf("\nSemester: %d", info[a].semester);
            printf("\nUmur    : %d", info[a].umur);
            printf("\nProdi   : %s", info[a].prodi);
            printf("\nFakultas: %s", info[a].fakultas);
            printf("\nUniveristas  : %s", info[a].univ);
             
        }
        
    }


bool Update(int array) { //fungsi untuk memperbarui data
	
            int j = array;
            printf("/nMasukkan NPM baru: ");
            scanf(" %[^\n]s", &info[j].npm);
            printf("\nMasukkan Nama: ");
            scanf(" %[^\n]c", &info[j].nama);
            printf("\nMasukkan Semester: ");
            scanf(" %d", &info[j].semester);
            printf("\nMasukkan Umur: ");
            scanf(" %d", &info[j].umur);
            printf("\nMasukkan Program Studi: ");
            scanf(" %[^\n]c", &info[j].prodi);
            printf("\nMasukkan Fakultas: ");
            scanf(" %[^\n]c", &info[j].fakultas);
            printf("\nMasukkan Universitas: ");
            scanf(" %[^\n]c", &info[j].univ);
           
            return true;
}

bool Delet(int array) { //fungsi untuk menghapus
    strcpy(info[array].npm, "");
    strcpy(info[array].nama, "");
    info[array].semester = 0;
    info[array].umur = 0;
    strcpy(info[array].prodi, "");
    strcpy(info[array].fakultas, "");
    strcpy(info[array].univ, "");;
    return true; 
}

int main() {
    //Menu
    int pilih;
    int i;
    char input[20];
    bool run = true;

    while(run == true) {
        printf("\n-----PILIH MENU-----\n"); //menu
      	printf("1. Tambah mahasiswa baru\n2. Tampilkan semua data mahasiswa\n3. Edit data mahasiswa\n4. Hapus data mahasiswa\n5. Urutkan data\n0. Keluar\n pilih :  ");
        scanf("%d", &pilih);
        if(pilih > 0 && pilih < 6) {
            if(pilih == 1) { 
            	system("cls");
                printf("Masukkan jumlah mahasiswa: ");
                scanf(" %d", &jumlahmhs);
                if(jumlahmhs > 0) {
                    if(baru(jumlahmhs) == true) printf("Berhasil ditambahkan.\n\n");
                    else printf("Gagal menambahkan. \n\n");
                } else printf("Input tidak valid \n\n");
            }
            if(pilih == 2) {
            	system("cls");
                printf("Menampilkan semua data: \n");
                view();
            }
            if(pilih == 3) {
            	system("cls");
            	int i;
                printf("\nMasukkan NPM yang akan di ganti: ");
                scanf(" %[^\n]s", &input);
                for( i = 1; i <= jumlahmhs; i++) {
                    if(!strcmp(info[i].npm, input)) {
                        if(Update(i)==true) printf("\nData diperbarui!\n\n");
                    } 
                }      
            }
            if (pilih == 4) {
            	system("cls");
            	int i;
                printf("\nMasukkan NPM yang akan di hapus: ");
                scanf(" %[^\n]s", &input);
                for( i = 1; i<= jumlahmhs; i++) {
                    if(!strcmp(info[i].npm, input)) {
                        if(Delet(i)==true) printf("Data NPM %s berhasil dihapus! \n\n", input);
                    }
                }
            }
            if (pilih == 5) {
            	system("cls");
                printf("\nMengurutkan berdasarkan NPM\n");
                int a, b;
                
                for(a=1;a<=jumlahmhs;a++) {
                    for( b=1;b<=jumlahmhs-1;b++) {
                        if(strcmp(info[b].npm, info[b+1].npm)>0) {
                            temp = info[b];
                            info[b] = info[b+1];
                            info[b+1] = temp;
                        }
                    }
                }
                printf("\nBerhasil diurutkan, Silahkan lihat di menu lihat semua data.");
            

            }
            
        } else if (pilih ==0) return 0;
    }

}
