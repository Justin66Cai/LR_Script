Action()
{

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(8);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=122977.336411503zDcfztzpHtVzzzzHDHQfDpiiAtf", ENDITEM, 
		"Name=username", "Value=andy", ENDITEM, 
		"Name=password", "Value=123456", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=login.x", "Value=49", ENDITEM, 
		"Name=login.y", "Value=19", ENDITEM, 
		LAST);

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("FormDateUpdate.class", 
		"URL=http://127.0.0.1:1080/WebTours/FormDateUpdate.class", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		LAST);

	web_url("CalSelect.class", 
		"URL=http://127.0.0.1:1080/WebTours/CalSelect.class", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		LAST);

	web_url("Calendar.class", 
		"URL=http://127.0.0.1:1080/WebTours/Calendar.class", 
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

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=02/10/2018", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
		"Name=returnDate", "Value=02/28/2018", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=45", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=040;350;02/10/2018", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=21", ENDITEM, 
		"Name=reserveFlights.y", "Value=2", ENDITEM, 
		LAST);

	lr_think_time(23);

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=jack", ENDITEM, 
		"Name=lastName", "Value=andy", ENDITEM, 
		"Name=address1", "Value=sdfdsf", ENDITEM, 
		"Name=address2", "Value=shanghai", ENDITEM, 
		"Name=pass1", "Value=jack andy", ENDITEM, 
		"Name=creditCard", "Value=011111111116", ENDITEM, 
		"Name=expDate", "Value=01/18", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value=040;350;02/10/2018", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=27", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_think_time(8);

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("itinerary.pl", 
		"Action=http://127.0.0.1:1080/WebTours/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/itinerary.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=41334827-796-ja", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=removeFlights.x", "Value=48", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}