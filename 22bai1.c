#include <stdio.h>
#include <string.h>

struct Sinhvien {
    char id[50];
    int age;
    char name[50];
};

struct Sinhvien sv[100];
int numStudent = 0;

// khai bao ham lay du lieu tu file
void loadFileSinhVien();
// ham in thong tin sinh vien
void printStudents();
// ham them sinh vien
void addStudent();
// ham luu sinh vien vao file student.bin
void saveStudent();

int main() {
    loadFileSinhVien();
    int choice;
    do {
        printf("\nMenu\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep sinh vien theo id\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // in sinh vien
                printStudents();
                break;
            case 2:
                // them sinh vien
                addStudent();
                break;
            case 3:
                // sua thong tin sinh vien
                // code sua thong tin sinh vien
                break;
            case 4:
                // xoa sinh vien
                // code xoa sinh vien
                break;
            case 5:
                // tim kiem sinh vien
                // code tim kiem sinh vien
                break;
            case 6:
                // sap xep sinh vien theo id
                // code sap xep sinh vien
                break;
        }
    } while (choice != 7);
    return 0;
}

// chien khai ham
void loadFileSinhVien() {
    FILE *file;
    file = fopen("students.bin", "rb");
    if (file == NULL) {
        printf("Loi, khong mo duoc file\n");
        return;
    }
    // lay du lieu trong file
    numStudent = fread(sv, sizeof(struct Sinhvien), 100, file);
    fclose(file);
}

// ham in thong tin sinh vien
void printStudents() {
    if (numStudent == 0) {
        printf("Danh sach sinh vien trong\n");
        return;
    }
    for (int i = 0; i < numStudent; i++) {
        printf("Thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: %s\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
    }
}

// ham them sinh vien
void addStudent() {
    if (numStudent >= 100) {
        printf("Danh sach day\n");
        return;
    }
    struct Sinhvien sv1;
    printf("Nhap id: ");
    getchar(); // Loai bo ky tu newline con lai trong bo dem
    fgets(sv1.id, sizeof(sv1.id), stdin);
    sv1.id[strcspn(sv1.id, "\n")] = '\0';
    printf("Nhap ten Sinh vien: ");
    fgets(sv1.name, sizeof(sv1.name), stdin);
    sv1.name[strcspn(sv1.name, "\n")] = '\0';
    printf("Nhap tuoi: ");
    scanf("%d", &sv1.age);
    sv[numStudent] = sv1;
    numStudent++;
    printf("Them sinh vien thanh cong\n");
    // luu vao trong file
    saveStudent();
}

// ham luu sinh vien vao file
void saveStudent() {
    FILE *file;
    file = fopen("students.bin", "wb");
    fwrite(sv, sizeof(struct Sinhvien), numStudent, file);
    fclose(file);
}

