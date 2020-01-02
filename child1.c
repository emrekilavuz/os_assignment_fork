#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

// This two structs will be used in task 3
typedef struct{
    char* customerName;
    char* products[50];
    int totalPrice;
}Customer;

typedef struct{
    char* productName;
    int price;
}Product;

// This day struct is for task5 
typedef struct{
    char* dayName;
    char* dayProducts[60];
    int dayPrice;
}Day;

int readPriceFile();
int productHowManyTimesSold(char* substring);
void findCustomerMostPurchase();
void totalPricePaidByCustomer(char* customer);
void calculateDayPrice();
char* trim(char* token);

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("error in usage\n");
        exit(1);
    }
    char* task = argv[1]; 
    if(strcmp(task, "task1") == 0){
        printf("executing task 1\n");
        int countOfProducts = readPriceFile();
        printf("the count of products is %d\n",countOfProducts);
    }
    else if(strcmp(task, "task2") == 0){
        char* product_e = argv[2];
        printf("product in exec is %s\n",product_e);
        printf("executing task 2\n");
        int howMany = productHowManyTimesSold(product_e);
        printf("product %s %d times sold\n",product_e, howMany);
    }
    else if(strcmp(task, "task3") == 0){
        printf("executing task 3\n");
        char* customer_e = argv[2];
        printf("customer in exec is %s\n",customer_e);
        totalPricePaidByCustomer(customer_e);
    }
    else if(strcmp(task, "task4") == 0){
        printf("executing task 4\n");
        findCustomerMostPurchase();
    }
    else if(strcmp(task, "task5") == 0){
        printf("executing task 5\n");
        calculateDayPrice();
    }
}


int readPriceFile(){
    int productCountOfPrice = 0;
    char * strReadFile = malloc(100*sizeof(char));
    FILE * fileprice = fopen("price.txt","r");
    while(fgets(strReadFile, 100, fileprice)!=NULL){
        printf("%s\n" , strReadFile);
        productCountOfPrice++;
    }
    fclose(fileprice);
    return productCountOfPrice;
}


// In this function we check if substring exist in product string
// This semantic has a problem, for example if milk exists in delacosed milk it counts that too
int productHowManyTimesSold(char* substring){
    int counter = 0;
    FILE * fp = fopen("market.txt", "r");
    char *str=malloc(125*sizeof(char));
    while(fgets(str, 125 , fp)!=NULL){
        if(strstr(str,substring)!=NULL){
            counter++;
        }
    }
    return counter;
}

void findCustomerMostPurchase(){
    int countOfProducts[5] = {0,0,0,0,0};  
    char* customer_names[5] = {NULL};
    char* currentCustomer;
    char *token;
    int found = 0;
    FILE * fp = fopen("market.txt", "r");
    char *str=malloc(125*sizeof(char));
    while(fgets(str, 125 , fp)!=NULL){
        int counter = 0;
        token = strtok(str,",");
        found = 0;
        int index=0;
        while((token=strtok(NULL,","))!=NULL){
            // If counter is 0, it means the token is a customer, so we should take it into customer name list
            if(counter==0){
                currentCustomer = strdup(token);
                for(int l=0; l<5; l++){
                    if(customer_names[l]!=NULL){
                        if(strcmp(token,customer_names[l])==0){
                        found = 1;
                        }
                    }
                    
                }
                if(found==0){
                    for(int k=0;k<5;k++){
                        if(customer_names[k]==NULL){
                            customer_names[k] = strdup(token);
                            break;
                        }
                    }
                }
            }
            counter++;
        }
        // We finf the index to be added by cheching if current customer is equal to customer names array index
        for(int p=0;p<5;p++){
            if(customer_names[p]!=NULL){
                if(strcmp(currentCustomer,customer_names[p])==0){
                index = p;
                }
            }
        }
        // Add counter value which represent the count of products in a row
        countOfProducts[index]+=counter;
    }
    printf("Customer names : %s and product count is %d\n",customer_names[0],countOfProducts[0]);
    printf("Customer names : %s and product count is %d\n",customer_names[1],countOfProducts[1]);
    printf("Customer names : %s and product count is %d\n",customer_names[2],countOfProducts[2]);
    printf("Customer names : %s and product count is %d\n",customer_names[3],countOfProducts[3]);
    printf("Customer names : %s and product count is %d\n",customer_names[4],countOfProducts[4]);
    int max_index1=0;
    for(int p=0;p<5;p++){
        
        if(countOfProducts[p]>countOfProducts[max_index1]){
            max_index1 = p;
        }

    }

    printf("Customer name who purchase most items is : %s and product count is %d\n",customer_names[max_index1],countOfProducts[max_index1]);
}



