#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
} Book;

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    getchar(); // consume newline

    Book books[n];

    // Input book details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);

        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar(); // consume newline
    }

    // Save to file
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n%s\n%.2f\n", books[i].title, books[i].author, books[i].price);
    }
    fclose(file);
    printf("\nBook details saved to 'books.txt' successfully!\n");

    // Read and display from file
    file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\nSaved Book Details:\n");
    for (int i = 0; i < n; i++) {
        fgets(books[i].title, sizeof(books[i].title), file);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        fgets(books[i].author, sizeof(books[i].author), file);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        fscanf(file, "%f\n", &books[i].price);

        printf("\nBook %d:\nTitle: %s\nAuthor: %s\nPrice: %.2f\n", i + 1, books[i].title, books[i].author, books[i].price);
    }
    fclose(file);

    return 0;
}