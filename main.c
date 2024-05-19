#include <stdbool.h>
#include <stdio.h>
int A_SeatList[ ] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int B_SeatList[ ] = {0,0,0,0,0,0,0,0,0,0,0,0};
int C_SeatList[ ] = {0,0,0,0,0,0,0,0,0,0,0,0};
int D_SeatList[ ] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void buySeat(){
    char SeatRow;
    int SeatNumber;
    printf("\n\n     Buying Seat....");
    printf("\nEnter the Seat Row: ");
    scanf("%s", &SeatRow);
    printf("\nEnter the Seat Number: ");
    scanf("%d",&SeatNumber);
    if(SeatRow == 'A' || SeatRow == 'a'){
        if (A_SeatList[SeatNumber - 1 ] == 0){
            A_SeatList[SeatNumber - 1 ] = 1;
            printf("\nSeat booked successfully. ");
        }else{
            printf("\nPlease select different seat. \nThis seat already booked.");
            buySeat();
        }
    }else if(SeatRow == 'B' || SeatRow == 'b'){
        if (B_SeatList[SeatNumber - 1 ] == 0){
            B_SeatList[SeatNumber - 1 ] = 1;
            printf("\nSeat booked successfully. ");
        }else{
            printf("\nPlease select different seat. \nThis seat already booked.");
            buySeat();
        }
    }else if(SeatRow == 'C' || SeatRow == 'c'){
        if (C_SeatList[SeatNumber - 1 ] == 0){
            C_SeatList[SeatNumber - 1 ] = 1;
            printf("\nSeat booked successfully. ");
        }else{
            printf("\nPlease select different seat. \nThis seat already booked.");
            buySeat();
        }
    }else if(SeatRow == 'D' || SeatRow == 'd'){
        if (D_SeatList[SeatNumber - 1 ] == 0){
            D_SeatList[SeatNumber - 1 ] = 1;
            printf("\nSeat booked successfully. ");
        }else{
            printf("\nPlease select different seat. \nThis seat already booked.");
            buySeat();
        }
    }else{
        printf("Enter the correct seat row.");
        buySeat();
    }
}
void cancelSeat(){
    char cancelSeatRow;
    int cancelSeatnumber;
    printf("\nEnter the seat row you want to cancel (A-D): ");
    scanf(" %s", &cancelSeatRow);
    printf("\nEnter the seat number you want to cancel: ");
    scanf("%d", &cancelSeatnumber);
    switch(tolower(cancelSeatRow)) {
        case 'a':
            if (A_SeatList[cancelSeatnumber - 1] == 1) {
                printf("Seat successfully canceled.\n");
                A_SeatList[cancelSeatnumber - 1] = 0;
            } else {
                printf("The seat is already free.\n");
            }
            break;
        case 'b':
            if (B_SeatList[cancelSeatnumber - 1] == 1) {
                printf("Seat successfully canceled.\n");
                B_SeatList[cancelSeatnumber - 1] = 0;
            } else {
                printf("The seat is already free.\n");
            }
            break;
        case 'c':
            if (C_SeatList[cancelSeatnumber - 1] == 1) {
                printf("Seat successfully canceled.\n");
                C_SeatList[cancelSeatnumber - 1] = 0;
            } else {
                printf("The seat is already free.\n");
            }
            break;
        case 'd':
            if (D_SeatList[cancelSeatnumber - 1] == 1) {
                printf("Seat successfully canceled.\n");
                D_SeatList[cancelSeatnumber - 1] = 0;
            } else {
                printf("The seat is already free.\n");
            }
            break;
        default:
            printf("Invalid seat row. Please enter a row between A and D.\n");
            break;
    }
}

void showseatingPlan(){
    printf("\nSeating Plan:\n");
    printf("Row A: ");
    for (int i = 0; i < sizeof(A_SeatList) / sizeof(A_SeatList[0]); i++) {
        printf(A_SeatList[i] == 0 ? "0 " : "X ");
    }
    printf("\nRow B: ");
    for (int i = 0; i < sizeof(B_SeatList) / sizeof(B_SeatList[0]); i++) {
        printf(B_SeatList[i] == 0 ? "0 " : "X ");
    }
    printf("\nRow C: ");
    for (int i = 0; i < sizeof(C_SeatList) / sizeof(C_SeatList[0]); i++) {
        printf(C_SeatList[i] == 0 ? "0 " : "X ");
    }
    printf("\nRow D: ");
    for (int i = 0; i < sizeof(D_SeatList) / sizeof(D_SeatList[0]); i++) {
        printf(D_SeatList[i] == 0 ? "0 " : "X ");
    }
    printf("\n");
}
void FirstSeat(){
    for (int i = 0; i < sizeof(A_SeatList) / sizeof(A_SeatList[0]); i++) {
        if(A_SeatList[i] == 0 ){
            printf("First Available Seat is: A%d\n", i + 1);
            return; // Stop further checks once the first available seat is found
        }
    }
    for (int i = 0; i < sizeof(B_SeatList) / sizeof(B_SeatList[0]); i++) {
        if(B_SeatList[i] == 0){
            printf("First Available Seat is: B%d\n", i + 1);
            return;
        }
    }
    for (int i = 0; i < sizeof(C_SeatList) / sizeof(C_SeatList[0]); i++) {
        if(C_SeatList[i] == 0){
            printf("First Available Seat is: C%d\n", i + 1);
            return;
        }
    }
    for (int i = 0; i < sizeof(D_SeatList) / sizeof(D_SeatList[0]); i++) {
        if(D_SeatList[i] == 0){
            printf("First Available Seat is: D%d\n", i + 1);
            return;
        }
    }
    printf("No available seats.\n");
}
void SearchTicket(){
    char searchRow;
    int searchNumber;
    printf("\nEnter the you want search ticket row: ");
    scanf("%s", &searchRow);
    printf("\nEnter the seat number you want search: ");
    scanf("%d", &searchNumber);
    if(searchRow == 'A' || searchRow == 'a'){
        if(A_SeatList[searchNumber-1] == 0){
            printf("\nSeat is free.");
        }else{
            printf("\nSeat is Booked.");
        }
    }else if(searchRow == 'B' || searchRow == 'b'){
        if(A_SeatList[searchNumber-1] == 0){
            printf("\nSeat is free.");
        }else{
            printf("\nSeat is Booked.");
        }
    }else if(searchRow == 'C' || searchRow == 'c'){
        if(A_SeatList[searchNumber-1] == 0){
            printf("\nSeat is free.");
        }else{
            printf("\nSeat is Booked.");
        }
    }else if(searchRow == 'D' || searchRow == 'd'){
        if(A_SeatList[searchNumber-1] == 0){
            printf("\nSeat is free.");
        }else{
            printf("\nSeat is Booked.");
        }
    }else{
        printf("\nEnter the correct seat row.");
    }
}
int main(void) {
    int option;
    while (true) {
        printf("\n\n--------------Main Menu-------------");
        printf("\n01) Buy Seat.");
        printf("\n02) Cancel Seat.");
        printf("\n03) Find First Available Seat.");
        printf("\n04) Show Seating Plan.");
        printf("\n05) Search Ticket.");
        printf("\n06) Quit.");
        printf("\n\nPlease select the option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                buySeat();
                main();
                break;
            case 2:
                cancelSeat();
                main();
                break;
            case 3:
                FirstSeat();
                main();
                break;
            case 4:
                showseatingPlan();
                main();
                break;
            case 5:
                SearchTicket();
                main();
                break;
            case 6:
                printf("Thank You\n");
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Please enter the option number correctly.\n");
                main();
                break;
        }
    }
    return 0;
}
