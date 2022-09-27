/*
INSTITUTO POLITÉCNICO NACIONAL
ALGORITMIA Y PROG. ESTRUCTURADA
GRUPO: 1CV2
ALUMNO(S): 
        López Morales Miguel Ángel
       Tolentino Pérez Jazmin Yaneli
ESCUELA SUPERIOR DE CÓMPUTO
PROF: DR. BENJAMÍN LUNA BENOSO
SEMESTRE 2018-2
PROYECTO: Laberinto
FECHA: Junio-2018
El juego consta de 5 niveles en los que se presentan diferentes planos
*/

#include <stdlib.h>
#include <stdio.h>
#include <allegro.h> //LIBRERIA PARA GRÁFICOS
#define FIL 32
#define COL 32

//FUNCIONES 
void mostrar();
void personaje();
void movimiento(char map[FIL][COL]);
void nivel1();
void nivel2();
void nivel3();
void nivel4();
void nivel5();
void niveles();
void init();
void deinit();
void guardar();
void recuperar();
void menu ();
void carg();
void final();

volatile int t;

void tiempo()
{
   t++;
   
}END_OF_FUNCTION(tiempo);
//ARCHIVOS MULTIMEDIA
FILE *juego;
FILE *puntajes;
MIDI *musica1;
MIDI *musica;
MIDI *musica2;
BITMAP *fondo;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *fondo4;
BITMAP *fondo5;
BITMAP *fondo6;
BITMAP *fondo7;
BITMAP *fondo8;
BITMAP *fondo9;
BITMAP *raton;
BITMAP *buffer;
BITMAP *mapa;
BITMAP *piso;
BITMAP *pers;
BITMAP *buf2;
BITMAP *carga;
BITMAP *can;
BITMAP *key1;
BITMAP *key2;
BITMAP *key3;
BITMAP *key4;
BITMAP *key5;
BITMAP *end;
BITMAP *fin;

//VARIABLES GLOBALES
int salir=0,dir=2,anim=0,px=32*0,py=32*21,x,y,bandera=0,n=0,niv,l1=0,l2=0,l3=0,l4=0,l5=0,p1,p2,p3,auxt;
char nom[15],nom1[15],nom2[15],nom3[15];

int main() 
{
	printf("Introduce tu nombre\n");
	gets(nom);
	init();
	menu ();
	deinit();
	return 0;
}
END_OF_MAIN() //CIERRE DE LIBERIA ALLEGRO 

