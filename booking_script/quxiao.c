char * submitBody(char * body,char * flightID,char * flightcheck);
quxiao()
{		
        char body[1024]="Body=";
		char flightcheck[10];
		web_reg_save_param("flightID",
		"LB=\"flightID\" value=\"",
		"RB=\"",
		"Ord=All",
		LAST);
		web_reg_save_param("flightcheck",
		"LB=name=\"",
		"RB=\" value=\"on\"",
        "Ord=All",
        LAST);
	lr_continue_on_error(1);
//	submitBody( body,"flightID",flightcheck);
	web_url("welcome.pl", 
		"URL={url}welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={url}nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
    if(atoi(lr_eval_string("{flightID_count}"))<=1){
		//小于一张票时，退出
        	web_url("SignOff Button",
			"URL={url}welcome.pl?signOff=1",
			"TargetFrame=body",
			"Resource=0",
			"RecContentType=text/html",
			"Referer={url}nav.pl?page=menu&in=itinerary",
			"Snapshot=t9.inf",
			"Mode=HTML",
			LAST);
		 }
	//lr_output_message("%s",submitBody(body,"flightID","flightcheck"));
	 lr_output_message("11111111111=%s",submitBody(body,"flightID","flightcheck"));
	//lr_output_message("%s",getName(tmp,lr_paramarr_idx("flightcheck",1)));

	if(atoi(lr_eval_string("{flightID_count}"))>=2){
	//大于等于2张票时退一张
	web_custom_request("cancelFly",
		"URL={url}itinerary.pl",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		body,
		LAST);
	}
	return 0;
}

char * submitBody(char * body,char * flightID,char * flightcheck){
	int countID = lr_paramarr_len(flightID);
	int countCtiy = lr_paramarr_len(flightcheck);
	int rand1,i;
// //     if(countCtiy==2){
// // 		for(i=1;i<=countCtiy;i++){
// // 			strcat(body,lr_paramarr_idx(flightcheck,i));
// // 			strcat(body,"=on&");
// // 		}
// // 	}else
	if(countCtiy>=2){
		rand1= rand()%countCtiy+1;
		strcat(body,lr_paramarr_idx(flightcheck,rand1));
		strcat(body,"=on&");
	}
	for(i=1;i<=countID;i++){
        strcat(body,"flightID=");
			strcat(body,lr_paramarr_idx(flightID,i));
			strcat(body,"&");
		}
    strcat(body,"removeFlights.x=57&removeFlights.y=14");
	for(i=1;i<=countCtiy;i++){
			strcat(body,"&.cgifields=");
			strcat(body,lr_paramarr_idx(flightcheck,i));
			
		}
		return body;

}



