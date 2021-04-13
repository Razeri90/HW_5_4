Cycle()
{
	
	i=1;
    count=0;

    maxticket[1]=0;
    maxticket[2]=0;
    maxticket[3]=0;

    for(i;i<=3;i++){
        if(i==1) lr_output_message("user: jojo");
        if(i==2) lr_output_message("user: jojo1");
        if(i==3) lr_output_message("user: jojo2");
            lr_think_time(2);
        vuser_init();
            lr_think_time(2);
        Action();
            lr_think_time(2);
        maxticket[i]=count;
            lr_think_time(2);
        vuser_end();
    }

    

    lr_output_message("Quantity jojo Firstclass Ticket =%d",maxticket[1]);
    lr_output_message("Quantity jojo1 Firstclass Ticket =%d",maxticket[2]);
    lr_output_message("Quantity jojo2 Firstclass Ticket =%d",maxticket[3]);


    
    if((maxticket[1]>=maxticket[2]) && (maxticket[1]>=maxticket[3])){ // 1 > 2
            count=maxticket[1];
            lr_save_string("jojo","usernamedel");
            lr_save_string("bean","passworddel");
            lr_output_message("DELETE tickets for=%s",lr_eval_string("{usernamedel}"));
        }else{
                if((maxticket[2]>=maxticket[3]) && (maxticket[2]>=maxticket[1])){ // 2 > 3
                count=maxticket[2];
                lr_save_string("jojo1","usernamedel");
                lr_save_string("bean","passworddel");
                lr_output_message("DELETE tickets for=%s",lr_eval_string("{usernamedel}"));
            }else{
                    if((maxticket[3]>=maxticket[2]) && (maxticket[3]>=maxticket[1])){ // 3 > 1
                    count=maxticket[3];
                    lr_save_string("jojo2","usernamedel");
                    lr_save_string("bean","passworddel");
                    lr_output_message("DELETE tickets for=%s",lr_eval_string("{usernamedel}"));
                }
            }
        }
    

    lr_output_message("Quantity of Firstclass tickets =%d",count);
    DelTicket();


    return 0;
}
