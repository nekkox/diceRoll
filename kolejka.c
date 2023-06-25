int kolejka (void){

    int kolejka;
    int status;

    do{
        puts("Podaj ile razy chcesz rzucić kostką");
       
        status = scanf("%d", &kolejka);
         while(getchar() !='\n')
            continue;
        if(status != 1 || kolejka < 0)
            puts("Numbers only");
    }
    
    while(status != 1 || kolejka < 0 );
    printf("OK, you rolled %d times\n", kolejka);
    
   return kolejka; 
}