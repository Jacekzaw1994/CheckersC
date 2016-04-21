///////////////////////////////////////////////////
// Plik: Warcaby.cpp
///////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NAME 20
#define SIZE 8

// ============= DEKLARACJE FUNKCJI =========================

void menu(void);  // funkcja menu g³ównego (interfejs)
int game( void);  // funkcja rozgrywania gry
int instruction(void);  // funkcja instrukcji
int choice(void); // funkcja wyboru uzytkownika
void wrong_choice(void); // funkcja z komunikatem jestli uzytkownik poda zly wybor

// =============== PROGRAM GLOWNY ========================

int main(void)
{
    menu();

	return 0;
}

// ============== FUNKCJA MENU GLOWNEGO ===================

void menu(void)
{
	system("cls"); // czyszczenie ekranu
	printf("888       888        d8888 8888888b.   .d8888b.        d8888 888888b. Y88b   d88P 	\n"
		   "888   o   888       d88888 888   Y88b d88P  Y88b      d88888 888  '88b Y88b d88P  	\n"
		   "888  d8b  888      d88P888 888    888 888    888     d88P888 888  .88P  Y88o88P   	\n"
		   "888 d888b 888     d88P 888 888   d88P 888           d88P 888 8888888K.   Y888P    	\n"
	       "888d88888b888    d88P  888 8888888P'  888          d88P  888 888  'Y88b   888     	\n"
		   "88888P Y88888   d88P   888 888 T88b   888    888  d88P   888 888    888   888    	\n"
		   "8888P   Y8888  d8888888888 888  T88b  Y88b  d88P d8888888888 888   d88P   888       \n"
		   "888P     Y888 d88P     888 888   T88b  'Y8888P' d88P     888 8888888P'    888       \n"
		   "\n"
		   "\n"
		   "                            _  _ ____ _  _ _  _    \n"
		   "                            |\\/| |___ |\\ | |  |  * \n"
           "                            |  | |___ | \\| |__|  * \n "
		   "                             ____    \n"
		   "			     ||P ||    \n"
		   "			     ||__||   PLAY \n"
		   "   			     |/__\\|   \n\t\t\t      ____\n"
		   "			     ||I ||    \n"
		   "			     ||__||   INSTRUCTION \n"
		   "   			     |/__\\|   \n\t\t\t      ____\n"
		   "			     ||E ||    \n"
		   "			     ||__||   END \n"
		   "   			     |/__\\|   \n");
		   choice();   //  program przechodzi do funkcji pobierania wyboru przez uzytkownika

}

// ================= FUNKCJA WYBORU UZYTKOWNIKA ========================

int choice(void)
{
	char menu_choice;   // zmienna char do pobierania wyboru

	menu_choice = getch();   // pobiera wybor z meny
	if( islower( menu_choice ))   // jesli uzytkownik poda duza litere funkcja islower przekonwertuje j¹ na ma³a, nastepnie od wartosci zostanie odjete 32 znaki z tablicy ASCII
		menu_choice -= 32;
	switch( menu_choice )
	{
		case 'P' :  game();   // jesli wpisalismy male p lub du¿e P switch przechodzi do tej etykiety case w ktorej przechodzi do funkcji gry
					break;
		case 'I' :  instruction();  // jesli wpisalismy male i lub duze I, switch przechodzi do tej etykiety case w ktrej przechodzi do funkcji z instrukcja gry
					break;
		case 'E' :  exit(1);  // jesli uzytkownik wpisal male e lub du¿e E, to funkcja switch przechodzi do tej etykiety ktora konczy program
					break;

		default:    wrong_choice();  // jesli uzytkownik nie poda litery ktora pasuje do ktorejs z powyzszych etykiet to etykieta default przekieruje program do etykiety  wrong_choice
					break;
	};
}

// =================== FUNKCJA GDY UZYTKOWNIK PODA ZLY WYBOR ========================

void wrong_choice(void)
{
	system("cls");    // funkcja z biblioteki windows.h czyszczaca ekran
	printf("\a\n\n\t\t\t      PODALES ZLY WYBOR\n\n\t\t\tWYBIERZ SPOSROD P, I LUB E !\n");   // komunikat o bledzie wyboru w menu
	sleep(1);         // funkcja uspienia programu na sekunde
	menu();           // przejscie do funkcji menu
}

// ========================= FUNKCJA MECHANIZMU GRY =================================

