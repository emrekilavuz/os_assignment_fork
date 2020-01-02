#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h> 
#include <string.h>

void writePriceFile();

int main(){
    srand(time(NULL));
    writePriceFile();
    // I have opened different pipes for each message
    int f1pipe[2];
    int f2pipe[2];
    int f3pipe[2];
    int f4pipe[2];
    int f5pipe[2];
    int arg1pipe[2];
    int arg2pipe[2];
    int arg3pipe[2];
    int arg4pipe[2];
    int arg5pipe[2];
    int arg6pipe[2];
    int arg7pipe[2];
    int arg8pipe[2];
    int arg9pipe[2];
    int arg10pipe[2];

    // Cerate pipes
    if (pipe(f1pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    

    if (pipe(f2pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(f3pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(f4pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(f5pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg1pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg2pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg3pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg4pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg5pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg6pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg7pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg8pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg9pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    if (pipe(arg10pipe)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    
    // Task array to choose from with random numbers
    char * tasks[5] = {"task1","task2","task3","task4","task5"};
    for(int i=0;i<5;i++){
        pid_t pid = fork();
       
        
        if(pid < 0){
            printf("error \n");
        }

         else if(pid == 0){
            ////////// CHILD PROCESSES
            char* argv[4]; // This argv will be sent to execv function
            int n = 0;
            argv[n] = "child.out";  // Child process must be compiled as child.out
            int processId = getpid();
            printf("i am the child with process id %d \n",processId);

            //I have defined different strings because scanf gave me trouble 
            char taskId1[7];
            char taskId2[7];
            char taskId3[7];
            char taskId4[7];
            char taskId5[7];
            char productC1[40];
            char productC2[40];
            char productC3[40];
            char productC4[40];
            char productC5[40];
            char customerC1[40];
            char customerC2[40];
            char customerC3[40];
            char customerC4[40];
            char customerC5[40];
            if(i==0){
                // Read the task id which is coming from parent process
                close(f1pipe[1]);
                read(f1pipe[0],taskId1,7);
                close(f1pipe[0]);
                printf("task id in child is %s\n",taskId1);
                argv[n+1] = taskId1;
                /// If task id is task2 or task3 we should read one more string which is product name and customer id
                if(strcmp(taskId1,"task2")==0){
                    close(arg1pipe[1]);
                    read(arg1pipe[0],productC1,40);
                    close(arg1pipe[0]);
                    argv[n+2] = productC1;
                    printf("product in child is %s\n",productC1);
                    argv[n+3] = NULL;
                }
                else if(strcmp(taskId1,"task3")==0){
                    close(arg2pipe[1]);
                    read(arg2pipe[0],customerC1,40);
                    close(arg2pipe[0]);
                    argv[n+2] = customerC1;
                    printf("customer in child is %s\n",customerC1);
                    argv[n+3] = NULL;
                }
                else{
                    argv[n+2] = NULL;
                }
            }
            else if(i==1){
                close(f2pipe[1]);
                read(f2pipe[0],taskId2,7);
                close(f2pipe[0]);
                printf("task id in child is %s\n",taskId2);
                argv[n+1] = taskId2;
                if(strcmp(taskId2,"task2")==0){
                    close(arg3pipe[1]);
                    read(arg3pipe[0],productC2,40);
                    close(arg3pipe[0]);
                    argv[n+2] = productC2;
                    printf("product in child is %s\n",productC2);
                    argv[n+3] = NULL;
                }
                else if(strcmp(taskId2,"task3")==0){
                    close(arg4pipe[1]);
                    read(arg4pipe[0],customerC2,40);
                    close(arg4pipe[0]);
                    argv[n+2] = customerC2;
                    printf("customer in child is %s\n",customerC2);
                    argv[n+3] = NULL;
                }
                else{
                    argv[n+2] = NULL;
                }
            }
            else if(i==2){
                close(f3pipe[1]);
                read(f3pipe[0],taskId3,7);
                close(f3pipe[0]);
                printf("task id in child is %s\n",taskId3);
                argv[n+1] = taskId3;
                if(strcmp(taskId3,"task2")==0){
                    close(arg5pipe[1]);
                    read(arg5pipe[0],productC3,40);
                    close(arg5pipe[0]);
                    argv[n+2] = productC3;
                    printf("product in child is %s\n",productC3);
                    argv[n+3] = NULL;
                }
                else if(strcmp(taskId3,"task3")==0){
                    close(arg6pipe[1]);
                    read(arg6pipe[0],customerC3,40);
                    close(arg6pipe[0]);
                    argv[n+2] = customerC3;
                    printf("customer in child is %s\n",customerC3);
                    argv[n+3] = NULL;
                }
                else{
                    argv[n+2] = NULL;
                }
            }
            else if(i==3){
                close(f4pipe[1]);
                read(f4pipe[0],taskId4,7);
                close(f4pipe[0]);
                printf("task id in child is %s\n",taskId4);
                argv[n+1] = taskId4;
                if(strcmp(taskId4,"task2")==0){
                    close(arg7pipe[1]);
                    read(arg7pipe[0],productC4,40);
                    close(arg7pipe[0]);
                    argv[n+2] = productC4;
                    printf("product in child is %s\n",productC4);
                    argv[n+3] = NULL;
                }
                else if(strcmp(taskId4,"task3")==0){
                    close(arg8pipe[1]);
                    read(arg8pipe[0],customerC4,40);
                    close(arg8pipe[0]);
                    argv[n+2] = customerC4;
                    printf("customer in child is %s\n",customerC4);
                    argv[n+3] = NULL;
                }
                else{
                    argv[n+2] = NULL;
                }
            }
            else if(i==4){
                /// Receive task id from parent
                close(f5pipe[1]);
                read(f5pipe[0],taskId5,7);
                close(f5pipe[0]);
                printf("task id in child is %s\n",taskId5);
                argv[n+1] = taskId5;
                // If task id is 2 receive product from parent
                if(strcmp(taskId5,"task2")==0){
                    close(arg9pipe[1]);
                    read(arg9pipe[0],productC5,40);
                    close(arg9pipe[0]);
                    argv[n+2] = productC5;
                    printf("product in child is %s\n",productC5);
                    argv[n+3] = NULL;
                }
                else if(strcmp(taskId5,"task3")==0){
                    close(arg10pipe[1]);
                    read(arg10pipe[0],customerC5,40);
                    close(arg10pipe[0]);
                    argv[n+2] = customerC5;
                    printf("customer in child is %s\n",customerC5);
                    argv[n+3] = NULL;
                }
                else{
                    argv[n+2] = NULL;
                }
            }
            
        
            if(execv(argv[0], argv)==-1)
                printf("error in calling exec\n");

        }
        else {  /// This is the parent process
            char product1[40];
            char product2[40];
            char product3[40];
            char product4[40];
            char product5[40];
            char customer1[40];
            char customer2[40];
            char customer3[40];
            char customer4[40];
            char customer5[40];

            if(i==0){
                int processId = getpid();
                printf("i am parent with id %d \n",processId);
                // Generating random number 
                int randomNumber = rand() % 5;
                char* task = tasks[randomNumber];
                // If chosen task is task2 then we have to take product name from user
                if(strcmp(task,"task2")==0){
                    printf("Enter the product name with uppercase letters\n");
                    scanf(" %s",product1);
                    printf("product in parent %s\n",product1);
                }
                // If chosen task is task2 then we have to take customer id from user
                else if(strcmp(task,"task3")==0){
                    printf("Enter the customer id like CUSTOMER_1\n");
                    scanf("%s",customer1);
                    printf("customer in parent id %s\n",customer1);
                }
                printf("task in parent %s\n",task);
                close(f1pipe[0]);
                write(f1pipe[1],task,strlen(task)+1);
                close(f1pipe[1]);
                if(strcmp(task, "task2")==0){
                    close(arg1pipe[0]);
                    write(arg1pipe[1],product1,strlen(product1)+1);
                    close(arg1pipe[1]);
                }
                else if(strcmp(task,"task3")==0){
                    close(arg2pipe[0]);
                    write(arg2pipe[1],customer1,strlen(customer1)+1);
                    close(arg2pipe[1]);
                }
            }
            else if(i==1){
                int processId = getpid();
                printf("i am parent with id %d \n",processId);
                // Generating random number using process id
                int randomNumber = rand() % 5;
                char* task = tasks[randomNumber];
                printf("task in parent %s\n",task);
                if(strcmp(task,"task2")==0){
                    printf("enter the product name with uppercase letters\n");
                    scanf(" %s",product2);
                    printf("Product in parent %s\n",product2);
                }
                else if(strcmp(task,"task3")==0){
                    printf("Enter the customer id like CUSTOMER_1\n");
                    scanf("%s",customer2);
                    printf("customer in parent id %s\n",customer2);
                }
                close(f2pipe[0]);
                write(f2pipe[1],task,strlen(task)+1);
                close(f2pipe[1]);
                if(strcmp(task, "task2")==0){
                    close(arg3pipe[0]);
                    write(arg3pipe[1],product2,strlen(product2)+1);
                    close(arg3pipe[1]);
                }
                else if(strcmp(task,"task3")==0){
                    close(arg4pipe[0]);
                    write(arg4pipe[1],customer2,strlen(customer2)+1);
                    close(arg4pipe[1]);
                }
            }
            else if(i==2){
                int processId = getpid();
                printf("i am parent with id %d \n",processId);
                // Generating random number using process id
                int randomNumber = rand() % 5;
                char* task = tasks[randomNumber];
                printf("task in parent %s\n",task);
                if(strcmp(task,"task2")==0){
                    printf("enter the product name with uppercase letters\n");
                    scanf("%s",product3);
                    printf("Product in parent %s\n",product3);
                }
                else if(strcmp(task,"task3")==0){
                    printf("Enter the customer id like CUSTOMER_1\n");
                    scanf("%s",customer3);
                    printf("customer in parent id %s\n",customer3);
                }
                close(f3pipe[0]);
                write(f3pipe[1],task,strlen(task)+1);
                close(f3pipe[1]);
                if(strcmp(task, "task2")==0){
                    close(arg5pipe[0]);
                    write(arg5pipe[1],product3,strlen(product3)+1);
                    close(arg5pipe[1]);
                }
                else if(strcmp(task,"task3")==0){
                    close(arg6pipe[0]);
                    write(arg6pipe[1],customer3,strlen(customer3)+1);
                    close(arg6pipe[1]);
                }
            }
            else if(i==3){
                int processId = getpid();
                printf("i am parent with id %d \n",processId);
            // Generating random number
                int randomNumber = rand() % 5;
                char* task = tasks[randomNumber];
                printf("task in parent %s\n",task);
                if(strcmp(task,"task2")==0){
                    printf("enter the product name with uppercase letters\n");
                    scanf("%s",product4);
                    printf("Product in parent %s\n",product4);
                }
                else if(strcmp(task,"task3")==0){
                    printf("Enter the customer id like CUSTOMER_1\n");
                    scanf("%s",customer4);
                    printf("customer in parent id %s\n",customer4);
                }
                close(f4pipe[0]);
                write(f4pipe[1],task,strlen(task)+1);
                close(f4pipe[1]);
                if(strcmp(task, "task2")==0){
                    close(arg7pipe[0]);
                    write(arg7pipe[1],product4,strlen(product4)+1);
                    close(arg7pipe[1]);
                }
                else if(strcmp(task,"task3")==0){
                    close(arg8pipe[0]);
                    write(arg8pipe[1],customer4,strlen(customer4)+1);
                    close(arg8pipe[1]);
                }
            }

            else if(i==4){
                int processId = getpid();
                printf("i am parent with id %d \n",processId);
                // Generating random number
                int randomNumber = rand() % 5;
                char* task = tasks[randomNumber];
                printf("task in parent %s\n",task);
                if(strcmp(task,"task2")==0){
                    printf("enter the product name with uppercase letters\n");
                    scanf("%s",product5);
                    printf("Product in parent %s\n",product5);
                }
                else if(strcmp(task,"task3")==0){
                    printf("Enter the customer id like CUSTOMER_1\n");
                    scanf("%s",customer5);
                    printf("customer in parent id %s\n",customer5);
                }
                close(f5pipe[0]);
                write(f5pipe[1],task,strlen(task)+1);
                close(f5pipe[1]);
                if(strcmp(task, "task2")==0){
                    close(arg9pipe[0]);
                    write(arg9pipe[1],product5,strlen(product5)+1);
                    close(arg9pipe[1]);
                }
                else if(strcmp(task,"task3")==0){
                    close(arg10pipe[0]);
                    write(arg10pipe[1],customer5,strlen(customer5)+1);
                    close(arg10pipe[1]);
                }
            }
            
            wait(NULL);
        }
        
    }

}



void writePriceFile(){
    FILE *fp;
    char *str=malloc(125*sizeof(char));
    int count=0;
    // Create a token array to store unique products
    char *tokenArray[150] = {NULL};
    int j;
    char *token;
    int result_compare;
    int result_compare2;
    fp = fopen("market.txt", "r");   
    int counter=0;
    int found;
    while(fgets(str, 125 , fp)!=NULL){
        token = strtok(str,",");
         //printf("%s\n",token);
         //printf("counter : %d\n",counter);
        while(1){
            if((token =strtok(NULL,",")) ==NULL){
                break;
            }
            else{
                // If elements are day or customer we skip them 
                if(((result_compare = strncmp("DAY",token,3))!=0) && (result_compare = strncmp("CUST",token,4))!=0){
                    // Trim the token, remove white spaces and new lines for convenience
                    char* trimmed = malloc(40 * sizeof(char));
                    int trim_count1 = 0;
                    int trim_count2 = 0;

                    while(token[trim_count1] != '\0'){
                        if((token[trim_count1] != ' ') && (token[trim_count1] != '\n') && (token[trim_count1]!='\t') && (token[trim_count1]!='\r')){
                            trimmed[trim_count2] = token[trim_count1];
                            trim_count2++;
                        }
                        trim_count1++;
                    }
                    // If the product doesn't exist in token array we add it to the array
                    found = 0;
                    for(j=0;j<200;j++){
                        
                        if(tokenArray[j]==NULL){
                            break;
                        }
                        else{
                            result_compare2 = strcmp(tokenArray[j],trimmed);
                            if(result_compare2==0){
                                found=1;
                                break;
                            }
                        }
                    }
                    if(found==0){
                        tokenArray[counter] = strdup(trimmed);
                        counter++;
                    }
                    
                }
                
                
            }      
        }
    }
    fclose(fp);
    // Create price array for products of size counter which we keep recently of product count
    int pricesArray[counter];
    // Create a random number between 1 and 50 and assign it to the array index
    int randomNumber;
    for(int k=0;k<counter;k++){
        randomNumber = rand() % 50 + 1;
        pricesArray[k] = randomNumber;
    }
    // Write to the price file
    FILE * anotherfp = fopen("price.txt","w");
   for(int i=0; i<counter;i++){
        if(tokenArray[i]==NULL)
            break;
         //printf(" %s\n",tokenArray[i]);
         fprintf(anotherfp,"%s %d\n",tokenArray[i],pricesArray[i]);
  }
  fclose(anotherfp);
}