int store_file_size(int file_size) {
    double time_;
    double time1;
    double time2;
    double time3;
    
    double signal_;
    double signal1;
    double signal2;
    double signal3;
    
    double sum_= 0;
    double sum1= 0;
    double sum2= 0;
    double sum3= 0;
    
    int index = 0;
    
    FILE *file_pointer = fopen("datasets/transmitted_signal.txt", "r");
    FILE *file_pointer1 = fopen("datasets/sample1.txt", "r");
    FILE *file_pointer2 = fopen("datasets/sample2.txt", "r");
    FILE *file_pointer3 = fopen("datasets/sample3.txt", "r");
    if (file_pointer ==  NULL) {
        printf("Error opening file\n");
        return 0;
        }
    
    else {
        while (fscanf(file_pointer, "%lf %lf", &time_, &signal_) != EOF) {
            
           fscanf(file_pointer1, "%lf %lf", &time1, &signal1);
           fscanf(file_pointer2, "%lf %lf", &time2, &signal2);
           fscanf(file_pointer3, "%lf %lf", &time3, &signal3);
           
           sum1+=(signal_ - signal1)*(signal_ - signal1);
           sum2+=(signal_ - signal2)*(signal_ - signal2);
           sum3+=(signal_ - signal3)*(signal_ - signal3);
           
            index++;
        }
        
        double best_signal;
        int sat_num;
        if (sum1<sum2) {
            if (sum1<sum3) {
                best_signal=sum1;
                sat_num=1;
            }
        }    
        if (sum2<sum1) {
            if (sum2<sum3) {
                best_signal=sum2;
                sat_num=2;
            }
        }
        if (sum3<sum1) {
            if (sum3<sum2) {
            best_signal=sum3;
            sat_num=3;
            }
        }
        
        printf ("Satellite %d has the best signal with a difference of %lf\n", sat_num, sum1);
        printf ("Difference for satellite 1 is %lf \n", sum1);
        printf ("Difference for satellite 2 is %lf \n", sum2);
        printf ("Difference for satellite 3 is %lf \n", sum3);
        //printf ("%d is the number of signals \n", index); 
        fclose(file_pointer);
        }
            file_size=index;
            return (file_size);
    }