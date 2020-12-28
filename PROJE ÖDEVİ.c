#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

const char matrix_bigram_strings[10][3] ={"th","he","in","er","an","en",
 "ch","de","ei","te"};
 const char matrix_trigram_strings[10][4] ={"the","and","ing","ent","ion",
 "der","sch","ich","nde","die"};

 const char languages[2][8]={"english","german"};

 //ingilizce dilinin frekans deðerleri
 const float frequency_eng[20]={ 2.71,2.33,2.03,1.78,1.61,1.13,0.01,0.01,
 0.01,0.01,1.81,0.73,0.72,0.42,0.42,0.01,0.01,0.01,0.01,0.01};
 //almanca dilinin frekans deðerleri
 const float frequency_germ[20]={ 0.01,0.89,1.71,3.90,1.07,3.61,2.36,2.31,
 1.98,1.98,0.01,0.01,0.01,0.01,0.01,1.04,0.76,0.75,0.72,0.62};

 float calculated_frequencies[20];
 float distances[2]={0,0};


void filter_str(char metin)
{

    int i=0;
    strupr(metin);//metindeki karakterleri buyutmek icin
    while(i<127){//girilen karakterin ascii kodu 127 den buyuk olamaz
      if(metin[i]<65 || 90<metin[i]){//65'den kucuk 90'dan buyuk olma kosulu
         metin[i]="\0";//kosul dogru ise bosluk haline getirilecek
         i++;//indis bir arttirilacak
       }
    }

}
void calculate_frequencies_bi(char metin)
{

    int j,i=0;
    char matrix_bigram_strings;
    float calculated_frequencies[20];
    int sayac=0;
    for(j=0;j<10;j++){//verilen bigram matrislerini tek tek tarayacak
     for(i=0;i<strlen(metin);i++){//metindeki harfleri tek tek tarayacak
        if(matrix_bigram_strings[i][i+1]==metin[i]){//bigram matrisinin metinde bulunma koşulu
                calculated_frequencies[sayac++]=i;//kosul dogru ise sayac degeri bir arttirilacak

         }
       }
    }
       printf("toplam bulunan harf obegi sayisi:%d\n",sayac);//sayac degeri ekrana yazdirilacak
       for(int c=0;c<sayac;c++){
           printf("cumlede toplanan harf sayisi:%d\n",calculated_frequencies[c]);//sayac degeri calculated_frequencies'e atanacak
}
void calculate_frequencies_tri(char metin)
{

    int j,i=0;
    char matrix_trigram_strings;
    float calculated_frequencies[20];
    int sayacx=0;
    for(j=0;j<10;j++){//verilen trigram matrislerini tek tek tarayacak
     for(i=0;i<strlen(metin);i++){//metindeki harfleri tek tek tarayacak
        if(matrix_trigram_strings[i][i+1]==metin[i]){//trigram matrisinin metinde bulunma koulu
                calculated_frequencies[sayacx++]=i;//koul dogru ise sayacx'in degeri bir artacak
         }
       }
    }
       printf("toplam bulunan harf obegi sayisi:%d\n",sayacx);//sayacx degeri yazdirilacak
       for(int c=0;c<sayacx;c++)
           printf("cumlede toplanan harf sayisi:%d\n",calculated_frequencies[c]);//sayacx degeri calculated_frequencies degerine atanacak
}

void calculate_distances(const float distances[2][20])
{
    int m,n,k;
    for(m=0;m<strlen(frequency_eng);m++){//frequency_eng'deki degerleri tek tek tarayacak
        for(k=0;k<strlen(calculated_frequencies);k++){//calculated_frequencies'deki buldugumuz sayilari tek tek tarayacak
            distances=sqrt(pow((frequency_eng[m])-(calculated_frequencies[k]),2.0)+pow((frequency_eng[m+1])-(calculated_frequencies[k+1]),2.0));/*distances'i oklid islemi ile tanimladik*/
            printf("aralarindaki mesafe farki:%f",distances[1]);//aralarindaki mesafe farki distances'in birinci satirina yazdirilacak
            printf("/n");//bir satir asagi inilecek
        }
     }
     for(n=0;n<strlen(frequency_germ);n++){//frequency_germ'deki degerleri tek tek tarayacak
        for(k=0;k<strlen(calculated_frequencies);k++){//calculated_frequencies'deki bulduğumuz sayıları tek tek tarayacak
            distances=sqrt(pow((frequency_germ[n])-(calculated_frequencies[k]),2.0)+pow((frequency_germ[n])-(calculated_frequencies[k]),2.0));/*distances'i oklid islemi ile tanimladik*/
            printf("aralarindaki mesafe farki:%f",distances[2]);//aralarindaki mesafe farki distances'in ikinci satirina yazdirilacak
            printf("/n");//bir satir asagi inilecek
        }
     }
}

void detect_lang()
{
int e,a,enk1,enk;
float distances[2][20];
int k;
enk=distances[1][0];//enk degerine distances[1][0] degeri atanacak
for(k=0;k<20;k++){//distances icindeki mesafe farklarini tek tek taranacak
    if(distances[1][k]<enk){//distances[1][k] degerinin enk degerinden kucuk olma kosulu
        enk=distances[1][k];//kosul dogru ise distances[1][k]degeri enk degerine atanacak
        distances[1][k]=='e';//switch case'de kullanmak uzere e'ye esitlendi
        switch(distances){
            case 'e':
                printf("Girdiginiz metin Ingilizce...\n");
                break;
            default://'e'den farkli ise
                printf("Girdiginiz metin Almanca...\n");
                break;
     }
    }
}

int main()
{
    char metin[500];//metni almak icin 500 karakterli bir dizi tanimladik
    int i=0;
    printf("lutfen metni giriniz: ");
    gets(metin);//metin alinacak
    filter_str(char metin[i]);
    calculate_frequencies_bi(char metin[i]);
    calculate_frequencies_tri(char metin[i]);
    calculate_distances();
    detect_lang();
    puts(metin);//metin yazdirilacak
    return 0;
}
