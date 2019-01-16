<?php
	//게시판 읽기를 출력한다
	echo("<h2>게시판 읽기</h2><br>");
	
	//data를 불러올 파일 이름으로 "data.txt"를 저장하고 있는 문자 배열
	$filename = "Data.txt";
	
	//읽기 모드로 data.txt열기
	$fp=fopen($filename, "r");							

	//data.txt에서 저장된 글을 읽어 오기
	$string = fread($fp, filesize($filename));					
	
	//파일 포인터 닫기
	fclose($fp);

	//data.txt에 저장된 글을 읽어 와 화면에 출력함.
	//form을 생성한 후 textarea에 string에 저장된 글을 출력하는 방식.
	echo("
		<form name='outputform'>
		<textarea name='comment' rows='10' cols='50''> $string </textarea> 		
		</form>
		<br><br>
	");																			
	//메인 화면인 Board_main.php 파일로 이동
	echo("<a href=Board_main.php> 되돌아 가기</a>");				
?>
