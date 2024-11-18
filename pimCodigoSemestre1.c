#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
    FILE *pArquivo;
    char email[201]={},nome[201]={},senha[201]={},cpf[12]={};
    int idade=0,opc=0,pagina,paginaAnterior,registrados=0,logado=0,blsala[4]={30,30,30,30}; blsala1=30,blsala2=30,blsala3=30,blsala4=30;
    typedef struct {
    char email[201],nome[201],senha[201];
    int idade,cpf;
    }Visitante;
    Visitante visitante[1500];

int charVrificar(char var[300]){
    int i, vrd;
        for(i =0; i < strlen(var);i++){}
        if(!isdigit(var[i])){
            vrd=0;
        }else{
            vrd=1;
        }
    return vrd;
}
int menuInicial(){
    pagina=0;

    if(logado!=0){
        do{

        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t_________________________________________");
        printf("\n\t|       Bem vindo ao nosso sistema      |");
        printf("\n\t_________________________________________");
        printf("\n\t| Escolha uma das seguintes op��es      |");
        printf("\n\t| [0] Sair                              |");
        printf("\n\t| [1] Ver as exibi��es do museu         |");
        printf("\n\t| [2] Comprar bilhetes para as exibi��es|");
        printf("\n\t| [3] Se registrar no nosso sistema     |");
        printf("\n\t_________________________________________\n\t");
        scanf("%d",&opc);
        printf("\t_________________________________________");
        if(opc<0||opc>3){
            system("cls");
            printf("Escolha uma das op��es listadas");
        }
        switch(opc){

            case(0):
                system("cls");
                printf("\n\n\t\tAt� a pr�xima.\n\n");
                break;
            case(1):
                system("cls");
                menuPrincipal();
                break;
            case(2):
                system("cls");
                paginaAnterior=0;
                bilhetesSala();
                break;
            case(3):
                system("cls");
                registrar();
                break;
            default: system("cls"); printf("Escolha uma das op��es listadas"); break;
        }
    }while(opc<0||opc>3);


    }else{
        do{

        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",visitante[registrados].nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t_________________________________________");
        printf("\n\t|       Bem vindo ao nosso sistema      |");
        printf("\n\t_________________________________________");
        printf("\n\t| Escolha uma das seguintes op��es      |");
        printf("\n\t| [0] Sair                              |");
        printf("\n\t| [1] Ver as exibi��es do museu         |");
        printf("\n\t| [2] Se registrar no nosso sistema     |");
        printf("\n\t_________________________________________\n\t");
        scanf("%d",&opc);
        printf("\t_________________________________________");
        if(opc<0||opc>2){
            system("cls");
            printf("Escolha uma das op��es listadas");
        }
        switch(opc){
            case(0):
                system("cls");
                printf("\n\n\t\tAt� a pr�xima.\n\n");
                break;
            case(1):
                system("cls");
                menuPrincipal();
                break;
            case(2):
                system("cls");
                registrar();
                break;

        }
    }while(opc<0||opc>2);

    }


return 0;
}

