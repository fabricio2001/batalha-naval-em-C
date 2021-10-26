#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

struct Conta
{
    char senha[11];
    char usuario[11];
    char conFsenha[11];
    int log;
    char user[11];
};

void mapa(char campo[10][10],int pontos,int qtiro);
void preencherC(char campo[10][10]);
void preencherG(char gabarito[10][10]);
int pontosJ(char posi);
int escolharL();
int escolharC();
void player();

void playerVS();
void preencherGP(char gabarito[10][10]);
void posiOB(char gabarito[10][10]);
void gabaritoP(char gabarito[10][10]);
void campoP(char campo[10][10]);
void escolharP(char campo[10][10],char gabarito[10][10]);

void menu();
void informacao();
void cor();
void corT();
void corF();
void menuL();
void intro();
void resolucao();

struct Conta login();
void cadastro();

int main()
{
    int esc , opc;

    struct Conta c;

    system("TITLE,BATALHA NAVAL");
    system("mode con:cols=160 lines=40");

    intro();
    do{
        do{
            menuL();
            scanf("%d",&opc);
            switch(opc)
            {
        case 1:
           c = login();
            break;

        case 2:
            cadastro();
            break;

        default:

            break;
            }
        }while(opc != 1 && opc != 2);
    }while(c.log != 1);
    //getch();

    do
    {
        menu(c);
        printf("\n\tDigite umas das opcoes para escolher: ");
        scanf("%d",&esc);
        getchar();
        switch(esc)
        {
        case 1:
            player();
            break;
        case 2:
            playerVS();
            break;
        case 3:
            informacao();
            break;
        case 4:
            cor();
            break;
        case 5:
            resolucao();
            break;
        case 6:
            printf("\n\tSaindo ......");
            break;
        default:
            printf("\n\tOpcao invalide");
        }
    }
    while(esc != 6);



    return 0 ;
}



void menuL()
{
    system("cls");
    printf("\n\t������������ CONTA �����������Ŀ");
    printf("\n\t�  [1] Login                   �");
    printf("\n\t�  [2] Cadastro                �");
    printf("\n\t��������������������������������\n\t ");
}

void menu(struct Conta c)
{

    system("cls");
    printf("\n\t�������� MODOS DE JOGOS ������Ŀ\t            |\\                        \t������������������������������Ŀ");
    printf("\n\t�  [1] Primeiro                �\t            |_\\                       \t           %s                   ",c.user);
    printf("\n\t�  [2] Segundo                 �\t            |__\\                      \t��������������������������������");
    printf("\n\t��������������������������������\t            |___\\                     ");
    printf("\n\t������������ EXTRAS ����������Ŀ\t            |____\\                    ");
    printf("\n\t�  [3] Informacao              �\t            |_____\\                  ");
    printf("\n\t�  [4] Cor                     �\t            |______\\                ");
    printf("\n\t�  [5] Resolucao               �\t       ______|_______________        ");
    printf("\n\t��������������������������������\t~~~~~~\\____________________/~~~~~  ");
    printf("\n\t������������������������������Ŀ\t..~~..~~..~~..~~..~~..~~..~~..~~.. ");
    printf("\n\t�  [6] Sair                    �\t~~..~~..~~..~~..~~..~~..~~..~~..~~   ");
    printf("\n\t��������������������������������\t");
}

void informacao()
{
    system("cls");
    printf("\n\t���������������������������������������������������������������������������Ŀ");
    printf("\n\t�  S = Submarino [1T] � N = Navio [3T] � P = Porta Aviao [5T] � B = Bomba   �");
    printf("\n\t�  S = Submarino [4P] � N = Navio [6P] � P = Porta Aviao [5P] � B = Bomba   �");
    printf("\n\t�����������������������������������������������������������������������������");
    printf("\n\t����������������������������������������Ŀ");
    printf("\n\t�  O T representa o tamanho              �");
    printf("\n\t�  O P representa a quantidade de pontos �");
    printf("\n\t������������������������������������������");
    printf("\n\t�������������������������������������������������������������������������������������Ŀ");
    printf("\n\t�  O Primeiro modo de jogo voce que tenta acerta a posicao dos barcos               �");
    printf("\n\t�  O Segundo modo de jogo voce que coloca os barcos para o computador tenta acerta �");
    printf("\n\t���������������������������������������������������������������������������������������");
    printf("\n\t�������������������������������������������������������������������������������������Ŀ");
    printf("\n\t�  O Primeiro modelo de jogo e o unico que possui pontuacao pois quando voce alcanca  �");
    printf("\n\t�  uma determinada pontuacao ira desbloquear **********                               �");
    printf("\n\t���������������������������������������������������������������������������������������");
    printf("\n\t��������������������������������������Ŀ");
    printf("\n\t�  Precione qualquer tecla para sair   �");
    printf("\n\t����������������������������������������");


    getch();
}

