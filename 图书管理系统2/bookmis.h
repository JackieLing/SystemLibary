typedef struct
{
	char isbn[20];
	char name[50];
	char author[20];
	int price[100];

}Book;
typedef struct
{
	Book *elem;
	int length;

}BookList; 
void LocateBook(BookList L);
void Deletebyname(BookList &L);
void Printf(BookList &L);