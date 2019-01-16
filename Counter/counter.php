<?php
	//방문자수: 출력
	echo("<font size=7>방문자 수 : ");								
	//방문자수 기록 파일 읽기모드로 열기
	$fp = fopen("counter.txt", "r");	

	//counter.txt에 저장된 숫자 가져오기			
	$count = fread($fp, filesize("counter.txt")); 
	fclose($fp);	
					
	//처음 동작하는 것이라면 $ip가 값을 가지지 않으므로 setcookie함수 실행	
	if (!$ip)						
	{						
		//방문자의 IP 주소를 알려줌
		setcookie("ip", $REMOTE_ADDR);
		
		//방문자수 증가
		$count++;				
	}
					
	//counter.txt파일을 쓰기모드로 염
	$fp = fopen("counter.txt", "w");			

	//새로운 방문자수 저장
	fwrite($fp, "$count", strlen($count));			
	fclose($fp);					

	//count를 string형식으로 변환
	$string = (string)$count;	
					
	//방문자수만큼 반복
	for ( $i=0; $i<strlen($string); $i++)			
	{   
		//string의 한 글자씩 ch에 저장
		$ch = substr($string,$i,1);		
			
		//방문자수 이미지로 출력
		echo("<img src=".$ch.".jpg></font>");			
	}
?>