void cor()
{
    int cor ;
    do
    {
        system("cls");
        printf("\n\t������������������������������Ŀ");
        printf("\n\t�Digite onde quer muda a cor:  �");
        printf("\n\t��������������������������������");
        printf("\n\t�����������Ŀ      �����������Ŀ");
        printf("\n\t� 1  Texto  �      � 2  Fundo  �");
        printf("\n\t�������������      �������������");
        printf("\n\t�����������Ŀ");
        printf("\n\t� 3  Volta  �");
        printf("\n\t�������������\n\t");

        scanf("%d",&cor);

        switch(cor)
        {
        case 1:
            corT();
            break;
        case 2:
            corF();
            break;
        default:
            printf("\tOpcao invalida");
        }
    }
    while(cor != 1 && cor != 2 && cor!= 3);
}

void corT()
{
    int cor;
    do
    {
        system("cls");
        printf("\n\t�����������������������Ŀ");
        printf("\n\t�Digite o numero da cor �");
        printf("\n\t�������������������������");
        printf("\n\t������������������������������Ŀ");
        printf("\n\t�   Volta            : 0       �");
        printf("\n\t�   Azul             : 1       �");
        printf("\n\t�   Verde            : 2       �");
        printf("\n\t�   Ciano            : 3       �");
        printf("\n\t�   Vermelho         : 4       �");
        printf("\n\t�   Magenta          : 5       �");
        printf("\n\t�   Marrom           : 6       �");
        printf("\n\t�   Cinza Claro      : 7       �");
        printf("\n\t�   Cinza Escuro     : 8       �");
        printf("\n\t�   Azul Claro       : 9       �");
        printf("\n\t��������������������������������\n\t");
        scanf("%d",&cor);

        switch(cor)
        {
            break;
        case 1:
            system("color 1");
            break;
        case 2:
            system("color 2");
            break;
        case 3:
            system("color 3");
            break;
        case 4:
            system("color 4");
            break;
        case 5:
            system("color 5");
            break;
        case 6:
            system("color 6");
            break;
        case 7:
            system("color 7");
            break;
        case 8:
            system("color 8");
            break;
        case 9:
            system("color 9");
            break;
        }


    }
    while(cor < 0 || cor > 9);
}

void corF()
{
    int cor;
    do
    {
        system("cls");
        printf("\n\t�����������������������Ŀ");
        printf("\n\t�Digite o numero da cor �");
        printf("\n\t�������������������������");
        printf("\n\t������������������������������Ŀ");
        printf("\n\t�   Volta            : 0       �");
        printf("\n\t�   Azul             : 1       �");
        printf("\n\t�   Verde            : 2       �");
        printf("\n\t�   Ciano            : 3       �");
        printf("\n\t�   Vermelho         : 4       �");
        printf("\n\t�   Magenta          : 5       �");
        printf("\n\t�   Marrom           : 6       �");
        printf("\n\t�   Cinza Claro      : 7       �");
        printf("\n\t�   Cinza Escuro     : 8       �");
        printf("\n\t�   Azul Claro       : 9       �");
        printf("\n\t��������������������������������\n\t");
        scanf("%d",&cor);

        switch(cor)
        {
            break;
        case 1:
            system("color 1B");
            break;
        case 2:
            system("color 2B");
            break;
        case 3:
            system("color 3B");
            break;
        case 4:
            system("color 4B");
            break;
        case 5:
            system("color 5B");
            break;
        case 6:
            system("color 6B");
            break;
        case 7:
            system("color 7B");
            break;
        case 8:
            system("color 8B");
            break;
        case 9:
            system("color 9B");
            break;
        }


    }
    while(cor < 0 || cor > 9);
}

