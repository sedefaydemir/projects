#include <stdio.h>
#include <string.h>

// Kullan�c� bilgilerini tutmak i�in diziler
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

    // Ana Men�
    while (1) {
        printf("\n 1- Kay�t Ol\n 2- Kullan�c� Giri�i\n 3- Admin Giri�i\n 4- Cikis\n");
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
                printf("Cikis yap�ld�\n");
                return 0; 
            default:
                printf("Uygun secim yap�n�z\n");
        }
    }

    return 0;
}

// Kay�t Olma Fonksiyonu
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

// Kullan�c� Giri�i Fonksiyonu
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
  
    // Kullan�c�y� bulmak i�in d�ng�
    for (i = 0; i < kullaniciSayisi; i++) {
        if (strcmp(isim[i], girilenIsim) == 0 && strcmp(sifre[i], girilenSifre) == 0) {
            kullaniciNo = i;  
            kullaniciBulundu = 1;
            break;
        }
    }

    //  randevu alma i�lemi
    if (kullaniciBulundu) {
        printf("Giris basarili, %s\n", isim[kullaniciNo]);

        printf("Ne t�r bir destek almak istersiniz? (Ergen Dan��manl���, Aile Danismanligi, Kariyer Danismanligi, vb.): ");
        scanf("%s", destek[kullaniciNo]);

        randevuAl(kullaniciNo); 
    } else {
        printf("Kullanici bulunamadi veya sifre hatali.\n");
    }
}

// Admin Giri�i 
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

// Randevular� Admin panelinde G�r�nt�leme Fonksiyonu
void randevuGoruntule() {
    int secim;

    printf("\nAdmin Paneli:\n");
    printf("\nKullan�c�lar ve Randevu Bilgileri:\n");
    for (i = 0; i < kullaniciSayisi; i++) {
        printf("\nKullan�c�: %s\n", isim[i]);
        printf("Randevu Tarihi: %s\n", tarih[i]);
        printf("Randevu Saati: %s\n", saat[i]);
    }
    
    printf("1- Randevuyu Onayla\n");
    printf("2- Randevu Olu�turulamad�\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim); /

   // Admin'in yapt��� se�ime g�re geri bildirim
    switch (secim) {
        case 1:
            printf("\nRandevu Onaylandi\n"); 
            break;
        case 2:
            printf("\nRandevu olu�turulamad�.\n"); 
            break;
        default:
            printf("Ge�ersiz se�im.\n");
    }
}