int registrar(){
    pagina =1;

    pArquivo = fopen("RegistrosMuseu.txt","a");
    if(pArquivo==NULL){

        printf("Erro ao abrbir o banco de dados");
    }



    printf("\n\t______________________");
    printf("\n\t|Entre com seu E-mail|");
    printf("\n\t______________________\n");
    scanf("%s",&email);
    printf("\n\t______________________");
    printf("\n\t|Confirme seu E-mail |");
    printf("\n\t______________________\n");
    scanf("%s",&email);

    printf("\n\t_____________________");
    printf("\n\t|Entre com sua senha|");
    printf("\n\t_____________________\n");
    scanf("%s",&senha);
    printf("\n\t_____________________");
    printf("\n\t|Cofirme sua senha  |");
    printf("\n\t_____________________\n");
    scanf("%s",&senha);

    printf("\n\t_____________________");
    printf("\n\t|Entre com sua cpf  |");
    printf("\n\t_____________________\n");
    scanf("%s",&cpf);
    printf("\n\t_____________________");
    printf("\n\t|Cofirme sua cpf    |");
    printf("\n\t_____________________\n");
    scanf("%s",&cpf);

    printf("\n\t____________________");
    printf("\n\t|Entre com seu Nome|");
    printf("\n\t____________________\n");
    fflush (stdin);
    fgets(nome, sizeof(nome), stdin);

    printf("\n\t_____________________");
    printf("\n\t|Entre com sua idade|");
    printf("\n\t_____________________\n");
    scanf("%d",&idade);

    fprintf(pArquivo,"\n Email:%s; Senha:%s; CPF:%s; Nome:%s ; Idade:%d; ",email,senha,cpf,nome,idade);
    fclose(pArquivo);
    system("cls");
    printf("\n\tRegistrado com sucesso");


    registrados+=1;
    logado=1;
    trocarPagina(pagina);
    return 0;
}
int menuPrincipal(){
    pagina=2;
    if(logado!=0){
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t___________________________________________");
        printf("\n\t|   Bem vindo ao nosso museu              |");
        printf("\n\t___________________________________________\n");
        printf("\n\t|Escolha uma das seguintes op��es         |");
        printf("\n\t| [0] Sair                                |");
        printf("\n\t| [1] 100 anos da semana de arte moderna  |");
        printf("\n\t| [2] 150 anos de Santos Dumont           |");
        printf("\n\t| [3] Ol�mpiadas de 2024 em Paris         |");
        printf("\n\t| [4] 200 anos de independ�ncia do Brasil |");
        printf("\n\t| [5] Comprar bilhetes                    |");
        printf("\n\t___________________________________________\n");
        scanf("%d",&opc);
        printf("\n\t___________________________________________\n");
        switch(opc){
            case(0): system("cls"); trocarPagina(pagina); break;
            case(1): system("cls"); tema1(); break;
            case(2): system("cls"); tema2(); break;
            case(3): system("cls"); tema3(); break;
            case(4): system("cls"); tema4(); break;
            case(5): system("cls"); paginaAnterior=2; bilhetesSala(); break;
            default: system("cls"); menuPrincipal(); break;
        }
        if(opc<0||opc>5){
            system("cls");
            printf("\n\tEscolha uma das op��es listadas!");
        }
    }while(opc<0 || opc>5);
    }else{
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t___________________________________________");
        printf("\n\t|   Bem vindo ao nosso museu              |");
        printf("\n\t___________________________________________\n");
        printf("\n\t|Escolha uma das seguintes op��es         |");
        printf("\n\t| [0] Sair                                |");
        printf("\n\t| [1] 100 anos da semana de arte moderna  |");
        printf("\n\t| [2] 150 anos de Santos Dumont           |");
        printf("\n\t| [3] Ol�mpiadas de 2024 em Paris         |");
        printf("\n\t| [4] 200 anos de independ�ncia do Brasil |");
        printf("\n\t___________________________________________\n");
        scanf("%d",&opc);
        printf("\n\t___________________________________________\n");
        switch(opc){
            case(0): system("cls"); trocarPagina(pagina); break;
            case(1): system("cls"); tema1(); break;
            case(2): system("cls"); tema2(); break;
            case(3): system("cls"); tema3(); break;
            case(4): system("cls"); tema4(); break;
            default: system("cls"); menuPrincipal(); break;
        }
        if(opc<0||opc>4){
            system("cls");
            printf("\n\tEscolha uma das op��es listadas!");
        }
    }while(opc<0 || opc>4);
    }
    return 0;
}
int bilhetesSala(int var){
    do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
            printf("\n\t________________________________________________");
            printf("\n\t|   Bem vindo ao nosso museu                   |");
            printf("\n\t________________________________________________\n");
            printf("\n\t|Para qual sala voc� deseja comprar um bilhete |");
            printf("\n\t| [0] Sair                                     |");
            printf("\n\t| [1] 100 anos da semana de arte moderna       |");
            printf("\n\t| [2] 150 anos de Santos Dumont                |");
            printf("\n\t| [3] Ol�mpiadas de 2024 em Paris              |");
            printf("\n\t| [4] 200 anos de independ�ncia do Brasil      |");
            printf("\n\t________________________________________________\n");
            scanf("%d",&opc);
            printf("\n\t________________________________________________\n");
            switch(opc){
                case(0): system("cls"); trocarPagina(pagina); break;
                case(1): system("cls"); bilhetes(0); break;
                case(2): system("cls"); bilhetes(1); break;
                case(3): system("cls"); bilhetes(2); break;
                case(4): system("cls"); bilhetes(3); break;
            }
            if( opc<0||opc>4){
                system("cls");
                printf("\n\tEscolha uma das op��es listadas!");
            }
        }while(opc<0 || opc>4);


}
int comprabilhetes(int sala, int qual){
    if(sala==0){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }

    }else if(sala==1){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
    }else if(sala==2){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
    } else if(sala==3){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
    }


}
int bilhetes(int var){
    pagina=3;


    if(idade>60){
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
            printf("\n\t_______________________________________");
            printf("\n\t|   Bem vindo ao nosso museu          |");
            printf("\n\t_______________________________________\n");
            printf("\n\t|Escolha uma dos seguintes bilhetes   |");

            printf("\n\t| [0] Sair                            |");

            if(blsala[var]>0){
            printf("\n\t| [1] bilhete individual              |");
            }else if(blsala[var]<1){
            printf("\n\t| [1] bilhete individual(INDISPONIVEL)|");
            }

            if(blsala[var]>4){
            printf("\n\t| [2] 5 bilhetes                      |");
            }else if(blsala[var]<5){
            printf("\n\t| [2] 5 bilhetes(INDISPONIVEL)        |");
            }

            if(blsala[var]>9){
            printf("\n\t| [3] 10 bilhetes                     |");
            }else if(blsala[var]<10){
            printf("\n\t| [3] 10 bilhetes(INDISPONIVEL)       |");
            }

            if(blsala[var]>14){
            printf("\n\t| [4] 15 bilhetes                     |");
            }else if(blsala[var]<15){
            printf("\n\t| [4] 15 bilhetes(INDISPONIVEL)       |");
            }

            if(blsala[var]>0){
            printf("\n\t| [5] bilhete p/idosos                |");
            }else if(blsala[var]<1){
            printf("\n\t| [5] bilhete p/idosos(INDISPONIVEL)  |");
            }

            printf("\n\t_______________________________________\n");
            scanf("%d",&opc);
            printf("\n\t_______________________________________\n");
            switch(opc){
                case(0): system("cls"); trocarPagina(pagina); break;
                case(1): comprabilhetes(var,1); system("cls"); trocarPagina(pagina);  break;
                case(2): comprabilhetes(var,2); system("cls"); trocarPagina(pagina);  break;
                case(3): comprabilhetes(var,3); system("cls"); trocarPagina(pagina); break;
                case(4): comprabilhetes(var,4); system("cls"); trocarPagina(pagina);  break;
                case(5): comprabilhetes(var,5); system("cls"); trocarPagina(pagina);  break;
                default: system("cls"); trocarPagina(pagina); break;
            }
            if( opc<0||opc>5){
                system("cls");
                printf("\n\tEscolha uma das op��es listadas!");
            }
        }while(opc<0 || opc>5);


    }else if(idade<60){
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t us�ario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
            printf("\n\t_______________________________________");
            printf("\n\t|   Bem vindo ao nosso museu          |");
            printf("\n\t_______________________________________\n");
            printf("\n\t|Escolha uma dos seguintes bilhetes   |");

            printf("\n\t| [0] Sair                            |");


            if(blsala[var]>0){
            printf("\n\t| [1] bilhete individual              |");
            }else if(blsala[var]<1){
            printf("\n\t| [1] bilhete individual(INDISPONIVEL)|");
            }


            if(blsala[var]>4){
            printf("\n\t| [2] 5 bilhetes                      |");
            }else if(blsala[var]<5){
            printf("\n\t| [2] 5 bilhetes(INDISPONIVEL)        |");
            }

            if(blsala[var]>9){
            printf("\n\t| [3] 10 bilhetes                     |");
            }else if(blsala[var]<10){
            printf("\n\t| [3] 10 bilhetes(INDISPONIVEL)       |");
            }

            if(blsala[var]>14){
            printf("\n\t| [4] 15 bilhetes                     |");
            }else if(blsala[var]<15){
            printf("\n\t| [4] 15 bilhetes(INDISPONIVEL)       |");
            }

            printf("\n\t_______________________________________\n");
            scanf("%d",&opc);
            printf("\n\t_______________________________________\n");
            switch(opc){
                case(0): system("cls"); trocarPagina(pagina); break;
                case(1): comprabilhetes(var,1); system("cls"); trocarPagina(pagina);  break;
                case(2): comprabilhetes(var,2); system("cls"); trocarPagina(pagina);  break;
                case(3): comprabilhetes(var,3); system("cls"); trocarPagina(pagina); break;
                case(4): comprabilhetes(var,4); system("cls"); trocarPagina(pagina);  break;
                default: system("cls"); trocarPagina(pagina); break;
            }
            if( opc<0||opc>4){
                system("cls");
                printf("\n\tEscolha uma das op��es listadas!");
            }
        }while(opc<0 || opc>4);
    }
    trocarPagina(pagina);
}


