Delete_Ticket()
{
	web_reg_save_param_ex(
    	"ParamName=userSession", 
    	"LB/IC=name=\"userSession\" value=\"",
    	"RB/IC=\"",
    	"Ordinal=1",
	LAST);
	
	web_url("webtours", 
		"URL={host}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/* Login */

	web_submit_data("login.pl", 
		"Action={host}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={usernamedel}", ENDITEM, 
		"Name=password", "Value={passworddel}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=54", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);
	
	lr_output_message("USE DELETE BLOCK FOR = %s",lr_eval_string("{usernamedel}"));
	
	randomize=atoi(lr_eval_string("{RND}"));
	
    number=atoi(lr_eval_string("{NumberOfTickets}"));
    lr_output_message("Randomize= %d",randomize);
    lr_output_message("Total number of tickets= %d",number);
    
	if(randomize>number){
		randomize=1;
	}
	itoa(randomize, conv, 10);
	lr_output_message("Convert= %s",conv);
	conv1=lr_eval_string("{randomize}");
	lr_output_message("Convert2= %d",conv1);
	lr_save_string("conv1","conv");
	lr_output_message("Convert3= %s",conv);
	
	web_reg_save_param_ex(
    	"ParamName=FlightID", 
    	"LB/IC=name=\"flightID\" value=\"",
    	"RB/IC=\"  ",
    	"Ordinal=all",
	LAST);
	
	
	
	/* Itinerary */

	web_url("Itinerary Button", 
		"URL={host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	/* Delete Ticket */
	

	web_submit_data("itinerary.pl", 
		"Action={host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM,
		"Name=flightID", "Value={FlightID_2}", ENDITEM,
		"Name=flightID", "Value={FlightID_3}", ENDITEM,
		"Name=flightID", "Value={FlightID_4}", ENDITEM,
		"Name=flightID", "Value={FlightID_5}", ENDITEM,
		"Name=flightID", "Value={FlightID_6}", ENDITEM,
		"Name=flightID", "Value={FlightID_7}", ENDITEM,
		"Name=flightID", "Value={FlightID_8}", ENDITEM,
		"Name=flightID", "Value={FlightID_9}", ENDITEM,
		"Name=flightID", "Value={FlightID_10}", ENDITEM,	
		"Name={conv}", "Value=on", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		"Name=.cgifields", "Value=2", ENDITEM,
		"Name=.cgifields", "Value=3", ENDITEM,
		"Name=.cgifields", "Value=4", ENDITEM,
		"Name=.cgifields", "Value=5", ENDITEM,
		"Name=.cgifields", "Value=6", ENDITEM,
		"Name=.cgifields", "Value=7", ENDITEM,
		"Name=.cgifields", "Value=8", ENDITEM,
		"Name=.cgifields", "Value=9", ENDITEM,
		"Name=.cgifields", "Value=10", ENDITEM,
		"Name=removeFlights.x", "Value=69", ENDITEM,
		"Name=removeFlights.y", "Value=8", ENDITEM,
		LAST);
	
	
	web_reg_find("Text=A First class ticket for",
        "SaveCount=First_Count2",
        LAST );
	
	web_reg_save_param_ex(
    	"ParamName=NumberOfTickets2", 
    	"LB/IC=<b>A total of ", 	
    	"RB/IC= scheduled flight",								
    	"Ordinal=1",
	LAST);
	
		/* Itinerary 2 */

	web_url("Itinerary Button", 
		"URL={host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_output_message("Number of tickets first class= %d",atoi(lr_eval_string("{First_Count2}")));
	lr_output_message("Total number of tickets after DEL= %d",atoi(lr_eval_string("{NumberOfTickets2}")));
	
	lr_output_message(" ");
	lr_output_message(" ");
	lr_output_message(" ");
	
	return 0;
}
