#include <stdio.h>
#include <string.h>

typedef struct Books{
    int id, price;
    char title[100];
}book_t;

void total_price(book_t this_books[], int amount){
    int total=0;
    for(int i=0; i<amount;i++){
        total+=this_books[i].price;
    }
    printf("%d", total);
}

void list_books(book_t this_books){
    printf("%d ", this_books.price);
    printf("%s", this_books.title);
}


int main()
{
    book_t books[6];
    int input=0;
    
    for(int i=1; i<=6; i++){
        books[i-1].id = i;
    }
    
    books[0].price = 1000;
    books[1].price = 300;
    books[2].price = 1000;
    books[3].price = 550;
    books[4].price = 870;
    books[5].price = 1344;
    
    strcpy(books[0].title,"All the Light We Cannot See");
    strcpy(books[1].title,"The 38 Letters from J.D. Rockefeller to his son");
    strcpy(books[2].title, "The Ballad of Songbirds and Snakes");
    strcpy(books[3].title, "Killers of the Flower Moon");
    strcpy(books[4].title, "Elon Musk");
    strcpy(books[5].title, "Milk and Honey 12-Month 2024");
    
    scanf("%d", &input);
    if(input == 0){
        total_price(books, 6);
    }
    else if (input>0 && input<=6){
        list_books(books[input-1]);
    }
    
    
    return 0;
}
