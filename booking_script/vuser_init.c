vuser_init()
{
	web_reg_save_param("session",
		"LB=hidden name=userSession value=",
		"RB=>",
		LAST); //¹ØÁªsessionÖµ
	web_url("WebTours", 
		"URL={url}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	
	web_submit_data("login.pl", 
		"Action={url}login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={url}nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={session}", ENDITEM, 
		"Name=username", "Value=andy", ENDITEM, 
		"Name=password", "Value=123456", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=login.x", "Value=49", ENDITEM, 
		"Name=login.y", "Value=19", ENDITEM, 
		LAST);
	lr_output_message(lr_eval_string("{session}"));
	return 0;
}
