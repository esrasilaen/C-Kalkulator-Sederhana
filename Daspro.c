//NAma : Esra M.R. Silaen
//NIM  : 11S22043
//Prodi : S1 Informatika
//Project UAS Praktikum Daspro, Mmembuat Kalkulator Sederhana


#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char operator[5];
    double input;
    double angka[100];
    int jumlah_angka;
} kalkulator;

void sederhana(kalkulator *sederhana)
{
    double hasil = 0;
    char respond;

    do
    {
        printf("Masukkan operator: ");
        scanf("%s", sederhana->operator);

        switch (sederhana->operator[0])
        {
        case 'p': 
            printf("Masukkan jumlah angka yang akan dijumlahkan: ");
            scanf("%d", &sederhana->jumlah_angka);

            printf("Masukkan angka-angka yang akan dijumlahkan: ");
            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                scanf("%lf", &sederhana->angka[i]);
            }

            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                hasil += sederhana->angka[i];
            }

            printf("Hasil_Penjumlahan = %.2lf\n", hasil);
            break;
            
        case 'k':
            printf("Masukkan jumlah angka yang akan dikurangkan: ");
            scanf("%d", &sederhana->jumlah_angka);

            printf("Masukkan angka-angka yang akan dikurangkan: ");
            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                scanf("%lf", &sederhana->angka[i]);
            }

            double hasil = sederhana->angka[0]; // Inisialisasi hasil dengan angka pertama
            for (int i = 1; i < sederhana->jumlah_angka; i++) // Mulai dari indeks 1
            {
                hasil -= sederhana->angka[i]; 
            }
            printf("Hasil_Pengurangan = %.2lf\n", hasil);
            break;
        case 'b' :
            printf("Masukkan jumlah angka yang akan dikalikan: ");
            scanf("%d", &sederhana->jumlah_angka);

            printf("Masukkan angka-angka yang akan dikalikan: ");
            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                scanf("%lf", &sederhana->angka[i]);
            }
            hasil = 1;
            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                hasil *= sederhana->angka[i];
            }
            printf("Hasil_Perkalian = %.2lf\n", hasil);
            break;
        case 'h':
            printf("Masukkan jumlah angka yang akan dibagikan: ");
            scanf("%d", &sederhana->jumlah_angka);

            printf("Masukkan angka-angka yang akan dibagikan: ");
            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                scanf("%lf", &sederhana->angka[i]);
            }
            hasil = sederhana->angka[0];
            for (int i = 1; i < sederhana->jumlah_angka; i++)
            {
                hasil /= sederhana->angka[i];
            }
            printf("Hasil_Pembagian = %.2lf\n", hasil);
            break;
       case 'm':
            printf("Masukkan jumlah angka yang ingin dicari modulnya: ");
            scanf("%d", &sederhana->jumlah_angka);

            printf("Masukkan angka-angka yang akan dicari modulnya: ");
            for (int i = 0; i < sederhana->jumlah_angka; i++)
            {
                scanf("%lf", &sederhana->angka[i]);
            }
             hasil = sederhana->angka[0]; 
             for (int i = 1; i < sederhana->jumlah_angka; i++) 
            {
            hasil = fmod(hasil, sederhana->angka[i]);
            }
            printf("Hasil_Modulus = %.2lf\n", hasil);
            break;

              
        }

        printf("Ingin mencoba operasi lain? y/n : ");
        scanf(" %c", &respond);
    } while (respond == 'y');
}

void dasar(kalkulator *dasar)
{
    double hasil = 0;
    char respond;

    do
    {
        printf("Masukkan operator: ");
        scanf("%s", dasar->operator);
        printf("Masukkan angka: ");
        scanf("%lf", &dasar->input);

        switch (dasar->operator[0])
        {
         case '1': 
            printf("Masukkan eksponen: ");
            int eksponen;
            scanf("%d", &eksponen);
            hasil = pow(dasar->input, eksponen);
            break;    
        case '2':
            hasil = sqrt(dasar->input);
            break;
        case '3':
            hasil = 1;
            for (int i = 1; i <= dasar->input; i++)
            {
                hasil *= i;
            }
            break;
        case '4':
            hasil = sin(dasar->input * 3.14 /180);
            break;
        case '5':
            hasil = cos(dasar->input * 3.14 / 180);
            break;    
        case '6':
            hasil = tan(dasar->input * 3.14 / 180);
            break; 
         
        default:
            break;
        }

        printf("Hasil = %.2lf\n", hasil);
        printf("Ingin mencoba operasi lain? y/n : ");
        scanf(" %c", &respond);
    } while (respond == 'y');
}

int main()
{
    kalkulator bilangan;
    char respond;
        printf("Pilih jenis kalkulator: sederhana (s) / dasar (d): ");
        scanf(" %c", &respond);

        switch (respond)
        {
        case 's':
            sederhana(&bilangan);
            break;
        case 'd':
            dasar(&bilangan);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
           
        }

    return 0;
}