void intro()
{
    int i, x, j ;

    x = 20;
    for(j = 0 ; j < 19 ; j ++)
    {
        Sleep(100);
        system("cls");

        for(i = 0 ; i < x ; i++)
        {

            printf("\n");

        }
        printf("\n\t  __      _____   _______   _____                    _____                         _____                    _____            ");
        printf("\n\t |  \\    |     |     |     |     |  |       |     | |     |            |\\      |  |     |  \\            /  |     |  |     ");
        printf("\n\t |   |   |     |     |     |     |  |       |     | |     |            | \\     |  |     |   \\          /   |     |  |      ");
        printf("\n\t |  /    |     |     |     |     |  |       |     | |     |            |  \\    |  |     |    \\        /    |     |  |      ");
        printf("\n\t | |     |_____|     |     |_____|  |       |_____| |_____|            |   \\   |  |_____|     \\      /     |_____|  |      ");
        printf("\n\t |  \\    |     |     |     |     |  |       |     | |     |            |    \\  |  |     |      \\    /      |     |  |     ");
        printf("\n\t |   |   |     |     |     |     |  |       |     | |     |            |     \\ |  |     |       \\  /       |     |  |      ");
        printf("\n\t |__/    |     |     |     |     |  |_____  |     | |     |            |      \\|  |     |        \\/        |     |  |_____ \n\n");
        printf("\n\t\t\tDesenvolvedores:");
        printf("\n\t\t\tFabricio");
        printf("\n\t\t\tFabio");
        x--;
    }
}

void resolucao()
{
    int res;
    do{
        system("cls");
        printf("\n\t���������������������Ŀ");
        printf("\n\t�Escolha o tamanho    �");
        printf("\n\t�����������������������");
        printf("\n\t�������������������������������Ŀ");
        printf("\n\t�  [1] 160 x 40 (recomendavel)  �");
        printf("\n\t�  [2] 110 x 30 (original)      �");
        printf("\n\t�  [3] 200 x 40                 �");
        printf("\n\t�  [4] 210 x 45                 �");
        printf("\n\t�  [5] 90 x 30                  �");
        printf("\n\t���������������������������������\n\t");
        scanf("%d",&res);

    }while(res < 1 || res > 5 );

    switch(res){
case 1 :
    system("mode con:cols=160 lines=40");
    break;
case 2 :
    system("mode con:cols=110 lines=30");
    break;
case 3 :
    system("mode con:cols=200 lines=40");
    break;
case 4 :
    system("mode con:cols=210 lines=45");
    break;
case 5 :
    system("mode con:cols=90 lines=30");
    break;
default:
    break;
    }
}



void playerVS()
{
    char campo[10][10], gabarito[10][10], sair;

    do
    {
        preencherC(campo);
        preencherGP(gabarito);
        posiOB(gabarito);
        escolharP(campo,gabarito);
        campoP(campo);
        printf("\n\tDeseja sair ? degite s:  ");
        //getchar();
        scanf("%c",&sair);
    }
    while(sair != 's');

}

void preencherGP(char gabarito[10][10])
{
    int i, j, li, co ;

    for(i = 0 ; i < 10 ; i++)
    {
        for(j = 0 ; j < 10 ; j++)
        {
            gabarito[i][j] = ' ';
        }
    }
}