void totalPricePaidByCustomer(char* customer){
    // Create customer and products structs and initialize them
    Customer customer_struct;
    customer_struct.customerName = strdup(customer);
    customer_struct.totalPrice = 0;
    for(int i=0; i<50; i++){
        customer_struct.products[i] = NULL;
    }
    Product products[100];
    for(int i=0; i<100; i++){
        products[i].productName = NULL;
        products[i].price = 0;
    }
    FILE * fp = fopen("market.txt", "r");
    char *str=malloc(125*sizeof(char));
    char* token;
    int counter;
    int index=0;
    int row_will_be_added =0;
    char* currentCustomer;
    // Add products in a row if customer ids are equal
    // Index value is incremented in each add operation
    while(fgets(str, 125 , fp)!=NULL){
        token = strtok(str,",");
        counter=0;
        row_will_be_added = 0;
        while((token=strtok(NULL,","))!=NULL){
            if(counter==0){
                if(strcmp(token,customer)==0){
                    row_will_be_added =1;
                }
            }
            else{
                if(row_will_be_added == 1){
                    char* newToken = strdup(token);
                    char* trimmed = trim(newToken);
                    customer_struct.products[index] = strdup(trimmed);
                    index++;
                }
            }
            
            counter++;
        }
    }

    // Print the products purchased by specific customer id
    int ccc = 0;
    printf("The products purchased by %s\n",customer);
    while(customer_struct.products[ccc]!=NULL){
        printf("%s\n",customer_struct.products[ccc]);
        ccc++;
    }
    printf("product count of %s is %d\n",customer,ccc);
    fclose(fp);
    FILE * pfp = fopen("price.txt","r");
    char *stri=malloc(75*sizeof(char));
    char * ptoken;
    int pindex = 0;
    // Get the products from file to struct array
    while(fgets(stri,75,pfp) != NULL){
        ptoken = strtok(stri," ");
        products[pindex].productName = strdup(ptoken);
        while((ptoken = strtok(NULL, " ")) != NULL){
            char* newPtoken = strdup(ptoken);
            char* trimmedPtoken = trim(newPtoken);
            int price_int = atoi(trimmedPtoken); 
            products[pindex].price = price_int;
        }
        pindex++;

    }
    fclose(pfp);
    int cc1 = 0;
    int cc2 = 0;
    // Iterate customer products and product prices using two while loop, 
    //if there is a match add product price to customer's total price 
    while(customer_struct.products[cc1] != NULL){
        cc2=0;
        while(products[cc2].productName!=NULL){
            if(strcmp(customer_struct.products[cc1],products[cc2].productName)==0){
                customer_struct.totalPrice += products[cc2].price;
                //printf("Found!!!! %s %s \n",products[cc2].productName,customer_struct.products[cc1]);
            }
            cc2++;
        }
        cc1++;
    }
    printf("Total price paid by customer %s is %d\n",customer,customer_struct.totalPrice);
}

void calculateDayPrice(){
    // Create days array of structs and initialize it
    Day days[7];
    for(int i=0;i<7;i++){
        for(int j=0;j<60;j++){
            days[i].dayProducts[j] = NULL;
        }
        days[i].dayName = NULL;
        days[i].dayPrice = 0;
    }
    FILE * fp_market = fopen("market.txt","r");
    char *str=malloc(125*sizeof(char));
    char* token;
    int index = 0;
    int index2[7] = {0,0,0,0,0,0,0};
    int counter = 0;
    while(fgets(str, 125 , fp_market)!=NULL){
        token = strtok(str,",");
        char * newToken = strdup(token);
        // Fınd the index to add products in a row for a specific day
        for(int i=0;i<7;i++){
            if(days[i].dayName!=NULL){
                if(strcmp(days[i].dayName,newToken)==0){
                    index = i;
                    break;
                }
            }
            else{
                days[i].dayName = strdup(newToken);
                index = i;
                break;
            }
        }
        counter = 0;
        while((token=strtok(NULL,","))!=NULL){
            if(counter!=0){
                char* newToken1 = strdup(token);
                char* trimmed = trim(newToken1);
                days[index].dayProducts[index2[index]] = strdup(trimmed);
                //printf("%s %d %d %s\n",days[index].dayName,index,index2[index],days[index].dayProducts[index2[index]]);
                index2[index]++;
            }   
            counter++;
        }
    }
    fclose(fp_market);
    // Initialize product struct array
    Product products[100];
    for(int i=0; i<100; i++){
        products[i].productName = NULL;
        products[i].price = 0;
    }
    FILE * priceFp = fopen("price.txt","r");
    char *stri=malloc(75*sizeof(char));
    char * ptoken;
    int pindex = 0;
    // Get the products from file to struct array
    while(fgets(stri,75,priceFp) != NULL){
        ptoken = strtok(stri," ");
        products[pindex].productName = strdup(ptoken);
        while((ptoken = strtok(NULL, " ")) != NULL){
            char* newPtoken = strdup(ptoken);
            char* trimmedPtoken = trim(newPtoken);
            int price_int = atoi(trimmedPtoken); 
            products[pindex].price = price_int;
        }
        pindex++;

    }
    fclose(priceFp);
    // Itearte day product struct array and product price array using three for loop, 
    //if there is a match increment the day price by product price
    for(int i=0;i<7;i++){
        for(int j=0;j<60;j++){
            for(int k=0;k<100;k++){
                if(days[i].dayProducts[j]!=NULL && products[k].productName!=NULL){
                    if(strcmp(days[i].dayProducts[j],products[k].productName)==0){
                    days[i].dayPrice += products[k].price;
                    }
                }
                
            }   
        }
    }
    // Find maximum and print
    int maxIndex = 0;
    for(int i=0; i<7; i++){
        if(days[i].dayPrice > days[maxIndex].dayPrice){
            maxIndex = i;
        }
        printf("%s day and %d price\n",days[i].dayName,days[i].dayPrice);
    }
    printf("The most profitable day is %s and its price is %d\n",days[maxIndex].dayName,days[maxIndex].dayPrice);
}


// Remove all white spaces and new lines from the string for convenience
char* trim(char* token){
    char* trimmed = malloc(50 * sizeof(char));
    int trim_count1 = 0;
    int trim_count2 = 0;

    while(token[trim_count1] != '\0'){
        if((token[trim_count1] != ' ') && (token[trim_count1] != '\n') && (token[trim_count1]!='\t') && (token[trim_count1]!='\r')){
            trimmed[trim_count2] = token[trim_count1];
            trim_count2++;
        }
        trim_count1++;
    }
    trimmed[trim_count2] = '\0';
    return trimmed;
}