int trocarPagina(paginaNum){
    switch(paginaNum){
        case(1): system("cls"); printf("\n\tRegistrado com sucesso"); menuInicial(); break;
        case(2): system("cls"); menuInicial(); break;
        case(3): system("cls");
            if(paginaAnterior==0){
                menuInicial();
            }else if(paginaAnterior==2){
                menuPrincipal();
            } break;
        case(4): system("cls"); menuPrincipal(); break;
        case(5): system("cls"); menuPrincipal(); break;
        case(6): system("cls"); menuPrincipal(); break;
        case(7): system("cls"); menuPrincipal(); break;
        default: system("cls"); menuInicial(); break;
    }
}

void tema1(){
    pagina = 4;

    printf("\n\t\t\t\t 100 anos da semana de arte moderna:"
           "\n\n\t� poss�vel que voc� j� tenha ouvido falar sobre a Semana de Arte Moderna de 1922, principalmente nas aulas de portugu�s, hist�ria e artes, durante o ensino fundamental e m�dio. Mas o quanto e de quem voc� se lembra quando escuta sobre o assunto? Foi um movimento de artistas de todo o Brasil? Qual o motivo que levou essa semana ser considerada t�o importante?"
           "\n\n\tA Semana de Arte Moderna aconteceu em fevereiro de 1922, na cidade de S�o Paulo, 100 anos ap�s a Independ�ncia do Brasil, 34 anos ap�s a aboli��o da escravid�o e 4 anos ap�s o fim da Primeira Guerra Mundial. Nesse contexto, uma quest�o importante para os considerados intelectuais brasileiros era como o Brasil tinha se sa�do desses processos hist�ricos, principalmente comparando o pa�s com os Estados Unidos da Am�rica, que sa�ram da Primeira Guerra Mundial como uma grande pot�ncia. Al�m disso, as quest�es sociais, principalmente a aboli��o da escravid�o, recebiam pouco destaque nos trabalhos art�sticos. Assim, a Semana de Arte Moderna se apoiava no pensamento nacionalista e na busca de uma identidade para o Brasil, al�m da procura por uma produ��o art�stica mais liberta, que rompesse com uma est�tica das academias de Belas Artes e das ideias parnasianistas. As ideias parnasianistas tratavam da arte pela arte, privilegiavam a busca pela perfei��o e demonstravam pouca preocupa��o com os sentimentos humanos e os contextos sociais."
           "\n\n\tA Semana de Arte Moderna teve muitos envolvidos, como Anita Malfatti, Di Cavalcanti, Ferrignac (In�cio da Costa Ferreira), Zina Aita, M�rio de Andrade, Martins Ribeiro, Oswaldo Goeldi, Regina Graz, Oswald de Andrade, entre outros artistas e intelectuais majoritariamente paulistas.  O evento se tornou um dos marcos da cena cultural brasileira anos depois do seu acontecimento. Apesar de o evento ter sido pensado para acontecer durante uma semana completa, de 11 a 18 de fevereiro, na verdade a Semana de Arte Moderna s� esteve aberta ao p�blico durante os dias 13, 15 e 17, respectivamente segunda, quarta e sexta, de fevereiro de 1922, com programa��o tem�tica que passava pelas artes visuais, literatura e m�sica. Vale ressaltar, que os trabalhos expostos na Semana n�o tiveram uma recep��o positiva pelos intelectuais conservadores de S�o Paulo, pelo fato de romperem com as tradi��es art�sticas do per�odo. Por�m, essas rea��es, bem como as not�cias sobre a Semana, ocorreram majoritariamente em S�o Paulo, n�o ocorrendo grande repercuss�o a n�vel nacional."
           "\n\n\tApesar da celebra��o da Semana de Arte Moderna como um marco da arte no Brasil, � preciso olh�-la de forma tamb�m cr�tica. Pois, toda a ideia que temos em volta da Semana aconteceu principalmente por conta de uma constru��o posterior sobre o evento, a partir dos escritos de Lourival Gomes Machado no livro �Retrato Da Arte Moderna Do Brasil�, de 1946, que foi replicado, reconstru�do e chegou ao que se � comumente falado hoje. Em resumo, a Semana n�o foi um grande sucesso na �poca, mas o modo como foi retratada posteriormente garantiu seu lugar dentro da hist�ria do Brasil."
           "\n\n\tTalvez o mais importante quando se pensa no assunto � considerar que esse evento n�o deu e n�o d� conta de quem somos enquanto Brasil e da complexidade e diversidade dos olhares sobre o pa�s. A investida daqueles artistas foi interessante do ponto de vista formal, mas insuficiente no que se prop�s, principalmente quanto � constru��o de uma identidade nacional nas artes. A Semana de Arte Moderna foi elaborada por uma elite branca, em S�o Paulo, que teve a oportunidade de estudar arte dentro e fora do Brasil, influenciados por ideais que vieram tamb�m de fora, principalmente da Europa. Como menciona Cardoso (2022), o pr�prio M�rio de Andrade, que foi uma importante figura da Semana, criticou esse movimento em 1942 na confer�ncia �O movimento modernista� , dizendo que os artistas da Semana n�o captaram de fato o que acontecia no Brasil e fez pouco para mud�-lo na sua estrutura. Refor�ou, inclusive, que os artistas da Semana n�o devem servir de exemplo, mas de li��o."
           "\n\n\tAtualmente, os campos art�sticos buscam incorporar as pautas raciais, LGBTQIA+, de mulheres, ind�genas e outros grupos minorit�rios em suas produ��es, a partir do ponto de vista dessas pessoas, e n�o pelo olhar do outro, que foi o que prevaleceu na Semana de Arte Moderna. Nesse sentido, a presen�a dessas pessoas, discuss�es e pautas na produ��o art�stica expande nossa representa��o nas artes, tornando-as mais fi�is � grande mistura de gente que � o Brasil, sejam os trabalhos dessas pessoas relacionados � identidade de forma direta ou n�o. Mais do que celebrar a Semana de Arte Moderna, � importante entend�-la como de fato foi e se aproximar do que vem sendo produzido hoje nas diversas artes, n�o s� as visuais, mas tamb�m a dan�a, a m�sica, no centro e na periferia. Afinal, a hist�ria � feita no agora. Artistas contempor�neos como Rosana Paulino, Priscila Resende, S�rgio Adriano, Rosa Luz, Ventura Profana, U�ra Sodoma, Denilson Baniwa, Isael Maxakali, Sallisa Rosa, Daiely Gon�alves e Yan Nicolas S�o Thiago s�o apenas alguns dos que merecem nossa aten��o."
           "\n\n\t[Texto de autoria de Abra�o Veloso Machado, aluno do curso de Artes Visuais  e estagi�rio do N�cleo de A��es Educativas do Espa�o do Conhecimento UFMG]"
           "\n\tdados n�o foram elaborados por nossa equipe mas sim retirados do site: https://www.ufmg.br/espacodoconhecimento/100-anos-da-semana-de-arte-moderna-celebracao-ou-reflexao/");



    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }

}
void tema2(){
    pagina = 5;

     printf("\n\t\t\t\t 150 anos de Santos Dumont:"
        "\n\n\t\t\t\t Sua vida"
        "\n\n\t H� 150 anos, nascia no interior de Minas Gerais um dos maiores inventores brasileiros: o not�vel Alberto Santos Dumont, considerado um dos precursores da avia��o e da cria��o de aeronaves no mundo."
        "\n\n\tA hist�ria de vida, as obras e os valores do Pai da Avia��o e Patrono da Aeron�utica Brasileira s�o fontes de inspira��o n�o s� no nosso pa�s, mas em v�rias regi�es do planeta. Suas inova��es e contribui��es para a avia��o s�o celebradas at� hoje."
        "\n\n\tO homem que deu asas � humanidade nasceu no dia 20 de julho de 1873, no s�tio Cabangu � local que, em 1890, passou a pertencer ao munic�pio de Palmyra (MG), um dos bens tombados sob tutela da For�a A�rea Brasileira (FAB)."
        "\n\n\tFilho de Francisca Santos Dumont, de tradicional fam�lia portuguesa vinda para o Brasil com D. Jo�o VI, em 1808, e de Henrique Dumont, engenheiro civil de obras p�blicas e, mais tarde, cafeicultor em Ribeir�o Preto (SP). Henrique Dumont, de ascend�ncia francesa, teve papel fundamental na trajet�ria do filho Alberto, pois, percebendo nele o fasc�nio pelas m�quinas � que existiam em grande quantidade na fazenda Arindi�va �, direcionou os estudos do rapaz para a mec�nica, a f�sica, a qu�mica e a eletricidade, n�o fazendo quest�o que ele se formasse em engenharia, como foi o caso dos outros filhos."
        "\n\n\tO sonho de voar de Alberto surgiu aos 15 anos quando ele teve uma vis�o: um bal�o livre nos c�us de S�o Paulo. No caso, bal�es livres s�o aqueles que fazem sua ascens�o sem possuir nenhum tipo de dirigibilidade, ficando ao sabor das correntes a�reas."
        "\n\n\tAos 18 anos, emancipado pelo pai, Alberto foi para Paris completar os estudos e perseguir o seu sonho de voar. Ao chegar � capital francesa, o jovem se admira com os motores de combust�o interna a petr�leo que come�avam a aparecer impulsionando os primeiros autom�veis e compra um para si, investigando todo o seu funcionamento. Logo estava promovendo e disputando as primeiras corridas de autom�veis na Cidade-Luz."
        "\n\n\tEm 31 de julho de 1932, a cidade de Palmyra, em Minas Gerais, passou a denominar-se Santos Dumont, em homenagem ao Pai da Avia��o."
        "\n\n\t\t\t\t Sua obra"
        "\n\n\t Um verdadeiro her�i da engenhosidade. A obra do brasileiro Santos Dumont est� diretamente vinculada a v�rias inova��es. O filho de Francisca e Henrique Dumont viveu em um per�odo de grandes revolu��es na tecnologia e foi o nosso maior protagonista dos ares."
        "\n\n\tAos 24 anos, Santos Dumont tinha sua primeira decolagem bem sucedida a bordo de um bal�o livre alugado. Um ano depois, em 1898, projeta e constr�i, com a ajuda de oper�rios e construtores de bal�es franceses, seu primeiro bal�o livre: o Brasil, o menor bal�o tripulado j� feito, homenageando sua p�tria. Logo em seguida, associando os leves motores de combust�o interna a petr�leo a seus leves bal�es e construindo engenhosos lemes, Santos Dumont inventa os bal�es dirig�veis."
        "\n\n\tEm 1901, Santos Dumont pilotou seu bal�o, o N�mero 6, que era movido a gasolina, sobre Paris, e ganhou um pr�mio de 100 mil francos por seu feito. As suas realiza��es foram frutos de sucesso na imprensa europeia, na imprensa norte-americana e no Brasil. O inventor, nesse momento, torna-se o centro das aten��es, despertando o interesse militar para seus bal�es."
        "\n\n\tAp�s o sucesso com bal�es e dirig�veis, Santos Dumont partiu para outra linha de pesquisa: queria, agora, voar com um ve�culo mais pesado que o ar. O prot�tipo era composto por uma fuselagem longa, com a nacele do bal�o n�mero 14 na parte de tr�s � um biplano com uma constru��o parecida com pipas japonesas, portando um motor de oito cilindros e sobre tr�s rodas: o primeiro trem de pouso que se tem not�cia. A inova��o era pulsante desde os testes. O aviador construiu um sistema de cabos inclinados para testar a dirigibilidade do 14-Bis: um inovador simulador de voo."
        "\n\n\tEm 1905, na plateia de uma corrida de lanchas num quente ver�o no Rio Sena, Santos Dumont avista uma potente lancha com motor Antoinette de 24 HP e come�a a� a planejar �o mais pesado que o ar�. Aproveitando o sucesso dos planadores e, em especial, o planador com c�lulas de Hargrave, o inventor constr�i o primeiro avi�o, o 14-Bis, com o motor Antoinette, usando o bal�o n� 14 para testes de estabilidade."
        "\n\n\tFoi no dia 7 de setembro de 1906 que o 14-Bis deu um primeiro salto no ar, mas faltou pot�ncia. J� em 23 de outubro, com motor Antoinette de 50 HP, o 14 Bis voou, decolando, mantendo-se no ar por uma dist�ncia de 60 metros, a tr�s metros de altura, e aterrissou. Era o primeiro voo homologado do �mais pesado que o ar� para uma multid�o de testemunhas euf�ricas no campo de Bagatelle, em Paris. No dia seguinte, toda a imprensa francesa louvou o fato hist�rico, o triunfo de um obstinado brasileiro, que, pelo feito, conquistou o pr�mio Archdeacon oferecido pelo Aeroclube de Fran�a. O dinheiro do pr�mio foi distribu�do para seus oper�rios e os pobres de Paris, como era o costume do inventor."
        "\n\n\tAssim, Santos Dumont se tornou uma celebridade conhecida mundialmente e continuou a trabalhar em avi�es, tendo feito muitas outras contribui��es importantes para a avia��o. Em 1909, ele voou em seu avi�o Demoiselle, um dos primeiros aeroplanos do mundo, e que se tornou um sucesso comercial. Santos Dumont tamb�m trabalhou em melhorias no design do avi�o, como a adi��o de cauda vertical para melhor estabilidade e controle."
        "\n\n\tSantos Dumont recebeu diversas homenagens por toda a Europa, nos EUA, na Am�rica Latina e, em especial, no Brasil, onde foi recebido com festas e euforia. Seus projetos foram aperfei�oados por outros aviadores e projetistas, j� que ele n�o os patenteava e n�o desejava adquirir bens materiais com suas inven��es, mas idealizava dotar a humanidade com meios de facilitar as comunica��es, desgostando-se com o uso agressivo que o avi�o teve na Primeira Guerra Mundial."
        "\n\n\tComo podemos observar, Santos Dumont dedicou sua vida � avia��o. Foi o primeiro aeronauta a alcan�ar, definitivamente, a dirigibilidade dos bal�es e a voar num aparelho mais pesado que o ar com propuls�o pr�pria. O desenvolvimento da avia��o ensejou a cria��o do Minist�rio da Aeron�utica e, desde ent�o, com o avan�o da tecnologia, a For�a A�rea Brasileira tem renovado seus vetores. Foram suas ideias e seus feitos que tornaram poss�vel, hoje, nas Asas que protegem o Pa�s, a atua��o da nossa For�a em diversas miss�es nacionais e internacionais."
        "\n\n\tdados n�o foram elaborados por nossa equipe mas sim retirados do site: https://www.fab.mil.br/santosdumont150anos/");

    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }
}
void tema3(){
    pagina = 6;

    printf("\n\t\t\t\t Ol�mpiadas de 2024 em Paris:"
        "\n\n\tJogos Ol�mpicos de 2024 (em franc�s: Les Jeux olympiques d'�t� de 2024) conhecidos oficialmente como os Jogos da XXXIII Olimp�ada, comumente chamado Paris 2024, � um evento multiesportivo futuro a ser realizado no segundo semestre de 2024, na cidade de Paris (capital da Fran�a). Ser� a terceira vez que a cidade ser� sede dos jogos (j� o tinha sido em 1900 e 1924). No total esta ser� a sexta edi��o dos Jogos Ol�mpicos realizados na Fran�a. O pa�s ainda sediou os Jogos Ol�mpicos de Inverno de 1924, em Chamonix, os Jogos Ol�mpicos de Inverno de 1968, em Grenoble e mais recentemente os Jogos Ol�mpicos de Inverno de 1992, na Sav�ia."
        "\n\n\tOs Jogos de 2024 ser�o a primeira edi��o fora de um pais do Extremo Oriente em seis anos e a primeira na Uni�o Europeia em doze anos - Londres sediou os Jogos Ol�mpicos de Ver�o de 2012 -, seguindo-se os Jogos Ol�mpicos de Inverno de 2018, em Pyeongchang, Coreia do Sul, aos Jogos Ol�mpicos de Ver�o de 2020, realizados em 2021, em T�quio, capital do Jap�o, e os Jogos Ol�mpicos de Inverno de 2022, que realizados em Pequim, capital da Rep�blica Popular da China. Paris e Los Angeles foram as cidades candidatas."
        "\n\n\t\t\t Candidatura de Paris:"
        "\n\n\tA capital francesa foi a primeira cidade a anunciar que estava interessada em receber os Jogos Ol�mpicos de Ver�o de 2024, e anunciou a sua inten��o em 23 de junho de 2015, a data em que � celebrado o Dia Ol�mpico. O ex-ministro franc�s, Jean-Francois Lamour, percebeu que 2024 seria um ano chave para encaixar com o centen�rio da �ltima vez em que os Jogos foram realizados na cidade e tamb�m o centen�rio dos Jogos Ol�mpicos de Inverno franceses gostariam muito disso. O tricampe�o ol�mpico de canoagem slalom Tony Estanguet que � um dos presidentes do Comit� Organizador disse em uma entrevista ao canal RTL que a cidade iria vencer de qualquer jeito.[7] A cidade deve investir por volta de 35 milh�es de euros na constru��o de novos locais de competi��o.[8][9][10]"
        "\n\n\tEm 8 de Novembro de 2014, a prefeita de Paris, Anne Hidalgo, percebeu que os Jogos de 2024 seriam muito caros para a cidade, alegando que, 'N�s n�o estamos em uma boa situa��o financeira e or�amental para garantir esta candidatura.' e que a estava sendo avaliada uma potencial candidatura para os Jogos Ol�mpicos de Ver�o de 2028."
        "\n\n\tEntretanto, cinco meses depois em Mar�o de 2015, Hidalgo autorizou � candidatura. No dia 14 de abril do mesmo ano, os conselheiros da cidade de Paris aceitaram a proposta e a cidade assim se tornou a primeira cidade postulante aos Jogos de 2024. Desde ent�o, Hidalgo se posicionou como uma das principais apoiadoras da candidatura. Ela e o ent�o presidente da Fran�a, Fran�ois Hollande, fizeram parte da comitiva da cidade durante os Jogos Ol�mpicos de Ver�o de 2016 no Rio de Janeiro ."
        "\n\n\tEm 26 de junho de 2015, a Federa��o Francesa de Vela anunciou que iria realizar um processo de sele��o para a sede do esporte. Seis cidades?Le Havre (Seine-Maritime), La Rochelle, Brest, Hy�res, Marselha,Bouches-du-Rh�ne e Quiberon manifestaram o seu interesse. Em 7 de setembro de 2015, foi anunciado que Marselha foi escolhida com a subsede da vela."
        "\n\n\tEm 9 de fevereiro de 2016, Paris revelou o logotipo de sua candidatura por meio de uma proje��o no Arco do Triunfo, exatamente �s 20:24, sendo o logotipo uma vers�o multicolorida da Torre Eifel com as inscri��es Paris 2024, Cidade Candidata aos Jogos Ol�mpicos de Ver�o de 2024, e ao mesmo tempo ele foi revelado tamb�m na prefeitura de Marselha ."
        "\n\n\tEm 12 de novembro de 2016, Anne Hidalgo e o judoca multimedalhista Teddy Riner lideraram a delega��o da cidade para uma apresenta��o de Paris para os membros de Comit� Ol�mpico Internacional e l�deres desportivos durante a Feira SportAccord em Doha, Qatar."
        "\n\n\tEm janeiro de 2017, o Comit� de Paris prop�s reduzir as suas emiss�es de carbono em mais de metade em compara��o com Londres e ao Rio de Janeiro e assim realizar os 'Jogos mais sustent�veis da hist�ria '.. Para a apresenta��o da terceira e �ltima parte do seu projeto, a Torre Eiffel foi adornada com as cores ol�mpicas em 3 de fevereiro de 2017. Essa ilumina��o especial foi feita para anunciar o slogan da candidatura da cidade: 'Feita para compartilhar'."
        "\n\n\tEm fevereiro de 2017, lideradas por Denis Coderre, prefeito de Montreal, mais de 50 cidades anunciaram seu apoio � candidatura de Paris 2024, incluindo sedes anteriores como Sydney, Atenas, Cidade do M�xico, Barcelona e T�quio."
        "\n\n\tNo final de fevereiro, a prefeita Hidalgo foi a T�quio para conhecer a governadora da regiao metropolitana, Yuriko Koike com base a um intercambio entre os stakeholders das duas cidades ."
        "\n\n\tParis sediou anteriormente Jogos Ol�mpicos de Ver�o de 1900 e os Jogos Ol�mpicos de Ver�o de 1924. A cidade � segunda na hist�ria a receber os Jogos Ol�mpicos de Ver�o oficialmente tr�s vezes (a primeira foi Londres em 1908, 1948 e 2012). O ano de 2024 tamb�m marca o centen�rio da �ltima vez que a cidade tinha sediado os Jogos, e tamb�m o primeiro centen�rio dos Jogos Ol�mpicos de Inverno que foram disputados em Chamonix. Al�m disso, ser� a sexta vez que os Jogos ser�o disputados na Fran�a, sendo a terceira de ver�o. Os Jogos Ol�mpicos ser�o disputados de 26 de julho a 11 de agosto de 2024 e os Jogos Paral�mpicos de 4 a 15 de setembro do mesmo ano."
        "\n\n\tdados n�o foram elaborados por nossa equipe mas sim retirados do site: https://pt.wikipedia.org/wiki/Jogos_Ol%C3%ADmpicos_de_Ver%C3%A3o_de_2024"
    );

    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }
}
void tema4(){
    pagina = 7;

    printf("\n\t\t\t\t 200 anos de independ�ncia do brasil:"
            "\n\n\tA independ�ncia do Brasil foi um processo iniciado a partir da Revolu��o Liberal do Porto, que levou ao rompimento entre Brasil e Portugal, no dia 7 de setembro de 1822."
            "\n\n\tA independ�ncia do Brasil aconteceu em 1822, tendo como grande marco o grito da independ�ncia que foi realizado por Pedro de Alc�ntara (D. Pedro I durante o Primeiro Reinado), �s margens do Rio Ipiranga, no dia 7 de setembro de 1822. Com a independ�ncia do Brasil declarada, o pa�s transformou-se em uma monarquia com a coroa��o de D. Pedro I."
            "\n\n\t\t\t Causas da independ�ncia do Brasil"
            "\n\n\t A independ�ncia do Brasil foi declarada em 1822 e esse acontecimento est� diretamente relacionado com eventos que foram iniciados em 1808, ano em que a fam�lia real portuguesa, fugindo das tropas francesas que invadiram Portugal, mudou-se para o Brasil."
            "\n\n\tA chegada da fam�lia real no Brasil ocasionou uma s�rie de mudan�as que contribuiu para o desenvolvimento comercial, econ�mico e, em �ltima inst�ncia, possibilitou a independ�ncia do Brasil. Al�m disso, o Brasil experimentou, em seus centros, um grande desenvolvimento resultado de uma s�rie de medidas implementadas por D. Jo�o VI, rei de Portugal."
            "\n\n\tInstalado no Rio de Janeiro, o rei portugu�s autorizou a abertura dos portos brasileiros �s na��es amigas, permitiu o com�rcio entre os brasileiros e os ingleses como medidas de destaque no �mbito econ�mico."
            "\n\n\tEssas e outras medidas que foram tomadas pelo rei portugu�s demonstravam uma clara inten��o de modernizar o pa�s como parte de uma proposta que fizesse o Brasil deixar de ser apenas uma col�nia portuguesa, tornando-se, de fato, parte integrante do Reino de Portugal. Isso foi confirmado quando, em 16 de dezembro de 1815, D. Jo�o VI decretou a eleva��o do Brasil para parte do Reino Unido."
            "\n\n\tIsso, na pr�tica, significou que o Brasil deixava de ser uma col�nia e transformava-se em parte integrante do Reino portugu�s, que agora passava a ser chamado de Reino Unido de Portugal, Brasil e Algarves. Essa medida era importante para o Brasil e, segundo as historiadoras Lilia Schwarcz e Helo�sa Starling, a medida tinha como objetivo principal evitar que o Brasil seguisse pelo caminho da fragmenta��o revolucion�ria � como havia acontecido na rela��o entre EUA e Inglaterra"
            "\n\n\tA presen�a da fam�lia real no Brasil havia proporcionado grandes avan�os, mas, ainda assim, demonstra��es de insatisfa��o aconteceram por meio da Revolu��o Pernambucana de 1817. A mudan�a da fam�lia real para o Brasil havia resultado em grande aumento de impostos e interferido diretamente na administra��o da capitania."
            "\n\n\tA Revolu��o Pernambucana de 1817 foi reprimida violentamente. Tr�s anos depois dessa repress�o, o rei D. Jo�o VI teve de lidar com insatisfa��es em Portugal que se manifestaram em Revolu��o Liberal do Porto de 1820. Esse foi o ponto de partida do processo de independ�ncia do Brasil."
            "\n\n\tPortugal vivia uma forte crise, tanto pol�tica quanto econ�mica, em consequ�ncia da invas�o francesa. Al�m disso, havia uma forte insatisfa��o em Portugal por conta das transforma��es que estavam acontecendo no Brasil, sobretudo com a liberdade econ�mica que o Brasil havia conquistado com as medidas de D. Jo�o VI."
            "\n\n\tA Revolu��o Liberal do Porto eclodiu em 1820 e foi organizada pela burguesia portuguesa inspirada em ideais liberais. Um dos grandes objetivos dos portugueses era o retorno do rei para Portugal. Na vis�o da burguesia portuguesa, Portugal deveria ser a sede do Imp�rio portugu�s."
            "\n\n\tOutra reivindica��o importante dos portugueses foi a exig�ncia de restabelecimento do monop�lio comercial sobre o Brasil. Essa exig�ncia causou grande insatisfa��o no Brasil, uma vez que demonstrava a inten��o dos portugueses em permanecer com os la�os coloniais em rela��o ao Brasil. O rei portugu�s, pressionado pelos acontecimentos em seu pa�s, resolveu retornar para Portugal em 26 de abril de 1821."
            "\n\n\tNa viagem de D. Jo�o VI, cerca de quatro mil pessoas retornaram para Portugal. O rei portugu�s, al�m disso, levou para Portugal uma grande quantidade de ouro e diamantes que estavam nos cofres do Banco do Brasil. Com o retorno de D. Jo�o VI, Pedro de Alc�ntara tornou-se regente do Brasil."
            "\n\n\tdados n�o foram elaborados por nossa equipe mas sim retirados do site: https://brasilescola.uol.com.br/historiab/independencia-brasil.htm"

);


    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }
}


int main(){
    pagina=0;
    setlocale(LC_ALL,"");


    menuInicial();
    return 0;
}