void posiOB(char gabarito[10][10])
{
    int li, co, i;

    i = 0;
    do
    {
        do
        {
            gabaritoP(gabarito);
            printf("\n\n\tDigite a posicao para coloca um Navio");
            printf("\n\tDigite a linha: ");
            scanf("%d",&li);
            getchar();
            if(li > 9 || li < 0)
            {
                printf("\tPosicao invalida");
                Sleep(1000);
            }

        }
        while(li > 9 || li < 0);

        do
        {
            gabaritoP(gabarito);
            printf("\n\n\n\tDigite a coluna: ");
            scanf("%d",&co);
            getchar();
            if(co > 7 || co < 0)
            {
                printf("\tPosicao invalida");
                Sleep(1000);
            }

        }
        while(co > 7 || co < 0);
        if((gabarito[li][co] == ' ')&&(gabarito[li][co+1] == ' ')&&(gabarito[li][co+2] == ' '))
        {
            gabarito[li][co] = 'N';
            gabarito[li][co+1] = 'N';
            gabarito[li][co+2] = 'N';
            gabaritoP(gabarito);
            i++;
        }
    }
    while(i < 5);


    i = 0;
    do
    {
        do
        {
            gabaritoP(gabarito);
            printf("\n\n\tDigite a posicao para coloca um Porta Aviao");
            printf("\n\tDigite a linha: ");
            scanf("%d",&li);
            getchar();
            if(li > 9 || li < 0)
            {
                printf("\tPosicao invalida");
                Sleep(1000);
            }

        }
        while(li > 9 || li < 0);

        do
        {
            gabaritoP(gabarito);
            printf("\n\n\n\tDigite a coluna: ");
            scanf("%d",&co);
            getchar();
            if(co > 5 || co < 0)
            {
                printf("\tPosicao invalida");
                Sleep(1000);
            }

        }
        while(co > 5 || co < 0);
        if((gabarito[li][co] == ' ') && (gabarito[li][co+2] == ' ') && (gabarito[li][co+4] == ' '))
        {
            gabarito[li][co] = 'P';
            gabarito[li][co+1] = 'P';
            gabarito[li][co+2] = 'P';
            gabarito[li][co+3] = 'P';
            gabarito[li][co+4] = 'P';
            gabaritoP(gabarito);
            i++;
        }
    }
    while(i != 2);


    i = 0 ;
    do
    {
        do
        {
            gabaritoP(gabarito);
            printf("\n\n\tDigite a posicao para coloca um Submarino");
            printf("\n\tDigite a linha: ");
            scanf("%d",&li);
            getchar();
            if(li > 9 || li < 0)
            {
                printf("\tPosicao invalida");
                Sleep(1000);
            }

        }
        while(li > 9 || li < 0);

        do
        {
            gabaritoP(gabarito);
            printf("\n\n\n\tDigite a coluna: ");
            scanf("%d",&co);
            getchar();
            if(co > 9 || co < 0)
            {
                printf("\tPosicao invalida");
                Sleep(1000);
            }

        }
        while(co > 9 || co < 0);

        if(gabarito[li][co] == ' ')
        {
            gabarito[li][co] = 'S';
            gabaritoP(gabarito);
            i++;
        }
    }
    while(i != 5);

    for(int l = 0 ; l < 10 ; l++)
    {
        for(int c = 0 ; c < 10 ; c++)
        {
            if(gabarito[l][c] == ' ')
            {
                gabarito[l][c] = 'B';
            }
        }
    }


}

void gabaritoP(char gabarito[10][10])
{
    int i, j ;
    system("cls");
    printf("\n\t\t\tBartalha Naval ");
    printf("\n\t���������������������������������������������������������������������������Ŀ");
    printf("\n\t�  S = Submarino [1T] � N = Navio [3T] � P = Porta Aviao [5T] � B = Bomba   �");
    printf("\n\t�����������������������������������������������������������������������������");
    puts("\n\n");
    printf("\t       0      1      2      3      4      5      6      7      8      9\n");
    for(i = 0 ; i < 10 ; i++)
    {
        printf("\n\t%d  ",i);
        for(j = 0 ; j < 10 ; j++)
        {
            printf("  [ %c ]",gabarito[i][j]);
        }
    }

}

void campoP(char campo[10][10])
{
    int i, j ;
    system("cls");
    printf("\n\t\t\tBartalha Naval");
    printf("\n\t���������������������������������������������������������������������������Ŀ");
    printf("\n\t�  S = Submarino [1T] � N = Navio [3T] � P = Porta Aviao [5T] � B = Bomba   �");
    printf("\n\t�����������������������������������������������������������������������������");
    puts("\n\n");
    printf("\t       0      1      2      3      4      5      6      7      8      9\n");

    for(i = 0 ; i < 10 ; i++)
    {
        printf("\n\t%d  ",i);
        for(j = 0 ; j < 10 ; j++)
        {
            printf("  [ %c ]",campo[i][j]);
        }
    }
}

void escolharP(char campo[10][10],char gabarito[10][10])
{
    int li, co, tiro ;
    srand( (unsigned)time(NULL) );

    tiro = 5;
    do
    {
        li = rand() % 9 ;
        co = rand() % 9 ;

        campo[li][co] = gabarito[li][co];

        if(campo[li][co] == 'N')
        {
            campo[li][co+1] = gabarito[li][co+1];
            tiro--;
            if(campo[li][co+1] == 'N')
            {
                campo[li][co+2] = gabarito[li][co+2];
                tiro--;
            }
            else if((campo[li][co+1] != 'N') || (campo[li][co+2] != 'N'))
            {
                campo[li][co-1] = gabarito[li][co-1];
                tiro--;
            }
            if((campo[li][co+1] != 'N') && (campo[li][co-1] == 'N'))
            {
                campo[li][co-2] = gabarito[li][co-2];
                tiro--;
            }
        }

        if(co < 6)
        {
            if(gabarito[li][co] == 'P')
            {
                campo[li][co+1] = gabarito[li][co+1];
                tiro--;
                if(gabarito[li][co+1] == 'P')
                {
                    campo[li][co+2] = gabarito[li][co+2];
                    tiro--;
                    if(gabarito[li][co+2] == 'P')
                    {
                        campo[li][co+3] = gabarito[li][co+3];
                        tiro--;
                        if(gabarito[li][co+3] == 'P')
                        {
                            campo[li][co+4] = gabarito[li][co+4];
                            tiro--;
                        }
                    }
                }
            }
        }


        tiro--;
    }
    while(tiro != 0 );





}



