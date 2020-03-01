#include <stdio.h>
#include <stdlib.h>


#define ROW 10
#define COL 10

void matrisOlustur();
void matrisYazdir(int matris[ROW][COL], int row, int col);
int kontrol(int matris[ROW][COL], int aranacakDeger);



int main(int argc, char *argv[]) 
{

	matrisOlustur();
	
	return 0;
}


/* 
 * 1.ALt fonksiyon
 * Kullanýcý tarafýnda girilmeyen hazýr olaraak ödevde belirtilen matrisi
 * oluþturmaya yaramaktadýr.
 */
void matrisOlustur()
{
   int matris[ROW][COL] = {  {0, 15, 15, 15, 15, 15, 7, 15, 15, 15},   // Ödevde verilen matrisin oluþturulmasý.
							 {15, 15, 15, 15, 15, 7, 0, 15, 15, 15},
							 {15, 15, 15, 15, 15, 0, 7, 15, 15, 15},
							 {0, 15, 15, 15, 8, 0, 15, 15, 15, 0}, 
							 {15, 15, 15, 15, 7, 0, 15, 15, 15, 7}, 
							 {7, 15, 15, 15, 0, 0, 15, 15, 15, 15},
							 {15, 15, 15, 0, 7, 0, 8, 15, 15, 15},
							 {15, 15, 0, 0, 15, 7, 0, 8, 15, 15},
							 {15, 0, 0, 15, 15, 15, 7, 0, 7, 15},
							 {7, 7, 15, 15, 15, 15, 15, 15, 7, 7} 
					   };
	
   int degerVarmi = kontrol(matris,  0);  // Kontrol fonksiyonu çaðrýlarak 0 olan elemanlarýn bilgileri gerekli komsu hücre kontrolü yapýlareak bulunur.
   
   if(degerVarmi == 10)  // Eger aranan elaman yani 0 yoksa program sonlanýr.
   		exit(0);
	
}


/*
 * Aranan elemanýn ve komþu elamanlarýn ayný deðerde olup olmadýðýnýn verilen matris üzerinde kontrolünü 
 * yapar. Daha sonra bu elemanýn, satýr ve sutun bilgilerini gösterir.
 * 
 */
int kontrol(int matris[ROW][COL], int aranacakDeger)
{
	int i , j;
	int degerVarmi = 0;   // Matriste eleman var mý yok mu bilgisini tutar varsa sayýsýný tutar
	
	
	for(i = 0; i < ROW; i++)
	{
		for( j = 0; j < COL; j++)
		{
		     if( (matris[i][j] == aranacakDeger) )   // Eger aranacak deger varsa komsularýnýn kontrolunu yapar
		     {
		     	degerVarmi++;   // Eger aranan elaman varsa deger 1 artýrýlýr.
		
		      if ( (matris[i - 1][j - 1] == aranacakDeger)  || (matris[i - 1][j] == aranacakDeger)  ||      	// komsu elemanlarýn kontrolu yapýlýr.
				    (matris[i - 1][j + 1] == aranacakDeger)  || (matris[i ][j - 1] == aranacakDeger) ||
			        (matris[i][j + 1]  == aranacakDeger) ||  (matris[i + 1][j - 1]  == aranacakDeger) || 
					(matris[i + 1 ][j ] == aranacakDeger) || (matris[i + 1][j + 1]  == aranacakDeger) )
				{
					if(i != 0 && i != ROW - 1 && j != 0 && j != COL - 1 )  // Ýlk ya da son sutun ve satýrlarda ki sýfýrlarý pas geçer
					{
						printf("Adress: %d - Satir: %d - Sutun: %d\n", &matris[i][j], i, j );  // Bulunan elmanýn adres , satur ve sutun bilgisi ekranda gösterilir.
					}
				
				} 
				
				
			 }
		}
	}
	
	if(degerVarmi == 0)   // 0 Elemaný yoksa 10 döndürür. 
		return 10;
	else
		return 0;  // Aranan elaman varsa 0 döndürür.
}


/*
 *  Verilen bir matrisi ekrana yazmaya yarar.
 */
void matrisYazdir(int matris[ROW][COL], int row, int col)
{
	int i , j;
	
	for(i = 0; i < row; i++)
	{
		for( j = 0; j < col; j++)
		{
			printf("%2d ", matris[i][j] );
		}
		
		printf("\n");
	}
	
}