int game( void )
{
	system("cls");    // czeszczenie ekranu
	char first_player[NAME];  // tablica wartosci char do przechowywania, nazwy pierwszego gracza
	char second_player[NAME]; // tablica wartosci char do przechowywania, nazwy drugiego gracza

	printf("Podaj nazwe gracza z pionkami X : ");
	scanf("%14s", first_player);  // pobieranie nazwy gracza pierwszego
	printf("\n");
	printf("\n\nPodaj nazwe gracza z pionkami O : ");
	scanf("%14s", second_player); // pobieranie nazwy gracza drugiego
	printf("\n");

	int i, j, pionowa, pozioma, k, w;    // zmienne lokalne do obslugi mechanizmu gry
    int g = 1;    // zmienna gracza
    char ruch;
    // Tablica wartosci char ktora jest plansza gry
    char plansza[SIZE][SIZE]={
           {' ','O',' ','O',' ','O',' ','O'},
           {'O',' ','O',' ','O',' ','O',' '},
           {' ','O',' ','O',' ','O',' ','O'},
           {' ',' ',' ',' ',' ',' ',' ',' '},
           {' ',' ',' ',' ',' ',' ',' ',' '},
           {'X',' ','X',' ','X',' ','X',' '},
           {' ','X',' ','X',' ','X',' ','X'},
           {'X',' ','X',' ','X',' ','X',' '}
           };

    printf("\t\nWARCABY DLA 2 OSOB.\n");
    printf("Jestes graczem %s\n",first_player);
    printf("Twoje pionki to X. Pionki gracza %s to O\n",second_player);
 	// Wyswietlanie planszy gry
    printf("\n\t  12345678 ");   //
    printf("\n\t ==========\n\t");
    for( i = 0 ; i < SIZE ; i++ )
    {
        printf("%d%c" ,i + 1 , '|');
        for( j = 0 ; j < SIZE ; j++ )
        {
            printf("%c",plansza[i][j]);
        }
    	printf("%c ", '|');
    	printf("\n\t");
    }
    printf(" ==========\n");
    while(1)                     // g³ówna pêtla wykonuj¹ca program, petla nieskonczona
    {         /*-------------------------------------------------------------------- gracz 1 */

    while( g == 1 )  // dopoki gracz pierwszy wykonuje sie petla
    {
               k = 7;  // spolrzedna pionowa gracza pierwszego pola na samym dole
			   w = 0;  // wspolrzedna pozioma gracza pierwszego, zainicjalizowana wartoscia 0
			   //  warunki zamiany pionka 'O' na damê 'G'
               if(plansza[k][w] == 'O' )
               		plansza[k][w] = 'G';
               if(plansza[k][w + 2] == 'O' )                                     /* zamiana pionka O na damkê G*/
               		plansza[k][w + 2] = 'G';
               if(plansza[k][w + 4] == 'O' )
               		plansza[k][w + 4] = 'G';
               if(plansza[k][w + 6] == 'O')
               		plansza[k][w + 6] = 'G';

    printf("Ruch gracza %s\n",first_player);   // komunikat dla gracza pierwszego, ¿e jest jego ruch
    g = g + 1;
    printf("Wprowadz wspolrzedne pionka (np. 1 1, 2 7 \nnajpierw wspolrzedna pozioma, pozniej pionowa) \ni w ktora strone przesunac pionek (l-lewo, p-prawo):\n");
    fflush(stdin); // Funkcja fflush wymusza zapisanie danych znajduj¹cych siê w buforach obs³ugi podanego pliku
    scanf("%d%d",&pozioma, &pionowa);   // pobiera wspolrzedne od gracza, wspolrzedna pozioma, wpolrzedna pionowa
    pozioma = pozioma - 1;
    pionowa = pionowa - 1;
    getchar();
    ruch = getchar();
    switch(ruch)
    {
    	case 'l':
        			if( pozioma > 0 &&  pionowa > 0 && pozioma < SIZE && pionowa < SIZE )
					{
                    	if(plansza[pionowa][pozioma]!='X')
						{             /* spr czy to twój pionek*/
                        	g = g - 1;
                        	printf("Nie twoj pionek!\n");
                        	break;
						}
                        else
						{
                        	plansza[pionowa][pozioma] = ' ';
                            if(plansza[pionowa - 2][pozioma - 2] == ' ' && plansza[pionowa - 1][pozioma - 1] == 'O')     /* bicie w lewo*/
                            {
                            	plansza[pionowa - 1][pozioma - 1] = ' ';
                                plansza[pionowa - 2][pozioma - 2] = 'X';
							}
                            else
							{
                            	if(plansza[--pionowa][--pozioma] != ' ')   /*sprawdza czy docelowe miejsce jest wolne*/
                                {
									g = g - 1;
                                    printf("Pole zajete\n");
                                    plansza[++pionowa][++pozioma] = 'X';
                                    break;
								}
                                else
									plansza[pionowa][pozioma] = 'X';
							}
                        }
                    }
                    else
					{
                    	g = g - 1;
                        printf("Zly ruch");
					}

                    printf("\n\t  12345678 ");
                    printf("\n\t ==========\n");
                    printf("\t");
                    for( i = 0 ; i < SIZE ; i++ )
                    {
                        printf("%d%c", i + 1 , '|' );
                        for( j = 0 ; j < SIZE ; j++ )
                        {
                            printf("%c",plansza[i][j]);
                        }
                        printf("%c ",'|');
                        printf("\n\t");
                    }
                    printf(" ==========\n");
                    break;
        case 'p':
                	if( pozioma > -1 && pionowa > -1 && pozioma < 7 && pionowa < 8 )
					{
                    	if(plansza[pionowa][pozioma] != 'X')
						{
                            g = g - 1;
                            printf("Nie twoj pionek!\n");
                            break;
						}
                        else
						{
                            plansza[pionowa][pozioma] = ' ';
                            if(plansza[pionowa - 2][pozioma + 2 ]== ' ' && plansza[pionowa - 1][pozioma + 1] == 'O')
							{
                                plansza[pionowa - 1][pozioma + 1] = ' ';              /*bicie w prawo*/
                                plansza[pionowa - 2][pozioma + 2] = 'X';
							}
                            else
							{
                                if(plansza[--pionowa][++pozioma] != ' ')
								{
                                    g = g - 1;
                                    printf("Pole zajete\n");
                                    plansza[++pionowa][--pozioma] = 'X';
                                    break;
								}
                                else
									plansza[pionowa][pozioma] = 'X';
							}
                        }
                    }
                    else
					{
                        g = g - 1;
                        printf("Zly ruch");
					}

                    printf("\n\t  12345678 ");
                    printf("\n\t ==========\n");
                    printf("\t");
                    for( i = 0 ; i < SIZE ; i++ )
                    {
                        printf("%d%c" , i + 1 , '|');
                        for( j = 0 ; j < SIZE ; j++ )
                        {
                            printf("%c",plansza[i][j]);
                        }
                        printf("%c ",'|');
                        printf("\n\t");
                    }
                    printf(" ==========\n");
                    break;
        default:
                    g = g - 1;
                    printf("\n\nWpisz poprawnie wspolrzedne!\n");
                    break;
	}
    }
/*-------------------------------------------------------------------- gracz 2 */
    while( g == 2)
    {
               k = 0;
			   w = 1;
                if(plansza[k][w] == 'X')
                	plansza[k][w] = 'Z';                                           /* zamiana pionka X na damkê Z*/
                if(plansza[k][w+2] == 'X')
                	plansza[k][w+2] = 'Z';
                if(plansza[k][w+4] == 'X')
                	plansza[k][w+4] = 'Z';
                if(plansza[k][w+6] == 'X')
      		        plansza[k][w+6] = 'Z';

    printf("Ruch gracza %s\n",second_player);
    g = g - 1;
    printf("Wprowadz wspolrzedne pionka (np. 1 1, 2 7 \nnajpierw wspolrzedna pozioma, pozniej pionowa) \ni w ktora strone przesunac pionek (l-lewo, p-prawo):\n");
    fflush(stdin);
    scanf("%d%d",&pozioma, &pionowa);
    pozioma = pozioma - 1;
    pionowa = pionowa - 1;
    getchar();
    ruch = getchar();
    switch(ruch)
              {
                     case 'l':
                          if(pozioma > 0 && pionowa > -1 && pozioma < SIZE && pionowa < SIZE )   // sprawdzenie czy wspolrzedne nie wykraczaja poza tablice
                          {

                                       if(plansza[pionowa][pozioma] != 'O')
									   {
                                          g = g + 1;
                                          printf("Nie twoj pionek!\n");
                                          break;
									   }
                                       else
									   {
                                          plansza[pionowa][pozioma] = ' ';
                                          if(plansza[pionowa + 2][pozioma - 2] == ' ' && plansza[pionowa + 1][pozioma - 1] == 'X')
										  {
                                          		plansza[pionowa + 1][pozioma - 1] = ' ';             /*bicie w lewo*/
                                          		plansza[pionowa + 2][pozioma - 2] = 'O';
										  }
                                          else
										  {
                                          		if(plansza[++pionowa][--pozioma] != ' ')
												{
                                             		g = g + 1;
                                                 	printf("Pole zajete\n");
                                                 	plansza[--pionowa][++pozioma] = 'O';
                                                 	break;
											    }
                                          else
                                             plansza[pionowa][pozioma] = 'O';
										  }
                                       }
                          }
                          else
						  {
                          	g = g + 1;
                          	printf("Zly ruch");
						  }

                           printf("\n\t  12345678 ");
                           printf("\n\t ==========\n");
                           printf("\t");
                           for( i = 0 ; i < 8 ; i++ )
                           {
                                printf("%d%c",i+1,'|');
                                for( j = 0 ; j < 8 ; j++ )
                                {
                                    printf("%c",plansza[i][j]);
                                }
                           		printf("%c ",'|');
                          		printf("\n\t");
                          }
                          printf(" ==========\n");
                          break;
                     case 'p':
                          if( pozioma > -1 &&  pionowa > -1 && pozioma < 7 && pionowa < 8 )
                          {
                                      if(plansza[pionowa][pozioma] != 'O')
									  {
                                         g = g + 1;
                                         printf("Nie twoj pionek!\n");
                                         break;
									  }
                                      else
									  {
                                         plansza[pionowa][pozioma] = ' ';
                                         if(plansza[pionowa + 2][pozioma + 2] == ' ' && plansza[pionowa + 1][pozioma + 1] == 'X')
										 {
                                         	plansza[pionowa + 1][pozioma + 1] = ' ';                 /*bicie w prawo*/
                                         	plansza[pionowa + 2][pozioma + 2] = 'O';
                                         }
                                         else
										 {
                                         	if(plansza[++pionowa][++pozioma] != ' ')
											{
                                             	g = g + 1;
                                             	printf("Pole zajete\n");
                                             	plansza[--pionowa][--pozioma] = 'O';
                                             	break;
										 	}
                                        	else
												plansza[pionowa][pozioma] = 'O';
                                         }
                                      }
                          }
                          else
						  {
                          		g = g + 1;
                          		printf("Zly ruch");
						  }

                          printf("\n\t  12345678 ");
                          printf("\n\t ==========\n");
                          printf("\t");
                          for( i = 0 ; i < 8 ; i++ )
                          {
                                printf("%d%c", i + 1 , '|' );
                                for( j = 0 ; j < 8 ; j++ )
                                {
                                    printf("%c",plansza[i][j]);
                                }
                                printf("%c ",'|');
                                printf("\n\t");
                          }
                          printf(" ==========\n");
                          break;
                     default:
                          g = g + 1;
                          printf("\n\nWpisz poprawnie wspolrzedne!!\n");
                          break;
              }


    }
	}
	sleep(1);
	return 0;
}