void player()
{
    int tiro, li, co, pontos, pontog, codigo;
    char campo[10][10], gabarito[10][10], sair;

    do
    {
        tiro = 5;
        pontos = 0;
        preencherC(campo);
        preencherG(gabarito);

        do
        {

            do
            {
                mapa(campo,pontos,tiro);
                li = escolharL();
                if(li == 2019)
                {
                    tiro++;
                }
                getchar();

            }
            while(li > 9 || li < 0);
            do
            {
                mapa(campo,pontos,tiro);
                co = escolharC();
                if(co == 2001)
                {
                    mapa(gabarito,pontos,tiro);
                    getch();
                }
                getchar();
            }
            while(co > 9 || co < 0);

            campo[li][co] = gabarito[li][co];

            tiro--;

            pontog = pontosJ(gabarito[li][co]);
            pontos = pontos + pontog;

            mapa(campo,pontos,tiro);

        }
        while(tiro != 0);

        if(pontos > 10)
        {
            system("cls");
            printf("\n\t����������������������������������������������Ŀ");
            printf("\n\t�Voce conseguil a quantida de pontos           �");
            printf("\n\t�necessaria para desbloquear uns dos codigos:  �");
            printf("\n\t������������������������������������������������");
            printf("\n\t����������������������������������������������Ŀ");
            printf("\n\t�Caso digita uma opcao invalida pedera a chance�");
            printf("\n\t������������������������������������������������");
            printf("\n\t����������������������������������Ŀ");
            printf("\n\t�Escolhe uns dos codigos:  � 1 � 2 �");
            printf("\n\t������������������������������������\n\t");

            scanf("%d",&codigo);
            switch(codigo)
            {
            case 1 :
                printf("\n\tUtilize o codigo 2019 quando for digita linha");
                getch();
                break;
            case 2 :
                printf("\n\tUtilize o codigo 2001 quando for digita coluna");
                getch();
                break;
            default :
                printf("\n\tPerdeu a chance");
                break;
            }
            getchar();
        }

        printf("\n\n\tDeseja sair s ? ");

        scanf("%c",&sair);

    }
    while(sair != 's');

}

void mapa(char campo[10][10],int pontos,int qtiro)
{
    int i, j ;
    system("cls");
    printf("\n\t\t\tBartalha Naval           Pontuacao: %d           Tiros: %d ",pontos,qtiro);
    printf("\n\t���������������������������������������������������������������������������Ŀ");
    printf("\n\t�  S = Submarino [1T] � N = Navio [3T] � P = Porta Aviao [5T] � B = Bomba   �");
    printf("\n\t�  S = Submarino [4P] � N = Navio [6P] � P = Porta Aviao [5P] � B = Bomba   �");
    printf("\n\t�����������������������������������������������������������������������������");
    puts("\n\n");
    printf("\t       0      1      2      3      4      5      6      7      8      9\n");

    for(i = 0 ; i < 10 ; i++)
    {
        printf("\n\t%d  ",i);
        for(j = 0 ; j < 10 ; j++)
        {
            printf("  [ %c ]",campo[i][j]);
        }
    }
}

void preencherC(char campo[10][10])
{
    int i, j ;
    for(i = 0 ; i < 10 ; i++)
    {
        for(j = 0 ; j < 10 ; j++)
        {
            campo[i][j] = ' ';
        }
    }
}

