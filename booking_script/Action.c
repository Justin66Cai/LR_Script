char * randtime(int x,int y);
Action()
{
	char outFight[2048]; //���庽�೤��
	
	int depnumber =rand()%8 ;//�������ʱ��
	int arrnumber = rand()%3+depnumber;//�������ʱ��
	lr_save_datetime("%m/%d/%Y", DATE_NOW+ONE_DAY*depnumber, "deptime");//��������
	lr_save_datetime("%m/%d/%Y", DATE_NOW+ONE_DAY*arrnumber, "arrtime");//��������
	lr_output_message("depnumber=%d",depnumber);
	lr_output_message("arrnumber=%d",arrnumber);
	

	web_url("Search Flights Button", 
		"URL={url}welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={url}nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("FormDateUpdate.class", 
		"URL={url}FormDateUpdate.class", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		LAST);

	web_url("CalSelect.class", 
		"URL={url}CalSelect.class", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		LAST);

	web_url("Calendar.class", 
		"URL={url}Calendar.class", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=YearMonthPanel.class", "Referer=", ENDITEM, 
		"Url=DayPanel.class", "Referer=", ENDITEM, 
		"Url=DateInfo.class", "Referer=", ENDITEM, 
		LAST);

 	web_reg_save_param("outFight",
		"LB=outboundFlight value=",
		"RB=>",
		"Ordinal=all",
        "SaveLen=18",
	//ֻȡ����������18λ�ַ�
		"NotFound=ERROR",
		LAST);
// 	web_reg_save_param_regexp(
// 	 	"ParamName=outFight",
//         "RegExp=outboundFlight value=([0-9]*;[0-9]*;[0-9]*/[0-9]*/[0-9]*)",
//         "Ordinal=all",
// 		SEARCH_FILTERS,
// 		LAST );
		

	//�õ�����İ��
	web_submit_data("reservations.pl", 
		"Action={url}reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={url}reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		//������
		"Name=departDate", "Value={deptime}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		//������
		"Name=returnDate", "Value={arrtime}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=45", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);
	lr_output_message(lr_eval_string("{arrtime}"));
	lr_output_message(lr_eval_string("{deptime}"));
	
	lr_save_string(lr_paramarr_random("outFight"),"randOutFight");

	web_submit_data("reservations.pl_2", 
		"Action={url}reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={url}reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={randOutFight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=reserveFlights.x", "Value=21", ENDITEM, 
		"Name=reserveFlights.y", "Value=2", ENDITEM, 
		LAST);


	web_submit_data("reservations.pl_3", 
		"Action={url}reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={url}reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=jack", ENDITEM, 
		"Name=lastName", "Value=andy", ENDITEM, 
		"Name=address1", "Value=sdfdsf", ENDITEM, 
		"Name=address2", "Value=shanghai", ENDITEM, 
		"Name=pass1", "Value={Cname}", ENDITEM, 
		"Name=creditCard", "Value={ccard}", ENDITEM, 
		"Name=expDate", "Value=01/18", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=outboundFlight", "Value={randOutFight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=27", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);

	return 0;
}



