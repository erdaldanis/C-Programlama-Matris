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
 * Kullan�c� taraf�nda girilmeyen haz�r olaraak �devde belirtilen matrisi
 * olu�turmaya yaramaktad�r.
 */
void matrisOlustur()
{
   int matris[ROW][COL] = {  {0, 15, 15, 15, 15, 15, 7, 15, 15, 15},   // �devde verilen matrisin olu�turulmas�.
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
	
   int degerVarmi = kontrol(matris,  0);  // Kontrol fonksiyonu �a�r�larak 0 olan elemanlar�n bilgileri gerekli komsu h�cre kontrol� yap�lareak bulunur.
   
   if(degerVarmi == 10)  // Eger aranan elaman yani 0 yoksa program sonlan�r.
   		exit(0);
	
}


/*
 * Aranan eleman�n ve kom�u elamanlar�n ayn� de�erde olup olmad���n�n verilen matris �zerinde kontrol�n� 
 * yapar. Daha sonra bu eleman�n, sat�r ve sutun bilgilerini g�sterir.
 * 
 */
int kontrol(int matris[ROW][COL], int aranacakDeger)
{
	int i , j;
	int degerVarmi = 0;   // Matriste eleman var m� yok mu bilgisini tutar varsa say�s�n� tutar
	
	
	for(i = 0; i < ROW; i++)
	{
		for( j = 0; j < COL; j++)
		{
		     if( (matris[i][j] == aranacakDeger) )   // Eger aranacak deger varsa komsular�n�n kontrolunu yapar
		     {
		     	degerVarmi++;   // Eger aranan elaman varsa deger 1 art�r�l�r.
		
		      if ( (matris[i - 1][j - 1] == aranacakDeger)  || (matris[i - 1][j] == aranacakDeger)  ||      	// komsu elemanlar�n kontrolu yap�l�r.
				    (matris[i - 1][j + 1] == aranacakDeger)  || (matris[i ][j - 1] == aranacakDeger) ||
			        (matris[i][j + 1]  == aranacakDeger) ||  (matris[i + 1][j - 1]  == aranacakDeger) || 
					(matris[i + 1 ][j ] == aranacakDeger) || (matris[i + 1][j + 1]  == aranacakDeger) )
				{
					if(i != 0 && i != ROW - 1 && j != 0 && j != COL - 1 )  // �lk ya da son sutun ve sat�rlarda ki s�f�rlar� pas ge�er
					{
						printf("Adress: %d - Satir: %d - Sutun: %d\n", &matris[i][j], i, j );  // Bulunan elman�n adres , satur ve sutun bilgisi ekranda g�sterilir.
					}
				
				} 
				
				
			 }
		}
	}
	
	if(degerVarmi == 0)   // 0 Eleman� yoksa 10 d�nd�r�r. 
		return 10;
	else
		return 0;  // Aranan elaman varsa 0 d�nd�r�r.
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