void preencherG(char gabarito[10][10])
{
    int i, j, x, y ;

    for(i = 0 ; i < 10 ; i++)
    {
        for(j = 0 ; j < 10 ; j++)
        {
            gabarito[i][j] = 'B';
        }
    }

    srand( (unsigned)time(NULL) );

    for(i = 0 ; i < 5 ; i++)
    {
        x = rand() % 9 ;
        y = rand() % 7 ;

        gabarito[x][y] = 'N';
        gabarito[x][y+1] = 'N';
        gabarito[x][y+2] = 'N';
        i++;

    }


    i = 0 ;
    do
    {

        x = rand() % 9 ;
        y = rand() % 5 ;
        if((gabarito[x][y] == 'B') && (gabarito[x][y+2] == 'B') && (gabarito[x][y+4] == 'B'))
        {
            gabarito[x][y] = 'P';
            gabarito[x][y+1] = 'P';
            gabarito[x][y+2] = 'P';
            gabarito[x][y+3] = 'P';
            gabarito[x][y+4] = 'P';
            i++;
        }
    }
    while(i != 2);

    i = 0 ;
    do
    {
        x = rand() % 9 ;
        y = rand() % 9 ;
        if(gabarito[x][y] == 'B')
        {
            gabarito[x][y] = 'S';
            i++;
        }
    }
    while(i != 5);
}

int pontosJ(char posi)
{
    int pontos;
    if(posi == 'S')
    {
        pontos = 4;
    }
    else if(posi == 'P')
    {
        pontos = 1;
    }
    else if(posi == 'N')
    {
        pontos = 2;
    }
    else
    {
        pontos = 0;
    }
    return pontos;
}

int escolharL()
{
    int li ;
    printf("\n\n\tDigite a linha: ");
    scanf("%d",&li);
    if(li > 9 || li < 0)
    {
        printf("\tPosicao invalida");
        Sleep(1000);
    }

    return li ;
}

int escolharC()
{
    int co;
    printf("\n\n\tDigite a coluna: ");
    scanf("%d",&co);
    if(co > 9 || co < 0)
    {
        printf("\tPosicao invalida");
        Sleep(1000);
    }
    return co ;
}



struct Conta login()
{
    struct Conta c;

    int x = 0;
    int y = 0;

    do
    {
        system("cls");

        printf("\n\t����������������");
        printf("\n\t�USUARIO: ");
        scanf("%s",c.usuario);

        strcpy(c.user,c.usuario);

        strcat(c.usuario,".txt");

        FILE *file = fopen(c.usuario,"r");

        x = 0;
        y = 1;

        if(file == NULL)
        {
            x = 1;
        }

        fgets(c.senha,10,file);

        printf("\t����������������");
        printf("\n\t�SENHA: ");
        scanf("%s",c.conFsenha);
        getchar();

        if(strcmp(c.senha,c.conFsenha) == 0)
        {
            y = 0;
        }

        puts("\t");

        if(x == 1 && y == 0)
        {
            printf("\n\tUsuario incorreto.\n\tTente novamente\n");
        }
        else if(x == 0 && y == 1)
        {
            printf("\n\tSenha incorreta.\n\tTente novamente\n");
        }
        else if(x == 1 && y == 1)
        {
            printf("\n\tUsuario e Senha incorreta.\n\tTente novamente\n");
        }
        else if(x == 0 && y == 0)
        {
            printf("\n\tUsuario e Senha confirmados.");
            Sleep(100);
            fclose(file);
            x = 5;
            y = 5;
            ;
        }
        Sleep(1000);
    }
    while(x != 5 && y != 5);

    c.log = 1;

    return c;
}

void cadastro()
{
    struct Conta c;

    char *usuario[11];
    char senha[11];

    do
    {
        do
        {
            Sleep(100);
            system("cls");
            printf("\n\tTanto o \"usuario\" quanto a \"senha\" devem \n\tser preencidas com menos de 9 caractere");
            printf("\n\t����������������");
            printf("\n\t�USUARIO: ");
            scanf("%s",c.usuario);

            if(strlen(c.usuario) > 9)
            {
                printf("\n\tUsuario invalido.\n\tTente um menor");
                Sleep(1000);
            }
        }
        while(strlen(c.usuario) > 9);

        strcat(c.usuario,".txt");

        printf("\t����������������");
        printf("\n\t�SENHA: ");
        scanf("%s",c.senha);
        getchar();

        if(strlen(c.senha) > 9)
        {
            printf("\n\tSenha invalida.\n\tTente uma menor");
            Sleep(1000);
        }
    }
    while(strlen(c.senha) > 9);

    FILE *file = fopen(c.usuario,"a");
    fputs(c.senha,file);

    fclose(file);
    printf("\n\tConta criado con sucesso.");
    Sleep(1000);
}
