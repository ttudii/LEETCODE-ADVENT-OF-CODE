#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct poker{
    char card[6];
    int bid;
    int pair;
};

// Funcție de comparare a două caractere în funcție de vectorul ordonat
int compareCaractere(char *a, char *b) {
    return a-b;
}


int compare(char* sir1,char* sir2, const char* vectorOrdonat) {
    while (*sir1 != '\0' && *sir2 != '\0') {

        char* pozitieCaracter1 = strchr(vectorOrdonat, *sir1);
        char* pozitieCaracter2 = strchr(vectorOrdonat, *sir2);

        int rezultatComparare = compareCaractere(pozitieCaracter1, pozitieCaracter2);

        if (rezultatComparare != 0) {
            return rezultatComparare;
        }

        sir1++;
        sir2++;
    }

    return 0;
}

int main(){

    struct poker *player;

    const char v[14]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

    int i,j,k,o,q,t;
    int three_of_a_kind;
    int two_pair;
    int frecv[5];

    player=(struct poker *)malloc(sizeof(struct poker)*1000);

    for(i=0;i<1000;i++){
        scanf("%s",player[i].card);
        scanf("%d",&player[i].bid);
    }

    for(i=0;i<1000;i++){
        char temp[6];
        strcpy(temp,player[i].card);

        three_of_a_kind=0;
        two_pair=0;

        for(q=0;q<5;q++) frecv[q]=1;

        for(j=0;j<5;j++){
            for(k=j+1;k<5;k++){
                if(*(temp+j)!='-'){
                    if(*(temp+j)==*(temp+k))
                    {
                        *(temp+k)='-';
                        frecv[j]=frecv[j]+1;
                    }
                }
            }
            //printf("%d ",frecv[j]);
        }
        //printf("\n");

        for(q=0;q<5;q++){
            if(frecv[q]==5) 
            {
                    player[i].pair=7;
                    break;
            }
        }

            for(q=0;q<5;q++){
                if(frecv[q]==4) 
                {
                    player[i].pair=6;
                    break;
                }
            }
            
            for(q=0;q<5;q++){
                if(frecv[q]==3) 
                {
                    t=0;
                    while(t<5 && frecv[t]!=2){
                        t+=1;
                    }
                if(t==5)
                    three_of_a_kind=-1;
                else
                if(t!=5)
                    three_of_a_kind=1;
                }
           
            }

            if(three_of_a_kind==1) player[i].pair=5;
            else
            if(three_of_a_kind==-1) player[i].pair=4;


            for(q=0;q<5;q++){
                if(frecv[q]==2) 
                {
                    for(t=q+1;t<5;t++){
                        if(frecv[t]==2) {
                            two_pair=1;
                            goto skip;
                        }
                    }

                    for(t=0;t<5 && frecv[t]!=3;t++){
                        ;
                    }
                    
                    if(t==5) two_pair=-1;

                }
            }

            skip:

            if(two_pair==1) player[i].pair=3;
            else
            if(two_pair==-1) player[i].pair=2;
            

            for(o=0;o<5 && frecv[o]==1;o++)
                ;
            if(o==5) player[i].pair=1;


    }

    //printf("\n\n%s %d %d\n",player[996].card,player[996].bid,player[996].pair);

    struct poker change;
    int poz=1;

    for(i=0;i<1000;i++){
        for(j=i+1;j<1000;j++){
            if(player[i].pair>player[j].pair)
            {
                change=player[i];
                player[i]=player[j];
                player[j]=change;
            }
        }
    }

    while(poz<=7){
        for(i=0;i<1000;i++){
            if(player[i].pair==poz){
                for(j=i+1;j<1000;j++){
                    if(player[j].pair==poz && compare(player[i].card,player[j].card,v)>0){
                        change=player[i];
                        player[i]=player[j];
                        player[j]=change;
                    }

                }

            }
        }
        poz++;
    }

    printf("\n\n\n");


    for(i=0;i<1000;i++) printf("%s %d %d\n",player[i].card,player[i].bid,player[i].pair);

    int sum=0;

    for(i=0;i<1000;i++) 
    {
    sum=sum+(i+1)*player[i].bid;
    }

    printf("\n\n\n");

    printf("%d",sum);

    return 0;
}



//strcmp intre sirurile care au acelasi pair
//ordonare crescatoare
//suma formata cu elemente de forma: bid*indice, indice=pozitie in noul vector dupa ordonare+1