// ======================== FUNCKJA INSTRUKCJI ========================

int instruction(void)
{
	system("cls");
	printf("\nTO JEST DWUOSOBOWA GRA W WARCABY. PLANSZA JEST ROZMIARU 8x8.\n\nPLANSZA SKLADA SIE Z 64 POL ULOZONYCH NA SZACHOWNICY NA PRZEMIAN. \n\n"
		   "PIONKI NA PLANSZY ULOZONE SA NA POLACH O JEDNYM KOLORZE.\n\nPO JEDNEJ STRONIE PIONKI ( X ) A PO DRUGIEJ STRONIE PIONKI ( Y ).\n\n"
		   "PIERWSZY RUCH NALEZY DO GRACZA Z PIONKAMI ( X ). ");
	printf("\n\n==========================================================\n\nAby wrocic do menu wcisnij klawisz M, aby zakonczyc wcisnji Q.\n\n");
	char your_choice; // zmienna pomocnicza wyboru gracza

	while( your_choice = getch() ) // petla
	{
		tolower( your_choice );  // funkcja tolower zmnieniajaca litery na male
		your_choice -= 32;		 // odjecie 32 znakow z tablicy kodow ASCII po to by do instrukcji if trafily duze litery
		if( your_choice == 'M' || your_choice == 'Q')   // jesli wybor gracza to 'm', 'M' lub 'q', 'Q' to warunek spelniony i zmienna wyboru przechodzi do instrukcji switch()
		{
			switch( your_choice )
			{
				case 'M' :  menu();         // jesli gracz wybral male 'm' lub duze 'M' to program przechodzi do tej etykiety w ktorej wywolywana jest funkcja menu()
							break;
				case 'Q' :  exit(1);		// jesli gracz wybral male 'q' lub duze 'Q' to program przechodzi do tej etykiety w ktorej wywolywana jest funckja exit(1)
							break;			// zakonczenie programu, i zwroceniem 1
			};
		}
		else     // jezli gracz podal zly wybor wyswietli sie ponizszy komunikat
			printf("Podaj jeszcze raz wybor!\n");
	}
}
