#include <stdio.h>
#include <string.h>

// Kullanýcý bilgilerini tutmak için diziler
char isim[10][20];   
char email[10][20];   
char sifre[10][20];   
char destek[10][50];  
char tarih[10][30];   
char saat[10][30];

int kullaniciSayisi = 0;
int i;

// Fonksiyonlar
void kayitOl();
void kullaniciGiris();
void adminGiris();
void randevuAl(int kullanicino);
void randevuGoruntule();
void randevuOnayla();

int main() {
    int secim;

    // Ana Menü
    while (1) {
        printf("\n 1- Kayýt Ol\n 2- Kullanýcý Giriþi\n 3- Admin Giriþi\n 4- Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
       
        switch (secim) {
            case 1:
                kayitOl();
                break;
            case 2:
                kullaniciGiris();
                break;
            case 3:
                adminGiris();
                break;
            case 4:
                printf("Cikis yapýldý\n");
                return 0; 
            default:
                printf("Uygun secim yapýnýz\n");
        }
    }

    return 0;
}

// Kayýt Olma Fonksiyonu
void kayitOl() {
    printf("\nKullanici Kayit \n");

    printf("Isim: ");
    scanf("%s", isim[kullaniciSayisi]); 

    printf("E-posta: ");
    scanf("%s", email[kullaniciSayisi]);

    printf("Sifre: ");
    scanf("%s", sifre[kullaniciSayisi]);

    kullaniciSayisi++;
    printf("Kayit basariyla tamamlandi.\n");
}

// Kullanýcý Giriþi Fonksiyonu
void kullaniciGiris() {
    char girilenSifre[20];
    int kullaniciBulundu = 0;
    int kullaniciNo;

    printf("\nKullanici Girisi\n");
    char girilenIsim[30];
    printf("Isim: ");
    scanf("%s", girilenIsim);

    printf("Sifre: ");
    scanf("%s", girilenSifre);
  
    // Kullanýcýyý bulmak için döngü
    for (i = 0; i < kullaniciSayisi; i++) {
        if (strcmp(isim[i], girilenIsim) == 0 && strcmp(sifre[i], girilenSifre) == 0) {
            kullaniciNo = i;  
            kullaniciBulundu = 1;
            break;
        }
    }

    //  randevu alma iþlemi
    if (kullaniciBulundu) {
        printf("Giris basarili, %s\n", isim[kullaniciNo]);

        printf("Ne tür bir destek almak istersiniz? (Ergen Danýþmanlýðý, Aile Danismanligi, Kariyer Danismanligi, vb.): ");
        scanf("%s", destek[kullaniciNo]);

        randevuAl(kullaniciNo); 
    } else {
        printf("Kullanici bulunamadi veya sifre hatali.\n");
    }
}

// Admin Giriþi 
void adminGiris() {
    char adminIsim[] = "sedef";
    char adminSifre[] = "sedef123";
    char girilenIsim[30];
    char girilenSifre[20];

    printf("\nAdmin Girisi\n");
    printf("Isim: ");
    scanf("%s", girilenIsim);

    printf("Sifre: ");
    scanf("%s", girilenSifre);

    if (strcmp(adminIsim, girilenIsim) == 0 && strcmp(adminSifre, girilenSifre) == 0) {
        printf("Admin girisi basarili\n");
        randevuGoruntule();
    } else {
        printf("Admin girisi basarisiz.\n");
    }
}

// Randevu Alma Fonksiyonu
void randevuAl(int kullanicino) {
    printf("\nRandevu Alabilirsiniz\n");

    printf("Randevu tarihini girin (gg-aa-yyyy formatinda girilmelidir): ");
    scanf("%s", tarih[kullanicino]);

    printf("Randevu saati girin (ss:dd formatinda girilmelidir): ");
    scanf("%s", saat[kullanicino]);

    printf("Randevunuz basariyla alindi\n");
    printf("Tarih: %s, Saat: %s\n", tarih[kullanicino], saat[kullanicino]);
}

// Randevularý Admin panelinde Görüntüleme Fonksiyonu
void randevuGoruntule() {
    int secim;

    printf("\nAdmin Paneli:\n");
    printf("\nKullanýcýlar ve Randevu Bilgileri:\n");
    for (i = 0; i < kullaniciSayisi; i++) {
        printf("\nKullanýcý: %s\n", isim[i]);
        printf("Randevu Tarihi: %s\n", tarih[i]);
        printf("Randevu Saati: %s\n", saat[i]);
    }
    
    printf("1- Randevuyu Onayla\n");
    printf("2- Randevu Oluþturulamadý\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim); /

   // Admin'in yaptýðý seçime göre geri bildirim
    switch (secim) {
        case 1:
            printf("\nRandevu Onaylandi\n"); 
            break;
        case 2:
            printf("\nRandevu oluþturulamadý.\n"); 
            break;
        default:
            printf("Geçersiz seçim.\n");
    }
}