//*****************************************************//
void init() {
	int depth, res;
	int detect_digi_driver(int driver_id);
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0)
	{
	    depth = 32;	
	}
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 992, 736, 0, 0); //TAMAÑO DE LA PANTALLA
	//ASIGNACIÓN DE VARIABLES A MULTIMEDIA 
	LOCK_VARIABLE(t);
    LOCK_FUNCTION(tiempo);
	buffer=create_bitmap(992,736);
	musica=load_midi("Recursos/song2.mid");
	musica1=load_midi("Recursos/song3.mid");
	musica2=load_midi("Recursos/song4.mid");
	buf2=create_bitmap(32,32);
	fondo=load_bitmap("Recursos/ini.bmp",NULL);
	fondo1=load_bitmap("Recursos/ini1.bmp",NULL);
	fondo2=load_bitmap("Recursos/ini2.bmp",NULL);
	fondo3=load_bitmap("Recursos/ini3.bmp",NULL);
	fondo4=load_bitmap("Recursos/ini4.bmp",NULL);
	fondo5=load_bitmap("Recursos/ini5.bmp",NULL);
	fondo6=load_bitmap("Recursos/ini6.bmp",NULL);
	fondo7=load_bitmap("Recursos/ini7.bmp",NULL);
	fondo8=load_bitmap("Recursos/ini8.bmp",NULL);
	fondo9=load_bitmap("Recursos/ini9.bmp",NULL);
	raton=load_bitmap("Recursos/raton.bmp",NULL);
	piso=load_bitmap("Recursos/floor.bmp",NULL);
	pers=load_bitmap("Recursos/personaje.bmp",NULL);
	carga=load_bitmap("Recursos/carga.bmp",NULL);
	fin=load_bitmap("Recursos/fin.bmp",NULL);
	can=load_bitmap("Recursos/locked1.bmp",NULL);
	key1=load_bitmap("Recursos/key2.bmp",NULL);
	key2=load_bitmap("Recursos/key3.bmp",NULL);
	key3=load_bitmap("Recursos/key4.bmp",NULL);
	key4=load_bitmap("key5.bmp",NULL);
	key5=load_bitmap("key6.bmp",NULL);
	end=load_bitmap("Recursos/end.bmp",NULL);
	//fin=load_bitmap("")
	if (res != 0) 
	{
		allegro_message(allegro_error);
		exit(-1);
	}
	install_timer(); //?
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
}
//*****************************************************//
void menu()
{
	play_midi(musica,1);
	while (salir!=10 && !key[KEY_ESC])  //MENÚ DE OPCIONES 
	{	 //POSICIONES DE MOUSE 
	    if(mouse_x>725 && mouse_x<954 && mouse_y> 316 && mouse_y<418)
	    {
	    	blit(fondo1,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		dir=2;
	    		anim=0;
	    		px=32*0,py=32*21;
	    		l1=0;
	    		l2=0;
	    		l3=0;
	    		bandera=1;
	    		t=0;
	    		carg();
	    		nivel1();
			}
		}
		else if(mouse_x>725 && mouse_x<954 && mouse_y> 440 && mouse_y<490)
		{
			blit(fondo2,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    	    recuperar();
	    	    if(bandera!=1)
	    	    {
	    	    	if(niv==1)
					{
						t=auxt;
						nivel1();
					}
	    	    	if(niv==2)
					{
						play_midi(musica1,1);
						nivel2();
					}
	    	    	if(niv==3)
	    	    	{
	    	    		play_midi(musica1,1);
	    	    		nivel3();
					}
	    	    	if(niv==4)
	    	    	{
	    	    		play_midi(musica1,1);
	    	    		nivel4();
					}
	    	    	if(niv==5)
	    	    	{
	    	    		play_midi(musica1,1);
	    	    		nivel5();
					}
	    	    	bandera=1;
	    	    }
	    	    salir=10;
			}
		}
		else if(mouse_x>725 && mouse_x<954 && mouse_y> 522 && mouse_y<618)
		{
			blit(fondo3,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		niveles();
			}
		}
		else
		{
			blit(fondo,buffer,0,0,0,0,992,736);
		}
		masked_blit(raton,buffer,0,0,mouse_x,mouse_y,40,44);
		blit(buffer,screen,0,0,0,0,992,736);
		if (key[KEY_ESC])
		{
			salir=1;
		}
	}
	salir=0;
}
//*****************************************************//
void deinit() 
{
	clear_keybuf();
	void remove_sound(); //?
}
//*****************************************************//
void mostrar()
{
	blit(buffer,screen,0,0,0,0,992,736);
}
void carg()
{
	while(!key[KEY_ENTER])
	{
		blit(carga,buffer,0,0,0,0,992,736);
		blit(buffer,screen,0,0,0,0,992,736);
	}
}
void punt()
{
	while(!key[KEY_ENTER])
	{
		cp();
		textprintf(screen,font,0,0,palette_color[2],"%s  %d",nom1,p1);
		textprintf(screen,font,0,2,palette_color[2],"%s  %d",nom2,p2);
		textprintf(screen,font,0,4,palette_color[2],"%s  %d",nom3,p3);
		
	}
}
//*****************************************************//
void personaje()
{
	blit(pers,buf2,anim*32,dir*32,0,0,32,32);
	draw_sprite(buffer,buf2,px,py);
}
//*****************************************************//
void niveles()
{
	n=0;
	while(n!=1)
	{
	    if(mouse_x>390 && mouse_x<540 && mouse_y> 70 && mouse_y<121)
	    {
	    	blit(fondo5,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		carg();
	    		dir=2;
	    		anim=0;
	    		px=32*0;
	    		py=32*21;
	    		l1=0,l2=0,l3=0;
	    		nivel1();
			}
		}
		else if(mouse_x>390 && mouse_x<954 && mouse_y> 196 && mouse_y<246)
		{
			blit(fondo6,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		carg();
	    		t=0;
	    		play_midi(musica1,1);
	    		px=32*0;
	    		py=32*21;
	    		l1=0,l2=0,l3=0;
	    	    nivel2();
			}
		}
		else if(mouse_x>390 && mouse_x<540 && mouse_y> 336 && mouse_y<386)
		{
			blit(fondo7,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		carg();
	    		t=0;
	    		play_midi(musica1,1);
	    		px=32*0;
	    		py=32*21;
	    		l1=0,l2=0,l3=0;
	    		nivel3();
			}
		}
		else if(mouse_x>390 && mouse_x<540 && mouse_y> 480 && mouse_y<526)
		{
			blit(fondo8,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		carg();
	    		t=0;
	    		play_midi(musica1,1);
	    		px=32*0;
	    		py=32*21;
	    		l1=0,l2=0,l3=0;
	    		nivel4();
			}
		}
		else if(mouse_x>390 && mouse_x<540 && mouse_y> 620 && mouse_y<662)
		{
			blit(fondo9,buffer,0,0,0,0,992,736);
	    	if(mouse_b & 1)
	    	{
	    		carg();
	    		t=0;
	    		play_midi(musica1,1);
	    		px=32*0;
	    		py=32*21;
	    		l1=0,l2=0,l3=0;
	    		nivel5();
			}
		}
		else
		{
			blit(fondo4,buffer,0,0,0,0,992,736);
		}
		masked_blit(raton,buffer,0,0,mouse_x,mouse_y,40,44);
	    blit(buffer,screen,0,0,0,0,992,736);
	    if(salir==1)
	    {
	    	n=1;
		}
	    if ( key[KEY_BACKSPACE] )
		{
			n=1;
		}
	}
}
//*****************************************************//
void movimiento(char map[FIL][COL])
{
	    x=px;
	    y=py;
	    if(key[KEY_UP])
	    {
	    	dir=3;
	    	if(map[(py-32)/32][px/32]=='X'||map[(py-32)/32][px/32]=='L')
	    	{
			    anim=1;
			}
			else
			{
				py-=32;
			}
		}
		else if(key[KEY_RIGHT])
		{
			dir=2;
		    if(map[py/32][(px+32)/32]=='X'||map[py/32][(px+32)/32]=='L')
	    	{
			    anim=1;
			}
			else
			{
				px+=32;
			}
		}
		else if(key[KEY_LEFT])
		{
			dir=1;
		    if(map[py/32][(px-32)/32]=='X'||map[py/32][(px-32)/32]=='L')
	    	{
	    		anim=1;
			}
			else
			{
				
			    px-=32;
				
			}
		}
		else if(key[KEY_DOWN])
		{
			dir=0;
		    if(map[(py+32)/32][px/32]=='X'||map[(py+32)/32][px/32]=='L')
	    	{
			    anim=1;
			}
			else
			{
				py+=32;
			}
		}
		if (px!= x||py!=y)
        {
            anim++;
            if (anim>2)
            {
            	anim=0;
			}
        }
		if(px<0)
		{
			anim=1;
			px=0;
		}
}
//*****************************************************//
void nivel1()
{
	int i,j;
	niv=1;
	play_midi(musica1,1);
	install_int(tiempo,1000);
    mapa=load_bitmap("Recursos/lvl1.bmp",NULL);
    char map[FIL][COL]={"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXEX",
                        "X   X       X        LLL      X",
                        "X X X XXX X X XXXXXXXXXXXXXXXXX",
                        "X X XKX   X X   X             X",
                        "X X XXX XXX XXX X XXXXXXXXXXX X",
                        "X X     X X   X     X     X   X",
                        "X XXXXXXX XXX XXXXX XXX X X X X",
                        "X X     X   X     X   X X X XTX",
                        "X X XXX X X XXXXX XXX XXX X XXX",
                        "X X X   X X     X   X   X X   X",
                        "X X X XXX XXXXXXXXX XXX X XXX X",
                        "X X X X   X       X X X X   X X",
                        "X X X X X X XXXXX X X X XXX X X",
                        "X   X X X X X X   X X X X   X X",
                        "X XXX XXX X X X XXX X X X XXX X",
                        "X X   X   X   X   X X     X   X",
                        "XXX XXX XXX XXXXX X XXXXX X XXX",
                        "X   X       X     X   X   X   X",
                        "X XXX XXXXXXX XXX XXX XXXXXXX X",
                        "X   X     X   X X X X         X",
                        "XXX XXXXXXX XXX X X XXX X XXXXX",
                        "    X       X   X       X    SX",
                        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	};
    while(salir!=1)
	{
	//	printf("%d\r",t);
		rest(115);
	    movimiento(map); 
        clear(buffer);
	    for(i=0;i<FIL;i++)
	    {
		    for(j=0;j<COL;j++)
		    {
		    	if(l1==1)
		    	{
		    		map[1][21]=' ';
		    		map[3][5]=' ';
				}
					if(l2==1)
		    	{
		    		map[1][22]=' ';
		    		map[21][29]=' ';
				}
					if(l3==1)
		    	{
		    		map[1][23]=' ';
		    		map[7][29]=' ';
				}
			    if(map[i][j]=='X')
			    {
				    draw_sprite(buffer,mapa,j*32,i*32);
		    	}
		       	else if(map[i][j]==' ')
		    	{
		    		draw_sprite(buffer,piso,j*32,i*32);
		    	}
		    	else if(map[i][j]=='L')
		    	{
		    		draw_sprite(buffer,can,j*32,i*32);
		    	}
		    	else if(map[i][j]=='K')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][21]=' ';
		    			l1++;
		    		}
		    	}
		    	else if(map[i][j]=='S')
		    	{
		    		draw_sprite(buffer,key2,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][22]=' ';
		    			l2++;
		    		}
		    	}
		    	else if(map[i][j]=='T')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][23]=' ';
		    			l3++;
		    		}
		    	}
		    	else if(map[i][j]=='E')
		    	{
		    		draw_sprite(buffer,end,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			px=32*0;
	    				py=32*21;
	    				l1=0,l2=0,l3=0;
		    			nivel2();
		    		}
		    		if ( key[KEY_ESC] )
		    		{
		    			exit(-1);
		    		}
		    	}
		    }
	    } 
	    personaje();
	    mostrar();
	    textprintf(screen,font,0,0,palette_color[2],"Time:%d",t);
	    auxt=t;
	    if(key[KEY_P])
	    {
	    	guardar();
	    	menu();
	    }
	}
	salir=1;
}
//*****************************************************//
void nivel2()
{
  int i,j;
  //l1=0,l2=0,l3=0;
  niv=2;
  //play_midi(musica1,1);
  mapa=load_bitmap("Recursos/lvl2.bmp",NULL);
  char map[FIL][COL]={"XXXXXXXXXXXXXXXXEXXXXXXXXXXXXXX",
                      "X     X        LLLX           X",
                      "XXXXXXX  XXXXXXX XK X XXX XXX X",
                      "X  X XXX  X    X XX X X   X   X",
                      "X  X X    X   XX  XXX X XXX XXX",
                      "X    XXXXXXXX  XX       X   X X",
                      "X X             XXX  XXXX XXX X",
                      "X X XXXXXXX  T    XXXX X  X   X",
                      "X X X X   X XX         X XX X X",
                      "X XXX X   XXX  XXXXX X X X  X X",
                      "X     XXX X    X     X X XXXX X",
                      "X  X X       X X  X  X     X XX",
                      "XXXX XXXXXX  X X XX  XXXXX X SX",
                      "X    X  X X X  X X   X   X X XX",
                      "X XXXX  X XXX XX X XXX X X X  X",
                      "X X  X  X      X X   X X X X  X",
                      "X X  X XX XXXXXX XXX X X XXXX X",
                      "X XXX X X X   X  X X X XXX  X X",
                      "XXX XXX  XXXXXX X XX XX X XXX X",
                      "X   X    X      X X  X  X X   X",
                      "X XXXXXXXX X XX X X  XXXX X X X",
                      "           X      X         X X",
                      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };
    while(salir!=1)
	{
		printf("%d\r",t);
	    movimiento(map);  
        clear(buffer);
	    for(i=0;i<FIL;i++)
	    {
		    for(j=0;j<COL;j++)
		    {
		    	if(l1==1)
		    	{
		    		map[1][15]=' ';
		    		map[2][18]=' ';
				}
					if(l2==1)
		    	{
		    		map[1][16]=' ';
		    		map[12][29]=' ';
				}
					if(l3==1)
		    	{
		    		map[1][17]=' ';
		    		map[7][13]=' ';
				}
			    if(map[i][j]=='X')
			    {
				    draw_sprite(buffer,mapa,j*32,i*32);
		    	}
		       	else if(map[i][j]==' ')
		    	{
		    		draw_sprite(buffer,piso,j*32,i*32);
		    	}
		    	else if(map[i][j]=='L')
		    	{
		    		draw_sprite(buffer,can,j*32,i*32);
		    	}
		    	else if(map[i][j]=='K')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][15]=' ';
		    			l1=1;
		    		}
		    	}
		    	else if(map[i][j]=='S')
		    	{
		    		draw_sprite(buffer,key2,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][16]=' ';
		    			l2=1;
		    		}
		    	}
		    	else if(map[i][j]=='T')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][17]=' ';
		    			l3=1;
		    		}
		    	}
		    	else if(map[i][j]=='E')
		    	{
		    		draw_sprite(buffer,end,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			px=32*0;
	    				py=32*21;
	    				l1=0,l2=0,l3=0;
		    			nivel3();
		    		}
		    		if ( key[KEY_ESC] )
		    		{
		    			exit(-1);
		    		}
		    	}
		    }
	    }
	    personaje();
	    mostrar();
	    textprintf(screen,font,0,0,palette_color[2],"Time:%d",t);
	    rest(115);
	    if(key[KEY_P])
	    {
	    	guardar();
	    	menu();
	    }
	}
	salir=1;
}
//*****************************************************//
void nivel3()
{
  int i,j;
  niv=3;
  //play_midi(musica1,1);
  mapa=load_bitmap("Recursos/lvl3.bmp",NULL);
  char map[FIL][COL]={"XXXXXXXXXXXXXXXXEXXXXXXXXXXXXXX",
                      "X              LLL            X",
                      "X          XXXXXX      XXXXXX X",
                      "XXXXXXXX        X             X",
                      "X        XXX    X      X XX   X",
                      "X     XXXX X  X X      XXX    X",
                      "X XXXXX  X X X  XXXXXXXX   XT X",
                      "X          X           X   XXXX",
                      "X  XXXXXXXXX   XXXXX          X",
                      "X              X      XXXXXX  X",
                      "X    X           XXX       X  X",
                      "X X    XXXX  X   X XXXXXXX X  X",
                      "X X X        X   X       X    X",
                      "X X X        X XXX XXXXX X    X",
                      "X X X  XXX  XXXX       X XXXX X",
                      "X X X  X       X    X  X    X X",
                      "X X X  X XXXXX X      XXXXX X X",
                      "X   X  X X     X        X   X X",
                      "X   X X  X  XXXXXX XXX  X XXX X",
                      "X   X X  X     X   X   SX X   X",
                      "X XXXXX  XXX   X XXXXXXXX X X X",
                      "        X        XK         X X",
                      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };
    while(salir!=1)
	{
		printf("%d\r",t);
	    movimiento(map);  
        clear(buffer);
		for(i=0;i<FIL;i++)
	    {
		    for(j=0;j<COL;j++)
		    {
		    	if(l1==1)
		    	{
		    		map[1][15]=' ';
		    		map[21][18]=' ';
				}
				if(l2==1)
		    	{
		    		map[1][16]=' ';
		    		map[19][23]=' ';
				}
				if(l3==1)
		    	{
		    		map[1][17]=' ';
		    		map[6][28]=' ';
				}
			    if(map[i][j]=='X')
			    {
				    draw_sprite(buffer,mapa,j*32,i*32);
		    	}
		       	else if(map[i][j]==' ')
		    	{
		    		draw_sprite(buffer,piso,j*32,i*32);
		    	}
		    	else if(map[i][j]=='L')
		    	{
		    		draw_sprite(buffer,can,j*32,i*32);
		    	}
		    	else if(map[i][j]=='K')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][15]=' ';
		    			l1=1;
		    		}
		    	}
		    	else if(map[i][j]=='S')
		    	{
		    		draw_sprite(buffer,key2,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][16]=' ';
		    			l2=1;
		    		}
		    	}
		    	else if(map[i][j]=='T')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][17]=' ';
		    			l3=1;
		    		}
		    	}
		    	else if(map[i][j]=='E')
		    	{
		    		draw_sprite(buffer,end,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			px=32*0;
	    				py=32*21;
	    				l1=0,l2=0,l3=0;
		    			nivel4();
		    		}
		    		if ( key[KEY_ESC] )
		    		{
		    			salir =1;
		    		}
		    	}
		    }
	    } 
	    personaje();
	    mostrar();
	    textprintf(screen,font,0,0,palette_color[2],"Time:%d",t);
	    rest(115);
	    if(key[KEY_P])
	    {
	    	guardar();
	    	menu();
	    }
	}
	salir=1;
}
//*****************************************************//
void nivel4()
{
  int i,j;
  niv=4;
  //play_midi(musica1,1);
  mapa=load_bitmap("Recursos/lvl6.bmp",NULL);
  char map[FIL][COL]={"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXEX",
                      "X   X       X        LLL      X",
                      "X X X XXX X X XXXXXXXXXXXXXXXXX",
                      "X X XKX   X X   X             X",
                      "X X XXX XXX XXX X XXXXXXXXXXX X",
                      "X X     X X   X     X     X   X",
                      "X XXXXXXX XXX XXXXX XXX X X X X",
                      "X X     X   X     X   X X X XTX",
                      "X X XXX X X XXXXX XXX XXX X XXX",
                      "X X X   X X     X   X   X X   X",
                      "X X X XXX XXXXXXXXX XXX X XXX X",
                      "X X X X   X       X X X X   X X",
                      "X X X X X X XXXXX X X X XXX X X",
                      "X   X X X X X X   X X X X   X X",
                      "X XXX XXX X X X XXX X X X XXX X",
                      "X X   X   X   X   X X     X   X",
                      "XXX XXX XXX XXXXX X XXXXX X XXX",
                      "X   X       X     X   X   X   X",
                      "X XXX XXXXXXX XXX XXX XXXXXXX X",
                      "X   X     X   X X X X         X",
                      "XXX XXXXXXX XXX X X XXX X XXXXX",
                      "    X       X   X       X    SX",
                      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };
    while(salir!=1)
	{
		printf("%d\r",t);
	    movimiento(map);  
        clear(buffer);
	    for(i=0;i<FIL;i++)
	    {
		    for(j=0;j<COL;j++)
		    {
		    	if(l1==1)
		    	{
		    		map[1][21]=' ';
		    		map[3][5]=' ';
				}
				if(l2==1)
		    	{
		    		map[1][22]=' ';
		    		map[21][29]=' ';
				}
				if(l3==1)
		    	{
		    		map[1][23]=' ';
		    		map[7][29]=' ';
				}
			    if(map[i][j]=='X')
			    {
				    draw_sprite(buffer,mapa,j*32,i*32);
		    	}
		       	else if(map[i][j]==' ')
		    	{
		    		draw_sprite(buffer,piso,j*32,i*32);
		    	}
		    	else if(map[i][j]=='L')
		    	{
		    		draw_sprite(buffer,can,j*32,i*32);
		    	}
		    	else if(map[i][j]=='K')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][21]=' ';
		    			l1=1;
		    		}
		    	}
		    	else if(map[i][j]=='S')
		    	{
		    		draw_sprite(buffer,key2,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][22]=' ';
		    			l2=1;
		    		}
		    	}
		    	else if(map[i][j]=='T')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[1][23]=' ';
		    			l3=1;
		    		}
		    	}
		    	else if(map[i][j]=='E')
		    	{
		    		draw_sprite(buffer,end,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			px=32*0;
	    				py=32*21;
	    				l1=0,l2=0,l3=0;
		    			nivel5();
		    		}
		    		if ( key[KEY_ESC] )
		    		{
		    			salir =1;
		    		}
		    	}
		    }
	    } 
	    personaje();
	    mostrar();
	    textprintf(screen,font,0,0,palette_color[2],"Time:%d",t);
	    rest(115);
	    if(key[KEY_P])
	    {
	    	guardar();
	    	menu();
	    }
	}
	salir=1;
}
//*****************************************************//
void nivel5()
{
  int i,j;
  niv=5;
  //play_midi(musica1,1);
  mapa=load_bitmap("Recursos/lvl7.bmp",NULL);
  char map[FIL][COL]={"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                      "XK      X          X          X",
                      "X X   XXX X X     XXXXXXX  XXXX",
                      "X XXX  X  X X   X X           X",
                      "X X   XXX X XXX X XXXX XXXXXX X",
                      "X X     X X   X     X  T      X",
                      "X X XXXXX XXX XXXXX XXX X X X X",
                      "X X     X   X     X   X X X X X",
                      "X X XXX X X XXXXX XXX XXX X XXX",
                      "X X X   X X     X   X   X X   X",
                      "X X X XXX XXX XXX   XXX X XXXLX",
                      "X X X X   X       X   X X   XLE",
                      "X X X X X X XXXXXXX X X X X XLX",
                      "X   X X X X X X   X X X X X X X",
                      "X XXX XXX X X XXXXX X X X XXX X",
                      "X X   X   X   X   X X     X   X",
                      "XXX XXX XXX XXXXX X XXXXX X XXX",
                      "X   X       X     X   X   X   X",
                      "X XXX XXXXXXX XXX XXX XXXXXXX X",
                      "X         X   X X X X         X",
                      "XXX XXXX XX XXX X X XXX X XXXXX",
                      "            X   X       X    SX",
                      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };
    while(salir!=1)
	{
		printf("%d\r",t);
	    movimiento(map); 
		clear(buffer);
	    for(i=0;i<FIL;i++)
	    {
		    for(j=0;j<COL;j++)
		    {
		    	if(l1==1)
		    	{
		    		map[10][29]=' ';
		    		map[1][1]=' ';
				}
				if(l2==1)
		    	{
		    		map[11][29]=' ';
		    		map[21][29]=' ';
				}
				if(l3==1)
		    	{
		    		map[12][29]=' ';
		    		map[5][23]=' ';
				}
			    if(map[i][j]=='X')
			    {
				    draw_sprite(buffer,mapa,j*32,i*32);
		    	}
		       	else if(map[i][j]==' ')
		    	{
		    		draw_sprite(buffer,piso,j*32,i*32);
		    	}
		    	else if(map[i][j]=='L')
		    	{
		    		draw_sprite(buffer,can,j*32,i*32);
		    	}
		    	else if(map[i][j]=='K')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[10][29]=' ';
		    			l1=1;
		    		}
		    	}
		    	else if(map[i][j]=='S')
		    	{
		    		draw_sprite(buffer,key2,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[11][29]=' ';
		    			l2=1;
		    		}
		    	}
		    	else if(map[i][j]=='T')
		    	{
		    		draw_sprite(buffer,key1,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			map[12][29]=' ';
		    			l3=1;
		    		}
		    	}
		    	else if(map[i][j]=='E')
		    	{
		    		draw_sprite(buffer,end,j*32,i*32);
		    		if(py/32==i && px/32==j)
		    		{
		    			map[i][j]=' ';
		    			gp();
		    			//punt();
		    			final();
		    		}
		    		if ( key[KEY_ESC] )
		    		{
		    			exit(-1);
		    		}
		    	}
		    }
	    } 
	    personaje();
	    mostrar();
	    textprintf(screen,font,0,0,palette_color[2],"Time:%d",t);
	    rest(115);
	    if(key[KEY_P])
	    {
	    	guardar();
	    	menu();
	    }
	}
	salir=1;
}
//*****************************************************//
void recuperar()
{
	int i,j;
	juego = fopen("Recursos/juego.txt","rt");
	if(juego == NULL)
	{
		printf("\n\n\t Problemas con el archivo\n");
	}
	fscanf(juego,"%d,",&salir);
	fscanf(juego,"%d,",&dir);
	fscanf(juego,"%d,",&anim);
	fscanf(juego,"%d,",&px);
	fscanf(juego,"%d,",&py);
	fscanf(juego,"%d,",&niv);
	fscanf(juego,"%d,",&l1);
	fscanf(juego,"%d,",&l2);
	fscanf(juego,"%d,",&l3);
	fscanf(juego,"%d,",&auxt);
}
//*****************************************************//
void guardar()
{
	int i,j;
	juego = fopen("Recursos/juego.txt","a+t");
	if(juego == NULL)
	{
		printf("\n\n\t Problemas al iniciar el archivo\n");
	}
	fprintf(juego,"%d,",salir);
	fprintf(juego,"%d,",dir);
	fprintf(juego,"%d,",anim);
	fprintf(juego,"%d,",px);
	fprintf(juego,"%d,",py);
	fprintf(juego,"%d,",niv);
	fprintf(juego,"%d,",l1);
	fprintf(juego,"%d,",l2);
	fprintf(juego,"%d,",l3);
	fprintf(juego,"%d,",auxt);
}
//*****************************************************//
void final()
{
	play_midi(musica2,1);
	while(!key[KEY_ENTER])
	{
		blit(fin,buffer,0,0,0,0,992,736);
		blit(buffer,screen,0,0,0,0,992,736);
	}
	menu();
}
void gp()
{
	puntajes = fopen("Recursos/puntajes.txt","wt");
	if(puntajes == NULL)
	{
		printf("\n\n\t Problemas al iniciar el archivo\n");
	}
/*	if(t<=p1)
//	{
			p1=t;
			strcmp(nom,nom1);
			fprintf(puntajes,"%d,",p1);
			fprintf(puntajes,"%s,",nom1);
	}
//	else if(t<=p2)
	{*/
			p2=t;
			strcmp(nom2,nom);
			fprintf(puntajes,"%d,",p2);
			fprintf(puntajes,"%s,",nom2);
	/*}
	else if(t<=p3)
	{
			p3=t;
			strcmp(nom,nom3);
			fprintf(puntajes,"%d,",p3);
			fprintf(puntajes,"%s,",nom3);
	}*/
}
void cp()
{
	puntajes = fopen("Recursos/puntajes.txt","rt");
	if(puntajes == NULL)
	{
		printf("\n\n\t Problemas con el archivo\n");
	}
	fscanf(puntajes,"%d,",&p1);
	fscanf(puntajes,"%s,",&nom1);
	fscanf(puntajes,"%d,",&p2);
	fscanf(puntajes,"%s,",&nom2);
	fscanf(puntajes,"%d,",&p3);
	fscanf(puntajes,"%s,",&nom3);
}
