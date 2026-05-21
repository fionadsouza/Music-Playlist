#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char artist[100];
    char song[100];
    int duration;
    struct node *prev;
    struct node *next;
};




struct node *addend(struct node *head){
    struct node *temp = malloc(sizeof(struct node));
    printf("enter name of the song \n");
    fgets(temp->song, sizeof(temp->song), stdin);
    temp->song[strcspn(temp->song, "\n")] = 0;

    printf("enter name of the artist \n");
    fgets(temp->artist, sizeof(temp->artist), stdin);
    temp->artist[strcspn(temp->artist, "\n")] = 0;

    printf("enter the duration \n");
    scanf("%d",&temp->duration);

    while(getchar() != '\n'); //This line is used to clear the input buffer in C

    temp->next = NULL;
    temp->prev = NULL;

    if(head==NULL){
        printf("\n music playlist is empty \n");
        head=temp;
        return head;
    }

    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    return head;


}


void display(struct node *head){
    if(head==NULL){
        printf("\n playlist is empty \n");
        return;
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("\nSong     : %s", ptr->song);
        printf("\nArtist   : %s", ptr->artist);
        printf("\nDuration : %d", ptr->duration);
        printf("\n----------------------\n");
        ptr=ptr->next;
    }

}

void count(struct node *head){
    struct node *ptr=head;
    int count=0;
    while(ptr!=NULL){
        count++;
        printf("\ncount=%d",count);
        printf("\nSong     : %s", ptr->song);
        printf("\nArtist   : %s", ptr->artist);
        printf("\nDuration : %d", ptr->duration);
        
        
        printf("\n----------------------\n");
        ptr=ptr->next;
    }
}

void search_song(struct node *head){
    char search[100];
    
    if(head==NULL){
        printf("\n playlist is empty \n");
        return;
    }

    printf("\n enter the song to be searched \n");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;
   

    struct node *ptr=head;

    while(ptr!=NULL){
        if(strcmp(ptr->song,search)==0){
            printf("\nSong Found!\n");

            printf("Song     : %s\n", ptr->song);
            printf("Artist   : %s\n", ptr->artist);
            printf("Duration : %d\n", ptr->duration);

            return;
        }

        ptr = ptr->next;
        
    }
    printf("\nsong not found\n");
}


struct node *deletenode(struct node *head){
    if(head==NULL){
        printf("\n playlist is empty \n");
        return head;
    }

    char name[100];

    printf("\n enter the song to be deleted \n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    struct node *ptr=head;

    while(ptr!=NULL){
        if(strcmp(ptr->song,name)==0){
            if(ptr->prev==NULL && ptr->next==NULL){
                head=NULL;
            }
            
            else if(ptr->prev==NULL){
                head=head->next;
                head->prev=NULL;
                
            }
            else if(ptr->next==NULL){
                ptr->prev->next=NULL;
            }

            else{
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }


            free(ptr);
            printf("\n song has been deleted successfully \n");
            return head;
            
            

        }
        ptr=ptr->next;
       
    }
    printf("\n song not found \n");
    return head;
}


    

int main(){
    struct node *head=NULL;
    int ch;

    while(1){
    printf("1.add a song,artist and the duration\n2.display\n3.search\n4.delete\n5.count\n6.exit\n");
    printf("select your choice\n");
    scanf("%d",&ch);
    while(getchar() != '\n');

    switch(ch){
        case 1:
        head=addend(head);
        break;

        case 2:
        display(head);
        break;

        case 3:
        search_song(head);
        break;

        case 4:
        head=deletenode(head);
        break;

        case 5:
        count(head);
        break;

        case 6:
        exit(0);
        

        default:
        printf("invalid choice");
    }
    }
    return 0;
}